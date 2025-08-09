#include "canIf.h"

// ================== State nội bộ ==================
static bool s_canIfInited = false;

// ================== Driver callbacks ==================
static void CanIf_RxCb(uint8_t instance,
                       const flexcan_msgbuff_t *frame,
                       void *user_param)
{
    (void)instance;
    (void)user_param;
    // Đẩy lên tầng trên
    CanIf_RxIndication(frame);
}

static void CanIf_TxCb(uint8_t instance, void *user_param)
{
    (void)instance;
    (void)user_param;
    // Báo gửi xong lên tầng trên
    CanIf_TxConfirmation();
}

// ================== Public API ==================
phTypes_ErrorCode_t CanIf_Init(void)
{
    if (s_canIfInited) return PH_ERR_SUCCESS;

    phDriverCan_Config_t cfg;
    cfg.tx_mb_idx               = CANIF_TX_MB_IDX;
    cfg.rx_mb_idx               = CANIF_RX_MB_IDX;
    cfg.msg_id_type             = CANIF_ID_TYPE;          // FLEXCAN_MSG_ID_STD/EXT
    cfg.tx_id                   = CANIF_TX_ID;            // ID cố định khi config TX MB
    cfg.rx_id                   = 0u;                     // không quan trọng khi mask = 0
    cfg.rx_mask                 = CANIF_RX_MASK;          // 0 -> nhận tất
    cfg.use_rx_individual_mask  = CANIF_USE_INDIVIDUAL_MASK;
    cfg.default_data_length     = CANIF_DEFAULT_DLC;
    cfg.event_callback          = NULL;                   // dùng callback tách riêng
    cfg.event_callback_param    = NULL;

    phTypes_ErrorCode_t ec = phDriverCan_Init(CANIF_CAN_INSTANCE, &cfg);
    if (ec != PH_ERR_SUCCESS) return ec;

    // Cài callback RX/TX lên driver
    phDriverCan_RegisterRxCallback(CANIF_CAN_INSTANCE, CanIf_RxCb, NULL);
    phDriverCan_RegisterTxCallback(CANIF_CAN_INSTANCE, CanIf_TxCb, NULL);

    s_canIfInited = true;
    return PH_ERR_SUCCESS;
}

phTypes_ErrorCode_t CanIf_DeInit(void)
{
    if (!s_canIfInited) return PH_ERR_SUCCESS;

    phTypes_ErrorCode_t ec = phDriverCan_DeInit(CANIF_CAN_INSTANCE);
    if (ec == PH_ERR_SUCCESS) {
        s_canIfInited = false;
    }
    return ec;
}

phTypes_ErrorCode_t CanIf_Transmit(const uint8_t *data, uint8_t len)
{
    if (!s_canIfInited)         return PH_ERR_FAILED;
    if (data == NULL)           return PH_ERR_INVALID_ARG;
    if (len == 0u || len > 8u)  return PH_ERR_INVALID_ARG;

    return phDriverCan_Send(CANIF_CAN_INSTANCE, CANIF_TX_ID, data, len);
}

__attribute__((weak)) void CanIf_TxConfirmation(void)
{
}

__attribute__((weak)) void CanIf_RxIndication(const flexcan_msgbuff_t *frame)
{
    (void)frame;
}
