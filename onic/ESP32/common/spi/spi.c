// spi.c - ESP-IDF 5.3.3 SPI non-blocking + DMA (safe pins), TX-only
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "driver/spi_master.h"
#include "esp_log.h"
#include "esp_heap_caps.h"

#include "spi.h"

#ifndef SPI_MAX_XFER_SZ
#define SPI_MAX_XFER_SZ 4096
#endif

static const char *TAG = "SPI";

static spi_device_handle_t   spi_handle     = NULL;
static spi_handler_t         p_spi_handler  = NULL;
static TaskHandle_t          s_spi_worker   = NULL;
static SemaphoreHandle_t     s_dev_mutex    = NULL;   // bảo vệ queue từ nhiều task
static volatile bool         s_shutting_down = false;

static inline bool spi_is_inited(void)    { return (spi_handle != NULL); }

// ================= Worker Task =================
static void spi_worker_task(void *arg)
{
    for (;;)
    {
        spi_transaction_t *ret_t = NULL;
        esp_err_t ret = spi_device_get_trans_result(spi_handle, &ret_t, portMAX_DELAY);
        if (ret != ESP_OK) {
            // Nếu đang deinit, có thể bị hủy giữa chừng
            if (s_shutting_down) break;
            ESP_LOGE(TAG, "get_trans_result: %s", esp_err_to_name(ret));
            continue;
        }

        // Giải phóng buffer copy (nếu có)
        if (ret_t && ret_t->user) {
            free(ret_t->user);
            ret_t->user = NULL;
        }

        // Gọi callback báo hoàn tất
        if (p_spi_handler) {
            p_spi_handler(ESP_OK);
        }
    }
    vTaskDelete(NULL);
}

// ================= Public APIs =================
void spi_init(void)
{
    if (spi_is_inited()) {
        ESP_LOGW(TAG, "SPI already initialized");
        return;
    }

    s_shutting_down = false;

    // Lưu ý: đảm bảo trong spi.h đã chọn host IDF v5: SPI2_HOST hoặc SPI3_HOST
    spi_bus_config_t buscfg = {
        .mosi_io_num     = SPI_MOSI_PIN,     // 23
        .miso_io_num     = SPI_MISO_PIN,     // 19 (đặt -1 nếu TX-only)
        .sclk_io_num     = SPI_CLK_PIN,      // 18
        .quadwp_io_num   = -1,
        .quadhd_io_num   = -1,
        .max_transfer_sz = SPI_MAX_XFER_SZ
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 10 * 1000 * 1000,  // 10 MHz (tùy slave)
        .mode           = 0,                  // SPI mode 0
        .spics_io_num   = SPI_CS_PIN,         // 5 (CS auto); -1 nếu tự điều khiển
        .queue_size     = SPI_QUEUE_SIZE,     // non-blocking cần >1
        // .flags = SPI_DEVICE_NO_DUMMY | SPI_DEVICE_HALFDUPLEX ... (nếu cần)
    };

    ESP_ERROR_CHECK(spi_bus_initialize(SPI_HOST_USED, &buscfg, SPI_DMA_CH_AUTO));
    ESP_ERROR_CHECK(spi_bus_add_device(SPI_HOST_USED, &devcfg, &spi_handle));

    s_dev_mutex = xSemaphoreCreateMutex();
    if (!s_dev_mutex) {
        ESP_LOGE(TAG, "Create mutex failed");
        spi_bus_remove_device(spi_handle);
        spi_handle = NULL;
        spi_bus_free(SPI_HOST_USED);
        ESP_ERROR_CHECK(ESP_ERR_NO_MEM);
    }

    // Worker lấy kết quả các transaction non-blocking
    BaseType_t ok = xTaskCreate(spi_worker_task, "spi_worker", 3072, NULL, tskIDLE_PRIORITY + 2, &s_spi_worker);
    if (ok != pdPASS) {
        ESP_LOGE(TAG, "Create worker failed");
        vSemaphoreDelete(s_dev_mutex);
        s_dev_mutex = NULL;
        spi_bus_remove_device(spi_handle);
        spi_handle = NULL;
        spi_bus_free(SPI_HOST_USED);
        ESP_ERROR_CHECK(ESP_ERR_NO_MEM);
    }

    ESP_LOGI(TAG, "SPI initialized (non-blocking, DMA)");
}

void spi_deinit(void)
{
    if (!spi_is_inited()) return;

    // Chặn thêm giao dịch mới
    s_shutting_down = true;

    // Hủy worker (đang block portMAX_DELAY trong get_trans_result)
    if (s_spi_worker) {
        vTaskDelete(s_spi_worker);
        s_spi_worker = NULL;
    }

    // Tự mình drain kết quả còn lại (nếu có)
    while (1) {
        spi_transaction_t *ret_t = NULL;
        esp_err_t ret = spi_device_get_trans_result(spi_handle, &ret_t, 0);
        if (ret == ESP_OK) {
            if (ret_t && ret_t->user) {
                free(ret_t->user);
                ret_t->user = NULL;
            }
            continue;
        }
        break; // ESP_ERR_TIMEOUT hoặc lỗi khác → coi như trống hàng đợi
    }

    if (s_dev_mutex) {
        vSemaphoreDelete(s_dev_mutex);
        s_dev_mutex = NULL;
    }

    spi_bus_remove_device(spi_handle);
    spi_handle = NULL;
    spi_bus_free(SPI_HOST_USED);

    ESP_LOGI(TAG, "SPI deinitialized");
}

void spi_set_callback(spi_handler_t cb)
{
    p_spi_handler = cb; // sẽ được gọi mỗi khi 1 transaction hoàn tất
}

/**
 * Enqueue TX non-blocking.
 * - Luôn an toàn DMA và vòng đời buffer: copy sang RAM DMA-capable nếu len > 4.
 * - Gói <=4 byte: dùng SPI_TRANS_USE_TXDATA (không cần DMA).
 */
esp_err_t spi_transfer_async(const uint8_t *data, uint16_t len)
{
    if (!spi_is_inited() || s_shutting_down) {
        return ESP_ERR_INVALID_STATE;
    }
    if (!data || len == 0) {
        return ESP_ERR_INVALID_ARG;
    }

    esp_err_t ret;
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = len * 8;

    if (len <= 4) {
        t.flags = SPI_TRANS_USE_TXDATA;
        memcpy(t.tx_data, data, len);
        t.user = NULL; // không cần free
    } else {
        // Copy sang DMA-capable RAM để:
        // 1) đảm bảo DMA đọc được,
        // 2) caller có thể sửa/giải phóng 'data' ngay sau khi enqueue.
        uint8_t *dma_buf = (uint8_t *)heap_caps_malloc(len, MALLOC_CAP_DMA);
        if (!dma_buf) return ESP_ERR_NO_MEM;
        memcpy(dma_buf, data, len);
        t.tx_buffer = dma_buf;
        t.user      = dma_buf; // giữ để worker free sau khi xong
    }

    if (s_dev_mutex) xSemaphoreTake(s_dev_mutex, portMAX_DELAY);
    ret = spi_device_queue_trans(spi_handle, &t, portMAX_DELAY);
    if (s_dev_mutex) xSemaphoreGive(s_dev_mutex);

    if (ret != ESP_OK) {
        // Nếu enqueue fail và có cấp phát tạm thì free ngay
        if (t.user) free(t.user);
        ESP_LOGE(TAG, "queue_trans failed: %s", esp_err_to_name(ret));
    }

    return ret;
}
