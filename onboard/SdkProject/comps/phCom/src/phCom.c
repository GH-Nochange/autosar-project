#include "phCom.h"
#include "phQueue.h"
#include "phComStack_Types.h"
#include "phPduR_Com.h"
#include "phBoard.h"
#include <string.h>
#include "device_registers.h"

#ifndef PH_COM_MAX_PDU
#define PH_COM_MAX_PDU 256u
#endif

static uint8_t s_txBuf[PH_COM_MAX_PDU];
static phPduInfoType s_txPdu = {.SduDataPtr = s_txBuf, .MetaDataPtr = NULL, .SduLength = 0};
static uint8_t sending_flag = 0;

static uint8_t s_rxBuf[PH_COM_MAX_PDU];
static phPduInfoType phRX_PduInfoPtr = {.SduDataPtr = s_rxBuf, .MetaDataPtr = NULL, .SduLength = 0};
/* Total expected bytes to receive */
static phPduLengthType s_rxExpected = 0;

/* Bytes already received/written */
static phPduLengthType s_rxWritten = 0;

PhTypes_ErrorCode_t phCom_Send(const phApp_Data_t *Data)
{
    if (sending_flag == 1)
        return PH_ERR_BUSY;
    if (Data == NULL)
        return PH_ERR_INVALID_ARG;
    if (Data->header.length > PH_COM_MAX_PDU - 2)
        return PH_ERR_NO_RESOURCE;

    s_txBuf[0] = (Data->header.group << 4) | (Data->header.ecu);
    s_txBuf[1] = Data->header.id;
    s_txBuf[2] = (Data->header.length >> 8) & 0x0F;
    s_txBuf[3] = Data->header.length & 0x0F;
    if (Data->header.length > 0)
    {

        memcpy(&s_txBuf[4], Data->payload, (size_t)(Data->header.length));
    }

    s_txPdu.SduLength = Data->header.length + 4;

    sending_flag = 1;
    if (phPduR_ComTransmit(&s_txPdu) != PH_ERR_OK)
    {
        sending_flag = 0;
        return PH_ERR_FAILED;
    }
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t phCom_Recv(const phApp_Data_t *Data) // ID
{
    phBoard_Recv(Data);
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
        phApp_Data_t data;
        memset(&data, 0, sizeof(data));
        memcpy(&data, phRX_PduInfoPtr.SduDataPtr, phRX_PduInfoPtr.SduLength);

        phCom_Recv(&data);
    }

    memset(s_rxBuf, 0, sizeof(s_rxBuf));
    memset(&phRX_PduInfoPtr, 0, sizeof(phRX_PduInfoPtr));
    phRX_PduInfoPtr.SduDataPtr = s_rxBuf;
    s_rxExpected = 0;
    s_rxWritten = 0;
}

void phCom_MainFunctionTx(void)
{
    phApp_Data_t data;

    if (QueueTX_Front(&data) == PH_ERR_OK)
    {
        if (phCom_Send(&data) == PH_ERR_OK)
        {
            QueueTX_Pop(&data);
        }
    }
}