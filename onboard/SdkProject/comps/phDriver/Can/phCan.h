#ifndef PH_CAN_H
#define PH_CAN_H

#include <stdint.h>
#include <stdbool.h>
#include "phTypes.h" 
#include "flexcan_driver.h"
#include "phCanDrv.h" 

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef CANIF_CAN_INSTANCE
#define CANIF_CAN_INSTANCE (0u) 
#endif

#ifndef CANIF_TX_MB_IDX
#define CANIF_TX_MB_IDX (0u) 
#endif

#ifndef CANIF_RX_MB_IDX
#define CANIF_RX_MB_IDX (1u) 
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
#define CANIF_RX_MASK (0u) 
#endif

#ifndef CANIF_USE_INDIVIDUAL_MASK
#define CANIF_USE_INDIVIDUAL_MASK (true)
#endif

#ifndef CANIF_DEFAULT_DLC
#define CANIF_DEFAULT_DLC (8u)
#endif

    PhTypes_ErrorCode_t phCan0_Init(void);
    PhTypes_ErrorCode_t phCan0_DeInit(void);

    PhTypes_ErrorCode_t phCan0_Transmit(
        const uint8_t *data,
        uint8_t len);

#ifdef __cplusplus
}
#endif
#endif // PH_CAN_H
