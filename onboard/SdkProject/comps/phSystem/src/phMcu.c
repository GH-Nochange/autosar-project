#include "phMcu.h"       
#include "phTypes.h"
#include "phClock.h"
#include "phDma.h"

#include "device_registers.h"      


#ifndef __DSB
#define __DSB() __asm volatile ("dsb 0xF" ::: "memory")
#endif
#ifndef __NOP
#define __NOP() __asm volatile ("nop")
#endif


static phMcu_ResetReason_t phMcu_MapResetReason(void)
{
    uint8_t srs = RCM->SRS;

    if (srs & RCM_SRS_POR_MASK)   return PH_POWER_ON_RS;
    if (srs & RCM_SRS_PIN_MASK)   return PH_EXTERNAL_RS;
    if (srs & RCM_SRS_WDOG_MASK)  return PH_WTDG_RS;
    if (srs & RCM_SRS_SW_MASK)    return PH_SW_RS;

    return PH_UNKNOWN_RS;
}

static phMcu_ResetReason_t s_resetReason = PH_UNKNOWN_RS;

PhTypes_ErrorCode_t phMcu_Init(void)
{
    // s_resetReason = phMcu_MapResetReason();
    phClockInit();
    phDma_Init();
    
    return PH_ERR_OK; 
}

void phMcu_PerformReset(void)
{
    uint32_t aircr = S32_SCB->AIRCR;
    S32_SCB->AIRCR = (0x5FAUL << 16)         /* VECTKEY */
                   | (aircr & (7UL << 8))    /* giữ PRIGROUP */
                   | (1UL << 2);             /* SYSRESETREQ */
    __DSB();
    for(;;){ __NOP(); }
}

phMcu_ResetReason_t Mcu_GetResetReason(void)
{
    return s_resetReason;
}
