#include "flexcan_driver.h"
#include "phCanDrv.h"
#include "device_registers.h"
#include "phTypes.h"

#define CAN_MSG_BUFF_MAX 32u

static flexcan_state_t s_canState[CAN_INSTANCE_COUNT];
static flexcan_msgbuff_t s_rxBuf[CAN_INSTANCE_COUNT];

static uint8_t s_txMbIdx[CAN_INSTANCE_COUNT] = {0};
static uint8_t s_rxMbIdx[CAN_INSTANCE_COUNT] = {0};

static phDriverCan_RxCb_t s_rxCb[CAN_INSTANCE_COUNT] = {0};
static void *s_rxCbParam[CAN_INSTANCE_COUNT] = {0};
static phDriverCan_TxCb_t s_txCb[CAN_INSTANCE_COUNT] = {0};
static void *s_txCbParam[CAN_INSTANCE_COUNT] = {0};

static void phDriverCan_OnEvent(uint8_t instance,
                                flexcan_event_type_t eventType,
                                uint32_t buffIdx,
                                flexcan_state_t *flexcanState)
{
    (void)flexcanState;

    switch (eventType)
    {
        case FLEXCAN_EVENT_RX_COMPLETE:
            if (buffIdx == s_rxMbIdx[instance] && s_rxCb[instance]) {
                s_rxCb[instance](instance, &s_rxBuf[instance], s_rxCbParam[instance]);

                /* Re-arm để tiếp tục nhận */
                (void)FLEXCAN_DRV_Receive(instance,
                                          s_rxMbIdx[instance],
                                          &s_rxBuf[instance]);
            }
            break;

        case FLEXCAN_EVENT_TX_COMPLETE:
            if (buffIdx == s_txMbIdx[instance] && s_txCb[instance]) {
                s_txCb[instance](instance, s_txCbParam[instance]);
            }
            break;

        default:
            break;
    }
}


static void phDriverCan_BindTxMb(uint8_t instance, uint8_t tx_mb_idx)
{
    if (instance < CAN_INSTANCE_COUNT)
    {
        s_txMbIdx[instance] = tx_mb_idx;
    }
}

static void phDriverCan_BindRxMb(uint8_t instance, uint8_t rx_mb_idx)
{
    if (instance < CAN_INSTANCE_COUNT)
    {
        s_rxMbIdx[instance] = rx_mb_idx;
    }
}

PhTypes_ErrorCode_t phDriverCan_Init(const uint8_t instance,
                                     const phDriverCan_Config_t *canConfig)
{
    if (instance >= CAN_INSTANCE_COUNT)
        return PH_ERR_FAILED;

    flexcan_user_config_t cfg;
    FLEXCAN_DRV_GetDefaultConfig(&cfg);

    status_t st = FLEXCAN_DRV_Init(instance, &s_canState[instance], &cfg);
    if (st != STATUS_SUCCESS)
        return PH_ERR_FAILED;

    if (canConfig == NULL)
        return PH_ERR_OK;

    if (canConfig->tx_mb_idx >= cfg.max_num_mb ||
        canConfig->rx_mb_idx >= cfg.max_num_mb)
    {
        return PH_ERR_FAILED;
    }
    if (canConfig->msg_id_type == FLEXCAN_MSG_ID_STD)
    {
        if (canConfig->tx_id > 0x7FFu || canConfig->rx_id > 0x7FFu)
            return PH_ERR_FAILED;
    }
    else
    { /* EXT */
        if (canConfig->tx_id > 0x1FFFFFFFu || canConfig->rx_id > 0x1FFFFFFFu)
            return PH_ERR_FAILED;
    }
    uint8_t dlc = (canConfig->default_data_length == 0u) ? 8u : canConfig->default_data_length;
    if (dlc > 8u)
        dlc = 8u;

    FLEXCAN_DRV_SetRxMaskType(instance,
                                   canConfig->use_rx_individual_mask ? FLEXCAN_RX_MASK_INDIVIDUAL
                                                                     : FLEXCAN_RX_MASK_GLOBAL);

    if (canConfig->use_rx_individual_mask)
    {
        FLEXCAN_DRV_SetRxIndividualMask(instance,
                                             canConfig->msg_id_type,
                                             canConfig->rx_mb_idx,
                                             canConfig->rx_mask);
    
    }
    else
    {
        FLEXCAN_DRV_SetRxMbGlobalMask(instance,
                                       canConfig->msg_id_type,
                                       canConfig->rx_mask);
    }

    flexcan_data_info_t info;
    info.msg_id_type = canConfig->msg_id_type;
    info.data_length = dlc;
    info.is_remote = false;

    st = FLEXCAN_DRV_ConfigRxMb(instance,
                                canConfig->rx_mb_idx,
                                &info,
                                canConfig->rx_id);
    if (st != STATUS_SUCCESS)
        return PH_ERR_FAILED;

    phDriverCan_BindRxMb(instance, canConfig->rx_mb_idx);

    st = FLEXCAN_DRV_ConfigTxMb(instance,
                                canConfig->tx_mb_idx,
                                &info,
                                canConfig->tx_id);
    if (st != STATUS_SUCCESS)
        return PH_ERR_FAILED;

    phDriverCan_BindTxMb(instance, canConfig->tx_mb_idx);

    FLEXCAN_DRV_InstallEventCallback(instance,
                                     phDriverCan_OnEvent,
                                     NULL);

    st = FLEXCAN_DRV_Receive(instance,
                             canConfig->rx_mb_idx,
                             &s_rxBuf[instance]);
    if (st != STATUS_SUCCESS)
        return PH_ERR_FAILED;

    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phDriverCan_DeInit(const uint8_t instance)
{
    if (instance >= CAN_INSTANCE_COUNT)
    {
        return PH_ERR_FAILED;
    }

    FLEXCAN_DRV_InstallEventCallback(instance, NULL, NULL);

    status_t st = FLEXCAN_DRV_Deinit(instance);
    if (st != STATUS_SUCCESS)
    {
        return PH_ERR_FAILED;
    }

    s_rxCb[instance] = NULL;
    s_rxCbParam[instance] = NULL;
    s_txCb[instance] = NULL;
    s_txCbParam[instance] = NULL;
    s_rxMbIdx[instance] = 0;
    s_txMbIdx[instance] = 0;

    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phDriverCan_Send(const uint8_t instance,
                                     const uint32_t msgId,
                                     const uint8_t *const sendData,
                                     const uint8_t length)
{
    if (instance >= CAN_INSTANCE_COUNT)
        return PH_ERR_FAILED;
    if (sendData == NULL)
        return PH_ERR_INVALID_ARG;
    if (length == 0u || length > 8u)
        return PH_ERR_INVALID_ARG;
    if (s_txMbIdx[instance] >= CAN_MSG_BUFF_MAX)
        return PH_ERR_FAILED; // tùy macro SDK của bạn

    flexcan_msgbuff_id_type_t idType = (msgId <= 0x7FFu) ? FLEXCAN_MSG_ID_STD
                                                         : FLEXCAN_MSG_ID_EXT;

    flexcan_data_info_t info;
    info.msg_id_type = idType;
    info.is_remote = false;

    uint8_t dlc = (length == 0u) ? 8u : length;
    if (dlc > 8u)
        dlc = 8u;
    info.data_length = dlc;

    status_t st = FLEXCAN_DRV_Send(instance,
                                   s_txMbIdx[instance],
                                   &info,
                                   msgId,
                                   sendData);
    if (st == STATUS_SUCCESS)
        return PH_ERR_OK;
    if (st == STATUS_BUSY)
        return PH_ERR_BUSY;
    return PH_ERR_FAILED;
}

void phDriverCan_RegisterRxCallback(uint8_t instance,
                                    phDriverCan_RxCb_t cb,
                                    void *user_param)
{
    if (instance < CAN_INSTANCE_COUNT)
    {
        s_rxCb[instance] = cb;
        s_rxCbParam[instance] = user_param;
    }
}

void phDriverCan_RegisterTxCallback(uint8_t instance,
                                    phDriverCan_TxCb_t cb,
                                    void *user_param)
{
    if (instance < CAN_INSTANCE_COUNT)
    {
        s_txCb[instance] = cb;
        s_txCbParam[instance] = user_param;
    }
}
