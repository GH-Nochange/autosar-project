#include "phBoard.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include "phCom.h"


PhTypes_ErrorCode_t phBoard_Recv(phApp_Data_t *data)
{
    if(!QueueRX_IsFull())
    {
        QueueRX_Push(data);
    } else {
        return PH_ERR_FAILED;
    }
}

PhTypes_ErrorCode_t phBoard_Send(phApp_Data_t *data) 
{
    return phCom_Send(data);
}

static PhTypes_ErrorCode_t phBoard_ProcessCmd(phApp_Data_t *data)
{
    if(data->header.ecu != PH_BOARD1) return PH_ERR_INVALID_ARG;

    switch(data->header.id)
    {
        case PH_ECHO_REVERT:

            break;
        case PH_VERSION:
            break;
        case PH_RESET_SOFT:
            break;
        case PH_LED:
            break;
    }
}

static PhTypes_ErrorCode_t phBoard_ProcessResp(phApp_Data_t *data)
{
    switch(data->header.id)
    {
        case PH_ECHO_REVERT:

            break;
        case PH_VERSION:
            break;
        case PH_RESET_SOFT:
            break;
        case PH_LED:
            break;
    }
}

static PhTypes_ErrorCode_t phBoard_ProcessNtf(phApp_Data_t *data)
{
    switch(data->header.id)
    {
        case PH_ECHO_REVERT:

            break;
        case PH_VERSION:
            break;
        case PH_RESET_SOFT:
            break;
        case PH_LED:
            break;
    }
}

static PhTypes_ErrorCode_t phBoard_RxProcessing(phApp_Data_t *data)
{
    if(data == NULL || data->payload == NULL) return PH_ERR_INVALID_ARG;
    switch (data->header.group)
    {
    case PH_COMMAND:
        
        break;
    case PH_RESPONSE:
        
        break;
    case PH_NOTIFY:
        
        break;
    default:
        break;
    }
}

static PhTypes_ErrorCode_t phBoard_CreateCommand(uint8_t ecu, uint8_t id, uint32_t value, phApp_Data_t *dataout)
{

}

static PhTypes_ErrorCode_t phBoard_CreateResponse(uint8_t id, uint32_t value, phApp_Data_t *dataout)
{

}

static PhTypes_ErrorCode_t phBoard_CreateNtf(uint8_t group, uint8_t ecu, uint8_t id, uint32_t value, phApp_Data_t *dataout)
{

}

void phBoard_MainFunction()
{
    
}