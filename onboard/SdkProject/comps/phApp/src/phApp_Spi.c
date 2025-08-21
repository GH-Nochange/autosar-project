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
    
    if (len > MESSAGE_SIZE)
        len = MESSAGE_SIZE;

    if (len > 0u)
    {
        phApp_Data_t data;
        memcpy(&data, &rx[2], len);
        if (len < MESSAGE_SIZE)
            memset(&data, 0, MESSAGE_SIZE - len);
        (void)QueueTX_Push(&data);
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
        phApp_Data_t out;

        memset(tx, 0, MESSAGE_SIZE);
        memset(rx, 0, MESSAGE_SIZE);

        if (!QueueRX_IsEmpty() && QueueRX_Pop(&out) == PH_ERR_OK)
        {
            uint16_t len = out.header.length + 4;
            if (len > MESSAGE_SIZE)
                len = MESSAGE_SIZE;
            if (len > 0)
                memcpy(&tx[2], out.payload, len);

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
        phApp_Data_t out;
        if (QueueRX_Front(&out) == PH_ERR_OK)
        {
            uint16_t len = out.header.length + 4;
            if (len > MESSAGE_SIZE)
                len = MESSAGE_SIZE;

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

            memcpy(&tx[2], out.payload, len);

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
