#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#include "spi.h"

static const char *TAG = "SPI";

static spi_device_handle_t spi_handle = NULL;
static spi_handler_t p_spi_handler = NULL;

void spi_init(void)
{
    esp_err_t ret;

    spi_bus_config_t buscfg = {
        .mosi_io_num = SPI_MOSI_PIN,
        .miso_io_num = SPI_MISO_PIN,
        .sclk_io_num = SPI_CLK_PIN,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 64
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1 * 1000 * 1000, // 1 MHz
        .mode = 0,                         // SPI mode 0
        .spics_io_num = SPI_CS_PIN,       // CS pin
        .queue_size = SPI_QUEUE_SIZE,
    };

    ret = spi_bus_initialize(SPI_HOST_USED, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    ret = spi_bus_add_device(SPI_HOST_USED, &devcfg, &spi_handle);
    ESP_ERROR_CHECK(ret);

    esp_log_level_set(TAG, ESP_LOG_INFO);

    ESP_LOGI(TAG, "SPI initialized");
}

void spi_set_callback(spi_handler_t cb)
{
    if (cb) {
        p_spi_handler = cb;
    }
}

void spi_put(uint8_t *data, uint16_t len)
{
    esp_err_t ret;
    spi_transaction_t trans = {
        .length = len * 8,  // length in bits
        .tx_buffer = data,
        .rx_buffer = NULL
    };

    ret = spi_device_transmit(spi_handle, &trans);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "SPI transmit failed: %s", esp_err_to_name(ret));
    }
}
