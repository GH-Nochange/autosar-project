[!AUTOSPACING!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H

/**
*   @file       Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
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

#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_VENDOR_ID                       43
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION                3
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION                0
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "instanceId" = "substring-after(./PwmHwInstance, '_')"!]
    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "channelId" = "substring-after(./PwmFtmChId, '_')"!]
        [!VAR "channelCfgName" = "name(.)"!]
/* Ftm instance index for configuration [!"$channelCfgName"!] */
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_I[!"$instanceId"!]_CH[!"$channelId"!]_CFG      ([!"$instanceId"!]U)
    [!ENDLOOP!]
[!ENDLOOP!]

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "ecu:get('Pwm.FTM_PWM_HAS_FAULT') = 'true'"!]
   [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
        [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]
        [!IF "(./FtmGlobalFaultCfg/FtmFaultFunctionality != 'FAULT_DISABLED')"!]
            [!IF "(./FtmGlobalFaultCfg/FtmFaultIrqUsed)"!]
                [!CODE!]
#ifndef FTM_PWM_IP_[!"$HwInstance"!]_FAULT_ISR_USED
    #define FTM_PWM_IP_[!"$HwInstance"!]_FAULT_ISR_USED
#endif
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!] 
   [!ENDLOOP!]
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
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "instanceId" = "substring-after(./PwmHwInstance, '_')"!]
/*================================================================================================*/
/* Ftm instance [!"$instanceId"!] User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_UserCfg[!"$instanceId"!];

/* Channel configurations for Ftm instance [!"$instanceId"!] */
    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "channelId" = "substring-after(./PwmFtmChId, '_')"!]
/* Ftm channel [!"$channelId"!] configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!];
[!CR!]
    [!ENDLOOP!]
[!ENDLOOP!]

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBCFG_H */

[!ENDCODE!]
