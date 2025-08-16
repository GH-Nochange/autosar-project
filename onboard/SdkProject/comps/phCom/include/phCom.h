#ifndef PH_COM_H
#define PH_COM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "phComStack_Types.h"
#include "phTypes.h"
#include "phApp_DataTypes.h"


// Communication Services
PhTypes_ErrorCode_t phCom_Send(const phApp_DataTypes_t *Data);

// Callback Function
void phCom_TpRxIndication(PhTypes_ErrorCode_t result);
void phCom_TpTxConfirmation(PhTypes_ErrorCode_t result);
phBufReq_ReturnType phCom_StartOfReception(const phPduInfoType* info, phPduLengthType TpSduLenth, phPduLengthType * bufferSizePtr);
phBufReq_ReturnType phCom_CopyRxData(const phPduInfoType* info, phPduLengthType* bufferSizePtr);


// Scheduled Functions
void phCom_MainFunctionTx(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_COM_H */
