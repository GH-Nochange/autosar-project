#include "phCanTP.h"
#include "phCanTpQueue.h"
#include "phPduR.h"
#include "phCanIf.h"
#include <string.h>

static phCanTP_SF_t singleframeTX;
static phCanTP_FF_t firstframeTX;

static volatile uint8_t s_tpTxDoneFlag = 0;
static volatile uint8_t s_tpRxPendFlag = 0;
static volatile uint8_t s_tpBusy = 0;

static uint8_t s_rxBuf[8];
static uint8_t s_rxLen = 0;

static uint8_t isSingleFrame = 1;

static uint8_t flagSending = 0;
static uint8_t flagRXComplete = 0;

phCanTP_State_t canTpTXState = Idle_State;
uint16_t RXoffset;
uint8_t RX_sn = 0;

phPduR_Pdu_t pduRXData;

static void phCanTP_TX_Processing(void);
static void phCanTP_RX_Processing(uint8_t *data);
static void phCanTP_RX(void);

void Can_TxConfirmation(void)
{
    s_tpTxDoneFlag = 1;
}

void Can_RxIndication(const flexcan_msgbuff_t *frame)
{
    uint8_t len = frame->dataLen;
    if (len > 8)
        len = 8;
    for (uint8_t i = 0; i < len; i++)
        s_rxBuf[i] = frame->data[i];
    s_rxLen = len;
    s_tpRxPendFlag = 1;
}

void phCanTP_Init(void)
{
    canTpTXState = Idle_State;
    flagSending = 0;
    Queue_Init();
}

void phCanTP_TX(phPduR_Pdu_t *pduData)
{
    if (CANIF_ID_TYPE == 0)
    {
        if (pduData->length <= 7)
        {
            phCanTP_SF_t sf;
            sf.FT = SF;
            sf.SFDL = pduData->length;
            memcpy(sf.Data, pduData->data, pduData->length);
            singleframeTX = sf;
            canTpTXState = SF_State;
        }
        else
        {
            firstframeTX.FT = FF;
            firstframeTX.MFDL = pduData->length;
            memcpy(firstframeTX.Data, pduData->data, 6); // First 6 bytes
            canTpTXState = FF_State;

            uint16_t offset = 6;
            uint8_t sn = 1;

            while (offset < pduData->length)
            {
                uint8_t chunk = ((pduData->length - offset) >= 7) ? 7 : (uint8_t)(pduData->length - offset);
                phCanTP_CF_t cf;
                cf.FT = CF;
                cf.SN = sn;
                memcpy(cf.Data, &pduData->data[offset], chunk);
                QueueTX_Push(&cf);

                offset += chunk;
                sn = (uint8_t)((sn + 1u) & 0x0F); // (SN + 1) mod 16
            }
        }
    }
    else
    {
        // Handle other frame formats if necessary
    }
    flagSending = 1;
}

void CanTpMainFunction()
{
    if (s_tpBusy)
        return; 
    s_tpBusy = 1;

    if (s_tpRxPendFlag)
    {
        s_tpRxPendFlag = 0;
        phCanTP_RX_Processing(s_rxBuf);
    }

    if (flagSending && (s_tpTxDoneFlag == 1))
    {
        s_tpTxDoneFlag = 0;
        phCanTP_TX_Processing();

    }

    s_tpBusy = 0;
}

static void phCanTP_TX_Processing(void)
{
    switch (canTpTXState)
    {
    case SF_State:
        Can_Transmit((uint8_t *)&singleframeTX, sizeof(singleframeTX));
        flagSending = 0;
        break;
    case FF_State:
        Can_Transmit((uint8_t *)&firstframeTX, sizeof(firstframeTX));
        break;
    case CF_State:
        phCanTP_CF_t cf;
        if(QueueTX_Pop(&cf)== PH_ERR_OK)
        {
            Can_Transmit((uint8_t *)&cf, sizeof(cf));
            if (QueueTX_IsEmpty())
            {
                phCanTP_Init(); 
            }
        }
        else
        {
            phCanTP_Init(); 
            return;
        }
        break;
    case WaitFC_State:
        break;
    case Idle_State:
        break;
    }
}

static void phHandle_FC(phCanTP_FC_t fc)
{
    switch (fc.Flag)
    {
    case 0:
        canTpTXState = CF_State;
        break;
    case 1:
        return;
    case 2:
        phCanTP_Init();
        return;
    default:
        break;
    }
    // Block Size & STmin
}

static void phCanTP_RX_Processing(uint8_t *data)
{
    switch (data[0] >> 4)
    {
    case SF:
        isSingleFrame = 1;
        pduRXData.length = data[0] & 0x0F;
        memcpy(pduRXData.data, &data[1], pduRXData.length);
        flagRXComplete = 1;
        break;
    case FF:
        phCanTP_FC_t fc =
            {
                .FT = FC,
                .Flag = 0,
                .BlockSize = 0,
                .STMin = 5u};

        pduRXData.length = ((data[0] & 0x0F) << 8) | data[1];
        for (int i = 0; i < 6; i++)
        {
            pduRXData.data[i] = data[i + 2];
        }

        RXoffset = 6;
        RX_sn = 1;

        // Send flow control
        Can_Transmit((uint8_t *)&fc, sizeof(fc));

        break;
    case CF:
        if ((data[0] & 0x0F) == RX_sn)
        {
            uint8_t chunk = ((pduRXData.length - RXoffset) >= 7) ? 7 : (uint8_t)(pduRXData.length - RXoffset);

            for (int i = 0; i < chunk; i++)
            {
                pduRXData.data[RXoffset + i] = data[i + 1];
            }
            RXoffset += chunk;
            if (RXoffset >= pduRXData.length)
            {
                flagRXComplete = 1;
                RX_sn = 0;
            }
            else
            {
                RX_sn = (uint8_t)((RX_sn + 1u) & 0x0F);
            }
        }
        break;
    case FC:
        phCanTP_FC_t fc;
        memcpy(&fc, data, 3);
        phHandle_FC(fc);
        break;
    }

    if (flagRXComplete)
    {
        phCanTP_RX();
    }
}

static void phCanTP_RX(void)
{
    if (RXoffset == pduRXData.length)
    {
        phPduR_ReceivePdu(&pduRXData);
    }
    RXoffset = 0;
    flagRXComplete = 0;
}
