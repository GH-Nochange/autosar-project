/**
 * @file phDriverSpi.c
 * @brief SPI Driver wrapper for FLEXIO-SPI using internal callback redirection
 */

#include "SpiDrv.h"
#include <string.h>

#define SPI_INSTANCE 0U 

#define DRIVER_TYPE FLEXIO_DRIVER_TYPE_INTERRUPTS
#define BIT_ORDER FLEXIO_SPI_TRANSFER_MSB_FIRST
#define TRANSFER_SIZE FLEXIO_SPI_TRANSFER_1BYTE
#define CLOCK_POLARITY 0U
#define CLOCK_PHASE 0U
#define MOSI_PIN 0U
#define MISO_PIN 1U
#define SCK_PIN 2U
#define SS_PIN 3U
#define RX_DMA_CHANNEL 255U
#define TX_DMA_CHANNEL 255U

// Internal static variables to store user callback
static phDriverSpi_Callback_t g_userCallback = NULL;
static void *g_userContext = NULL;

// Internal state handle for SPI slave
static flexio_spi_slave_state_t g_slaveState;

// Internal callback mapped from SDK to user-defined callback
static void phDriverSpi_InternalCallback(void *driverState, spi_event_t event, void *userData)
{
    if (g_userCallback != NULL)
    {
        PhTypes_ErrorCode_t status;

        if (event == SPI_EVENT_END_TRANSFER)
        {
            status = EER_OK; 
        }
        else
        {
            status = EER_Unknown; 
        }

        g_userCallback(status, g_userContext);
    }
}

PhTypes_ErrorCode_t phDriverSpi_SlaveRegisterCallback(phDriverSpi_Callback_t cb, void *context)
{
    g_userCallback = cb;
    g_userContext = context;
    return EER_OK;
}

PhTypes_ErrorCode_t phDriverSpi_SlaveInit(void)
{
    flexio_spi_slave_user_config_t config;
    FLEXIO_SPI_DRV_SlaveGetDefaultConfig(&config);

    config.driverType = DRIVER_TYPE;
    config.bitOrder = BIT_ORDER;
    config.transferSize = TRANSFER_SIZE;
    config.clockPolarity = CLOCK_POLARITY;
    config.clockPhase = CLOCK_PHASE;
    config.mosiPin = MOSI_PIN;
    config.misoPin = MISO_PIN;
    config.sckPin = SCK_PIN;
    config.ssPin = SS_PIN;

    config.callback = phDriverSpi_InternalCallback;

    status_t status = FLEXIO_SPI_DRV_SlaveInit(SPI_INSTANCE, &config, &g_slaveState);
    return (status == STATUS_SUCCESS) ? EER_OK : STATUS_ERROR;
}

PhTypes_ErrorCode_t phDriverSpi_SlaveDeInit(void)
{
    status_t status = FLEXIO_SPI_DRV_SlaveDeinit(&g_slaveState);
    return (status == STATUS_SUCCESS) ? EER_OK : STATUS_ERROR;
}

PhTypes_ErrorCode_t phDriverSpi_SlaveTransfer(const uint8_t *txData,
                                               uint8_t *rxData,
                                               uint32_t dataSize)
{
    status_t status = FLEXIO_SPI_DRV_SlaveTransfer(&g_slaveState, txData, rxData, dataSize);
    return (status == STATUS_SUCCESS) ? EER_OK : STATUS_ERROR;
}

PhTypes_ErrorCode_t phDriverSpi_SlaveTransferAbort(void)
{
    status_t status = FLEXIO_SPI_DRV_SlaveTransferAbort(&g_slaveState);
    return (status == STATUS_SUCCESS) ? EER_OK : STATUS_ERROR;
}
