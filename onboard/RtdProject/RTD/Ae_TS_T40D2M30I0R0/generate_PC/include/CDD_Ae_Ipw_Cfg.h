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

#ifndef CDD_AE_IPW_CFG_H
#define CDD_AE_IPW_CFG_H

/**
*   @file
*
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configurations
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
[!CODE!]#include "CDD_Ae_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Ae_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "CDD_Ae_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_AE_IPW_CFG_VENDOR_ID                    43
#define CDD_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CDD_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define CDD_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define CDD_AE_IPW_CFG_SW_MAJOR_VERSION             3
#define CDD_AE_IPW_CFG_SW_MINOR_VERSION             0
#define CDD_AE_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against CDD_Ae_Ipw_[!"."!]_PBcfg.h */
#if (CDD_AE_IPW_CFG_VENDOR_ID != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((CDD_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((CDD_AE_IPW_CFG_SW_MAJOR_VERSION != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_MINOR_VERSION != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_PATCH_VERSION != CDD_AE_IPW_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against CDD_Ae_Ipw_PBcfg.h */
#if (CDD_AE_IPW_CFG_VENDOR_ID != CDD_AE_IPW_PBCFG_VENDOR_ID)
    #error "CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((CDD_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_PBcfg.h are different"
#endif
#if ((CDD_AE_IPW_CFG_SW_MAJOR_VERSION != CDD_AE_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_MINOR_VERSION != CDD_AE_IPW_PBCFG_SW_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_PATCH_VERSION != CDD_AE_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against CDD_Ae_Cfg.h */
#if (CDD_AE_IPW_CFG_VENDOR_ID != CDD_AE_CFG_VENDOR_ID)
    #error "CDD_Ae_Ipw_Cfg.h and CDD_Ae_Cfg.h have different vendor ids"
#endif
#if ((CDD_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION    != CDD_AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != CDD_AE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Cfg.h are different"
#endif
#if ((CDD_AE_IPW_CFG_SW_MAJOR_VERSION != CDD_AE_CFG_SW_MAJOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_MINOR_VERSION != CDD_AE_CFG_SW_MINOR_VERSION) || \
     (CDD_AE_IPW_CFG_SW_PATCH_VERSION != CDD_AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ae_Ipw_Cfg.h and CDD_Ae_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define AE_IPW_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]AE_IPW_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]AE_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

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
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_AE_IPW_CFG_H */
