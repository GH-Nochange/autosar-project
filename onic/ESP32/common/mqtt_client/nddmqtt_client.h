#ifndef __NDD_MQTT_CLIENT_H__
#define __NDD_MQTT_CLIENT_H__

typedef void (*mqtt_handle_t)(char *topic, int topic_len, char *data, int len);

void mqtt_init(void);
void mqtt_start(void);
void mqtt_set_callback(void *cb);
void mqtt_pub(char *topic, char *data, int len);
void mqtt_sub(char *topic);

#endif // __NDD_MQTT_CLIENT_H__
