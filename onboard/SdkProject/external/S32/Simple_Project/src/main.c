#include "phBoard.h"
#include "device_registers.h"
#include "phMcu.h"

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
    phMcu_Init();

	phBoard_Init();
	while (1)
	{
		phBoard_MainFunction();
		delay(10000);
	}

    return 0;
}


