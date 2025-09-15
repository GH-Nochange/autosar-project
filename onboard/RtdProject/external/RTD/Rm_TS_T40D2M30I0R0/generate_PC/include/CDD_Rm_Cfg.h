[!AUTOSPACING!][!//
[!CODE!][!//
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
#ifndef CDD_RM_CFG_H
#define CDD_RM_CFG_H

/**
*   @file CDD_Rm_Cfg.h
*
*   @addtogroup RM_MODULE RM Driver 
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
#include "Mcal.h"
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!]
#include "CDD_Rm_[!"."!]_PBcfg.h"
[!ENDLOOP!]
[!ELSE!][!//
#include "CDD_Rm_PBcfg.h"
[!ENDIF!]
#include "CDD_Rm_Ipw_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_CFG_VENDOR_ID                       43
#define RM_CFG_AR_RELEASE_MAJOR_VERSION        4
#define RM_CFG_AR_RELEASE_MINOR_VERSION        7
#define RM_CFG_AR_RELEASE_REVISION_VERSION     0
#define RM_CFG_SW_MAJOR_VERSION                3
#define RM_CFG_SW_MINOR_VERSION                0
#define RM_CFG_SW_PATCH_VERSION                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against CDD_Rm_[!"."!]_PBcfg.h */
#if (RM_CFG_VENDOR_ID != RM_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "CDD_Rm_Cfg.h and CDD_Rm_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((RM_CFG_AR_RELEASE_MAJOR_VERSION    != RM_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (RM_CFG_AR_RELEASE_MINOR_VERSION    != RM_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (RM_CFG_AR_RELEASE_REVISION_VERSION != RM_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_[!"."!]_PBcfg.h are different"
#endif
#if ((RM_CFG_SW_MAJOR_VERSION != RM_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (RM_CFG_SW_MINOR_VERSION != RM_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (RM_CFG_SW_PATCH_VERSION != RM_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against CDD_Rm_PBcfg.h */
#if (RM_CFG_VENDOR_ID != RM_PBCFG_VENDOR_ID)
    #error "CDD_Rm_Cfg.h and CDD_Rm_PBcfg.h have different vendor ids"
#endif
#if ((RM_CFG_AR_RELEASE_MAJOR_VERSION    != RM_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_CFG_AR_RELEASE_MINOR_VERSION    != RM_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_CFG_AR_RELEASE_REVISION_VERSION != RM_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_PBcfg.h are different"
#endif
#if ((RM_CFG_SW_MAJOR_VERSION != RM_PBCFG_SW_MAJOR_VERSION) || \
     (RM_CFG_SW_MINOR_VERSION != RM_PBCFG_SW_MINOR_VERSION) || \
     (RM_CFG_SW_PATCH_VERSION != RM_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_CFG_VENDOR_ID != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_CFG_SW_MAJOR_VERSION != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_CFG_SW_MINOR_VERSION != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_CFG_SW_PATCH_VERSION != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!] [!//
/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    RM_CONFIG_[!"text:toupper(.)"!]_PB[!IF "$variantIndex < $variantNumber"!] \[!CR!][!ENDIF!]
[!ENDLOOP!][!//
[!ELSE!][!//
    RM_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!][!//

/* Rm Pre Compile Switch */
#define RM_PRECOMPILE_SUPPORT                   ([!IF "(IMPLEMENTATION_CONFIG_VARIANT ='VariantPreCompile') and (variant:size()<=1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define RM_DEV_ERROR_DETECT                     ([!IF "RmGeneral/RmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Rm_GetVersionInfo() from the code.
*        STD_ON: Rm_GetVersionInfo() can be used. STD_OFF: Rm_GetVersionInfo() can not be used.
*
*/
#define RM_GET_VERSION_INFO_API                 ([!IF "RmGeneral/Rm_VersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief            Support for User mode.
*                   STD_ON: the Rm driver can be executed from both supervisor and user mode.
*                   STD_OFF: the Rm driver can be executed only from supervisor mode.
*/
#define RM_ENABLE_USER_MODE_SUPPORT             ([!IF "RmGeneral/RmEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == RM_ENABLE_USER_MODE_SUPPORT)
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running RM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == RM_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

[!VAR "rmFeatureEnabled"="0"!]
/*********************************** DMA MUX SECTION ******************************/
#define RM_ENABLE_DMA_MUX                       ([!IF "RmGeneral/RmEnableDmaMuxSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "RmGeneral/RmEnableDmaMuxSupport"!][!VAR "rmFeatureEnabled"="1"!][!ENDIF!]
[!IF "$rmFeatureEnabled=0"!][!//
   [!ERROR!] [!//
         "At least one RM feature must be enabled(Xrdc, Sema42, Mscm, Dma Mux,...)."[!//
   [!ENDERROR!][!//
[!ENDIF!][!//

/**
* @brief            Support for Global Init.
*                   STD_ON: the Rm driver will support the API Rm_Init to initialize all IPs.
*                   STD_OFF: the Rm driver will support init function separately for IPs.
*/
#define RM_ENABLE_GLOBAL_INIT                   ([!IF "RmGeneral/RmEnableGlobalInit"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!IF "node:exists(RmGeneral/RmMultiPartitionSupport)"!]
/**
* @brief        Support for MultiPartition.
*/
#define RM_MULTIPARTITION_SUPPORT               ([!IF "RmGeneral/RmMultiPartitionSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#if (STD_ON == RM_MULTIPARTITION_SUPPORT)
#define Rm_GetPartitionID()                     OsIf_GetUserId()
#else
#define RM_SPURIOUS_USER_ID_U8                  ((uint8)0U)
#define Rm_GetPartitionID()                     RM_SPURIOUS_USER_ID_U8
#endif
    [!IF "RmGeneral/RmMultiPartitionSupport = 'true'"!][!//
        [!LOOP "RmConfigSet/RmEcucPartitionRef/*"!][!//
            [!VAR "CurrentPartitionShortName" = "text:split(., '/')[position() = 5]"!][!//
            [!LOOP "as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!][!//
                [!IF "$CurrentPartitionShortName = node:name(.)"!][!//  
                [!VAR "CurrentPartitionId" = "node:pos(.)"!][!//
#define RM_PARTITION_[!"num:i($CurrentPartitionId)"!]                          ((uint8)[!"num:i($CurrentPartitionId)"!]U)
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
[!ELSE!][!//
/**
* @brief        Support for MultiPartition.
*/
#define RM_MULTIPARTITION_SUPPORT               (STD_OFF)
#define RM_SPURIOUS_USER_ID_U8                  ((uint8)0U)
[!ENDIF!]

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief This type is used to group all multiple configurations.
*/
typedef struct
{
#if defined(RM_MULTIPARTITION_SUPPORT)
#if (STD_ON == RM_MULTIPARTITION_SUPPORT)
    const uint8 u8PartitionId;                  /**< Partition Id */
#endif /* STD_ON == RM_MULTIPARTITION_SUPPORT */
#endif /* RM_MULTIPARTITION_SUPPORT */
    const Rm_Ipw_ConfigType *Rm_pIpwConfig;     /**< Rm Ip wrapper configuration structure */
} Rm_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* CDD_RM_CFG_H */

[!ENDCODE!][!//
