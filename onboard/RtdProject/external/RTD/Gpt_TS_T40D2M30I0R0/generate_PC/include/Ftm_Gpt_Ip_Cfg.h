/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530
*
* Copyright 2020-2025 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FTM_GPT_IP_CFG_H
#define FTM_GPT_IP_CFG_H

/**
*   @file           Ftm_Gpt_Ip_Cfg.h
*
*   @addtogroup     Ftm_Gpt_Ip Ftm_Gpt_Ip IPL
*
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
/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "Ftm_Gpt_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "Ftm_Gpt_Ip_PBcfg.h"
[!ENDIF!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_GPT_IP_VENDOR_ID_CFG                    43
#define FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define FTM_GPT_IP_SW_MAJOR_VERSION_CFG             3
#define FTM_GPT_IP_SW_MINOR_VERSION_CFG             0
#define FTM_GPT_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#if (FTM_GPT_IP_VENDOR_ID_CFG != FTM_GPT_IP_VENDOR_ID_[!"text:toupper(.)"!]_PBCFG_H)
    #error "Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_[!"."!]_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION_CFG != FTM_GPT_IP_SW_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (FTM_GPT_IP_SW_MINOR_VERSION_CFG != FTM_GPT_IP_SW_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (FTM_GPT_IP_SW_PATCH_VERSION_CFG != FTM_GPT_IP_SW_PATCH_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!]
[!ELSE!]
#if (FTM_GPT_IP_VENDOR_ID_CFG != FTM_GPT_IP_VENDOR_ID_PBCFG_H)
    #error "Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION_CFG != FTM_GPT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (FTM_GPT_IP_SW_MINOR_VERSION_CFG != FTM_GPT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (FTM_GPT_IP_SW_PATCH_VERSION_CFG != FTM_GPT_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_Cfg.h and Ftm_Gpt_Ip_PBcfg.h are different"
#endif
[!ENDIF!]
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Dev error detect switch
* @details Enable/disable GptDevErrorDetect
*/
#define FTM_GPT_IP_DEV_ERROR_DETECT ([!IF "GptDriverConfiguration/GptDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
*/
#define FTM_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API ([!IF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
* @brief    FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define FTM_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE     ([!IF "GptAutosarExt/GptChangeNextTimeoutValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*================================================================================================*/
/**
* @brief    FTM_GPT_IP_ABSOLUTE_COUNTING_API switch
* @details  Enable/disable FtmAbsoluteCounting.
*/
[!NOCODE!]
[!VAR "AbsCounting" = "0"!]
[!SELECT "./GptChannelConfigSet"!][!//
[!IF "count(GptFtm/*) > '0'"!][!//
    [!LOOP "GptFtm/*"!][!//
        [!LOOP "GptFtmChannels/*"!][!//
            [!IF "FtmAbsoluteCounting"!][!//
                [!VAR "AbsCounting" = "1"!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!]

#define FTM_GPT_IP_ABSOLUTE_COUNTING_API    ([!IF "$AbsCounting=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*================================================================================================*/
/**
* @brief    FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to TRUE the GPT driver code can be executed from both supervisor and user mode.
*/
#define FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT    ([!IF "GptAutosarExt/GptEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef FTM_GPT_IP_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*================================================================================================*/
[!NOCODE!]
[!MACRO "CalculateModulesNumber","Module"!]
    [!IF "$Module = 'FTM_0'"!][!//
        [!VAR "ChannelsNumberFtm0" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_1'"!][!//
        [!VAR "ChannelsNumberFtm1" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_2'"!][!//
        [!VAR "ChannelsNumberFtm2" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_3'"!][!//
        [!VAR "ChannelsNumberFtm3" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_4'"!][!//
        [!VAR "ChannelsNumberFtm4" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_5'"!][!//
        [!VAR "ChannelsNumberFtm5" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_6'"!][!//
        [!VAR "ChannelsNumberFtm6" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FTM_7'"!][!//
        [!VAR "ChannelsNumberFtm7" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_COSS_FTM_0'"!][!//
        [!VAR "ChannelsNumberFssCossFtm0" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_COSS_FTM_1'"!][!//
        [!VAR "ChannelsNumberFssCossFtm1" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_COSS_FTM_2'"!][!//
        [!VAR "ChannelsNumberFssCossFtm2" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_COSS_FTM_3'"!][!//
        [!VAR "ChannelsNumberFssCossFtm3" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_HKI_FTM_0'"!][!//
        [!VAR "ChannelsNumberFssHkiFtm0" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ELSEIF "$Module = 'FSS_HKI_FTM_1'"!][!//
        [!VAR "ChannelsNumberFssHkiFtm1" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($Module,'_CH','.*')))"!][!//
    [!ENDIF!]
[!ENDMACRO!]
[!ENDNOCODE!]
/*================================================================================================*/
[!NOCODE!]
[!CALL "CalculateModulesNumber","Module"="string('FTM_0')"!][!//
[!IF "num:i($ChannelsNumberFtm0) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_0 */
#define FTM_0_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm0)"!]U)
#define FTM_0_IP_EXISTS
#define FTM_0_IP_INSTANCE_NUMBER    (0U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_1')"!][!//
[!IF "num:i($ChannelsNumberFtm1) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_1 */
#define FTM_1_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm1)"!]U)
#define FTM_1_IP_EXISTS
#define FTM_1_IP_INSTANCE_NUMBER    (1U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_2')"!][!//
[!IF "num:i($ChannelsNumberFtm2) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_2 */
#define FTM_2_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm2)"!]U)
#define FTM_2_IP_EXISTS
#define FTM_2_IP_INSTANCE_NUMBER    (2U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_3')"!][!//
[!IF "num:i($ChannelsNumberFtm3) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_3 */
#define FTM_3_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm3)"!]U)
#define FTM_3_IP_EXISTS
#define FTM_3_IP_INSTANCE_NUMBER    (3U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_4')"!][!//
[!IF "num:i($ChannelsNumberFtm4) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_4 */
#define FTM_4_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm4)"!]U)
#define FTM_4_IP_EXISTS
#define FTM_4_IP_INSTANCE_NUMBER    (4U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_5')"!][!//
[!IF "num:i($ChannelsNumberFtm5) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_5 */
#define FTM_5_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm5)"!]U)
#define FTM_5_IP_EXISTS
#define FTM_5_IP_INSTANCE_NUMBER    (5U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_6')"!][!//
[!IF "num:i($ChannelsNumberFtm6) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_6 */
#define FTM_6_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm6)"!]U)
#define FTM_6_IP_EXISTS
#define FTM_6_IP_INSTANCE_NUMBER    (6U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FTM_7')"!][!//
[!IF "num:i($ChannelsNumberFtm7) > 0"!][!//
[!CODE!][!//
/** Channels number instance FTM_7 */
#define FTM_7_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFtm7)"!]U)
#define FTM_7_IP_EXISTS
#define FTM_7_IP_INSTANCE_NUMBER    (7U)
[!ENDCODE!][!//
[!ENDIF!][!//

[!CALL "CalculateModulesNumber","Module"="string('FSS_COSS_FTM_0')"!][!//
[!IF "num:i($ChannelsNumberFssCossFtm0) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_COSS_FTM_0 */
#define FSS_COSS_FTM_0_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssCossFtm0)"!]U)
#define FSS_COSS_FTM_0_IP_EXISTS
#define FSS_COSS_FTM_0_IP_INSTANCE_NUMBER    (0U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FSS_COSS_FTM_1')"!][!//
[!IF "num:i($ChannelsNumberFssCossFtm1) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_COSS_FTM_1 */
#define FSS_COSS_FTM_1_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssCossFtm1)"!]U)
#define FSS_COSS_FTM_1_IP_EXISTS
#define FSS_COSS_FTM_1_IP_INSTANCE_NUMBER    (1U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FSS_COSS_FTM_2')"!][!//
[!IF "num:i($ChannelsNumberFssCossFtm2) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_COSS_FTM_2 */
#define FSS_COSS_FTM_2_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssCossFtm2)"!]U)
#define FSS_COSS_FTM_2_IP_EXISTS
#define FSS_COSS_FTM_2_IP_INSTANCE_NUMBER    (2U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FSS_COSS_FTM_3')"!][!//
[!IF "num:i($ChannelsNumberFssCossFtm3) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_COSS_FTM_3 */
#define FSS_COSS_FTM_3_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssCossFtm3)"!]U)
#define FSS_COSS_FTM_3_IP_EXISTS
#define FSS_COSS_FTM_3_IP_INSTANCE_NUMBER    (3U)
[!ENDCODE!][!//
[!ENDIF!][!//

[!CALL "CalculateModulesNumber","Module"="string('FSS_HKI_FTM_0')"!][!//
[!IF "num:i($ChannelsNumberFssHkiFtm0) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_HKI_FTM_0 */
#define FSS_HKI_FTM_0_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssHkiFtm0)"!]U)
#define FSS_HKI_FTM_0_IP_EXISTS
#define FSS_HKI_FTM_0_IP_INSTANCE_NUMBER    (4U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!CALL "CalculateModulesNumber","Module"="string('FSS_HKI_FTM_1')"!][!//
[!IF "num:i($ChannelsNumberFssHkiFtm1) > 0"!][!//
[!CODE!][!//
/** Channels number instance FSS_HKI_FTM_1 */
#define FSS_HKI_FTM_1_IP_CHANNELS_NUMBER  ([!"num:i($ChannelsNumberFssHkiFtm1)"!]U)
#define FSS_HKI_FTM_1_IP_EXISTS
#define FSS_HKI_FTM_1_IP_INSTANCE_NUMBER    (5U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
/*================================================================================================*/

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
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* FTM_GPT_IP_CFG_H */
