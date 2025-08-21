#ifndef PH_QUEUE_H
#define PH_QUEUE_H
/**
 * @file phQueue.h
 * @brief Simple static TX/RX queue for application data frames.
 *
 * Provides push/pop/front operations with fixed capacity.
 * Returns error codes on invalid args, full or empty queues.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "phTypes.h"           
#include "phApp_DataTypes.h"   

#define QUEUE_CAPACITY 20  /**< Max number of frames per queue. */

/**
 * @brief Initialize both static TX and RX queues.
 * @return ERR_Ok if success.
 */
PhTypes_ErrorCode_t Queue_Init(void);

/* ===================== TX QUEUE API ===================== */

/**
 * @brief Push a frame into TX queue.
 * @param[in] data    Frame pointer.
 * @param[in] Length  Frame length.
 * @return ERR_Ok, ERR_InvalidArg, or ERR_NoResource if full.
 */
PhTypes_ErrorCode_t QueueTX_Push(const phApp_Data_t *data);

/**
 * @brief Pop the first frame from TX queue.
 * @param[out] out_data Destination buffer.
 * @return ERR_Ok or ERR_NoResource if empty.
 */
PhTypes_ErrorCode_t QueueTX_Pop(phApp_Data_t *out_data);

/**
 * @brief Peek at the first TX frame without removing it.
 * @param[out] out_data Destination buffer.
 * @return ERR_Ok or ERR_NoResource if empty.
 */
PhTypes_ErrorCode_t QueueTX_Front(phApp_Data_t *out_data);

/** @return true if TX queue is empty. */
bool   QueueTX_IsEmpty(void);
/** @return true if TX queue is full. */
bool   QueueTX_IsFull(void);
/** @return number of elements in TX queue. */
size_t QueueTX_Size(void);

/* ===================== RX QUEUE API ===================== */

/**
 * @brief Push a frame into RX queue.
 * @param[in] data    Frame pointer.
 * @param[in] Length  Frame length.
 * @return ERR_Ok, ERR_InvalidArg, or ERR_NoResource if full.
 */
PhTypes_ErrorCode_t QueueRX_Push(const phApp_Data_t *data);

/**
 * @brief Pop the first frame from RX queue.
 * @param[out] out_data Destination buffer.
 * @return ERR_Ok or ERR_NoResource if empty.
 */
PhTypes_ErrorCode_t QueueRX_Pop(phApp_Data_t *out_data);

/**
 * @brief Peek at the first RX frame without removing it.
 * @param[out] out_data Destination buffer.
 * @return ERR_Ok or ERR_NoResource if empty.
 */
PhTypes_ErrorCode_t QueueRX_Front(phApp_Data_t *out_data);

/** @return true if RX queue is empty. */
bool   QueueRX_IsEmpty(void);
/** @return true if RX queue is full. */
bool   QueueRX_IsFull(void);
/** @return number of elements in RX queue. */
size_t QueueRX_Size(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_QUEUE_H */
