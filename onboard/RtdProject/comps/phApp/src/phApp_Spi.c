#include "phApp_Spi.h"
#include "Spi.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include <string.h>

/* --- TX buffers --- */
static uint8_t tx_buf[2][MESSAGE_SIZE+2];
static uint8_t tx_dummy[MESSAGE_SIZE+2];

/* --- RX buffer --- */
static uint8_t rx[MESSAGE_SIZE+2];

/* --- Internal state --- */
static volatile uint8_t f_transfer = 0u;         /* A transfer is in progress */
static volatile uint8_t tx_active = 0u;          /* Index of buffer currently used by HW */
static volatile uint8_t tx_fill = 1u;            /* Index of buffer where app writes next */
static volatile uint8_t tx_active_has_data = 0u; /* Current transfer is a real frame? */

/* Outstanding frames count (0..2): in-flight (+1 if any) + fill (+1 if any) */
static volatile uint8_t outstanding = 0u;

/* Swap roles safely before starting a new transfer */
static inline void phApp_SpiSwapTxBuffers(void)
{
    uint8_t tmp = tx_active;
    tx_active = tx_fill;
    tx_fill = tmp;
}

void SpiJob1_EndCb(void)
{
    uint16_t len = (uint16_t)rx[0] | ((uint16_t)rx[1] << 8);
    if (len > MESSAGE_SIZE)
    {
        len = MESSAGE_SIZE;
    }

    if (len > 0u)
    {
        phApp_Data_t data;

        data.header.group = (rx[2] >> 4) & 0x0F;
        data.header.ecu = rx[2] & 0x0F;
        data.header.id = rx[3];
        data.header.length = (uint16_t)(rx[4] << 8) | (uint16_t)rx[5];

        for(int i = 0; i< data.header.length; i++)
        {
            data.payload[i] = rx[i + 6]; // 2 byte spi_length + 4 byte header
        }

        if (len < MESSAGE_SIZE)
        {
            memset(((uint8_t *)&data) + len, 0, MESSAGE_SIZE - len);
        }

        (void)QueueRX_Push(&data);
    }

    f_transfer = 0u;

    if (tx_active_has_data)
    {
        tx_active_has_data = 0u;
        if (outstanding > 0u)
        {
            outstanding--;
        }
    }
}

void phApp_SpiInit(void)
{
    memset(tx_buf[0], 0, MESSAGE_SIZE + 2);
    memset(tx_buf[1], 0, MESSAGE_SIZE + 2);

    memset(tx_dummy, 0xFF, MESSAGE_SIZE + 2);
    tx_dummy[0] = 0x00;
    tx_dummy[1] = 0x00;

    memset(rx, 0, MESSAGE_SIZE + 2);

    f_transfer = 0u;
    tx_active = 0u;
    tx_fill = 1u;
    tx_active_has_data = 0u;
    outstanding = 0u;
}

void phApp_SpiPrepareData(phApp_Data_t *data)
{
    uint16_t len = (uint16_t)(data->header.length + 4u);
    if (len > (MESSAGE_SIZE))
    {
        len = (uint16_t)(MESSAGE_SIZE);
    }

    uint8_t *txw = tx_buf[tx_fill];

    txw[0] = (uint8_t)(len & 0xFF);
    txw[1] = (uint8_t)((len >> 8) & 0xFF);

    txw[2] = (data->header.group << 4) | (data->header.ecu);
    txw[3] = data->header.id;
    txw[4] = (data->header.length >> 8) & 0xFF;
    txw[5] = data->header.length & 0xFF;
    if (data->header.length > 0u)
    {
        memcpy(&txw[6], data->payload, data->header.length);
    }

    if (len < MESSAGE_SIZE)
    {
        memset(&txw[2 + len], 0, MESSAGE_SIZE - len);
    }

    if (outstanding < 2u)
    {
        outstanding++;
    }
}

void phApp_SpiMainFunction(void)
{
    Std_ReturnType ret;
    Spi_SeqResultType seqResult;

    if (!f_transfer)
    {
        if (outstanding > 0u)
        {
            phApp_SpiSwapTxBuffers();
            tx_active_has_data = 1u;
        }
        else
        {
            tx_active_has_data = 0u;
        }

        f_transfer = 1u;

        /* Ghi vào internal buffer */
        const uint8_t *tx_src = tx_active_has_data ? tx_buf[tx_active] : tx_dummy;
        ret = Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_Slave, tx_src);
        if (ret != E_OK)
        {
            f_transfer = 0u;
            return;
        }

        /* Bắt đầu truyền */
        ret = Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Slave);
        if (ret != E_OK)
        {
            f_transfer = 0u;
            return;
        }
    }
    else
    {
        seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Slave);
        if (seqResult == SPI_SEQ_OK)
        {
            /* Đọc dữ liệu nhận về */
            ret = Spi_ReadIB(SpiConf_SpiChannel_SpiChannel_Slave, rx);
            if (ret == E_OK)
            {
                // TODO
            }

            if (tx_active_has_data)
            {
                tx_active_has_data = 0u;
                if (outstanding > 0u)
                {
                    outstanding--;
                }
            }

            f_transfer = 0u;
        }
        else if (seqResult == SPI_SEQ_FAILED)
        {
            f_transfer = 0u; // reset cho lần sau
        }
    }
}
