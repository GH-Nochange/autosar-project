#ifndef PHPDUR_H
#define PHPDUR_H

#include "phComQueue.h"
#include <stdint.h>

typedef enum {
    PDU_CAN,
    PDU_SPI
} phPduR_Protocol_t;

typedef struct {
    uint16_t length;
    uint8_t data[4096];
} phPduR_Pdu_t;

void phPduR_Init(void);

void phPduR_SendPdu(phPduR_Pdu_t *pdu);
void phPduR_ReceivePdu(phPduR_Pdu_t *pdu);

#endif /* PHPDUR_H */