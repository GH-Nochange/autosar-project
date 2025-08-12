#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>
#include "driver/spi_master.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SPI_HOST_USED      SPI2_HOST  // Có thể là SPI2_HOST hoặc SPI3_HOST
#define SPI_CLK_PIN        14
#define SPI_MOSI_PIN       13
#define SPI_MISO_PIN       12
#define SPI_CS_PIN         15
#define SPI_QUEUE_SIZE     3

typedef void (*spi_handler_t)(uint8_t *data, uint16_t len);  // callback

void spi_init(void);
void spi_set_callback(spi_handler_t cb);
void spi_put(uint8_t *data, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif // __SPI_H__
