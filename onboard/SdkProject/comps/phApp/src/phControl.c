#include "phApp_DataTypes.h"
#include "phLightSensor.h"
#include "phControl.h"
#include "phConvert.h"
#include "phQueue.h"
#include "S32K144.h"

static void phCreate_Notify(phApp_Id_t id, uint8_t value, phApp_DataTypes_t *dataout)
{
    if (dataout == NULL)
        return 0;
    dataout->length = 14;
    dataout->group = PH_NOTIFY;
    dataout->id = id;
    dataout->payload[0] = value;
    dataout->payload[1] = value; 
    dataout->payload[2] = value;
    dataout->payload[3] = value;
    dataout->payload[4] = value;
    dataout->payload[5] = value;
    dataout->payload[6] = value;
    dataout->payload[7] = value;
    dataout->payload[8] = value;
    dataout->payload[9] = value;
    dataout->payload[10] = value;
    dataout->payload[11] = value;
    dataout->payload[12] = value;
}

void Control_MainFunction(void)
{
    phApp_DataTypes_t data= {0};
    phCreate_Notify(LIGHT_SENSOR, 3, &data);
    (void)TransmitSignal(data);
}

PhTypes_ErrorCode_t TransmitSignal(phApp_DataTypes_t data)
{
    return QueueTX_Push(&data, data.length + 2);
}