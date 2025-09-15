[!CODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef FTM_ICU_IP_DEFINES_H
#define FTM_ICU_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup ftm_icu_ip FTM IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"
[!NOCODE!][!// Include specific header file

[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85xx_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF86')"!][!//
        [!CODE!][!WS "0"!]#include "SAF86xx_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32N5')"!][!//
        [!CODE!][!WS "0"!]#include "S32N55_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32N7')"!][!//
        [!CODE!][!WS "0"!]#include "S32N79_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K5')"!][!//
        [!CODE!][!WS "0"!]#include "S32K566_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define FTM_ICU_IP_DEFINES_VENDOR_ID                       43
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define FTM_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define FTM_ICU_IP_DEFINES_SW_MAJOR_VERSION                3
#define FTM_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define FTM_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "CheckFtmSupport" = "0"!][!//
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "./IcuChannel/*"!][!//
        [!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuFtm')"!][!//
            [!VAR "CheckFtmSupport" = "$CheckFtmSupport + 1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!]

[!CODE!]#define FTM_ICU_IP_USED               [!IF "$CheckFtmSupport != 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!CR!][!ENDCODE!]

[!CODE!][!WS "0"!]#if (STD_ON == FTM_ICU_IP_USED)[!CR!][!ENDCODE!][!//

[!VAR "ovfIsrUsed" = "IcuAutosarExt/IcuOverflowNotificationApi"!][!//
[!SELECT "./IcuConfigSet"!][!//
    [!IF "count(IcuHwInterruptConfigList/*) > '0'"!][!//
        [!CODE!][!WS "0"!]/* Macros that indicate FTM instances used by ICU. */[!CR!][!ENDCODE!][!//
        [!FOR "ModuleIdx" = "0" TO "7"!][!//
            [!VAR "InstanceUsed" = "'false'"!][!//
            [!LOOP "IcuHwInterruptConfigList/*"!][!//
                [!IF "contains(IcuIsrHwId, concat('FTM_',$ModuleIdx))"!][!//
                    [!VAR "InstanceUsed" = "'true'"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "($InstanceUsed = 'true')"!][!//
                [!CODE!][!WS "0"!]#ifndef FTM_[!"$ModuleIdx"!]_USED[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]#define FTM_[!"$ModuleIdx"!]_USED[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "0"!]#else[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]#error "FTM_[!"$ModuleIdx"!] instance cannot be used by ICU. Instance locked by another driver!"[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!][!//
                [!CODE!][!CR!][!ENDCODE!][!//
            [!ENDIF!][!//
            
            [!IF "contains($DerivativeName, 'S32K14') or contains($DerivativeName, 'S32M24')"!][!//
                [!IF "($ovfIsrUsed = 'true') and ($InstanceUsed = 'true')"!][!//
                    [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!] OVF interrupt service enable/disable */[!CR!][!ENDCODE!][!//
                    [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_OVF_ISR_USED             (STD_ON)[!CR!][!ENDCODE!][!//
                    [!CODE!][!CR!][!ENDCODE!][!//
                [!ENDIF!][!//
                
                [!FOR "ChannelIdx" = "0" TO "3"!][!//
                    [!VAR "ChannelIsrUsed" = "'false'"!][!//
                    [!LOOP "IcuHwInterruptConfigList/*"!][!//
                        [!IF "contains(IcuIsrHwId, concat('FTM_',$ModuleIdx)) and (contains(IcuIsrHwId, concat('CH_',num:i($ChannelIdx)*2)) or contains(IcuIsrHwId, concat('CH_',num:i($ChannelIdx)*2 + 1)))"!][!//
                            [!VAR "ChannelIsrUsed" = "'true'"!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                    [!IF "($ChannelIsrUsed = 'true')"!][!//
                        [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
                        [!CODE!][!CR!][!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDFOR!][!//
            [!ELSEIF "contains($DerivativeName, 'S32N')"!][!//
                [!IF "($ModuleIdx > '3') and ($InstanceUsed = 'true')"!][!//
                    [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
                    [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_ISR_USED                 (STD_ON)[!CR!][!ENDCODE!][!//
                    [!CODE!][!CR!][!ENDCODE!][!//
                [!ELSE!][!//
                    [!IF "($ovfIsrUsed = 'true') and ($InstanceUsed = 'true')"!][!//
                        [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!] OVF interrupt service enable/disable */[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_OVF_ISR_USED             (STD_ON)[!CR!][!ENDCODE!][!//
                        [!CODE!][!CR!][!ENDCODE!][!//
                    [!ENDIF!][!//
                    [!FOR "ChannelIdx" = "0" TO "7"!][!//
                        [!VAR "ChannelIsrUsed" = "'false'"!][!//
                        [!LOOP "IcuHwInterruptConfigList/*"!][!//
                            [!IF "contains(IcuIsrHwId, concat('FTM_',$ModuleIdx)) and (contains(IcuIsrHwId, concat('CH_',$ChannelIdx)))"!][!//
                                [!VAR "ChannelIsrUsed" = "'true'"!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                        [!IF "($ChannelIsrUsed = 'true')"!][!//
                            [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!]_CH_[!"$ChannelIdx"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
                            [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_CH_[!"$ChannelIdx"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
                            [!CODE!][!CR!][!ENDCODE!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//

                [!ENDIF!][!//
            [!ELSE!][!//
                [!IF "($InstanceUsed = 'true')"!][!//
                    [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
                    [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_ISR_USED                 (STD_ON)[!CR!][!ENDCODE!][!//
                    [!CODE!][!CR!][!ENDCODE!][!//
                [!ENDIF!][!//  
                [!IF "contains($DerivativeName, 'S32K11')"!][!//
                    [!IF "($ovfIsrUsed = 'true') and ($InstanceUsed = 'true')"!][!//
                        [!CODE!][!WS "0"!]/** @brief FTM_[!"$ModuleIdx"!] OVF interrupt service enable/disable */[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "0"!]#define FTM_ICU_[!"$ModuleIdx"!]_OVF_ISR_USED             (STD_ON)[!CR!][!ENDCODE!][!//
                        [!CODE!][!CR!][!ENDCODE!][!// 
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDFOR!]
    [!ENDIF!]
[!ENDSELECT!][!//

[!ENDNOCODE!][!//
/** @brief Switches the Development Error Detection and Notification on or off.  */
#define FTM_ICU_IP_DEV_ERROR_DETECT        ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief The number of channels available on each FTM instance */
#define FTM_ICU_IP_NUM_OF_CHANNELS         ([!"ecu:get('Icu.Num_Ftm_Hw_Channels')"!]U)

/** @brief The number of channels with filter on each FTM instance */
#define FTM_FILTER_MAX_NO_CH               (4U)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define FTM_ICU_TIMESTAMP_API              ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define FTM_ICU_EDGE_DETECT_API            ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define FTM_ICU_SIGNAL_MEASUREMENT_API     ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the input level. */
#define FTM_ICU_GET_INPUT_LEVEL_API        ([!IF "IcuAutosarExt/IcuGetInputLevelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define FTM_ICU_DEINIT_API                 ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define FTM_ICU_SET_MODE_API               ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to edge count functionality. */
#define FTM_ICU_EDGE_COUNT_API             ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes the service Icu_GetTimeElapsed() from the code. */
#define FTM_ICU_GET_TIME_ELAPSED_API       ([!IF "IcuOptionalApis/IcuGetTimeElapsedApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes the service Icu_GetDutyCycleValues() from the code. */
#define FTM_ICU_GET_DUTY_CYCLE_VALUES_API  ([!IF "IcuOptionalApis/IcuGetDutyCycleValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define FTM_ICU_GET_INPUT_STATE_API        ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define FTM_ICU_DUAL_CLOCK_MODE_API        ([!IF "IcuAutosarExt/IcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to capture register functionality. */
#define FTM_ICU_CAPTURERGISTER_API         ([!IF "node:exists(IcuAutosarExt/IcuGetCaptureRegisterValueApi)"!][!IF "IcuAutosarExt/IcuGetCaptureRegisterValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or Removes the code related to overflow notification */
#define FTM_ICU_OVERFLOW_NOTIFICATION_API  ([!IF "IcuAutosarExt/IcuOverflowNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!VAR "TimestampDmaEnable" = "0"!][!/*
*/!][!VAR "MeasurementDmaEnable" = "0"!][!/*
*/!][!SELECT "IcuConfigSet"!][!/*
    */!][!LOOP "./IcuChannel/*"!][!/*
    */!][!IF "IcuDMAChannelEnable = 'true'"!][!/*
        */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
            */!][!VAR "TimestampDmaEnable" = "$TimestampDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
            */!][!VAR "MeasurementDmaEnable" = "$MeasurementDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
 */!][!ENDSELECT!]
/** @brief Adds or removes the support measurement with DMA*/
#define FTM_ICU_TIMESTAMP_USES_DMA         ([!IF "$TimestampDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode.If this parameter has been configured to STD_ON,
 *  the FTM driver code can be executed from both supervisor and user mode.
 */
#define FTM_ICU_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (FTM_ICU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == FTM_ICU_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

/** @brief Get FTM type for each platform. */
#define Ftm_Icu_Ip_BaseType                   FTM_Type

/** @brief Define if global variables need to be placed in non-cache area or not */
#define FTM_ICU_IP_NO_CACHE_USED              ([!IF "num:i(count(IcuGeneral/IcuEcucPartitionRef/*)) > 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == FTM_ICU_TIMESTAMP_API)
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific micro-controller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 Ftm_Icu_ValueType;
#endif
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* FTM_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

#endif  /* FTM_ICU_IP_DEFINES_H */

/** @} */

[!ENDCODE!][!//
