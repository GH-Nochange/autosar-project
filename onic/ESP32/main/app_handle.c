#include "app_handle.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "output.h"

#define APP_RX_TASK_NAME "app_rx_task"
#define APP_RX_TASK_STACK (4096)
#define APP_RX_TASK_PRIO (tskIDLE_PRIORITY + 2)
#define APP_RX_POLL_MS (10)
#define APP_RX_BATCH_LIMIT (32)

static const char *TAG = "app_handle";
static TaskHandle_t s_app_task = NULL;

static void app_process(phApp_Data_t *msg);
static void app_process_batch(void);
static void app_rx_task(void *arg);


static PhTypes_ErrorCode_t app_send(phApp_Data_t *data)
{
    return QueueTX_Push(data);
}

void app_handle(void)
{
    if (s_app_task != NULL)
    {
        return;
    }

    if (Queue_Init() != PH_ERR_OK)
    {
        ESP_LOGE(TAG, "Queue init failed");
        return;
    }

    BaseType_t ok = xTaskCreate(
        app_rx_task,
        APP_RX_TASK_NAME,
        APP_RX_TASK_STACK,
        NULL,
        APP_RX_TASK_PRIO,
        &s_app_task);

    if (ok != pdPASS)
    {
        ESP_LOGE(TAG, "Create %s failed", APP_RX_TASK_NAME);
        s_app_task = NULL;
    }
    else
    {
        ESP_LOGI(TAG, "%s started", APP_RX_TASK_NAME);
    }
}

static void app_rx_task(void *arg)
{
    (void)arg;

    for (;;)
    {
        if (!QueueRX_IsEmpty())
        {
            app_process_batch();
        }
        else
        {
            vTaskDelay(pdMS_TO_TICKS(APP_RX_POLL_MS));
        }
    }
}

static void app_process_batch(void)
{
    phApp_Data_t msg;
    uint32_t handled = 0;

    while (!QueueRX_IsEmpty() && handled < APP_RX_BATCH_LIMIT)
    {
        if (QueueRX_Pop(&msg) == PH_ERR_OK)
        {
            app_process(&msg);
            handled++;
        }
        else
        {
            break;
        }
    }
}

static void app_process(phApp_Data_t *msg)
{
    if (msg == NULL || msg->payload == NULL)
    {
        ESP_LOGW(TAG, "Invalid message pointer: msg=%p payload=%p", msg, msg ? msg->payload : NULL);
        return;
    }
    if (msg->header.ecu == PH_IC1 && msg->header.group == PH_COMMAND)
    {
        switch (msg->header.id)
        {
        case PH_ECHO_REVERSE:
            msg->header.group == PH_RESPONSE;
            uint8_t i, temp;
            uint16_t n = msg->header.length;
            for (i = 0; i < n / 2; i++)
            {
                temp = msg->payload[i];
                msg->payload[i] = msg->payload[n - 1 - i];
                msg->payload[n - 1 - i] = temp;
            }
            if(app_send(msg) != PH_ERR_OK)
            {
                ESP_LOGW(TAG, "Send fail!");
            }
            break;
        case PH_VERSION:
            msg->header.group = PH_RESPONSE;
            msg->header.length = PH_VERSION_LEN;
            msg->payload[0] = PH_MAJOR_VERSION;
            msg->payload[1] = PH_MINOR_VERSION;
            msg->payload[2] = PH_PATCH_VERSION;

            if(app_send(msg) != PH_ERR_OK)
            {
                ESP_LOGW(TAG, "Send fail!");
            }
            break;
        case PH_RESET:
            msg->header.group = PH_RESPONSE;
            msg->header.length = 1;
            msg->payload[0] = PH_ERR_OK; 
            if(app_send(msg) != PH_ERR_OK)
            {
                ESP_LOGW(TAG, "Send fail!");
            }

            vTaskDelay(pdMS_TO_TICKS(500));

            esp_restart();
            break;
        case PH_LED:
            msg->header.group = PH_RESPONSE;
            if (msg->payload[0] >= 0 && msg->payload[0] <= 1)
            {
                output_io_set_level(msg->payload[0]);
                msg->payload[0] = PH_ERR_OK;
            }
            else
            {
                msg->payload[0] = PH_ERR_INVALID_ARG;
            }
            app_send(msg);
            break;
        default:
            break;
        }
    }
}
