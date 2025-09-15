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

#ifndef LPTMR_ICU_IP_DEFINES_H
#define LPTMR_ICU_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup lptmr_icu_ip LPTMR IPL
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
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_LPTMR.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_LPTMR.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPTMR_ICU_IP_DEFINES_VENDOR_ID                       43
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LPTMR_ICU_IP_DEFINES_SW_MAJOR_VERSION                3
#define LPTMR_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define LPTMR_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!IF "count(./IcuConfigSet/IcuLptmr/*) > '0'"!][!//
    [!CODE!][!WS "0"!]/* Macros that indicate LPTMR instances used by ICU. */[!CR!][!ENDCODE!][!//
    [!SELECT "./IcuConfigSet"!][!//
        [!LOOP "IcuHwInterruptConfigList/*"!][!//
            [!IF "contains(IcuIsrHwId, 'LPTMR')"!][!//
                [!VAR "lptmrInstance" = "text:split(./IcuIsrHwId, '_')[2]"!][!//
                [!VAR "lptmrChannel" = "text:split(./IcuIsrHwId, '_')[4]"!][!//
                [!CODE!]
#ifndef LPTMR_[!"$lptmrInstance"!]_USED
    #define LPTMR_[!"$lptmrInstance"!]_USED
#else
    #error "LPTMR_[!"$lptmrInstance"!]_USED instance cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef LPTMR_ICU_[!"$lptmrInstance"!]_CH_[!"$lptmrChannel"!]_ISR_USED
    /** @brief Macros for instance used in ISR. */
    #define LPTMR_ICU_[!"$lptmrInstance"!]_CH_[!"$lptmrChannel"!]_ISR_USED               (STD_ON)
#endif
                [!ENDCODE!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define LPTMR_ICU_IP_DEV_ERROR_DETECT               ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief The number of LPTMR instances available on platform */
#define LPTMR_ICU_IP_NUM_OF_MODULES                 ([!"ecu:get('Icu.Num_Lptmr_Hw_Modules')"!]U)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define LPTMR_ICU_EDGE_DETECT_API                   ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the standby wakeup supported */
#define LPTMR_ICU_STANDBY_WAKEUP_SUPPORT            ([!IF "node:exists(IcuAutosarExt/IcuLptmrStandbyWakeupSupport)"!][!IF "IcuAutosarExt/IcuLptmrStandbyWakeupSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define LPTMR_ICU_DEINIT_API                        ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to edge count functionality. */
#define LPTMR_ICU_EDGE_COUNT_API                    ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define LPTMR_ICU_GET_INPUT_STATE_API               ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Define if global variables need to be placed in non-cache area or not */
#define LPTMR_ICU_IP_NO_CACHE_USED                  ([!IF "num:i(count(IcuGeneral/IcuEcucPartitionRef/*)) > 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode.If this parameter has been configured to STD_ON,
 *  the LPTMR driver code can be executed from both supervisor and user mode. */
#define LPTMR_ICU_ENABLE_USER_MODE_SUPPORT          ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (LPTMR_ICU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == LPTMR_ICU_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif
[!VAR "TimestampDmaEnable" = "0"!][!/*
*/!][!VAR "MeasurementDmaEnable" = "0"!][!/*
*/!][!SELECT "IcuConfigSet"!][!/*
    */!][!LOOP "./IcuChannel/*"!][!/*
    */!][!IF "IcuDMAChannelEnable = 'true'"!][!/*
        */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
            */!][!VAR "MeasurementDmaEnable" = "$MeasurementDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
 */!][!ENDSELECT!]

/** @brief Get LPTMR type for each platform. */
#define Lptmr_Icu_Ip_BaseType                       LPTMR_Type

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* LPTMR_ICU_IP_DEFINES_H */

/** @} */

[!ENDCODE!][!//
