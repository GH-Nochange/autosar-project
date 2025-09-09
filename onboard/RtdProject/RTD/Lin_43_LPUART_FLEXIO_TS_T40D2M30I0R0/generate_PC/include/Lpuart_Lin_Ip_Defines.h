/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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

#ifndef LPUART_LIN_IP_DEFINES_H
#define LPUART_LIN_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup LPUART_LIN
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K3') or contains($DerivativeName, 'S32K1') or contains($DerivativeName, 'S32K5')"!][!//
        [!IF "contains($DerivativeName, 'S32K39') or contains($DerivativeName, 'S32K36')"!][!//
[!CODE!][!WS "0"!]
#include "S32K39_LPUART.h"[!CR!]
[!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K37')"!][!//
[!CODE!][!WS "0"!]
#include "S32K37_LPUART.h"
[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K310')"!][!//
[!CODE!][!WS "0"!]
#include "S32K311_LPUART.h"
[!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348') or contains($DerivativeName, 'S32K358')"!][!//
[!CODE!][!WS "0"!]
#include "S32K358_LPUART.h"
[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]
#include "[!"$DerivativeName"!]_LPUART.h"
[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32M244') or contains($DerivativeName, 'S32M242') or contains($DerivativeName, 'S32M241') or contains($DerivativeName, 'S32M243')"!]
    [!//
    [!CODE!][!WS "0"!]
#include "S32M24x_LPUART.h"
[!CR!][!ENDCODE!]
    [!ENDIF!][!//
    [!IF "contains($DerivativeName, 'S32M27')"!]
    [!//
    [!CODE!][!WS "0"!]
#include "S32M27x_LPUART.h"
[!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP_DEFINES_VENDOR_ID                    43
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define LPUART_LIN_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define LPUART_LIN_IP_DEFINES_SW_MAJOR_VERSION             3
#define LPUART_LIN_IP_DEFINES_SW_MINOR_VERSION             0
#define LPUART_LIN_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LPUART_LIN_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPUART_LIN_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Lpuart_Lin_Ip_Defines.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                     DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "NumHwChannelConfig" = "0"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "contains(node:value(LinHwChannel),'LPUART')"!][!//
        [!VAR "NumHwChannelConfig" = "$NumHwChannelConfig + 1"!]
    [!ENDIF!]
    [!IF "$NumHwChannelConfig = 0"!][!//When Lpuart is not configured, NumHwChannelConfig should be set to 1 to avoid build failures when the number of array elements is zero.
        [!VAR "NumHwChannelConfig" = "1"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!]
/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define LPUART_LIN_IP_DEV_ERROR_DETECT               ([!IF "LinGeneral/LinDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) /*!< Development error detection */

/**
* @brief   No of Channels configured for Lpuart
*
*
*/
#define LPUART_LIN_IP_NUMBER_OF_INSTANCES         ([!"num:i($NumHwChannelConfig)"!]U)


/**
* @brief          Lin Osif source counter
* @details        This parameter is used to select between different OsIf counter implementation
*
*
*/
#define  LPUART_LIN_IP_TIMEOUT_TYPE       ([!"LinGeneral/LinTimeoutMethod"!])

/**
* @brief   Number of loops before returning LPUART_STATUS_TIMEOUT.
*
*
*/
#define LPUART_LIN_IP_TIMEOUT_VALUE_US    ([!"LinGeneral/LinTimeoutDuration"!]U)

/**
* @brief   Enable/Disable Autobaud feature. This feature only support for IPV layer
* So HLD layer always disable for this feature.
*
*
*/
#define LPUART_LIN_IP_AUTO_BAUD           (STD_OFF)

/**
* @brief   Enable/Disable timeout feature.
*
*
*/
#define LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE        [!IF "AutosarExt/LinFrameTimeoutDisable = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!NOCODE!]
[!IF "node:fallback(AutosarExt/LinFrameTimeoutDisable, 'false') = 'false'"!]
    [!IF "node:exists(AutosarExt/LinLpuartStartTimerNotification)"!]
        [!IF "node:value(AutosarExt/LinLpuartStartTimerNotification) != 'NULL_PTR'"!]
            [!CODE!]
/**
* @brief   Notification function to start timeout counter.
*
*
*/
#define LPUART_LIN_IP_START_TIMER_NOTIFICATION       [!"AutosarExt/LinLpuartStartTimerNotification"!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(AutosarExt/LinLpuartStopTimerNotification)"!]
        [!IF "node:value(AutosarExt/LinLpuartStopTimerNotification) != 'NULL_PTR'"!]
            [!CODE!]
/**
* @brief   Notification function to end timeout counter.
*
*
*/
#define LPUART_LIN_IP_STOP_TIMER_NOTIFICATION         [!"AutosarExt/LinLpuartStopTimerNotification"!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!]

[!IF "node:exists(AutosarExt/LinLpuartWakeupTimerNotification)"!]
    [!IF "node:value(AutosarExt/LinLpuartWakeupTimerNotification) != 'NULL_PTR'"!]
[!CODE!]
/**
* @brief   Notification function to start/stop timeout counter when detecting the Wakeup pulse.
*
*
*/
#define LPUART_LIN_IP_WAKEUP_TIMER_NOTIFICATION         [!"AutosarExt/LinLpuartWakeupTimerNotification"!]
[!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]

/**
*
* @internal
* @brief          Link Lin channels symbolic names with Lin hardware channel IDs for LPUART instance.
* @details        Link Lin channels symbolic names with Lin hardware channel IDs for LPUART instance.
*
*
*/
[!ENDNOCODE!]
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K5')"!][!//
        [!VAR "HardwareInstance" = "0"!]
        [!LOOP "LinGlobalConfig/LinChannel/*"!][!//
            [!IF "contains(node:value(LinHwChannel), 'LPUART')"!]
                [!IF "contains(node:value(LinHwChannel), 'LPE_LPUART')"!][!// LPE_LPUART_IP_x is only available on S32K5
                    [!VAR "HardwareInstance" = "num:i(substring-after(LinHwChannel,'LPE_LPUART_IP_') + 22)"!]
                [!ELSE!]
                    [!VAR "HardwareInstance" = "num:i(substring-after(LinHwChannel,'IP_'))"!]
                [!ENDIF!]
    [!CODE!]
#define [!"LinHwChannel"!]    ((uint8)[!"$HardwareInstance"!]U)[!//
    [!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!][!//
    [!CODE!]

/** Re-define instances of the LPUART module for S32K5 */
#define LPUART_LIN_IP_LPUART_BASE_PTRS { IP_LPUART_0, IP_LPUART_1, IP_LPUART_2, IP_LPUART_3, IP_LPUART_4, IP_LPUART_5, IP_LPUART_6, IP_LPUART_7, IP_LPUART_8, IP_LPUART_9, IP_LPUART_10, IP_LPUART_11, IP_LPUART_12, \
                                         IP_LPUART_13, IP_LPUART_14, IP_LPUART_15, IP_LPUART_16, IP_LPUART_17, IP_LPUART_18, IP_LPUART_19, IP_LPUART_20, IP_LPUART_21, IP_LPE_LPUART_0, IP_LPE_LPUART_1, IP_LPE_LPUART_2 }
    [!ENDCODE!][!//
    [!ELSE!]
        [!VAR "HardwareInstance" = "0"!]
        [!LOOP "LinGlobalConfig/LinChannel/*"!][!//
            [!IF "contains(node:value(LinHwChannel), 'LPUART')"!]
            [!VAR "HardwareInstance" = "num:i(substring-after(LinHwChannel,'IP_'))"!]
    [!CODE!]
#define [!"LinHwChannel"!]    ((uint8)[!"$HardwareInstance"!]U)[!//
    [!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!][!//
    [!CODE!]
#define LPUART_LIN_IP_LPUART_BASE_PTRS      IP_LPUART_BASE_PTRS /* Default from Base */
    [!ENDCODE!][!//
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPUART_LIN_IP_DEFINES_H */
