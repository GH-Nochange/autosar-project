#ifndef STORAGE_NVS_H
#define STORAGE_NVS_H

void storage_nvs_get_uint8(char *key, uint8_t *value);
void storage_nvs_set_uint8(char *key, uint8_t value);

void storage_nvs_get_int(char *key, int *value);
void storage_nvs_set_int(char *key, int value);

void storage_nvs_get_float(char *key, float *value);
void storage_nvs_set_float(char *key, float value);

void storage_nvs_get_string(char *key, char *out);
void storage_nvs_set_string(char *key, char *str);

#endif