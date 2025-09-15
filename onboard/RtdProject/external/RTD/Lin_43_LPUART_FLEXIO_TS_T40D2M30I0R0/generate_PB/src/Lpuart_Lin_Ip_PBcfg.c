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
[!NOCODE!]
[!VAR "PostBuildVariant"="string(null)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "PostBuildVariant"="text:toupper(concat('_',$postBuildVariant))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
/**
*   @file   Lpuart_Lin_Ip_PBcfg.c
*   @implements Lpuart_Lin_Ip_PBcfg.c_Artifact
*
*   @addtogroup LPUART_LIN
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Lpuart_Lin_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_VENDOR_ID_C                     43
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MAJOR_VERSION_C              3
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MINOR_VERSION_C              0
#define LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Lpuart_Lin_Ip_Cfg.h */
#if (LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_VENDOR_ID_C != LPUART_LIN_IP_CFG_VENDOR_ID)
    #error "Lpuart_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpuart_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Lpuart_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPUART_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPUART_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPUART_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lpuart_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpuart_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Lpuart_Lin_Ip_Cfg header file are of the same Software version */
#if ((LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MAJOR_VERSION_C != LPUART_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MINOR_VERSION_C != LPUART_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LPUART_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_PATCH_VERSION_C != LPUART_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lpuart_Lin_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL FUNCTIONS DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]
[!VAR "NumHwChannelConfig" = "0"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "contains(node:value(LinHwChannel),'LPUART')"!][!//
        [!VAR "NumHwChannelConfig" = "$NumHwChannelConfig + 1"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!]

[!IF "$NumHwChannelConfig > 0"!]
#define LIN_43_LPUART_FLEXIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
[!ENDIF!]
[!NOCODE!]
[!VAR "CurrentChannel" = "0"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!]
    [!IF "contains(node:value(LinHwChannel),'LPUART')"!][!//
        [!VAR "Baudrate" = "LinChannelBaudRate"!]

        [!VAR "LinHeaderTimeoutValue" = "ceiling(LinHeaderTimeout * 1000000 * (1 div $Baudrate))"!]
        [!VAR "LinResponseTimeoutValue" = "ceiling((LinResponseTimeout) * 1000000 * (1 div $Baudrate))"!]
        [!// Assign wakeup signal to satisfy LIN Specifications specifies that wakeup signal shall be in range from 250us to 5 ms.
        [!IF "$Baudrate > 10000"!]
            [!VAR "WakeupByte" = "128"!][!// Wakeup signal will be range from 400us to 800us depend on baudrate.
        [!ELSE!]
            [!VAR "WakeupByte" = "248"!][!// Wakeup signal will be range from 400us to 4ms depend on baudrate.
        [!ENDIF!]

[!CODE!]
/**
* @brief          Hardware configuration for Lin Hardware Instance [!"LinHwChannel"!] - Configuration:
*
*
*/
const Lpuart_Lin_Ip_UserConfigType Lpuart_Lin_Ip_pxHwConfigPB_[!"LinChannelId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!]
        [!VAR "LinBaudrate" = "LinChannelBaudRate"!]
        [!SELECT "node:ref(LinClockRef)"!]
            [!INCLUDE "Lin_BaudRate_Comp.m"!][!//
        [!ENDSELECT!][!//
        [!IF "contains(node:value(LinHwChannel), 'LPE_LPUART_IP')"!][!// LPE_LPUART_IP_x is only available on S32K5
            [!VAR "HwInstanceCount" = "substring-after(LinHwChannel, 'LPE_LPUART_IP') + 22"!]
        [!ELSE!]
            [!VAR "HwInstanceCount" = "substring-after(LinHwChannel, 'LPUART_IP_')"!]
        [!ENDIF!]
[!CODE!]
    [!"num:i($HwInstanceCount)"!]U, /*!< Hardware instance */

    [!"$BaudrateConf_Value"!]U, /*!< Baudrate divisor */

    16U, /*!< Baudrate OSR */
[!ENDCODE!]
        [!IF "contains(node:value(LinNodeType), 'MASTER')"!]
[!CODE!]
    (boolean)LPUART_LIN_IP_MASTER, /*!< Master node */
[!ENDCODE!]
        [!ELSE!]
[!CODE!]
    (boolean)LPUART_LIN_IP_SLAVE, /*!< Slave node */
[!ENDCODE!]
        [!ENDIF!], /*!< Node function as Master or Slave */
[!CODE!]
    LPUART_LIN_IP_BREAK_CHAR_13_BIT_MINIMUM_U8, /*!< Break character length is transmitted */
[!ENDCODE!]
[!CODE!]
    (uint8)1U,    /*!< Detect break character at [!"substring-after(DetectedBreakLength, '_')"!] bits */
#if (LPUART_LIN_IP_AUTO_BAUD == STD_ON)
    (boolean)FALSE, /*!<  Autobaudrate feature */
#endif
    (Lpuart_Lin_Ip_CallbackType)&Lin_43_LPUART_FLEXIO_Ipw_Callback, /*!< Callback function to invoke after receiving a byte or transmitting a byte. */

    &Lpuart_Lin_Ip_axStateStructure[[!"num:i($CurrentChannel)"!]U], /*!< Runtime state structure referrence */
#if (LPUART_LIN_IP_FRAME_TIMEOUT_DISABLE == STD_OFF)
#ifdef LPUART_LIN_IP_START_TIMER_NOTIFICATION
    [!"num:i($LinHeaderTimeoutValue)"!]U,           /*!< HeaderTimeoutValue in microseconds */

    [!"num:i($LinResponseTimeoutValue)"!]U,         /*!< ResponseTimeoutValue in microseconds for 1 byte */
#endif
#endif /* (LPUART_LIN_IP_START_TIMER_NOTIFICATION == STD_OFF) */
    (uint8)[!"concat('0x',text:toupper(substring-after(num:inttohex($WakeupByte),'0x')))"!], /*!< Wakeup byte */

    [!"num:i($ClockFrequencyFromMcu)"!]U            /*!< Channel clock */
};
[!ENDCODE!]
        [!VAR "CurrentChannel" = "$CurrentChannel + 1"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!]
[!IF "$NumHwChannelConfig > 0"!]
#define LIN_43_LPUART_FLEXIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_43_LPUART_FLEXIO_MemMap.h"
[!ENDIF!]
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
