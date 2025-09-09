#ifndef PH_DMA_H
#define PH_DMA_H

#include "phClock.h"
#include "edma_driver.h"

#define EDMA_CHN0_NUMBER   0U
#define EDMA_CHN1_NUMBER   1U
#define EDMA_CHN2_NUMBER   2U
#define EDMA_CHN3_NUMBER   3U

#define EDMA_CONFIGURED_CHANNELS_COUNT   4U

void phDma_Init(void);

#endif  // PH_DMA_H
