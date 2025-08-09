#ifndef PHCONTROL_H
#define PHCONTROL_H

#include <stdint.h>
#include "phTypes.h"

void Control_MainFunction(void);

PhTypes_ErrorCode_t TransmitSignal(phApp_DataTypes_t data);

#endif
