/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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
[!// Constant that defines the variant name
[!VAR "postBuildVariantUpperCase" = "text:toupper($postBuildVariant)"!]

#ifndef EWM_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_H
#define EWM_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_H

/**
*   @file
*
*   @addtogroup Ewm_Ip
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

#include "Ewm_Ip_Cfg_Defines.h"
#include "Ewm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG                    43
#define EWM_IP_MODULE_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG                    102
#define EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG     4
#define EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG     7
#define EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG  0
#define EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG             3
#define EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG             0
#define EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same vendor */
#if (EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_CFG_DEFINES_VENDOR_ID)
#error "Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same Autosar version */
#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG    != EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG    != EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same software version */
#if ((EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Ewm_Ip_Types.h header file are of the same vendor */
#if (EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_TYPES_VENDOR_ID)
#error "Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Types.h have different vendor ids"
#endif

#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG    != EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG    != EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Types.h are different"
#endif

#if ((EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG != EWM_IP_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ewm_Ip_Types.h are different"
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

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!NOCODE!]
[!INDENT "0"!]
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance1_','TS_T40D2M30I0R0/Wdg')"!][!//
[!IF "node:exists($xPathModule)"!][!//
[!CODE!]extern const Ewm_Ip_ConfigType Ewm_Ip_Settings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariantUpperCase"!][!ENDIF!];[!ENDCODE!][!CR!]

[!ENDIF!][!//

[!ENDINDENT!]
[!ENDNOCODE!]

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EWM_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_H */
