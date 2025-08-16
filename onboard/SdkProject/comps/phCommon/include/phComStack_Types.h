#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "stdint.h"

typedef uint16_t     phPduIdType;

typedef uint16_t     phPduLengthType;

typedef enum
{
    PH_BUFREQ_OK = 0,
    PH_BUFREQ_E_NOT_OK = 1,
    PH_BUFREQ_E_BUSY = 2,
    PH_BUFREQ_E_OVFL = 3
} phBufReq_ReturnType;

typedef enum
{
    Ph_TP_DATACONF = 0,
    Ph_TP_DATARETRY = 1,
    Ph_TP_CONFPENDING = 2
} phTpDataStateType;

typedef enum
{
    PH_TP_STMIN = 0,
    PH_TP_BS = 1,
    PH_TP_BC = 2 // FlexRay
} phTPParameterType;

typedef enum
{
    PH_ICOM_SWITCH_E_OK = 0,
    PH_ICOM_SWITCH_E_FAILED = 1
} phIcomSwitch_ErrorType;

typedef uint8_t        phNotifResultType;
typedef uint8_t        phNetworkHandleType;
typedef uint8_t        phPNCHandleType;

typedef struct
{
    uint8_t * SduDataPtr;
    uint8_t * MetaDataPtr;
	phPduLengthType  SduLength;
} phPduInfoType;

typedef struct
{
    phTpDataStateType TpDataState;
    phPduLengthType  TxTpDataCnt;
} phRetryInfoType;

typedef uint8_t        phIcomConfigIdType;
typedef uint16_t       phCbkHandleIdType;

#ifdef __cplusplus
}
#endif

#endif /* COMSTACK_TYPES_H */
