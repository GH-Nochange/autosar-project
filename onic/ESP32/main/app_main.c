#include "esp_err.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "string.h"
#include <stdio.h>

#include "input.h"
#include "phQueue.h"
#include "wifi_config.h"

#include "app_mqtt.h"
#include "app_spi.h"

static const char *TAG = "APP_MAIN";

// Reset ESP32
typedef struct {
  int gpio_num;
  uint32_t press_time_ms;
} button_event_t;

static QueueHandle_t button_evt_queue;

void button_task(void *arg) {
  button_event_t evt;
  while (1) {
    if (xQueueReceive(button_evt_queue, &evt, portMAX_DELAY)) {
      if (evt.press_time_ms > 3000) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_LOGI(TAG, "NVS erased. Restarting...");

        vTaskDelay(pdMS_TO_TICKS(500));

        esp_restart();
      }
    }
  }
}

void input_button_callback(int gpio_num, uint64_t tick) {
  if (gpio_num == GPIO_NUM_0) {
    button_event_t evt = {.gpio_num = gpio_num,
                          .press_time_ms = tick * portTICK_PERIOD_MS};
    xQueueSendFromISR(button_evt_queue, &evt, NULL);
  }
}

void app_main(void) {
  ESP_LOGI(TAG, "[APP] Startup..");
  ol ESP_LOGI(TAG, "[APP] Free memory: %lu bytes", esp_get_free_heap_size());
  ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

  ESP_ERROR_CHECK(nvs_flash_init());
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());

  // input_set_callback(input_button_callback);
  // input_io_create(GPIO_NUM_0, ANY_EDGE);

  button_evt_queue = xQueueCreate(4, sizeof(button_event_t));
  xTaskCreate(button_task, "button_task", 2048, NULL, 5, NULL);

  // Queue Init
  PhTypes_ErrorCode_t err = Queue_Init();
  if (err != PH_ERR_OK)
    ESP_LOGI(TAG, "Queue_Init error: %d", err);

  // wifi_config();
  // app_mqtt();
  app_spi();
}
