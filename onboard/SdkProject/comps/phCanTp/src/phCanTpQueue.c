#include "phCanTPQueue.h"
#include <stdlib.h>
#include <string.h>
#include "phApp_DataTypes.h"

typedef struct
{
    phCanTP_CF_t buffer[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
} Queue;

static Queue com_tx_queue;
static Queue com_rx_queue;

static inline uint16_t _payload_max_bytes(void)
{
    return (uint16_t)sizeof(((phCanTP_CF_t *)0)->Data);
}
static inline bool _valid_len(uint16_t len) { return len <= _payload_max_bytes(); }

PhTypes_ErrorCode_t Queue_Init(void)
{
    com_tx_queue.head = 0;
    com_tx_queue.tail = 0;
    com_tx_queue.size = 0;

    // com_rx_queue.head = 0;
    // com_rx_queue.tail = 0;
    // com_rx_queue.size = 0;

    return ERR_Ok;
}

PhTypes_ErrorCode_t QueueTX_Push(const phCanTP_CF_t *data)
{
    if (!data)
        return ERR_InvalidArg;
    if (!_valid_len(data->header.length))
        return ERR_InvalidArg;
    if (QueueTX_IsFull())
        return ERR_NoResource;

    memcpy(&com_tx_queue.buffer[com_tx_queue.tail], data, sizeof(phCanTP_CF_t));
    com_tx_queue.tail = (com_tx_queue.tail + 1) % QUEUE_CAPACITY;
    com_tx_queue.size++;
    return ERR_Ok;
}

// PhTypes_ErrorCode_t QueueRX_Push(const phCanTP_CF_t *data)
// {
//     if (!data)
//         return ERR_InvalidArg;
//     if (!_valid_len(data->header.length))
//         return ERR_InvalidArg;
//     if (QueueRX_IsFull())
//         return ERR_NoResource;

//     memcpy(&com_rx_queue.buffer[com_rx_queue.tail], data, sizeof(phCanTP_CF_t));
//     com_rx_queue.tail = (com_rx_queue.tail + 1) % QUEUE_CAPACITY;
//     com_rx_queue.size++;
//     return ERR_Ok;
// }

PhTypes_ErrorCode_t QueueTX_Pop(phCanTP_CF_t *out_data)
{
    if (QueueTX_IsEmpty())
        return ERR_NoResource;

    memcpy(out_data, &com_tx_queue.buffer[com_tx_queue.head], sizeof(phCanTP_CF_t));
    com_tx_queue.head = (com_tx_queue.head + 1) % QUEUE_CAPACITY;
    com_tx_queue.size--;
    return ERR_Ok;
}

// PhTypes_ErrorCode_t QueueRX_Pop(phCanTP_CF_t *out_data)
// {
//     if (QueueRX_IsEmpty())
//         return ERR_NoResource;

//     memcpy(out_data, &com_rx_queue.buffer[com_rx_queue.head], sizeof(phCanTP_CF_t));
//     com_rx_queue.head = (com_rx_queue.head + 1) % QUEUE_CAPACITY;
//     com_rx_queue.size--;
//     return ERR_Ok;
// }

PhTypes_ErrorCode_t QueueTX_Front(phCanTP_CF_t *out_data)
{
    if (QueueTX_IsEmpty())
        return ERR_NoResource;

    memcpy(out_data, &com_tx_queue.buffer[com_tx_queue.head], sizeof(phCanTP_CF_t));
    return ERR_Ok;
}

// PhTypes_ErrorCode_t QueueRX_Front(phCanTP_CF_t *out_data)
// {
//     if (QueueRX_IsEmpty())
//         return ERR_NoResource;

//     memcpy(out_data, &com_rx_queue.buffer[com_rx_queue.head], sizeof(phCanTP_CF_t));
//     return ERR_Ok;
// }

bool QueueTX_IsEmpty(void)
{
    return com_tx_queue.size == 0;
}

bool QueueTX_IsFull(void)
{
    return com_tx_queue.size == QUEUE_CAPACITY;
}

// bool QueueRX_IsFull(void)
// {
//     return com_rx_queue.size == QUEUE_CAPACITY;
// }

size_t QueueTX_Size(void)
{
    return com_tx_queue.size;
}

// size_t QueueRX_Size(void)
// {
//     return com_rx_queue.size;
// }