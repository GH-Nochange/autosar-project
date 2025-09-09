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
        PH_RESPONSE = 0b0001,
        PH_NOTIFY = 0b0010
    } phApp_Group_t;

    typedef enum
    {
        PH_HOST1 = 0b1000,
        PH_BOARD1 = 0b0100,
        PH_IC1 = 0b0000,
    } phApp_Ecu_t; 

    typedef enum
    {
        PH_ECHO_REVERSE,
        PH_VERSION,
        PH_RESET,
        PH_LED,

        PH_SPEED,
        PH_RPM,
        PH_FUEL,
        PH_LIGHT,
        PH_TPMS,
        PH_ENG_TEMP,
        PH_DOOR,
        PH_ENGINE,
        PH_HVAC,
        PH_WARNING,
        
    } phApp_Id_t;

    typedef struct __attribute__((packed)) {
    uint16_t group : 4;  
    uint16_t ecu   : 4;   
    uint16_t id    : 8;   
    uint16_t length;      
    } phApp_Header_t;

    typedef struct
    {
        phApp_Header_t header;
        uint8_t payload[PAYLOAD_SIZE];
    } phApp_Data_t;


    
#ifdef __cplusplus
}
#endif

#endif // PHAPP_DATATYPES_H
