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

#ifndef LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H

/**
*   @file
*   @defgroup lpuart_uart_ip Lpuart UART IPL
*   @addtogroup  lpuart_uart_ip Lpuart UART IPL
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

#include "Lpuart_Uart_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpuart_Uart_Ip_Types.h */
#if (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID != LPUART_UART_IP_TYPES_VENDOR_ID)
    #error "Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION   != LPUART_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION   != LPUART_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION!= LPUART_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h are different"
#endif
#if ((LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION!= LPUART_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION!= LPUART_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION!= LPUART_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpuart_Uart_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.h and Lpuart_Uart_Ip_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Link Uart channels symbolic names with Uart hardware channel IDs.
* @details        Link Uart channels symbolic names with Uart hardware channel IDs.
*
* @api
*/
[!VAR "Derivative" = "''"!][!//
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "GetDerivative" = "as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative"!][!//
    [!VAR "Derivative" = "text:toupper(substring-before($GetDerivative, '_'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!// Get number instance
[!VAR "VarUartHwChannel" = "0"!][!//
[!VAR "VarUartChannelDmaUsing" = "''"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
  [!IF "UartHwUsing = 'LPUART_IP'"!][!//
    [!VAR "HardwareChannel" = "node:value(DetailModuleConfiguration/UartHwChannel)"!][!//
    [!IF "contains($HardwareChannel, 'LPUART_MSC')"!][!// LPUART_MSC is only available on S32K396 S32K366 S32K364
            [!VAR "VarUartHwChannel" = "4"!][!//
        [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', substring-after($HardwareChannel,'LPUART_'))"!][!//
    [!ELSEIF "contains($HardwareChannel, 'LPE_LPUART_0')"!][!// LPUART_LPE is only available on S32K5
        [!VAR "VarUartHwChannel" = "22"!]
        [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', num:i($VarUartHwChannel))"!][!//
    [!ELSEIF "contains($HardwareChannel, 'LPE_LPUART_1')"!][!// LPUART_LPE is only available on S32K5
        [!VAR "VarUartHwChannel" = "23"!]
        [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', num:i($VarUartHwChannel))"!][!//
    [!ELSEIF "contains($HardwareChannel, 'LPE_LPUART_2')"!][!// LPUART_LPE is only available on S32K5
        [!VAR "VarUartHwChannel" = "24"!]
        [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', num:i($VarUartHwChannel))"!][!//
    [!ELSE!]
        [!VAR "VarUartHwChannel" = "substring-after(string($HardwareChannel),'LPUART_')"!][!//
        [!VAR "UartHWChannelName" = "concat('LPUART_UART_IP_INSTANCE_USING_', substring-after($HardwareChannel,'LPUART_'))"!][!//
    [!ENDIF!]
      [!CODE!][!//

#ifndef [!"$UartHWChannelName"!]
    #define [!"$UartHWChannelName"!]    [!"num:i($VarUartHwChannel)"!]U
#endif

      [!ENDCODE!][!//

    [!IF "contains($Derivative, 'S32K314') or contains($Derivative, 'S32K324') or contains($Derivative, 'S32K344') or contains($Derivative, 'S32K328') or contains($Derivative, 'S32K338') or contains($Derivative, 'S32K348') or contains($Derivative, 'S32K356') or contains($Derivative, 'S32K358') or contains($Derivative, 'S32K388')"!][!//
        [!IF "node:value(DetailModuleConfiguration/UartInteruptDmaMethod) = 'LPUART_UART_IP_USING_DMA'"!][!//
            [!VAR "VarUartChannelDmaUsing" = "concat($VarUartChannelDmaUsing,'_',$HardwareChannel,'_')"!][!//
        [!ENDIF!]
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//

[!IF "contains($Derivative, 'S32K314') or contains($Derivative, 'S32K324') or contains($Derivative, 'S32K344') or contains($Derivative, 'S32K328') or contains($Derivative, 'S32K338') or contains($Derivative, 'S32K348') or contains($Derivative, 'S32K356') or contains($Derivative, 'S32K358') or contains($Derivative, 'S32K388')"!][!//
    [!FOR "i" = "0" TO "7"!]
        [!IF "contains($VarUartChannelDmaUsing, concat('_','LPUART_',num:i($i),'_')) and contains($VarUartChannelDmaUsing, concat('_','LPUART_',num:i($i+8),'_'))"!][!//
            [!ERROR!]
                The LPUART[!"$i"!] and LPUART[!"num:i($i+8)"!] are used the same source channel of DMA method. So please config only one HW instance LPUART[!"$i"!] or LPUART[!"num:i($i+8)"!] to tranfer with DMA method.
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDIF!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

[!NOCODE!]
[!VAR "UsingLpuart" = "0"!]
[!LOOP "UartGlobalConfig/UartChannel/*"!]
    [!IF "UartHwUsing = 'LPUART_IP'"!]
        [!VAR "UsingLpuart" = "1"!]
        [!BREAK!][!//
    [!ENDIF!]
[!ENDLOOP!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "PostBuildVariantNameUnderspartition" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define LPUART_UART_IP_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB[!IF "$UsingLpuart = 1"!] \[!ENDIF!][!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "PostBuildVariantNameUnderspartition" = "string(null)"!][!//
[!CODE!]#define LPUART_UART_IP_CONFIG_PB[!IF "$UsingLpuart = 1"!] \[!ENDIF!][!CR!][!ENDCODE!]
[!ENDIF!][!//
[!VAR "MaxChannelNr" = "0"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'LPUART_IP'"!]
    [!VAR "MaxChannelNr" = "num:i($MaxChannelNr) + 1"!]
[!ENDIF!]
[!ENDLOOP!]
[!VAR "Idx" = "0"!][!//
[!LOOP "UartGlobalConfig/UartChannel/*"!][!//
[!IF "UartHwUsing = 'LPUART_IP'"!][!//
[!CODE!]extern const Lpuart_Uart_Ip_UserConfigType Lpuart_Uart_Ip_xHwConfigPB_[!"UartChannelId"!][!"$PostBuildVariantNameUnderspartition"!];[!IF "$Idx < $MaxChannelNr - 1"!][!CODE!]\[!ENDCODE!][!ENDIF!][!VAR "Idx" = "$Idx + 1"!][!CR!][!ENDCODE!][!//
[!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPUART_UART_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H */
