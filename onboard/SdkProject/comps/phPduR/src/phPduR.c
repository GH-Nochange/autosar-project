#include "phPduR.h"
#include "phComQueue.h"
#include "phApp_DataTypes.h"
#include "phCanTP.h"
#include "phTypes.h"

static phPduR_Protocol_t protocol;

void phPduR_Init(void)
{
    protocol = PDU_CAN;
}

PhTypes_ErrorCode_t phPduR_TX_Handle(void)
{
    if (QueueTX_IsEmpty())
    {
        return ERR_NoResource;
    }
    phApp_DataTypes_t data;
    QueueTX_Pop(&data);
    if (data.header.id == Internal)
    {
        switch (data.payload[0])
        {
        case SetProtocol:
            if (data.payload[1] == PDU_CAN)
            {
                protocol = PDU_CAN;
            }
            else if (data.payload[1] == PDU_SPI)
            {
                protocol = PDU_SPI;
            }
            else
            {
                return ERR_InvalidArg; 
            }
            break;

        default:
            return ERR_InvalidArg;
        }
    }
    else
    {
        phPduR_Pdu_t pdu;
        pdu.length = data.header.length + 4; // 4byte header
        memcpy(pdu.data, &data, pdu.length);

        phPduR_SendPdu(&pdu);
    }

    return ERR_Ok;
}

void phPduR_SendPdu(phPduR_Pdu_t *pdu)
{
    switch (protocol)
    {
    case PDU_CAN:
        phCanTP_TX(pdu);
        break;

    case PDU_SPI:

        break;

    default:
        break;
    }
}

void phPduR_ReceivePdu(phPduR_Pdu_t *pdu)
{
    phApp_DataTypes_t datarx;
    memcpy(&datarx, pdu->data, pdu->length);
    QueueRX_Push(&datarx);
}
