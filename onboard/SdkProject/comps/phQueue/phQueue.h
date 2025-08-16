#ifndef PH_QUEUE_H
#define PH_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "phTypes.h"           
#include "phApp_DataTypes.h"   

#define QUEUE_CAPACITY 20

/**
 * @brief Khởi tạo 2 queue tĩnh: TX và RX.
 * @return ERR_Ok nếu thành công.
 */
PhTypes_ErrorCode_t Queue_Init(void);

/* ===================== TX QUEUE API ===================== */

/**
 * @brief Đẩy 1 frame vào hàng đợi TX.
 * @note  Trả ERR_InvalidArg nếu NULL/length không hợp lệ.
 *        Trả ERR_NoResource nếu queue đầy.
 */
PhTypes_ErrorCode_t QueueTX_Push(const phApp_DataTypes_t *data, uint16_t Length);

/**
 * @brief Lấy và xóa phần tử đầu hàng đợi TX.
 * @note  Trả ERR_NoResource nếu rỗng.
 */
PhTypes_ErrorCode_t QueueTX_Pop(phApp_DataTypes_t *out_data);

/**
 * @brief Xem phần tử đầu hàng đợi TX (không xóa).
 * @note  Trả ERR_NoResource nếu rỗng.
 */
PhTypes_ErrorCode_t QueueTX_Front(phApp_DataTypes_t *out_data);

/** @return true nếu TX rỗng. */
bool   QueueTX_IsEmpty(void);

/** @return true nếu TX đầy. */
bool   QueueTX_IsFull(void);
/** @return số phần tử hiện có trong TX. */
size_t QueueTX_Size(void);

/* ===================== RX QUEUE API ===================== */

/**
 * @brief Đẩy 1 frame vào hàng đợi RX.
 * @note  Trả ERR_InvalidArg nếu NULL/length không hợp lệ.
 *        Trả ERR_NoResource nếu queue đầy.
 */
PhTypes_ErrorCode_t QueueRX_Push(const phApp_DataTypes_t *data, uint16_t Length);

/**
 * @brief Lấy và xóa phần tử đầu hàng đợi RX.
 * @note  Trả ERR_NoResource nếu rỗng.
 */
PhTypes_ErrorCode_t QueueRX_Pop(phApp_DataTypes_t *out_data);

/**
 * @brief Xem phần tử đầu hàng đợi RX (không xóa).
 * @note  Trả ERR_NoResource nếu rỗng.
 */
PhTypes_ErrorCode_t QueueRX_Front(phApp_DataTypes_t *out_data);

/** @return true nếu RX rỗng. */
bool   QueueRX_IsEmpty(void);
/** @return true nếu RX đầy. */
bool   QueueRX_IsFull(void);
/** @return số phần tử hiện có trong RX. */
size_t QueueRX_Size(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_QUEUE_H */
