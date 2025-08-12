#include "nvs_config.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#define NAME "__nvs_user"
#define KEY "config_mode"
#define HOMEID "homeid"

static nvs_handle nvs_handle_user;

// uint8_t va int8_t

int app_flash_get_config_mode(void)
{
    uint8_t config;
    nvs_open(NAME, NVS_READWRITE, &nvs_handle_user);
    nvs_get_u8(nvs_handle_user, KEY, &config);
    printf("get_mode = %d\n", config);
    nvs_close(nvs_handle_user);
    return config;
}

void app_flash_set_config_mode(int mode)
{
    nvs_open(NAME, NVS_READWRITE, &nvs_handle_user);
    nvs_set_u8(nvs_handle_user, KEY, mode);
    printf("set_mode = %d\n", mode);
    nvs_close(nvs_handle_user);
}

char *app_flash_get_home_id(void)
{
    size_t len = 0;
    esp_err_t err;
    nvs_open(NAME, NVS_READWRITE, &nvs_handle_user);
    err = nvs_get_str(nvs_handle_user, HOMEID, NULL, &len);
    char *homeid = calloc(len, sizeof(char));

    err = nvs_get_str(nvs_handle_user, HOMEID, homeid, &len);
    nvs_close(nvs_handle_user);
    
    return homeid;
}

void app_flash_set_home_id(char *homeID)
{
    nvs_open(NAME, NVS_READWRITE, &nvs_handle_user);
    nvs_set_str(nvs_handle_user, HOMEID, homeID);
    printf("set home id = %s\n", homeID);
    nvs_close(nvs_handle_user);
}

void app_flash_restore(void)
{
    ESP_ERROR_CHECK(nvs_flash_erase());
}