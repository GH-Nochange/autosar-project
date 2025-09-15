[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('DPGA_REGOPERATIONS_M'))"!]
[!VAR "DPGA_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DPGA
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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup dpga_driver_config Dpga Driver Configuration
*   @{
*/

[!ENDNOCODE!][!//
[!AUTOSPACING!]
/* ----------------------------------------- IPL Configuration -----------------------------------------
* IPL - Dpga Config
* GenerationType='declaration_config' or 'declaration_callback' or 'definition_amplifier_config' or 'definition_config'
*/
[!MACRO "Dpga_Ip_Config" , "MacroGenerationType"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]

[!VAR "NumOfDpgaChannels"="num:i(count(DpgaChannel/*)-1)"!][!//
[!FOR "Unit" = "0" TO "num:i($NumOfDpgaChannels)"!][!//
    [!LOOP "DpgaChannel/*"!][!//
        [!IF "(DpgaChannelId = $Unit)"!][!//
            [!IF "$MacroGenerationType = 'declaration_config'"!]
[!CODE!]
/**
* @brief Dpga Ip Channel [!"DpgaChannelId"!] Config for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
extern const Dpga_Ip_ConfigType Dpga_Ip_Config[!"$postBuildVariantNameUnderscore"!];
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'declaration_callback'"!]
[!CODE!][!//
[!IF "(DpgaConfiguration/DpgaCallback != 'NULL_PTR') and (DpgaConfiguration/DpgaCallback != 'NULL') and (DpgaConfiguration/DpgaCallback != '')"!][!//
/**
* @brief Dpga Callback Function.
*/
extern void [!"DpgaConfiguration/DpgaCallback"!](Dpga_Ip_EventType Event);[!//
[!ENDIF!][!//
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'definition_amplifier_config'"!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(8)"!]
                    [!VAR "DpgaAmplGain" = "num:i(0)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(16)"!]
                    [!VAR "DpgaAmplGain" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(24)"!]
                    [!VAR "DpgaAmplGain" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(32)"!]
                    [!VAR "DpgaAmplGain" = "num:i(3)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(40)"!]
                    [!VAR "DpgaAmplGain" = "num:i(4)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(50)"!]
                    [!VAR "DpgaAmplGain" = "num:i(5)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(65)"!]
                    [!VAR "DpgaAmplGain" = "num:i(6)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_')) = num:i(80)"!]
                    [!VAR "DpgaAmplGain" = "num:i(7)"!]
                [!ENDIF!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(12)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(0)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(6)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(4)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_')) = num:i(2)"!]
                    [!VAR "DpgaOutCommonMode" = "num:i(3)"!]
                [!ENDIF!]
                [!IF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(200)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(1)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(100)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(2)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(50)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(3)"!]
                [!ELSEIF "num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_')) = num:i(0)"!]
                    [!VAR "DpgaInCommonModeCoarse" = "num:i(0)"!]
                [!ENDIF!]
[!CODE!][!//
/**
* @brief Amplifier configuration structure for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
static Dpga_Ip_AmplifierConfigType Dpga_Ip_AmplifierConfig[!"$postBuildVariantNameUnderscore"!] =
{
    [!"$DpgaAmplGain"!]U,    /* .AmplifierGain - amplify by [!"num:i(substring-after(DpgaConfiguration/DpgaAmplifierGain, 'GAIN_'))"!] */
    [!"$DpgaOutCommonMode"!]U,    /* .OutCommonModeVoltage - Vref / [!"num:i(substring-after(DpgaConfiguration/DpgaOutCommonModeVoltage, 'VREF_DIV_'))"!] */
    [!"DpgaConfiguration/DpgaOffset"!]U,    /* .AmplifierOffset - see RM for detailed description of this value significance */
    [!"$DpgaInCommonModeCoarse"!]U,    /* .InCommonModeCoarse - shift with [!"num:i(substring-after(DpgaConfiguration/DpgaInCommonModeCoarse, 'SHIFT_'))"!] uA current out of both inputs */
    [!"DpgaConfiguration/DpgaInCommonModeFine"!]U     /* .InCommonModeFine - see RM for detailed description of this value significance */
};
[!ENDCODE!][!//
            [!ELSEIF "$MacroGenerationType = 'definition_config'"!]
[!CODE!]
/**
* @brief Dpga configuration structure for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
const Dpga_Ip_ConfigType Dpga_Ip_Config[!"$postBuildVariantNameUnderscore"!] =
{
    &Dpga_Ip_AmplifierConfig[!"$postBuildVariantNameUnderscore"!],    /* .AmplifierConfig */
    [!"DpgaConfiguration/DpgaBlankingTimeDuration"!]U,    /* .BlankingTimeDuration */
    /* .BTTriggerStateArray */
    {
[!ENDCODE!][!//
                [!VAR "NumOfTriggers"="num:i(count(DpgaConfiguration/DpgaBlankingTimeTriggerList/*))"!][!//
                [!VAR "LoopIdx"="0"!][!//
                [!LOOP "DpgaConfiguration/DpgaBlankingTimeTriggerList/*"!][!//
                    [!VAR "LoopIdx" = "$LoopIdx + 1"!][!//
                    [!IF "substring-before(DpgaBTTriggerState, '_EDGE') = 'NO'"!]
                        [!VAR "BTTriggerState" = "num:i(0)"!]
                        [!VAR "BTTriggerStateText" = "'this trigger cannot start the BT counter'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'FALLING'"!]
                        [!VAR "BTTriggerState" = "num:i(1)"!]
                        [!VAR "BTTriggerStateText" = "'the falling edge of this trigger starts the BT counter from 0'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'RISING'"!]
                        [!VAR "BTTriggerState" = "num:i(2)"!]
                        [!VAR "BTTriggerStateText" = "'the rising edge of this trigger starts the BT counter from 0'"!]
                    [!ELSEIF "substring-before(DpgaBTTriggerState, '_EDGE') = 'BOTH'"!]
                        [!VAR "BTTriggerState" = "num:i(3)"!]
                        [!VAR "BTTriggerStateText" = "'both edges of this trigger start the BT counter from 0'"!]
                    [!ENDIF!]
[!CODE!][!//
        [!"$BTTriggerState"!]U[!IF "$LoopIdx < num:i($NumOfTriggers)"!],[!ENDIF!]    /* Trigger [!"num:i($LoopIdx)"!] - [!"$BTTriggerStateText"!] */
[!ENDCODE!][!//
                [!ENDLOOP!][!//
[!CODE!][!//
    },
[!IF "../../GeneralConfiguration/DpgaEnableVoltageMonitoring = 'true'"!][!//
#if (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING)
    (boolean)[!IF "DpgaConfiguration/DpgaEnableBipolarDetector = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],    /* .BipolarInputModeEnable */
    [!"DpgaConfiguration/DpgaLowDetectLimit"!]U,    /* .LowDetectLimit */
    [!"DpgaConfiguration/DpgaHighDetectLimit"!]U,    /* .HighDetectLimit */
    [!"DpgaConfiguration/DpgaLowDetectFilterDuration"!]U,    /* .LowDetectFilterDuration */
    [!"DpgaConfiguration/DpgaHighDetectFilterDuration"!]U,    /* .HighDetectFilterDuration */
#endif /* (STD_ON == DPGA_IP_ENABLE_VOLTAGE_MONITORING) */
[!ENDIF!][!//
[!IF "(DpgaConfiguration/DpgaCallback != 'NULL_PTR') and (DpgaConfiguration/DpgaCallback != 'NULL') and (DpgaConfiguration/DpgaCallback != '')"!][!//
    (Dpga_Ip_CallbackType)&[!"DpgaConfiguration/DpgaCallback"!]    /* .DpgaCallback */
[!ELSE!][!//
    NULL_PTR    /* .DpgaCallback */
[!ENDIF!][!//
};
[!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

/* IPL - Cfg Defines */
[!MACRO "Dpga_Ip_ConfigDef"!][!//

#define DPGA_IP_DEV_ERROR_DETECT                [!IF "GeneralConfiguration/DpgaIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_IP_TIMEOUT_TYPE                    ([!"GeneralConfiguration/DpgaTimeoutMethod"!])
#define DPGA_IP_TIMEOUT_VALUE                   ([!"GeneralConfiguration/DpgaTimeoutValue"!]U)
#define DPGA_IP_CONFIG_TYPE                      Dpga_Ip_ConfigType
#define DPGA_IP_VOLTAGE_MONITOR_SELF_TEST_API   [!IF "GeneralConfiguration/DpgaVoltageMonitorSelfTestApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_IP_AMPLIFIER_SELF_TEST_API         [!IF "GeneralConfiguration/DpgaAmplifierSelfTestApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/**
* @brief  If Voltage Monitoring is enbaled, this define is (STD_ON). Otherwise, this define is (STD_OFF).
*/
#define DPGA_IP_ENABLE_VOLTAGE_MONITORING       [!IF "GeneralConfiguration/DpgaEnableVoltageMonitoring"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief  Maximum number of Blanking Time triggers.
*/
#define DPGA_IP_BT_NUM_OF_TRIGGERS              (6U)

[!NOCODE!][!//
[!IF "GeneralConfiguration/DpgaAmplifierSelfTestApi"!]
    [!SELECT "node:ref(as:modconf('Dpga')[1]/GeneralConfiguration/DpgaAmplifierSelfTestAdcReference)"!][!//
        [!VAR "AdcMaxValue" = "num:i(bit:shl(2, num:i(substring-after(AdcHwUnitResolution, 'RESOLUTION_')) - 1) - 1)"!]
    [!ENDSELECT!][!//
[!ELSE!]
    [!VAR "AdcMaxValue" = "num:i(16383)"!]
[!ENDIF!]
    [!VAR "AmplifierSelfTestTolerance" = "num:i(GeneralConfiguration/DpgaAmplifierSelfTestTolerance)"!]

[!ENDNOCODE!][!//
#if (STD_ON == DPGA_IP_AMPLIFIER_SELF_TEST_API)
/**
* @brief  ADC instance.
*/
#define DPGA_IP_SELFTEST_ADC_INSTANCE_USED      ([!"num:i(substring-after(ecu:get('Dpga.Selftest.AdcInstanceName'), 'ADC'))"!]U)

/**
* @brief  ADC channel.
*/
#define DPGA_IP_SELFTEST_ADC_CHANNEL_USED       ([!"num:i(ecu:get('Dpga.Selftest.AdcChannelName'))"!]U)

/**
* @brief  The tolerance to check the result of ADC measurement.
*/
#define DPGA_IP_AMPLIFIER_SELFTEST_TOLERANCE    ([!"$AmplifierSelfTestTolerance"!]U)

/**
* @brief  The max value of Adc with selected resolution.
*/
#define DPGA_IP_SELFTEST_ADC_MAX_VALUE          ([!"$AdcMaxValue"!]U)

/**
* @brief  The gain array.
*/
#define DPGA_IP_GAIN_ARRAY                      {[!"normalize-space(ecu:get('Dpga.Selftest.GainArray.List'))"!]}

/**
* @brief  The offset array.
*/
#define DPGA_IP_OFFSET_ARRAY                    {[!"normalize-space(ecu:get('Dpga.Selftest.OffsetArray.List'))"!]}

/**
* @brief  Dpga max reference voltage in mV.
*/
#define DPGA_IP_MAX_REFERENCE_VOLTAGE           ([!"ecu:get('Dpga.Selftest.MaxReferenceVoltage')"!])

#endif /*STD_ON == DPGA_IP_AMPLIFIER_SELF_TEST_API*/

[!ENDMACRO!]

/* ----------------------------------------- HLD Configuration -----------------------------------------
* HLD - Cfg Defines
*/
[!MACRO "CDD_Dpga_ConfigDef"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!ENDNOCODE!][!//
#define DPGA_DEV_ERROR_DETECT                   [!IF "GeneralConfiguration/DpgaDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_VERSION_INFO_API                   [!IF "GeneralConfiguration/DpgaVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_VOLTAGE_MONITOR_SELF_TEST_API      [!IF "GeneralConfiguration/DpgaVoltageMonitorSelfTestApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_AMPLIFIER_SELF_TEST_API            [!IF "GeneralConfiguration/DpgaAmplifierSelfTestApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define DPGA_ENABLE_USER_MODE_SUPPORT           (STD_OFF)
#define DPGA_MULTIPARTITION_SUPPORT             [!IF "GeneralConfiguration/DpgaMultiPartitionSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "($VariantsNo <= 1) and (IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild')"!][!//
#define DPGA_PRECOMPILE_SUPPORT                 (STD_ON)
[!ELSE!][!//
#define DPGA_PRECOMPILE_SUPPORT                 (STD_OFF)
[!ENDIF!][!//
#define DPGA_CONFIG_TYPE                        DPGA_IP_CONFIG_TYPE

[!NOCODE!]
[!VAR "maxPartition" = "num:i(0)"!]
[!IF "node:value(GeneralConfiguration/DpgaMultiPartitionSupport)='true'"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!ENDIF!]
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!]
[!ENDNOCODE!]

/**
* @brief Total number of partitions configured in Ecu.
*/
#define DPGA_MAX_PARTITIONS                     ([!"num:i($maxPartition)"!]U)

#if (STD_OFF == DPGA_MULTIPARTITION_SUPPORT)
/**
* @brief Defines default CodeId value which is assigned to HWUnits, Sequences, Jobs and Channels in the case MultiPartition is not enabled.
*/
    #define DPGA_SPURIOUS_ID_U32                ((uint32)0UL)
#endif

#if (STD_ON == DPGA_MULTIPARTITION_SUPPORT)
    #define Dpga_GetUserID                      ((uint32)OsIf_GetUserId())
#else
    #define Dpga_GetUserID                      DPGA_SPURIOUS_ID_U32
#endif

#define Dpga_GetID                              Dpga_GetUserID

/**
* @brief  Dpga channel name to logic channel id mapping
*/
[!NOCODE!][!//
[!LOOP "DpgaChannel/*"!][!//
[!CODE!][!//
#define [!"@name"!]                   ([!"node:value(DpgaChannelId)"!]U)
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

#ifdef DPGA_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT)
        /**
        * @brief  This define indicate that the ipv Dpga is protected by register protection.
        */
        #define DPGA_REG_PROT_AVAILABLE
    #endif /* (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifdef DPGA_ENABLE_USER_MODE_SUPPORT */

/**
* @brief  perform checking marco MCAL_ENABLE_USER_MODE_SUPPORT available or not.
*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running DPGA in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == DPGA_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ENDMACRO!]

/* HLD Config
* GenerationType='definition' or 'declaration' or 'definition_local' or 'Dpga_ConfigurationInfo'
*/
[!MACRO "GetConfigStructName"!][!//
[!NOCODE!]
    [!VAR "Mac_CtrlConfigStructureName" = "'NULL_PTR'"!]
    [!VAR "Mac_PostBuildVariantNameUnderscore" = "string(null)"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "Mac_PostBuildVariantNameUnderscore" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]
    [!VAR "Mac_CtrlConfigStructureName" = "concat('&Dpga_Ip_Config', $Mac_PostBuildVariantNameUnderscore, '')"!]
    [!CODE!][!"$Mac_CtrlConfigStructureName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "CDD_Dpga_Config" , "MacroGenerationType"!][!//
[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]

[!IF "$MacroGenerationType = 'declaration'"!]

[!CODE!][!//
/* Dpga config structure to be used by Dpga Init function */
[!ENDCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!] [!//
    [!IF "var:defined('postBuildVariant')"!][!//
        [!VAR "Mac_postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
        [!CODE!]#define DPGA_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!VAR "Mac_postBuildVariantNameUnderscore" = "string(null)"!][!//
        [!CODE!]#define DPGA_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!][!//
    [!VAR "DpgaConfiguredPartitions" = "num:i((count(GeneralConfiguration/DpgaEcucPartitionRef/*)))"!][!//
    [!IF "$DpgaConfiguredPartitions > 0"!][!//
        [!LOOP "GeneralConfiguration/DpgaEcucPartitionRef/*"!][!//
            [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
            [!WS "8"!][!CODE!]extern const Dpga_ConfigType Dpga_Config[!"$Mac_postBuildVariantNameUnderscore"!]_[!"$currentPartition"!]; \[!CR!][!ENDCODE!]
        [!ENDLOOP!][!//
    [!ELSE!][!//
            [!WS "8"!][!CODE!]extern const Dpga_ConfigType Dpga_Config[!"$Mac_postBuildVariantNameUnderscore"!];[!ENDCODE!]
    [!ENDIF!][!//
[!ENDIF!]

[!ELSEIF "$MacroGenerationType = 'Dpga_ConfigurationInfo'"!]
    [!IF "node:exists(as:modconf('Dpga')[1]/GeneralConfiguration/DpgaMultiPartitionSupport)"!]
        [!VAR "MultiCorePartitionEnable" = "as:modconf('Dpga')[1]/GeneralConfiguration/DpgaMultiPartitionSupport"!]
    [!ENDIF!]

    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!ENDIF!]

    [!VAR "DpgaConfiguredPartitions" = "num:i(count(GeneralConfiguration/DpgaEcucPartitionRef/*))"!]
    [!VAR "TotalPartition" = "num:i(count(GeneralConfiguration/DpgaEcucPartitionRef/*))"!]

    [!IF "$DpgaConfiguredPartitions = 0"!]
        [!VAR "TotalPartition" = "num:i(1)"!]
    [!ENDIF!]

    [!FOR "PartitionCount" = "1" TO "$TotalPartition"!]
        [!IF "$MultiCorePartitionEnable = 'true'"!]
            [!VAR "CurrentPartition" = "concat('_',node:name(node:ref(GeneralConfiguration/DpgaEcucPartitionRef/*[num:i($PartitionCount)])))"!]
        [!ELSE!]
            [!VAR "CurrentPartition" = "string(null)"!]
        [!ENDIF!]
[!CODE!]
/** Compiler_Warning: In some cases, the partition configuration may not be used by the application. */
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!]static [!ENDIF!] const Dpga_ConfigType Dpga_Config[!IF "(IMPLEMENTATION_CONFIG_VARIANT ='VariantPostBuild') or (variant:size()>1)"!][!"$postBuildVariantNameUnderscore"!][!ENDIF!][!"$CurrentPartition"!]=
{
[!ENDCODE!]
    [!IF "$MultiCorePartitionEnable = 'true'"!]
        [!VAR "CurrentPName" = "node:value(GeneralConfiguration/DpgaEcucPartitionRef/*[num:i($PartitionCount)])"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "$CurrentPName = node:value(./OsAppEcucPartitionRef)"!][!//
                [!IF "node:exists(as:modconf('Dpga')[1]/GeneralConfiguration/DpgaMultiPartitionSupport)"!]
                    [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                [!CODE!]    (uint32)[!"num:i(node:pos(.))"!]U, /* DpgaCorePartitionUse*/[!ENDCODE!]
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
                [!BREAK!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ELSE!]
        [!WS "4"!][!CODE!](uint32)DPGA_SPURIOUS_ID_U32, /* DpgaCorePartitionUse */[!ENDCODE!]
    [!ENDIF!]
[!CODE!]
    [!CALL "GetConfigStructName"!], /* Dpga_pIpConfig */
};
[!ENDCODE!]
    [!ENDFOR!]
    [!VAR "numPartition" = "0"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
        [!VAR "numPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
    [!ENDIF!]

    [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' and (variant:size() <= 1))"!]
        [!IF "$MultiCorePartitionEnable = 'true'"!]
[!CODE!]
const Dpga_ConfigType * const Dpga_ConfigVariantPredefined[[!"num:i($numPartition)"!]]=
{
            [!NOCODE!]
                [!VAR "MaxCorePartitionId"="0"!]
                [!IF "node:exists(as:modconf('Dpga')[1]/GeneralConfiguration/DpgaMultiPartitionSupport)"!]
                    [!LOOP "as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!][!//
                        [!IF "$MaxCorePartitionId < node:pos(.)"!]
                            [!VAR "MaxCorePartitionId"="node:pos(.)"!]
                        [!ENDIF!]
                    [!ENDLOOP!][!//
                [!ENDIF!]
                [!VAR "MacNoPartitions" = "0"!][!//
                [!FOR "DpgaCorePartitionIdCount"="0" TO "$MaxCorePartitionId"!]
                    [!VAR "CorePartitionIsMatch" = "'false'"!]
                    [!VAR "Partitionname" = "0"!][!//
                    [!LOOP "GeneralConfiguration/DpgaEcucPartitionRef/*"!]
                        [!VAR "MacPartNo" = "node:name(node:ref(.))"!]
                        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                            [!IF "$MacPartNo = node:name(node:ref(./OsAppEcucPartitionRef))"!]
                                [!IF "node:exists(as:modconf('Dpga')[1]/GeneralConfiguration/DpgaMultiPartitionSupport)"!]
                                    [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                                        [!IF "num:i($DpgaCorePartitionIdCount) = num:i(node:pos(.))"!]
                                            [!VAR "CorePartitionIsMatch" = "'true'"!]
                                            [!VAR "Partitionname" = "$MacPartNo"!]
                                        [!ENDIF!]
                                    [!ENDSELECT!]
                                [!ENDIF!]
                                [!BREAK!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDLOOP!][!//
                    [!IF "$CorePartitionIsMatch = 'true'"!]
[!CODE!]
    &Dpga_Config_[!"$Partitionname"!][!IF "$MacNoPartitions < num:i($MaxCorePartitionId)"!],[!VAR "MacNoPartitions" = "$MacNoPartitions + 1"!][!ENDIF!]
[!ENDCODE!]
                    [!ELSE!]
[!CODE!]
    NULL_PTR[!IF "$MacNoPartitions < num:i($MaxCorePartitionId)"!],[!VAR "MacNoPartitions" = "$MacNoPartitions + 1"!][!ENDIF!]
[!ENDCODE!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDNOCODE!]
};
[!ENDCODE!]
        [!ELSE!]
[!CODE!]
const Dpga_ConfigType * const Dpga_ConfigVariantPredefined[DPGA_MAX_PARTITIONS]=
{
    &Dpga_Config
};
[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//


/** @} */
[!ENDIF!]
