#include "phSpiDrv.h"
#include "flexio_spi_driver.h"
#include "phTypes.h"
#include <string.h>

static flexio_spi_master_state_t s_mst[FLEXIO_INSTANCE_COUNT];
static bool s_mstInited[FLEXIO_INSTANCE_COUNT];

static flexio_spi_slave_state_t  s_slv[FLEXIO_INSTANCE_COUNT];
static bool s_slvInited[FLEXIO_INSTANCE_COUNT];

static PhTypes_ErrorCode_t map_status(status_t st) {
    switch (st) {
        case STATUS_SUCCESS:     return PH_ERR_OK;
        case STATUS_BUSY:        return PH_ERR_BUSY;
        case STATUS_TIMEOUT:     return PH_ERR_TIMEOUT;
        case STATUS_UNSUPPORTED: return PH_ERR_UNSUPPORTED;
        default:                 return PH_ERR_FAILED;
    }
}

static void to_flexio_master_cfg(const phSpiDrv_MasterConfig_t *in, flexio_spi_master_user_config_t *out) {
    memset(out, 0, sizeof(*out));
    out->baudRate     = in->baudRate;             
    out->driverType   = in->driverType;
    out->bitOrder     = (flexio_spi_transfer_bit_order_t)in->bitOrder;
    out->transferSize = (flexio_spi_transfer_size_t)in->transferSize;
    out->clockPolarity= in->clockPolarity;
    out->clockPhase   = in->clockPhase;
    out->mosiPin      = in->mosiPin;
    out->misoPin      = in->misoPin;
    out->sckPin       = in->sckPin;
    out->ssPin        = in->ssPin;
    out->callback     = in->callback;
    out->callbackParam= in->callbackParam;
    out->rxDMAChannel = in->rxDMAChannel;
    out->txDMAChannel = in->txDMAChannel;
}
static void to_flexio_slave_cfg(const phSpiDrv_SlaveConfig_t *in, flexio_spi_slave_user_config_t *out) {
    memset(out, 0, sizeof(*out));
    out->driverType   = in->driverType;
    out->bitOrder     = (flexio_spi_transfer_bit_order_t)in->bitOrder;
    out->transferSize = (flexio_spi_transfer_size_t)in->transferSize;
    out->clockPolarity= in->clockPolarity;
    out->clockPhase   = in->clockPhase;
    out->mosiPin      = in->mosiPin;
    out->misoPin      = in->misoPin;
    out->sckPin       = in->sckPin;
    out->ssPin        = in->ssPin;
    out->callback     = in->callback;
    out->callbackParam= in->callbackParam;
    out->rxDMAChannel = in->rxDMAChannel;
    out->txDMAChannel = in->txDMAChannel;
}

PhTypes_ErrorCode_t phSpiDrv_MasterInit(uint32_t instance, const phSpiDrv_MasterConfig_t *cfg) {
    if (!cfg || instance >= FLEXIO_INSTANCE_COUNT) return PH_ERR_INVALID_ARG;
    if (s_mstInited[instance]) return PH_ERR_ALREADY_INIT;
    flexio_spi_master_user_config_t c; to_flexio_master_cfg(cfg, &c);
    status_t st = FLEXIO_SPI_DRV_MasterInit(instance, &c, &s_mst[instance]);
    s_mstInited[instance] = (st == STATUS_SUCCESS);
    return map_status(st);
}
PhTypes_ErrorCode_t phSpiDrv_MasterDeinit(uint32_t instance) {
    if (instance >= FLEXIO_INSTANCE_COUNT) return PH_ERR_INVALID_ARG;
    if (!s_mstInited[instance]) return PH_ERR_INVALID_STATE;
    status_t st = FLEXIO_SPI_DRV_MasterDeinit(&s_mst[instance]);
    s_mstInited[instance] = false;
    return map_status(st);
}
PhTypes_ErrorCode_t phSpiDrv_MasterTransfer(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_mstInited[instance] || (!tx && !rx) || (len == 0u)) return PH_ERR_INVALID_ARG;
    return map_status(FLEXIO_SPI_DRV_MasterTransfer(&s_mst[instance], tx, rx, len));
}
PhTypes_ErrorCode_t phSpiDrv_MasterTransferBlocking(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len, uint32_t timeoutMs) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_mstInited[instance] || (!tx && !rx) || (len == 0u)) return PH_ERR_INVALID_ARG;
    return map_status(FLEXIO_SPI_DRV_MasterTransferBlocking(&s_mst[instance], tx, rx, len, timeoutMs));
}
PhTypes_ErrorCode_t phSpiDrv_MasterTransferAbort(uint32_t instance) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_mstInited[instance]) return PH_ERR_INVALID_STATE;
    return map_status(FLEXIO_SPI_DRV_MasterTransferAbort(&s_mst[instance]));
}
PhTypes_ErrorCode_t phSpiDrv_MasterGetStatus(uint32_t instance, uint32_t *bytesRemaining) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_mstInited[instance] || !bytesRemaining) return PH_ERR_INVALID_STATE;
    return map_status(FLEXIO_SPI_DRV_MasterGetStatus(&s_mst[instance], bytesRemaining));
}

PhTypes_ErrorCode_t phSpiDrv_SlaveInit(uint32_t instance, const phSpiDrv_SlaveConfig_t *cfg) {
    if (!cfg || instance >= FLEXIO_INSTANCE_COUNT) return PH_ERR_INVALID_ARG;
    if (s_slvInited[instance]) return PH_ERR_ALREADY_INIT;
    flexio_spi_slave_user_config_t c; to_flexio_slave_cfg(cfg, &c);
    status_t st = FLEXIO_SPI_DRV_SlaveInit(instance, &c, &s_slv[instance]);
    s_slvInited[instance] = (st == STATUS_SUCCESS);
    return map_status(st);
}
PhTypes_ErrorCode_t phSpiDrv_SlaveDeinit(uint32_t instance) {
    if (instance >= FLEXIO_INSTANCE_COUNT) return PH_ERR_INVALID_ARG;
    if (!s_slvInited[instance]) return PH_ERR_INVALID_STATE;
    status_t st = FLEXIO_SPI_DRV_SlaveDeinit(&s_slv[instance]);
    s_slvInited[instance] = false;
    return map_status(st);
}
PhTypes_ErrorCode_t phSpiDrv_SlaveTransfer(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance] || (!tx && !rx) || (len == 0u)) return PH_ERR_INVALID_ARG;
    return map_status(FLEXIO_SPI_DRV_SlaveTransfer(&s_slv[instance], tx, rx, len));
}
PhTypes_ErrorCode_t phSpiDrv_SlaveTransferBlocking(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len, uint32_t timeoutMs) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance] || (!tx && !rx) || (len == 0u)) return PH_ERR_INVALID_ARG;
    return map_status(FLEXIO_SPI_DRV_SlaveTransferBlocking(&s_slv[instance], tx, rx, len, timeoutMs));
}
PhTypes_ErrorCode_t phSpiDrv_SlaveTransferAbort(uint32_t instance) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance]) return PH_ERR_INVALID_ARG;
    return map_status(FLEXIO_SPI_DRV_SlaveTransferAbort(&s_slv[instance]));
}
PhTypes_ErrorCode_t phSpiDrv_SlaveGetStatus(uint32_t instance, uint32_t *bytesRemaining) {
    if (instance >= FLEXIO_INSTANCE_COUNT || !s_slvInited[instance] || !bytesRemaining) return PH_ERR_INVALID_STATE;
    return map_status(FLEXIO_SPI_DRV_SlaveGetStatus(&s_slv[instance], bytesRemaining));
}
