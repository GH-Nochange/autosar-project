#include "phCanTp.h"
#include "phCanIf.h"
#include "phPduR.h"
#include "phPduR_CanTp.h"
#include "phTypes.h"
#include "string.h"

#define CAN_FRAME_SIZE 8

// TX
static const uint8_t *TX_appPtr = NULL;
static phPduLengthType TX_totalLen = 0;
static phPduLengthType TX_sentLen = 0;
static uint8_t TX_SN = 0;
// static phPduLengthType TX_bufferSizePtr;
static phCanTpState txState = PH_IDLE;

// RX
static phPduLengthType RX_bufferSizePtr;
static uint8_t RX_SN = 0;
static phPduLengthType totalLen;
static phPduLengthType copiedLen;

PhTypes_ErrorCode_t phCanTp_Transmit(const phPduInfoType *PduInfoPtr)
{
    if (!PduInfoPtr || !PduInfoPtr->SduDataPtr || PduInfoPtr->SduLength == 0u)
        return PH_ERR_FAILED;
    if (txState != PH_IDLE)
        return PH_ERR_FAILED;

    if (PduInfoPtr->SduLength <= 7u) // Single Frame
    {
        phPduInfoType info;
        static uint8_t sfBuf[8];
        info.SduDataPtr = sfBuf;
        info.MetaDataPtr = NULL;
        info.SduDataPtr[0] = (uint8_t)((PCI_TYPE_SF << 4) | (PduInfoPtr->SduLength & 0x0F));
        memcpy(&info.SduDataPtr[1], PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
        info.SduLength = (phPduLengthType)(1u + PduInfoPtr->SduLength);

        txState = PH_SF;
        return phCanIf_Transmit(&info);
    }

    if (PduInfoPtr->SduLength > 0x0FFFu)
        return PH_ERR_FAILED;
    // Multiple Frame (First Frame)
    phPduInfoType infoFirstFrame;
    static uint8_t ffBuf[8];

    infoFirstFrame.SduDataPtr = ffBuf;
    infoFirstFrame.MetaDataPtr = NULL;

    infoFirstFrame.SduDataPtr[0] = (uint8_t)((PCI_TYPE_FF << 4) | ((PduInfoPtr->SduLength >> 8) & 0x0F));
    infoFirstFrame.SduDataPtr[1] = (uint8_t)(PduInfoPtr->SduLength & 0xFF);

    memcpy(&infoFirstFrame.SduDataPtr[2], PduInfoPtr->SduDataPtr, 6u);
    infoFirstFrame.SduLength = 8u;

    TX_appPtr = PduInfoPtr->SduDataPtr;
    TX_totalLen = PduInfoPtr->SduLength;
    TX_sentLen = 6u;
    TX_SN = 1u;

    txState = PH_FF;
    return phCanIf_Transmit(&infoFirstFrame);
}

void phCanTp_TxConfirmation(PhTypes_ErrorCode_t result)
{
    if (result != PH_ERR_OK)
    {
        txState = PH_IDLE;
        phPduR_CanTpTxConfirmation(PH_ERR_FAILED);
        return;
    }
    switch (txState)
    {
    case PH_SF:
        txState = PH_IDLE;
        phPduR_CanTpTxConfirmation(result);
        break;

    case PH_FF:
        txState = PH_WAIT_FC;
        break;

    case PH_CF: // Update: set flag & transmit on main function
    {
        phPduLengthType left_before = (phPduLengthType)(TX_totalLen - TX_sentLen);
        phPduLengthType just = (left_before > 7u) ? 7u : left_before;
        TX_sentLen += just;
        TX_SN = (uint8_t)((TX_SN + 1u) & 0x0F);

        if (TX_sentLen >= TX_totalLen)
        {
            txState = PH_IDLE;
            phPduR_CanTpTxConfirmation(PH_ERR_OK);
            break;
        }

        static uint8_t cfBuf[8];
        phPduInfoType info;
        phPduLengthType chunk = (phPduLengthType)((TX_totalLen - TX_sentLen) > 7u ? 7u : (TX_totalLen - TX_sentLen));

        info.SduDataPtr = cfBuf;
        info.MetaDataPtr = NULL;
        info.SduDataPtr[0] = (uint8_t)((PCI_TYPE_CF << 4) | (TX_SN & 0x0F));
        memcpy(&info.SduDataPtr[1], &TX_appPtr[TX_sentLen], chunk);
        info.SduLength = (phPduLengthType)(1u + chunk);

        if (phCanIf_Transmit(&info) != PH_ERR_OK)
        {
            txState = PH_IDLE;
            phPduR_CanTpTxConfirmation(PH_ERR_FAILED);
        }
        break;
    }

    case PH_WAIT_FC:
    case PH_IDLE:
    default:
        break;
    }
}

void phCanTp_MainFunction(void)
{
}

static void phPrepareFC_AllowAll(void)
{
    static uint8_t fc_buf[3];
    phPduInfoType pdu;

    /* PCI: FT=FC(0x3) | FS=CTS(0x0) */
    fc_buf[0] = (uint8_t)((PCI_TYPE_FC << 4) | 0);
    fc_buf[1] = 0x00;
    fc_buf[2] = 0x00;

    pdu.SduDataPtr = fc_buf;
    pdu.MetaDataPtr = NULL;
    pdu.SduLength = (phPduLengthType)sizeof(fc_buf); /* 3 byte */

    (void)phCanIf_Transmit(&pdu);
}

void phCanTp_RxIndication(const phPduInfoType *PduInfoPtr)
{
    phPduLengthType TpSduLength = 0;
    phPduInfoType info;
    phBufReq_ReturnType bufferReq;
    switch ((PduInfoPtr->SduDataPtr[0] >> 4) & 0x0F)
    {
    case PCI_TYPE_SF:
        TpSduLength = PduInfoPtr->SduDataPtr[0] & 0x0F;
        if (TpSduLength == 0 || TpSduLength > 7 || TpSduLength > (PduInfoPtr->SduLength - 1))
        {
            return;
        }

        info.SduDataPtr = (uint8_t *)&PduInfoPtr->SduDataPtr[1];
        info.SduLength = TpSduLength;

        bufferReq = phPduR_CanTpStartOfReception(&info, TpSduLength, &RX_bufferSizePtr);

        if (bufferReq != PH_BUFREQ_OK || (RX_bufferSizePtr < info.SduLength))
            return;
        if (phPduR_CanTpCopyRxData(&info, &RX_bufferSizePtr) == PH_BUFREQ_OK)
        {
            phPduR_CanTpRxIndication(PH_ERR_OK);
        }

        break;

    case PCI_TYPE_FF:

        TpSduLength = ((PduInfoPtr->SduDataPtr[0] & 0x0F) << 8) | (PduInfoPtr->SduDataPtr[1]);
        if (TpSduLength == 0)
            return;

        phPduLengthType firstChunk = (PduInfoPtr->SduLength > 2) ? (PduInfoPtr->SduLength - 2) : 0;
        if (firstChunk > 6)
            firstChunk = 6;
        info.SduDataPtr = (uint8_t *)&PduInfoPtr->SduDataPtr[2];
        info.MetaDataPtr = NULL;
        info.SduLength = firstChunk;

        bufferReq = phPduR_CanTpStartOfReception(&info, TpSduLength, &RX_bufferSizePtr);

        if (bufferReq != PH_BUFREQ_OK || RX_bufferSizePtr < info.SduLength)
            return;

        if (phPduR_CanTpCopyRxData(&info, &RX_bufferSizePtr) == PH_BUFREQ_OK)
        {
            phPrepareFC_AllowAll();

            totalLen = TpSduLength;
            copiedLen = firstChunk;
            RX_SN = 0;
        }
        break;

    case PCI_TYPE_CF:
        if (totalLen == 0 || copiedLen >= totalLen) // Not received or already completed
        {
            phPduR_CanTpRxIndication(PH_ERR_FAILED);
            break;
        }

        uint8_t sn_expect = (uint8_t)((RX_SN + 1U) & 0x0Fu);
        uint8_t sn_rx = (uint8_t)(PduInfoPtr->SduDataPtr[0] & 0x0F);
        if (sn_rx != sn_expect) // Error sequence number
        {
            phPduR_CanTpRxIndication(PH_ERR_FAILED);
            break;
        }

        phPduLengthType chunk = (PduInfoPtr->SduLength > 1u) ? (PduInfoPtr->SduLength - 1u) : 0u;
        phPduLengthType left = (phPduLengthType)(totalLen - copiedLen);
        if (chunk > left)
            chunk = left;

        phPduInfoType info;
        info.SduDataPtr = (uint8_t *)&PduInfoPtr->SduDataPtr[1];
        info.MetaDataPtr = NULL;
        info.SduLength = chunk;

        if (phPduR_CanTpCopyRxData(&info, &RX_bufferSizePtr) != PH_BUFREQ_OK)
        {
            phPduR_CanTpRxIndication(PH_ERR_FAILED);
            break;
        }

        copiedLen = (phPduLengthType)(copiedLen + chunk);
        RX_SN = sn_expect;

        if (copiedLen >= totalLen) // Reception complete
        {
            phPduR_CanTpRxIndication(PH_ERR_OK);
            totalLen = 0u;
            copiedLen = 0u;
            RX_SN = 0u;
        }
        break;
    case PCI_TYPE_FC:
        if (txState == PH_WAIT_FC && PduInfoPtr->SduLength >= 3u)
        {
            uint8_t fs = (uint8_t)(PduInfoPtr->SduDataPtr[0] & 0x0F);

            if (fs == FC_FS_CTS)
            {
                static uint8_t cfBuf[8];
                phPduInfoType info;

                phPduLengthType left = (phPduLengthType)(TX_totalLen - TX_sentLen);
                phPduLengthType chunk = (left > 7u) ? 7u : left;

                info.SduDataPtr = cfBuf;
                info.MetaDataPtr = NULL;
                info.SduDataPtr[0] = (uint8_t)((PCI_TYPE_CF << 4) | (TX_SN & 0x0F));
                memcpy(&info.SduDataPtr[1], &TX_appPtr[TX_sentLen], chunk);
                info.SduLength = (phPduLengthType)(1u + chunk);

                txState = PH_CF;
                if (phCanIf_Transmit(&info) != PH_ERR_OK) // send first CF
                {
                    txState = PH_IDLE;
                    phPduR_CanTpTxConfirmation(PH_ERR_FAILED);
                }
            }
            else if (fs == FC_FS_WT)
            {
            }
            else
            {
                txState = PH_IDLE;
                phPduR_CanTpTxConfirmation(PH_ERR_FAILED);
            }
        }
        break;
    }
}
