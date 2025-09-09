#ifndef PH_COM_H
#define PH_COM_H
/**
 * @file phCom.h
 * @brief High-level Communication Services API.
 *
 * Provides application-level send function, callbacks for TP,
 * and scheduled main function for TX handling.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phComStack_Types.h"
#include "phTypes.h"
#include "phApp_DataTypes.h"

/* ================= Communication Services ================= */

/**
 * @brief Send application data through COM stack.
 * @param[in] Data Pointer to application data.
 * @return PH_ERR_OK if accepted; error code otherwise.
 */
PhTypes_ErrorCode_t phCom_Send(const phApp_Data_t *Data);

/**
 * @brief Recv application data through COM stack.
 * @param[in] Data Pointer to application data.
 * @return PH_ERR_OK if accepted; error code otherwise.
 */
PhTypes_ErrorCode_t phCom_Recv(const phApp_Data_t *Data);

/* ================= Callback Functions ================= */

/**
 * @brief Indicate result of a TP reception.
 * @param[in] result PH_ERR_OK if success; error otherwise.
 */
void phCom_TpRxIndication(PhTypes_ErrorCode_t result);

/**
 * @brief Confirm result of a TP transmission.
 * @param[in] result PH_ERR_OK if success; error otherwise.
 */
void phCom_TpTxConfirmation(PhTypes_ErrorCode_t result);

/**
 * @brief Start of reception callback (buffer allocation).
 * @param[in]  info         Initial PDU info.
 * @param[in]  TpSduLenth   Expected SDU length.
 * @param[out] bufferSizePtr Available buffer size.
 * @return BUFREQ_OK, BUFREQ_E_NOT_OK, or BUFREQ_E_BUSY.
 */
phBufReq_ReturnType phCom_StartOfReception(const phPduInfoType* info,
                                           phPduLengthType TpSduLenth,
                                           phPduLengthType * bufferSizePtr);

/**
 * @brief Copy received data chunk into COM buffer.
 * @param[in]  info           PDU data pointer/length.
 * @param[out] bufferSizePtr  Remaining free buffer space.
 * @return BUFREQ_OK, BUFREQ_E_NOT_OK, or BUFREQ_E_BUSY.
 */
phBufReq_ReturnType phCom_CopyRxData(const phPduInfoType* info,
                                     phPduLengthType* bufferSizePtr);

/* ================= Scheduled Functions ================= */

/**
 * @brief Periodic task for COM TX processing.
 */
void phCom_MainFunctionTx(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_COM_H */
