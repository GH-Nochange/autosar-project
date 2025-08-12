#include "phCan.h"
#include "phCanDrv.h"
#include "device_registers.h"

static bool s_canIfInited = false;

static void Can_RxCb(uint8_t instance,
                     const flexcan_msgbuff_t *frame,
                     void *user_param)
{
    (void)instance;
    (void)user_param;
    Can_RxIndication(frame);
}

static void Can_TxCb(uint8_t instance, void *user_param)
{
    (void)instance;
    (void)user_param;
    Can_TxConfirmation();
}
 
PhTypes_ErrorCode_t Can_Init(void)
{
    if (s_canIfInited)
        return PH_ERR_OK;
    

    phDriverCan_Config_t cfg = {0};
    cfg.tx_mb_idx = CANIF_TX_MB_IDX;
    cfg.rx_mb_idx = CANIF_RX_MB_IDX;
    cfg.msg_id_type = CANIF_ID_TYPE;
    cfg.tx_id = CANIF_TX_ID;
    cfg.rx_id = CANIF_RX_ID;
    cfg.rx_mask = CANIF_RX_MASK;
    cfg.use_rx_individual_mask = CANIF_USE_INDIVIDUAL_MASK;
    cfg.default_data_length = CANIF_DEFAULT_DLC;
    cfg.event_callback = NULL;
    cfg.event_callback_param = NULL;

    PhTypes_ErrorCode_t ec = phDriverCan_Init(CANIF_CAN_INSTANCE, &cfg);
    if (ec != PH_ERR_OK)
        return ec;

    phDriverCan_RegisterRxCallback(CANIF_CAN_INSTANCE, Can_RxCb, NULL);
    phDriverCan_RegisterTxCallback(CANIF_CAN_INSTANCE, Can_TxCb, NULL);

    s_canIfInited = true;
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t Can_DeInit(void)
{
    if (!s_canIfInited)
        return PH_ERR_OK;

    PhTypes_ErrorCode_t ec = phDriverCan_DeInit(CANIF_CAN_INSTANCE);
    if (ec == PH_ERR_OK)
    {
        s_canIfInited = false;
    }
    return ec;
}

PhTypes_ErrorCode_t Can_Transmit(const uint8_t *data, uint8_t len)
{
    if (!s_canIfInited)
        return PH_ERR_FAILED;
    if (data == NULL)
        return PH_ERR_INVALID_ARG;
    if (len == 0u || len > 8u)
        return PH_ERR_INVALID_ARG;

    return phDriverCan_Send(CANIF_CAN_INSTANCE, CANIF_TX_ID, data, len);
}

__attribute__((weak)) void Can_TxConfirmation(void)
{
}

__attribute__((weak)) void Can_RxIndication(const flexcan_msgbuff_t *frame)
{
    (void)frame;
}
