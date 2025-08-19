#include "app_mqtt.h"
#include "nddmqtt_client.h"
#include "phApp_DataTypes.h"
#include "phQueue.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include <string.h>

static const char *TAG = "APP_MQTT";
#define MQTT_PUB_TOPIC "topic/tx"

void mqtt_data_callback(char *dt, int len)
{
    char buf[256] = {0};
    int length = (len > 255) ? 255 : len;
    memcpy(buf, dt, length);
    buf[length] = '\0';

    phApp_DataTypes_t data;
    data.length = len;
    data.group = dt[0];
    data.id = dt[1];
    for (int i = 0; i < len - 2; i++)
    {
        data.payload[i] = dt[i + 2];
    }
    QueueTX_Push(&data, length + 2);
    printf("DATA=%s\n", buf);
}

static void mqtt_pub_task(void *arg)
{
    phApp_DataTypes_t msg;

    for (;;)
    {
        if (QueueRX_Pop(&msg))
        {
            char frame[256];
            int n = 0;

            frame[n++] = msg.group;
            frame[n++] = msg.id;

            int copy = msg.length;
            if (copy > sizeof(frame) - 2)
                copy = sizeof(frame) - 2;
            memcpy(&frame[2], msg.payload, copy);
            n += copy;

            mqtt_pub(MQTT_PUB_TOPIC, frame, n);

            ESP_LOGI(TAG, "Published %d bytes (grp=%u id=%u)", n, msg.group, msg.id);
        }
    }
}

void app_mqtt(void)
{
    mqtt_init();
    mqtt_set_callback(mqtt_data_callback);
    mqtt_start();
    // xTaskCreate(mqtt_pub_task, "mqtt_pub_task", 4096, NULL, 8, NULL);
}