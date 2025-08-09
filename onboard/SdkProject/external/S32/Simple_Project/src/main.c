// main.c — Test phGpio driver: RGB 7 colors + BUTTON interrupt to cycle color (NVIC handled in driver)
#include "device_registers.h"
#include "pins_driver.h"
#include "phGpio.h"
#include <stdint.h>
#include <stdbool.h>

#define __NOP() __asm("nop")

static void board_clock_ports_enable(void)
{
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;
}

int main(void)
{
    board_clock_ports_enable();
    phGpioHwAb_Init();

    while (1) { __NOP(); }
}
