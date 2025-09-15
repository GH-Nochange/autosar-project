/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO
*   Dependencies         : 
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

#ifndef FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H

/**
*   @file
*   @defgroup flexio_uart_ip Flexio UART IPL
*   @addtogroup  flexio_uart_ip Flexio UART IPL
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_Uart_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_Uart_Ip_Types.h */
#if (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID != FLEXIO_UART_IP_TYPES_VENDOR_ID)
    #error "Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION   != FLEXIO_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION   != FLEXIO_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION!= FLEXIO_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Uart_Ip_Types.h are different"
#endif
#if ((FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION!= FLEXIO_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION!= FLEXIO_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION!= FLEXIO_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Uart_Ip_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


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

[!NOCODE!]
[!VAR "UsingFlexio" = "0"!]
[!LOOP "UartGlobalConfig/UartChannel/*"!]
    [!IF "UartHwUsing = 'FLEXIO_IP'"!]
        [!VAR "UsingFlexio" = "1"!]
        [!BREAK!][!//
    [!ENDIF!]
[!ENDLOOP!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "PostBuildVariantNameUnderspartition" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define FLEXIO_UART_IP_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB[!IF "$UsingFlexio = 1"!] \[!ENDIF!][!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "PostBuildVariantNameUnderspartition" = "string(null)"!][!//
[!CODE!]#define FLEXIO_UART_IP_CONFIG_PB[!IF "$UsingFlexio = 1"!] \[!ENDIF!][!CR!][!ENDCODE!]
[!ENDIF!][!//
[!VAR "MaxChannelNr" = "0"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'FLEXIO_IP'"!]
    [!VAR "MaxChannelNr" = "num:i($MaxChannelNr) + 1"!]
[!ENDIF!]
    [!ENDLOOP!]
[!VAR "Idx" = "0"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'FLEXIO_IP'"!]
[!CODE!]
extern const Flexio_Uart_Ip_UserConfigType Flexio_Uart_Ip_xHwConfigPB_[!"UartChannelId"!][!"$PostBuildVariantNameUnderspartition"!];[!IF "$Idx < $MaxChannelNr - 1"!][!CODE!]\[!ENDCODE!][!ENDIF!][!VAR "Idx" = "$Idx + 1"!][!CR!]
[!ENDCODE!][!//
[!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H */
