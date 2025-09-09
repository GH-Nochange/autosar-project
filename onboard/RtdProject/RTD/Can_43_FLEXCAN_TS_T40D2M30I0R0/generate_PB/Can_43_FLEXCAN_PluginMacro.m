[!NOCODE!]
/**
  @file    Can_PluginMacro.m
  @version 3.0.0

  @brief   AUTOSAR Can_43_FLEXCAN - macros.
  @details Macros

  Project RTD AUTOSAR 4.7
  Platform CORTEXM
  Peripheral FLEXCAN
  Dependencies 

  ARVersion 4.7.0
  ARRevision ASR_REL_4_7_REV_0000
  ARConfVariant
  SWVersion 3.0.0
  BuildVersion S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530

  Copyright 2020-2025 NXP
  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
  used strictly in accordance with the applicable license terms. By expressly
  accepting such terms or by downloading, installing, activating and/or otherwise
  using the software, you are agreeing that you have read, and that you agree to
  comply with and are bound by, such license terms. If you do not agree to be
  bound by the applicable license terms, then you may not retain, install,
  activate or otherwise use the software.

/*==================================================================================================
==================================================================================================*/
[!IF "not(var:defined('CAN_PLUGINMACRO_M'))"!]
[!VAR "CAN_PLUGINMACRO_M"="'true'"!]
[!/***********************Can export driver configuration Macro ****************************************/!]
[!MACRO "CanExportDriverConfiguration"!]
[!NOCODE!]
    [!VAR "configName" = "as:name(./CanConfigSet)"!]
    [!CODE!]#define CAN_43_FLEXCAN_CONF_PB \[!ENDCODE!][!CR!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "variantIndex"="0"!]
        [!VAR "variantNumber"="variant:size()"!]
        [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!]
            [!CODE!][!WS "4"!]extern const Can_43_FLEXCAN_ConfigType Can_43_FLEXCAN_Config_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!]
    [!ELSE!]
        [!CODE!][!WS "4"!]extern const Can_43_FLEXCAN_ConfigType Can_43_FLEXCAN_Config;[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!/***********************Can Notification Config Macro ****************************************/!]
[!MACRO "Can_NotificationHandler"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "CanConfigSet/CanController/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "WarnMatchCounter" = "0"!]
        [!VAR "OvfMatchCounter" = "0"!]
        [!VAR "DmaErrMatchCounter" = "0"!]
        [!VAR "WarnNotification" = "0"!]
        [!VAR "OvfNotification" = "0"!]
        [!VAR "DmaErrorNotification" = "0"!]
        [!IF "node:exists(./CanRxFiFo)"!]
            [!IF "node:name(./CanRxFiFo) = 'CanLegacyFiFo'"!]
                [!IF "./CanRxFiFo/CanLegacyFiFoDmaEnable = 'true'"!]
                    [!VAR "DmaErrorNotification" = "normalize-space(./CanRxFiFo/CanFiFoDmaErrorNotif)"!]
                [!ELSE!]
                [!VAR "WarnNotification" = "normalize-space(./CanRxFiFo/CanFiFoWarnNotif)"!]
                [!VAR "OvfNotification" = "normalize-space(./CanRxFiFo/CanFiFoOverflowNotif)"!]
                [!ENDIF!]
            [!ELSE!]
                [!IF "./CanRxFiFo/CanEnhanceFiFoDmaEnable = 'true'"!]
                    [!VAR "DmaErrorNotification" = "normalize-space(./CanRxFiFo/CanFiFoDmaErrorNotif)"!]
                [!ELSE!]
                    [!VAR "OvfNotification" = "normalize-space(./CanRxFiFo/CanFiFoOverflowNotif)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
        [!LOOP "../*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "node:exists(./CanRxFiFo)"!]
                [!IF "node:name(./CanRxFiFo) = 'CanLegacyFiFo'"!]
                    [!IF "./CanRxFiFo/CanLegacyFiFoDmaEnable = 'true'"!]
                        [!IF "./CanRxFiFo/CanFiFoDmaErrorNotif != 'NULL_PTR'"!]
                            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                                [!IF "$DmaErrorNotification = ./CanRxFiFo/CanFiFoDmaErrorNotif"!]
                                    [!VAR "DmaErrMatchCounter" = "$DmaErrMatchCounter + 1"!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ELSE!]
                    [!IF "./CanRxFiFo/CanFiFoWarnNotif != 'NULL_PTR'"!]
                        [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                            [!IF "$WarnNotification = ./CanRxFiFo/CanFiFoWarnNotif"!]
                                [!VAR "WarnMatchCounter" = "$WarnMatchCounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                    [!IF "./CanRxFiFo/CanFiFoOverflowNotif != 'NULL_PTR'"!]
                        [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                            [!IF "$OvfNotification = ./CanRxFiFo/CanFiFoOverflowNotif"!]
                                [!VAR "OvfMatchCounter" = "$OvfMatchCounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "./CanRxFiFo/CanEnhanceFiFoDmaEnable = 'true'"!]
                        [!IF "./CanRxFiFo/CanFiFoDmaErrorNotif != 'NULL_PTR'"!]
                            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                                [!IF "$DmaErrorNotification = ./CanRxFiFo/CanFiFoDmaErrorNotif"!]
                                    [!VAR "DmaErrMatchCounter" = "$DmaErrMatchCounter + 1"!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!IF "./CanRxFiFo/CanFiFoOverflowNotif != 'NULL_PTR'"!]
                            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                                [!IF "$OvfNotification = ./CanRxFiFo/CanFiFoOverflowNotif"!]
                                    [!VAR "OvfMatchCounter" = "$OvfMatchCounter + 1"!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$WarnMatchCounter = 1"!]
            [!CODE!]extern void [!"normalize-space(./CanRxFiFo/CanFiFoWarnNotif)"!](void);[!CR!][!ENDCODE!]
        [!ENDIF!]
        [!IF "$OvfMatchCounter = 1"!]
            [!CODE!]extern void [!"normalize-space(./CanRxFiFo/CanFiFoOverflowNotif)"!](void);[!CR!][!ENDCODE!]
        [!ENDIF!]
         [!IF "$DmaErrMatchCounter = 1"!]
            [!CODE!]extern void [!"normalize-space(./CanRxFiFo/CanFiFoDmaErrorNotif)"!](void);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]
[!ENDIF!]
[!ENDNOCODE!]