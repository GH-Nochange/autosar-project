#ifndef PH_BOARD_H_
#define PH_BOARD_H_

#include "phApp_DataTypes.h"
#include "phTypes.h"

PhTypes_ErrorCode_t phBoard_Recv(phApp_Data_t *data);

PhTypes_ErrorCode_t phBoard_Send(phApp_Data_t *data);

void phBoard_MainFunction(void);

#endif