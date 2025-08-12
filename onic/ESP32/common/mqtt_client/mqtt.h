#ifndef __MQTT_H__
#define __MQTT_H__

typedef void(*mqtt_handle_t)(char *data, int len);

void mqtt_init(void);
void mqtt_start(void);
void mqtt_set_callback(void *cb);
void mqtt_pub(char *topic, char *data, int len);
void mqtt_sub(char *topic);

#endif // __MQTT_H__
