#include "queue.h"
#include <stdlib.h>
#include <string.h>

#define FRAME_MAX_SIZE 256
#define QUEUE_CAPACITY 20
Queue sQueueCom = {0};
typedef struct
{
    uint16_t len;
    uint8_t data[FRAME_MAX_SIZE + 3];
} Frame;

struct Queue
{
    Frame buffer[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
};

PhTypes_ErrorCode_t Queue_Init(Queue *q)
{
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return EER_OK;
}

PhTypes_ErrorCode_t QueueCom_Push(Queue *q, const uint8_t *data, uint16_t len)
{
    Queue_Push()
    sQueueCom
    if (!q || !data || len > FRAME_MAX_SIZE)
        return EER_InvalidArg;
    if (Queue_IsFull(q))
        return EER_NoResource;

    memcpy(q->buffer[q->tail].data, data, len);
    q->buffer[q->tail].len = len;
    q->tail = (q->tail + 1) % QUEUE_CAPACITY;
    q->size++;
    return EER_OK;
}

PhTypes_ErrorCode_t Queue_Pop(Queue *q, Frame *out_frame)
{
    if (!q || !out_frame)
        return EER_InvalidArg;
    if (Queue_IsEmpty(q))
        return EER_NoResource;

    memcpy(out_frame->data, q->buffer[q->head].data, q->buffer[q->head].len);
    out_frame->len = q->buffer[q->head].len;

    q->head = (q->head + 1) % QUEUE_CAPACITY;
    q->size--;
    return EER_OK;
}

PhTypes_ErrorCode_t Queue_Front(const Queue *q, Frame *out_frame)
{
    if (!q || !out_frame)
        return EER_InvalidArg;
    if (Queue_IsEmpty(q))
        return EER_NoResource;

    memcpy(out_frame->data, q->buffer[q->head].data, q->buffer[q->head].len);
    out_frame->len = q->buffer[q->head].len;
    return EER_OK;
}

bool Queue_IsEmpty(const Queue *q)
{
    return q->size == 0;
}

bool Queue_IsFull(const Queue *q)
{
    return q->size == QUEUE_CAPACITY;
}

size_t Queue_Size(const Queue *q)
{
    return q->size;
}