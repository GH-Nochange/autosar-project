#ifndef CONTROL_H
#define CONTROL_H

#include <stdint.h>
`#include "PhTypes.h"

void Control_MainFunction(void);

void Control_SetLEDState(uint8_t state);  
uint8_t Control_GetLEDState(void);

PhTypes_ErrorCode_t TransmitSignal(uint16_t signalId, uint16_t value);

#endif
