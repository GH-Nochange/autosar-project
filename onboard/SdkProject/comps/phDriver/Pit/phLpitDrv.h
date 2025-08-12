#ifndef PH_LPITDRV_H
#define PH_LPITDRV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "phTypes.h"
#include "lpit_driver.h"

/* =========================================================================
 *  INITIALIZATION / DEINITIALIZATION API
 * ========================================================================= */

/**
 * @brief Initialize the LPIT module for a given instance.
 *
 * @param instance      LPIT instance number.
 * @param userConfig    Pointer to LPIT user configuration (debug/doze mode settings).
 * @return PH_ERR_OK if successful, or an error code otherwise.
 *
 * @note This is equivalent to NXP's LPIT_DRV_Init() but returns PhTypes_ErrorCode_t.
 *       Should be called before configuring any channels.
 */
PhTypes_ErrorCode_t phLpitDrv_Init(uint32_t instance,
                                   const lpit_user_config_t *userConfig);

/**
 * @brief Deinitialize the LPIT module for a given instance.
 *
 * @param instance      LPIT instance number.
 * @return PH_ERR_OK if successful.
 */
PhTypes_ErrorCode_t phLpitDrv_Deinit(uint32_t instance);

/**
 * @brief Initialize an LPIT channel.
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index (0..).
 * @param chanConfig    Pointer to the channel configuration (mode, period, trigger, interrupt...).
 * @return PH_ERR_OK if successful; PH_ERR_INVALID_ARG if parameters are invalid;
 *         PH_ERR_FAILED if the operation failed.
 *
 * @note This is equivalent to LPIT_DRV_InitChannel().
 *       After initialization, the channel is not running yet; call Start to begin counting.
 */
PhTypes_ErrorCode_t phLpitDrv_InitChannel(uint32_t instance,
                                          uint32_t channel,
                                          const lpit_user_channel_config_t *chanConfig);

/* =========================================================================
 *  START / STOP API
 * ========================================================================= */

/**
 * @brief Start (begin counting) channels according to a mask.
 *
 * @param instance      LPIT instance number.
 * @param mask          Bitmask selecting channels to start (bit0 → ch0, bit1 → ch1, etc.).
 * @return PH_ERR_OK.
 */
PhTypes_ErrorCode_t phLpitDrv_Start(uint32_t instance, uint32_t mask);

/**
 * @brief Stop (halt counting) channels according to a mask.
 *
 * @param instance      LPIT instance number.
 * @param mask          Bitmask selecting channels to stop.
 * @return PH_ERR_OK.
 */
PhTypes_ErrorCode_t phLpitDrv_Stop(uint32_t instance, uint32_t mask);

/* =========================================================================
 *  PERIOD CONFIGURATION & TIME READBACK API
 * ========================================================================= */

/**
 * @brief Set the channel period in microseconds (us) for 32-bit periodic or dual-16 periodic modes.
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index.
 * @param periodUs      Desired period in microseconds.
 * @return PH_ERR_OK if successful, PH_ERR_FAILED if out of range.
 */
PhTypes_ErrorCode_t phLpitDrv_SetPeriodUs(uint32_t instance,
                                          uint32_t channel,
                                          uint32_t periodUs);

/**
 * @brief Set the period for dual 16-bit periodic mode (high/low) in microseconds.
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index.
 * @param periodHighUs  High 16-bit portion in microseconds.
 * @param periodLowUs   Low 16-bit portion in microseconds.
 * @return PH_ERR_OK if successful, PH_ERR_FAILED if out of range.
 */
PhTypes_ErrorCode_t phLpitDrv_SetPeriodDual16Us(uint32_t instance,
                                                uint32_t channel,
                                                uint16_t periodHighUs,
                                                uint16_t periodLowUs);

/**
 * @brief Get the current period (us) of a channel
 *        (only valid in 32-bit periodic / dual-16 periodic modes).
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index.
 * @param outPeriodUs   Pointer to store the period in microseconds.
 * @return PH_ERR_OK if successful; PH_ERR_INVALID_ARG if pointer is NULL.
 */
PhTypes_ErrorCode_t phLpitDrv_GetPeriodUs(uint32_t instance,
                                          uint32_t channel,
                                          uint64_t *outPeriodUs);

/**
 * @brief Get the current counter value in microseconds (timestamp).
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index.
 * @param outCurrentUs  Pointer to store the current time in microseconds.
 * @return PH_ERR_OK if successful; PH_ERR_INVALID_ARG if pointer is NULL.
 *
 * @note Can be used for time measurement: read at start and end, then compute the difference.
 */
PhTypes_ErrorCode_t phLpitDrv_GetCurrentUs(uint32_t instance,
                                           uint32_t channel,
                                           uint64_t *outCurrentUs);

/**
 * @brief Set the channel period in raw counter ticks (count).
 *
 * @param instance      LPIT instance number.
 * @param channel       Channel index.
 * @param count         Load value (counter ticks).
 * @return PH_ERR_OK.
 */
PhTypes_ErrorCode_t phLpitDrv_SetPeriodCount(uint32_t instance,
                                             uint32_t channel,
                                             uint32_t count);

/**
 * @brief Set the dual 16-bit periodic mode period in raw counter ticks.
 */
PhTypes_ErrorCode_t phLpitDrv_SetPeriodDual16Count(uint32_t instance,
                                                   uint32_t channel,
                                                   uint16_t periodHighCount,
                                                   uint16_t periodLowCount);

/**
 * @brief Get the current period in raw counter ticks.
 *
 * @param outCount      Pointer to store the period (ticks).
 */
PhTypes_ErrorCode_t phLpitDrv_GetPeriodCount(uint32_t instance,
                                             uint32_t channel,
                                             uint32_t *outCount);

/**
 * @brief Get the current counter value (ticks).
 *
 * @param outCount      Pointer to store the current counter value.
 */
PhTypes_ErrorCode_t phLpitDrv_GetCurrentCount(uint32_t instance,
                                              uint32_t channel,
                                              uint32_t *outCount);

/* =========================================================================
 *  INTERRUPT API
 * ========================================================================= */

/**
 * @brief Enable interrupts for channels according to a mask.
 */
PhTypes_ErrorCode_t phLpitDrv_EnableInterrupt(uint32_t instance, uint32_t mask);

/**
 * @brief Disable interrupts for channels according to a mask.
 */
PhTypes_ErrorCode_t phLpitDrv_DisableInterrupt(uint32_t instance, uint32_t mask);

/**
 * @brief Read interrupt flags for channels according to a mask.
 *
 * @param outFlags      Pointer to store the bitflags read (masked).
 */
PhTypes_ErrorCode_t phLpitDrv_GetInterruptFlags(uint32_t instance,
                                                uint32_t mask,
                                                uint32_t *outFlags);

/**
 * @brief Clear interrupt flags for channels according to a mask.
 */
PhTypes_ErrorCode_t phLpitDrv_ClearInterruptFlags(uint32_t instance, uint32_t mask);

#ifdef __cplusplus
}
#endif

#endif /* PH_LPITDRV_H */
