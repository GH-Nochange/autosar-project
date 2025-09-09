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

#ifndef PORT_CI_ICU_IP_DEFINES_H
#define PORT_CI_ICU_IP_DEFINES_H

/**
 *   @file    Port_Ci_Icu_Ip_Defines.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup port_ci_icu_ip PORT_CI IPL
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
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_PORT.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_PORT.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_DEFINES_VENDOR_ID                      43
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       7
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define PORT_CI_ICU_IP_DEFINES_SW_MAJOR_VERSION               3
#define PORT_CI_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define PORT_CI_ICU_IP_DEFINES_SW_PATCH_VERSION               0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!IF "count(./IcuConfigSet/IcuPort/*) > '0'"!][!//
    [!CODE!][!WS "0"!]/* Macros that indicate PORT instances used by ICU. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K14') or contains($DerivativeName, 'S32M24')"!][!//
        [!SELECT "./IcuConfigSet"!][!//
            [!LOOP "IcuHwInterruptConfigList/*"!][!//
                [!IF "contains(IcuIsrHwId, 'PORT')"!][!//
                    [!VAR "portInstance" = "text:split(./IcuIsrHwId, '_')[2]"!][!//
                    [!CODE!]
/** @brief PORT [!"$portInstance"!] ISR enable/disable */
#define PORT_CI_ICU_IP_PORT_[!"$portInstance"!]_ISR_USED                    (STD_ON)

                    [!ENDCODE!]
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDSELECT!][!//
    [!ELSE!][!//
        [!CODE!]
/** @brief PORT single ISR enable/disable */
#define PORT_CI_ICU_IP_SINGLE_INTERRUPT           (STD_ON)

/** @brief The number of PORT_CI instances available on platform */
#define ICU_NUM_PORT_CI_HW_MODULE_U8              ((uint8)[!"ecu:get('Icu.Num_Port_Hw_Modules')"!]U)

        [!ENDCODE!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/** @brief Switches the Development Error Detection and Notification on or off.  */
#define PORT_CI_ICU_IP_DEV_ERROR_DETECT           ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define PORT_CI_ICU_IP_EDGE_DETECT_API            ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define PORT_CI_ICU_IP_DEINIT_API                 ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define PORT_CI_ICU_IP_SET_MODE_API               ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Add or remove all functions related to input state. */
#define PORT_CI_ICU_IP_GET_INPUT_STATE_API        ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Define if global variables need to be placed in non-cache area or not */
#define PORT_CI_ICU_IP_NO_CACHE_USED              ([!IF "num:i(count(IcuGeneral/IcuEcucPartitionRef/*)) > 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode. If this parameter has been configured to STD_ON, the PORT driver 
 *         code can be executed from both supervisor and user mode. */
#define PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* PORT_CI_ICU_IP_DEFINES_H */
[!ENDCODE!]
