#include "storage_nvs.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#define USER_NAMESPACE "__storage_nvs"

static nvs_handle my_handle;


void storage_nvs_set_uint8(char *key, uint8_t value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }

    err = nvs_set_u8(my_handle, key, value);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    err = nvs_commit(my_handle);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    nvs_close(my_handle);
}

void storage_nvs_set_int(char *key, int value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    { 
        printf("nvs open fail\n");
    }

    err = nvs_set_i32(my_handle, key, value);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    err = nvs_commit(my_handle);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    nvs_close(my_handle);
}

void storage_nvs_set_float(char *key, float value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }

    err = nvs_set_f32(my_handle, key, value);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    err = nvs_commit(my_handle);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    nvs_close(my_handle);
}

void storage_nvs_set_string(char *key, char* str)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }

    err = nvs_set_str(my_handle, key, str);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    err = nvs_commit(my_handle);
    printf((err != ESP_OK) ? "failed\n" : "Done\n");
    nvs_close(my_handle);
}

void storage_nvs_get_uint8(char *key, uint8_t *value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }
    err = nvs_get_u8(my_handle, key, value);
    switch (err)
    {
    case ESP_OK:
        printf("Done ok\n");
        printf("%s - %d\n", key, *value);
        break;

    case ESP_ERR_NOT_FOUND:
        printf("The value is not initialized\n");
        break;

    default:
        printf("error (%s) reading!\n", esp_err_to_name(err));
        break;
    }
    nvs_close(my_handle);
}

void storage_nvs_get_int(char *key, int *value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }
    err = nvs_get_i32(my_handle, key, value);
    switch (err)
    {
    case ESP_OK:
        printf("Done ok\n");
        printf("%s - %d\n", key, *value);
        break;

    case ESP_ERR_NOT_FOUND:
        printf("The value is not initialized\n");
        break;

    default:
        printf("error (%s) reading!\n", esp_err_to_name(err));
        break;
    }
    nvs_close(my_handle);
}

void storage_nvs_get_float(char *key, float *value)
{
    esp_err_t err;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }
    err = nvs_get_f32(my_handle, key, value);
    switch (err)
    {
    case ESP_OK:
        printf("Done ok\n");
        printf("%s - %f\n", key, *value);
        break;

    case ESP_ERR_NOT_FOUND:
        printf("The value is not initialized\n");
        break;

    default:
        printf("error (%s) reading!\n", esp_err_to_name(err));
        break;
    }
    nvs_close(my_handle);
}

void storage_nvs_get_string(char *key, char *out)
{
    esp_err_t err;
    size_t length=0;
    err = nvs_open(USER_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        printf("nvs open fail\n");
    }
    err = nvs_get_str(my_handle, key, out, &length);
    err =0;
    err = nvs_get_str(my_handle, key, out, &length);
    switch (err)
    {
    case ESP_OK:
        printf("Done ok\n");
        printf("%s - %s, length= %d \n", key, out, length);
        break;

    case ESP_ERR_NOT_FOUND:
        printf("The value is not initialized\n");
        break;

    default:
        printf("error (%s) reading!\n", esp_err_to_name(err));
        break;
    }
    nvs_close(my_handle);
}

