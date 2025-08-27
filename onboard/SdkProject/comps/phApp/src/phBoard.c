#include "phBoard.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include "phCom.h"
#include "phLed.h"
#include "phApp_Spi.h"
#include "phMcu.h"
#include "phCan.h"

PhTypes_ErrorCode_t phBoard_Recv(phApp_Data_t *data)
{
   
    if (!QueueRX_IsFull())
    {
        (void)QueueRX_Push(data);
        

    }
    else
    {
        return PH_ERR_FAILED;
    }
}

PhTypes_ErrorCode_t phBoard_Send(phApp_Data_t *data)
{
    return QueueTX_Push(data);
}

static PhTypes_ErrorCode_t phBoard_ProcessCmd(phApp_Data_t *data)
{
    if (data->header.ecu == PH_IC1)
    {
//        phApp_SpiPrepareData(data);
        return PH_ERR_OK;
    }
    else if (data->header.ecu != PH_BOARD1)
        return PH_ERR_FAILED;

    switch (data->header.id)
    {
    case PH_ECHO_REVERSE:
        data->header.group = PH_RESPONSE;

        uint8_t i, temp;
        uint16_t n = data->header.length;
        for (i = 0; i < n / 2; i++)
        {
            temp = data->payload[i];
            data->payload[i] = data->payload[n - 1 - i];
            data->payload[n - 1 - i] = temp;
        }
        phBoard_Send(data);
        break;
    case PH_VERSION:
        data->header.group = PH_RESPONSE;
        data->header.length = PH_VERSION_LEN;
        data->payload[0] = PH_MAJOR_VERSION;
        data->payload[1] = PH_MINOR_VERSION;
        data->payload[2] = PH_PATCH_VERSION;

        phBoard_Send(data);
        break;
    case PH_RESET:
        data->header.group = PH_RESPONSE;

        phBoard_Send(data);

        phMcu_PerformReset(); // McuInit -> send Ntf reason reset trigger Flash.
        break;
    case PH_LED:
        phSetLed(data->payload[0]);
        data->header.group = PH_RESPONSE;
        data->payload[0] = PH_ERR_OK;

        phBoard_Send(data);
        break;
    }
}

static PhTypes_ErrorCode_t phBoard_ProcessResp(phApp_Data_t *data)
{
    if (data->header.ecu == PH_IC1)
    {
        QueueTX_Push(data);
        return PH_ERR_OK;
    }
    else if (data->header.ecu != PH_BOARD1)
        return PH_ERR_FAILED;

    // switch (data->header.id)
    // {
    // case PH_ECHO_REVERSE:
    //     // Check
    //     break;
    // case PH_VERSION:
    //     break;
    // case PH_RESET:
    //     break;
    // case PH_LED:
    //     break;
    // }
}

static PhTypes_ErrorCode_t phBoard_ProcessNtf(phApp_Data_t *data)
{
    if (data->header.ecu == PH_IC1)
    {
        QueueTX_Push(data);
        return PH_ERR_OK;
    }
    else if (data->header.ecu != PH_BOARD1)
        return PH_ERR_FAILED;

    // switch (data->header.id)
    // {
    // case PH_RESET:
    //     break;
    // case PH_LED:
    //     break;
    // }
}

static PhTypes_ErrorCode_t phBoard_RxProcessing(phApp_Data_t *data)
{

    if (data == NULL || data->payload == NULL)
        return PH_ERR_INVALID_ARG;
    switch (data->header.group)
    {
    case PH_COMMAND:
        return phBoard_ProcessCmd(data);
        break;
    case PH_RESPONSE:
        return phBoard_ProcessResp(data);
        break;
    case PH_NOTIFY:
        return phBoard_ProcessNtf(data);
        break;
    default:
        break;
    }
}

static PhTypes_ErrorCode_t phBoard_CreateFrame(phApp_Group_t group, phApp_Ecu_t ecu, phApp_Id_t id, uint16_t length, uint8_t *value, phApp_Data_t *dataout)
{
    if (value == NULL || dataout == NULL)
        return PH_ERR_INVALID_ARG;
    dataout->header.group == group;
    dataout->header.ecu = ecu;
    dataout->header.id = id;
    dataout->header.length = length;
    memcpy(dataout->payload, value, dataout->header.length);

    return PH_ERR_OK;
}

void phBoard_Init()
{
    phMcu_Init();
    Queue_Init();
    phGpio_Init();
    phCan0_Init();
    phApp_SpiInit();
}

void phBoard_MainFunction()
{

    PhTypes_ErrorCode_t err = PH_ERR_OK;
    if(!QueueRX_IsEmpty())
    {
        phApp_Data_t data;
        err = QueueRX_Front(&data);
        if(err == PH_ERR_OK)
        {
            err = phBoard_RxProcessing(&data);
        }
        if(err == PH_ERR_OK)
            QueueRX_Pop(&data);
    }
    phCom_MainFunctionTx();
    phApp_SpiMainFunction();
}
