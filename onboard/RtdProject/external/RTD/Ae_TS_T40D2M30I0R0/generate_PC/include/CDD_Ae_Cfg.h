/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef CDD_AE_CFG_H
#define CDD_AE_CFG_H

/**
*   @file CDD_Ae_Cfg.h
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configuration
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
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "CDD_Ae_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Ae_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Mcal.h"
#include "CDD_Ae_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_AE_CFG_VENDOR_ID                    43
#define CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CDD_AE_CFG_AR_RELEASE_MINOR_VERSION     7
#define CDD_AE_CFG_AR_RELEASE_REVISION_VERSION  0
#define CDD_AE_CFG_SW_MAJOR_VERSION             3
#define CDD_AE_CFG_SW_MINOR_VERSION             0
#define CDD_AE_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against CDD_Ae_[!"."!]_PBcfg.h */
#if (CDD_AE_CFG_VENDOR_ID !=CDD_AE_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "CDD_Ae_Cfg.h and CDD_Ae_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_[!"."!]_PBcfg.h are different"
#endif
#if ((CDD_AE_CFG_SW_MAJOR_VERSION != CDD_AE_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (CDD_AE_CFG_SW_MINOR_VERSION != CDD_AE_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (CDD_AE_CFG_SW_PATCH_VERSION != CDD_AE_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against CDD_Ae_PBcfg.h */
#if (CDD_AE_CFG_VENDOR_ID != CDD_AE_PBCFG_VENDOR_ID)
    #error "CDD_Ae_Cfg.h and CDD_Ae_PBcfg.h have different vendor ids"
#endif
#if ((CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_PBcfg.h are different"
#endif
#if ((CDD_AE_CFG_SW_MAJOR_VERSION != CDD_AE_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_AE_CFG_SW_MINOR_VERSION != CDD_AE_PBCFG_SW_MINOR_VERSION) || \
     (CDD_AE_CFG_SW_PATCH_VERSION != CDD_AE_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Ae_Ipw_Types.h */
#if (CDD_AE_CFG_VENDOR_ID != CDD_AE_IPW_TYPES_VENDOR_ID)
    #error "CDD_Ae_Cfg.h and CDD_Ae_Ipw_Types.h have different vendor ids"
#endif
#if ((CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_Ipw_Types.h are different"
#endif
#if ((CDD_AE_CFG_SW_MAJOR_VERSION != CDD_AE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (CDD_AE_CFG_SW_MINOR_VERSION != CDD_AE_IPW_TYPES_SW_MINOR_VERSION) || \
     (CDD_AE_CFG_SW_PATCH_VERSION != CDD_AE_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Ae_Cfg.h and CDD_Ae_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_AE_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of CDD_Ae_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1))"!]
[!CODE!]#define AE_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]AE_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]AE_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

/*! @brief Enables / Disables PreCompile support when there is a single configuration */
#define AE_PRECOMPILE_SUPPORT          ([!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables DET development errors detection and reporting */
#define AE_DEV_ERROR_DETECT            ([!IF "AeGeneral/AeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Ae_GetVersionInfo API */
#define AE_VERSION_INFO_API            ([!IF "AeGeneral/AeVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief        Support for User mode.
*               If this parameter has been configured to 'TRUE' the AE driver can be executed from both supervisor and user mode.
*/
#define AE_ENABLE_USER_MODE_SUPPORT   ([!IF "AeGeneral/AeEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief        Support for NMI Interrupt.
*               If this parameter has been configured to 'TRUE' the interrupt can be executed.
*/
#define AE_USE_NMI_INTERRUPT (AEC_IP_USE_NMI_INTERRUPT)

#define AE_MULTIPARTITION_ENABLED                   ([!IF "AeGeneral/AeMultipartitionSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!]
[!VAR "maxPartition" = "num:i(0)"!]
[!IF "node:value(AeGeneral/AeMultipartitionSupport)='true'"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!ENDIF!]
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!]
[!ENDNOCODE!]

#define AE_MAX_PARTITIONS                   ([!"num:i($maxPartition)"!]U)

#if (STD_OFF == AE_MULTIPARTITION_ENABLED)
/**
* @brief Defines default CodeId value which is assigned to HWUnits, Sequences, Jobs and Channels in the case MultiPartition is not enabled.
*/
    #define AE_SPURIOUS_USER_ID_U32        ((uint32)0UL)
    #define AE_SPURIOUS_ID_U32     AE_SPURIOUS_USER_ID_U32
#endif

#if (STD_ON == AE_MULTIPARTITION_ENABLED)
    #define Ae_GetUserID     ((uint32)OsIf_GetUserId())
#else
    #define Ae_GetUserID     AE_SPURIOUS_ID_U32
#endif

#define Ae_GetID     Ae_GetUserID
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Forward IPW structure declarations */
struct Ae_Ipw_sConfigType;

/**
* @brief This type is used to group all multiple configurations.
* implements Ae_ConfigType_structure
*/
typedef struct
{
    uint32 AeCorePartitionUse;
    const struct Ae_Ipw_sConfigType *Ae_pIpwConfig;

} Ae_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_AE_CFG_H */

