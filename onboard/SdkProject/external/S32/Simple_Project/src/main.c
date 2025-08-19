#include "phControl.h"
#include "device_registers.h"

int main(void)
{
//    TEST_run();

//	spi_test();

	PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;
	    PORTD->PCR[16] = 0x00000100;
	    PTD->PDDR |= (1u << 16);
	    PTD->PSOR |= (1 << 16);

	    PORTD->PCR[15] = 0x00000100;
	    PTD->PDDR |= (1u << 15);
	    PTD->PSOR |= (1 << 15);

	    PORTD->PCR[0] = 0x00000100;
	    PTD->PDDR |= (1u << 0);
	    PTD->PSOR |= (1 << 0);
	phControl_Init();
	while (1)
	{
		phControl_MainFunction();
		delay(100000);
	}

    return 0;
}


