#ifndef PH_CAN_DRV_H
#define PH_CAN_DRV_H

#include <stdint.h>
#include <stdbool.h>
#include "status.h"
#include "flexcan_driver.h"
#include "device_registers.h"
#include "phTypes.h"

/**
 * @brief CAN driver configuration structure.
 */
typedef struct
{
    uint8_t tx_mb_idx;                  /**< TX message buffer index */
    uint8_t rx_mb_idx;                  /**< RX message buffer index */
    flexcan_msgbuff_id_type_t msg_id_type; /**< Standard or extended ID */
    uint32_t tx_id;                      /**< Default TX message ID */
    uint32_t rx_id;                      /**< Expected RX message ID */
    uint32_t rx_mask;                    /**< RX mask value */
    bool use_rx_individual_mask;         /**< Enable individual RX mask */
    uint8_t default_data_length;         /**< Default CAN payload length */
    flexcan_callback_t event_callback;   /**< Event callback (FlexCAN) */
    void *event_callback_param;          /**< Parameter for event callback */
} phDriverCan_Config_t;

/**
 * @brief RX callback function prototype.
 */
typedef void (*phDriverCan_RxCb_t)(uint8_t instance,
                                   const flexcan_msgbuff_t *frame,
                                   void *user_param);

/**
 * @brief TX callback function prototype.
 */
typedef void (*phDriverCan_TxCb_t)(uint8_t instance,
                                   void *user_param);

/**
 * @brief Initialize CAN driver.
 */
PhTypes_ErrorCode_t phDriverCan_Init(const uint8_t instance, const phDriverCan_Config_t *canConfig);

/**
 * @brief Deinitialize CAN driver.
 */
PhTypes_ErrorCode_t phDriverCan_DeInit(const uint8_t instance);

/**
 * @brief Send a CAN frame.
 */
PhTypes_ErrorCode_t phDriverCan_Send(const uint8_t instance, const uint32_t msgId,
                                     const uint8_t *const sendData, const uint8_t length);

/**
 * @brief Register RX callback.
 */
void phDriverCan_RegisterRxCallback(uint8_t instance,
                                    phDriverCan_RxCb_t cb,
                                    void *user_param);

/**
 * @brief Register TX callback.
 */
void phDriverCan_RegisterTxCallback(uint8_t instance,
                                    phDriverCan_TxCb_t cb,
                                    void *user_param);

#endif /* PH_CAN_DRV_H */
