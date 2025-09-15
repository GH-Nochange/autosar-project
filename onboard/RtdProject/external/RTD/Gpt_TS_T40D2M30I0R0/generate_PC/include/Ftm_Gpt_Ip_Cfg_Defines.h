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

#ifndef FTM_GPT_IP_CFG_DEFINES_H
#define FTM_GPT_IP_CFG_DEFINES_H

/**
*   @file           Ftm_Gpt_Ip_Cfg_Defines.h
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
#include "Std_Types.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName,'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'SAF85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85xx_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'SAF86')"!][!//
        [!CODE!][!WS "0"!]#include "SAF86xx_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32R45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32N5')"!][!//
        [!CODE!][!WS "0"!]#include "S32N55_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName,'S32N7')"!][!//
        [!CODE!][!WS "0"!]#include "S32N79_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugins or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_GPT_IP_DEFINES_VENDOR_ID_CFG                    43
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define FTM_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define FTM_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG             3
#define FTM_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define FTM_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "MacFtmUsed"="0"!][!//
    // Loop on all channels inside the same Configuration Set
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "node:value(GptChannelIsUsed) = 'true' and contains(GptIsrHwId, 'FTM')"!][!//
            [!VAR "MacFtmUsed"="1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//

/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define FTM_GPT_IP_USED ([!IF "$MacFtmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!//
[!IF "contains($DerivativeName,'S32N5')"!][!//
    [!CODE!]
/*================================================================================================*/
/**
 * @brief   This define is 'STD_ON' when on the same platform there are interrupts for all channels in one ISR,
 *          but also interrupt for each channel separately
 */
#define FTM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS (STD_ON)
/*================================================================================================*/
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define FTM_GPT_IP_MODULE_SINGLE_INTERRUPT (STD_OFF)
    [!ENDCODE!][!//
[!ELSE!][!//
    [!CODE!]
/*================================================================================================*/
/**
 * @brief   This define is 'STD_ON' when on the same platform there are interrupts for all channels in one ISR,
 *          but also interrupt for each channel separately
 */
#define FTM_GPT_IP_MODULE_SINGLE_AND_MULTIPLE_INTERRUPTS (STD_OFF)
/*================================================================================================*/
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define FTM_GPT_IP_MODULE_SINGLE_INTERRUPT [!IF "ecu:get('Gpt.GptConfig.Gpt_FTM_ModuleSingleInterrupt')='STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
    [!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*================================================================================================*/
/**
* @brief    FTN_GPT_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define FTM_GPT_IP_SET_CLOCK_MODE ([!IF "GptAutosarExt/GptEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
*
* @brief IRQ Defines for each channel used
*/
[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!IF "contains($DerivativeName,'S32N5')"!][!//
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "contains(GptIsrHwId,'FTM') and (GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
            [!IF "contains(GptIsrHwId,'FSS_HKI_FTM')"!][!//
                [!VAR "ModuleUsed"="concat(concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2]), '_' , text:split(GptIsrHwId,'_')[3], '_' , text:split(GptIsrHwId,'_')[4])"!][!//
                [!IF "contains($AlreadyParsedModule, $ModuleUsed) = false()"!][!//
                    [!CODE!][!WS "0"!]#define [!"$ModuleUsed"!]_ISR_USED[!CR!][!ENDCODE!][!//
                    [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,$ModuleUsed,'|')"!][!//
                [!ENDIF!][!//
            [!ELSEIF "contains(GptIsrHwId,'FSS_COSS_FTM')"!][!//
                [!CODE!][!WS "0"!]#define [!"GptIsrHwId"!]_ISR_USED[!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                [!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
                    [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
                    [!CODE!][!WS "0"!]#define [!"$ModuleUsed"!]_ISR_USED[!CR!][!ENDCODE!][!//
                    [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!]//
    [!ENDLOOP!][!//
[!ELSE!]
    [!IF "ecu:get('Gpt.GptConfig.Gpt_FTM_ModuleSingleInterrupt')='STD_ON'"!][!//
        [!LOOP "GptHwConfiguration/*"!][!//
            [!IF "contains(GptIsrHwId,'FTM') and (GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
                [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
                [!IF "contains($AlreadyParsedModule,$ModuleUsed) = false()"!][!//
                    [!CODE!][!WS "0"!]#define [!"$ModuleUsed"!]_ISR_USED[!CR!][!ENDCODE!][!//
                    [!VAR "AlreadyParsedModule"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ELSE!]
        [!FOR "Instance" = "0" TO "num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules')) - 1"!][!//
            /* Channel per instance */
            [!FOR "ChannelIdx" = "0" TO "floor(number(8) div 2)"!][!//
                [!VAR "GptChannelIsUsed_1" = "'false'"!][!//
                [!LOOP "GptHwConfiguration/*"!][!//
                    [!IF "contains(GptIsrHwId,'FTM') and (GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
                        [!IF "node:value(GptIsrEnable) = 'true' and contains(GptIsrHwId, concat('FTM_',$Instance)) and (contains(GptIsrHwId, concat('CH_',num:i($ChannelIdx)*2)) or contains(GptIsrHwId, concat('CH_',num:i($ChannelIdx)*2 + 1)))"!][!//
                            [!VAR "GptChannelIsUsed_1" = "'true'"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!]//
                [!ENDLOOP!][!//
                    /* Generate ISR when check in GptHwConfiguration */
                    [!IF "$GptChannelIsUsed_1 = 'true'"!][!//
[!CODE!]
#define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_ISR_USED[!ENDCODE!][!//
[!CODE!]
#ifndef FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_USED
    #define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_USED
#else
    #error "FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!] cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
[!CODE!]
#ifndef FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_USED
    #define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_USED
#else
    #error "FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!] cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ENDFOR!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!LOOP "GptHwConfiguration/*"!][!//
    [!IF "contains(GptIsrHwId,'FTM') and (GptChannelIsUsed = 'true')"!][!//
        [!IF "contains(GptIsrHwId,'FSS_COSS_FTM')"!][!//
            [!VAR "ModuleUsed"="concat(concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2]), '_' , text:split(GptIsrHwId,'_')[3], '_' , text:split(GptIsrHwId,'_')[4])"!][!//
            [!IF "contains($AlreadyParsedModule, $ModuleUsed) = false()"!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,$ModuleUsed,'|')"!][!//
[!LOOP "//GptFtm/*"!][!//
    [!IF "contains(GptFtmModule,$ModuleUsed)"!][!//
[!CODE!]
#ifndef [!"$ModuleUsed"!]_USED
    #define [!"$ModuleUsed"!]_USED
#else
    #error "[!"$ModuleUsed"!] instance cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ELSE!][!//
            [!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
                [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
[!LOOP "//GptFtm/*"!][!//
    [!IF "contains(GptFtmModule,$ModuleUsed)"!][!//
[!CODE!]
#ifndef [!"$ModuleUsed"!]_USED
    #define [!"$ModuleUsed"!]_USED
#else
    #error "[!"$ModuleUsed"!] instance cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
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

#endif  /* FTM_GPT_IP_CFG_DEFINES_H */
