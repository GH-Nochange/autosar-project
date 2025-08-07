#ifndef COPM_H
#define COPM_H

#include <stdint.h>
#include "ph_Types.h"


// Kích thước tối đa của payload (chưa tính header)
#define I_PDU_MAX_PAYLOAD_SIZE   256

// typedef struct {
//     uint16_t id;                          
//     uint16_t length;                      
//     uint8_t payload[I_PDU_MAX_PAYLOAD_SIZE]; 
// } I_PDU_t;

// typedef enum {
//     NOTIFY_CAN = 0x01,
//     NOTIFY_SPI = 0x02,
//     COMMAND_CAN = 0x03,
//     COMMAND_SPI = 0x04,
//     RESPONSE_CAN = 0x05,
//     RESPONSE_SPI = 0x06
// } ID_SIGNAL_t;

/**
 * @brief Khởi tạo mô-đun COM và các hàng đợi.
 * 
 * @return EER_OK nếu thành công, hoặc mã lỗi nếu có vấn đề.
 */
PhTypes_ErrorCode_t COM_Init(void);


/**
 * @brief Đóng gói và đẩy một tín hiệu vào hàng đợi truyền.
 * 
 * @param id        ID logic của tín hiệu
 * @param signal    Dữ liệu payload
 * @param length    Độ dài dữ liệu
 * @return PhTypes_ErrorCode_t 
 */
PhTypes_ErrorCode_t COM_Send(uint8_t * data, uint8_t length);

/**
 * @brief Lấy một gói tin đã được chuẩn bị từ hàng đợi truyền.
 * 
 * @param pdu_out Con trỏ tới Frame để nhận dữ liệu
 * @return true nếu có dữ liệu, false nếu hàng đợi trống
 */
bool getQueueSend(Frame *pdu_out);


/**
 * @brief Đẩy một gói tin nhận vào hàng đợi nhận.
 * 
 * @param length    Độ dài dữ liệu
 * @param data      Dữ liệu payload nhận được
 * @return PhTypes_ErrorCode_t 
 */
PhTypes_ErrorCode_t COM_Receive(uint16_t length, uint8_t *data);

/**
 * @brief Lấy một I-PDU từ hàng đợi nhận.
 * 
 * @param pdu_out   Con trỏ tới I_PDU để nhận dữ liệu
 * @return true nếu có dữ liệu, false nếu hàng đợi trống
 */
bool getQueueRecv(I_PDU_t *pdu_out);