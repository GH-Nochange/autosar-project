[!NOCODE!][!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!////////////////////////   VARIABLE DEFINE FOR EB TRESOS       ///////////////////////////////////


[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////

[!MACRO "FlsExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(FlsConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!][!CR!][!ENDCODE!]
        [!CODE!][!WS4!]extern const Fls_ConfigType [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!][!CR!][!ENDCODE!]
    [!CODE!][!WS4!]extern const Fls_ConfigType [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!MACRO "FeatureGetValue", "FeatureName"!][!//
[!NOCODE!][!//
[!IF "ecu:has($FeatureName)"!][!//
    [!CODE!][!"ecu:get($FeatureName)"!][!ENDCODE!]
[!ELSE!][!//
    [!CODE!]0[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_4_REV_0000_20250530
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

#ifndef FLS_CFG_H
#define FLS_CFG_H

/**
 *   @file       Fls_Cfg.h
 *
 *   @addtogroup FLS
 *   @implements Fls_Cfg.h_Artifact
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif


[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls_Types.h"
#include "Mcal.h"
[!ENDINDENT!][!//
#include "MemIf_Types.h"
#include "Ftfc_Fls_Ip_Cfg.h"
[!IF "FlsGeneral/FlsAcLoadOnJobStart != 'true'"!]#include "Ftfc_Fls_Ip_Ac.h"[!CR!][!ENDIF!][!//

#include "Qspi_Ip_Cfg.h"

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
#include "Fls_[!"."!]_PBcfg.h"
[!ENDLOOP!]
[!ELSE!]
#include "Fls_PBcfg.h"
[!ENDIF!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG                    43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG     4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG  0
#define FLS_SW_MAJOR_VERSION_CFG             3
#define FLS_SW_MINOR_VERSION_CFG             0
#define FLS_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls configuration header file are of the same vendor */
#if (FLS_TYPES_VENDOR_ID != FLS_VENDOR_ID_CFG)
    #error "Fls_Types.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fls configuration header file are of the same Autosar version */
#if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls configuration header file are of the same software version */
#if ((FLS_TYPES_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_TYPES_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Types.h and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_CFG != MEMIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Cfg.h and MemIf_Types.h are different"
    #endif
#endif


/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG != FTFC_FLS_IP_VENDOR_ID_CFG)
    #error "Fls_Cfg.h and Ftfc_Fls_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_Cfg.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG != FTFC_FLS_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG != FTFC_FLS_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG != FTFC_FLS_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_Cfg.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif


/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_Cfg.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Cfg.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION_CFG != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_Cfg.h and Qspi_Ip_Cfg.h are different"
#endif

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!VAR "variantName" = "."!][!//
[!VAR "variantNameUpperCase" = "text:toupper($variantName)"!][!//
/* Check if current file and Fls_[!"$variantName"!]_PBcfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG != FLS_[!"$variantNameUpperCase"!]_PBCFG_VENDOR_ID)
    #error "Fls_Cfg.h and Fls_[!"$variantName"!]_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Fls_[!"$variantName"!]_PBcfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG    != FLS_[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG    != FLS_[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG != FLS_[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Cfg.h and Fls_[!"$variantName"!]_PBcfg.h are different"
#endif
/* Check if current file and Fls_[!"$variantName"!]_PBcfg header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION_CFG != FLS_[!"$variantNameUpperCase"!]_PBCFG_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG != FLS_[!"$variantNameUpperCase"!]_PBCFG_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG != FLS_[!"$variantNameUpperCase"!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Cfg.h and Fls_[!"$variantName"!]_PBcfg.h are different"
#endif
[!ENDLOOP!]
[!ELSE!]
/* Check if current file and Fls_PBcfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG != FLS_PBCFG_VENDOR_ID)
    #error "Fls_Cfg.h and Fls_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Fls_PBcfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG    != FLS_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG    != FLS_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG != FLS_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Cfg.h and Fls_PBcfg.h are different"
#endif
/* Check if current file and Fls_PBcfg header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION_CFG != FLS_PBCFG_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG != FLS_PBCFG_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG != FLS_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Cfg.h and Fls_PBcfg.h are different"
#endif
[!ENDIF!][!//
[!//
[!INCLUDE "Fls_VersionCheck.m"!][!//

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

[!VAR "variantSize"="variant:size()"!][!//
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and ($variantSize <= 1))"!][!//
#define FLS_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantIndex"="0"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    FLS_CONFIG_[!"text:toupper(.)"!]_PB[!IF "$variantIndex < $variantSize"!] \[!ENDIF!][!CR!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
    FLS_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!][!//

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

/* Pre-compile Support. */
[!INDENT "0"!][!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]
#define FLS_PRECOMPILE_SUPPORT  (STD_ON)

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* Declaration of pre-compile configuration set structure */
#define Fls_Config Fls_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!]

extern const Fls_ConfigType Fls_Config;

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
[!ELSE!][!//
#define FLS_PRECOMPILE_SUPPORT  (STD_OFF)
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLS_CFG_H */

