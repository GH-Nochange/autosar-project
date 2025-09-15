#ifndef PH_CANTP_H
#define PH_CANTP_H
/**
 * @file phCanTp.h
 * @brief Public API for CAN Transport Protocol (ISO-TP).
 *
 * Provides frame type definitions, state machine enums,
 * flow control status, and main TP APIs:
 * - phCanTp_Transmit()
 * - phCanTp_MainFunction()
 * - phCanTp_RxIndication()
 * - phCanTp_TxConfirmation()
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phComStack_Types.h"
#include "ComStack_Types.h"
#include "phTypes.h"

/**
 * @enum phFrameType
 * @brief Protocol Control Information (PCI) frame types.
 */
typedef enum
{
    PCI_TYPE_SF = 0b0000, /**< Single Frame: full payload in one frame */
    PCI_TYPE_FF = 0b0001, /**< First Frame: start of multi-frame transfer */
    PCI_TYPE_CF = 0b0010, /**< Consecutive Frame: subsequent segment */
    PCI_TYPE_FC = 0b0011  /**< Flow Control: receiver response */
} phFrameType;

/**
 * @enum phCanTpState
 * @brief Internal state machine for CAN TP channel.
 */
typedef enum
{
    PH_IDLE,    /**< Idle, no active transfer */
    PH_SF,      /**< Single Frame processing */
    PH_FF,      /**< First Frame in progress */
    PH_CF,      /**< Consecutive Frame in progress */
    PH_WAIT_FC  /**< Waiting for Flow Control */
} phCanTpState;

/**
 * @enum phCanTp_FcFsType
 * @brief Flow Status (FS) values in Flow Control frame.
 */
typedef enum {
    FC_FS_CTS   = 0x0u, /**< Clear To Send: continue sending */
    FC_FS_WT    = 0x1u, /**< Wait: temporary backpressure */
    FC_FS_OVFLW = 0x2u  /**< Overflow: receiver buffer full */
} phCanTp_FcFsType;

/**
 * @brief Request transmission of a PDU via CAN TP.
 *
 * Uses Single Frame if payload fits, otherwise starts
 * a multi-frame transfer (FF + CF).
 *
 * @param[in] PduInfoPtr Pointer to PDU descriptor.
 * @return PH_ERR_OK on success, error code otherwise.
 */
PhTypes_ErrorCode_t phCanTp_Transmit(const phPduInfoType *PduInfoPtr);

/**
 * @brief Periodic scheduler for CAN TP.
 *
 * Must be called at fixed interval (per CanTpMainFunctionPeriod).
 * Handles timeouts (N_As/N_Bs/N_Cs/N_Ar/N_Br/N_Cr), STmin,
 * and state machine progression.
 */
void phCanTp_MainFunction(void);

/**
 * @brief Notify TP about a received CAN frame.
 *
 * Called by lower CAN interface on frame reception.
 *
 * @param[in] PduInfoPtr Pointer to received CAN PDU.
 */
void phCanTp_RxIndication(PduIdType RxPduId, const PduInfoType * PduInfoPtr);

/**
 * @brief Confirm the result of a transmitted CAN frame.
 *
 * Called by lower CAN interface after transmission.
 *
 * @param[in] result PH_ERR_OK if success, error otherwise.
 */
void phCanTp_TxConfirmation(PduIdType CanIfTxPduId, Std_ReturnType result);

#ifdef __cplusplus
}
#endif

#endif /* PH_CANTP_H */
