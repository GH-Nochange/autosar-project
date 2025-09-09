#include "app_device.h"
#include "storage_nvs.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define TAG "app_device"

// NVS keys
#define NVS_KEY_SPEED_KMH "speed"
#define NVS_KEY_ENGINE_RPM "rpm"
#define NVS_KEY_FUEL_PCT "fuel"
#define NVS_KEY_LIGHT_ON "light"
#define NVS_KEY_TPMS_KPA "tpms_kpa"
#define NVS_KEY_ENG_TEMP_C "eng_temp"
#define NVS_KEY_DOOR "door"
#define NVS_ENGINE_STATUS "engine_status"
#define NVS_KEY_HVAC "hvac"
#define NVS_KEY_WARNING "warning"

#define EPS_SPEED_KMH 0.5f
#define EPS_RPM 10
#define EPS_FUEL_PCT 0.5f
#define EPS_TPMS_KPA 1.0f
#define EPS_ENG_TEMP_C 0.5f

#define MONITOR_PERIOD_MS 5000

// Sensor API extern
extern float get_vehicle_speed_kmh(void);
extern int32_t get_engine_rpm(void);
extern float get_fuel_level_percent(void);
extern uint8_t get_lighting_status(void);
extern float get_tpms_pressure_kpa(void);
extern float get_engine_temp_c(void);
extern uint8_t get_door_status(void);
extern uint8_t get_engine_status(void);
extern uint8_t get_hvac_status(void);
extern uint8_t get_warning_status(void);

typedef struct
{
    float speed_kmh;
    int32_t engine_rpm;
    float fuel_pct;
    uint8_t light_on;
    float tpms_kpa;
    float eng_temp_c;
    uint8_t door_status;
    uint8_t engine_status;
    uint8_t hvac_status;
    uint8_t warning_status;
} device_state_t;

static TaskHandle_t s_monitor_task = NULL;
static device_state_t s_cached;
static bool s_inited = false;

static inline bool diff_float(float a, float b, float eps)
{
    return fabsf(a - b) > eps;
}

static void save_state_to_nvs(const device_state_t *st)
{
    storage_nvs_set_float(NVS_KEY_SPEED_KMH, st->speed_kmh);
    storage_nvs_set_int(NVS_KEY_ENGINE_RPM, st->engine_rpm);
    storage_nvs_set_float(NVS_KEY_FUEL_PCT, st->fuel_pct);
    storage_nvs_set_uint8(NVS_KEY_LIGHT_ON, st->light_on ? 1 : 0);
    storage_nvs_set_float(NVS_KEY_TPMS_KPA, st->tpms_kpa);
    storage_nvs_set_float(NVS_KEY_ENG_TEMP_C, st->eng_temp_c);
    storage_nvs_set_uint8(NVS_KEY_DOOR, st->door_status);
    storage_nvs_set_uint8(NVS_ENGINE_STATUS, st->engine_status);
    storage_nvs_set_uint8(NVS_KEY_HVAC, st->hvac_status);
    storage_nvs_set_uint8(NVS_KEY_WARNING, st->warning_status);
}

static void read_state_from_sensors(device_state_t *st)
{
    st->speed_kmh = get_vehicle_speed_kmh();
    st->engine_rpm = get_engine_rpm();
    st->fuel_pct = get_fuel_level_percent();
    st->light_on = get_lighting_status();
    st->tpms_kpa = get_tpms_pressure_kpa();
    st->eng_temp_c = get_engine_temp_c();
    st->door_status = get_door_status();
    st->engine_status = get_engine_status();
    st->hvac_status = get_hvac_status();
    st->warning_status = get_warning_status();
}

static void device_monitor_task(void *arg)
{
    (void)arg;

    while (1)
    {
        device_state_t now;
        read_state_from_sensors(&now);

        if (diff_float(now.speed_kmh, s_cached.speed_kmh, EPS_SPEED_KMH))
        {
            storage_nvs_set_float(NVS_KEY_SPEED_KMH, now.speed_kmh);
            s_cached.speed_kmh = now.speed_kmh;
        }
        if ((now.engine_rpm > s_cached.engine_rpm + EPS_RPM) ||
            (now.engine_rpm < s_cached.engine_rpm - EPS_RPM))
        {
            storage_nvs_set_int(NVS_KEY_ENGINE_RPM, now.engine_rpm);
            s_cached.engine_rpm = now.engine_rpm;
        }
        if (diff_float(now.fuel_pct, s_cached.fuel_pct, EPS_FUEL_PCT))
        {
            storage_nvs_set_float(NVS_KEY_FUEL_PCT, now.fuel_pct);
            s_cached.fuel_pct = now.fuel_pct;
        }
        if (now.light_on != s_cached.light_on)
        {
            storage_nvs_set_uint8(NVS_KEY_LIGHT_ON, now.light_on ? 1 : 0);
            s_cached.light_on = now.light_on;
        }
        if (diff_float(now.tpms_kpa, s_cached.tpms_kpa, EPS_TPMS_KPA))
        {
            storage_nvs_set_float(NVS_KEY_TPMS_KPA, now.tpms_kpa);
            s_cached.tpms_kpa = now.tpms_kpa;
        }
        if (diff_float(now.eng_temp_c, s_cached.eng_temp_c, EPS_ENG_TEMP_C))
        {
            storage_nvs_set_float(NVS_KEY_ENG_TEMP_C, now.eng_temp_c);
            s_cached.eng_temp_c = now.eng_temp_c;
        }
        if (now.door_status != s_cached.door_status)
        {
            storage_nvs_set_uint8(NVS_KEY_DOOR, now.door_status);
            s_cached.door_status = now.door_status;
        }
        if (now.engine_status != s_cached.engine_status)
        {
            storage_nvs_set_uint8(NVS_ENGINE_STATUS, now.engine_status);
            s_cached.engine_status = now.engine_status;
        }
        if (now.hvac_status != s_cached.hvac_status)
        {
            storage_nvs_set_uint8(NVS_KEY_HVAC, now.hvac_status);
            s_cached.hvac_status = now.hvac_status;
        }
        if (now.warning_status != s_cached.warning_status)
        {
            storage_nvs_set_uint8(NVS_KEY_WARNING, now.warning_status);
            s_cached.warning_status = now.warning_status;
        }
        vTaskDelay(pdMS_TO_TICKS(MONITOR_PERIOD_MS));
    }
}

void device_init(void)
{
    if (s_inited)
        return;
    ESP_ERROR_CHECK(storage_nvs_init());
    read_state_from_sensors(&s_cached);
    save_state_to_nvs(&s_cached);
    xTaskCreatePinnedToCore(device_monitor_task, "device_monitor",
                            4096, NULL, tskIDLE_PRIORITY + 1,
                            &s_monitor_task, tskNO_AFFINITY);
    s_inited = true;
}

void device_deinit(void)
{
    if (!s_inited)
        return;
    if (s_monitor_task)
    {
        vTaskDelete(s_monitor_task);
        s_monitor_task = NULL;
    }
    s_inited = false;
}
