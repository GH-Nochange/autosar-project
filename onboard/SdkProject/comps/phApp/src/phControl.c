#include "phApp_DataTypes.h"
#include "phLightSensor.h"
#include "phControl.h"
#include "phConvert.h"
#include "phComQueue.h"

static void CreateInternalData(phApp_Internal_t key, uint8_t value, phApp_DataTypes_t *dataout)
{
    dataout->header.id = Internal;
    dataout->header.length = 2;
    dataout->payload[0] = key;
    dataout->payload[1] = value;
}

static void CreateLedStateData(uint8_t state, phApp_DataTypes_t *dataout)
{
    dataout->header.id = LedState;
    dataout->header.length = 1;
    dataout->payload[0] = state;
}

static void CreateBrightnessData(float brightness, phApp_DataTypes_t *dataout)
{
    dataout->header.id = Brightness;
    dataout->header.length = 4;

    uint8_t *pBrightness = Convert_Float_To_Bytes(brightness);
    for (int i = 0; i <= 3; i++)
    {
        dataout->payload[i] = pBrightness[i];
    }
}

static void CreateLedStateAndBrightnessData(uint8_t state, float brightness, phApp_DataTypes_t *dataout)
{
    dataout->header.id = LedStateAndBrightness;
    dataout->header.length = 5;
    dataout->payload[0] = state;

    uint8_t *pBrightness = Convert_Float_To_Bytes(brightness);
    for (int i = 0; i <= 3; i++)
    {
        dataout->payload[i + 1] = pBrightness[i];
    }
}

static void CreateLedControlData(uint8_t control, phApp_DataTypes_t *dataout)
{
    dataout->header.id = Cmd_CAN;
    dataout->header.length = 2;
    dataout->payload[0] = Cmd_LedControl;
    dataout->payload[1] = control;
}

PhTypes_ErrorCode_t TransmitSignal(phApp_DataTypes_t data)
{
    return QueueTX_Push(&data);
}

PhTypes_ErrorCode_t ReceiveSignal(phApp_DataTypes_t *data)
{
    return QueueRX_Pop(data);
}

void Control_MainFunction(void)
{
    float brightness = LightSensor_GetBrightness();
    uint8_t LedState = LightSensor_GetLedState();
    while (!QueueRX_IsEmpty())
    {
        brightness = LightSensor_GetBrightness();
        LedState = LightSensor_GetLedState();
        phApp_DataTypes_t data;
        if (ReceiveSignal(&data) == ERR_Ok)
        {
            switch (data.header.id)
            {
            case Cmd_CAN:
                phApp_DataTypes_t internalData;
                CreateInternalData(SetProtocol, 0, &internalData);
                TransmitSignal(internalData);
                if (data.header.length == 2 && data.payload[0] == Cmd_LedControl)
                {
                    uint8_t control = data.payload[1];
                    LED_SetState(control);
                }

                break;
            case Cmd_SPI:
                // Xử lý tín hiệu Command_SPI
                phApp_DataTypes_t dataResponse;
                // Routing SPI
                phApp_DataTypes_t internalData;
                CreateInternalData(SetProtocol, 0x01, &internalData);
                TransmitSignal(internalData);
                switch (data.payload[0])
                {
                case Cmd_LED_State:
                    CreateLedStateData(LedState, &dataResponse);
                    TransmitSignal(dataResponse);
                    break;
                case Cmd_Brightness:
                    CreateBrightnessData(brightness, &dataResponse);
                    TransmitSignal(dataResponse);
                    break;
                case Cmd_LedStateAndBrightness:
                    CreateLedStateAndBrightnessData(LedState, brightness, &dataResponse);
                    TransmitSignal(dataResponse);
                    break;
                case Cmd_LedControl:
                    iff(data.header.length == 2)
                    {
                        uint8_t control = data.payload[1];
                        LED_SetState(control);
                        CreateLedStateData(LED_GetState(), &dataResponse);
                        TransmitSignal(dataResponse);
                    }
                    break;
                default:
                    break;
                }
            default:
                // Xử lý các tín hiệu không xác định
                break;
            }
        }
    }
}