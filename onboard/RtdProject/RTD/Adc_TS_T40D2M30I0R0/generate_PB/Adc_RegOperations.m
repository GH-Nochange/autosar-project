[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_REGOPERATIONS_M'))"!]
[!VAR "ADC_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
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
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup adc_driver_config Adc Driver Configuration
*   @{
*/

[!ENDNOCODE!][!//
[!AUTOSPACING!]

[!MACRO "Adc_Group_Config"!][!//
[!NOCODE!][!//

[!MACRO "BuildNotification" , "Notification"!][!//
[!NOCODE!][!//
    [!CODE!][!IF "$Notification != 'NULL_PTR'"!]&[!ENDIF!][!"$Notification"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
        [!VAR "MaxPartitionCfg"="num:i(count(AdcGeneral/AdcEcucPartitionRef/*))"!][!//
    [!ELSE!][!//
        [!VAR "MaxPartitionCfg"="1"!][!//
    [!ENDIF!][!//

    [!FOR "Partition" = "0" TO "num:i($MaxPartitionCfg) - 1"!][!//
        [!VAR "loopGroupPartition"="0"!][!//
        [!VAR "maxGroupInPartition"="0"!][!//
        [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
            [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcGeneral/AdcEcucPartitionRef/*[@index = $Partition],'/'),'/'),'/'),'/')"!][!//
            [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
                [!IF "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!]
                    [!VAR "maxGroupInPartition"="$maxGroupInPartition + num:i(count(AdcGroup/*))"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ELSE!][!//
            [!VAR "maxGroupInPartition"="$maxGroupInPartition + num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!][!//
        [!ENDIF!][!//
        [!VAR "EnableCHDisableCHIndex" ="0"!][!//
        [!CODE!][!//

/**
* @brief          Definition of all ADC groups for configuration variant[!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!] [!"$CurrentPartition"!][!ENDIF!].
*/
static const Adc_GroupConfigurationType Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][] =
{
[!ENDCODE!][!//
        [!VAR "numGroup" = "num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1)"!][!//
        [!FOR "LoopVar" = "0" TO "$numGroup"!][!//
            [!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
                [!VAR "HWUnitPartition"="0"!][!//
                [!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!IF "substring-after(substring-after(substring-after(substring-after(../../AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!][!//
                        [!VAR "HWUnitPartition"="1"!][!//
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!VAR "HWUnitPartition"="2"!][!//
                [!ENDIF!][!//

                [!IF "(AdcGroupId = $LoopVar) and ($HWUnitPartition > 0)"!][!//
                    [!VAR "loopGroupPartition" = "$loopGroupPartition + 1"!][!//
                    [!VAR "AdcTemp_Ch" = "0"!]
                    [!VAR "AdcChanGroup0" = "0"!]
                    [!VAR "AdcChanGroup1" = "0"!]
                    [!VAR "AdcChanGroup2" = "0"!]
                    [!VAR "AdcWer0" = "0"!]
                    [!VAR "AdcWer1" = "0"!]
                    [!VAR "AdcWer2" = "0"!]
                    [!VAR "FirstDmaCh" = "255"!]
                    [!VAR "LastDmaCh" = "0"!]
                    [!VAR "PreFlag" = "0"!]

                    [!LOOP "AdcGroupDefinition/*"!]
                        [!VAR "CurrAdcChannel" = "."!]
                        [!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!]
                        [!LOOP "../../../../AdcChannel/*"!]

                            [!IF "$CurrAdcChannel1 = @name"!]
                                [!IF "contains(AdcChannelName,'ADCH')"!]
                                    [!VAR "AdcTemp_Ch" = "substring-after(AdcChannelName,'ADCH')"!]

                                    [!IF "$AdcTemp_Ch >= $LastDmaCh"!]
                                        [!VAR "LastDmaCh" = "$AdcTemp_Ch"!]
                                    [!ENDIF!]

                                    [!IF "$AdcTemp_Ch <= $FirstDmaCh"!]
                                        [!VAR "FirstDmaCh" = "$AdcTemp_Ch"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDLOOP!]

                    [!IF "(../../../../../AdcGeneral/AdcGrpNotifCapability = 'true') and (node:exists(AdcNotification))"!][!//
                        [!VAR "AdcNotificationString"!][!CALL "BuildNotification" , "Notification" = "node:value(AdcNotification)"!][!ENDVAR!]
                    [!ELSE!]
                        [!VAR "AdcNotificationString" = "'NULL_PTR'"!]
                    [!ENDIF!][!//

                    [!IF "(../../../../../AutosarExt/AdcEnableInitialNotification = 'true')"!][!//
                        [!VAR "AdcExtraNotificationString"!][!CALL "BuildNotification" , "Notification" = "node:value(AdcExtraNotification)"!][!ENDVAR!]
                    [!ELSE!]
                        [!VAR "AdcExtraNotificationString" = "'NULL_PTR'"!]
                    [!ENDIF!][!//

                    [!IF "(../../../../../AutosarExt/AdcEnableDmaErrorNotification = 'true')"!][!//
                        [!VAR "AdcDmaErrorNotificationString"!][!CALL "BuildNotification" , "Notification" = "node:value(AdcDmaErrorNotification)"!][!ENDVAR!]
                    [!ELSE!]
                        [!VAR "AdcDmaErrorNotificationString" = "'NULL_PTR'"!]
                    [!ENDIF!][!//

                    [!IF "AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!]
                        [!VAR "HwTriggerString"!][!"concat('PDB_ADC_IP_', node:ref(AdcGroupHwTriggerSource)/AdcHwTrigSrc)"!][!ENDVAR!]
                    [!ELSE!]
                        [!VAR "HwTriggerString" = "'PDB_ADC_IP_SOFTWARE_TRIGGER'"!]
                    [!ENDIF!]
[!CODE!][!//
    /**< @brief Group[!"AdcGroupId"!] -- Logical Unit Id [!"../../AdcLogicalUnitId"!] -- Hardware Unit [!"../../AdcHwUnitId"!] */
    {
        /**< @brief Index of group */
        [!"AdcGroupId"!]U, /* GroupId */
        /**< @brief ADC Logical Unit Id that the group belongs to */
        (Adc_HwUnitType)[!"../../AdcLogicalUnitId"!], /* AdcLogicalUnitId */
        /**< @brief Access mode */
        [!"AdcGroupAccessMode"!], /* AccessMode */
        /**< @brief Conversion mode */
        [!"AdcGroupConversionMode"!], /* Mode */
        /**< @brief Conversion type */
        [!"AdcGroupConversionType"!], /* Type */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        [!IF "(../../../../../AdcGeneral/AdcPriorityImplementation != 'ADC_PRIORITY_NONE') and (node:exists(AdcGroupPriority))"!](Adc_GroupPriorityType)ADC_GROUP_PRIORITY([!"AdcGroupPriority"!]),[!ELSE!](Adc_GroupPriorityType)ADC_GROUP_PRIORITY,[!ENDIF!] /* Priority */
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART, /* eReplacementMode */
        /**< @brief Trigger source configured */
        [!"AdcGroupTriggSrc"!], /* TriggerSource */
#if (STD_ON == ADC_HW_TRIGGER_API)
[!ENDCODE!]
[!CODE!][!//
        /**< @brief Hardware trigger source for the group */
        [!"$HwTriggerString"!], /* HwTriggerSource */
        /**< @brief Hardware trigger signal */
        [!IF "(../../../../../AdcGeneral/AdcHwTriggerApi = 'true') and (AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW') and (node:exists(AdcHwTrigSignal))"!][!"AdcHwTrigSignal"!],[!ELSE!]ADC_HW_TRIG_RISING_EDGE,[!ENDIF!] /* eTriggerEdge */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
        [!"$AdcNotificationString"!], /* Notification */
#endif /* (STD_ON == ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
        [!"$AdcExtraNotificationString"!], /* ExtraNotification */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#if defined(ADC_DMA_ERROR_SUPPORTED)
        /**< @brief DMA error notification function */
        [!"$AdcDmaErrorNotificationString"!], /* DmaErrorNotification */
#endif /* (ADC_DMA_ERROR_SUPPORTED) */
        /**< @brief Group Streaming Buffer Mode */
        [!"AdcStreamingBufferMode"!], /* BufferMode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)[!IF "node:fallback(AdcEnableChDisableChGroup,'false') = 'true'"!][!"num:i($EnableCHDisableCHIndex)"!][!VAR "EnableCHDisableCHIndex" = "$EnableCHDisableCHIndex + 1"!][!ELSE!]ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX[!ENDIF!], /* EnableChDisableChGroupIndex */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES([!"AdcStreamingNumSamples"!]), /* NumSamples */
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        /**< @brief Arrange the adc results as multiple sets of group result buffer */
        (boolean)[!IF "(../../../../../AutosarExt/AdcEnableGroupStreamingResultReorder = 'true') and (AdcStreamResultGroup = 'true') and (AdcGroupAccessMode = 'ADC_ACCESS_MODE_STREAMING')"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* StreamResultGroupMultiSets */
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        /**< @brief Channels assigned to the group*/
        Adc_Group[!"AdcGroupId"!]_Assignment_[!"num:i(substring-after(../../AdcHwUnitId, 'ADC'))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* AssignmentPtr */
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS, /* AssignedChannelCount */
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"num:i($LastDmaCh)"!])), /* LastCh */
        /**< @brief First Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"num:i($FirstDmaCh)"!])), /* FirstCh */
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)[!IF "AdcWithoutInterrupts"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!], /* AdcWithoutInterrupt */
        /**< @brief Enables or Disables configuring external DMA channel in the group */
        (uint8)[!IF "AdcExtDMAChanEnable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!], /* AdcExtDMAChanEnable */
        /**< @brief When true, disables completely DMA configuration done by ADC driver for the group */
        (boolean)[!IF "AdcWithoutDma"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* AdcWithoutDma */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
        /**< @brief Enables or Disables the ADC optimize DMA streaming groups feature */
        (boolean)[!IF "AdcEnableOptimizeDmaStreamingGroups"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* AdcOptimizeDmaStream */
        /**< @brief Enable/disable half interrupt for group with optimize DMA streaming groups */
        (boolean)[!IF "AdcEnableHalfInterrupt"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* HalfInterrupt */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)[!IF "node:exists(node:refs(AdcGroupDefinition/*)/AdcChannelLimitCheck) and (node:refs(AdcGroupDefinition/*)/AdcChannelLimitCheck = 'true')"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* AdcGroupLimitcheck */
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
        &AdcIpwGroupConfig_[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] /* AdcIpwGroupConfigPtr */
    }[!IF "$loopGroupPartition < num:i($maxGroupInPartition)"!],[!ENDIF!]
[!ENDCODE!][!//
                [!ENDIF!][!//[!IF "(AdcGroupId = $LoopVar) and ($HWUnitPartition > 0)"!][!//
            [!ENDLOOP!][!//[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
        [!ENDFOR!][!//[!FOR "LoopVar" = "0" TO "$numGroup"!][!//
        [!CODE!][!//
};
[!ENDCODE!][!//
[!IF "$Partition < (num:i($MaxPartitionCfg) - 1)"!]
[!CODE!]
[!ENDCODE!][!//
[!ENDIF!][!//
    [!ENDFOR!][!//[!FOR "Partition" = "0" TO "num:i($MaxPartitionCfg) - 1"!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_GroupIdToIndexMap_Config"!][!//
/**
* @brief         Array of index for mapping the groups.
* @details       Array of index for mapping the groups in each partition.
*
*/
static const uint16 Adc_au16GroupIdToIndexMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][ADC_MAX_GROUPS] =
{
[!NOCODE!][!//
[!VAR "MaxCfgGroup" = "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)"!][!//
[!FOR "OuterIndex" = "0" TO "num:i($MaxCfgGroup)-1"!][!//
[!VAR "GroupIndex" = "0"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
        [!IF "AdcGroupId = $OuterIndex"!][!//
            [!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(../../AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/')"!][!//
                    [!FOR "InnerIndex" = "0" TO "num:i($MaxCfgGroup)-1"!][!//
                        [!LOOP "../../../../../AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
                            [!IF "AdcGroupId = $InnerIndex"!][!//
                                [!IF "substring-after(substring-after(substring-after(substring-after(../../AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!][!//
                                    [!IF "$OuterIndex = $InnerIndex"!][!//
                                        [!IF "$OuterIndex < num:i($MaxCfgGroup)-1"!][!//
                                            [!VAR "Comma" = "','"!]
                                        [!ELSE!]
                                            [!VAR "Comma" = "' '"!]
                                        [!ENDIF!]
[!CODE!][!//
    [!"num:i($GroupIndex)"!][!"$Comma"!] /* Group [!"num:i($OuterIndex)"!] parameters can be found at Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_[!"$CurrentPartition"!][[!"num:i($GroupIndex)"!]] */
[!ENDCODE!][!//
                                    [!ELSE!][!//
                                        [!VAR "GroupIndex" = "$GroupIndex + 1"!][!//
                                    [!ENDIF!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDFOR!][!//
            [!ELSE!][!//[!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
[!CODE!][!//
    [!"num:i($OuterIndex)"!][!IF "$OuterIndex < num:i($MaxCfgGroup)-1"!],[!ELSE!][!ENDIF!]
[!ENDCODE!][!//
            [!ENDIF!][!//[!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
        [!ENDIF!][!//[!IF "AdcGroupId = $OuterIndex"!][!//
    [!ENDLOOP!][!//[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!ENDFOR!][!//[!FOR "OuterIndex" = "0" TO "num:i($MaxCfgGroup)-1"!][!//
[!ENDNOCODE!][!//
};
[!ENDMACRO!][!//


[!MACRO "Adc_Ecuc_Partition_Ref_Config"!][!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
/**
* @brief         Array contains UserId of Partition.
* @details       Array contains UserId of Partition.
*
*/
static const uint8 Adc_u8AdcEcucPartition[ADC_MAX_PARTITIONS_CFG] =
[!ELSE!][!//
/**
* @brief         Array contains UserId used for [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
* @details       Array contains UserId used for [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*
*/
[!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!//
static const uint8 Adc_Partition_Assignment[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PARTITION] =
[!ELSE!][!//
static const uint8 Adc_Partition_Assignment[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] =
[!ENDIF!][!//
[!ENDIF!][!//
{
[!NOCODE!][!//
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
        [!VAR "MaxCount" = "count(AdcGeneral/AdcEcucPartitionRef/*)-1"!][!//
        [!VAR "CrtCount" = "0"!][!//
        [!LOOP "AdcGeneral/AdcEcucPartitionRef/*"!][!//
            [!VAR "AdcCrtPart" = "node:value(.)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$AdcCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
[!CODE!][!//
    (uint8)([!"node:value(./EcucCoreId)"!]UL)[!IF "$CrtCount < $MaxCount"!],[!ELSE!][!ENDIF!]
[!ENDCODE!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!VAR "CrtCount" = "$CrtCount + 1"!][!//
        [!ENDLOOP!][!//
    [!ELSE!][!//
[!CODE!][!//
    (uint8)(0UL)
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
};
[!ENDMACRO!][!//


[!MACRO "Adc_PdbChannelDelay_Config"!][!//
/**
* @brief          Group Channel Delays for configuration variant[!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*
*/
[!NOCODE!][!//
    [!VAR "numGroup" = "num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1)"!][!//
    [!FOR "LoopVar" = "0" TO "$numGroup"!][!//
        [!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
            [!VAR "numDelays" = "num:i(count(AdcChannelDelay/*))"!][!//
            [!IF "(AdcGroupId = $LoopVar) and (node:fallback(AdcGroupUsesChannelDelays,'false') = 'true') and ($numDelays > 0)"!][!//
[!CODE!][!//
static const uint16 Adc_GroupChannelDelays[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!ENDCODE!][!//
            [!VAR "crtDelays" = "1"!][!//
                [!LOOP "AdcChannelDelay/*"!]
[!CODE!][!//
    [!"."!]U[!IF "$crtDelays < $numDelays"!],[!ELSE!][!ENDIF!]
[!ENDCODE!][!//
                [!VAR "crtDelays" = "$crtDelays + 1"!][!//
                [!ENDLOOP!]
[!CODE!][!//
};
[!ENDCODE!][!//
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_Structure_Config"!][!//
[!NOCODE!][!//
    [!VAR "VariantsNo" = "variant:size()"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!ENDIF!]
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!//Support multipartition
        [!VAR "AdcConfiguredPartitions" = "num:i(count(AdcGeneral/AdcEcucPartitionRef/*))"!]
    [!ELSE!][!//
        [!VAR "AdcConfiguredPartitions" = "num:i(1)"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!FOR "Partition" = "0" TO "num:i($AdcConfiguredPartitions) - 1"!][!//
[!INDENT "0"!]
[!NOCODE!][!//
    [!VAR "ConfigType" = "'const'"!][!//
    [!VAR "CurrentPartition" = "string(null)"!][!//
    [!VAR "CurrentPartitionString" = "string(null)"!][!//
    [!VAR "VariantNameAndPartitionName" = "string(null)"!][!//
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!][!//VariantPreCompile/LinkTime and at most 1 configured variant
        [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!//
            [!VAR "ConfigType" = "'static const'"!][!//
        [!ENDIF!]
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!ENDIF!][!//
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!//
        [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcGeneral/AdcEcucPartitionRef/*[@index = $Partition],'/'),'/'),'/'),'/')"!][!//
        [!VAR "CurrentPartitionString" = "concat('_',$CurrentPartition)"!][!//
    [!ENDIF!]
    [!VAR "VariantNameAndPartitionName" = "concat($postBuildVariantNameUnderscore,$CurrentPartitionString)"!][!//
[!CODE!][!//
/**
* @brief          ADC driver Configuration structure [!"$VariantNameAndPartitionName"!].
*/
[!"$ConfigType"!] Adc_ConfigType Adc_Config[!"$VariantNameAndPartitionName"!] =
[!ENDCODE!][!//
[!ENDNOCODE!][!//
{
[!ENDINDENT!][!//
    &AdcIpwCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!], /* AdcIpwConfigPtr */
    /** @brief Group configurations */
    Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!], /* GroupsPtr */
    ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"text:toupper($CurrentPartition)"!][!ENDIF!], /* GroupCount */
    /**< @brief Array for mapping the groups */
    Adc_au16GroupIdToIndexMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* GroupIdToIndexMapPtr */
[!NOCODE!][!//
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "$CurrentPartition = substring-after(substring-after(substring-after(substring-after(node:value(./OsAppEcucPartitionRef),'/'),'/'),'/'),'/')"!][!//
                [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
[!CODE!][!//
    /** @brief Configuration UserId */
    (uint8)([!"node:value(./EcucCoreId)"!]U), /* UserId */
[!ENDCODE!][!//
                [!ENDSELECT!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ELSE!][!//
[!CODE!][!//
    /** @brief Configuration UserId */
    (uint8)(0U), /* UserId */
[!ENDCODE!]
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
    /**< @brief Array contains UserId */
    Adc_u8AdcEcucPartition, /* AssignmentPartitionPtr */
    /**< @brief Number of partitions */
    (uint8)ADC_MAX_PARTITIONS_CFG /* AssignedPartitionCount */
[!ELSE!][!//
    /**< @brief Array contains UserId */
    Adc_Partition_Assignment[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* AssignmentPartitionPtr */
    /**< @brief Number of partitions */
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!](uint8)ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PARTITION[!ELSE!](uint8)1UL[!ENDIF!] /* AssignedPartitionCount */
[!ENDIF!][!//
};
[!ENDFOR!][!//[!FOR "Partition" = "0" TO "num:i($AdcConfiguredPartitions) - 1"!][!//
[!ENDMACRO!][!//



[!MACRO "Adc_Global_Pointer_Config"!][!//
[!NOCODE!]
    [!VAR "VariantsNo" = "variant:size()"!]
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!]
        [!VAR "MaxPartition" = "num:i(0)"!]
            [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
                [!VAR "MaxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
            [!ENDIF!]
        [!IF "$MaxPartition = 0"!][!VAR "MaxPartition" = "num:i(1)"!][!ENDIF!][!//
[!CODE!][!//
const Adc_ConfigType * const Adc_ConfigVariantPredefined[ADC_MAX_PARTITIONS] =
{
[!ENDCODE!]
        [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
            [!FOR "idx" = "0" TO "num:i($MaxPartition) - 1"!][!//
                [!VAR "PartitionExist"="0"!][!//
                [!LOOP "AdcGeneral/AdcEcucPartitionRef/*"!][!//
                    [!VAR "AdcCrtPart" = "node:value(.)"!][!//
                    [!VAR "AdcCrtPartShortName" = "substring-after(substring-after($AdcCrtPart, node:name(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1])), "/")"!][!//
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                        [!IF "$AdcCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                                [!IF "$idx = node:value(./EcucCoreId)"!][!//
                                    [!VAR "CurrentPartition" = "$AdcCrtPartShortName"!][!//
                                    [!VAR "PartitionExist"="1"!][!//
                                [!ENDIF!][!//
                            [!ENDSELECT!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDLOOP!][!//
                [!IF "$PartitionExist = 1"!][!//
[!CODE!]    &Adc_Config_[!"$CurrentPartition"!][!IF "$idx < ($MaxPartition - 1)"!],[!ELSE!][!ENDIF!]
[!ENDCODE!]
                [!ELSE!][!//
[!CODE!]    NULL_PTR[!IF "$idx < ($MaxPartition - 1)"!],[!ELSE!][!ENDIF!]
[!ENDCODE!]
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ELSE!][!//
[!CODE!]    &Adc_Config
[!ENDCODE!]
        [!ENDIF!]
[!CODE!]};[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//



[!MACRO "Adc_Group_Define"!][!//
[!NOCODE!]
[!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
    [!LOOP "AdcGeneral/AdcEcucPartitionRef/*"!][!//
        [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
[!CODE!]
/**
* @brief          Total number of groups in partition [!"$CurrentPartition"!] .
*
*/
#define ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_[!"text:toupper($CurrentPartition)"!]       ([!"num:i(count(../../../AdcConfigSet/AdcHwUnit/*[substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition]/AdcGroup/*))"!]U)
[!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!]
/**
* @brief          Total number of groups in Config.
*
*/
#define ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]                       ([!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!]U)
[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]


[!MACRO "Adc_Group_Assignments"!][!//
[!VAR "MaxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!FOR "Unit" = "0" TO "num:i($MaxUnit)"!][!//
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
/**
* @brief          Group Assignments on ADC[!"$Unit"!][!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*
*/
static const Adc_ChannelType Adc_Group[!"AdcGroupId"!]_Assignment_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS] =
{
[!INDENT "4"!][!//
    [!VAR "MaxCount" = "count(AdcGroupDefinition/*)-1"!][!//
    [!VAR "CrtCount" = "0"!][!//
    [!LOOP "AdcGroupDefinition/*"!][!//
        [!VAR "CurrAdcChannel" = "."!][!//
        [!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!][!//
        [!VAR "Idx" = "0"!][!//
        [!LOOP "../../../../AdcChannel/*"!][!//
            [!IF "@name = $CurrAdcChannel1"!][!//
                [!CODE!][!//
                [!"AdcLogicalChannelId"!]U[!IF "$CrtCount < $MaxCount"!],[!ELSE!][!ENDIF!]
                [!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "Idx" = "$Idx + 1"!][!//
        [!ENDLOOP!][!//
        [!VAR "CrtCount" = "$CrtCount + 1"!][!//
    [!ENDLOOP!][!//
[!ENDINDENT!][!//
};

[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_IpChansConfig"!][!//
[!NOCODE!][!// the logicalId is unique among all partitions, no need to generate following number of partitions
    [!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
    [!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
        [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
            [!IF "(AdcLogicalUnitId = $Unit)"!][!//
                [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[@index = "0"],'/'),'/'),'/'),'/')"!][!//
                [!ENDIF!][!//
[!CODE!]
/**
* @brief          ADC Ip List of Channels Configuration for Logical ID [!"AdcLogicalUnitId"!] corresponding to the [!"AdcHwUnitId"!] configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
static const Adc_Ip_ChanConfigType AdcIpChansConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][[!"num:i(count(AdcChannel/*))"!]U] =
{
[!ENDCODE!][!//
                [!VAR "MAX_NUM"="count(AdcChannel/*)"!]
                [!VAR "CRT_NUM"="0"!]
                [!FOR "CRT_NUM" = "0" TO "$MAX_NUM"!][!// This array should be generated order by Logical Channel Id (AdcLogicalChannelId) instead of @index
                    [!LOOP "AdcChannel/*"!]
                        [!IF "AdcLogicalChannelId = $CRT_NUM"!][!//
                            [!VAR "InputChannelString" = "'ADC_IP_INPUTCHAN_'"!][!//
                            [!IF "contains(AdcChannelName, '_INT0_ADCH21')"!][!//
                                [!VAR "InputChannelString" = "concat($InputChannelString, 'SUPPLY_', substring-before(AdcChannelName, '_INT0_ADCH21'))"!][!//
                            [!ELSEIF "contains(AdcChannelName, 'BANDGAP') or contains(AdcChannelName, 'VREF')"!][!//
                                [!VAR "InputChannelString" = "concat($InputChannelString, substring-before(AdcChannelName, '_ADCH'))"!][!//
                            [!ELSE!][!//
                                [!IF "substring-after(AdcChannelName, 'ADCH') > 15"!]
                                    [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', (substring-after(AdcChannelName, 'ADCH') - 16))"!][!//
                                [!ELSE!][!//
                                    [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', substring-after(AdcChannelName, 'ADCH'))"!][!//
                                [!ENDIF!]
                            [!ENDIF!]
[!CODE!][!//
    {
        [!"AdcLogicalChannelId"!]U, /* ChnIdx */
        [!"$InputChannelString"!], /* Channel */
    #if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
        (boolean)FALSE /* InterruptEnable */[!// Set to false at config time, to be enabled at runtime
    #endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
[!IF "$CRT_NUM < $MAX_NUM - 1"!][!//
    },[!ELSE!][!//
    }[!ENDIF!]
[!ENDCODE!][!//
                        [!ENDIF!][!//[!IF "AdcLogicalChannelId = $CRT_NUM"!][!//
                    [!ENDLOOP!][!//[!LOOP "AdcChannel/*"!]
                [!ENDFOR!][!//[!FOR "CRT_NUM" = "0" TO "$MAX_NUM"!]
[!CODE!][!//
};
[!ENDCODE!][!//
            [!ENDIF!][!//[!IF "(AdcLogicalUnitId = $Unit)"!][!//
        [!ENDLOOP!][!//[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
    [!ENDFOR!][!//[!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_Ipw_Notification"!][!//
[!NOCODE!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!]
        [!VAR "AdcPhysicalId" = "substring-after(AdcHwUnitId,'ADC')"!][!//
        [!IF "AdcTransferType = 'ADC_INTERRUPT'"!]
            [!LOOP "AdcGroup/*[AdcWithoutInterrupts = 'false']"!]
[!CODE!][!//
void Adc_Ipw_Adc[!"$AdcPhysicalId"!]EndConversionNotification(const uint8 ControlChanIdx);
[!ENDCODE!][!//
                [!BREAK!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!][!//
[!ENDMACRO!]



[!MACRO "Adc_IpwAltClock_Config"!][!//
[!NOCODE!][!//
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
        [!VAR "MaxPartitionCfg"="num:i(count(AdcGeneral/AdcEcucPartitionRef/*))"!][!//
    [!ELSE!][!//
        [!VAR "MaxPartitionCfg"="1"!][!//
    [!ENDIF!][!//
    [!VAR "CRT_COUNT" = "0"!][!//
    [!IF "((AutosarExt/AdcEnableDualClockMode) = 'true')"!][!//
[!CODE!]
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
[!ENDCODE!][!//
    [!FOR "Partition" = "0" TO "num:i($MaxPartitionCfg) - 1"!][!//
        [!VAR "MaxHWUnitInPartition"="0"!][!//
        [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
            [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcGeneral/AdcEcucPartitionRef/*[@index = $Partition],'/'),'/'),'/'),'/')"!][!//
            [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
                [!IF "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!]
                    [!VAR "MaxHWUnitInPartition"="$MaxHWUnitInPartition + 1"!][!//
            [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ELSE!][!//
            [!VAR "MaxHWUnitInPartition"="num:i(count(AdcConfigSet/AdcHwUnit/*))"!][!//
        [!ENDIF!][!//
        [!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
        [!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
            [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
                [!VAR "HWUnitPartition"="0"!][!//
                [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!IF "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!][!//
                        [!VAR "HWUnitPartition"="1"!][!//
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!VAR "HWUnitPartition"="2"!][!//
                [!ENDIF!][!//
                [!IF "(AdcLogicalUnitId = $Unit) and ($HWUnitPartition > 0)"!][!//
                    [!IF "(node:exists(AdcAlternateConvTimings) and (../../../AutosarExt/AdcConvTimeOnce = 'true'))"!][!//
                        [!IF "node:exists(AdcAlternateConvTimings/AdcHardwareAverageEnableAlternate)"!]
                            [!VAR "AdcHwAvgEnableAltString" = "text:toupper(AdcAlternateConvTimings/AdcHardwareAverageEnableAlternate)"!]
                        [!ENDIF!]
                        [!IF "node:exists(AdcAlternateConvTimings/AdcHardwareAverageSelectAlternate)"!]
                            [!VAR "AdcHwAvgSelectAltString" = "concat('ADC_IP_AVG_', substring-after(AdcAlternateConvTimings/AdcHardwareAverageSelectAlternate, 'SAMPLES_'),'_CONV')"!]
                        [!ENDIF!]
                        [!VAR "SampleTimeString" = "concat(node:value(AdcAlternateConvTimings/AdcSampleTimeDurationAlternate), 'U')"!]
                    [!ELSE!]
                        [!VAR "AdcHwAvgEnableAltString" = "'FALSE'"!]
                        [!VAR "AdcHwAvgSelectAltString" = "'ADC_IP_AVG_4_CONV'"!]
                        [!VAR "SampleTimeString" = "'ADC_IP_DEFAULT_SAMPLE_TIME'"!]
                    [!ENDIF!]
                    [!VAR "ClockSelectString" = "'ADC_IP_CLK_FULL_BUS'"!]
                    [!IF "node:exists(AdcAltPrescale)"!]
                        [!IF "num:i(AdcAltPrescale) = 2"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_HALF_BUS'"!]
                        [!ELSEIF "num:i(AdcAltPrescale) = 4"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_QUARTER_BUS'"!]
                        [!ELSEIF "num:i(AdcAltPrescale) = 8"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_EIGHTH_BUS'"!]
                        [!ENDIF!]
                    [!ENDIF!]
[!CODE!][!//
/**
* @brief          Definition of Alternate Clock Config for Logical ID [!"AdcLogicalUnitId"!] corresponding to the [!"AdcHwUnitId"!] configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
static const Adc_Ip_ClockConfigType AdcIpwAltClockConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] =
{
    [!"$ClockSelectString"!], /* ClockDivide */
    ADC_IP_CLK_ALT_1, /* InputClock */
    [!"$SampleTimeString"!], /* SampleTime */
    (boolean)[!"$AdcHwAvgEnableAltString"!], /* AvgEn */
    [!"$AdcHwAvgSelectAltString"!] /* AvgSel */
};

[!ENDCODE!][!//
                [!ENDIF!][!//[!IF "(AdcLogicalUnitId = $Unit) and ($HWUnitPartition > 0)"!][!//
            [!ENDLOOP!][!//[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
        [!ENDFOR!][!//[!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
    [!ENDFOR!][!//[!FOR "Partition" = "0" TO "num:i($MaxPartitionCfg) - 1"!][!//
[!CODE!][!//
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
[!ENDCODE!][!//
    [!ENDIF!][!//[!IF "((AutosarExt/AdcEnableDualClockMode) = 'true')"!][!//
[!ENDNOCODE!]
[!ENDMACRO!]


[!MACRO "Adc_IpwChannelConfig"!][!//
[!NOCODE!][!//
[!IF "(AdcGeneral/AdcEnableLimitCheck = 'true')"!][!//
    [!FOR "Unit" = "0" TO "num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit')) - 1"!][!// START FOR 1
        [!VAR "HwUnitExist" = "0"!][!// To check which Hardware Unit will be generated.
        [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!// LOOP 1
                [!IF "AdcLogicalUnitId = $Unit"!][!//
                    [!VAR "HwUnitExist" = "$HwUnitExist+1"!][!//
                    [!VAR "AdcHwUnit" = "concat('AdcConfigSet/AdcHwUnit/',@name)"!][!//
                    [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                        [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[@index = "0"],'/'),'/'),'/'),'/')"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
        [!ENDLOOP!][!// END LOOP 1

        [!IF "$HwUnitExist = 1"!][!// If the unit exist, its configuration will be generated.
            [!VAR "LoopVar"="0"!][!//
[!CODE!][!//
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of Adc Ipw Channel limits for Logical Unit Id [!"node:ref(concat($AdcHwUnit,'/AdcLogicalUnitId'))"!] configuration variant[!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!] [!"$CurrentPartition"!][!ENDIF!].
*/
static const Adc_ChannelLimitCheckingType ChannelLimitCheckingConfig_[!"node:ref(concat($AdcHwUnit,'/AdcLogicalUnitId'))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][] =
{
[!ENDCODE!][!//
            [!VAR "numChannel" = "num:i(count(AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId = $Unit]/AdcChannel/*)-1)"!][!//
            [!FOR "x" = "0" TO "$numChannel"!][!// START FOR 2
                [!LOOP "AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId = $Unit]/AdcChannel/*"!][!// LOOP 2
                    [!VAR "Loop"="num:i($LoopVar)"!][!//
                    [!IF "AdcLogicalChannelId = $Loop"!][!//
                        [!VAR "ChannelLimitEnableString" = "'FALSE'"!]
                        [!VAR "ChannelRangeString" = "'ADC_RANGE_ALWAYS'"!]
                        [!VAR "ChannelHighLimitString" = "'4095'"!] [!//
                        [!VAR "ChannelLowLimitString" = "'0'"!]
                        [!IF "node:exists(AdcChannelLimitCheck) and AdcChannelLimitCheck ='true'"!][!//
                            [!VAR "ChannelLimitEnableString" = "'TRUE'"!]
                            [!IF "node:exists(AdcChannelRangeSelect)"!][!//
                                [!VAR "ChannelRangeString" = "AdcChannelRangeSelect"!]
                            [!ENDIF!][!//
                            [!IF "node:exists(AdcChannelHighLimit)"!][!//
                                [!VAR "ChannelHighLimitString" = "AdcChannelHighLimit"!]
                            [!ENDIF!][!//
                            [!IF "node:exists(AdcChannelLowLimit)"!][!//
                                [!VAR "ChannelLowLimitString" = "AdcChannelLowLimit"!]
                            [!ENDIF!][!//
                        [!ENDIF!][!//
[!CODE!][!//
    {
        /**< @brief limit check enabled */
        (boolean)[!"$ChannelLimitEnableString"!], /* ChannelLimitCheckEnabled */
        /**< @brief range for limit check */
        [!"$ChannelRangeString"!], /* ChannelRange */
        /**< @brief high limit value */
        [!"$ChannelHighLimitString"!]U, /* ChannelHighLimit */
        /**< @brief low limit value */
        [!"$ChannelLowLimitString"!]U /* ChannelLowLimit */
    }[!IF "$x < $numChannel"!],[!ENDIF!]
[!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!// END LOOP 2
                [!VAR "LoopVar"="$LoopVar + 1"!][!//
            [!ENDFOR!][!// END FOR 2
[!CODE!][!//
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!// END FOR 1
[!ENDIF!][!// If AdcEnableLimitCheck is set
[!ENDNOCODE!]
[!ENDMACRO!]


[!MACRO "Adc_IpwConfig" , "MacroGenerationType"!][!// GenerationType='definition' or 'declaration'
[!NOCODE!][!//
    [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
        [!VAR "MaxPartitionCfg"="num:i(count(AdcGeneral/AdcEcucPartitionRef/*))"!][!//
    [!ELSE!][!//
        [!VAR "MaxPartitionCfg"="1"!][!//
    [!ENDIF!][!//

    [!FOR "Partition" = "0" TO "num:i($MaxPartitionCfg) - 1"!][!// Start of For Loop 1
        [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcGeneral/AdcEcucPartitionRef/*[@index = $Partition],'/'),'/'),'/'),'/')"!][!//

        [!IF "$MacroGenerationType = 'declaration'"!]
[!CODE!][!//
/**
* @brief          Adc Ipw Config configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
extern const Adc_Ipw_Config AdcIpwCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!];
[!ENDCODE!][!//
        [!ELSE!]
[!CODE!][!//
/**
* @brief          Adc Ipw Config configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
const Adc_Ipw_Config AdcIpwCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] =
{
[!ENDCODE!][!//
        [!VAR "AdcConfigArrayString" = "'{ '"!][!//
        [!VAR "PdbConfigArrayString" = "'{ '"!][!//
        [!VAR "AdcPhysicalChannelIdArrayString" = "'{ '"!][!//
        [!VAR "AdcAltClockConfigArrayString" = "'{ '"!][!//
        [!VAR "ChannelLimitCheckingArrayString" = "'{ '"!][!//
        [!VAR "TransferTypeArrayString" = "'{ '"!][!//
        [!VAR "GroupCountArrayString" = "'{ '"!][!//
        [!VAR "ChannelCountArrayString" = "'{ '"!][!//
        [!VAR "DmaChannelArrayString" = "'{ '"!][!//
        [!VAR "CountingDmaChannelArrayString" = "'{ '"!][!//
        [!VAR "HwUnitEnableArrayString" = "'{ '"!][!//
        [!VAR "HwLogicalIdArrayString" = "'{ '"!][!//

        [!FOR "Unit" = "0" TO "num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit')) - 1"!][!// Start of For Loop 2
            [!IF "($Unit < num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit')) - 1)"!][!//
                [!VAR "Comma" = "', '"!]
            [!ELSE!]
                [!VAR "Comma" = "' '"!]
            [!ENDIF!]

            [!VAR "AdcHwUnit" = "'____________'"!][!//
            [!LOOP "AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId = $Unit]"!][!//
                [!VAR "AdcHwUnit" = "node:path(.)"!][!//
            [!ENDLOOP!][!//

            [!VAR "HWUnitPartition"="0"!][!// Indicate the Multipartition but the current Unit did not assign to current partition.
            [!IF "node:exists($AdcHwUnit)"!]
                [!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!IF "substring-after(substring-after(substring-after(substring-after(node:value(concat($AdcHwUnit,'/AdcHwUnitEcucPartitionRef/*[1]')),'/'),'/'),'/'),'/') = $CurrentPartition"!][!//
                        [!VAR "HWUnitPartition"="1"!][!// Indicate the Multipartition.
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!VAR "HWUnitPartition"="2"!][!// Indicate the Single Core.
                [!ENDIF!][!//
                [!VAR "AdcLogicalUnitId"="node:value(concat($AdcHwUnit,'/AdcLogicalUnitId'))"!][!//
                [!VAR "AdcPhysicalId" = "substring-after(node:value(concat($AdcHwUnit,'/AdcHwUnitId')),'ADC')"!][!//

                [!IF "($HWUnitPartition > 0)"!][!//
                    [!IF "(node:value(concat($AdcHwUnit,'/AdcTransferType')) = 'ADC_DMA') and node:exists(concat($AdcHwUnit,'/AdcDmaChannelId'))"!]
                        [!VAR "DmaChannelArrayString" = "concat($DmaChannelArrayString, as:ref(node:ref(concat($AdcHwUnit,'/AdcDmaChannelId')))/dmaLogicChannel_LogicName, $Comma)"!][!// Get Dma Channel Id from Mcl
                        [!VAR "AdcCountingDmaChannelEnabled" = "'FALSE'"!][!//
                        [!LOOP "AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId = $Unit]"!][!//
                            [!IF "(num:i(count(./AdcGroup/*[(((AdcEnableOptimizeDmaStreamingGroups = 'true') or ((AdcWithoutInterrupts = 'true') and (AdcGroupAccessMode = 'ADC_ACCESS_MODE_STREAMING') and (AdcStreamResultGroup = 'true'))) and (count(AdcGroupDefinition/*) > 1)) or ((AdcWithoutInterrupts = 'true') and (AdcGroupAccessMode = 'ADC_ACCESS_MODE_STREAMING') and (count(AdcGroupDefinition/*) = 1))])) > 0)"!]
                                [!IF "node:exists(concat($AdcHwUnit,'/AdcCountingDmaChannelId'))"!][!//
                                    [!VAR "AdcCountingDmaChannelEnabled" = "'TRUE'"!][!//
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!][!//
                        [!IF "($AdcCountingDmaChannelEnabled = 'TRUE') and not(node:empty(concat($AdcHwUnit,'/AdcCountingDmaChannelId')))"!]
                            [!VAR "CountingDmaChannelArrayString" = "concat($CountingDmaChannelArrayString, as:ref(node:ref(concat($AdcHwUnit,'/AdcCountingDmaChannelId')))/dmaLogicChannel_LogicName, $Comma)"!][!// Get Dma Channel Id from Mcl
                        [!ELSE!]
                            [!VAR "CountingDmaChannelArrayString" = "concat($CountingDmaChannelArrayString, 'ADC_IPW_INVALID_DMA_CHANNEL_ID', $Comma)"!][!// INVALID DMA Channel ID
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "CountingDmaChannelArrayString" = "concat($CountingDmaChannelArrayString, 'ADC_IPW_INVALID_DMA_CHANNEL_ID', $Comma)"!][!// INVALID DMA Channel ID
                        [!VAR "DmaChannelArrayString" = "concat($DmaChannelArrayString, 'ADC_IPW_INVALID_DMA_CHANNEL_ID', $Comma)"!][!// INVALID DMA Channel ID
                    [!ENDIF!]

                    [!VAR "AdcConfigArraySubString"!]&AdcIpConfig_[!"$AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][!ENDVAR!]
                    [!VAR "AdcConfigArrayString" = "concat($AdcConfigArrayString, $AdcConfigArraySubString, $Comma)"!]
                    [!VAR "PdbConfigArraySubString"!]&PdbAdcIpConfig_[!"$AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][!ENDVAR!]
                    [!VAR "PdbConfigArrayString" = "concat($PdbConfigArrayString, $PdbConfigArraySubString, $Comma)"!]

                    [!IF "(AutosarExt/AdcEnableDualClockMode = 'true')"!][!//
                        [!VAR "AdcAltClockConfigArraySubString"!]&AdcIpwAltClockConfig_[!"$AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][!ENDVAR!]
                    [!ELSE!][!//
                        [!VAR "AdcAltClockConfigArraySubString" = "'NULL_PTR'"!]
                    [!ENDIF!][!//
                    [!VAR "AdcAltClockConfigArrayString" = "concat($AdcAltClockConfigArrayString, $AdcAltClockConfigArraySubString, $Comma)"!]

                    [!IF "(AdcGeneral/AdcEnableLimitCheck = 'true')"!][!//
                        [!VAR "ChannelLimitCheckingArraySubString"!]ChannelLimitCheckingConfig_[!"$AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!][!ENDVAR!]
                    [!ELSE!][!//
                        [!VAR "ChannelLimitCheckingArraySubString" = "'NULL_PTR'"!]
                    [!ENDIF!][!//
                    [!VAR "ChannelLimitCheckingArrayString" = "concat($ChannelLimitCheckingArrayString, $ChannelLimitCheckingArraySubString, $Comma)"!][!//

                    [!VAR "AdcPhysicalChannelIdArrayString" = "concat($AdcPhysicalChannelIdArrayString, text:replace(node:value(concat($AdcHwUnit,'/AdcHwUnitId')),'ADC',''), 'U', $Comma)"!]
                    [!VAR "TransferTypeArrayString" = "concat($TransferTypeArrayString, node:ref(concat($AdcHwUnit,'/AdcTransferType')), $Comma)"!][!//
                    [!VAR "GroupCountArrayString" = "concat($GroupCountArrayString, num:i(count(node:ref(concat($AdcHwUnit,'/AdcGroup'))/*)), 'U', $Comma)"!][!//
                    [!VAR "ChannelCountArrayString" = "concat($ChannelCountArrayString, num:i(count(node:ref(concat($AdcHwUnit,'/AdcChannel'))/*)), 'U', $Comma)"!][!//
                    [!VAR "HwUnitEnableArrayString" = "concat($HwUnitEnableArrayString, 'STD_ON', $Comma)"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//

            [!IF "(node:exists($AdcHwUnit) != 'true') or (num:i($HWUnitPartition) = num:i(0))"!] [!// If Unit is not configured OR does not belong to current partition
                [!VAR "AdcConfigArrayString" = "concat($AdcConfigArrayString, 'NULL_PTR', $Comma)"!][!//
                [!VAR "PdbConfigArrayString" = "concat($PdbConfigArrayString, 'NULL_PTR', $Comma)"!][!//
                [!VAR "AdcPhysicalChannelIdArrayString" = "concat($AdcPhysicalChannelIdArrayString, 'ADC_IPW_INVALID_LOGICAL_UNIT_ID', $Comma)"!][!//
                [!VAR "AdcAltClockConfigArrayString" = "concat($AdcAltClockConfigArrayString, 'NULL_PTR', $Comma)"!][!//
                [!VAR "ChannelLimitCheckingArrayString" = "concat($ChannelLimitCheckingArrayString, 'NULL_PTR', $Comma)"!][!//
                [!VAR "TransferTypeArrayString" = "concat($TransferTypeArrayString, 'ADC_IPW_INVALID_TRANSFER_TYPE /* Unit not used */', $Comma)"!][!//
                [!VAR "GroupCountArrayString" = "concat($GroupCountArrayString, '0U', $Comma)"!][!//
                [!VAR "ChannelCountArrayString" = "concat($ChannelCountArrayString, '0U', $Comma)"!][!//
                [!VAR "HwUnitEnableArrayString" = "concat($HwUnitEnableArrayString, 'STD_OFF', $Comma)"!][!//
                [!VAR "DmaChannelArrayString" = "concat($DmaChannelArrayString, 'ADC_IPW_INVALID_DMA_CHANNEL_ID', $Comma)"!][!// INVALID DMA Channel ID
                [!VAR "CountingDmaChannelArrayString" = "concat($CountingDmaChannelArrayString, 'ADC_IPW_INVALID_DMA_CHANNEL_ID', $Comma)"!][!// INVALID DMA Channel ID
            [!ENDIF!][!//

            [!// This loop will generate the mapping between Physical Id and Logical Id, ordered by AdcHwUnitId.
            [!// For example: Max Unit is 3. ADC0 = Logical 1 and ADC2 = Logical 0 => HwLogicalId = {1, INVALID, 0}
            [!// So in driver, we can get Logical from Physical like that: LogicalAdcUnit = Adc_apxCfgPtr[u32CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalHwUnitId]
            [!VAR "bFoundUnit"="0"!][!// '0' means curent Physical unit is unused.
            [!LOOP "AdcConfigSet/AdcHwUnit/*[num:i(substring(substring-after(AdcHwUnitId, 'ADC'), 1, 1)) = $Unit]"!][!//
                [!VAR "HWUnitPartition"="0"!][!// '0' means Multipartition was enabled but the current Unit did not assign to current partition.
                [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!IF "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[1],'/'),'/'),'/'),'/') = $CurrentPartition"!][!//
                        [!VAR "HWUnitPartition"="1"!][!// '1' means Multipartition was enabled but the current Unit is assigned to current partition.
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!VAR "HWUnitPartition"="2"!][!//[!// '2' means Multipartition was disabled.
                [!ENDIF!][!//
                [!IF "($HWUnitPartition > 0)"!][!//
                    [!VAR "HwLogicalIdArrayString" = "concat($HwLogicalIdArrayString, node:value(AdcLogicalUnitId) , 'U', $Comma)"!][!//
                [!ELSE!]
                    [!VAR "HwLogicalIdArrayString" = "concat($HwLogicalIdArrayString, 'ADC_IPW_INVALID_LOGICAL_UNIT_ID', $Comma)"!][!//
                [!ENDIF!]
                [!VAR "bFoundUnit"="1"!][!// '1' means curent Physical unit is used in configuration.
            [!ENDLOOP!]
            [!IF "($bFoundUnit = 0)"!][!//
                [!VAR "HwLogicalIdArrayString" = "concat($HwLogicalIdArrayString, 'ADC_IPW_INVALID_LOGICAL_UNIT_ID', $Comma)"!][!//
            [!ENDIF!]
        [!ENDFOR!][!// End of For Loop 2

        [!VAR "AdcConfigArrayString" = "concat($AdcConfigArrayString, '}')"!][!//
        [!VAR "PdbConfigArrayString" = "concat($PdbConfigArrayString, '}')"!][!//
        [!VAR "AdcPhysicalChannelIdArrayString" = "concat($AdcPhysicalChannelIdArrayString, '}')"!][!//
        [!VAR "AdcAltClockConfigArrayString" = "concat($AdcAltClockConfigArrayString, '}')"!][!//
        [!VAR "ChannelLimitCheckingArrayString" = "concat($ChannelLimitCheckingArrayString, '}')"!][!//
        [!VAR "TransferTypeArrayString" = "concat($TransferTypeArrayString, '}')"!][!//
        [!VAR "GroupCountArrayString" = "concat($GroupCountArrayString, '}')"!][!//
        [!VAR "ChannelCountArrayString" = "concat($ChannelCountArrayString, '}')"!][!//
        [!VAR "DmaChannelArrayString" = "concat($DmaChannelArrayString, '}')"!][!//
        [!VAR "CountingDmaChannelArrayString" = "concat($CountingDmaChannelArrayString, '}')"!][!//
        [!VAR "HwUnitEnableArrayString" = "concat($HwUnitEnableArrayString, '}')"!][!//
        [!VAR "HwLogicalIdArrayString" = "concat($HwLogicalIdArrayString, '}')"!][!//

 [!CODE!][!//
    [!"$AdcConfigArrayString"!], /* AdcConfigPtrArr */
    [!"$PdbConfigArrayString"!], /* PdbConfig */
    [!"$AdcPhysicalChannelIdArrayString"!], /* AdcPhysicalIdArr */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    [!"$AdcAltClockConfigArrayString"!], /* AdcAltClockConfig */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    [!"$ChannelLimitCheckingArrayString"!], /* ChannelLimitCheckingConfigs */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /* Mapping */
    {
        [!"$TransferTypeArrayString"!], /* AdcDmaInterruptSoftware */
        /**< @brief number of groups per hw unit > */
        [!"$GroupCountArrayString"!], /* AdcGroups */
        /**< @brief number of channels per hw unit > */
        [!"$ChannelCountArrayString"!], /* AdcChannels */
        [!"$DmaChannelArrayString"!], /* AdcDmaChannelLogicId */
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        [!"$CountingDmaChannelArrayString"!], /* AdcCountingDmaChanLogicId */
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) || (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        [!"$HwUnitEnableArrayString"!], /* AdcHwUnitArr */
        [!"$HwLogicalIdArrayString"!] /* HwLogicalId */
    }
};
[!ENDCODE!][!//
        [!ENDIF!][!//[!IF "$MacroGenerationType = 'declaration'"!]
[!IF "$Partition < (num:i($MaxPartitionCfg) - 1)"!]
[!CODE!]
[!ENDCODE!][!//
[!ENDIF!][!//
    [!ENDFOR!][!// End of For Loop 1
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_IpwGroupConfig" , "MacroGenerationType"!][!// GenerationType='definition' or 'declaration'
[!NOCODE!][!//
    [!VAR "numGroup" = "num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1)"!][!//
    [!FOR "LoopVar" = "0" TO "$numGroup"!][!//
        [!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
            [!IF "(AdcGroupId = $LoopVar)"!][!//
                [!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(../../AdcHwUnitEcucPartitionRef/*[@index = "0"],'/'),'/'),'/'),'/')"!][!//
                [!ENDIF!][!//
                [!IF "$MacroGenerationType = 'declaration'"!]
[!CODE!][!//
/**
* @brief          ADC Ipw Group [!"AdcGroupId"!] Config [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
extern const Adc_Ipw_GroupConfig AdcIpwGroupConfig_[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!];

[!ENDCODE!][!//
                [!ELSE!]
[!CODE!][!//
/**
* @brief          ADC Ipw Group [!"AdcGroupId"!] Config [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
const Adc_Ipw_GroupConfig AdcIpwGroupConfig_[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] =
{
[!ENDCODE!][!//
                    [!VAR "AdcPdbPeriodValue" = "0"!]
                    [!IF "(../../../../../AutosarExt/AdcConvTimeOnce = 'false')"!][!//
                        [!VAR "SampleTimeString" = "concat(node:value(AdcGroupConversionConfiguration/AdcGroupSampleTimeDuration), 'U')"!]
                        [!IF "(../../../../../AutosarExt/AdcEnableDualClockMode)"!][!//
                            [!VAR "AltSampleTimeString" = "concat(node:value(AdcAlternateGroupConvTimings/AdcGroupAltSampleTimeDuration), 'U')"!]
                        [!ELSE!][!//
                            [!VAR "AltSampleTimeString" = "'ADC_IP_DEFAULT_SAMPLE_TIME'"!]
                        [!ENDIF!]
                        [!IF "AdcGroupConversionConfiguration/AdcGroupHardwareAverageEnable = 'true'"!][!VAR "GroupAvgEnableString" = "'STD_ON'"!][!ELSE!][!VAR "GroupAvgEnableString" = "'STD_OFF'"!][!ENDIF!]
                        [!VAR "GroupAvgSelectString" = "concat('ADC_IP_AVG_', substring-after(AdcGroupConversionConfiguration/AdcGroupHardwareAverageSelect, 'SAMPLES_'),'_CONV')"!]
                    [!ELSE!][!//
                        [!VAR "SampleTimeString" = "'ADC_IP_DEFAULT_SAMPLE_TIME'"!]
                        [!VAR "AltSampleTimeString" = "'ADC_IP_DEFAULT_SAMPLE_TIME'"!]
                        [!VAR "GroupAvgEnableString" = "'STD_OFF'"!]
                        [!VAR "GroupAvgSelectString" = "'ADC_IP_AVG_4_CONV'"!]
                    [!ENDIF!][!//

                    [!VAR "GroupAvgEnableAlternateString" = "'STD_OFF'"!]
                    [!VAR "GroupAvgSelectAlternateString" = "'ADC_IP_AVG_4_CONV'"!]
                    [!IF "(../../../../../AutosarExt/AdcEnableDualClockMode)"!][!//
                        [!IF "AdcAlternateGroupConvTimings/AdcGroupAltHardwareAverageEnable = 'true'"!][!VAR "GroupAvgEnableAlternateString" = "'STD_ON'"!][!ELSE!][!VAR "GroupAvgEnableAlternateString" = "'STD_OFF'"!][!ENDIF!]
                        [!VAR "GroupAvgSelectAlternateString" = "concat('ADC_IP_AVG_', substring-after(AdcAlternateGroupConvTimings/AdcGroupAltHardwareAverageSelect, 'SAMPLES_'),'_CONV')"!]
                    [!ENDIF!][!//

                    [!IF "((node:value(AdcWithoutInterrupts) = 'true') or (node:value(AdcEnableOptimizeDmaStreamingGroups) = 'true')) and (node:value(AdcGroupConversionMode) = 'ADC_CONV_MODE_CONTINUOUS')"!][!//
                        [!VAR "AdcPdbPeriodValue" = "node:value(AdcPdbPeriodContinuousMode)"!]
                    [!ENDIF!][!//

                    [!VAR "NumChannel" = "num:i(count(AdcGroupDefinition/*))"!]
                    [!IF "($NumChannel) > 8"!]
                        [!// ADC_IPW_CALCULATE_CHAN_NUMBER(x) (((x) >= ADC_MAX_CHAN_COUNT) ? ADC_MAX_CHAN_COUNT : ((x)%ADC_MAX_CHAN_COUNT))
                        [!IF "($NumChannel) >= ecu:get('Adc.AdcConfigSet.AdcScRegister')"!]
                            [!VAR "NumChannel" = "ecu:get('Adc.AdcConfigSet.AdcScRegister')"!]
                        [!ELSE!]
                            [!VAR "NumChannel" = "(($NumChannel) mod ecu:get('Adc.AdcConfigSet.AdcScRegister'))"!]
                        [!ENDIF!]

                        [!// ADC_IPW_PDB_CHANNELS_USED(x)
                        [!VAR "MaxPdbChannelUsed" = "ceiling(($NumChannel) div 8)"!]

                        [!//Since back-to-back mode cannot be configured as a ring across PDB channels (by using SIM or configure across PDB channels 1-2-3)
                        [!//If AdcGroupInBacktoBackMode = true and number of group channels > 8 channels,
                        [!//AdcDelayNextPdb is intended to initiate first pretrigger in each PDB channels by setting its first pretrigger delay value = AdcDelayNextPdb * PDB channel index
                        [!//This check ensures that AdcDelayNextPdb value won't make calculated PDB_MOD value (PdbPeriod) greater than 65535
                        [!IF "node:value(AdcGroupUsesChannelDelays) = 'true'"!]
                            [!IF "node:value(AdcGroupInBacktoBackMode) = 'true'"!]
                                [!VAR "PdbPeriod" = "AdcChannelDelay/*[1] + (AdcDelayNextPdb * ($MaxPdbChannelUsed - 1))"!]
                                [!IF "($PdbPeriod > 65535)"!]
                                    [!VAR "MaxAdcDelayNextPdb" = "(65535 - AdcChannelDelay/*[1]) div ($MaxPdbChannelUsed - 1)"!]
                                    [!ERROR!][!//
                                        [!"'AdcDelayNextPdb of '"!][!"@name"!][!"' must not be greater than '"!][!"num:i($MaxAdcDelayNextPdb)"!][!//
                                    [!ENDERROR!][!//
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ELSE!]
                            [!VAR "PdbPeriod" = "(AdcDelayNextPdb * ($MaxPdbChannelUsed - 1))"!]
                                [!IF "($PdbPeriod > 65535)"!]
                                    [!VAR "MaxAdcDelayNextPdb" = "65535 div ($MaxPdbChannelUsed - 1)"!]
                                    [!ERROR!][!//
                                        [!"'AdcDelayNextPdb of '"!][!"@name"!][!"' must not be greater than '"!][!"num:i($MaxAdcDelayNextPdb)"!][!//
                                    [!ENDERROR!][!//
                                [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]

[!CODE!][!//
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /**< @brief Main Average enable status of group */
    [!"$GroupAvgEnableString"!], /* GroupAvgEnable */
    /**< @brief Main Average selection of group */
    [!"$GroupAvgSelectString"!], /* GroupAvgSelect */
    [!"$SampleTimeString"!], /* ConvTime */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Alternate Average enable status of group */
    [!"$GroupAvgEnableAlternateString"!], /* GroupAvgEnableAlternate */
    /**< @brief Alternate Average selection of group */
    [!"$GroupAvgSelectAlternateString"!], /* GroupAvgSelectAlternate */
    [!"$AltSampleTimeString"!], /* AlternateConvTime */
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
    [!IF "$AdcPdbPeriodValue = 0"!]0[!ELSE!][!"$AdcPdbPeriodValue"!][!ENDIF!]U, /* PdbPeriod */
    [!"node:value(AdcDelayNextPdb)"!]U, /* PdbDelay */
    (boolean)[!IF "node:value(AdcGroupInBacktoBackMode) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* AdcGroupEnableBackToBack */
    (boolean)[!IF "node:value(AdcGroupUsesChannelDelays) = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* AdcGroupEnableChannelDelays */
[!ENDCODE!]
                    [!VAR "numDelays" = "num:i(count(AdcChannelDelay/*))"!][!//
                    [!IF "(node:fallback(AdcGroupUsesChannelDelays,'false') = 'true') and ($numDelays > 0)"!]
                        [!VAR "ChannelDelaysString" = "concat('Adc_GroupChannelDelays', AdcGroupId)"!]
                        [!IF "var:defined('postBuildVariant')"!]
                            [!VAR "ChannelDelaysString" = "concat($ChannelDelaysString, '_', $postBuildVariant)"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!VAR "ChannelDelaysString" = "'NULL_PTR'"!]
                    [!ENDIF!]
[!CODE!][!//
    [!"$ChannelDelaysString"!] /* DelayPtr */
};

[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_IpConfig" , "MacroGenerationType"!][!// GenerationType='definition' or 'declaration'
[!NOCODE!][!// the logicalId is unique among all partitions, no need to generate following number of partitions
    [!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
    [!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
        [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
            [!IF "(AdcLogicalUnitId = $Unit)"!][!//
                [!VAR "AdcPhysicalId" = "substring-after(AdcHwUnitId,'ADC')"!][!//
                [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[@index = "0"],'/'),'/'),'/'),'/')"!][!//
                [!ENDIF!][!//
                [!IF "$MacroGenerationType = 'declaration'"!]
[!CODE!][!//
/**
* @brief          ADC Ip Config for Logical ID [!"AdcLogicalUnitId"!] corresponding to the [!"AdcHwUnitId"!] configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
extern const Adc_Ip_ConfigType AdcIpConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!];

[!ENDCODE!][!//
                [!ELSE!]
[!CODE!][!//
/**
* @brief          ADC Ip Config for Logical ID [!"AdcLogicalUnitId"!] corresponding to the [!"AdcHwUnitId"!] configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
const Adc_Ip_ConfigType AdcIpConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] =
{
[!ENDCODE!][!//
                    [!VAR "ClockSelectString" = "'ADC_IP_CLK_FULL_BUS'"!]
                    [!VAR "SupplyMonitoringEnableString" = "'FALSE'"!]
                    [!IF "AdcHwUnitId = 'ADC0'"!]
                        [!LOOP "AdcChannel/*"!][!//
                            [!IF "contains(AdcChannelName,'INT0_ADCH21')"!]
                                [!VAR "SupplyMonitoringEnableString" = "'TRUE'"!]
                                [!BREAK!][!//
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDIF!]
                    [!IF "node:exists(AdcPrescale)"!]
                        [!IF "num:i(AdcPrescale) = 2"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_HALF_BUS'"!]
                        [!ELSEIF "num:i(AdcPrescale) = 4"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_QUARTER_BUS'"!]
                        [!ELSEIF "num:i(AdcPrescale) = 8"!]
                            [!VAR "ClockSelectString" = "'ADC_IP_CLK_EIGHTH_BUS'"!]
                        [!ENDIF!]
                    [!ENDIF!]
                    [!VAR "ClockCalibrationSelectString" = "'ADC_IP_CLK_EIGHTH_BUS'"!]
                    [!IF "(../../../AutosarExt/AdcEnableCalibration)"!]
                        [!IF "num:i(AdcCalibrationPrescale) = 1"!]
                            [!VAR "ClockCalibrationSelectString" = "'ADC_IP_CLK_FULL_BUS'"!]
                        [!ELSEIF "num:i(AdcCalibrationPrescale) = 2"!]
                            [!VAR "ClockCalibrationSelectString" = "'ADC_IP_CLK_HALF_BUS'"!]
                        [!ELSEIF "num:i(AdcCalibrationPrescale) = 4"!]
                            [!VAR "ClockCalibrationSelectString" = "'ADC_IP_CLK_QUARTER_BUS'"!]
                        [!ENDIF!]
                    [!ENDIF!]

                    [!IF "(../../../AutosarExt/AdcConvTimeOnce = 'true') and (node:exists(AdcNormalConvTimings))"!]
                        [!VAR "AdcHwAvgEnableString" = "text:toupper(AdcNormalConvTimings/AdcHardwareAverageEnable)"!]
                        [!VAR "AdcHwAvgSelectString" = "concat('ADC_IP_AVG_', substring-after(AdcNormalConvTimings/AdcHardwareAverageSelect, 'SAMPLES_'),'_CONV')"!]
                        [!VAR "SampleTimeString" = "concat(node:value(AdcNormalConvTimings/AdcSampleTimeDuration), 'U' )"!]
                    [!ELSE!]
                        [!VAR "AdcHwAvgEnableString" = "'FALSE'"!]
                        [!VAR "AdcHwAvgSelectString" = "'ADC_IP_AVG_4_CONV'"!]
                        [!VAR "SampleTimeString" = "'ADC_IP_DEFAULT_SAMPLE_TIME'"!]
                    [!ENDIF!]

                    [!VAR "ConversionCompleteNotificationString" = "'NULL_PTR'"!]
                    [!IF "AdcTransferType = 'ADC_INTERRUPT'"!]
                        [!LOOP "AdcGroup/*[AdcWithoutInterrupts = 'false']"!]
                            [!VAR "ConversionCompleteNotificationString" = "concat('&Adc_Ipw_Adc', $AdcPhysicalId, 'EndConversionNotification')"!]
                            [!BREAK!]
                        [!ENDLOOP!]
                    [!ENDIF!]
[!CODE!][!//
    [!"$ClockSelectString"!], /* ClockDivide */
    [!"$ClockCalibrationSelectString"!], /* CalibrationClockDivide */
    ADC_IP_CLK_ALT_1, /* InputClock */
    [!"$SampleTimeString"!], /* SampleTime */
    (boolean)[!"$AdcHwAvgEnableString"!], /* AvgEn */
    [!"$AdcHwAvgSelectString"!], /* AvgSel */
    [!"concat('ADC_IP_', AdcHwUnitResolution, 'BIT')"!], /* Resolution */
    ADC_IP_TRIGGER_HARDWARE, /* TriggerMode */[!// Hardcoded to PDB(hardware)
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    ADC_IP_PRETRIGGER_SEL_PDB, /* PretriggerSel */[!// Hardcoded to PDB
    ADC_IP_TRIGGER_SEL_PDB, /* TriggerSel */[!// Hardcoded to PDB
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
    (boolean)FALSE, /* DmaEnable */
    ADC_IP_VOLTAGEREF_VREF, /* VoltageRef */
    (boolean)FALSE, /* ContinuousConvEnable */
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    (boolean)[!"$SupplyMonitoringEnableString"!], /* SupplyMonitoringEnable */
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
    (boolean)FALSE, /* CompareEnable */[!// Compare functionality not used in HLD
    (boolean)FALSE, /* CompareGreaterThanEnable */
    (boolean)FALSE, /* CompareRangeFuncEnable */
    0U, /* CompVal1 */
    255U, /* CompVal2 */
    [!"AdcHwUnitUsrGain"!]U, /* UsrGain */
    [!"AdcHwUnitUsrOffset"!]U, /* UsrOffset */
    0U, /* NumChannels */[!// channels are re-configured when calling groups, set as 0 to not init at Adc_Init()
    AdcIpChansConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!], /* ChannelConfigs */
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    [!"$ConversionCompleteNotificationString"!] /* ConversionCompleteNotification */
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
};

[!ENDCODE!][!//
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "AdcNotificationConfigMacro"!][!//
[!NOCODE!][!//
[!VAR "adcNotifArr" = "''"!][!//
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*[$x = AdcGroupId]"!][!//
        [!IF "(../../../../../AdcGeneral/AdcGrpNotifCapability = 'true') and (node:exists(AdcNotification) and (AdcNotification != 'NULL_PTR') and (AdcNotification != 'NULL') and (AdcNotification != ''))"!][!//
            [!IF "(text:indexOf(text:split($adcNotifArr, ','), node:value(AdcNotification)) = -1)"!][!//
                [!VAR "adcNotifArr" = "concat($adcNotifArr, AdcNotification, ',')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!IF "(../../../../../AutosarExt/AdcEnableInitialNotification = 'true') and (AdcExtraNotification != 'NULL_PTR') and (AdcExtraNotification != 'NULL') and (AdcExtraNotification != '')"!][!//
            [!IF "(text:indexOf(text:split($adcNotifArr, ','), node:value(AdcExtraNotification)) = -1)"!][!//
                [!VAR "adcNotifArr" = "concat($adcNotifArr, AdcExtraNotification, ',')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!IF "(../../../../../AutosarExt/AdcEnableDmaErrorNotification = 'true') and (AdcDmaErrorNotification != 'NULL_PTR') and (AdcDmaErrorNotification != 'NULL') and (AdcDmaErrorNotification != '')"!][!//
            [!IF "(text:indexOf(text:split($adcNotifArr, ','), node:value(AdcDmaErrorNotification)) = -1)"!][!//
                [!VAR "adcNotifArr" = "concat($adcNotifArr, AdcDmaErrorNotification, ',')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//

[!IF "($adcNotifArr != '')"!]
[!CODE!][!//
/**
* @brief         ADC Notification functions.
* @details       ADC Notification functions defined by user.
*
*/
[!ENDCODE!][!//
    [!LOOP "text:split($adcNotifArr, ',')"!][!//
[!CODE!][!//
void [!"."!](void);
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Pdb_Sequence_Error_Notification"!][!//
[!NOCODE!][!//
[!VAR "pdbNotifArr" = "''"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/PdbHwUnit"!][!//
    [!IF "(AdcPdbErrorNotification != 'NULL_PTR') and (AdcPdbErrorNotification != 'NULL') and (AdcPdbErrorNotification != '')"!][!//
        [!IF "(text:indexOf(text:split($adcNotifArr, ','), node:value(AdcPdbErrorNotification)) = -1)"!][!//
            [!VAR "pdbNotifArr" = "concat($pdbNotifArr, AdcPdbErrorNotification, ',')"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "($pdbNotifArr != '')"!]
[!CODE!][!//
/**
* @brief         PDB Sequence Error Notification functions.
* @details       PDB Sequence Error Notification functions defined by user.
*
*/
[!ENDCODE!][!//
    [!LOOP "text:split($pdbNotifArr, ',')"!][!//
[!CODE!][!//
Pdb_Adc_Ip_SeqErrNotificationType [!"."!];
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Pdb_Interrupt_Delay_Notification"!][!//
[!NOCODE!][!//
[!VAR "pdbNotifArr" = "''"!][!//
[!IF "node:value(AutosarExt/AdcEnablePdbInterruptDelay) = 'true'"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*/PdbHwUnit"!][!//
        [!IF "(AdcPdbInterruptDelayNotification != 'NULL_PTR') and (AdcPdbInterruptDelayNotification != 'NULL') and (AdcPdbInterruptDelayNotification != '')"!][!//
            [!IF "(text:indexOf(text:split($adcNotifArr, ','), node:value(AdcPdbInterruptDelayNotification)) = -1)"!][!//
                [!VAR "pdbNotifArr" = "concat($pdbNotifArr, AdcPdbInterruptDelayNotification, ',')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!IF "($pdbNotifArr != '')"!]
[!CODE!][!//
/**
* @brief         PDB Interrupt Delay Notification functions.
* @details       PDB Interrupt Delay Notification functions defined by user.
*
*/
[!ENDCODE!][!//
    [!LOOP "text:split($pdbNotifArr, ',')"!][!//
[!CODE!][!//
void [!"."!](const uint8 Instance);
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Pdb_Adc_IpConfig" , "MacroGenerationType"!][!// GenerationType='definition' or 'declaration'
[!NOCODE!][!//
    [!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
    [!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
        [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
            [!IF "(AdcLogicalUnitId = $Unit)"!][!//
                [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]
                    [!VAR "CurrentPartition" = "substring-after(substring-after(substring-after(substring-after(AdcHwUnitEcucPartitionRef/*[@index = "0"],'/'),'/'),'/'),'/')"!][!//
                [!ENDIF!][!//
                [!VAR "AdcPdbChannelBackToBack" = "'FALSE'"!]
                    [!IF "(ecu:get('Adc.Pdb.ChannelBackToBack') = 'TRUE')"!]
                        [!IF "node:value(PdbHwUnit/PdbInterChnBackToBackEnable)"!]
                            [!VAR "AdcPdbChannelBackToBack" = "'TRUE'"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!IF "$MacroGenerationType = 'declaration'"!]
[!CODE!][!//
/**
* @brief          PDB Ip Config for Hardware Unit [!"AdcHwUnitId"!] for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
extern const Pdb_Adc_Ip_ConfigType PdbAdcIpConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!];

[!ENDCODE!][!//
                [!ELSE!]
                    [!VAR "seqErrNotification" = "node:value(PdbHwUnit/AdcPdbErrorNotification)"!]
                    [!IF "$seqErrNotification != 'NULL_PTR'"!]
                        [!VAR "seqErrNotification" = "concat('&', $seqErrNotification)"!]
                    [!ENDIF!]
[!CODE!][!//
/**
* @brief          PDB Ip Config for Hardware Unit [!"AdcHwUnitId"!] for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] [!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!][!"$CurrentPartition"!][!ENDIF!].
*/
const Pdb_Adc_Ip_ConfigType PdbAdcIpConfig_[!"AdcLogicalUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "node:value(../../../AutosarExt/AdcMultiPartitionSupport)='true'"!]_[!"$CurrentPartition"!][!ENDIF!] =
{
    PDB_ADC_IP_LOAD_VAL_IMMEDIATELY, /* LoadValueMode */[!// Hardcoded
    (Pdb_Adc_Ip_ClkPrescalerDivType) [!"node:value(PdbHwUnit/AdcPdbPrescalerDividerSelect)"!]U, /* PrescalerDiv */
    (Pdb_Adc_Ip_ClkPrescalerMultFactType) [!"node:value(PdbHwUnit/AdcPdbMultiplicationFactorSelect)"!]U, /* ClkPreMultFactor */
    PDB_ADC_IP_SOFTWARE_TRIGGER, /* TriggerSource */[!// Changed at runtime
    (boolean)FALSE, /* ContinuousModeEnable */
    (boolean)FALSE, /* DmaEnable */
    [!"node:value(PdbHwUnit/AdcPdbCounterPeriod)"!]U, /* ModValue */
#if  (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK)
    (boolean)FALSE, /* InstanceBackToBackEnable */[!// Hardcoded
#endif /* (STD_ON == FEATURE_PDB_HAS_INSTANCE_BACKTOBACK) */
#if  (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK)
    (boolean)[!"$AdcPdbChannelBackToBack"!], /* InterChannelBackToBackEnable */
#endif /* (STD_ON == FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK) */
    0u, /* NumChans */[!// Configured at runtime
    NULL_PTR, /* ChanConfigs */[!// Configured at runtime
    [!"$seqErrNotification"!], /* SeqErrNotification */
[!IF "node:value(../../../AutosarExt/AdcEnablePdbInterruptDelay)='true'"!]
#if (PDB_ADC_IP_ENABLE_INTERRUPT_DELAY == STD_ON)
    [!"node:value(PdbHwUnit/AdcPdbInterruptDelayPeriod)"!]U, /* Interrupt Delay Period */
    [!"node:value(PdbHwUnit/AdcPdbInterruptDelayNotification)"!] /* Interrupt Delay notification */
#endif /* (PDB_ADC_IP_ENABLE_INTERRUPT_DELAY == STD_ON) */
[!ENDIF!]
};

[!ENDCODE!][!//
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!]


[!MACRO "Adc_Ip_CfgDefines"!][!//
#define ADC_IP_DEV_ERROR_DETECT                [!IF "AutosarExt/AdcIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define ADC_IP_TIMEOUT_TYPE                    ([!"AutosarExt/AdcTimeoutMethod"!])
#define ADC_IP_TIMEOUT_VAL                     ([!"AutosarExt/AdcTimeoutVal"!]UL)
#define ADC_IP_ASYNC_CALIBARTION_ENABLED       [!IF "AutosarExt/AdcEnableAsyncCalibration"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!NOCODE!][!//
    [!VAR "EnableConvCompleteString" = "'STD_OFF'"!]
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!]
        [!IF "AdcTransferType = 'ADC_INTERRUPT'"!]
            [!LOOP "AdcGroup/*[AdcWithoutInterrupts = 'false']"!]
                [!VAR "EnableConvCompleteString" = "'STD_ON'"!]
                [!BREAK!]
            [!ENDLOOP!]
        [!ENDIF!][!// End of checking TransferType is ADC_INTERRUPT
    [!ENDLOOP!][!// End of loop all HW Units configured
[!CODE!][!//
#define ADC_IP_AIEN_INTERRUPT_ENABLE           ([!"$EnableConvCompleteString"!])
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!VAR "AdcIpEnableUserMode" = "'STD_OFF'"!]
[!IF "AutosarExt/AdcEnableUserModeSupport"!][!//
    [!IF "(ecu:get('Adc.AdcAdcRegProtAvailable') = 'TRUE')"!][!//
        [!VAR "AdcIpEnableUserMode" = "'STD_ON'"!][!//
    [!ELSE!]
        [!IF "AutosarExt/AdcEnableSimSupplyMonitor"!]
            [!VAR "AdcIpEnableUserMode" = "'STD_ON'"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!CODE!][!//
#define ADC_IP_ENABLE_USER_MODE_SUPPORT        ([!"$AdcIpEnableUserMode"!])
[!ENDCODE!][!//
[!ENDNOCODE!][!//
#define ADC_IP_SUPPLY_MONITORING_ENABLED       [!IF "AutosarExt/AdcEnableSimSupplyMonitor"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define ADC_IP_ENABLE_SIM_SOURCE_SELECTION     (STD_OFF)
[!NOCODE!][!//
[!VAR "AdcIpOptimizeGetConvData" = "'STD_OFF'"!]
[!IF "AutosarExt/AdcEnableReadRawDataApi"!][!//
    [!IF "AutosarExt/AdcIpOptimizeGetConvData"!]
        [!VAR "AdcIpOptimizeGetConvData" = "'STD_ON'"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
#define ADC_IP_OPTIMIZE_GET_CONV_DATA          ([!"$AdcIpOptimizeGetConvData"!])
/*! @brief ADC default Sample Time from RM */
#define ADC_IP_DEFAULT_SAMPLE_TIME             (0x0CU)
/*! @brief ADC default User Gain from RM */
#define ADC_IP_DEFAULT_USER_GAIN               (0x04U)

[!NOCODE!][!//
    [!VAR "AdcMaxExtID" = "0"!][!//
    [!FOR "idx" = "1" TO "num:i(count(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')))"!][!//
        [!IF "contains((ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')[num:i($idx)]), 'SE') = 'true'"!][!//
            [!VAR "TempChan" = "substring-before(substring-after((ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')[num:i($idx)]),'SE'), '_')"!][!//
            [!IF "$TempChan > $AdcMaxExtID"!][!//
                [!VAR "AdcMaxExtID" = "$TempChan"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDFOR!][//
[!ENDNOCODE!][!//
/*! @brief ADC Max external channel ID */
#define FEATURE_ADC_MAX_EXT_CHAN_ID            ([!"num:i($AdcMaxExtID)"!]U)
/*! @brief ADC has external channels */
#define ADC_IP_CHANNEL_2_AVAILABLE             ([!IF "contains(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName'), 'SE2_ADCH2')"!]1[!ELSE!]0[!ENDIF!]U)
#define ADC_IP_CHANNEL_8_AVAILABLE             ([!IF "contains(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName'), 'SE8_ADCH8')"!]1[!ELSE!]0[!ENDIF!]U)
#define ADC_IP_CHANNEL_9_AVAILABLE             ([!IF "contains(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName'), 'SE9_ADCH9')"!]1[!ELSE!]0[!ENDIF!]U)

[!IF "AutosarExt/AdcIpOptimizeGetConvData"!][!//
[!CODE!][!//
/*!
 * @brief Enumeration of input channels assignable to a control channel.
 * \n <b>Note 0</b>: entries in this enum are affected by ::FEATURE_ADC_NUM_EXT_CHANS, which is device dependent
 * and controlled from <i>"device_name"_features.h</i> file.
 *
 * \n <b>Note 1</b>: the actual number of external channels may differ between device packages
 * and ADC instances. Reading a channel that is not connected externally, will return a random value within the range.
 * Please refer to the Reference Manual for the maximum number of external channels for each device variant and ADC instance.
 *
 * \n <b>Note 2</b>: ADC_IP_INPUTCHAN_SUPPLY_ select which internal supply channel to be measured.
 * They are only available for ADC0 and measured internally via internal input channel 0.
 * Please note that supply monitoring needs to be enabled separately via dedicated flag in adc_converter_config_t.
 *
 * Implements : Adc_Ip_InputChannelType_Class
 */
typedef enum
{
    ADC_IP_INPUTCHAN_EXT0_VAL      = 0x00U,                 /*!< External input channel 0 */
    ADC_IP_INPUTCHAN_EXT1_VAL      = 0x01U,                 /*!< External input channel 1 */
#if (ADC_IP_CHANNEL_2_AVAILABLE)
    ADC_IP_INPUTCHAN_EXT2_VAL      = 0x02U,                 /*!< External input channel 2 */
#endif /* (ADC_IP_CHANNEL_2_AVAILABLE) */
    ADC_IP_INPUTCHAN_EXT3_VAL      = 0x03U,                 /*!< External input channel 3 */
    ADC_IP_INPUTCHAN_EXT4_VAL      = 0x04U,                 /*!< External input channel 4 */
    ADC_IP_INPUTCHAN_EXT5_VAL      = 0x05U,                 /*!< External input channel 5 */
    ADC_IP_INPUTCHAN_EXT6_VAL      = 0x06U,                 /*!< External input channel 6 */
    ADC_IP_INPUTCHAN_EXT7_VAL      = 0x07U,                 /*!< External input channel 7 */
#if (ADC_IP_CHANNEL_8_AVAILABLE)
    ADC_IP_INPUTCHAN_EXT8_VAL      = 0x08U,                 /*!< External input channel 8 */
#endif /* (ADC_IP_CHANNEL_8_AVAILABLE) */
#if (ADC_IP_CHANNEL_9_AVAILABLE)
    ADC_IP_INPUTCHAN_EXT9_VAL      = 0x09U,                 /*!< External input channel 9 */
#endif /* (ADC_IP_CHANNEL_9_AVAILABLE) */
    ADC_IP_INPUTCHAN_EXT10_VAL     = 0x0AU,                 /*!< External input channel 10 */
    ADC_IP_INPUTCHAN_EXT11_VAL     = 0x0BU,                 /*!< External input channel 11 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 11u)
    ADC_IP_INPUTCHAN_EXT12_VAL     = 0x0CU,                 /*!< External input channel 12 */
    ADC_IP_INPUTCHAN_EXT13_VAL     = 0x0DU,                 /*!< External input channel 13 */
    ADC_IP_INPUTCHAN_EXT14_VAL     = 0x0EU,                 /*!< External input channel 14 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 14u)
    ADC_IP_INPUTCHAN_EXT15_VAL     = 0x0FU,                 /*!< External input channel 15 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 15u)
    ADC_IP_INPUTCHAN_EXT16_VAL     = 0x20U,                 /*!< External input channel 16 */
    ADC_IP_INPUTCHAN_EXT17_VAL     = 0x21U,                 /*!< External input channel 17 */
    ADC_IP_INPUTCHAN_EXT18_VAL     = 0x22U,                 /*!< External input channel 18 */
    ADC_IP_INPUTCHAN_EXT19_VAL     = 0x23U,                 /*!< External input channel 19 */
    ADC_IP_INPUTCHAN_EXT20_VAL     = 0x24U,                 /*!< External input channel 20 */
    ADC_IP_INPUTCHAN_EXT21_VAL     = 0x25U,                 /*!< External input channel 21 */
    ADC_IP_INPUTCHAN_EXT22_VAL     = 0x26U,                 /*!< External input channel 22 */
    ADC_IP_INPUTCHAN_EXT23_VAL     = 0x27U,                 /*!< External input channel 23 */
#if (FEATURE_ADC_MAX_EXT_CHAN_ID > 23u)
    ADC_IP_INPUTCHAN_EXT24_VAL     = 0x28U,                 /*!< External input channel 24 */
    ADC_IP_INPUTCHAN_EXT25_VAL     = 0x29U,                 /*!< External input channel 25 */
    ADC_IP_INPUTCHAN_EXT26_VAL     = 0x2AU,                 /*!< External input channel 26 */
    ADC_IP_INPUTCHAN_EXT27_VAL     = 0x2BU,                 /*!< External input channel 27 */
    ADC_IP_INPUTCHAN_EXT28_VAL     = 0x2CU,                 /*!< External input channel 28 */
    ADC_IP_INPUTCHAN_EXT29_VAL     = 0x2DU,                 /*!< External input channel 29 */
    ADC_IP_INPUTCHAN_EXT30_VAL     = 0x2EU,                 /*!< External input channel 30 */
    ADC_IP_INPUTCHAN_EXT31_VAL     = 0x2FU,                 /*!< External input channel 31 */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 23u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 15u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 14u) */
#endif /* (FEATURE_ADC_MAX_EXT_CHAN_ID > 11u) */

    ADC_IP_INPUTCHAN_INT0_VAL      = 0x15,                  /*!< Internal input channel 0  */
    ADC_IP_INPUTCHAN_INT1_VAL      = 0x16,                  /*!< Internal input channel 1  */
    ADC_IP_INPUTCHAN_INT2_VAL      = 0x17,                  /*!< Internal input channel 2  */
    ADC_IP_INPUTCHAN_INT3_VAL      = 0x1C,                  /*!< Internal input channel 3  */

    ADC_IP_INPUTCHAN_TEMP_VAL      = 0x1A,                  /*!< Temperature Sensor            */
    ADC_IP_INPUTCHAN_BANDGAP_VAL   = 0x1B,                  /*!< Band Gap                      */
    ADC_IP_INPUTCHAN_VREFH_VAL     = 0x1D,                  /*!< Voltage Reference Select High */
    ADC_IP_INPUTCHAN_VREFL_VAL     = 0x1E,                  /*!< Voltage Reference Select Low  */

#if (STD_ON == ADC_IP_SUPPLY_MONITORING_ENABLED)
                                                        /*!< The following channels are measured via internal input channel 0 */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_VAL            = 0xF00U,    /*!< Monitor internal supply 5 V input VDD supply.              */
    ADC_IP_INPUTCHAN_SUPPLY_VDDA_VAL           = 0xF01U,    /*!< Monitor internal supply 5 V input analog supply.           */
    ADC_IP_INPUTCHAN_SUPPLY_VREFH_VAL          = 0xF02U,    /*!< Monitor internal supply ADC reference supply.              */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_3V_VAL         = 0xF03U,    /*!< Monitor internal supply 3.3 V oscillator regulator output. */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_FLASH_3V_VAL   = 0xF04U,    /*!< Monitor internal supply 3.3 V flash regulator output.      */
    ADC_IP_INPUTCHAN_SUPPLY_VDD_LV_VAL         = 0xF05U    /*!< Monitor internal supply 1.2 V core regulator output.       */
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
} Adc_Ip_InputChannelValueType;

/*!
 * @brief Enumeration of input channels assignable to a control channel.
 * \n <b>Note 0</b>: entries in this enum are affected by ::FEATURE_ADC_NUM_EXT_CHANS, which is device dependent
 * and controlled from <i>"device_name"_features.h</i> file.
 *
 * \n <b>Note 1</b>: the actual number of external channels may differ between device packages
 * and ADC instances. Reading a channel that is not connected externally, will return a random value within the range.
 * Please refer to the Reference Manual for the maximum number of external channels for each device variant and ADC instance.
 *
 * \n <b>Note 2</b>: ADC_IP_INPUTCHAN_SUPPLY_ select which internal supply channel to be measured.
 * They are only available for ADC0 and measured internally via internal input channel 0.
 * Please note that supply monitoring needs to be enabled separately via dedicated flag in adc_converter_config_t.
 *
 * Implements : Adc_Ip_InputChannelType_Class
 */

typedef enum
{
[!ENDCODE!][!//
[!NOCODE!]
[!VAR "AdcMaxNumberOfChannels" = "num:i(count(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')))"!][!//
[!VAR "NumberOfChannels" = "0"!]
[!FOR "idx" = "1" TO "$AdcMaxNumberOfChannels"!][!//
    [!VAR "AdcChannelListName" = "ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')[num:i($idx)]"!]
    [!VAR "InputChannelString" = "'ADC_IP_INPUTCHAN_'"!]
    [!IF "contains($AdcChannelListName, '_INT0_ADCH21')"!]
        [!IF "node:value(AutosarExt/AdcEnableSimSupplyMonitor) = 'true'"!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'SUPPLY_', substring-before($AdcChannelListName, '_INT0_ADCH21'))"!]
            [!VAR "NumberOfChannels" = "$NumberOfChannels + num:i(1)"!]
        [!ENDIF!]
    [!ELSEIF "contains($AdcChannelListName, 'BANDGAP') or contains($AdcChannelListName, 'VREF')"!]
        [!VAR "InputChannelString" = "concat($InputChannelString, substring-before($AdcChannelListName, '_ADCH'))"!]
        [!VAR "NumberOfChannels" = "$NumberOfChannels + num:i(1)"!]
    [!ELSE!]
        [!IF "substring-after($AdcChannelListName, 'ADCH') > 15"!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', (substring-after($AdcChannelListName, 'ADCH') - 16))"!]
        [!ELSE!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', substring-after($AdcChannelListName, 'ADCH'))"!]
        [!ENDIF!]
		[!VAR "NumberOfChannels" = "$NumberOfChannels + num:i(1)"!]
    [!ENDIF!]
    [!VAR "InputChannelString" = "concat($InputChannelString,' = ', num:i($NumberOfChannels) - 1)"!]
	[!VAR "NumberOfChannels" = "num:i($NumberOfChannels)"!]
[!IF "not(contains($InputChannelString, 'ADC_IP_INPUTCHAN_ = '))"!]
[!CODE!][!//
    [!"$InputChannelString"!]U,
[!ENDCODE!][!//
[!ENDIF!]
[!ENDFOR!][!//
[!NOCODE!]
[!VAR "AdcMaxNumberOfChannelsString" = "concat('ADC_IP_INPUTCHAN_MAX_INDEX = ', $NumberOfChannels)"!][!//
[!ENDNOCODE!]
[!CODE!][!//
    ADC_IP_INPUTCHAN_DISABLED  = ADC_SC1_ADCH_MASK,     /*!< Channel disabled          */
    [!"$AdcMaxNumberOfChannelsString"!]U
} Adc_Ip_InputChannelType;
[!ENDCODE!][!//
[!ENDNOCODE!]

[!CODE!][!//
/*!
    @brief Mapping array of input channel to indexes. Each element represents an input channel value that is assign to its corresponding index.
*/
[!NOCODE!][!//
[!VAR "AdcMaxNumberOfChannels" = "num:i(count(ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')))"!][!//
[!ENDNOCODE!][!//
#define IP_MAP_INDEX_TO_CHANNEL { \
[!NOCODE!][!//
[!VAR "FirstElementAdded" = "'FALSE'"!][!//
[!FOR "idx" = "1" TO "$AdcMaxNumberOfChannels"!][!//
    [!VAR "AdcChannelListName" = "ecu:list('Adc.AdcConfigSet.AdcHwUnit.AdcChannel.AdcChannelName')[num:i($idx)]"!]
    [!VAR "InputChannelString" = "'ADC_IP_INPUTCHAN_'"!]
    [!IF "contains($AdcChannelListName, '_INT0_ADCH21')"!]
        [!IF "node:value(AutosarExt/AdcEnableSimSupplyMonitor) = 'true'"!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'SUPPLY_', substring-before($AdcChannelListName, '_INT0_ADCH21'))"!]
        [!ENDIF!]
    [!ELSEIF "contains($AdcChannelListName, 'BANDGAP') or contains($AdcChannelListName, 'VREF')"!]
        [!VAR "InputChannelString" = "concat($InputChannelString, substring-before($AdcChannelListName, '_ADCH'))"!]
    [!ELSE!]
        [!IF "substring-after($AdcChannelListName, 'ADCH') > 15"!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', (substring-after($AdcChannelListName, 'ADCH') - 16))"!]
        [!ELSE!]
            [!VAR "InputChannelString" = "concat($InputChannelString, 'EXT', substring-after($AdcChannelListName, 'ADCH'))"!]
        [!ENDIF!]
    [!ENDIF!]
	[!IF "$FirstElementAdded = 'TRUE'"!]
        [!VAR "InputChannelString" = "concat(',(Adc_Ip_InputChannelType) ',$InputChannelString,'_VAL')"!]
    [!ELSE!]
        [!VAR "InputChannelString" = "concat('(Adc_Ip_InputChannelType) ',$InputChannelString,'_VAL')"!]
    [!ENDIF!]
[!IF "not(contains($InputChannelString, 'ADC_IP_INPUTCHAN__VAL'))"!]
[!VAR "FirstElementAdded" = "'TRUE'"!][!//
[!CODE!][!//
	[!"$InputChannelString"!] \
[!ENDCODE!][!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDNOCODE!][!//
} \
[!ENDCODE!][!//

[!ENDIF!][!//

[!ENDMACRO!][!//

[!MACRO "Pdb_Adc_Ip_CfgDefines"!][!//
/* @brief PDB has instance back to back mode between PDB0 CH0 and PDB1 CH0 pre-triggers */
#define FEATURE_PDB_HAS_INSTANCE_BACKTOBACK     (STD_OFF)

/* @brief PDB has inter-channel back to back mode between PDBx CH0 and PDBx CH1 pre-triggers */
#define FEATURE_PDB_HAS_INTERCHANNEL_BACKTOBACK [!IF "(ecu:get('Adc.Pdb.ChannelBackToBack') = 'TRUE') and (AutosarExt/AdcEnablePdbInterChannelBackToBackSupport = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define PDB_ADC_IP_DEV_ERROR_DETECT             [!IF "AutosarExt/PdbIpDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!IF "AutosarExt/AdcEnableUserModeSupport"!][!//
#define PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT     [!IF "(ecu:get('Adc.AdcPdbRegProtAvailable') = 'TRUE') or (AutosarExt/AdcEnablePdbInterChannelBackToBackSupport = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define PDB_ADC_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

[!ENDIF!][!//
#define PDB_ADC_IP_ENABLE_INTERRUPT_DELAY       [!IF "AutosarExt/AdcEnablePdbInterruptDelay"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ENDMACRO!][!//


[!MACRO "CheckUniqueDmaChannel"!][!//
[!NOCODE!][!//
[!VAR "DmaChnArr" = "''"!][!//
[!VAR "CheckingStatus" = "'TRUE'"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*[AdcTransferType = 'ADC_DMA']"!][!//
        [!IF "node:exists(AdcDmaChannelId)"!][!//
            [!IF "(text:indexOf(text:split($DmaChnArr, ','), node:value(AdcDmaChannelId)) = -1)"!][!//
                [!VAR "DmaChnArr" = "concat($DmaChnArr, AdcDmaChannelId, ',')"!][!//
            [!ELSE!]
                [!VAR "CheckingStatus" = "'FALSE'"!][!//
                [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!LOOP "AdcGroup/*[((AdcEnableOptimizeDmaStreamingGroups = 'true') and (count(AdcGroupDefinition/*) > 1)) or ((AdcWithoutInterrupts = 'true') and (AdcGroupAccessMode = 'ADC_ACCESS_MODE_STREAMING'))]"!][!//
            [!IF "node:exists(../../AdcCountingDmaChannelId)"!][!//
                [!IF "(text:indexOf(text:split($DmaChnArr, ','), node:value(../../AdcCountingDmaChannelId)) = -1)"!][!//
                    [!VAR "DmaChnArr" = "concat($DmaChnArr, ../../AdcCountingDmaChannelId, ',')"!][!//
                [!ELSE!]
                    [!VAR "CheckingStatus" = "'FALSE'"!][!//
                [!ENDIF!][!//
                [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!IF "($CheckingStatus = 'FALSE')"!]
        [!ERROR!][!//
            [!"'DMA Channel cannot be shared among Adc configurations.'"!][!//
        [!ENDERROR!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

/** @} */
[!ENDIF!]
