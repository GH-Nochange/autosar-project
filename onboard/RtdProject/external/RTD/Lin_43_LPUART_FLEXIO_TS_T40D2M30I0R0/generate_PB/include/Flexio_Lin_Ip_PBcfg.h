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
#ifndef FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_H
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_H

/**
*   @file
*
*   @addtogroup FLEXIO_IP
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

#include "Flexio_Lin_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_VENDOR_ID                     43
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MAJOR_VERSION              3
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MINOR_VERSION              0
#define FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Flexio_Lin_Ip_Types.h */
#if (FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_VENDOR_ID != FLEXIO_LIN_IP_TYPES_VENDOR_ID)
    #error "Flexio_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Lin_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Flexio_Lin_Ip_Types header file are of the same Autosar version */
#if ((FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_AR_RELEASE_REVISION_VERSION != FLEXIO_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Lin_Ip_Types.h are different"
#endif
/* Check if current file and Flexio_Lin_Ip_Types header file are of the same Software version */
#if ((FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MAJOR_VERSION != FLEXIO_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_MINOR_VERSION != FLEXIO_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_SW_PATCH_VERSION != FLEXIO_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_Lin_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Flexio_Lin_Ip_Types.h are different"
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
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "PostBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define FLEXIO_LIN_IP_CONFIG[!"$PostBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
    [!VAR "PostBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define FLEXIO_LIN_IP_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "contains(node:value(LinHwChannel),'FLEXIO')"!][!//
    [!CODE!]
    extern const Flexio_Lin_Ip_UserConfigType Flexio_Lin_Ip_pxHwConfigPB_[!"LinChannelId"!][!"$PostBuildVariantNameUnderscore"!];\
    [!ENDCODE!]
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

#endif /* FLEXIO_LIN_IP[!"$PostBuildVariant"!]_PBCFG_H */
