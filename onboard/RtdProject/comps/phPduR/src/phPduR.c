#include "phPduR.h"
#include "phPduR_Com.h"
#include "phPduR_CanTp.h"
#include "phCom.h"
#include "phCanTp.h"
#include "phTypes.h"

static PH_PDUR_t g_pdur = PH_CAN;

PhTypes_ErrorCode_t phPduR_ComTransmit(const phPduInfoType *PduInfoPtr)
{
    switch (g_pdur)
    {
    case PH_CAN:
        return  phCanTp_Transmit(PduInfoPtr);
        break;
    
    default:
        break;
    }
}

phBufReq_ReturnType phPduR_CanTpCopyRxData(const phPduInfoType* info, phPduLengthType* bufferSizePtr)
{
    switch (g_pdur)
    {
    case PH_CAN:
        return phCom_CopyRxData(info, bufferSizePtr);
        break;
    
    default:
        break;
    }
}

void phPduR_CanTpRxIndication(PhTypes_ErrorCode_t result)
{
    switch (g_pdur)
    {
    case PH_CAN:
        phCom_TpRxIndication(result);
        break;
    
    default:
        break;
    }
}
phBufReq_ReturnType phPduR_CanTpStartOfReception(const phPduInfoType* info, phPduLengthType TpSduLength, phPduLengthType *bufferSizePtr)
{
    switch (g_pdur)
    {
    case PH_CAN:
        return phCom_StartOfReception(info, TpSduLength, bufferSizePtr);
        break;
    
    default:
        break;
    }
}
phBufReq_ReturnType phPduR_CanTpCopyTxData(const phPduInfoType* info, const phRetryInfoType* retry, phPduLengthType* bufferSizePtr)
{
    switch (g_pdur)
    {
    case PH_CAN:
        return phCom_CopyTxData(info, retry, bufferSizePtr);
        break;
    
    default:
        break;
    }
}
void phPduR_CanTpTxConfirmation(PhTypes_ErrorCode_t result)
{
    switch (g_pdur)
    {
    case PH_CAN:
        phCom_TpTxConfirmation(result);
        break;
    
    default:
        break;
    }
}
PhTypes_ErrorCode_t phPduR_CanTpTriggerTransmit(const phPduInfoType *PduInfoPtr)
{
    switch (g_pdur)
    {
    case PH_CAN:
        return phCom_TriggerTransmit(PduInfoPtr);
        break;
    
    default:
        break;
    }
}
