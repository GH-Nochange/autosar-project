#include "phBoard.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include "phCom.h"
#include "phLed.h"
#include "phApp_Spi.h"

#include "Mcu.h"
#include "Platform.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Port.h"
#include "phCanTp.h"
#include "CanIf.h"
#include "Spi.h"
#include "phTypes.h"

#include "string.h"
#if (SPI_DMA_USED == STD_ON)
#include "Mcl.h"
#include "CDD_Rm.h"
#endif

PhTypes_ErrorCode_t phBoard_Recv(phApp_Data_t *data)
{

    if (!QueueRX_IsFull())
    {
        return QueueRX_Push(data);
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
        phApp_SpiPrepareData(data);
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

        Mcu_PerformReset(); // McuInit -> send Ntf reason reset trigger Flash.
        break;
    case PH_LED:
        data->header.group = PH_RESPONSE;
        if (data->header.length != 1)
        {
            data->header.length = 1;
            data->payload[0] = PH_ERR_LENGTH;
        }
        else if (data->payload[0] >= 0 && data->payload[0] <= 7)
        {
            phSetLed(data->payload[0]);
            data->payload[0] = PH_ERR_OK;
        }
        else
        {
            data->payload[0] = PH_ERR_INVALID_ARG;
        }

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
    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config);
#endif
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
    Port_Init(NULL_PTR);
#else
    Port_Init(&Port_Config);
#endif

    Queue_Init();
    phApp_SpiInit();

    /* Initialize Can driver */
#if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
    Can_43_FLEXCAN_Init(NULL_PTR);
#else
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config);
#endif

    CanIf_Init(NULL_PTR);
    /* Start Can controller */
    Can_43_FLEXCAN_SetControllerMode(Can_43_FLEXCANConf_CanController_CanController_0, CAN_CS_STARTED);

#if (SPI_DMA_USED == STD_ON)
        /* Initialize Mcl to use Dma and/or FlexIO */
        Mcl_Init(NULL_PTR);
        /* Initialize Rm to use Dma*/
        Rm_Init(NULL_PTR);
#endif

    Spi_Init(NULL_PTR);

    Mcu_ResetType reset_reson = Mcu_GetResetReason();
    uint8_t reset_val = (uint8_t)reset_reson;
    phApp_Data_t data;
    phBoard_CreateFrame(PH_NOTIFY, PH_BOARD1, PH_RESET, 1u, &reset_val, &data);
    phBoard_Send(&data);
}

void phBoard_MainFunction()
{

    PhTypes_ErrorCode_t err = PH_ERR_OK;
    if (!QueueRX_IsEmpty())
    {
        phApp_Data_t data;
        err = QueueRX_Front(&data);
        if (err == PH_ERR_OK)
        {
            err = phBoard_RxProcessing(&data);
        }
        if (err == PH_ERR_OK)
            QueueRX_Pop(&data);
    }
    phCom_MainFunctionTx();
    phApp_SpiMainFunction();
}
