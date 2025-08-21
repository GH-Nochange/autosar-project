#ifndef PHAPP_DATATYPES_H
#define PHAPP_DATATYPES_H

#include <stdint.h>

#define PAYLOAD_SIZE 256
#define MESSAGE_SIZE 260

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        PH_COMMAND = 0b0000,
        PH_NOTIFY = 0b0001,
        PH_RESPONSE = 0b0010
    } phApp_Group_t;

    typedef enum
    {
        PH_HOST1 = 0b1000,
        PH_BOARD1 = 0b0100,
        PH_IC1 = 0b0000,
    } phApp_Ecu_t; // change 2bit low

    typedef enum
    {
        PH_ECHO_REVERT,
        PH_VERSION,
        PH_RESET_SOFT,
        PH_LED,
    } phApp_Id_t;

    typedef struct
    {
        phApp_Group_t group;
        phApp_Ecu_t ecu;
        phApp_Id_t id;
        uint16_t length;
    } phApp_Hearder_t;

    typedef struct
    {
        phApp_Hearder_t header;
        uint8_t payload[PAYLOAD_SIZE];
    } phApp_Data_t;

#ifdef __cplusplus
}
#endif

#endif // PHAPP_DATATYPES_H
