// #include "app_spi.h"

// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/semphr.h"
// #include "esp_log.h"
// #include <string.h>
// #include <stdio.h>

// #include "spi.h"
// #include "phQueue.h"
// #include "phApp_DataTypes.h"
// #include "input.h"

// static const char *TAG = "APP_SPI";
// static SemaphoreHandle_t spi_sem = NULL;
// static TaskHandle_t s_xfer_task = NULL;

// /* ---------- SPI callback (driver gọi khi xong 1 phiên) ---------- */
// static void on_spi_done(esp_err_t r)
// {
//     if (spi_sem)
//         xSemaphoreGive(spi_sem);
//     if (r != ESP_OK)
//         ESP_LOGE(TAG, "spi done err=%s", esp_err_to_name(r));
// }

// /* ---------- helper: build TX từ item (hoặc dummy) ---------- */
// static size_t build_tx(uint8_t *tx, const phApp_Data_t *item_or_null)
// {
//     memset(tx, 0, MESSAGE_SIZE + 2);

//     if (item_or_null)
//     {
//         size_t payload_len = item_or_null->header.length;
//         if (payload_len > PAYLOAD_SIZE)
//             payload_len = PAYLOAD_SIZE;

//         const uint16_t len = (uint16_t)payload_len + 4;
//         tx[0] = (uint8_t)(len & 0xFF);
//         tx[1] = (uint8_t)((len >> 8) & 0xFF);

//         if (payload_len)
//         {
//             tx[2] = (item_or_null->header.group << 4) | (item_or_null->header.ecu);
//             tx[3] = item_or_null->header.id;
//             tx[4] = (item_or_null->header.length >> 8) & 0xFF;
//             tx[5] = item_or_null->header.length & 0xFF;
//             if (item_or_null->header.length > 0)
//             {
//                 memcpy(&tx[6], item_or_null->payload, item_or_null->header.length);
//             }

//             if ((uint16_t)(len + 2u) < MESSAGE_SIZE)
//             {
//                 memset(&tx[len + 2], 0, MESSAGE_SIZE - len);
//             }
//         }
//     }
//     return MESSAGE_SIZE;
// }

// static bool rx_parse_if_valid(const uint8_t *rx, size_t xfer_len,
//                               phApp_Data_t *out_item)
// {
//     if (!rx)
//         return false;
//     if (xfer_len < 4u)
//         return false;

//     uint16_t rx_len = (uint16_t)rx[0] | ((uint16_t)rx[1] << 8);

//     if (rx_len == 0u || rx_len == 0xFFFFu)
//         return false;

//     if (rx_len > MESSAGE_SIZE)
//         return false;

//     if ((size_t)rx_len > xfer_len)
//         return false;

//     if (out_item)
//     {
//         if (rx_len)
//         {
//             out_item->header.group = (rx[2] >> 4) & 0x0F;
//             out_item->header.ecu = rx[2] & 0x0F;
//             out_item->header.id = rx[3];
//             out_item->header.length = (uint16_t)(rx[4] << 8) | (uint16_t)rx[5];

//             for (int i = 0; i < out_item->header.length; i++)
//             {
//                 out_item->payload[i] = rx[i + 6]; // 2byte spi_length + 4byte header
//             }
//         }
//     }

//     return true;
// }

// /* ---------- ISR input: báo slave-ready → đánh thức task (debounce) ---------- */
// static void IRAM_ATTR input_cb_isr(int gpio_num)
// {
//     if (gpio_num != GPIO_NUM_4)
//         return;
//     if (s_xfer_task)
//     {
//         BaseType_t hpw = pdFALSE;
//         vTaskNotifyGiveFromISR(s_xfer_task, &hpw);
//         if (hpw)
//             portYIELD_FROM_ISR(); // context switch if needed
//     }
// }

// /* ---------- task: hợp nhất 2 chiều ----------
//    - Chỉ transfer khi có notify (SRDY) HOẶC có TX data
//    - Sau khi transfer done: chỉ log + push QueueRX nếu KHÔNG phải dummy
// */
// static void transfer_task(void *arg)
// {
//     static uint8_t tx[MESSAGE_SIZE + 2], rx[MESSAGE_SIZE + 2];
//     phApp_Data_t item;
//     s_xfer_task = xTaskGetCurrentTaskHandle();

//     TickType_t last_warn = 0;

//     for (;;)
//     {
//         uint32_t notified = ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(500));
//         if (notified)
//             ESP_LOGE(TAG, "task notified: %lu", notified);
//         bool want_tx = !QueueTX_IsEmpty();
//         if (!notified && !want_tx)
//         {
//             continue;
//         }

//         const phApp_Data_t *p = NULL;
//         if (want_tx)
//         {
//             if (QueueTX_Pop(&item) == PH_ERR_OK)
//             {
//                 p = &item;
//             }
//         }

//         if (spi_sem)
//             (void)xSemaphoreTake(spi_sem, 0);

//         (void)build_tx(tx, p);
//         memset(rx, 0, MESSAGE_SIZE + 2);

//         esp_err_t ret = spi_transfer_async_duplex(tx, rx, MESSAGE_SIZE + 2);
//         if (ret != ESP_OK)
//         {
//             ESP_LOGE(TAG, "spi xfer err: %s", esp_err_to_name(ret));
//             vTaskDelay(pdMS_TO_TICKS(2));
//             continue;
//         }

//         if (xSemaphoreTake(spi_sem, pdMS_TO_TICKS(200)) == pdTRUE)
//         {
//             phApp_Data_t rx_item;
//             if (rx_parse_if_valid(rx, MESSAGE_SIZE, &rx_item))
//             {
//                 ESP_LOGI(TAG, "RX frame: group=%u ecu_id=%u id=%u length=%u",
//                          rx_item.header.group,
//                          rx_item.header.ecu,
//                          rx_item.header.id,
//                          (unsigned)rx_item.header.length);

//                 ESP_LOG_BUFFER_HEX(TAG, rx_item.payload, rx_item.header.length);
//                 (void)QueueRX_Push(&rx_item);
//             }
//         }
//         else
//         {
//             TickType_t now = xTaskGetTickCount();
//             if ((now - last_warn) > pdMS_TO_TICKS(1000))
//             {
//                 ESP_LOGW(TAG, "spi timeout");
//                 last_warn = now;
//             }
//         }
//     }
// }

// void app_spi(void)
// {
//     spi_init();

//     if (!spi_sem)
//         spi_sem = xSemaphoreCreateBinary();
//     spi_set_callback(on_spi_done);

//     input_io_create(GPIO_NUM_4, GPIO_INTR_ANYEDGE);
//     xTaskCreate(transfer_task, "spi_xfer", 3072, NULL, tskIDLE_PRIORITY + 2, NULL);
//     input_set_callback((void *)input_cb_isr);
// }


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include <string.h>
#include <stdint.h>

#include "spi.h"   // spi_init(), spi_set_callback(), spi_transfer_async_duplex(...)

static const char *TAG = "SPI_POLL_ASYNC";

// Kích thước frame test (tùy bạn): 16/32/64/256...
#ifndef XFER_SIZE
#define XFER_SIZE 16
#endif

static SemaphoreHandle_t s_done_sem = NULL;

// Callback do SPI common của bạn gọi khi 1 transaction hoàn tất
static void spi_done_handler(esp_err_t r)
{
    if (r != ESP_OK) {
        ESP_LOGE(TAG, "SPI done err=%s", esp_err_to_name(r));
    }
    if (s_done_sem) {
        // callback này đang chạy trong task worker của bạn, nên dùng xSemaphoreGive là đủ
        xSemaphoreGive(s_done_sem);
    }
}

static void spi_poll_async_task(void *arg)
{
    static uint8_t tx[XFER_SIZE];
    static uint8_t rx[XFER_SIZE];
    static uint8_t seq = 0;

    ESP_LOGI(TAG, "Start SPI async polling (period=1s, size=%d)", XFER_SIZE);

    for (;;)
    {
        // 1) Tạo pattern gửi cho dễ quan sát (0x00,0x01,...)
        for (int i = 0; i < XFER_SIZE; i++) {
            tx[i] = (uint8_t)(seq + i);
        }
        seq++;

        memset(rx, 0, sizeof(rx));

        // 2) Clear sem cũ (nếu có)
        if (s_done_sem) (void)xSemaphoreTake(s_done_sem, 0);

        // 3) Gửi non-blocking
        esp_err_t ret = spi_transfer_async_duplex(tx, rx, XFER_SIZE);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "queue trans err=%s", esp_err_to_name(ret));
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }

        // 4) Chờ callback báo xong (timeout bảo vệ)
        if (xSemaphoreTake(s_done_sem, pdMS_TO_TICKS(500)) != pdTRUE) {
            ESP_LOGW(TAG, "Timeout waiting SPI completion");
        } else {
            // 5) Log từng byte nhận được
            ESP_LOGI(TAG, "SPI RX (%d bytes):", 16);
            for (int i = 0; i < 16; i++) {
                ESP_LOGI(TAG, "  Byte[%02d] = 0x%02X", i, rx[i]);
            }
        }

        // 6) Lặp mỗi 1s
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

void app_spi(void)
{
    spi_init();  // dùng spi_init() từ common của bạn

    if (!s_done_sem) s_done_sem = xSemaphoreCreateBinary();
    spi_set_callback(spi_done_handler);  // đăng ký callback

    // Tạo task test
    xTaskCreate(spi_poll_async_task, "spi_poll_async", 4096, NULL, tskIDLE_PRIORITY + 2, NULL);

    ESP_LOGI(TAG, "app_spi init done (async polling).");
}
