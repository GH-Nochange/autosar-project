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

/**
*   @file
*
*   @addtogroup Ewm_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C                      43
#define EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C       4
#define EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C       7
#define EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C    0
#define EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C               3
#define EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C               0
#define EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h header file are of the same vendor */
#if (EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C != EWM_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG)
#error "Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif

/* Check if current file and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same Autosar version */
#if ((EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C    != EWM_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG) || \
     (EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C    != EWM_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG) || \
     (EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C != EWM_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG))
#error "AutoSar Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

/* Check if current file and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same software version */
#if ((EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C != EWM_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG) || \
     (EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C != EWM_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG) || \
     (EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG_C != EWM_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariantUpperCase"!]_[!ENDIF!]PBCFG))
#error "Software Version Numbers of Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ewm_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!AUTOSPACING!]
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance1_','TS_T40D2M30I0R0/Wdg')"!][!//
[!IF "node:exists($xPathModule)"!][!//
[!IF "(normalize-space(node:value(concat($xPathModule,'/WdgGeneral/WdgCallbackNotification'))) !='NULL_PTR') and (normalize-space(node:value(concat($xPathModule,'/WdgGeneral/WdgCallbackNotification'))) !='NULL')"!]
/**
 *   @brief External Notifications for Wdg Interrupt
 */[!CR!]
extern void [!"node:value(concat($xPathModule,'/WdgGeneral/WdgCallbackNotification'))"!](void);
[!VAR "WdgCbkFunc" = "node:value(concat($xPathModule,'/WdgGeneral/WdgCallbackNotification'))"!]
[!ELSE!]
[!VAR "WdgCbkFunc" = "'NULL_PTR'"!]
[!ENDIF!]
[!ENDIF!]

[!IF "node:exists($xPathModule)"!][!//
const Ewm_Ip_ConfigType Ewm_Ip_Settings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariantUpperCase"!][!ENDIF!]=
{
    [!CALL "EwmConfig", "WdgNo" = "$xPathModule"!]
    [!IF "$WdgCbkFunc != 'NULL_PTR'"!]
    (Ewm_Ip_CallbackPtrType) &[!"$WdgCbkFunc"!]     /*pfEwmCallback*/
    [!ELSE!]
    (Ewm_Ip_CallbackPtrType) NULL_PTR       /*pfEwmCallback*/
    [!ENDIF!]
};

[!ENDIF!][!//

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
