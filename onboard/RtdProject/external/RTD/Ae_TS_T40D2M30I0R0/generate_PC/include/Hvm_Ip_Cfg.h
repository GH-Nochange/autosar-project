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

#ifndef HVM_IP_CFG_H
#define HVM_IP_CFG_H

/**
*   @file
*
*   @addtogroup HVM_DRIVER_CONFIGURATION HVM Driver Configuration
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
[!CODE!]#include "Hvm_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Hvm_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Std_Types.h"
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define HVM_IP_CFG_VENDOR_ID                     43
#define HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define HVM_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define HVM_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define HVM_IP_CFG_SW_MAJOR_VERSION              3
#define HVM_IP_CFG_SW_MINOR_VERSION              0
#define HVM_IP_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Hvm_Ip_[!"."!]_PBcfg.h */
#if (HVM_IP_CFG_VENDOR_ID != HVM_IP_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "Hvm_Ip_Cfg.h and Hvm_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != HVM_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_CFG_AR_RELEASE_MINOR_VERSION    != HVM_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_CFG_AR_RELEASE_REVISION_VERSION != HVM_IP_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Cfg.h and Hvm_Ip_[!"."!]_PBcfg.h are different"
#endif
#if ((HVM_IP_CFG_SW_MAJOR_VERSION != HVM_IP_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (HVM_IP_CFG_SW_MINOR_VERSION != HVM_IP_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (HVM_IP_CFG_SW_PATCH_VERSION != HVM_IP_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Cfg.h and Hvm_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Hvm_Ip_PBcfg.h */
#if (HVM_IP_CFG_VENDOR_ID != HVM_IP_PBCFG_VENDOR_ID)
    #error "Hvm_Ip_Cfg.h and Hvm_Ip_PBcfg.h have different vendor ids"
#endif
#if ((HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != HVM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (HVM_IP_CFG_AR_RELEASE_MINOR_VERSION    != HVM_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (HVM_IP_CFG_AR_RELEASE_REVISION_VERSION != HVM_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Hvm_Ip_Cfg.h and Hvm_Ip_PBcfg.h are different"
#endif
#if ((HVM_IP_CFG_SW_MAJOR_VERSION != HVM_IP_PBCFG_SW_MAJOR_VERSION) || \
     (HVM_IP_CFG_SW_MINOR_VERSION != HVM_IP_PBCFG_SW_MINOR_VERSION) || \
     (HVM_IP_CFG_SW_PATCH_VERSION != HVM_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Hvm_Ip_Cfg.h and Hvm_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Std_Types.h */
    #if ((HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (HVM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Hvm_Ip_Cfg.h and Std_Types.h are different"
    #endif
    /* Checks against Reg_eSys.h */
    #if ((HVM_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (HVM_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Hvm_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define HVM_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]HVM_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]HVM_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#define HVM_IP_DEV_ERROR_DETECT            ([!IF "AeGeneral/AeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define HVM_TIMEOUT_TYPE                ([!"AeGeneral/AeGeneralVendorSpecific/AeTimeoutMethod"!])

#define HVM_TIMEOUT_VALUE_US            ([!"AeGeneral/AeGeneralVendorSpecific/AeTimeoutDuration"!]U)

#define HVI_NUMOF_MAX_INSTANCES         ([!"num:i(count(AeHvmHviConfig/AeHvmHviInstanceConfig/*))"!]U)

#define HVM_CONTROL_CALLBACK_FUNC       ([!IF "AeHvmHviConfig/AeHvmHviGeneralConfig/AeHvmUnderControlIsrCallback"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define HVM_ENABLE_USER_MODE_SUPPORT    ([!IF "AeGeneral/AeEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward Hvm structure declarations */
struct Hvm_Ip_sHviChannelConfig;
struct Hvm_Ip_sVmConfig;

/**
* @brief   The structure contains the hardware controller configuration type.
* @implements Hvm_Ip_ConfigType_structure
*/
typedef struct Hvm_Ip_sConfigType
{
    uint8 AnalogChannel;
    uint8 AnalogInput;
    const struct Hvm_Ip_sHviChannelConfig *Hvm_pChannelConfig;
    const struct Hvm_Ip_sVmConfig *Hvm_pVmConfig;
} Hvm_Ip_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* HVM_IP_CFG_H */
