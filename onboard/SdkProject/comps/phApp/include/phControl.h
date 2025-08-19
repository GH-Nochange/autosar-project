#ifndef PHCONTROL_H
#define PHCONTROL_H

#include <stdint.h>
#include "phTypes.h"
#include "phApp_DataTypes.h"


void phControl_Init(void);
void phControl_MainFunction(void);

PhTypes_ErrorCode_t TransmitSignal(phApp_DataTypes_t data);

#endif
