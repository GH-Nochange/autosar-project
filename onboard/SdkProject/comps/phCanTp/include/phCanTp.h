#ifndef PH_CANTP_H
#define PH_CANTP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phComStack_Types.h"
#include "phTypes.h"

typedef enum
{
    PCI_TYPE_SF = 0b0000,
    PCI_TYPE_FF = 0b0001,
    PCI_TYPE_CF = 0b0010,
    PCI_TYPE_FC = 0b0011
} phFrameType;

typedef enum
{
    PH_IDLE,
    PH_SF,
    PH_FF,
    PH_CF,
    PH_WAIT_FC
} phCanTpState;

typedef enum {
    FC_FS_CTS   = 0x0u,  // cho phép gửi CF
    FC_FS_WT    = 0x1u,  // chờ (Wait)
    FC_FS_OVFLW = 0x2u   // overflow/bộ đệm không đủ
} phCanTp_FcFsType;

PhTypes_ErrorCode_t phCanTp_Transmit(const phPduInfoType* PduInfoPtr);

void phCanTp_MainFunction(void);

void phCanTp_RxIndication(const phPduInfoType* PduInfoPtr);
void phCanTp_TxConfirmation(PhTypes_ErrorCode_t result);


#ifdef __cplusplus
}
#endif

#endif /* PH_CANTP_H */