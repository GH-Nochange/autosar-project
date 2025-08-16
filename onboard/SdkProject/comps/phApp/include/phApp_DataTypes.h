#ifndef PHAPP_DATATYPES_H
#define PHAPP_DATATYPES_H

#include <stdint.h>

#define PAYLOAD_SIZE 256

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        LED,
        LIGHT_SENSOR,
    } phApp_Id_t;


    typedef enum
    {
        PH_COMMAND,
        PH_NOTIFY,
        PH_RESPONSE
    } phApp_Group_t;


    typedef struct
    {
        uint16_t length;
        uint8_t group;
        uint8_t id;
        uint8_t payload[PAYLOAD_SIZE];
    } phApp_DataTypes_t;

#ifdef __cplusplus
}
#endif

#endif // PHAPP_DATATYPES_H
