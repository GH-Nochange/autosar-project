#ifndef PH_CANIF_H
#define PH_CANIF_H
/**
 * @file phCanIf.h
 * @brief CAN Interface (CanIf) public API and types.
 *
 * Provides transmit/receive primitives between upper layers and CAN driver.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phComStack_Types.h"
#include "phTypes.h"

/**
 * @enum CanIf_FrameType
 * @brief CAN/CAN-FD frame formats and ID types.
 */
typedef enum
{
    CANIF_EXTENDED_CAN = 0U,  /**< Classic CAN, 29-bit ID */
    CANIF_EXTENDED_FD_CAN,    /**< CAN FD,     29-bit ID */
    CANIF_STANDARD_CAN,       /**< Classic CAN, 11-bit ID */
    CANIF_STANDARD_FD_CAN     /**< CAN FD,      11-bit ID */
} CanIf_FrameType;

/**
 * @brief Transmit a PDU via CAN.
 * @param[in] PduInfoPtr Pointer to payload/length and optional metadata.
 * @return PH_ERR_OK if accepted; error code otherwise.
 */
PhTypes_ErrorCode_t phCanIf_Transmit(const phPduInfoType* PduInfoPtr);

/**
 * @brief Read the latest received PDU data.
 * @param[out] CanIfRxInfoPtr Buffer to fill with payload/length.
 * @return PH_ERR_OK on success; PH_ERR_NoResource if none available.
 */
PhTypes_ErrorCode_t phCanIf_ReadRxPduData(phPduInfoType* CanIfRxInfoPtr);

/**
 * @brief Pull-model transmit: request upper layer to provide TX data now.
 * @param[out] PduInfoPtr Filled with data to send.
 * @return PH_ERR_OK if data provided; error code otherwise.
 */
PhTypes_ErrorCode_t phCanIf_TriggerTransmit(phPduInfoType* PduInfoPtr);

/**
 * @brief Notify upper layer that a CAN PDU was transmitted.
 * @note No parameters; implementation may use internal context/queues.
 */
void phCanIf_TxConfirmation(void);

/**
 * @brief Indicate a received CAN PDU to upper layer.
 * @param[in] PduInfoPtr Received payload/length and metadata.
 */
void phCanIf_RxIndication(const phPduInfoType* PduInfoPtr);

#ifdef __cplusplus
}
#endif

#endif /* PH_CANIF_H */
