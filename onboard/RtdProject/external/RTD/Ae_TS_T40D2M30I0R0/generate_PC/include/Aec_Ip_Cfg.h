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

#ifndef AEC_IP_CFG_H
#define AEC_IP_CFG_H

/**
*   @file
*
*   @addtogroup AEC_DRIVER_CONFIGURATION AEC Driver Configuration
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
[!CODE!]#include "Aec_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Aec_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Std_Types.h"
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEC_IP_CFG_VENDOR_ID                     43
#define AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define AEC_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define AEC_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define AEC_IP_CFG_SW_MAJOR_VERSION              3
#define AEC_IP_CFG_SW_MINOR_VERSION              0
#define AEC_IP_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Aec_Ip_[!"."!]_PBcfg.h */
#if (AEC_IP_CFG_VENDOR_ID != AEC_IP_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "Aec_Ip_Cfg.h and Aec_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != AEC_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION    != AEC_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION != AEC_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_[!"."!]_PBcfg.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION != AEC_IP_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION != AEC_IP_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION != AEC_IP_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Aec_Ip_PBcfg.h */
#if (AEC_IP_CFG_VENDOR_ID != AEC_IP_PBCFG_VENDOR_ID)
    #error "Aec_Ip_Cfg.h and Aec_Ip_PBcfg.h have different vendor ids"
#endif
#if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != AEC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION    != AEC_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (AEC_IP_CFG_AR_RELEASE_REVISION_VERSION != AEC_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_PBcfg.h are different"
#endif
#if ((AEC_IP_CFG_SW_MAJOR_VERSION != AEC_IP_PBCFG_SW_MAJOR_VERSION) || \
     (AEC_IP_CFG_SW_MINOR_VERSION != AEC_IP_PBCFG_SW_MINOR_VERSION) || \
     (AEC_IP_CFG_SW_PATCH_VERSION != AEC_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Aec_Ip_Cfg.h and Aec_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Std_Types.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Std_Types.h are different"
    #endif
    /* Checks against Reg_eSys.h */
    #if ((AEC_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (AEC_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Aec_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define AEC_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]AEC_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]AEC_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#define AEC_IP_DEV_ERROR_DETECT            ([!IF "AeGeneral/AeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define AEC_TIMEOUT_TYPE                ([!"AeGeneral/AeGeneralVendorSpecific/AeTimeoutMethod"!])

#define AEC_TIMEOUT_VALUE_US            ([!"AeGeneral/AeGeneralVendorSpecific/AeTimeoutDuration"!]U)

#define AEC_EVENT_FAULT_NUM_MAX            ([!"num:i(count(AeIrqConfig/AeIntConfig/*))"!]U)

#define AEC_GHS_NUM_MAX                 ([!"num:i(count(AeGHSConfig/AeGHSHandlerConfig/*))"!]U)

#define AEC_EVENT_FAULT_FLAG_CLEAR      ([!IF "AeIrqConfig/ClearEventsFaultsFlagEn"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define AEC_GHS_FAULT_HANDLER      ([!IF "AeGHSConfig/AeGHSHandlerEnable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define AEC_ENABLE_USER_MODE_SUPPORT        ([!IF "AeGeneral/AeEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward Aec structure declarations */
struct Aec_Ip_sSpiConfigType;
struct Aec_Ip_sIntRouteConfigType;
struct Aec_Ip_sGHSRouteConfigType;

/**
* @brief          Structure storing the list of routing configurations for all configured interrupts.
* @implements     Aec_Ip_GlobalRouteConfigType_structure
*/
typedef struct
{
    /** @brief Faults enabled to raise interrupt */
    uint16 AecEnFaults;
    /** @brief Events enabled to raise interrupt */
    uint16 AecEnEvents;
    /** @brief List of interrupts configurations */
    const struct Aec_Ip_sIntRouteConfigType *aIntConfig;
} Aec_Ip_GlobalRouteConfigType;

/**
* @brief          Structure storing the list of routing configurations for all configured callback.
*/
typedef struct
{
    /** @brief Faults enabled to use callback */
    uint16 AecGHSFaults;
    /** @brief List of handler configurations */
    const struct Aec_Ip_sGHSRouteConfigType *aIntConfig;
} Aec_Ip_GlobalGHSRouteConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
* @implements Aec_Ip_ConfigType_structure
*/
typedef struct Aec_Ip_sConfigType
{
    const struct Aec_Ip_sSpiConfigType *AeSpiConfig;
} Aec_Ip_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

extern const Aec_Ip_GlobalRouteConfigType Aec_intRouteConfig;
extern const Aec_Ip_GlobalGHSRouteConfigType Aec_GHSRouteConfig;

[!NOCODE!]
[!VAR "Mac_UniqueHandlers"!][!ENDVAR!]
[!LOOP "AeIrqConfig/AeIntConfig/*/AeIntHandler"!]
    [!IF "contains($Mac_UniqueHandlers, concat(' ',node:value(.),' ') ) = 0"!]
        [!VAR "Mac_UniqueHandlers" = "concat($Mac_UniqueHandlers, concat(' ',node:value(.),' ') , ' ')"!]
        [!IF "contains(. , 'NULL_PTR') and (contains(text:split($Mac_UniqueHandlers), 'undefined_handler') = 0) or (contains(. , 'undefined_handler') and contains(text:split($Mac_UniqueHandlers), 'NULL_PTR') = 0)"!]
            [!CODE!]extern void undefined_handler(void);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!IF "contains(. , 'undefined_handler') = 0 and (contains(. , 'NULL_PTR') = 0)"!]
                [!CODE!]extern void [!"."!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

[!NOCODE!]
[!VAR "Mac_UniqueHandlers"!][!ENDVAR!]
[!LOOP "AeGHSConfig/AeGHSHandlerConfig/*/AeGHSHandler"!]
    [!IF "contains($Mac_UniqueHandlers, concat(' ',node:value(.),' ') ) = 0"!]
        [!VAR "Mac_UniqueHandlers" = "concat($Mac_UniqueHandlers, concat(' ',node:value(.),' ') , ' ')"!]
        [!IF "contains(. , 'NULL_PTR') and (contains(text:split($Mac_UniqueHandlers), 'undefined_handler') = 0) or (contains(. , 'undefined_handler') and contains(text:split($Mac_UniqueHandlers), 'NULL_PTR') = 0)"!]
            [!CODE!]extern void undefined_handler(void);[!CR!][!ENDCODE!]
        [!ELSE!]
            [!IF "contains(. , 'undefined_handler') = 0 and (contains(. , 'NULL_PTR') = 0)"!]
                [!CODE!]extern void [!"."!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEC_IP_CFG_H */
