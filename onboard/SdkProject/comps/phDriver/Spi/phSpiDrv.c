#include "lpspi_slave_driver.h"
#include "phSpiDrv.h"
#include "device_registers.h"
#include "phTypes.h"


static lpspi_state_t s_lpspiState[LPSPI_INSTANCE_COUNT];
static bool          s_inited[LPSPI_INSTANCE_COUNT] = { false };

static inline PhTypes_ErrorCode_t map_status(status_t st)
{
    switch (st) {
        case STATUS_SUCCESS:   return PH_ERR_OK;
        case STATUS_BUSY:      return PH_ERR_BUSY;
        case STATUS_TIMEOUT:   return PH_ERR_TIMEOUT;
        case STATUS_UNSUPPORTED: return PH_ERR_UNSUPPORTED;
        default:               return PH_ERR_UNKNOWN;
    }
}


PhTypes_ErrorCode_t phSpiDrvSlave_Init(uint32_t instance, const lpspi_slave_config_t *cfg)
{
    if ((instance >= LPSPI_INSTANCE_COUNT) || (cfg == NULL)) return PH_ERR_INVALID_ARG;
    if (s_inited[instance]) return PH_ERR_ALREADY_INIT;

    status_t st = LPSPI_DRV_SlaveInit(instance, &s_lpspiState[instance], cfg);
    s_inited[instance] = (st == STATUS_SUCCESS);
    return map_status(st);
}

PhTypes_ErrorCode_t phSpiDrvSlave_Deinit(uint32_t instance)
{
    if (instance >= LPSPI_INSTANCE_COUNT) return PH_ERR_INVALID_ARG;
    if (!s_inited[instance]) return PH_ERR_NOT_INIT;

    status_t st = LPSPI_DRV_SlaveDeinit(instance);
    s_inited[instance] = false;
    return map_status(st);
}

PhTypes_ErrorCode_t phSpiDrvSlave_Transfer(uint32_t instance,
                                         const uint8_t *tx,
                        uint8_t *rx,
                        uint16_t len)
{
    if ((instance >= LPSPI_INSTANCE_COUNT) || !s_inited[instance] || (len == 0u))
        return PH_ERR_INVALID_ARG;

    status_t st = LPSPI_DRV_SlaveTransfer(instance, tx, rx, len);
    return map_status(st);
}

PhTypes_ErrorCode_t phSpiDrvSlave_TransferBlocking(uint32_t instance,
                                const uint8_t *tx,
                                uint8_t *rx,
                                uint16_t len,
                                uint32_t timeout_ms)
{
    if ((instance >= LPSPI_INSTANCE_COUNT) || !s_inited[instance] || (len == 0u))
        return PH_ERR_INVALID_ARG;

    status_t st = LPSPI_DRV_SlaveTransferBlocking(instance, tx, rx, len, timeout_ms);
    return map_status(st);
}

PhTypes_ErrorCode_t phSpiDrvSlave_Abort(uint32_t instance)
{
    if ((instance >= LPSPI_INSTANCE_COUNT) || !s_inited[instance])
        return PH_ERR_INVALID_ARG;

    status_t st = LPSPI_DRV_SlaveAbortTransfer(instance);
    return map_status(st);
}

PhTypes_ErrorCode_t LpspiSlave_GetStatus(uint32_t instance, uint32_t *bytesRemained)
{
    if ((instance >= LPSPI_INSTANCE_COUNT) || !s_inited[instance] || (bytesRemained == NULL))
        return PH_ERR_INVALID_ARG;

    status_t st = LPSPI_DRV_SlaveGetTransferStatus(instance, bytesRemained);
    return map_status(st);
}
