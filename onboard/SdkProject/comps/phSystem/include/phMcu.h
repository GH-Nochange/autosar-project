#ifndef PH_MCU_H
#define PH_MCU_H

#include "phTypes.h"

typedef enum
{
    PH_POWER_ON_RS,
    PH_EXTERNAL_RS,
    PH_WTDG_RS,
    PH_SW_RS,
    PH_UNKNOWN_RS
} phMcu_ResetReason_t;

PhTypes_ErrorCode_t phMcu_Init(void);

void phMcu_PerformReset(void);
phMcu_ResetReason_t Mcu_GetResetReason(void);


#endif // PH_MCU_H