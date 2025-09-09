#ifndef PH_PDUR_COM_H
#define PH_PDUR_COM_H
/**
 * @file phPduR_Com.h
 * @brief PduR <-> Com interface for transmit and cancel operations.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phComStack_Types.h"
#include "phTypes.h"

/**
 * @brief Request transmission of a PDU from Com to lower layers.
 * @param[in] PduInfoPtr Pointer to PDU data/length.
 * @return PH_ERR_OK if accepted, error code otherwise.
 */
PhTypes_ErrorCode_t phPduR_ComTransmit(const phPduInfoType *PduInfoPtr);

/**
 * @brief Cancel an ongoing transmission request.
 * @param[in] TxPduId Identifier of the PDU to cancel.
 * @return PH_ERR_OK if cancelled, error code otherwise.
 */
PhTypes_ErrorCode_t phPduR_CancelTransmit(phPduIdType TxPduId);

/**
 * @brief Cancel an ongoing reception request.
 * @param[in] RxPduId Identifier of the PDU to cancel.
 * @return PH_ERR_OK if cancelled, error code otherwise.
 */
PhTypes_ErrorCode_t phPduR_ComCancelReceive(phPduIdType RxPduId);

#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_COM_H */
