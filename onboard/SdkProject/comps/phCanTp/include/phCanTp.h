#ifndef PHCANTP_H
#define PHCANTP_H

#include <stdint.h>
#include "phApp_DataTypes.h"
#include "phPduR.h"

typedef struct {
    uint8_t FT:4;
    uint8_t SFDL:4;
    uint8_t Data[7];
} phCanTP_SF_t;

typedef struct {
    uint16_t FT:4;
    uint16_t MFDL:12;
    uint8_t Data[6];
} phCanTP_FF_t;

typedef struct {
    uint8_t FT:4;
    uint8_t SN:4;
    uint8_t Data[7];
} phCanTP_CF_t;

typedef struct {
    uint8_t FT:4;
    uint8_t Flag:4; //0:Clear to Send, 1: Wait, 2: Overflow
    uint8_t BlockSize;
    uint8_t STMin;
} phCanTP_FC_t;

typedef enum {
    SF = 0b0000,
    FF = 0b0001,
    CF = 0b0010,
    FC = 0b0011
} Frame_t;

typedef enum {
    SF_State,
    FF_State,
    CF_State,
    WaitFC_State,
    Idle_State
} phCanTP_State_t;



void phCanTP_Init(void);

void phCanTP_TX(phPduR_Pdu_t *pduData);

void CanTpMainFunction(void);

void phCanTP_RX_Processing(uint8_t *data);

#endif /* PHCANTP_H */