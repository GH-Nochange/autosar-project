#ifndef PH_PDUR_CANTP_H
#define PH_PDUR_CANTP_H
/**
 * @file phPduR_CanTp.h
 * @brief PduR <-> CanTp interface (copy, start-of-reception, confirm, trigger).
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phComStack_Types.h"
#include "phPduR.h"
#include "phTypes.h"

/**
 * @brief Copy RX data chunk from CanTp into upper-layer buffer.
 * @param[in]  info            Source data pointer/length.
 * @param[out] bufferSizePtr   Remaining free bytes after copy.
 * @return BUFREQ_OK/BUFREQ_E_NOT_OK/BUFREQ_E_BUSY/BUFREQ_E_OVFL.
 */
phBufReq_ReturnType phPduR_CanTpCopyRxData(const phPduInfoType* info, phPduLengthType* bufferSizePtr);

/**
 * @brief Indicate end result of an RX transfer to upper layer.
 * @param[in] result PH_ERR_OK if complete; error otherwise.
 */
void phPduR_CanTpRxIndication(PhTypes_ErrorCode_t result);

/**
 * @brief Start-of-reception notification; allocates RX buffer.
 * @param[in]  info          First bytes / metadata.
 * @param[in]  TpSduLength   Total SDU length (if known).
 * @param[out] bufferSizePtr Initial available buffer size.
 * @return BUFREQ_OK/BUFREQ_E_NOT_OK/BUFREQ_E_BUSY/BUFREQ_E_OVFL.
 */
phBufReq_ReturnType phPduR_CanTpStartOfReception(const phPduInfoType* info,
                                                 phPduLengthType TpSduLength,
                                                 phPduLengthType* bufferSizePtr);

/**
 * @brief Provide TX data chunk to CanTp on demand.
 * @param[in]  info           Source buffer/length to copy out.
 * @param[in]  retry          Retry info (offset/mode) or NULL.
 * @param[out] bufferSizePtr  Remaining data still available to send.
 * @return BUFREQ_OK/BUFREQ_E_NOT_OK/BUFREQ_E_BUSY.
 */
phBufReq_ReturnType phPduR_CanTpCopyTxData(const phPduInfoType* info,
                                           const phRetryInfoType* retry,
                                           phPduLengthType* bufferSizePtr);

/**
 * @brief Confirm end result of a TX transfer to upper layer.
 * @param[in] result PH_ERR_OK if successful; error otherwise.
 */
void phPduR_CanTpTxConfirmation(PhTypes_ErrorCode_t result);

/**
 * @brief Trigger immediate read-out of a TX PDU (pull model).
 * @param[out] PduInfoPtr Destination buffer/length filled by upper layer.
 * @return PH_ERR_OK on success; error code otherwise.
 */
PhTypes_ErrorCode_t phPduR_CanTpTriggerTransmit(const phPduInfoType* PduInfoPtr);

#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_CANTP_H */
