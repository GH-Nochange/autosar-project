#include "phQueue.h"
#include <stdlib.h>
#include <string.h>
#include "phApp_DataTypes.h"

typedef struct
{
    phApp_DataTypes_t buffer[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
} Queue;

static Queue com_tx_queue;
static Queue com_rx_queue;

PhTypes_ErrorCode_t Queue_Init(void)
{
    com_tx_queue.head = 0;
    com_tx_queue.tail = 0;
    com_tx_queue.size = 0;

    com_rx_queue.head = 0;
    com_rx_queue.tail = 0;
    com_rx_queue.size = 0;

    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueTX_Push(const phApp_DataTypes_t *data, uint16_t length)
{
    if (!data)
        return PH_ERR_INVALID_ARG;
    if (QueueTX_IsFull())
        return PH_ERR_NO_RESOURCE;

    memcpy(&com_tx_queue.buffer[com_tx_queue.tail], data, length);

    com_tx_queue.tail = (com_tx_queue.tail + 1) % QUEUE_CAPACITY;
    com_tx_queue.size++;
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueRX_Push(const phApp_DataTypes_t *data, uint16_t Length)
{
    if (!data)
        return PH_ERR_INVALID_ARG;
    if (QueueRX_IsFull())
        return PH_ERR_NO_RESOURCE;

    memcpy(&com_rx_queue.buffer[com_rx_queue.tail], data, Length);

    com_rx_queue.tail = (com_rx_queue.tail + 1) % QUEUE_CAPACITY;
    com_rx_queue.size++;
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueTX_Pop(phApp_DataTypes_t *out_data)
{
    if (QueueTX_IsEmpty())
        return PH_ERR_NO_RESOURCE;

    *out_data = com_tx_queue.buffer[com_tx_queue.head];

    com_tx_queue.head = (com_tx_queue.head + 1) % QUEUE_CAPACITY;
    com_tx_queue.size--;
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueRX_Pop(phApp_DataTypes_t *out_data)
{
    if (QueueRX_IsEmpty())
        return PH_ERR_NO_RESOURCE;

    *out_data = com_rx_queue.buffer[com_rx_queue.head];

    com_rx_queue.head = (com_rx_queue.head + 1) % QUEUE_CAPACITY;
    com_rx_queue.size--;
    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueTX_Front(phApp_DataTypes_t *out_data)
{
    if (QueueTX_IsEmpty())
        return PH_ERR_NO_RESOURCE;

    *out_data = com_tx_queue.buffer[com_tx_queue.head];

    return PH_ERR_OK;
}

PhTypes_ErrorCode_t QueueRX_Front(phApp_DataTypes_t *out_data)
{
    if (QueueRX_IsEmpty())
        return PH_ERR_NO_RESOURCE;

    *out_data = com_rx_queue.buffer[com_rx_queue.head];

    return PH_ERR_OK;
}

bool QueueTX_IsEmpty(void)
{
    return com_tx_queue.size == 0;
}
bool QueueRX_IsEmpty(void)
{
    return com_rx_queue.size == 0;
}
bool QueueTX_IsFull(void)
{
    return com_tx_queue.size == QUEUE_CAPACITY;
}

bool QueueRX_IsFull(void)
{
    return com_rx_queue.size == QUEUE_CAPACITY;
}

size_t QueueTX_Size(void)
{
    return com_tx_queue.size;
}

size_t QueueRX_Size(void)
{
    return com_rx_queue.size;
}