#ifndef PH_PDUR_CANTP_H
#define PH_PDUR_CANTP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phComStack_Types.h"
#include "phPduR.h"
#include "phTypes.h"

phBufReq_ReturnType phPduR_CanTpCopyRxData(const phPduInfoType* info, phPduLengthType* bufferSizePtr);
void phPduR_CanTpRxIndication(PhTypes_ErrorCode_t result);
phBufReq_ReturnType phPduR_CanTpStartOfReception(const phPduInfoType* info, phPduLengthType TpSduLength, phPduLengthType *bufferSizePtr);
phBufReq_ReturnType phPduR_CanTpCopyTxData(const phPduInfoType* info, const phRetryInfoType* retry, phPduLengthType* bufferSizePtr);
void phPduR_CanTpTxConfirmation(PhTypes_ErrorCode_t result);
PhTypes_ErrorCode_t phPduR_CanTpTriggerTransmit(const phPduInfoType *PduInfoPtr);


#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_CANTP_H */
