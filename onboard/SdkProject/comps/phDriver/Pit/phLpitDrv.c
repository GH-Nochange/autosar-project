#include "phLpitDrv.h"

static inline PhTypes_ErrorCode_t map_status(status_t st)
{
    switch (st)
    {
        case STATUS_SUCCESS:     return PH_ERR_OK;
        case STATUS_TIMEOUT:     return PH_ERR_TIMEOUT;
        case STATUS_BUSY:        return PH_ERR_BUSY;
        case STATUS_UNSUPPORTED: return PH_ERR_UNKNOWN;
        default:                 return PH_ERR_FAILED;
    }
}

PhTypes_ErrorCode_t phLpitDrv_Init(uint32_t instance, const lpit_user_config_t *userConfig)
{
    if (userConfig == NULL) return PH_ERR_INVALID_ARG;
    LPIT_DRV_Init(instance, userConfig);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_Deinit(uint32_t instance)
{
    LPIT_DRV_Deinit(instance);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_InitChannel(uint32_t instance, uint32_t channel, const lpit_user_channel_config_t *chanConfig)
{
    if (chanConfig == NULL) return PH_ERR_INVALID_ARG;
    status_t st = LPIT_DRV_InitChannel(instance, channel, chanConfig);
    return map_status(st);
}

PhTypes_ErrorCode_t phLpitDrv_Start(uint32_t instance, uint32_t mask)
{
    LPIT_DRV_StartTimerChannels(instance, mask);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_Stop(uint32_t instance, uint32_t mask)
{
    LPIT_DRV_StopTimerChannels(instance, mask);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_SetPeriodUs(uint32_t instance, uint32_t channel, uint32_t periodUs)
{
    status_t st = LPIT_DRV_SetTimerPeriodByUs(instance, channel, periodUs);
    return map_status(st);
}

PhTypes_ErrorCode_t phLpitDrv_SetPeriodDual16Us(uint32_t instance, uint32_t channel, uint16_t periodHighUs, uint16_t periodLowUs)
{
    status_t st = LPIT_DRV_SetTimerPeriodInDual16ModeByUs(instance, channel, periodHighUs, periodLowUs);
    return map_status(st);
}

PhTypes_ErrorCode_t phLpitDrv_GetPeriodUs(uint32_t instance, uint32_t channel, uint64_t *outPeriodUs)
{
    if (outPeriodUs == NULL) return PH_ERR_INVALID_ARG;
    *outPeriodUs = LPIT_DRV_GetTimerPeriodByUs(instance, channel);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_GetCurrentUs(uint32_t instance, uint32_t channel, uint64_t *outCurrentUs)
{
    if (outCurrentUs == NULL) return PH_ERR_INVALID_ARG;
    *outCurrentUs = LPIT_DRV_GetCurrentTimerUs(instance, channel);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_SetPeriodCount(uint32_t instance, uint32_t channel, uint32_t count)
{
    LPIT_DRV_SetTimerPeriodByCount(instance, channel, count);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_SetPeriodDual16Count(uint32_t instance, uint32_t channel, uint16_t periodHighCount, uint16_t periodLowCount)
{
    LPIT_DRV_SetTimerPeriodInDual16ModeByCount(instance, channel, periodHighCount, periodLowCount);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_GetPeriodCount(uint32_t instance, uint32_t channel, uint32_t *outCount)
{
    if (outCount == NULL) return PH_ERR_INVALID_ARG;
    *outCount = LPIT_DRV_GetTimerPeriodByCount(instance, channel);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_GetCurrentCount(uint32_t instance, uint32_t channel, uint32_t *outCount)
{
    if (outCount == NULL) return PH_ERR_INVALID_ARG;
    *outCount = LPIT_DRV_GetCurrentTimerCount(instance, channel);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_EnableInterrupt(uint32_t instance, uint32_t mask)
{
    LPIT_DRV_EnableTimerChannelInterrupt(instance, mask);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_DisableInterrupt(uint32_t instance, uint32_t mask)
{
    LPIT_DRV_DisableTimerChannelInterrupt(instance, mask);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_GetInterruptFlags(uint32_t instance, uint32_t mask, uint32_t *outFlags)
{
    if (outFlags == NULL) return PH_ERR_INVALID_ARG;
    *outFlags = LPIT_DRV_GetInterruptFlagTimerChannels(instance, mask);
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phLpitDrv_ClearInterruptFlags(uint32_t instance, uint32_t mask)
{
    LPIT_DRV_ClearInterruptFlagTimerChannels(instance, mask);
    return PH_ERR_OK;
}
