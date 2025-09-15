[!NOCODE!]
/**
    @file    Power_Ip_RegOperations.m
    @version 3.0.0

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.7
    Platform CORTEXM
    Peripheral 
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530

    Copyright 2020-2025 NXP

    NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
 */



[!MACRO "Power_Ip_Mode_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief          Initialization mode data.
* @details        Static configuration realized by calling Mcu_SetMode() API.
*
*/
const Power_Ip_ModeConfigType Power_Ip_aModeConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
        [!VAR "ModeConfigs"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
        [!IF "node:exists(McuPowerEcucPartitionRef)"!]
            [!VAR "PartitionRefName" = "node:value("McuPowerEcucPartitionRef")"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($PartitionRefName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!LOOP "as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!]
                [!IF "$CurrentPartitionShortName = node:name(.)"!]                 
                    [!VAR "CurrentPartitionId" = "node:pos(.)"!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
[!CODE!][!//
    /* Start of Mcu_aModeConfig[[!"@index"!]] */
    {
[!ENDCODE!][!//
        [!VAR "PCindex" = "@index"!]
[!CODE!][!//
[!IF "node:exists(McuPowerEcucPartitionRef)"!]
#if (POWER_IP_MULTIPARTITION_SUPPORT == STD_ON)
        /* The ID for Partition. */
        (uint8)POWER_IP_PARTITION_[!"num:i($CurrentPartitionId)"!],
#endif
[!ENDIF!]
        /* Mode Configuration ID. */
        (Power_Ip_ModeType)[!"num:i(McuMode)"!]U,

        /* The Power Mode name (code). */
        POWER_IP_[!"McuPowerMode"!]_MODE,

        /* The Sleep On Exit configuration */
        [!IF "McuEnableSleepOnExit='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }[!IF "$PCindex < $ModeConfigs"!],[!ENDIF!] /* End of Mcu_aModeConfig[[!"@index"!]] */
[!ENDCODE!][!//
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDIF!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Power_Ip_PMC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_PMC_ConfigType Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!IF "(ecu:get('MCU.PMC.LVDSC1.SUPPORT') = 'true')"!][!//
    /* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1). This register only exist on 1xx series of devices */
    (
        [!IF "McuPowerControl/McuPMC_Config/McuLowVoltageDetectInterruptEnable='true'"!]PMC_LVDSC1_LVD_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVD_DISABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_Config/McuLowVoltageDetectResetEnable='true'"!]PMC_LVDSC1_LVDRE_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVDRE_DISABLE_U8[!ENDIF!]
    ),
    [!ENDIF!][!//
    /* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
    (
        [!IF "McuPowerControl/McuPMC_Config/McuLowVoltageWarningInterruptEnable = 'true'"!]PMC_LVDSC2_LVW_ENABLE_U8[!ELSE!]PMC_LVDSC2_LVW_DISABLE_U8[!ENDIF!]
    ),
    /* Regulator Status and Control Register (PMC_REGSC) */
    (
        [!IF "McuPowerControl/McuPMC_Config/McuLPODisable = 'true'"!]PMC_REGSC_LPO_DISABLE_U8[!ELSE!]PMC_REGSC_LPO_ENABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_Config/McuClockBiasDisable = 'true'"!]PMC_REGSC_CLKBIAS_DISABLE_U8[!ELSE!]PMC_REGSC_CLKBIAS_ENABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_Config/McuLowPowerBiasEnable = 'true'"!]PMC_REGSC_BIAS_ENABLE_U8[!ELSE!]PMC_REGSC_BIAS_DISABLE_U8[!ENDIF!]
    ),
    /* Low Power Oscillator Trim Register Register (PMC_LPOTRIM) */
    (
        PMC_LPOTRIM_[!"McuPowerControl/McuPMC_Config/McuLPOTRIMSelect"!]_U8
    )
    [!IF "(ecu:get('MCU.PMC.AE.SUPPORT') = 'true')"!][!//
    ,
    /* PMC_AE Configuration Register (CONFIG). This register only exist on M2xx series of devices */
    (
        [!IF "McuPowerControl/McuPMC_AE_Config/McuLinphySupplyEnable='true'"!]PMC_AE_CONFIG_LINSUPEN_ENABLE_U32[!ELSE!]PMC_AE_CONFIG_LINSUPEN_DISABLE_U32[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuVDDCEnable='true'"!]PMC_AE_CONFIG_VDDCEN_ENABLE_U32[!ELSE!]PMC_AE_CONFIG_VDDCEN_DISABLE_U32[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuLvdVlsSelect='LVD_6_5V'"!]PMC_AE_CONFIG_LVDVLSSEL_6_5V_U32[!ELSE!]PMC_AE_CONFIG_LVDVLSSEL_5_5V_U32[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuLinphySupplySelect='VSUP_PIN'"!]PMC_AE_CONFIG_LINSUPSEL_VSUP_PIN_U32[!ELSE!]PMC_AE_CONFIG_LINSUPSEL_HD_PIN_U32[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuVddVoltageLevelSelect='VDD_3_3V'"!]PMC_AE_CONFIG_VDDSEL5V_3_3V_U32[!ELSE!]PMC_AE_CONFIG_VDDSEL5V_5V_U32[!ENDIF!]
    ),
    /* PMC_AE Monitor Register (MONITOR). This register only exist on M2xx series of devices */
    (
        [!IF "McuPowerControl/McuPMC_AE_Config/McuLowVoltageDetectInterruptsOnVLSEnable='true'"!]PMC_AE_MONITOR_LVDVLSIE_ENABLE_U32[!ELSE!]PMC_AE_MONITOR_LVDVLSIE_DISABLE_U32[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuLowVoltageDetectInterruptsOnVDDCEnable='true'"!]PMC_AE_MONITOR_LVDCIE_ENABLE_U32[!ELSE!]PMC_AE_MONITOR_LVDCIE_DISABLE_U32[!ENDIF!]  |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuHighVoltageDetectInterruptOnVDDEnable='true'"!]PMC_AE_MONITOR_HVDVDDIE_ENABLE_U32[!ELSE!]PMC_AE_MONITOR_HVDVDDIE_DISABLE_U32[!ENDIF!]  |
        [!IF "McuPowerControl/McuPMC_AE_Config/McuHighVoltageDetectInterruptOnVDDINTAndVDD15Enable='true'"!]PMC_AE_MONITOR_HVDINT15IE_ENABLE_U32[!ELSE!]PMC_AE_MONITOR_HVDINT15IE_DISABLE_U32[!ENDIF!] 
    )
    [!ENDIF!][!//
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_RCM_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/

static const Power_Ip_RCM_ConfigType Power_Ip_RCM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Reset Pin Control register (RCM_RPC) */
    (
        RCM_RPC_STOP_[!"McuResetConfig/McuResetPinFilterInStopMode"!]_U32 |
        RCM_RPC_NORMAL_[!"McuResetConfig/McuResetPinFilterInRunAndWait"!]_U32 |
        RCM_RPC_RSTFLTSEL((uint32)([!"num:i(McuResetConfig/McuResetPinFilterBusClockSelect)"!]U))
    ),
    /* System Reset Interrupt Enable Register (RCM_SRIE) */
    (
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuStopAcknowledgeErrorInterrupt"!]RCM_SRIE_SACKERR_INT_EN_U32[!ELSE!]RCM_SRIE_SACKERR_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuMDMAPSystemResetInterrupt"!]RCM_SRIE_MDM_AP_INT_EN_U32[!ELSE!]RCM_SRIE_MDM_AP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuSoftwareInterrupt"!]RCM_SRIE_SW_INT_EN_U32[!ELSE!]RCM_SRIE_SSW_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuCoreLockupInterrupt"!]RCM_SRIE_LOCKUP_INT_EN_U32[!ELSE!]RCM_SRIE_LOCKUP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuJTAGResetInterrupt"!]RCM_SRIE_JTAG_INT_EN_U32[!ELSE!]RCM_SRIE_JTAG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuGlobalInterrupt"!]RCM_SRIE_GIE_INT_EN_U32[!ELSE!]RCM_SRIE_GIE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuExternalResetPinInterrupt"!]RCM_SRIE_PIN_INT_EN_U32[!ELSE!]RCM_SRIE_PIN_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuWatchdogInterrupt"!]RCM_SRIE_WDOG_INT_EN_U32[!ELSE!]RCM_SRIE_WDOG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuCMULossOfClockResetInterrupt"!]RCM_SRIE_CMU_INT_EN_U32[!ELSE!]RCM_SRIE_CMU_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuLossOfLockInterrupt"!]RCM_SRIE_LOL_INT_EN_U32[!ELSE!]RCM_SRIE_LOL_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuLossOfClockInterrupt"!]RCM_SRIE_LOC_INT_EN_U32[!ELSE!]RCM_SRIE_LOC_INT_DIS_U32[!ENDIF!] |
        RCM_SRIE_[!"McuResetConfig/McuSystemInterruptEnable/McuResetDelayTime"!]_U32
    )
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_SMC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for SMC hw IP.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_SMC_ConfigType Power_Ip_SMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Allowed modes */
    (
        [!IF "McuAllowedModes/McuAllowHighSpeedRunMode = 'true'"!]SMC_PMPROT_HSRUN_ALLOWED_U32[!ELSE!]SMC_PMPROT_HSRUN_NOT_ALLOWED_U32[!ENDIF!] |
        [!IF "McuAllowedModes/McuAllowVeryLowPowerModes = 'true'"!]SMC_PMPROT_VLP_ALLOWED_U32[!ELSE!]SMC_PMPROT_VLP_NOT_ALLOWED_U32[!ENDIF!]
    ),
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Power_Ip_AEC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
#if(STD_ON == POWER_IP_AEC_SUPPORT)
/**
* @brief          Initialization data for AEC_AE_RSTGEN_CFG[RSTGEN_CFG] register
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_AEC_ConfigType Power_Ip_AEC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    (
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuRegsOtpReset = 'true'"!]AEC_AE_RSTGEN_CFG_REGS_OTP_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_REGS_OTP_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuCanPhyReset = 'true'"!]AEC_AE_RSTGEN_CFG_CANPHY_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_CANPHY_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuLinPhyHpReset = 'true'"!]AEC_AE_RSTGEN_CFG_LINPHY_HP_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_LINPHY_HP_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuLinPhyLpReset = 'true'"!]AEC_AE_RSTGEN_CFG_LINPHY_LP_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_LINPHY_LP_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuGduReset = 'true'"!]AEC_AE_RSTGEN_CFG_GDU_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_GDU_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuHviReset = 'true'"!]AEC_AE_RSTGEN_CFG_HVI_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_HVI_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuDpgaReset = 'true'"!]AEC_AE_RSTGEN_CFG_DPGA_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_DPGA_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuTempsensorReset = 'true'"!]AEC_AE_RSTGEN_CFG_TEMPSENSOR_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_TEMPSENSOR_DISABLE_U16[!ENDIF!] |
        [!IF "McuResetConfig/McuResetGeneratorConfiguration/McuCxpiReset = 'true'"!]AEC_AE_RSTGEN_CFG_CXPI_ENABLE_U16[!ELSE!]AEC_AE_RSTGEN_CFG_CXPI_DISABLE_U16[!ENDIF!]
    ),
};
#endif
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Power_Ip_HwIPs_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
const Power_Ip_HwIPsConfigType Power_Ip_HwIPsConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Configuration for RCM (Reset Control Module) hardware IP. */
    &Power_Ip_RCM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for PMC (Power Management Controller) hardware IP */
    &Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for SMC hardware IP. */
    &Power_Ip_SMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
#if (STD_ON == POWER_IP_AEC_SUPPORT)
    /* Configuration for AEC hardware IP. */
    &Power_Ip_AEC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#endif

};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!ENDNOCODE!][!//


