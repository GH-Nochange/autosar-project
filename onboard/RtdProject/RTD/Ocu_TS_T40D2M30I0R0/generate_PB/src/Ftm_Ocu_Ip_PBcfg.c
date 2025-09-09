[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
/**
*   @file          Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c
*
*   @addtogroup    ocu_ip Ocu IPL
*   @brief         Ocu IPL Postbuild configuration source file.
*   @details       Postbuild configuration structure instances.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C                       43
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C                3
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C                0
#define FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
    #error "Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != FTM_OCU_IP[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!NOCODE!]
    [!VAR "numConfiguredOcuChannels" = "num:i(count(OcuConfigSet/OcuChannel/*))"!]
    [!VAR "numConfiguredOcuModules" = "num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]
    [!VAR "numFtmHwModules" = "ecu:get('Ocu.Num_Ftm_Hw_Modules')"!]
    [!VAR "numFtmHwChannels" = "ecu:get('Ocu.Num_Ftm_Hw_Channels')"!]
    [!VAR "OcuEnableDualClockMode" = "node:value(OcuGeneral/OcuEnableDualClockMode)"!]

    [!VAR "numOcuModules" = "0"!]
    [!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
    [!LOOP "OcuConfigSet/OcuHWSpecificSettings/*"!]
        /* Extract configuration only once for each Ftm module */
        [!IF "contains($AlreadyParsedModule, text:split(OcuHardwareElements,'_')[2]) = false()"!][!//
            [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(OcuHardwareElements,'_')[2], '|')"!][!//
            [!VAR "numOcuModules" = "$numOcuModules + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!VAR "MacNumFtmChannels"="0"!]
    /* Loop on all channels inside the same configuration Set */
    [!LOOP "OcuConfigSet/OcuChannel/*"!][!//
        [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'FTM')"!][!//
            [!VAR "MacNumFtmChannels"="$MacNumFtmChannels + 1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!]

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
extern void Ocu_ProcessChannelNotification(uint16 Channel);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!NOCODE!]
[!SELECT "OcuConfigSet"!]
[!IF "$numConfiguredOcuChannels > 0"!]
    [!FOR "ModuleIdx" = "0" TO "$numFtmHwModules - 1"!]
    [!VAR "CountChannels" = "0"!]
        [!LOOP "./OcuChannel/*"!]
            [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'FTM')"!]
                [!IF "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2] = $ModuleIdx"!][!//
                    [!VAR "CountChannels" = "$CountChannels + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$CountChannels != 0"!]
            [!CODE!]
/** @brief Number of configured Ftm channels for instance [!"$ModuleIdx"!] */
#define NUMBER_CONF_FTM_[!"$ModuleIdx"!]_CHANNEL[!"text:toupper($VS_number)"!]    ([!"num:i($CountChannels)"!]U)[!CR!]
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]

    [!IF "node:exists(OcuCountdirection)"!]
        [!IF "(OcuCountdirection = 'OCU_FTM_DOWNCOUNTING')"!]
            [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_DOWNCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
        [!ELSE!]
            [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_UPCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
        [!ENDIF!]
        [!ELSE!]
        [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_UPCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
    [!ENDIF!]

    [!VAR "AlreadyParsedModules"!][!ENDVAR!][!//
    [!VAR "NumOcuChannels" = "num:i(count(./OcuChannel/*))"!]
    [!FOR "ModuleIdx" = "0" TO "$numFtmHwModules - 1"!]
    [!FOR "VarChannelIndex" = "0" TO "$NumOcuChannels"!]
        [!LOOP "./OcuChannel/*"!]
            [!IF "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2] = $ModuleIdx"!][!//
                [!IF "contains($AlreadyParsedModules, $ModuleIdx) = false()"!]


                    /* Get logic channel information: max counter value */
                    [!VAR "ModuleMaxCounterValue" = "node:value(OcuMaxCounterValue)"!]

                    /* Get hw information: clock source */
                    [!IF "(node:exists(node:ref(./OcuHWSpecificSettingsRef)/OcuClockSource))"!]
                        [!IF "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuClockSource) = 'OCU_SYSTEM_CLOCK'"!]
                            [!VAR "SourceClock" = "'((uint8)(FTM_OCU_IP_CLOCK_SOURCE_SYSTEMCLK) << FTM_OCU_IP_CLOCK_SOURCE_SHIFT)'"!]
                        [!ELSE!]
                            [!VAR "SourceClock" = "'((uint8)(FTM_OCU_IP_CLOCK_SOURCE_EXTERNALCLK) << FTM_OCU_IP_CLOCK_SOURCE_SHIFT)'"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "SourceClock" = "'((uint8)(FTM_OCU_IP_CLOCK_SOURCE_SYSTEMCLK) << FTM_OCU_IP_CLOCK_SOURCE_SHIFT)'"!]
                    [!ENDIF!]

                    /* Get hw information: prescaler */
                    [!IF "(node:exists(node:ref(./OcuHWSpecificSettingsRef)/OcuPrescale))"!]
                        [!VAR "Prescaler" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuPrescale)"!]
                    [!ELSE!]
                        [!VAR "Prescaler" = "'DIV1'"!]
                    [!ENDIF!]

                    [!VAR "Prescaler" = "concat('FTM_OCU_IP_SC_PS_', $Prescaler,'_U32')"!]
                    [!VAR "Prescaler" = "concat('(uint8)((uint32)(', $Prescaler, ') << FTM_OCU_IP_CLOCK_DIV_SHIFT)')"!]

                    /* Get hw information: alternate prescaler */
                    [!IF "($OcuEnableDualClockMode = 'true')"!]
                        [!VAR "AltPrescaler" = "node:ref(./OcuHWSpecificSettingsRef)/OcuPrescale_Alternate"!]
                    [!ELSE!]
                        [!VAR "AltPrescaler" = "'DIV1'"!]
                    [!ENDIF!]

                    [!VAR "AltPrescaler" = "concat('FTM_OCU_IP_SC_PS_', $AltPrescaler,'_U32')"!]
                    [!VAR "AltPrescaler" = "concat('(uint8)((uint32)(', $AltPrescaler, ') << FTM_OCU_IP_ALT_CLOCK_DIV_SHIFT)')"!]

                    /* Get hw information: debug information */
                    [!IF "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuDebugMode) = 'CNT_STOPED_FLAG_SET'"!]
                        [!VAR "DebugCfg" = "'((uint8)(FTM_OCU_IP_BDM_MODE_00) << FTM_OCU_IP_CONF_BDMMODE_SHIFT_U8)'"!]
                    [!ELSEIF "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuDebugMode) = 'CNT_STOPED_OUTPUTS_SAFE'"!]
                        [!VAR "DebugCfg" = "'((uint8)(FTM_OCU_IP_BDM_MODE_01) << FTM_OCU_IP_CONF_BDMMODE_SHIFT_U8)'"!]
                    [!ELSEIF "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuDebugMode) = 'CNT_STOPED_OUTPUTS_FROZEN'"!]
                        [!VAR "DebugCfg" = "'((uint8)(FTM_OCU_IP_BDM_MODE_10) << FTM_OCU_IP_CONF_BDMMODE_SHIFT_U8)'"!]
                    [!ELSE!]
                        [!VAR "DebugCfg" = "'((uint8)(FTM_OCU_IP_BDM_MODE_11) << FTM_OCU_IP_CONF_BDMMODE_SHIFT_U8)'"!]
                    [!ENDIF!]

                    [!CODE!]
[!CR!]
/** @brief     Common module configuration for Ftm module [!"$ModuleIdx"!] */
static const Ftm_Ocu_Ip_SpecificIpConfigType Ftm_Ocu_Ip_[!"$ModuleIdx"!]_SpecificIpConfig_PB[!"$VS_number"!] = {
    /** @brief  Max Counter Value */
    (uint16)[!"concat('0x',text:toupper(text:split(num:inttohex($ModuleMaxCounterValue,4),'x')[2]))"!]U,
    /** @brief  Ftm Control Value */
    (uint8)
    (
    [!WS "8"!][!"$SourceClock"!] | /* Clock source */
    [!WS "8"!][!"$Prescaler"!] | /* Timer clock prescaler configuration */
    [!WS "8"!][!"$DebugCfg"!] /* Timer debug config */
    ),
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
    /** @brief  Alternate prescaler */
    [!"$AltPrescaler"!]
#endif
};

/** @brief    Channel configuration for Ftm module [!"$ModuleIdx"!] */
static const Ftm_Ocu_Ip_ChannelConfigType Ftm_Ocu_Ip_[!"$ModuleIdx"!]_ChannelConfig_PB[!"$VS_number"!][NUMBER_CONF_FTM_[!"$ModuleIdx"!]_CHANNEL[!"text:toupper($VS_number)"!]] = {
                    [!ENDCODE!]
                    [!VAR "AlreadyParsedModules"="concat($AlreadyParsedModules, $ModuleIdx)"!]
                [!ENDIF!]
                [!NOCODE!]
                [!VAR "MacChannelId" = "num:i(./OcuChannelId)"!]
                [!VAR "LocalHwChannel" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]
                [!LOOP "../../../OcuGeneral/OcuHwResourceConfig/*"!][!//
                    [!IF "((node:value(OcuChannelIsUsed) = 'true') and contains(OcuHwResourceId, 'FTM')) and (not(OcuIsrEnable = 'true'))"!][!//
                        [!IF "node:value(./OcuHwResourceId) = $LocalHwChannel"!]
                            [!VAR "MacChannelId" = "num:i(255)"!]
                        [!ENDIF!]
                    [!ENDIF!][!//
                [!ENDLOOP!][!//

                [!VAR "DefaultThreshold" = "num:i(OcuDefaultThreshold)"!]
                [!VAR "PinUsed" = "OcuOutputPinUsed"!]
                [!VAR "PinState" = "'(FTM_OCU_IP_OUTPUTDISABLED)'"!]
                [!VAR "PinAction" = "'((uint8)(FTM_OCU_IP_SET_DISABLE) << FTM_OCU_IP_PIN_ACTION_SHIFT)'"!]

                [!IF "($PinUsed = 'true')"!]
                    [!IF "(node:exists('OcuOutputPinDefaultState'))"!]
                        [!IF "(OcuOutputPinDefaultState = 'OCU_HIGH')"!]
                            [!VAR "PinState"= "'(1UL << FTM_OCU_IP_OUTPIN_USED_SHIFT) | (1UL << FTM_OCU_IP_PIN_STATE_SHIFT)'"!]
                        [!ELSE!]
                            [!VAR "PinState"= "'(1UL << FTM_OCU_IP_OUTPIN_USED_SHIFT)'"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "PinState"= "'(1UL << FTM_OCU_IP_OUTPIN_USED_SHIFT)'"!]
                    [!ENDIF!]

                    [!IF "(node:exists('OcuOutputPinAction'))"!]
                        [!IF "(OcuOutputPinAction = 'OCU_SET_HIGH')"!]
                            [!VAR "PinAction"= "'((uint8)(FTM_OCU_IP_SET_HIGH) << FTM_OCU_IP_PIN_ACTION_SHIFT)'"!]
                        [!ELSEIF "(OcuOutputPinAction = 'OCU_TOGGLE')"!]
                            [!VAR "PinAction"= "'((uint8)(FTM_OCU_IP_SET_TOGGLE) << FTM_OCU_IP_PIN_ACTION_SHIFT)'"!]
                        [!ELSEIF "(OcuOutputPinAction = 'OCU_DISABLE')"!]
                            [!VAR "PinAction"= "'((uint8)(FTM_OCU_IP_SET_DISABLE) << FTM_OCU_IP_PIN_ACTION_SHIFT)'"!]
                        [!ELSE!]
                            [!VAR "PinAction"= "'((uint8)(FTM_OCU_IP_SET_LOW) << FTM_OCU_IP_PIN_ACTION_SHIFT)'"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]

                [!IF "OcuChannelId = $VarChannelIndex"!]
                [!CODE!]
    /* [!"node:name(.)"!] -> [!"node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!] */
    {
        /** @brief  Ftm hardware channel */
        (uint8)[!"text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements),'_')[4]"!]U,
        /** @brief  Default threshold: [!"$DefaultThreshold"!] */
        (uint16)[!"concat('0x',text:toupper(text:split(num:inttohex($DefaultThreshold,4),'x')[2]))"!]U,
        /** @brief  Ftm Control Value */
        (uint8)
        (
        [!WS "12"!][!"$PinState"!] |    /* Output Pin Enable and default state */
        [!WS "12"!][!"$PinAction"!]     /* Output Pin default action */
        ),
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
        [!WS "8"!]/** @brief Ftm callback function name */[!CR!]
        [!WS "8"!]&Ocu_ProcessChannelNotification,[!CR!]
        [!WS "8"!]/** @brief Ftm callback param */[!CR!]
        [!WS "8"!](uint16)[!"$MacChannelId"!]U[!CR!]
#endif
    },
                [!ENDCODE!]
                [!ENDIF!]
            [!ENDNOCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]

    [!IF "contains($AlreadyParsedModules, $ModuleIdx) = true()"!]
        [!CODE!]
};
[!CR!]
/** @brief    IPL configuration structure for Ftm module [!"$ModuleIdx"!] */
const Ftm_Ocu_Ip_ModuleConfigType Ftm_Ocu_Ip_[!"$ModuleIdx"!]_ModuleCfgPB[!"$VS_number"!] = {
    /** @brief    Number of this FTM module */
    (uint8)[!"$ModuleIdx"!]U,
    /** @brief    Number of FTM channels configured for this FTM module */
    (uint8)NUMBER_CONF_FTM_[!"$ModuleIdx"!]_CHANNEL[!"text:toupper($VS_number)"!],
    /** @brief    Pointer to the channels configuration structure */
    &Ftm_Ocu_Ip_[!"$ModuleIdx"!]_ChannelConfig_PB[!"$VS_number"!],
    /** @brief    Pointer to the common module configuration structure */
    &Ftm_Ocu_Ip_[!"$ModuleIdx"!]_SpecificIpConfig_PB[!"$VS_number"!]
};
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]
[!ELSE!]
[!CODE!]
    /** @brief    No Ftm channel configured */
[!ENDCODE!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDNOCODE!]


#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]