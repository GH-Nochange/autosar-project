#ifndef PH_SPI_H
#define PH_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phTypes.h"
#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                             SPI Configuration                              */
/* -------------------------------------------------------------------------- */

/** Bits per word (frame size). */
#define SPI_TRANSFER_SIZE 8

/** Bit order: 0 = MSB first, 1 = LSB first. */
#define SPI_BIT_ORDER 0

/** Clock polarity: 0 = idle low, 1 = idle high. */
#define SPI_CLOCK_POLARITY 0

/** Clock phase: 0 = sample on first edge, 1 = sample on second edge. */
#define SPI_CLOCK_PHASE 0

/** MOSI pin assignment (PTB15). */
#define SPI_MOSI_PIN 3

/** MISO pin assignment (PTB16). */
#define SPI_MISO_PIN 4

/** SCK pin assignment (PTB14). */
#define SPI_SCK_PIN 2

/** Slave select pin assignment (PTB17 -> PCS3). */
#define SPI_SS_PIN 5

/** Hardware SPI instance used (LPSPI1). */
#define SPI_INSTANCE 0

    typedef void (*phSpi_Callback_t)(void *userData);

    /* -------------------------------------------------------------------------- */
    /*                             SPI Slave API                                  */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Initialize SPI in slave mode.
     *
     * Configures the SPI peripheral as a slave with predefined settings
     * (transfer size, polarity, phase, pins).
     */
    void phSpi_SlaveInit(phSpi_Callback_t *cb);

    /**
     * @brief Deinitialize SPI slave.
     *
     * Disables the SPI peripheral and frees associated resources.
     */
    void phSpi_SlaveDeinit(void);

    /**
     * @brief Start an SPI slave transfer.
     *
     * Exchanges data between master and slave.
     *
     * @param tx Pointer to transmit buffer (can be NULL if only receiving).
     * @param rx Pointer to receive buffer (can be NULL if only transmitting).
     * @param len Number of bytes to transfer.
     * @return Error code (PH_ERR_OK on success).
     */
    PhTypes_ErrorCode_t phSpi_SlaveTransfer(uint8_t *tx, uint8_t *rx, uint32_t len);

    /**
     * @brief Get remaining bytes of the current transfer.
     *
     * Useful for polling or checking if transfer has completed.
     *
     * @param bytesRemaining Pointer to store number of bytes not yet transferred.
     * @return Error code.
     */
    PhTypes_ErrorCode_t phSpi_SlaveGetStatus(uint32_t *bytesRemaining);

    /**
     * @brief Signal that SPI slave is ready.
     *
     * Typically sets a flag or prepares the device to receive the next frame.
     */
    void phSpi_SlaveSetReady(void);

    PhTypes_ErrorCode_t phSpi_SlaveAbort(void);

    bool phSpi_SlaveIsCsHigh(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_SPI_H */
