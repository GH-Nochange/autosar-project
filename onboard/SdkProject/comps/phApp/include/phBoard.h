#ifndef PH_BOARD_H_
#define PH_BOARD_H_

#include "phApp_DataTypes.h"
#include "phTypes.h"

#define PH_VERSION_LEN   3
#define PH_MAJOR_VERSION 0x01
#define PH_MINOR_VERSION 0x00
#define PH_PATCH_VERSION 0x01

PhTypes_ErrorCode_t phBoard_Recv(phApp_Data_t *data);

PhTypes_ErrorCode_t phBoard_Send(phApp_Data_t *data);
void phBoard_Init(void);
void phBoard_MainFunction(void);

#endif