#include "app_mqtt.h"
#include "nddmqtt_client.h"
#include "phApp_DataTypes.h"
#include "phQueue.h"
#include "convert.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include <string.h>
#include "stdlib.h"

static const char *TAG = "APP_MQTT";

#define SUB_TOPIC "/car/cmd/#"

#define SPEED_CMD "/car/cmd/speed"
#define SPEED_RSP "/car/rsp/speed"
#define SPEED_NTF "/car/ntf/speed"

#define RPM_NTF "/car/ntf/rpm"

#define FUEL_NTF "/car/ntf/fuel"

#define LIGHT_CMD "/car/cmd/light"
#define LIGHT_NTF "/car/ntf/light"

#define TPMS_NTF "/car/ntf/tpms"

#define ENG_TEMP_NTF "/car/ntf/eng_temp"

#define DOOR_CMD "/car/cmd/door"
#define DOOR_NTF "/car/ntf/door"

#define ENGINE_CMD "/car/cmd/engine"
#define ENGINE_NTF "/car/ntf/engine"

#define HVAC_CMD "/car/cmd/hvac"
#define HVAC_NTF "/car/ntf/hvac"

#define WARNING_CMD "/car/cmd/warning"
#define WARNING_NTF "/car/ntf/warning"

typedef enum
{
    SPEED_CMD_ID,
    SPEED_RSP_ID,
    SPEED_NTF_ID,
    RPM_NTF_ID,
    FUEL_NTF_ID,
    LIGHT_CMD_ID,
    LIGHT_NTF_ID,
    TPMS_NTF_ID,
    ENG_TEMP_NTF_ID,
    DOOR_CMD_ID,
    DOOR_NTF_ID,
    ENGINE_CMD_ID,
    ENGINE_NTF_ID,
    HVAC_CMD_ID,
    HVAC_NTF_ID,
    WARNING_CMD_ID,
    WARNING_NTF_ID,
} topic_id_t;

#include <string.h>
#include <stdio.h>

topic_id_t topic_to_id(const char *topic, int topic_len)
{
    char tbuf[128] = {0};
    int copy_len = (topic_len < sizeof(tbuf) - 1) ? topic_len : (sizeof(tbuf) - 1);
    memcpy(tbuf, topic, copy_len);
    tbuf[copy_len] = '\0';

    if (strcmp(tbuf, SPEED_CMD) == 0)
        return SPEED_CMD_ID;
    if (strcmp(tbuf, SPEED_RSP) == 0)
        return SPEED_RSP_ID;
    if (strcmp(tbuf, SPEED_NTF) == 0)
        return SPEED_NTF_ID;
    if (strcmp(tbuf, RPM_NTF) == 0)
        return RPM_NTF_ID;
    if (strcmp(tbuf, FUEL_NTF) == 0)
        return FUEL_NTF_ID;
    if (strcmp(tbuf, LIGHT_CMD) == 0)
        return LIGHT_CMD_ID;
    if (strcmp(tbuf, LIGHT_NTF) == 0)
        return LIGHT_NTF_ID;
    if (strcmp(tbuf, TPMS_NTF) == 0)
        return TPMS_NTF_ID;
    if (strcmp(tbuf, ENG_TEMP_NTF) == 0)
        return ENG_TEMP_NTF_ID;
    if (strcmp(tbuf, DOOR_CMD) == 0)
        return DOOR_CMD_ID;
    if (strcmp(tbuf, DOOR_NTF) == 0)
        return DOOR_NTF_ID;
    if (strcmp(tbuf, ENGINE_CMD) == 0)
        return ENGINE_CMD_ID;
    if (strcmp(tbuf, ENGINE_NTF) == 0)
        return ENGINE_NTF_ID;
    if (strcmp(tbuf, HVAC_CMD) == 0)
        return HVAC_CMD_ID;
    if (strcmp(tbuf, HVAC_NTF) == 0)
        return HVAC_NTF_ID;
    if (strcmp(tbuf, WARNING_CMD) == 0)
        return WARNING_CMD_ID;
    if (strcmp(tbuf, WARNING_NTF) == 0)
        return WARNING_NTF_ID;

    return -1;
}

void mqtt_data_callback(char *topic, int topic_len, char *data, int len)
{
    switch (topic_to_id(topic, topic_len))
    {
    case SPEED_CMD_ID:
        if (len == 4)
        {
            ESP_LOGI("MQTT", "speed limit: %.2f", Convert_Bytes_To_Float(data[0], data[1], data[2], data[3]));
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_SPEED;
            msg.header.length = len;
            for (int i = 0; i < len; i++)
            {
                msg.payload[i] = data[i];
            }
        }
        break;
    case LIGHT_CMD_ID:
        if (len == 1)
        {
            ESP_LOGI("MQTT", "Handle LIGHT CMD: %d", data[0]);
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_LIGHT;
            msg.header.length = len;
            msg.payload[0] = data[0];
            phQueue_Send(&msg);
        }
        break;

    case DOOR_CMD_ID:
        if (len == 1)
        {
            ESP_LOGI("MQTT", "Handle DOOR CMD: %d", data[0]);
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_DOOR;
            msg.header.length = len;
            msg.payload[0] = data[0];
            phQueue_Send(&msg);
        }
        break;

    case ENGINE_CMD_ID:
        if (len == 1)
        {
            ESP_LOGI("MQTT", "Handle ENGINE CMD: %d", data[0]);
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_ENGINE;
            msg.header.length = len;
            msg.payload[0] = data[0];
            phQueue_Send(&msg);
        }
        break;

    case HVAC_CMD_ID:
        if (len == 5)
        {
            ESP_LOGI("MQTT", "Handle HVAC CMD: Temperature: %.2f°C, Fan speed: %d", Convert_Bytes_To_Float(data[0], data[1], data[2], data[3]), data[4]);
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_HVAC;
            msg.header.length = len;
            memcpy(msg.payload, data, len);
            phQueue_Send(&msg);
        }
        break;

    case WARNING_CMD_ID:
        if (len == 1)
        {
            ESP_LOGI("MQTT", "Handle WARNING CMD: %d", data[0]);
            phApp_Data_t msg;
            msg.header.group = PH_COMMAND;
            msg.header.ecu = PH_HOST1;
            msg.header.id = PH_WARNING;
            msg.header.length = len;
            msg.payload[0] = data[0];
            phQueue_Send(&msg);
        }
        break;

    default:
        ESP_LOGW("MQTT", "Unknown topic: %.*s", topic_len, topic);
        break;
    }
}

void app_mqtt(void)
{
    mqtt_init();
    mqtt_set_callback(mqtt_data_callback);

    mqtt_sub(SUB_TOPIC);
    mqtt_start();
}