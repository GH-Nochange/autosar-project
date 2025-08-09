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
        Internal = 0b000,
        LedState = 0b001,
        Brightness = 0b010,
        LedStateAndBrightness = 0b011,
        Cmd_CAN = 0b100,
        Cmd_SPI = 0b101
    } phApp_Id_t;

    typedef enum
    {
        SetProtocol = 0x00,
    } phApp_Internal_t;

    typedef enum
    {
        Cmd_LED_State = 0x01,
        Cmd_Brightness = 0x02,
        Cmd_LedStateAndBrightness = 0x03,
        Cmd_LedControl = 0x04
    } phApp_Cmd_t;


    typedef struct
    {
        uint16_t id : 3; // Internal Signal, LedState Signal, Led Controll, Brightness Signal, LedState & Brightness
        uint16_t rfu : 13;
        uint16_t length;
    } phApp_header_t;

    typedef struct
    {
        phApp_header_t header;
        uint8_t payload[PAYLOAD_SIZE];
    } phApp_DataTypes_t;


#ifdef __cplusplus
}
#endif

#endif // PHAPP_DATATYPES_H
