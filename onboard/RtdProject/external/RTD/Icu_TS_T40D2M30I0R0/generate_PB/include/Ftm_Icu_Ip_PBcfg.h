[!AUTOSPACING!][!//
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H

/**
 *   @file    Ftm_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup ftm_icu_ip FTM IPL
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
#include "Ftm_Icu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_VENDOR_ID                    43
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION     7
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION  0
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION             3
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION             0
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and ICU header file are of the same vendor */
#if (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_VENDOR_ID != FTM_ICU_IP_TYPES_VENDOR_ID)
    #error "Ftm_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ftm_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if header file and ICU header file are of the same AutoSar version */
#if ((FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION    != FTM_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION    != FTM_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION != FTM_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ftm_Icu_Ip_Types.h are different"
#endif
/* Check if header file and ICU header file are of the same Software version */
#if ((FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION != FTM_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION != FTM_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION != FTM_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Ftm_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//

[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!][!//
    [!IF "count(./IcuConfigSet/IcuFtm/*) > '0'"!][!//
        [!CODE!]/* Macro used to export generated configuration. */[!ENDCODE!][!//
        [!CODE!][!CR!]#define FTM_ICU_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB \[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "PBCfg_Variant" = "'PB'"!][!//
    [!IF "count(./IcuConfigSet/IcuFtm/*) > '0'"!][!//
        [!CODE!]/* Macro used to export generated configuration. */[!ENDCODE!][!//
        [!CODE!][!CR!]#define FTM_ICU_CONFIG_PB \[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuFtm/*) > '0'"!][!//
    [!LOOP "IcuFtm/*"!][!//
    [!CODE!][!WS "4"!]extern const Ftm_Icu_Ip_ChannelConfigType  Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"num:i(count(IcuFtmChannels/*))"!]U]; \[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]extern const Ftm_Icu_Ip_InstanceConfigType Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_InstanceConfig_[!"$PBCfg_Variant"!]; \[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]extern const Ftm_Icu_Ip_ConfigType         Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_Config_[!"$PBCfg_Variant"!]; \[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H */

[!ENDCODE!]
