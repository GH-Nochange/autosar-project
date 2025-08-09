#ifndef SPIDRV_H
#define SPIDRV_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "ph_Types.h"
#include "flexio_spi_driver.h"

    typedef void (*phDriverSpi_Callback_t)(PhTypes_ErrorCode_t status, void *context);

    PhTypes_ErrorCode_t phDriverSpi_SlaveInit(void);
    PhTypes_ErrorCode_t phDriverSpi_SlaveDeInit(void);
    PhTypes_ErrorCode_t phDriverSpi_SlaveTransfer(const uint8_t *txData,
                                                   uint8_t *rxData,
                                                   uint32_t dataSize);
    PhTypes_ErrorCode_t phDriverSpi_SlaveTransferAbort(void);

    PhTypes_ErrorCode_t phDriverSpi_SlaveRegisterCallback(phDriverSpi_Callback_t cb, void *context);

#ifdef __cplusplus
}
#endif

#endif /* SPIDRV_H */