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



#ifndef CDD_UART_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H
#define CDD_UART_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H

/**
*   @file
*
*   @defgroup uart_driver UART Driver
*   @addtogroup  uart_driver UART Driver
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
#include "Uart_Types.h"

[!NOCODE!][!//
[!INCLUDE "Uart_VersionCheck_Inc_PB.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              3
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Uart_Types.h */
#if (UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_VENDOR_ID != UART_TYPES_VENDOR_ID)
    #error "Uart[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Uart_Types.h have different vendor ids"
#endif
#if ((UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION   != UART_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION   != UART_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION!= UART_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Uart[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Uart_Types.h are different"
#endif
#if ((UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION!= UART_TYPES_SW_MAJOR_VERSION) || \
     (UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION!= UART_TYPES_SW_MINOR_VERSION) || \
     (UART[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION!= UART_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Uart[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Uart_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
    [!IF "var:defined('postBuildVariant')"!][!//
        [!VAR "PostBuildVariantNameUnderspartition" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define UART_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!VAR "PostBuildVariantNameUnderspartition" = "string(null)"!][!//
[!CODE!]#define UART_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!][!//

    [!VAR "UartConfiguredPartitions" = "num:i((count(GeneralConfiguration/UartEcucPartitionRef/*)))"!][!//
        [!IF "$UartConfiguredPartitions > 0"!][!//
            [!LOOP "GeneralConfiguration/UartEcucPartitionRef/*"!][!//
                [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
[!CODE!]extern const Uart_ConfigType Uart_xConfig[!"$PostBuildVariantNameUnderspartition"!]_[!"$CurrentPartition"!];\[!CR!][!ENDCODE!][!//
            [!ENDLOOP!]
        [!ELSE!][!//
[!CODE!]extern const Uart_ConfigType Uart_xConfig[!"$PostBuildVariantNameUnderspartition"!];\
[!ENDCODE!]
        [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
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

#endif /* CDD_UART_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H */
