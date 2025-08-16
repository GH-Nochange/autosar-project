#ifndef PH_CANIF_H
#define PH_CANIF_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phComStack_Types.h"
#include "phTypes.h"

typedef enum
{
    CANIF_EXTENDED_CAN = 0U,        /* CAN frame with extended identifier (29 bits) */
    CANIF_EXTENDED_FD_CAN,          /* CAN FD frame with extended identifier (29 bits) */
    CANIF_STANDARD_CAN,             /* CAN frame with standard identifier (11 bits) */
    CANIF_STANDARD_FD_CAN           /* CAN FD frame with standard identifier (11 bits) */
} CanIf_FrameType;

PhTypes_ErrorCode_t phCanIf_Transmit(const phPduInfoType* PduInfoPtr);
PhTypes_ErrorCode_t phCanIf_ReadRxPduData(phPduInfoType* CanIfRxInfoPtr);

PhTypes_ErrorCode_t phCanIf_TriggerTransmit(phPduInfoType* PduInfoPtr);
void phCanIf_TxConfirmation(void);
void phCanIf_RxIndication(const phPduInfoType * PduInfoPtr);


#ifdef __cplusplus
}
#endif

#endif /* PH_CANIF_H */
