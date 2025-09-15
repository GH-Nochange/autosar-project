[!AUTOSPACING!]
[!NOCODE!]
/**
*   @file    Gpt_Ipw_PluginMacros.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Gpt - Macros used to generate code template for GPT driver.
*   @details Macros used to generate code template for GPT driver.
*
*   @internal
*   @addtogroup gpt gpt_ipw
*
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm_Srtc_Lptmr_LPit
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
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

[!/* Avoid multiple inclusion */!]
[!IF "not(var:defined('GPT_IPW_PLUGIN_MACRO_M'))"!][!//
[!VAR "GPT_IPW_PLUGIN_MACRO_M" = "'true'"!][!//

[!VAR "GptEcucPartitionRefCount" = "num:i(count(as:modconf('Gpt')[1]/GptDriverConfiguration/GptEcucPartitionRef/*))"!]
[!IF "$GptEcucPartitionRefCount != 0 "!]
    [!VAR "GptEcucPartitionRefNum" = "$GptEcucPartitionRefCount"!]
[!ELSE!]
    [!VAR "GptEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
[!ENDIF!]

[!//This macros is used to build the configuration structure for a config set.
[!MACRO "CONVERT_PARTITION_TO_ID" , "currentPartition"!][!//
    [!VAR "OutRespectivePartitionId" = "0"!]
    [!IF "contains($currentPartition,'EcucPartition_One')"!]
        [!VAR "OutRespectivePartitionId"  = "1"!]
    [!ELSEIF "contains($currentPartition,'EcucPartition_Cinque')"!]
        [!VAR "OutRespectivePartitionId"  = "5"!]
    [!ELSE!]
        [!VAR "OutRespectivePartitionId"  = "substring-after($currentPartition, 'EcucPartition_')"!]
    [!ENDIF!]
[!ENDMACRO!][!// End of Macro GPT_VARIABLES
[!// MACRO for creating the mapping between hardware channels and logical channels
[!// need to be called in the context of each partition where $GptEcucPartitionRefName is available
[!MACRO "GPT_VARIABLES"!][!//
[!NOCODE!]
    [!VAR "MaximumCoreId" = "0"!]
    [!VAR "CurrentCoreId" = "0"!]
    [!VAR "OutRespectiveCoreId" = "0"!]
    [!VAR "OutNumGptChannelsUsingSRtc"  = "0"!]
    [!VAR "OutNumGptChannelsUsingLptmr"  = "0"!]
    [!VAR "OutNumGptChannelsUsingLPit"  = "0"!]
    [!VAR "OutNumGptChannelsUsingFtm"  = "0"!]
    [!VAR "OutNumGptChannels" = "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!]
    [!VAR "OutNumGptChannelsConfiguration" = "num:i(count(GptChannelConfiguration/*))"!]
    [!VAR "OutNumChannelInPartition"  = "0"!]
    [!VAR "OutNumInstancesInPartition"  = "0"!]
    [!VAR "OutNumInstances"  = "0"!]
    [!VAR "OutNumInstancesSRtc"  = "0"!]
    [!VAR "OutNumInstancesFtm"  = "0"!]
    [!VAR "OutNumInstancesLptmr"  = "0"!]
    [!VAR "OutNumInstancesLPit"  = "0"!]
    [!// Count channels and instances in each module that is using for current partition
    [!IF "$GptEcucPartitionRefCount != 0 "!]
        [!// Count instances
        [!LOOP "GptFtm/*"!]
            [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptFtmModule = node:current()/GptFtmModule) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!LOOP "GptLpit/*"!]
            [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptLpitModule = node:current()/GptLpitModule) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'SRTC') and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]

        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'LPTMR') and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
        [!// Count channels
        [!LOOP "GptChannelConfiguration/*"!]
            [!VAR "HardwareModule" = "./GptHwIp"!]
            [!LOOP "./GptChannelEcucPartitionRef/*"!]
                [!IF "node:value(.) = $GptEcucPartitionRefName"!]
                    [!//Update variables storing number of Gpt channels
                    [!IF "contains($HardwareModule,'FTM')"!]
                        [!VAR "OutNumGptChannelsUsingFtm" = "$OutNumGptChannelsUsingFtm + 1"!]
                    [!ELSEIF "contains($HardwareModule,'SRTC')"!]
                        [!VAR "OutNumGptChannelsUsingSRtc" = "$OutNumGptChannelsUsingSRtc + 1"!]
                    [!ELSEIF "contains($HardwareModule,'LPTMR')"!]
                        [!VAR "OutNumGptChannelsUsingLptmr" = "$OutNumGptChannelsUsingLptmr + 1"!]
                    [!ELSEIF "contains($HardwareModule,'LPIT')"!]
                        [!VAR "OutNumGptChannelsUsingLPit" = "$OutNumGptChannelsUsingLPit + 1"!]
                    [!ENDIF!]
                    [!VAR "OutNumChannelInPartition" = "$OutNumChannelInPartition + 1"!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDLOOP!]
        [!LOOP "../GptDriverConfiguration/GptEcucPartitionRef/*"!]
            [!VAR "GptPartRefName" = "node:value(.)"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "text:toupper($GptPartRefShortName)"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$GptPartRefName = node:value(OsAppEcucPartitionRef)"!]
                    [!SELECT "node:ref(OsApplicationCoreRef)"!]
                        [!IF "$GptPartRefName = $GptEcucPartitionRefName"!]
                            [!VAR "OutRespectiveCoreId" = "node:value(./EcucCoreId)"!]
                        [!ENDIF!]
                        [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]
                        [!IF "num:i($MaximumCoreId) < num:i($CurrentCoreId)"!]
                            [!VAR "MaximumCoreId" = "$CurrentCoreId"!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ELSE!]
        [!// TODO: Count instances

    [!VAR "OutNumInstancesFtm"  = "0"!]
    [!LOOP "GptChannelConfigSet/GptFtm/*"!]
        [!VAR "HardwareModule" = "./GptFtmModule"!]
        [!VAR "chUsed"  = "0"!]
            [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
                [!IF "contains(GptHwIp,'FTM')"!]
                    [!IF "node:value(node:ref(./GptModuleRef)/../../GptFtmModule) = $HardwareModule"!]
                        [!IF "$chUsed = 0"!]
                            [!VAR "OutNumInstancesFtm"  = "$OutNumInstancesFtm + 1"!]
                            [!VAR "chUsed"  = "1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "OutNumInstancesLPit"  = "0"!]
    [!LOOP "GptChannelConfigSet/GptLpit/*"!]
        [!VAR "HardwareModule" = "./GptLpitModule"!]
        [!VAR "chUsed"  = "0"!]
            [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
                [!IF "contains(GptHwIp,'LPIT')"!]
                    [!IF "node:value(node:ref(./GptModuleRef)/../../GptLpitModule) = $HardwareModule"!]
                        [!IF "$chUsed = 0"!]
                            [!VAR "OutNumInstancesLPit"  = "$OutNumInstancesLPit + 1"!]
                            [!VAR "chUsed"  = "1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
    [!ENDLOOP!]

    [!LOOP "GptChannelConfigSet/GptSRtc/*"!]
    [!VAR "HardwareModule" = "./GptSRtcModule"!]
    [!VAR "chUsed"  = "0"!]
    [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'SRTC')"!]
            [!IF "node:value(node:ref(./GptModuleRef)/GptSRtcModule) = $HardwareModule"!]
                    [!IF "$chUsed = 0"!]
                        [!VAR "OutNumInstancesSRtc"  = "$OutNumInstancesSRtc + 1"!]
                        [!VAR "chUsed"  = "1"!]
                    [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]

    [!LOOP "GptChannelConfigSet/GptLptmr/*"!]
    [!VAR "HardwareModule" = "./GptLptmrModule"!]
    [!VAR "chUsed"  = "0"!]
    [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'LPTMR')"!]
            [!IF "node:value(node:ref(./GptModuleRef)/GptLptmrModule) = $HardwareModule"!]
                    [!IF "$chUsed = 0"!]
                        [!VAR "OutNumInstancesLptmr"  = "$OutNumInstancesLptmr + 1"!]
                        [!VAR "chUsed"  = "1"!]
                    [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "OutNumInstances" = "$OutNumInstancesFtm + $OutNumInstancesSRtc + $OutNumInstancesLptmr + $OutNumInstancesLPit"!]

    [!LOOP "GptFtm/*"!]
        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptFtmModule = node:current()/GptFtmModule)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!LOOP "GptLpit/*"!]
        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptLpitModule = node:current()/GptLpitModule)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'SRTC')])"!]
        [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
    [!ENDIF!]

    [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'LPTMR')])"!]
        [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
    [!ENDIF!]

    [!VAR "OutNumChannelInPartition" = "num:i(count(GptChannelConfiguration/*))"!]
    [!// Count channels and instances
    [!LOOP "GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'FTM')"!]
            [!VAR "OutNumGptChannelsUsingFtm" = "$OutNumGptChannelsUsingFtm + 1"!]
        [!ELSEIF "contains(GptHwIp,'SRTC')"!]
            [!VAR "OutNumGptChannelsUsingSRtc" = "$OutNumGptChannelsUsingSRtc + 1"!]
        [!ELSEIF "contains(GptHwIp,'LPTMR')"!]
            [!VAR "OutNumGptChannelsUsingLptmr" = "$OutNumGptChannelsUsingLptmr + 1"!]
        [!ELSEIF "contains(GptHwIp,'LPIT')"!]
            [!VAR "OutNumGptChannelsUsingLPit" = "$OutNumGptChannelsUsingLPit + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro GPT_VARIABLES

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
/** @} */
[!ENDNOCODE!]
