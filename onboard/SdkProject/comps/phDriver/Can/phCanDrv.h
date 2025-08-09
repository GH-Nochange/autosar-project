#ifndef PH_CAN_DRV_H
#define PH_CAN_DRV_H

#include <stdint.h>
#include <stdbool.h>
#include "status.h"
#include "flexcan_driver.h"
#include "device_registers.h"
#include "ph_Types.h"

typedef struct
{
    uint8_t tx_mb_idx;
    uint8_t rx_mb_idx;
    flexcan_msgbuff_id_type_t msg_id_type;
    uint32_t tx_id;
    uint32_t rx_id;
    uint32_t rx_mask;
    bool use_rx_individual_mask;
    uint8_t default_data_length;
    flexcan_callback_t event_callback;
    void *event_callback_param;
} phDriverCan_Config_t;

typedef void (*phDriverCan_RxCb_t)(uint8_t instance,
                                   const flexcan_msgbuff_t *frame,
                                   void *user_param);

typedef void (*phDriverCan_TxCb_t)(uint8_t instance,
                                   void *user_param);

phTypes_ErrorCode_t phDriverCan_Init(const uint8_t instance, const phDriverCan_Config_t *canConfig);
phTypes_ErrorCode_t phDriverCan_DeInit(const uint8_t instance);
phTypes_ErrorCode_t phDriverCan_Send(const uint8_t instance, const uint32_t msgId,
                                     const uint8_t *const sendData, const uint8_t length);

void phDriverCan_RegisterRxCallback(uint8_t instance,
                                    phDriverCan_RxCb_t cb,
                                    void *user_param);

void phDriverCan_RegisterTxCallback(uint8_t instance,
                                    phDriverCan_TxCb_t cb,
                                    void *user_param);

#endif /* PH_CAN_DRV_H */
