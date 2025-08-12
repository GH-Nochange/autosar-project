/*
 * test.c
 *
 *  Created on: Aug 12, 2025
 *      Author: nguye
 */


#include "device_registers.h"
#include "flexcan_driver.h"
#include "phClock.h"
#include "osif.h"
#include "phCan.h"
#include "test.h"

static inline void led_set(uint32_t pin, bool on)
{
    if (on)  { PTD->PCOR = (1u << pin); }
    else     { PTD->PSOR = (1u << pin); }
}

void TEST_PORT_init(void)
{
    PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK;
    PORTE->PCR[4] |= PORT_PCR_MUX(5);
    PORTE->PCR[5] |= PORT_PCR_MUX(5);

    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;

    PORTD->PCR[16] = 0x00000100;
    PTD->PDDR |= (1u << 16);

    PORTD->PCR[15] = 0x00000100;
    PTD->PDDR |= (1u << 15);

    PORTD->PCR[0] = 0x00000100;
    PTD->PDDR |= (1u << 0);
}

void TEST_run(void)
{
    WDOG_disable();
    SOSC_init_8MHz();
    SPLL_init_160MHz();
    NormalRUNmode_80MHz();

    TEST_PORT_init();

    PhTypes_ErrorCode_t err = Can_Init();
    if (err != PH_ERR_OK)
    {
        led_set(16u, false);
        led_set(0u, false);
        for (;;);
    }
#if defined(CAN)
    uint8_t data[8] = {0xAA, 0x44, 0x55, 0x66, 0x77, 0xFF, 0xBB, 0x99};
    (void)Can_Transmit(data, 8);
#endif
    for (;;)
    {
        __asm("nop");
    }
}

#if defined(CAN)
void Can_TxConfirmation(void)
{
}

void Can_RxIndication(const flexcan_msgbuff_t *frame)
{
    if (frame == NULL) return;

    const uint8_t dlc = frame->dataLen;
    const uint8_t b0  = (dlc > 0u) ? frame->data[0] : 0u;
    const uint8_t b1  = (dlc > 1u) ? frame->data[1] : 0u;
    const uint8_t b2  = (dlc > 2u) ? frame->data[2] : 0u;

    led_set(16u, (b0 != 0u));
    led_set(15u, (b1 != 0u));
    led_set(0u,  (b2 != 0u));

    uint8_t out[8];
    uint8_t n = (dlc > 8u) ? 8u : dlc;
    for (uint8_t i = 0; i < n; i++)
        out[i] = frame->data[n - 1u - i];

    (void)Can_Transmit(out, n);
}
#endif
