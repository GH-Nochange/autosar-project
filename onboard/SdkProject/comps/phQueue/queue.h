#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "ph_Types.h"

typedef struct Queue Queue;

PhTypes_ErrorCode_t Queue_Init(Queue* q);
PhTypes_ErrorCode_t Queue_Push(Queue* q, const uint8_t* data, uint16_t len);
PhTypes_ErrorCode_t Queue_Pop(Queue* q, Frame* out_frame);
PhTypes_ErrorCode_t Queue_Front(const Queue* q, Frame* out_frame);

bool Queue_IsEmpty(const Queue* q);
bool Queue_IsFull(const Queue* q);
uint16_t Queue_Size(const Queue* q);

#endif // QUEUE_H
