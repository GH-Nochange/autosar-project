#include "phCom.h"
#include "phQueue.h"
#include "phComStack_Types.h"
#include "phPduR_Com.h"
#include <string.h>

#ifndef PH_COM_MAX_PDU
#define PH_COM_MAX_PDU 256u
#endif

static uint8_t s_txBuf[PH_COM_MAX_PDU];
static phPduInfoType s_txPdu = {.SduDataPtr = s_txBuf, .MetaDataPtr = NULL, .SduLength = 0};
static uint8_t sending_flag = 0;

static uint8_t s_rxBuf[PH_COM_MAX_PDU];
static phPduInfoType phRX_PduInfoPtr = {.SduDataPtr = s_rxBuf, .MetaDataPtr = NULL, .SduLength = 0};
static phPduLengthType s_rxExpected = 0; 
static phPduLengthType s_rxWritten = 0;  


PhTypes_ErrorCode_t phCom_Send(const phApp_DataTypes_t *Data)
{
    if (sending_flag == 1)
        return PH_ERR_BUSY;
    if (Data == NULL)
        return PH_ERR_INVALID_ARG;
    if (Data->length < 2u)
        return PH_ERR_INVALID_ARG; 
    if (Data->length > PH_COM_MAX_PDU)
        return PH_ERR_NO_RESOURCE;

    s_txBuf[0] = Data->group;
    s_txBuf[1] = Data->id;
    if (Data->length > 2u)
    {
        memcpy(&s_txBuf[2], Data->payload, (size_t)(Data->length - 2u));
    }

    s_txPdu.SduLength = Data->length;

    sending_flag = 1;
    if (phPduR_ComTransmit(&s_txPdu) != PH_ERR_OK)
    {
        sending_flag = 0;
        return PH_ERR_FAILED;
    }
    return PH_ERR_OK;
}

void phCom_TpTxConfirmation(PhTypes_ErrorCode_t result)
{
    (void)result;
    sending_flag = 0;
}

phBufReq_ReturnType phCom_StartOfReception(const phPduInfoType *info,
                                           phPduLengthType TpSduLength,
                                           phPduLengthType *bufferSizePtr)
{
    (void)info; 

    if (s_rxExpected != 0 && s_rxWritten < s_rxExpected)
    {
        if (bufferSizePtr)
            *bufferSizePtr = 0;
        return PH_BUFREQ_E_NOT_OK;
    }

    if (TpSduLength == 0 || TpSduLength > PH_COM_MAX_PDU)
    {
        if (bufferSizePtr)
            *bufferSizePtr = 0;
        return PH_BUFREQ_E_NOT_OK;
    }

    
    s_rxExpected = TpSduLength;
    s_rxWritten = 0;
    phRX_PduInfoPtr.SduLength = TpSduLength; 

    if (bufferSizePtr)
        *bufferSizePtr = PH_COM_MAX_PDU; 
    return PH_BUFREQ_OK;
}

phBufReq_ReturnType phCom_CopyRxData(const phPduInfoType *info, phPduLengthType *bufferSizePtr)
{
    if (!info || !info->SduDataPtr)
    {
        if (bufferSizePtr)
            *bufferSizePtr = (phPduLengthType)(PH_COM_MAX_PDU - s_rxWritten);
        return PH_BUFREQ_E_NOT_OK;
    }

    phPduLengthType chunk = info->SduLength;
    if (s_rxWritten + chunk > s_rxExpected)
    {
        if (bufferSizePtr)
            *bufferSizePtr = (phPduLengthType)(PH_COM_MAX_PDU - s_rxWritten);
        return PH_BUFREQ_E_NOT_OK;
    }

    memcpy(&s_rxBuf[s_rxWritten], info->SduDataPtr, (size_t)chunk);
    s_rxWritten = (phPduLengthType)(s_rxWritten + chunk);

    if (bufferSizePtr)
    {
        phPduLengthType remain = (s_rxExpected > s_rxWritten) ? (s_rxExpected - s_rxWritten) : 0u;
        *bufferSizePtr = remain;
    }
    return PH_BUFREQ_OK;
}

void phCom_TpRxIndication(PhTypes_ErrorCode_t result)
{
    if (result == PH_ERR_OK && s_rxWritten == s_rxExpected && s_rxExpected >= 2u)
    {
        phApp_DataTypes_t data;
        data.length = s_rxExpected;
        data.group = s_rxBuf[0];
        data.id = s_rxBuf[1];
        if (data.length > 2u)
        {
            memcpy(data.payload, &s_rxBuf[2], (size_t)(data.length - 2u));
        }

        (void)QueueRX_Push(&data, data.length + 2);
    }

    memset(s_rxBuf, 0, sizeof(s_rxBuf));
    memset(&phRX_PduInfoPtr, 0, sizeof(phRX_PduInfoPtr));
    phRX_PduInfoPtr.SduDataPtr = s_rxBuf;
    s_rxExpected = 0;
    s_rxWritten = 0;
}


void phCom_MainFunctionTx(void)
{
    phApp_DataTypes_t data;
    QueueTX_Front(&data);
    if(phCom_Send(&data)==PH_ERR_OK)
    {
        QueueTX_Pop(&data);
    }
}