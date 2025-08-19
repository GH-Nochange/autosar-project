#ifndef PH_SPI_DRV_H
#define PH_SPI_DRV_H

/**
 * @file phSpiDrv.h
 * @brief Wrapper APIs for NXP LPSPI slave driver on S32K1xx.
 *
 * Provides a simplified interface for initializing, deinitializing,
 * and transferring data using the LPSPI slave peripheral, based on
 * the NXP SDK `lpspi_slave_driver.h`.
 */

#include <stdint.h>
#include <stdbool.h>
#include "lpspi_slave_driver.h"
#include "phTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize an LPSPI instance in slave mode.
 *
 * @param instance LPSPI instance index (0..LPSPI_INSTANCE_COUNT-1).
 * @param cfg      Pointer to a valid slave configuration structure.
 * @return PH_ERR_OK on success, or an error code on failure.
 *
 * @retval PH_ERR_INVALID_ARG If parameters are invalid.
 * @retval PH_ERR_ALREADY_INIT If the instance is already initialized.
 */
PhTypes_ErrorCode_t phSpiDrvSlave_Init(uint32_t instance,
                                    const lpspi_slave_config_t *cfg);

/**
 * @brief Deinitialize a previously initialized LPSPI slave instance.
 *
 * @param instance LPSPI instance index.
 * @return PH_ERR_OK on success, or an error code on failure.
 *
 * @retval PH_ERR_INVALID_ARG If instance index is invalid.
 * @retval PH_ERR_NOT_INIT If the instance is not initialized.
 */
PhTypes_ErrorCode_t phSpiDrvSlave_Deinit(uint32_t instance);

/**
 * @brief Start a non-blocking transfer on the LPSPI bus.
 *
 * @param instance LPSPI instance index.
 * @param tx       Pointer to transmit buffer (NULL to skip TX).
 * @param rx       Pointer to receive buffer (NULL to skip RX).
 * @param len      Number of bytes to transfer (must be > 0).
 * @return PH_ERR_OK if transfer was started successfully, otherwise error code.
 */
PhTypes_ErrorCode_t phSpiDrvSlave_Transfer(uint32_t instance,
                                        const uint8_t *tx,
                                        uint8_t *rx,
                                        uint16_t len);

/**
 * @brief Perform a blocking transfer on the LPSPI bus.
 *
 * @param instance    LPSPI instance index.
 * @param tx          Pointer to transmit buffer (NULL to skip TX).
 * @param rx          Pointer to receive buffer (NULL to skip RX).
 * @param len         Number of bytes to transfer (must be > 0).
 * @param timeout_ms  Timeout in milliseconds.
 * @return PH_ERR_OK if transfer completed successfully, otherwise error code.
 */
PhTypes_ErrorCode_t phSpiDrvSlave_TransferBlocking(uint32_t instance,
                                                const uint8_t *tx,
                                                uint8_t *rx,
                                                uint16_t len,
                                                uint32_t timeout_ms);

/**
 * @brief Abort an ongoing non-blocking transfer.
 *
 * @param instance LPSPI instance index.
 * @return PH_ERR_OK on success, otherwise error code.
 */
PhTypes_ErrorCode_t phSpiDrvSlave_Abort(uint32_t instance);

/**
 * @brief Get status of an ongoing non-blocking transfer.
 *
 * @param instance       LPSPI instance index.
 * @param bytesRemained  Pointer to store remaining bytes count.
 * @return PH_ERR_OK if status was retrieved successfully, otherwise error code.
 */
PhTypes_ErrorCode_t LpspiSlave_GetStatus(uint32_t instance,
                                         uint32_t *bytesRemained);

#ifdef __cplusplus
}
#endif

#endif /* PH_SPI_DRV_H */
