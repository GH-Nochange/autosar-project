// #include "phApp_Spi.h"
// #include "phSpi.h"
// #include "phQueue.h"
// #include "phApp_DataTypes.h"
// #include <string.h>
// #include "device_registers.h"

// /* --- TX buffers --- */
// static uint8_t tx_buf[2][MESSAGE_SIZE+2];
// static uint8_t tx_dummy[MESSAGE_SIZE+2];

// /* --- RX buffer --- */
// static uint8_t rx[MESSAGE_SIZE+2];

// /* --- Internal state --- */
// static volatile uint8_t f_transfer = 0u;         /* A transfer is in progress */
// static volatile uint8_t tx_active = 0u;          /* Index of buffer currently used by HW */
// static volatile uint8_t tx_fill = 1u;            /* Index of buffer where app writes next */
// static volatile uint8_t tx_active_has_data = 0u; /* Current transfer is a real frame? */

// /* Outstanding frames count (0..2): in-flight (+1 if any) + fill (+1 if any) */
// static volatile uint8_t outstanding = 0u;

// /* Swap roles safely before starting a new transfer */
// static inline void phApp_SpiSwapTxBuffers(void)
// {
//     uint8_t tmp = tx_active;
//     tx_active = tx_fill;
//     tx_fill = tmp;
// }

// static void spi_cb(void *ud)
// {
//     (void)ud;

//     uint16_t len = (uint16_t)rx[0] | ((uint16_t)rx[1] << 8);
//     if (len > MESSAGE_SIZE)
//     {
//         len = MESSAGE_SIZE;
//     }

//     if (len > 0u)
//     {
//         phApp_Data_t data;

//         data.header.group = (rx[2] >> 4) & 0x0F;
//         data.header.ecu = rx[2] & 0x0F;
//         data.header.id = rx[3];
//         data.header.length = (uint16_t)(rx[4] << 8) | (uint16_t)rx[5];

//         for(int i = 0; i< data.header.length; i++)
//         {
//             data.payload[i] = rx[i + 6]; // 2 byte spi_length + 4 byte header
//         }

//         if (len < MESSAGE_SIZE)
//         {
//             memset(((uint8_t *)&data) + len, 0, MESSAGE_SIZE - len);
//         }

//         (void)QueueRX_Push(&data);
//     }

//     f_transfer = 0u;

//     if (tx_active_has_data)
//     {
//         tx_active_has_data = 0u;
//         if (outstanding > 0u)
//         {
//             outstanding--;
//         }
//     }
// }

// void phApp_SpiInit(void)
// {
//     phSpi_SlaveInit(&spi_cb);

//     memset(tx_buf[0], 0, MESSAGE_SIZE + 2);
//     memset(tx_buf[1], 0, MESSAGE_SIZE + 2);

//     memset(tx_dummy, 0xFF, MESSAGE_SIZE + 2);
//     tx_dummy[0] = 0x00;
//     tx_dummy[1] = 0x00;

//     memset(rx, 0, MESSAGE_SIZE + 2);

//     f_transfer = 0u;
//     tx_active = 0u;
//     tx_fill = 1u;
//     tx_active_has_data = 0u;
//     outstanding = 0u;
// }

// void phApp_SpiPrepareData(phApp_Data_t *data)
// {
//     uint16_t len = (uint16_t)(data->header.length + 4u);
//     if (len > (MESSAGE_SIZE))
//     {
//         len = (uint16_t)(MESSAGE_SIZE);
//     }

//     uint8_t *txw = tx_buf[tx_fill];

//     txw[0] = (uint8_t)(len & 0xFF);
//     txw[1] = (uint8_t)((len >> 8) & 0xFF);

//     txw[2] = (data->header.group << 4) | (data->header.ecu);
//     txw[3] = data->header.id;
//     txw[4] = (data->header.length >> 8) & 0xFF;
//     txw[5] = data->header.length & 0xFF;
//     if (data->header.length > 0u)
//     {
//         memcpy(&txw[6], data->payload, data->header.length);
//     }

//     if (len < MESSAGE_SIZE)
//     {
//         memset(&txw[2 + len], 0, MESSAGE_SIZE - len);
//     }

//     if (outstanding < 2u)
//     {
//         outstanding++;
//     }
// }

// void phApp_SpiMainFunction(void)
// {
//     if (!f_transfer)
//     {
//         if (outstanding > 0u)
//         {
//             phApp_SpiSwapTxBuffers();
//             tx_active_has_data = 1u;
//         }
//         else
//         {
//             tx_active_has_data = 0u;
//         }

//         memset(rx, 0, MESSAGE_SIZE + 2);
//         f_transfer = 1u;

//         const uint8_t *tx_src = tx_active_has_data ? tx_buf[tx_active] : tx_dummy;

//         if (phSpi_SlaveTransfer(tx_src, rx, MESSAGE_SIZE + 2) == PH_ERR_OK)
//         {
//             if (tx_active_has_data)
//             {
//                 phSpi_SlaveSetReady();
//             }
//         }
//         else
//         {
//             f_transfer = 0u;
//         }
//         return;
//     }

//     if ((outstanding > 0u) && phSpi_SlaveIsCsHigh())
//     {
//         phSpi_SlaveAbort();

//         phApp_SpiSwapTxBuffers();
//         tx_active_has_data = 1u;

//         if (outstanding > 0u)
//         {
//             outstanding--;
//         }

//         memset(rx, 0, MESSAGE_SIZE + 2);
//         f_transfer = 1u;

//         if (phSpi_SlaveTransfer(tx_buf[tx_active], rx, MESSAGE_SIZE + 2) == PH_ERR_OK)
//         {
//             phSpi_SlaveSetReady();
//         }
//         else
//         {
//             f_transfer = 0u;
//         }
//     }
// } 


#include "phSpi.h"
#include <string.h>
#include <stdint.h>

#define XFER_SIZE 16u

static uint8_t tx_buf[XFER_SIZE];
static uint8_t rx_buf[XFER_SIZE];
static volatile uint8_t f_transfer = 0u;

/* Callback khi SPI transfer xong */
static void spi_cb(void *ud)
{
    (void)ud;
    f_transfer = 0u;

    // In dữ liệu nhận được từ master nếu cần
    // for (int i = 0; i < XFER_SIZE; i++) {
    //     printf("RX[%d] = 0x%02X\n", i, rx_buf[i]);
    // }
}

/* Init SPI slave */
void phApp_SpiInit(void)
{
    phSpi_SlaveInit(&spi_cb);

    /* Tạo dữ liệu test cố định */
    for (int i = 0; i < XFER_SIZE; i++) {
        tx_buf[i] = (uint8_t)(i * 0x11);   // 0x00, 0x11, 0x22, ...
    }

    memset(rx_buf, 0, XFER_SIZE);
    f_transfer = 0u;
}

/* Hàm gọi liên tục trong vòng while */
void phApp_SpiMainFunction(void)
{
    if (!f_transfer)
    {
        memset(rx_buf, 0, XFER_SIZE);
        f_transfer = 1u;

        if (phSpi_SlaveTransfer(tx_buf, rx_buf, XFER_SIZE) == PH_ERR_OK)
        {
            // phSpi_SlaveSetReady();  // báo master: slave có data sẵn
        }
        else
        {
            f_transfer = 0u;
        }
    }
}
