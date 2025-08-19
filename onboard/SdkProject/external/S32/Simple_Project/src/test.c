/*
 * test.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nguye
 */


#include "device_registers.h"
#include "phClock.h"
#include "phCanIf.h"
#include "test.h"
#include "phCom.h"
#include "phControl.h"

void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm("NOP");
    }
}

static inline void led_set(uint32_t pin, bool on)
{
    if (on)  { PTD->PCOR = (1u << pin); }
    else     { PTD->PSOR = (1u << pin); }
}

void TEST_PORT_init(void)
{
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;

    PORTD->PCR[16] = 0x00000100;
    PTD->PDDR |= (1u << 16);
    PTD->PSOR |= (1 << 16);

    PORTD->PCR[15] = 0x00000100;
    PTD->PDDR |= (1u << 15);
    PTD->PSOR |= (1 << 15);

    PORTD->PCR[0] = 0x00000100;
    PTD->PDDR |= (1u << 0);
    PTD->PSOR |= (1 << 0);
}

void TEST_run(void)
{
	system_clock_init();

    TEST_PORT_init();

    PhTypes_ErrorCode_t err = phCan0_Init();
    if (err != PH_ERR_OK)
    {
        led_set(16u, false);
        led_set(0u, false);
        for (;;);
    }

    phControl_MainFunction();
#if defined(CAN)
    uint8_t data[8] = {0xAA, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xBB, 0x99};
    (void)phCan0_Transmit(data, 8);
#endif
    while (1)
    {
    	delay(1000000);
        phCom_MainFunctionTx();


    }
}

#if defined(CAN)
void Test_RxIndication(const phPduInfoType * PduInfoPtr)
{
    const uint8_t dlc = PduInfoPtr->SduLength;
    const uint8_t b0  = (dlc > 0u) ? PduInfoPtr->SduDataPtr[0] : 0u;
    const uint8_t b1  = (dlc > 1u) ? PduInfoPtr->SduDataPtr[1] : 0u;
    const uint8_t b2  = (dlc > 2u) ? PduInfoPtr->SduDataPtr[2] : 0u;

    led_set(16u, (b0 != 0u));
    led_set(15u, (b1 != 0u));
    led_set(0u,  (b2 != 0u));

    uint8_t out[8];
    uint8_t n = (dlc > 8u) ? 8u : dlc;
    for (uint8_t i = 0; i < n; i++)
        out[i] = PduInfoPtr->SduDataPtr[n - 1u - i];

    (void)phCan0_Transmit(out, n);
}
#endif
