#include "phLed.h"
#include "phGpio.h"

void phSetLed(uint8_t value)
{
    phGpio_LedSetColorIndex(value);
}
uint8_t phGetLed(void)
{
    return 0;
}