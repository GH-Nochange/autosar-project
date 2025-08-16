#ifndef PH_PDUR_COM_H
#define PH_PDUR_COM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phComStack_Types.h"
#include "phTypes.h"

PhTypes_ErrorCode_t phPduR_ComTransmit(const phPduInfoType *PduInfoPtr);
PhTypes_ErrorCode_t phPduR_CancelTransmit(phPduIdType TxPduId);
PhTypes_ErrorCode_t phPduR_ComCancelReceive(phPduIdType RxPduId);

#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_COM_H */