#include "CanDrv.h"
#include "flexcan_driver.h"
#include "clock_manager.h"
#include "interrupt_manager.h"

#define PH_CAN_INSTANCE 0U
#define PH_CAN_TX_MB 0U
#define PH_CAN_RX_MB 1U

#define TIMEOUT_MS 20U

static phDriverCan_Config_t s_canChannels[PH_CAN_CHANNEL_NUM] = {
    [PH_CAN_CHANNEL_MAIN] = {
        .instance = PH_CAN_INSTANCE,
        .txMbIdx = PH_CAN_TX_MB,
        .rxMbIdx = PH_CAN_RX_MB,
        .callback = NULL,
        .userData = NULL}};

static flexcan_state_t s_CanState[PH_CAN_CHANNEL_NUM];

static void CAN_RxISR_Callback(uint8_t instance,
                               flexcan_event_type_t eventType,
                               uint32_t buffIdx,
                               flexcan_state_t *state)
{
    if (eventType != FLEXCAN_EVENT_RX_COMPLETE)
        return; // Bỏ qua các loại ngắt không phải nhận frame
    for (phDriverCan_Channel_t ch = 0; ch < PH_CAN_CHANNEL_NUM; ch++)
    {
        if (s_canChannels[ch].instance == instance &&
            s_canChannels[ch].rxMbIdx == buffIdx &&
            s_canChannels[ch].callback != NULL &&
            s_canChannels[ch].rxFrameBuf != NULL)
        {
            // Gọi callback người dùng đã đăng ký
            s_canChannels[ch].callback(
                ch,
                s_canChannels[ch].rxFrameBuf->msgId,
                s_canChannels[ch].rxFrameBuf->data,
                s_canChannels[ch].rxFrameBuf->dataLen,
                s_canChannels[ch].userData);

            // Bắt đầu nhận tiếp
            FLEXCAN_DRV_Receive(instance,
                                buffIdx,
                                s_canChannels[ch].rxFrameBuf);
        }
    }
}

PhTypes_ErrorCode_t phDriverCan_Init(void)
{
    for (int i = 0; i < PH_CAN_CHANNEL_NUM; i++)
    {
        flexcan_user_config_t cfg = {
            .max_num_mb = 2U,
            .num_id_filters = FLEXCAN_RX_FIFO_ID_FILTERS_8,
            .is_rx_fifo_needed = false,
            .flexcanMode = FLEXCAN_NORMAL_MODE,
            .bitrate = {
                .propSeg = 6U,
                .phaseSeg1 = 8U,
                .phaseSeg2 = 5U,
                .preDivider = 4U,
                .rJumpwidth = 2U},
            .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS};

        status_t stat = FLEXCAN_DRV_Init(s_canChannels[i].instance, &s_CanState[i], &cfg);

        if (stat != STATUS_SUCCESS)
            return EER_Unknown;

        s_canChannels[i].initialized = true;
    }

    return EER_OK;
}

PhTypes_ErrorCode_t phDriverCan_DeInitChannel(phDriverCan_Channel_t channel)
{
    if (channel >= PH_CAN_CHANNEL_NUM)
        return EER_InvalidArg;
    FLEXCAN_DRV_Deinit(s_canChannels[channel].instance);
    return EER_OK;
}

PhTypes_ErrorCode_t phDriverCan_DeInit(void)
{
    for (phDriverCan_Channel_t ch = 0; ch < PH_CAN_CHANNEL_NUM; ch++)
    {
        FLEXCAN_DRV_Deinit(s_canChannels[ch].instance);
    }
    return EER_OK;
}

PhTypes_ErrorCode_t phDriverCan_Send(phDriverCan_Channel_t channel,
                                     uint32_t id,
                                     const uint8_t *data,
                                     uint8_t len)
{
    if (!s_canChannels[channel].initialized)
        return EER_NOTINIT;

    if (channel >= PH_CAN_CHANNEL_NUM || data == NULL || len > PH_CAN_MAX_DLEN)
        return EER_InvalidArg;

    flexcan_data_info_t txInfo = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = len,
        .is_remote = false};

    status_t status = FLEXCAN_DRV_SendBlocking(s_canChannels[channel].instance,
                                               s_canChannels[channel].txMbIdx,
                                               &txInfo,
                                               id,
                                               data,
                                               TIMEOUT_MS);
    return (status == STATUS_SUCCESS) ? EER_OK : EER_BUSY;
}

PhTypes_ErrorCode_t phDriverCan_Recv(phDriverCan_Channel_t channel,
                                     phDriverCan_RxCallback_t callback,
                                     flexcan_msgbuff_t *rxFrameBuffer,
                                     void *userData)
{
    if (!s_canChannels[channel].initialized)
        return EER_NOTINIT;

    if (channel >= PH_CAN_CHANNEL_NUM || callback == NULL || rxFrameBuffer == NULL)
        return EER_InvalidArg;

    s_canChannels[channel].callback = callback;
    s_canChannels[channel].userData = userData;
    s_canChannels[channel].rxFrameBuf = rxFrameBuffer;

    // Đăng ký hàm callback ISR nội bộ của FlexCAN driver
    FLEXCAN_DRV_InstallEventCallback(
        s_canChannels[channel].instance,
        CAN_RxISR_Callback, // Hàm ISR nội bộ đúng định dạng
        NULL);

    FLEXCAN_DRV_SetRxMaskType(s_canChannels[channel].instance, FLEXCAN_RX_MASK_GLOBAL);
    FLEXCAN_DRV_SetRxMbGlobalMask(
        s_canChannels[channel].instance,
        s_canChannels[channel].rxMbIdx,
        FLEXCAN_MSG_ID_STD);

    FLEXCAN_DRV_Receive(s_canChannels[channel].instance,
                        s_canChannels[channel].rxMbIdx,
                        s_canChannels[channel].rxFrameBuf);

    return EER_OK;
}