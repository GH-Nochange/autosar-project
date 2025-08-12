#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"
#include "mqtt.h"

static const char *TAG = "MQTT";

extern const uint8_t ca_cert_pem_start[] asm("_binary_ca_crt_start");
extern const uint8_t ca_cert_pem_end[] asm("_binary_ca_crt_end");

extern const uint8_t client_cert_pem_start[] asm("_binary_client_crt_start");
extern const uint8_t client_cert_pem_end[] asm("_binary_client_crt_end");

extern const uint8_t client_key_pem_start[] asm("_binary_client_key_start");
extern const uint8_t client_key_pem_end[] asm("_binary_client_key_end");

static esp_mqtt_client_handle_t client = NULL;
static mqtt_handle_t mqtt_handle = NULL;


static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t) event_data;
    client = event->client;

    switch ((esp_mqtt_event_id_t) event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        mqtt_sub("/topic/test");
        break;

    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        mqtt_pub("/topic/test", "Hello MQTT", 10);
        break;

    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;

    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;

    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");

        mqtt_handle(event->data, event->data_len);

        break;

    case MQTT_EVENT_ERROR:
        ESP_LOGE(TAG, "MQTT_EVENT_ERROR");
        break;

    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

void mqtt_start(void)
{
    esp_mqtt_client_start(client);
}

void mqtt_init(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        // .broker.address.uri = "mqtt://192.168.54.198:1883",
        .broker.address.uri = "mqtts://192.168.54.198:8883",
        .broker.verification = {
            .certificate = (const char *)ca_cert_pem_start,
            .certificate_len = ca_cert_pem_end - ca_cert_pem_start,
            .skip_cert_common_name_check = true, // Skip CN check for simplicity, not recommended for production
        },
        .credentials = {
            .authentication = {
                .certificate = (const char *)client_cert_pem_start,
                .certificate_len = client_cert_pem_end - client_cert_pem_start,
                .key = (const char *)client_key_pem_start,
                .key_len = client_key_pem_end - client_key_pem_start,
            }
        }
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, MQTT_EVENT_ANY, mqtt_event_handler, NULL);

    ESP_LOGI(TAG, "Free mamory: %lu bytes", esp_get_free_heap_size());
}

void mqtt_set_callback(void *cb)
{
    if(cb){
        mqtt_handle = cb;
    }
}

void mqtt_sub(char *topic)
{
    esp_mqtt_client_subscribe(client, topic, 1);
}

void mqtt_pub(char *topic, char *data, int len)
{
    esp_mqtt_client_publish(client, topic, data, len, 1, 0);
}
