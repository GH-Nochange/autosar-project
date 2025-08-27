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
    if (len < 4)
    {
        ESP_LOGW(TAG, "Frame to short %d", len);
        return;
    }
    phApp_Data_t data;
    memset(&data, 0, sizeof(data));

    data.header.group = (dt[0] >> 4) & 0x0F;
    data.header.ecu = dt[0] & 0x0F;

    data.header.id = dt[1];

    data.header.length = (dt[2] << 8) | dt[3];

    int length = data.header.length;
    if (length > (len - 4))
    {
        length = len - 4;
    }

    memcpy(data.payload, &dt[4], len);
    QueueRX_Push(&data);

    ESP_LOGI(TAG, "Received frame grp=%u ecu=%u id=%u len=%u (copied=%d)",
             data.header.group, data.header.ecu,
             data.header.id, data.header.length, length);
}

static void mqtt_pub_task(void *arg)
{
    phApp_Data_t msg;

    for (;;)
    {
        if (QueueRX_Pop(&msg))
        {
            char frame[MESSAGE_SIZE];
            int n = 0;

            frame[n++] = ((msg.header.group & 0x0F) << 4) | (msg.header.ecu & 0x0F);
            frame[n++] = msg.header.id;

            frame[n++] = ((msg.header.length >> 8) & 0xFF);
            frame[n++] = (msg.header.length & 0xFF);
            int copy = msg.header.length;
            if (copy > sizeof(frame) - n)
                copy = sizeof(frame) - n;
            memcpy(&frame[n], msg.payload, copy);
            n += copy;

            mqtt_pub(MQTT_PUB_TOPIC, frame, n);

            ESP_LOGI(TAG, "Published %d bytes (grp=%u id=%u)", n, msg.header.group, msg.header.id);
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