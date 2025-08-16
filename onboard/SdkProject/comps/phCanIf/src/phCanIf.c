#include "phCanIf.h"
#include "phCanTp.h"
#include "phCan.h"
#include "test.h"

PhTypes_ErrorCode_t phCanIf_Transmit(const phPduInfoType* PduInfoPtr)
{
    return phCan0_Transmit(PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
}

PhTypes_ErrorCode_t phCanIf_ReadRxPduData(phPduInfoType* CanIfRxInfoPtr)
{
    (void)CanIfRxInfoPtr;
     return PH_ERR_OK;
}

PhTypes_ErrorCode_t phCanIf_TriggerTransmit(phPduInfoType* PduInfoPtr)
{
    (void)PduInfoPtr;
     return 0;
}

void phCanIf_TxConfirmation()
{
   phCanTp_TxConfirmation(PH_ERR_OK);
}

void phCanIf_RxIndication(const phPduInfoType * PduInfoPtr)
{
    if(PduInfoPtr == NULL) return;
    phCanTp_RxIndication(PduInfoPtr);
}
