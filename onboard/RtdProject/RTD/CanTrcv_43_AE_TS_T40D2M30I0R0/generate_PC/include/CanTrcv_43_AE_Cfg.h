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

#ifndef CANTRCV_43_AE_CFG_H
#define CANTRCV_43_AE_CFG_H

/**
*   @file    CanTrcv_43_AE_Cfg.h
*
*   @addtogroup CANTRCV_43_AE_DRIVER Can Transceiver Driver
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
[!AUTOSPACING!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "CanTrcv_43_AE_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "CanTrcv_43_AE_PBcfg.h"
[!ENDIF!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANTRCV_43_AE_CFG_VENDOR_ID                    43
#define CANTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_AE_CFG_SW_MAJOR_VERSION             3
#define CANTRCV_43_AE_CFG_SW_MINOR_VERSION             0
#define CANTRCV_43_AE_CFG_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h header file are of the same vendor */
#if (CANTRCV_43_AE_CFG_VENDOR_ID != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
    #error "CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    (CANTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h are different"
#endif

/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h header file are of the same software version */
#if ((CANTRCV_43_AE_CFG_SW_MAJOR_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
    (CANTRCV_43_AE_CFG_SW_MINOR_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
    (CANTRCV_43_AE_CFG_SW_PATCH_VERSION != CANTRCV_43_AE_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!]
[!ELSE!]
/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h header file are of the same vendor */
#if (CANTRCV_43_AE_CFG_VENDOR_ID != CANTRCV_43_AE_PBCFG_VENDOR_ID)
    #error "CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h header file are of the same Autosar version */
#if ((CANTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_AE_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION != CANTRCV_43_AE_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    (CANTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION != CANTRCV_43_AE_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h are different"
#endif

/* Check if CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h header file are of the same software version */
#if ((CANTRCV_43_AE_CFG_SW_MAJOR_VERSION != CANTRCV_43_AE_PBCFG_SW_MAJOR_VERSION) || \
    (CANTRCV_43_AE_CFG_SW_MINOR_VERSION != CANTRCV_43_AE_PBCFG_SW_MINOR_VERSION) || \
    (CANTRCV_43_AE_CFG_SW_PATCH_VERSION != CANTRCV_43_AE_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Cfg.h and CanTrcv_43_AE_PBcfg.h are different"
#endif
[!ENDIF!]

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   @brief      Enable/Disable Precompile Support
*/
#define CANTRCV_43_AE_PRECOMPILE_SUPPORT[!WS "4"!][!IF "IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size()<=1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      The definition represent for number of ECUC partition configured.
*/
[!NOCODE!]
    [!VAR "maxPartitionConfig" = "num:i(1)"!]
    [!IF "CanTrcvGeneral/CanTrcvMultiPartitionSupport = 'true'"!]
        [!IF "node:exists(as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
            [!VAR "maxPartitionConfig" = "num:i(count(as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDNOCODE!]
#define CANTRCV_43_AE_MAX_PARTITIONS[!WS "4"!]([!"$maxPartitionConfig"!]U)

[!SELECT "CanTrcvGeneral"!]
/**
*   @brief      The definition used for guarding GetCoreID/MultiPartition
*/
#define CANTRCV_43_AE_MULTIPARTITION_ENABLED[!WS "4"!][!IF "num:i(count(./CanTrcvEcucPartitionRef/*)) > 0"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Enable/Disable Development Error Detection and Notification
*/
#define CANTRCV_43_AE_DEV_ERROR_DETECT[!WS "4"!][!IF "./CanTrcvDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Enable/Disable support CanTrcv_GetVersionInfo API
*/
#define CANTRCV_43_AE_VERSION_INFO_API[!WS "4"!][!IF "./CanTrcvVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Enable/Disable support Wakeup Mode
*/
#define CANTRCV_43_AEWAKEUP_MODE_POLLING[!WS "4"!][!IF "./CanTrcvWakeUpSupport = 'CANTRCV_WAKEUP_BY_POLLING'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Instance of the Can Hw unit
*/
#define CANTRCV_43_AE_INSTANCE[!WS "4"!]((uint8)[!"num:i(./CanTrcvIndex)"!]U)

[!IF "node:exists(./CanTrcvMainFunctionDiagnosticsPeriod)"!]
/**
*   @brief      Period for cyclic call of MainFunction Diagnostics
*/
#define CANTRCV_43_AE_MAINFUNCTIONDIAGNOSTICS_PERIOD[!WS "4"!]([!"./CanTrcvMainFunctionDiagnosticsPeriod"!]F)
[!ENDIF!]

[!IF "node:exists(./CanTrcvMainFunctionPeriod)"!]
/**
*   @brief      Period for cyclic call of MainFunction
*/
#define CANTRCV_43_AE_MAINFUNCTION_PERIOD[!WS "4"!]([!"./CanTrcvMainFunctionPeriod"!]F)
[!ENDIF!]

/**
*   @brief      Dem driver used
*/
#define CANTRCV_43_AE_DEM_USED[!WS "4"!][!IF "./CanTrcvDisableDiagnosticEventManager = 'false'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

[!ENDSELECT!]

[!SELECT "CanTrcvConfigSet"!]
/**
*   @brief      Number Of Can Transceiver Config
*/
#define CANTRCV_43_AE_TRANSCEIVER_CONFIG_COUNT[!WS "4"!]([!"num:i(count(./CanTrcvChannel/*))"!]U)[!CR!]

/**
*   @brief      Icu driver used
*/
#define CANTRCV_43_AE_ICU_USED[!WS "4"!][!IF "node:exists(./CanTrcvChannel/*/CanTrcvIcuChannelRef)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      EcuM driver used
*/
#define CANTRCV_43_AE_ECUM_USED[!WS "4"!][!IF "node:exists(./CanTrcvChannel/*/CanTrcvWakeupSourceRef)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Indicates if the Bus Error (BUSERR) flag is managed by the BSW
*/
#define CANTRCV_43_AE_BUSERR_EN[!WS "4"!][!IF "node:exists(./CanTrcvChannel/*[CanTrcvPartialNetwork/CanTrcvBusErrFlag='true'])"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

/**
*   @brief      Indicates if the capability of Driver to switch between Wake Up Frame or Wake Up Pattern modes
*/
#define CANTRCV_43_AE_SELECTIVE_WAKEUP_SUPPORT[!WS "4"!][!IF "ecu:get('CanTrcv.SelectiveWakeSupport') = 'STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
/**
*   @brief      Symbolic Name generated for Can Transceiver
*/
[!LOOP "node:order(./CanTrcvChannel/*, './CanTrcvChannelId')"!]
#define CanTrcv_43_AEConf_CanTrcvChannel_[!"@name"!][!WS "4"!]((uint8)[!"num:i(./CanTrcvChannelId)"!]U)[!CR!]
[!ENDLOOP!]

[!ENDSELECT!]

[!NOCODE!]
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
[!CODE!]#define CANTRCV_43_AE_CONFIG_EXT \[!CR!][!ENDCODE!]
    [!INDENT "4"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "variantIndex"="0"!]
        [!VAR "variantNumber"="variant:size()"!]
        [!LOOP "variant:all()"!]
            [!VAR "variantIndex"="$variantIndex + 1"!]
            [!CODE!]CANTRCV_43_AE_CONFIG_[!"text:toupper(.)"!]_PB [!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
        [!CODE!]CANTRCV_43_AE_CONFIG_PB[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!ENDINDENT!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANTRCV_43_AE_CFG_H */
