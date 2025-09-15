/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ENET
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530
*
*   Copyright 2020-2025 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef ENET_IP_PBCFG_C
#define ENET_IP_PBCFG_C

/**
*   @file
*
*   @addtogroup ENET_DRIVER_CONFIGURATION ENET Driver Configuration
*   @{
*/
 
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Enet_Ip_Types.h"
#include "Enet_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              3
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Types.h */
#if (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID_C != ENET_IP_TYPES_VENDOR_ID)
    #error "Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h have different vendor ids"
#endif
#if ((ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h are different"
#endif
#if ((ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != ENET_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h are different"
#endif

/* Checks against Enet_Ip_Cfg.h */
#if (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID_C != ENET_IP_CFG_VENDOR_ID)
    #error "Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h have different vendor ids"
#endif
#if ((ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != ENET_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h are different"
#endif
#if ((ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != ENET_IP_CFG_SW_MAJOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != ENET_IP_CFG_SW_MINOR_VERSION) || \
     (ENET_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != ENET_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!MACRO "GetPhysicalAddress"!][!//
[!NOCODE!]
    [!VAR "PhysAddr" = "'00:00:00:00:00:00'"!]
    [!IF "node:exists(EthCtrlPhyAddress)"!]
        [!VAR "PhysAddr" = "node:value(EthCtrlPhyAddress)"!]
    [!ENDIF!]

    [!FOR "AddrByteIdx" = "1" TO "6"!]
        [!CODE!][!"concat('0x', text:split($PhysAddr, ':')[num:i($AddrByteIdx)])"!]U[!IF "$AddrByteIdx < 6"!], [!ENDIF!][!ENDCODE!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMacLayerType"!][!//
[!NOCODE!]
    [!VAR "MacLayer" = "string(null)"!]

    [!IF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XMII'"!]
        [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
            [!VAR "MacLayer" = "'MII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'SERIAL'"!]
            [!VAR "MacLayer" = "'SMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
            [!VAR "MacLayer" = "'RMII'"!]
        [!ENDIF!]
    [!ELSEIF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XGMII'"!]
        [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
            [!VAR "MacLayer" = "'GMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'SERIAL'"!]
            [!VAR "MacLayer" = "'SGMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
            [!VAR "MacLayer" = "'RGMII'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacLayer = string(null)"!][!ERROR!]Unknown or unsupported media independent interface! ([!"EthCtrlMacLayerType"!], [!"EthCtrlMacLayerSubType"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacLayer"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetRxConfigMask"!][!//
[!NOCODE!]
    [!VAR "RxCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigReceptionOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "RxCfgMask" = "concat($RxCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$RxCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetInterruptConfigMask"!][!//
[!NOCODE!]
    [!VAR "IntCfgMask" = "'0U'"!]

    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableErrorInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_BABR_INTERRUPT | (uint32)ENET_BABT_INTERRUPT | (uint32)ENET_UNDERRUN_INTERRUPT')"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_EBERR_INTERRUPT | (uint32)ENET_LATE_COLLISION_INTERRUPT | (uint32)ENET_RETRY_LIMIT_INTERRUPT')"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_PAYLOAD_RX_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableWakeUpInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_WAKEUP_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableTimerInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_TS_TIMER_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlEnableTxInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_TX_FRAME_INTERRUPT | (uint32)ENET_TX_BUFFER_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlEnableRxInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_RX_FRAME_INTERRUPT | (uint32)ENET_RX_BUFFER_INTERRUPT')"!]
    [!ENDIF!]
    [!CODE!][!"$IntCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetRxAccelerConfig"!][!//
[!NOCODE!]
    [!VAR "RxAccelerCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigRxAcceleratorOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "RxAccelerCfgMask" = "concat($RxAccelerCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$RxAccelerCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetTxAccelerConfig"!][!//
[!NOCODE!]
    [!VAR "TxAccelerCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigTxAcceleratorOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "TxAccelerCfgMask" = "concat($TxAccelerCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$TxAccelerCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetTxConfigMask"!][!//
[!NOCODE!]
    [!VAR "TxCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigTransmissionOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "TxCfgMask" = "concat($TxCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$TxCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "GetDataBuffer", "Enable", "CtrlIdx", "RingCount", "Type"!][!//
[!NOCODE!]
    [!IF "$Enable"!]
        [!IF "$Type='Tx'"!]
[!CODE!]ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingCount)"!]_DataBuffer[!ENDCODE!]
        [!ELSEIF "$Type='Rx'"!]
[!CODE!]ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingCount)"!]_DataBuffer[!ENDCODE!]
    [!ENDIF!]
    [!ELSE!]
[!CODE!]NULL_PTR[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCallbackEventInterrupt"!][!//
[!NOCODE!]
    [!VAR "EventInt" = "false()"!]
    [!VAR "CallbackEvent" = "'NULL_PTR'"!]

    [!IF "((node:value(EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableErrorInterrupt) = 'true') or (node:value(EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableWakeUpInterrupt) = 'true'))"!]
        [!VAR "EventInt" = "true()"!]
    [!ENDIF!]

    [!IF "$EventInt"!]
        [!VAR "CallbackEvent" = "'&Eth_43_ENET_Ipw_EventIrqCallback'"!]
    [!ELSE!]
        [!VAR "CallbackEvent" = "'NULL_PTR'"!]
    [!ENDIF!]

    [!CODE!][!"$CallbackEvent"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCallbackTimerInterrupt"!][!//
[!NOCODE!]
    [!VAR "TimerInt" = "false()"!]
    [!VAR "CallbackTimer" = "'NULL_PTR'"!]

    [!IF "((node:value(EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableTimerInterrupt) = 'true') and (node:value(../../../EthGeneral/EthGlobalTimeSupport) = 'true'))"!]
        [!VAR "TimerInt" = "true()"!]
    [!ENDIF!]

    [!IF "$TimerInt"!]
        [!VAR "CallbackTimer" = "'&Eth_43_ENET_Ipw_TimeStampCallback'"!]
    [!ELSE!]
        [!VAR "CallbackTimer" = "'NULL_PTR'"!]
    [!ENDIF!]

    [!CODE!][!"$CallbackTimer"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ENET_ADDR_LENGTH        (6U)

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CODE
#include "Eth_43_ENET_MemMap.h"

/*! @brief Channel callbacks external declarations */
[!NOCODE!]
[!IF "EthConfigSet/EthCtrlConfig/*/EthCtrlEnableRxInterrupt"!]
    [!VAR "CallbackName" = "node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*/EthCtrlConfigIngressFifoCallback)"!]
    [!IF "$CallbackName != 'NULL_PTR'"!]
        [!IF "$CallbackName = 'Eth_RxIrqCallback'"!]
            [!CODE!]extern void Eth_43_ENET_RxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!CODE!]extern void [!"$CallbackName"!](const uint8 CtrlIdx, const uint8 DMAChannel);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

[!IF "EthConfigSet/EthCtrlConfig/*/EthCtrlEnableTxInterrupt"!]
    [!VAR "CallbackName" = "node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoCallback)"!]
    [!IF "$CallbackName != 'NULL_PTR'"!]
        [!IF "$CallbackName = 'Eth_TxIrqCallback'"!]
            [!CODE!]extern void Eth_43_ENET_TxIrqCallback(const uint8 CtrlIdx, const uint8 DMAChannel);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!CODE!]extern void [!"$CallbackName"!](const uint8 CtrlIdx, const uint8 DMAChannel);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

[!IF "((node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableErrorInterrupt) = 'true') or (node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableWakeUpInterrupt) = 'true'))"!]
    [!VAR "CallbackName" = "node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlConfigEventCallback)"!]
    [!IF "$CallbackName != 'NULL_PTR'"!]
        [!IF "$CallbackName = 'Eth_Ipw_EventIrqCallback'"!]
            [!CODE!]extern void Eth_43_ENET_Ipw_EventIrqCallback(const uint8 CtrlIdx, const Enet_Ip_EventType Event);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!CODE!]extern void [!"$CallbackName"!](const uint8 CtrlIdx, const Enet_Ip_EventType Event);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

[!IF "((node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableTimerInterrupt) = 'true') and (node:value(EthGeneral/EthGlobalTimeSupport) = 'true'))"!]
    [!VAR "CallbackName" = "node:value(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlConfigTimeStampCallback)"!]
    [!IF "$CallbackName != 'NULL_PTR'"!]
        [!IF "$CallbackName = 'Eth_Ipw_TimeStampCallback'"!]
            [!CODE!]extern void Eth_43_ENET_Ipw_TimeStampCallback(const uint8 CtrlIdx);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!CODE!]extern void [!"$CallbackName"!](const uint8 CtrlIdx);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]


#define ETH_43_ENET_STOP_SEC_CODE
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/
#define ETH_43_ENET_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_ENET_MemMap.h"

[!NOCODE!]
    [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
        [!VAR "AllocateTxBuffer" = "false()"!]
        [!VAR "AllocateRxBuffer" = "false()"!]
        [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]

            [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateTxDataBuffers"!]
                [!VAR "AllocateTxBuffer" = "true()"!]
            [!ENDIF!]
            [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateRxDataBuffers"!]
                [!VAR "AllocateRxBuffer" = "true()"!]
            [!ENDIF!]
        [!LOOP "node:order(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*, 'EthCtrlConfigIngressFifoIdx')"!]
            [!VAR "RingIdx" = "node:value(EthCtrlConfigIngressFifoIdx)"!]
[!CODE!]
extern Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DescBuffer[];
[!ENDCODE!]
            [!IF "$AllocateRxBuffer"!]
[!CODE!]
extern uint8 ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DataBuffer[];
[!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!][!// RingIdx

        [!LOOP "node:order(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*, 'EthCtrlConfigEgressFifoIdx')"!]
            [!VAR "RingIdx" = "node:value(EthCtrlConfigEgressFifoIdx)"!]
[!CODE!]
extern Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DescBuffer[];
[!ENDCODE!]
            [!IF "$AllocateRxBuffer"!]
[!CODE!]
extern uint8 ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DataBuffer[];
[!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!][!// RingIdx

    [!ENDLOOP!][!// CtrlIdx
[!ENDNOCODE!]

#define ETH_43_ENET_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/
#define ETH_43_ENET_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

[!NOCODE!]
    [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
        [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
[!CODE!]
extern Enet_Ip_StateType ENET_[!"num:i($CtrlIdx)"!]_StateStructure;
[!ENDCODE!]
    [!ENDLOOP!][!// CtrlIdx
[!ENDNOCODE!]

#define ETH_43_ENET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"


/*! @brief The MAC address(es) of the configured controller(s) */
[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
[!CODE!][!//
static const uint8 ENET_[!"num:i(EthCtrlIdx)"!]_au8MacAddrPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][ENET_ADDR_LENGTH] = { [!CALL "GetPhysicalAddress"!] };
[!ENDCODE!]
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
            [!VAR "AllocateRxBuffer" = "false()"!]
            [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
            [!VAR "NumOfRxFifos" = "count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)"!]
            [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateRxDataBuffers"!]
                [!VAR "AllocateRxBuffer" = "true()"!]
            [!ENDIF!]
            [!IF "$NumOfRxFifos > 0"!]
[!CODE!]
/*! @brief Reception ring configuration structures */
static const Enet_Ip_BufferConfigType ENET_[!"num:i($CtrlIdx)"!]_aRxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfRxFifos)"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstFifo" = "1"!]
    [!LOOP "node:order(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*, 'EthCtrlConfigIngressFifoIdx')"!]
[!CODE!][!//
    [!IF "num:i($FirstFifo)=0"!],[!ENDIF!][!VAR "FirstFifo"="0"!]
    /* The configuration structure for Rx Ring [!"num:i(EthCtrlConfigIngressFifoIdx)"!] */
    {
        /*.ringDesc = */ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i(EthCtrlConfigIngressFifoIdx)"!]_DescBuffer,
        /*.callback = */[!IF "../../../EthCtrlEnableRxInterrupt"!]&Eth_43_ENET_RxIrqCallback[!ELSE!]NULL_PTR[!ENDIF!],
        /*.buffer = */[!CALL "GetDataBuffer",
                            "Enable" = "$AllocateRxBuffer",
                            "CtrlIdx" = "$CtrlIdx",
                            "RingCount" = "node:value(EthCtrlConfigIngressFifoIdx)",
                            "Type" = "'Rx'"!],
        /*.interrupts = */(uint32)[!IF "../../../EthCtrlEnableRxInterrupt"!]ENET_RX_FRAME_INTERRUPT[!ELSE!]0U[!ENDIF!],
        /*.bufferLen = */[!"num:i(EthCtrlConfigIngressFifoBufLenByte)"!]U,
        /*.ringSize = */[!"num:i(EthCtrlConfigIngressFifoBufTotal)"!]U
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*
[!CODE!]
};
[!ENDCODE!]
            [!ENDIF!][!// $NumOfRxFifos > 0
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]


[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
            [!VAR "AllocateTxBuffer" = "false()"!]
            [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
            [!VAR "NumOfTxFifos" = "count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!]
            [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateTxDataBuffers"!]
                [!VAR "AllocateTxBuffer" = "true()"!]
            [!ENDIF!]
            [!IF "$NumOfTxFifos > 0"!]
[!CODE!]
/*! @brief Transmission ring configuration structures */
static const Enet_Ip_BufferConfigType ENET_[!"num:i($CtrlIdx)"!]_aTxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfTxFifos)"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstFifo" = "1"!]
    [!LOOP "node:order(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*, 'EthCtrlConfigEgressFifoIdx')"!]
[!CODE!][!//
    [!IF "num:i($FirstFifo)=0"!],[!ENDIF!][!VAR "FirstFifo"="0"!]
    /* The configuration structure for Tx Ring [!"num:i(EthCtrlConfigEgressFifoIdx)"!] */
    {
        /*.ringDesc = */ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i(EthCtrlConfigEgressFifoIdx)"!]_DescBuffer,
        /*.callback = */[!IF "../../../EthCtrlEnableTxInterrupt"!]&Eth_43_ENET_TxIrqCallback[!ELSE!]NULL_PTR[!ENDIF!],
        /*.buffer = */[!CALL "GetDataBuffer",
                            "Enable" = "$AllocateTxBuffer",
                            "CtrlIdx" = "$CtrlIdx",
                            "RingCount" = "node:value(EthCtrlConfigEgressFifoIdx)",
                            "Type" = "'Tx'"!],
        /*.interrupts = */(uint32)[!IF "../../../EthCtrlEnableTxInterrupt"!]ENET_TX_FRAME_INTERRUPT[!ELSE!]0U[!ENDIF!],
        /*.bufferLen = */[!"num:i(EthCtrlConfigEgressFifoBufLenByte)"!]U,
        /*.ringSize = */[!"num:i(EthCtrlConfigEgressFifoBufTotal)"!]U
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*
[!CODE!]
};
[!ENDCODE!]
            [!ENDIF!][!// $NumOfTxFifos > 0
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

/*! @brief Module configuration structure */
[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
[!CODE!]
static const Enet_Ip_ConfigType ENET_[!"num:i(EthCtrlIdx)"!]_InitConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!] =
{
    /*.rxRingCount = */[!"num:i(count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*))"!]U,
    /*.txRingCount = */[!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U,
    /*.callback = */[!CALL "GetCallbackTimerInterrupt"!],
    /*.interrupts = */[!CALL "GetInterruptConfigMask"!],
    /*.callback = */[!CALL "GetCallbackEventInterrupt"!],
    /*.maxFrameLen = */[!"num:i(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthMaxFrameLength)"!]U,
    /*.miiMode = */ENET_[!CALL "GetMacLayerType"!]_MODE,
    /*.speed = */ENET_MII_SPEED_[!"substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_')"!],
    /*.duplex = */ENET_MII_[!"substring-after(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthDuplexMode, 'ETH_')"!],
    /*.rxConfig = */[!CALL "GetRxConfigMask"!],
    /*.txConfig = */[!CALL "GetTxConfigMask"!],
    /*.rxAccelerConfig = */[!CALL "GetRxAccelerConfig"!],
    /*.txAccelerConfig = */[!CALL "GetTxAccelerConfig"!],
    /*.enableCtrl = */FALSE
};
[!ENDCODE!]
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

#define ETH_43_ENET_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "num:i(count(EthConfigSet/EthCtrlConfig/*))"!]
    [!IF "num:i($NumOfEthCtrls) > 0"!]
[!CODE!]
const Enet_CtrlConfigType Enet_aCtrlConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"$NumOfEthCtrls"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
        [!VAR "CtrlHwId"  = "num:i(EthCtrlIdx)"!]
[!CODE!][!//
    [!IF "num:i($FirstCtrl)=0"!],[!ENDIF!][!VAR "FirstCtrl"="0"!]
    /* The configuration structure for Enet_aCtrlConfig[[!"num:i(@index)"!]U] */
    {
        &ENET_[!"$CtrlHwId"!]_StateStructure,
        &ENET_[!"$CtrlHwId"!]_InitConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!],
        &ENET_[!"$CtrlHwId"!]_aRxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][0U],
        &ENET_[!"$CtrlHwId"!]_aTxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][0U],
        &ENET_[!"$CtrlHwId"!]_au8MacAddrPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][0U]
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!][!//
};
[!ENDCODE!]
    [!ENDIF!][!// num:i($NumOfEthCtrls) > 0
[!ENDNOCODE!]

#define ETH_43_ENET_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_PBCFG_C */
