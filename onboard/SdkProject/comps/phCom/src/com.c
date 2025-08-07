#include "com.h"
#include "ph_Types.h"
#include "queue.h"
#include <stdbool.h>
#include <string.h> 

static Queue *tx_queue;
static Queue *rx_queue;

PhTypes_ErrorCode_t COM_Init(void)
{
    if (Queue_Init(tx_queue) != EER_OK || Queue_Init(rx_queue) != EER_OK)
    {
        return EER_NoResource;
    }
    return EER_OK;
}


PhTypes_ErrorCode_t COM_Send(ID_SIGNAL_t id, const uint8_t *signal, uint8_t length)
{
    if (signal == NULL || length > I_PDU_MAX_PAYLOAD_SIZE)
    {
        return EER_InvalidArg; // Tham số không hợp lệ
    }

    I_PDU_t pdu;
    pdu.id = id;
    pdu.length = length;
    memcpy(pdu.payload, signal, length);

    if (Queue_Push(tx_queue, (const uint8_t *)&pdu, sizeof(I_PDU_t)) != EER_OK)
    {
        return EER_NoResource; // Không đủ tài nguyên để gửi
    }

    return EER_OK;
}

bool getQueueSend(Frame *pdu_out)
{
    if (Queue_Pop(tx_queue, pdu_out) != EER_OK) {
        return false; // Không có dữ liệu để lấy
    }
    
    return true;
}

bool getQueueRecv(I_PDU_t *pdu_out)
{
    Frame frame;
    if (Queue_Pop(rx_queue, &frame) != EER_OK) {
        return false; // Không có dữ liệu để lấy
    }

    memcpy(pdu_out, &frame.data, frame.len);
    return true;
}

PhTypes_ErrorCode_t COM_Receive(uint16_t length, uint8_t *data)
{
    if (data == NULL) {
        return EER_InvalidArg; // Tham số không hợp lệ
    }

    Frame frame;
    frame.len = length;
    memcpy(frame.data, data, length);

    if (Queue_Push(rx_queue, (const uint8_t *)&frame, sizeof(Frame)) != EER_OK) {
        return EER_NoResource;
    }

    return EER_OK;
}








