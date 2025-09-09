#include "phDma.h"

edma_state_t dmaController1_State;

edma_chn_state_t dmaController1Chn0_State;
edma_chn_state_t dmaController1Chn1_State;
edma_chn_state_t dmaController1Chn2_State;
edma_chn_state_t dmaController1Chn3_State;

edma_chn_state_t *const edmaChnStateArray[] = {
    &dmaController1Chn0_State,
    &dmaController1Chn1_State,
    &dmaController1Chn2_State,
    &dmaController1Chn3_State};

edma_channel_config_t dmaController1Chn0_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN0_NUMBER,
    .source = EDMA_REQ_LPSPI0_RX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false};

edma_channel_config_t dmaController1Chn1_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN1_NUMBER,
    .source = EDMA_REQ_LPSPI0_TX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false};

edma_channel_config_t dmaController1Chn2_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN2_NUMBER,
    .source = EDMA_REQ_LPSPI1_RX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false};

edma_channel_config_t dmaController1Chn3_Config = {
    .channelPriority = EDMA_CHN_DEFAULT_PRIORITY,
    .virtChnConfig = EDMA_CHN3_NUMBER,
    .source = EDMA_REQ_LPSPI1_TX,
    .callback = NULL,
    .callbackParam = NULL,
    .enableTrigger = false};

const edma_channel_config_t *const edmaChnConfigArray[] = {
    &dmaController1Chn0_Config,
    &dmaController1Chn1_Config,
    &dmaController1Chn2_Config,
    &dmaController1Chn3_Config};

const edma_user_config_t dmaController1_InitConfig0 = {
    .chnArbitration = EDMA_ARBITRATION_FIXED_PRIORITY,
    .haltOnError = false};

void phDma_Init(void)
{
    EDMA_DRV_Init(&dmaController1_State, &dmaController1_InitConfig0, edmaChnStateArray, edmaChnConfigArray, EDMA_CONFIGURED_CHANNELS_COUNT);
}
