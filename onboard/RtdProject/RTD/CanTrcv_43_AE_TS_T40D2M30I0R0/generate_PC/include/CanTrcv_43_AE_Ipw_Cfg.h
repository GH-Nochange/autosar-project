/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
/*==================================================================================================
==================================================================================================*/

#ifndef CANTRCV_43_AE_IPW_CFG_H
#define CANTRCV_43_AE_IPW_CFG_H

/**
*   @file    CanTrcv_43_AE_Ipw_Cfg.h
*
* @addtogroup   CANTRCV_43_AE_DRIVER Can Transceiver Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "CanTrcv_43_AE_Ipw_PBcfg.h"
[!ENDIF!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_IPW_CFG_VENDOR_ID                    43
#define CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION             3
#define CANTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h header file are of the same vendor */
        #if (CANTRCV_43_AE_IPW_CFG_VENDOR_ID != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
            #error "CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h have different vendor ids"
        #endif
        /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h header file are of the same Autosar version */
        #if ((CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
            (CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
            (CANTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
            )
            #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h are different"
        #endif

        /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h header file are of the same software version */
        #if ((CANTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
            (CANTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
            (CANTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION != CANTRCV_43_AE_IPW_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION) \
            )
            #error "Software Version Numbers of CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_[!"."!]_PBcfg.h are different"
        #endif
    [!ENDLOOP!]
[!ELSE!]
    /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.h header file are of the same vendor */
    #if (CANTRCV_43_AE_IPW_CFG_VENDOR_ID != CANTRCV_43_AE_IPW_PBCFG_VENDOR_ID)
        #error "CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.hhave different vendor ids"
    #endif
    /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.h header file are of the same Autosar version */
    #if ((CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
        (CANTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
        (CANTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_IPW_PBCFG_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.h are different"
    #endif

    /* Check if CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.h header file are of the same software version */
    #if ((CANTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION != CANTRCV_43_AE_IPW_PBCFG_SW_MAJOR_VERSION) || \
        (CANTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION != CANTRCV_43_AE_IPW_PBCFG_SW_MINOR_VERSION) || \
        (CANTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION != CANTRCV_43_AE_IPW_PBCFG_SW_PATCH_VERSION) \
        )
        #error "Software Version Numbers of CanTrcv_43_AE_Ipw_Cfg.h and CanTrcv_43_AE_Ipw_PBcfg.h are different"
    #endif
[!ENDIF!]
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define CANTRCV_43_AE_IPW_EXT \
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "variantIndex"="0"!]
    [!VAR "variantNumber"="variant:size()"!]
    [!LOOP "variant:all()"!]
        [!VAR "variantIndex"="$variantIndex + 1"!]
        [!CODE!]CANTRCV_43_AE_IPW_CONFIG_[!"text:toupper(.)"!]_PB [!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]CANTRCV_43_AE_IPW_CONFIG_PB[!CR!][!ENDCODE!]
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
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANTRCV_43_AE_IPW_CFG_H */
