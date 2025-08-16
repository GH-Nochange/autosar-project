#include "phApp_DataTypes.h"
#include "phLightSensor.h"
#include "phControl.h"
#include "phConvert.h"
#include "phQueue.h"

static void phCreate_Notify(phApp_Id_t id, uint8_t value, phApp_DataTypes_t *dataout)
{
    if (dataout == NULL)
        return 0;
    dataout->length = 3;
    dataout->group = PH_NOTIFY;
    dataout->id = id;
    dataout->payload[0] = value;
}

void Control_MainFunction(void)
{
    if(!QueueRX_IsEmpty())
    {
        phApp_DataTypes_t data1 = {0};
        if (QueueRX_Pop(&data1) != PH_ERR_OK)
            return;
        (void)TransmitSignal(data1);
    }
    phApp_DataTypes_t data= {0};
    phCreate_Notify(LIGHT_SENSOR, 3, &data);
    (void)TransmitSignal(data);
}

PhTypes_ErrorCode_t TransmitSignal(phApp_DataTypes_t data)
{
    QueueTX_Push(&data, data.length + 2);
}