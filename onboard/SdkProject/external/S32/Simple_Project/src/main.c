#include "phBoard.h"
#include "device_registers.h"

void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm("NOP");
    }
}

int main(void)
{
//    TEST_run();

//	spi_test();
	PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;

	phBoard_Init();
	while (1)
	{
		phBoard_MainFunction();
		delay(10000);
	}

    return 0;
}


