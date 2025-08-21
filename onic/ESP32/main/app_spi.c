#include "app_spi.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include <string.h>
#include <stdio.h>

#include "spi.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include "input.h"

static const char *TAG = "APP_SPI";
static SemaphoreHandle_t spi_sem = NULL;
static TaskHandle_t s_xfer_task = NULL;

/* ---------- SPI callback (driver gọi khi xong 1 phiên) ---------- */
static void on_spi_done(esp_err_t r)
{
    if (spi_sem)
        xSemaphoreGive(spi_sem);
    if (r != ESP_OK)
        ESP_LOGE(TAG, "spi done err=%s", esp_err_to_name(r));
}

/* ---------- helper: build TX từ item (hoặc dummy) ---------- */
static size_t build_tx(uint8_t *tx, const phApp_Data_t *item_or_null)
{
    memset(tx, 0, MESSAGE_SIZE);

    const size_t max_payload_buf = (MESSAGE_SIZE >= 4) ? (MESSAGE_SIZE - 4) : 0;

    if (item_or_null)
    {
        size_t payload_len = item_or_null->header.length;
        if (payload_len > PAYLOAD_SIZE)
            payload_len = PAYLOAD_SIZE;
        if (payload_len > max_payload_buf)
            payload_len = max_payload_buf;

        const uint16_t len = (uint16_t)payload_len + 4;
        tx[0] = (uint8_t)(len & 0xFF);
        tx[1] = (uint8_t)(len >> 8);

        if (payload_len)
        {
            memcpy(&tx[2], item_or_null->payload, len);
        }
    }
    else
    {
        tx[0] = 0x00;
        tx[1] = 0x00;
        tx[2] = 0x00;
        tx[3] = 0x00;
        tx[4] = 0x00;
    }

    return MESSAGE_SIZE;
}

static bool rx_parse_if_valid(const uint8_t *rx, size_t xfer_len,
                              phApp_Data_t *out_item)
{
    if (!rx)
        return false;
    if (xfer_len < 4u)
        return false;

    uint16_t rx_len = (uint16_t)rx[0] | ((uint16_t)rx[1] << 8);

    if (rx_len == 0u || rx_len == 0xFFFFu)
        return false;

    if (rx_len > PAYLOAD_SIZE)
        return false;

    if ((size_t)rx_len + 4u > xfer_len)
        return false;

    if (out_item)
    {
        if (rx_len)
            memcpy(out_item, &rx[2], rx_len);
    }

    return true;
}

/* ---------- ISR input: báo slave-ready → đánh thức task (debounce) ---------- */
static void IRAM_ATTR input_cb_isr(int gpio_num)
{
    if (gpio_num != GPIO_NUM_4)
        return;
    if (s_xfer_task)
    {
        BaseType_t hpw = pdFALSE;
        vTaskNotifyGiveFromISR(s_xfer_task, &hpw);
        if (hpw)
            portYIELD_FROM_ISR(); // context switch if needed
    }
}

/* ---------- task: hợp nhất 2 chiều ----------
   - Chỉ transfer khi có notify (SRDY) HOẶC có TX data
   - Sau khi transfer done: chỉ log + push QueueRX nếu KHÔNG phải dummy
*/
static void transfer_task(void *arg)
{
    static uint8_t tx[MESSAGE_SIZE], rx[MESSAGE_SIZE];
    phApp_Data_t item;
    s_xfer_task = xTaskGetCurrentTaskHandle();

    TickType_t last_warn = 0;

    for (;;)
    {
        uint32_t notified = ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(500));
        if (notified)
            ESP_LOGE(TAG, "task notified: %lu", notified);
        bool want_tx = !QueueTX_IsEmpty();
        if (!notified && !want_tx) {
            continue;
        }

        const phApp_Data_t *p = NULL;
        if (want_tx)
        {
            if (QueueTX_Pop(&item) == PH_ERR_OK)
            {
                p = &item;
            }
        }

        if (spi_sem)
            (void)xSemaphoreTake(spi_sem, 0);

        (void)build_tx(tx, p);
        memset(rx, 0, MESSAGE_SIZE);

        esp_err_t ret = spi_transfer_async_duplex(tx, rx, MESSAGE_SIZE);
        if (ret != ESP_OK)
        {
            ESP_LOGE(TAG, "spi xfer err: %s", esp_err_to_name(ret));
            vTaskDelay(pdMS_TO_TICKS(2));
            continue;
        }

        if (xSemaphoreTake(spi_sem, pdMS_TO_TICKS(200)) == pdTRUE)
        {
            phApp_Data_t rx_item;
            size_t rx_copy = 0;
            if (rx_parse_if_valid(rx, MESSAGE_SIZE, &rx_item))
            {
                ESP_LOGI(TAG, "RX frame: group=%u ecu_id=%u id=%u length=%u",
                         rx_item.header.group,
                         rx_item.header.ecu,
                         rx_item.header.id,
                         (unsigned)rx_item.header.length);

                if (rx_copy > 0)
                {
                    ESP_LOG_BUFFER_HEX(TAG, rx_item.payload, rx_copy);
                }
                (void)QueueRX_Push(&rx_item);
            }
        }
        else
        {
            TickType_t now = xTaskGetTickCount();
            if ((now - last_warn) > pdMS_TO_TICKS(1000))
            {
                ESP_LOGW(TAG, "spi timeout");
                last_warn = now;
            }
        }
    }
}

void app_spi(void)
{
    spi_init();

    if (!spi_sem)
        spi_sem = xSemaphoreCreateBinary();
    spi_set_callback(on_spi_done);

    input_io_create(GPIO_NUM_4, GPIO_INTR_ANYEDGE);
    xTaskCreate(transfer_task, "spi_xfer", 3072, NULL, tskIDLE_PRIORITY + 2, NULL);
    input_set_callback((void *)input_cb_isr);
}


