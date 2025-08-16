#include "phSpi.h"
#include "phSpiDrv.h"  
#include <string.h>
#include <stdio.h>
#include "flexio_spi_driver.h"
#include "flexio.h"

static flexio_spi_slave_state_t s_slv[FLEXIO_INSTANCE_COUNT];
static bool s_slvInited[FLEXIO_INSTANCE_COUNT];

static void to_flexio_slave_cfg(flexio_spi_slave_user_config_t *out) {
    memset(out, 0, sizeof(*out));

    out->driverType   = FLEXIO_DRIVER_TYPE_INTERRUPTS;
    out->bitOrder     = (flexio_spi_transfer_bit_order_t)SPI0_BIT_ORDER;
    out->transferSize = (flexio_spi_transfer_size_t)SPI0_TRANSFER_SIZE;
    out->clockPolarity= SPI0_CLOCK_POLARITY;
    out->clockPhase   = SPI0_CLOCK_PHASE;
    out->mosiPin      = SPI0_MOSI_PIN;
    out->misoPin      = SPI0_MISO_PIN;
    out->sckPin       = SPI0_SCK_PIN;
    out->ssPin        = SPI0_SS_PIN;
    out->callback     = NULL;
    out->callbackParam= NULL;
}

void phSpi_SlaveInit(void) {
    uint32_t instance = SPI0_INSTANCE;
    if (instance >= FLEXIO_INSTANCE_COUNT) return;

    if (s_slvInited[instance]) return;

    flexio_spi_slave_user_config_t c;
    to_flexio_slave_cfg(&c);

    PhTypes_ErrorCode_t status = phSpiDrv_SlaveInit(instance, &c);
    if (status == PH_ERR_OK) {
        s_slvInited[instance] = true;
    }
}

void phSpi_SlaveDeinit(void) {
    uint32_t instance = SPI0_INSTANCE;
    if (instance >= FLEXIO_INSTANCE_COUNT) return;

    if (!s_slvInited[instance]) return;

    PhTypes_ErrorCode_t status = phSpiDrv_SlaveDeinit(instance);
    s_slvInited[instance] = false;
}

PhTypes_ErrorCode_t phSpi_SlaveTransferNonBlocking(uint8_t *tx, uint8_t *rx, uint32_t len) {
    uint32_t instance = SPI0_INSTANCE;
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance] || (!tx && !rx) || (len == 0u)) {
        return PH_ERR_INVALID_ARG;
    }

    PhTypes_ErrorCode_t status = phSpiDrv_SlaveTransferNonBlocking(instance, tx, rx, len);
    return (status == PH_ERR_OK) ? PH_ERR_OK : PH_ERR_FAILED;
}

PhTypes_ErrorCode_t phSpi_SlaveGetStatus(uint32_t *bytesRemaining) {
    uint32_t instance = SPI0_INSTANCE;
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance] || !bytesRemaining) {
        return PH_ERR_INVALID_STATE;
    }

    uint32_t remaining;
    PhTypes_ErrorCode_t status = phSpiDrv_SlaveGetStatus(instance, &remaining);
    *bytesRemaining = remaining;
    return (status == PH_ERR_OK) ? PH_ERR_OK : PH_ERR_FAILED;
}

void phSpi_SlaveCallback(void *driverState, spi_event_t event, void *userData) {
    
}