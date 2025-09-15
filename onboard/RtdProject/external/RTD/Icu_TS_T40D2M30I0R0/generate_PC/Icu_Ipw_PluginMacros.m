[!NOCODE!]
[!AUTOSPACING!]
/*==================================================================================================
*   Project RTD AUTOSAR 4.7
*   Patform CORTEXM
*   Peripheral Ftm Lpit Lptmr Port_Ci LpCmp
*   Dependencies none
*  
*   ARVersion 4.7.0
*   ARRevision ASR_REL_4_7_REV_0000
*   ARConfVariant
*   SWVersion 3.0.0
*   BuildVersion S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530
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
*   @file    Icu_Ipw_PluginMacros.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Icu - plugin check.
*   @details Version checks.
==================================================================================================*/

[!VAR "IcuEcucPartitionRefCount" = "num:i(count(as:modconf('Icu')[1]/IcuGeneral/IcuEcucPartitionRef/*))"!][!//
[!IF "$IcuEcucPartitionRefCount != 0 "!][!//
    [!VAR "IcuEcucPartitionRefNum" = "$IcuEcucPartitionRefCount"!][!//
[!ELSE!]
    [!VAR "IcuEcucPartitionRefNum" = "1"!][!//
[!ENDIF!]
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!][!//
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!][!//
[!ENDIF!]

[!// MACRO for creating the mapping between hardware channels and logical channels
[!// need to be called in the context of each partition where $IcuEcucPartitionRefName is available 
[!MACRO "ICU_VARIABLES"!][!//
[!NOCODE!]
    [!VAR "MaximumPartitionId" = "0"!][!//
    [!VAR "CurrentPartitionId" = "0"!][!//
    [!VAR "OutRespectivePartitionId" = "0"!][!//
    [!VAR "OutNumIcuChannelsUsingFtm"  = "0"!][!//
    [!VAR "OutNumIcuChannelsUsingLpit" = "0"!][!//
    [!VAR "OutNumIcuChannelsUsingLptmr" = "0"!][!//
    [!VAR "OutNumIcuChannelsUsingPort" = "0"!][!//
    [!VAR "OutNumIcuChannelsUsingCmp" = "0"!][!//
    [!VAR "OutNumIcuChannels" = "num:i(count(IcuChannel/*))"!][!//
    [!VAR "OutNumChannelInPartition"  = "0"!][!//
    [!VAR "OutNumInstancesInPartition"  = "0"!][!//
    [!// Count channels and instances in each module that is using for current partition
    [!IF "$IcuEcucPartitionRefCount != 0 "!][!//
        [!// Count instances
        [!LOOP "IcuFtm/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuFtmModule = node:current()/IcuFtmModule) and (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLpit/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuLpitModule = node:current()/IcuLpitModule) and (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLptmr/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuLptmrModule = node:current()/IcuLptmrModule) and (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuPort/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuPortModule = node:current()/IcuPortModule) and (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLpCmp/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuCmpInstanceNumber = node:current()/IcuCmpInstanceNumber) and (node:value(./IcuChannelEcucPartitionRef/*[1]) = $IcuEcucPartitionRefName)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!// Count channels
        [!LOOP "IcuChannel/*"!][!//
            [!VAR "HardwareModule" = "node:path(node:ref(./IcuChannelRef))"!][!//
            [!LOOP "./IcuChannelEcucPartitionRef/*"!][!//
                [!IF "node:value(.) = $IcuEcucPartitionRefName"!][!//
                    [!//Update variables storing number of Icu channels using either FTM, Lpit, Lptrm or Port Ci
                    [!IF "contains($HardwareModule,'IcuFtm')"!][!//
                        [!VAR "OutNumIcuChannelsUsingFtm" = "$OutNumIcuChannelsUsingFtm + 1"!][!//
                    [!ELSEIF "contains($HardwareModule,'IcuLptmr')"!][!//
                        [!VAR "OutNumIcuChannelsUsingLptmr" = "$OutNumIcuChannelsUsingLptmr + 1"!][!//
                    [!ELSEIF "contains($HardwareModule,'IcuPort')"!][!//
                        [!VAR "OutNumIcuChannelsUsingPort" = "$OutNumIcuChannelsUsingPort + 1"!][!//
                    [!ELSEIF "contains($HardwareModule,'IcuLpit')"!][!//
                        [!VAR "OutNumIcuChannelsUsingLpit" = "$OutNumIcuChannelsUsingLpit + 1"!][!//
                    [!ELSEIF "contains($HardwareModule,'IcuLpCmp')"!][!//
                        [!VAR "OutNumIcuChannelsUsingCmp" = "$OutNumIcuChannelsUsingCmp + 1"!][!//
                    [!ENDIF!]
                    [!VAR "OutNumChannelInPartition" = "$OutNumChannelInPartition + 1"!][!//
                [!ENDIF!]
            [!ENDLOOP!]
            [!// Validation for DMA source
            [!IF "((IcuMeasurementMode = 'ICU_MODE_TIMESTAMP') or (IcuMeasurementMode = 'ICU_MODE_SIGNAL_MEASUREMENT')) and IcuDMAChannelEnable = 'true'"!][!//
                [!IF "node:exists(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType)"!][!/* Validation for DMA source*/!]
                    [!IF "not(contains(node:value(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux0HwRequest), 'DISABLED'))"!][!//
                        [!IF "substring-after(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux0HwRequest,'DMA_IP_REQ_MUX0_')!=concat('FTM', num:i(node:value(node:ref(IcuChannelRef)/../../IcuFtmModule)), '_CH', num:i(node:value(node:ref(IcuChannelRef)/IcuFtmChannel)))"!][!//
                            [!ERROR!] From variant "[!"variant:name( )"!]",Dma Source current is "[!"node:value(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux0HwRequest)"!]" which shall be "[!"concat('DMA_IP_REQ_MUX0_FTM', num:i(node:value(node:ref(IcuChannelRef)/../../IcuFtmModule)), '_CH', num:i(node:value(node:ref(IcuChannelRef)/IcuFtmChannel)))"!]" [!ENDERROR!]
                        [!ENDIF!]
                    [!ELSEIF "not(contains(node:value(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux1HwRequest), 'DISABLED'))"!][!//
                        [!IF "substring-after(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux1HwRequest,'DMA_IP_REQ_MUX1_')!=concat('FTM', num:i(node:value(node:ref(IcuChannelRef)/../../IcuFtmModule)), '_CH', num:i(node:value(node:ref(IcuChannelRef)/IcuFtmChannel)))"!][!//
                            [!ERROR!] From variant "[!"variant:name( )"!]",Dma Source current is "[!"node:value(node:ref(IcuDMAChannelRef)/dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux1HwRequest)"!]" which shall be "[!"concat('DMA_IP_REQ_MUX1_FTM', num:i(node:value(node:ref(IcuChannelRef)/../../IcuFtmModule)), '_CH', num:i(node:value(node:ref(IcuChannelRef)/IcuFtmChannel)))"!]" [!ENDERROR!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!ERROR!] From variant "[!"variant:name( )"!]", DMAMUX Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!]
                    [!ENDIF!]
                [!ELSE!]
                    [!ERROR!] From variant "[!"variant:name( )"!]", DMAMUX Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "../IcuGeneral/IcuEcucPartitionRef/*"!][!//
            [!VAR "IcuPartRefName" = "node:value(.)"!][!//
            [!VAR "IcuPartRefShortName" = "substring-after($IcuPartRefName, '/')"!][!//
            [!VAR "IcuPartRefShortName" = "substring-after($IcuPartRefShortName, '/')"!][!//
            [!VAR "IcuPartRefShortName" = "substring-after($IcuPartRefShortName, '/')"!][!//
            [!VAR "IcuPartRefShortName" = "substring-after($IcuPartRefShortName, '/')"!][!//
            [!VAR "IcuPartRefShortName" = "text:toupper($IcuPartRefShortName)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                    [!IF "$IcuPartRefName = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                            [!IF "$IcuPartRefName = $IcuEcucPartitionRefName"!][!//
                                [!VAR "OutRespectivePartitionId" = "node:pos(.)"!][!//
                            [!ENDIF!][!//
                            [!VAR "CurrentPartitionId" = "node:pos(.)"!][!//
                            [!IF "num:i($MaximumPartitionId) < num:i($CurrentPartitionId)"!][!//
                                [!VAR "MaximumPartitionId" = "$CurrentPartitionId"!][!//
                            [!ENDIF!][!//
                        [!ENDSELECT!][!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ELSE!]     
        [!LOOP "IcuFtm/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuFtmModule = node:current()/IcuFtmModule)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLpit/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuLpitModule = node:current()/IcuLpitModule)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLptmr/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuLptmrModule = node:current()/IcuLptmrModule)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuPort/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/../../IcuPortModule = node:current()/IcuPortModule)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!LOOP "IcuLpCmp/*"!][!//
            [!IF "node:exists(../../IcuChannel/*[(node:refs(./IcuChannelRef)/IcuCmpInstanceNumber = node:current()/IcuCmpInstanceNumber)])"!][!//
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
        [!VAR "OutNumChannelInPartition" = "num:i(count(IcuChannel/*))"!][!//
        [!// Count channels and instances
        [!LOOP "IcuChannel/*"!][!//
            [!IF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuFtm')"!][!//
                [!VAR "OutNumIcuChannelsUsingFtm" = "$OutNumIcuChannelsUsingFtm + 1"!][!//
            [!ELSEIF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuLptmr')"!][!//
                [!VAR "OutNumIcuChannelsUsingLptmr" = "$OutNumIcuChannelsUsingLptmr + 1"!][!//
            [!ELSEIF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuLpit')"!][!//
                [!VAR "OutNumIcuChannelsUsingLpit" = "$OutNumIcuChannelsUsingLpit + 1"!][!//
            [!ELSEIF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuPort')"!][!//
                [!VAR "OutNumIcuChannelsUsingPort" = "$OutNumIcuChannelsUsingPort + 1"!][!//
            [!ELSEIF "contains(node:path(node:ref(./IcuChannelRef)), 'IcuLpCmp')"!][!//
                [!VAR "OutNumIcuChannelsUsingCmp" = "$OutNumIcuChannelsUsingCmp + 1"!][!//
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro ICU_VARIABLES


[!// MACRO for creating the mapping between channels and channel Index in each partition
[!MACRO "ICU_GENERATE_CHANNEL_INDEX_MAPPING","VARIANT"!][!//
[!NOCODE!]
    [!FOR "PartitionIdx" = "1" TO "$IcuEcucPartitionRefNum"!][!//
        [!IF "$IcuEcucPartitionRefCount != 0 "!][!//
            [!VAR "PartitionIndex" = "node:name(node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)]))"!][!//
            [!VAR "IcuEcucPartitionRefName" = "node:value(IcuGeneral/IcuEcucPartitionRef/*[num:i($PartitionIdx)])"!][!//
        [!ENDIF!]
        [!CALL "ICU_VARIABLES"!][!//
        [!SELECT "IcuConfigSet"!][!//
            [!VAR "NumIcuChannels" = "num:i(count(IcuChannel/*))"!][!//
[!CODE!]/*[!CR!][!ENDCODE!]
[!CODE!]*   @brief Translation LUT for Logical channel number to Partition Configuration indexed location[!CR!][!ENDCODE!]
[!CODE!]*/[!CR!][!ENDCODE!]
[!CODE!]static const uint8 Icu_ChIndexMap_[!"$VARIANT"!][!IF "$IcuEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"$NumIcuChannels"!]U] = [!CR!]{[!CR!][!ENDCODE!]
            [!VAR "Index" = "0"!][!//
            [!FOR "Idx" = "0" TO "$NumIcuChannels - 1"!][!//
                [!IF "$IcuEcucPartitionRefCount != 0 "!][!//
                    [!LOOP "./IcuChannel/*"!][!//
                        [!IF "num:i($Idx)=num:i(IcuChannelId)"!][!//
                            [!VAR "Found" = "'false'"!][!//
                            [!LOOP "./IcuChannelEcucPartitionRef/*"!][!//
                                [!IF "node:value(.) = $IcuEcucPartitionRefName"!][!//
                                    [!VAR "Found" = "'true'"!][!//
                                [!ENDIF!]
                            [!ENDLOOP!]
                            [!IF "$Found='false'"!][!//
[!CODE!][!WS "4"!]255U[!IF "$Idx < $NumIcuChannels - 1"!],[!ENDIF!]    /* No channel */[!CR!][!ENDCODE!]
                            [!ELSEIF "$Found='true'"!][!//
[!CODE!][!WS "4"!][!"num:i($Index)"!]U[!IF "$Idx < $NumIcuChannels - 1"!],[!ENDIF!][!CR!][!ENDCODE!]
                                [!VAR "Index" = "$Index + 1"!][!//
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ELSE!]
[!CODE!][!WS "4"!][!"num:i($Idx)"!]U[!IF "$Idx < $NumIcuChannels - 1"!],[!ENDIF!][!CR!][!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]};[!ENDCODE!]
        [!ENDSELECT!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!]
[!ENDNOCODE!]