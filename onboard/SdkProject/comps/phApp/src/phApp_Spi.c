#include "phApp_Spi.h"
#include "phSpi.h"
#include "phQueue.h"
#include "phApp_DataTypes.h"
#include <string.h>
#include "device_registers.h"

static uint8_t tx[MESSAGE_SIZE];
static uint8_t rx[MESSAGE_SIZE];
static volatile uint8_t f_transfer = 0;

static void spi_cb(void *ud)
{
    (void)ud;

    uint16_t len = (uint16_t)rx[0] | ((uint16_t)rx[1] << 8);
    uint8_t grp = rx[2];
    uint8_t id = rx[3];

    if (len > PAYLOAD_SIZE)
        len = PAYLOAD_SIZE;
    if (len > (MESSAGE_SIZE - 4))
        len = (MESSAGE_SIZE - 4);

    if (len > 0u)
    {
        phApp_DataTypes_t data;
        data.length = len;
        data.group = grp;
        data.id = id;
        memcpy(data.payload, &rx[4], len);
        if (len < PAYLOAD_SIZE)
            memset(&data.payload[len], 0, PAYLOAD_SIZE - len);
        (void)QueueTX_Push(&data, len);
    }

    f_transfer = 0;
}

void phApp_SpiInit(void)
{
    phSpi_SlaveInit(&spi_cb);

    memset(tx, 0, MESSAGE_SIZE);
    memset(rx, 0, MESSAGE_SIZE);
    f_transfer = 0;
}

void phApp_SpiMainFunction(void)
{
    if (!f_transfer)
    {
        bool has_tx_data = false;
        phApp_DataTypes_t out;

        memset(tx, 0, MESSAGE_SIZE);
        memset(rx, 0, MESSAGE_SIZE);

        if (!QueueRX_IsEmpty() && QueueRX_Pop(&out) == PH_ERR_OK)
        {
            uint16_t len = out.length;
            if (len > PAYLOAD_SIZE)
                len = PAYLOAD_SIZE;
            if (len > (MESSAGE_SIZE - 4))
                len = (MESSAGE_SIZE - 4);

            tx[0] = (uint8_t)(len & 0xFF);
            tx[1] = (uint8_t)((len >> 8) & 0xFF);
            tx[2] = out.group;
            tx[3] = out.id;
            if (len > 0)
                memcpy(&tx[4], out.payload, len);

            has_tx_data = true;
        }

        f_transfer = 1;
        if (phSpi_SlaveTransfer(tx, rx, MESSAGE_SIZE) == PH_ERR_OK)
        {
            if (has_tx_data)
                phSpi_SlaveSetReady();
        }
        else
        {
            f_transfer = 0;
        }
        return;
    }

    if (!QueueRX_IsEmpty() && phSpi_SlaveIsCsHigh())
    {
        phApp_DataTypes_t out;
        if (QueueRX_Front(&out) == PH_ERR_OK)
        {
            uint16_t len = out.length;
            if (len > PAYLOAD_SIZE)
                len = PAYLOAD_SIZE;
            if (len > (MESSAGE_SIZE - 4))
                len = (MESSAGE_SIZE - 4);

            phSpi_SlaveAbort();
            f_transfer = 0;

            memset(tx, 0, MESSAGE_SIZE);
            memset(rx, 0, MESSAGE_SIZE);

            // //    Dubug code
            // out.length = 11;  // payload size
            // out.group = 0x10; // ví dụ group ID
            // out.id = 0x11;    // ví dụ message ID

            // // Fill payload test (16 byte)
            // for (uint8_t i = 0; i < out.length; i++)
            // {
            //     out.payload[i] = (uint8_t)(i + 1); // 01 02 03 ... 10
            // }

            tx[0] = (uint8_t)(len & 0xFF);
            tx[1] = (uint8_t)((len >> 8) & 0xFF);
            tx[2] = out.group;
            tx[3] = out.id;
            if (len > 0)
                memcpy(&tx[4], out.payload, len);

            // // Debug
            // if(out.length == 0x0011 && out.group == 0x10 && out.id == 0x11 && out.payload[5] == 0xAA) PTD->PTOR = (1u << 16);
            f_transfer = 1;
            if (phSpi_SlaveTransfer(tx, rx, MESSAGE_SIZE) == PH_ERR_OK)
            {
                phSpi_SlaveSetReady();
                (void)QueueRX_Pop(&out); /* pop thật khi arm OK */
            }
            else
            {
                f_transfer = 0;
            }
        }
    }
}
