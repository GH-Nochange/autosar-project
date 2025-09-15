#include "phLed.h"
#include "Dio.h"

void phSetLed(uint8_t value)
{
    Dio_PortLevelType portLevel = 0;

    value &= 0x07;

    if (value & 0x01) portLevel |= (1UL << 0);   // PTD0
    if (value & 0x02) portLevel |= (1UL << 15);  // PTD15
    if (value & 0x04) portLevel |= (1UL << 16);  // PTD16

    Dio_WritePort(DioConf_DioPort_DioPort_0, portLevel);
}
uint8_t phGetLed(void)
{
    uint8_t value = 0;
    Dio_PortLevelType portLevel;

    portLevel = Dio_ReadPort(DioConf_DioPort_DioPort_0);

    if (portLevel & (1UL << 0))  value |= 0x01;   // PTD0 → bit0
    if (portLevel & (1UL << 15)) value |= 0x02;   // PTD15 → bit1
    if (portLevel & (1UL << 16)) value |= 0x04;   // PTD16 → bit2

    return value;
}

