#ifndef PH_SPI_H
#define PH_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "phTypes.h"
#include <stdint.h>

#define SPI0_BAUD_RATE        1000000   
#define SPI0_TRANSFER_SIZE    8         
#define SPI0_BIT_ORDER        0         
#define SPI0_CLOCK_POLARITY   0         
#define SPI0_CLOCK_PHASE      0         
#define SPI0_MOSI_PIN         15        
#define SPI0_MISO_PIN         16        
#define SPI0_SCK_PIN          14        
#define SPI0_SS_PIN           13        

#define SPI0_INSTANCE         0        

void phSpi_SlaveInit(void);
void phSpi_SlaveDeinit(void);
PhTypes_ErrorCode_t phSpi_SlaveTransferNonBlocking(uint8_t *tx, uint8_t *rx, uint32_t len);
PhTypes_ErrorCode_t phSpi_SlaveGetStatus(uint32_t *bytesRemaining);

#ifdef __cplusplus
}
#endif

#endif /* PH_SPI_H */
