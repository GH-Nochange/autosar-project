#ifndef CANIF_H
#define CANIF_H

#include <stdint.h>
#include <stdbool.h>
#include "phTypes.h" // PH_ERR_SUCCESS/FAILED...
#include "flexcan_driver.h"
#include "phDriverCan.h" // driver bạn vừa viết

#ifdef __cplusplus
extern "C"
{
#endif

// ==== Tham số cấu hình mặc định cho CAN0 (có thể đổi ở build-time) ====
#ifndef CANIF_CAN_INSTANCE
#define CANIF_CAN_INSTANCE (0u) // CAN0
#endif

#ifndef CANIF_TX_MB_IDX
#define CANIF_TX_MB_IDX (0u) // MB0 làm TX
#endif

#ifndef CANIF_RX_MB_IDX
#define CANIF_RX_MB_IDX (1u) // MB1 làm RX
#endif

#ifndef CANIF_ID_TYPE
#define CANIF_ID_TYPE (FLEXCAN_MSG_ID_STD) 
#endif

#ifndef CANIF_TX_ID
#define CANIF_TX_ID (888u)
#endif

#ifndef CANIF_RX_ID
#define CANIF_RX_ID (0x321u)
#endif

#ifndef CANIF_RX_MASK
#define CANIF_RX_MASK (0u) // mask full bits cho STD ID
#endif

#ifndef CANIF_USE_INDIVIDUAL_MASK
#define CANIF_USE_INDIVIDUAL_MASK (true)
#endif

#ifndef CANIF_DEFAULT_DLC
#define CANIF_DEFAULT_DLC (8u)
#endif

    phTypes_ErrorCode_t CanIf_Init(void);
    phTypes_ErrorCode_t CanIf_DeInit(void);

    phTypes_ErrorCode_t CanIf_Transmit(
        const uint8_t *data,
        uint8_t len);

    void CanIf_TxConfirmation(void);
    void CanIf_RxIndication(const flexcan_msgbuff_t *frame);

#ifdef __cplusplus
}
#endif
#endif // CANIF_H
