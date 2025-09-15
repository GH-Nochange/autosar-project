[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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
*   @file
*
*   @addtogroup Wdg
*   @{
*/

[!// MACRO for defining mode configuration
[!MACRO "WdogConfig","WdgMode","WdgNo"!][!//
[!NOCODE!]
[!VAR "TimeoutPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgTimeoutPeriod'))"!]
[!VAR "WindowPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowPeriod'))"!]
[!VAR "WdgClockValue" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockValue'))"!]
[!ENDNOCODE!]
    (Wdog_Ip_ClkSourceType)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockSelection')) = 'Bus_Clock'"!]WDOG_IP_BUS_CLOCK[!/*
            */!][!ELSEIF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockSelection')) = 'LPO_Clock'"!]WDOG_IP_LPO_CLOCK[!/*
            */!][!ELSEIF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockSelection')) = 'SOSC_Clock'"!]WDOG_IP_SOSC_CLOCK[!/*
            */!][!ELSEIF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockSelection')) = 'SIRC_Clock'"!]WDOG_IP_SIRC_CLOCK[!ENDIF!],       /* .clkSource */[!/*
            */!]
    {[!CR!]
             (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgRunsInWaitMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],         /* .bWait */
             (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgRunsInStopMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],         /* .bStop */
             (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgRunsInDebugMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!]         /* .bDebug */
    },
    (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgAllowUpdates'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .UpdateEnable */
    (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgOperationMode')) = 'Interrupt'"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .IntEnable */
    (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .WinEnable */
    (uint16) [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowMode'))"!][!/*
                */!][!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgPrescalerEnabled'))"!][!/*
                    */!][!"num:inttohex(num:i((($TimeoutPeriod - $WindowPeriod) * $WdgClockValue * 1000) div 256),4)"!]U[!/*
                */!][!ELSE!][!/*
                    */!][!"num:inttohex(num:i(($TimeoutPeriod - $WindowPeriod) * $WdgClockValue * 1000),4)"!]U[!/*
                */!][!ENDIF!][!/*
            */!][!ELSE!]0x00U[!ENDIF!],                   /* .WindowValue */
    (uint16) [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgPrescalerEnabled'))"!][!/*
    */!][!"num:inttohex(num:i((node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgTimeoutPeriod')) * node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockValue')) * 1000) div 256))"!]U,                   /* .TimeoutValue */[!/*
    */!][!ELSE!][!"num:inttohex(num:i(node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgTimeoutPeriod')) * node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockValue')) * 1000))"!]U,                   /* .TimeoutValue */[!ENDIF!]
    (boolean)[!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgPrescalerEnabled'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .PrescalerEnable */
[!ENDMACRO!]

[!MACRO "EwmConfig","WdgNo"!][!//
[!NOCODE!]
[!VAR "WdgClockVal" = "num:i(node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration/WdgClockValue')))"!]
[!VAR "Prescaler" = "num:i(node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgPrescalerValue')))"!]
[!VAR "TimeoutPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgTimeoutPeriod'))"!]
[!VAR "WindowPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgWindowPeriod'))"!]
[!VAR "CompareHigh" = "num:inttohex(num:i(($TimeoutPeriod * $WdgClockVal * 1000) div ($Prescaler + 1)))"!]
[!VAR "CompareLow" = "num:inttohex(num:i((($TimeoutPeriod - $WindowPeriod) * $WdgClockVal * 1000) div ($Prescaler + 1)))"!]
[!ENDNOCODE!]
    [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgAssertLogic')) = 'Assert_Disabled'"!]EWM_IN_ASSERT_DISABLED[!/*
            */!][!ELSEIF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgAssertLogic')) = 'Assert_OnLogicZero'"!]EWM_IN_ASSERT_ON_LOGIC_ZERO[!/*
            */!][!ELSEIF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgAssertLogic')) = 'Assert_OnLogicOne'"!]EWM_IN_ASSERT_ON_LOGIC_ONE[!ENDIF!], /*.assertLogic */[!/*
            */!]
    (boolean)       [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgInterruptEnable'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /*.InterruptEnable */
    (uint8)         [!"num:i(node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgPrescalerValue')))"!]U,                   /*.u8Prescaler */
    (uint8)         [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgWindowMode'))"!][!"$CompareLow"!]U[!ELSE!]0x0U[!ENDIF!],                   /*.u8CompareLow */
    (uint8)         [!"$CompareHigh"!]U,                   /*.u8CompareHigh */
[!ENDMACRO!]

[!MACRO "AeWdogConfig","WdgMode","WdgNo"!][!//
[!NOCODE!]
[!VAR "WatchdogMode" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgWatchdogMode'))"!]
[!VAR "OperationMode" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgOperationMode'))"!]
[!VAR "WindowPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowPeriod'))"!]
[!VAR "ClosedWindowDutyCycle" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClosedWindowDutyCycle'))"!]
[!VAR "BadRespon" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgBadRespon'))"!]
[!ENDNOCODE!]
    (AeWdog_Ip_ModeType)             AEWDOG_IP_[!"$WatchdogMode"!],
    (AeWdog_Ip_FaultRespType)        AEWDOG_IP_[!"$OperationMode"!],
    (AeWdog_Ip_BadRespType)          AEWDOG_IP_BADRESP_[!"$BadRespon"!],
    (AeWdog_Ip_WindowDutyCycleType)  AEWDOG_IP_[!"$ClosedWindowDutyCycle"!],
    (AeWdog_Ip_WindowPeriodType)     AEWDOG_IP_WD_PERIOD_[!"$WindowPeriod"!]
[!ENDMACRO!]

[!MACRO "AeWdogConfigOffmode","WdgMode","WdgNo"!][!//
[!NOCODE!]
[!VAR "WatchdogMode" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgWatchdogMode'))"!]
[!VAR "OperationMode" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgOperationMode'))"!]
[!VAR "BadRespon" = "node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgBadRespon'))"!]
[!ENDNOCODE!]
    (AeWdog_Ip_ModeType)             AEWDOG_IP_[!"$WatchdogMode"!],
    (AeWdog_Ip_FaultRespType)        AEWDOG_IP_[!"$OperationMode"!],
    (AeWdog_Ip_BadRespType)          AEWDOG_IP_BADRESP_[!"$BadRespon"!],
    (AeWdog_Ip_WindowDutyCycleType)  AEWDOG_IP_DUTY_DISABLED,
    (AeWdog_Ip_WindowPeriodType)     AEWDOG_IP_WD_PERIOD_DISABLED
[!ENDMACRO!]

[!ENDNOCODE!]
[!// MACRO for calculating the trigger period
[!MACRO "WdgTriggerPeriod","WdgMode","WdgNo"!][!//
[!NOCODE!]
    [!VAR "WdgTimeoutPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgTimeoutPeriod'))"!]
    [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowMode'))"!]
        [!VAR "WdgWindowPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowPeriod'))"!]
    [!ELSE!]
        [!VAR "WdgWindowPeriod" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "WdgInternalClockVal" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClockValue'))"!]
    [!VAR "WdgTriggerSourceClock" = "num:i(node:value(node:ref(node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgExternalTriggerCounterRef')))/GptChannelTickFrequency)div 1000)"!]
    [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgPrescalerEnabled'))"!]
        [!VAR "Prescaler" = "num:i(256)"!]
    [!ELSE!]
        [!VAR "Prescaler" = "num:i(1)"!]
    [!ENDIF!]

    [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowMode'))"!]
        [!VAR "WdgWindowVal" = "(($WdgTimeoutPeriod - $WdgWindowPeriod) * $WdgInternalClockVal * 1000) div $Prescaler"!]
    [!ELSE!]
        [!VAR "WdgWindowVal" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "WdgTimeoutVal" = "($WdgTimeoutPeriod * $WdgInternalClockVal * 1000) div $Prescaler"!]

[!CODE!][!//
    (uint32) [!"num:inttohex(num:i((($WdgTimeoutVal - (($WdgTimeoutVal - $WdgWindowVal) div 2)) div ($WdgInternalClockVal div $Prescaler)) * $WdgTriggerSourceClock))"!],[!//
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "WdgEwmTriggerPeriod","WdgNo"!][!//
[!NOCODE!]
    [!VAR "WdgInternalClockVal" = "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration/WdgClockValue'))"!]
    [!VAR "WdgTriggerSourceClock" = "node:value(node:ref(node:value(concat($WdgNo,'/WdgSettingsConfig/WdgExternalTriggerCounterRef')))/GptChannelTickFrequency) div 1000"!]
    [!VAR "Prescaler" = "num:i(num:i(node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgPrescalerValue'))) + 1)"!]
    [!VAR "TimeoutPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgTimeoutPeriod'))"!]

    [!IF "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgWindowMode'))"!]
        [!VAR "WindowPeriod" = "node:value(concat($WdgNo,'/WdgSettingsConfig/WdgSettingsConfiguration','/WdgWindowPeriod'))"!]
        [!VAR "CompareLow" = "(($TimeoutPeriod - $WindowPeriod) * $WdgInternalClockVal * 1000) div $Prescaler"!]
    [!ELSE!]
        [!VAR "CompareLow" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "CompareHigh" = "($TimeoutPeriod * $WdgInternalClockVal * 1000) div $Prescaler"!]

[!CODE!][!//
    (uint32) [!"num:inttohex(num:i((($CompareHigh - (($CompareHigh - $CompareLow) div 2)) div ($WdgInternalClockVal div $Prescaler)) * $WdgTriggerSourceClock))"!],
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "WdgAeWdogTriggerPeriod","WdgMode","WdgNo"!][!//
[!NOCODE!]
    [!VAR "temp_AeWdogTimeout" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgWindowPeriod'))"!]
    [!IF "$temp_AeWdogTimeout = 'DISABLED'"!]
        [!VAR "WdgTimeoutPeriod" = "num:i(0)"!]
    [!ELSE!]
        [!VAR "WdgTimeoutPeriod" = "substring-after($temp_AeWdogTimeout,'TIME_')"!]
        [!VAR "WdgTimeoutPeriod" = "substring-before($WdgTimeoutPeriod,'_512')"!]
        [!IF "contains($WdgTimeoutPeriod,'_')='true'"!]
            [!VAR "temp_AeWdogTimeout" = "$WdgTimeoutPeriod"!]
            [!VAR "WdgTimeoutPeriod" = "num:i(num:i((substring-before($temp_AeWdogTimeout,'_')) * num:i(substring-after($temp_AeWdogTimeout,'_')) * 512))"!]
        [!ELSE!]
           [!VAR "WdgTimeoutPeriod" = "num:i(num:i($WdgTimeoutPeriod) * 512)"!]
        [!ENDIF!]
    [!ENDIF!]

    [!VAR "temp_AeWdogDutyCycle" = "node:value(concat($WdgNo,'/WdgSettingsConfig/',$WdgMode,'/WdgClosedWindowDutyCycle'))"!]
    [!IF "$temp_AeWdogDutyCycle = 'DUTY_DISABLED'"!]
        [!VAR "WdgClosedWindowDutyCycle" = "num:i(0)"!]
    [!ELSE!]
        [!VAR "temp_AeWdogDutyCycle" = "substring-after($temp_AeWdogDutyCycle,'DUTY_')"!]
        [!VAR "WdgClosedWindowDutyCycle_integer" = "substring-before($temp_AeWdogDutyCycle,'_')"!]
        [!VAR "WdgClosedWindowDutyCycle_decimal" = "substring-after($temp_AeWdogDutyCycle,'_')"!]
        [!VAR "WdgClosedWindowDutyCycle" = "num:i(num:i($WdgClosedWindowDutyCycle_integer) * 100 + num:i($WdgClosedWindowDutyCycle_decimal))"!]   
    [!ENDIF!]
    [!IF "$WdgClosedWindowDutyCycle > num:i(0)"!]
        [!VAR "WdgClosedWindowPeriod" = "num:i($WdgTimeoutPeriod * $WdgClosedWindowDutyCycle div 10000)"!]
    [!ELSE!]
        [!VAR "WdgClosedWindowPeriod" = "num:i(0)"!]
    [!ENDIF!]

    [!VAR "WdgTriggerSourceClock" = "num:i(node:value(node:ref(node:value(concat($WdgNo,'/WdgSettingsConfig/','WdgExternalTriggerCounterRef')))/GptChannelTickFrequency))div 1000000"!]

    [!VAR "WdgTimeoutVal" = "$WdgTimeoutPeriod"!]

[!CODE!][!//
    (uint32) [!"num:inttohex(num:i( ($WdgTimeoutVal - (($WdgTimeoutVal - $WdgClosedWindowPeriod) div 2))* $WdgTriggerSourceClock))"!],[!//
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "WdgPartitionConfig","WdgNo"!][!//
[!NOCODE!]
[!IF "node:exists($WdgNo)"!][!//
    [!IF "node:value(concat($WdgNo,'/WdgGeneral/WdgEnableMultiPartitionSupport'))"!][!//
        [!VAR "partitionUsed" = "65535"!][!//
        [!VAR "WdgCrtPart" = "node:value(concat($WdgNo,'/WdgGeneral/WdgEcucPartitionRef'))"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "$WdgCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//​
                [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//​
                    [!VAR "partitionUsed" ="node:pos(.)"!][!//​
                [!ENDSELECT!][!//
            [!ENDIF!][!//​
        [!ENDLOOP!][!//
        [!IF "$partitionUsed = 65535"!][!//
            [!ERROR!][!//
                "Os appication is not configured for [!"text:split($WdgCrtPart,'/')[5]"!]"[!//
            [!ENDERROR!][!//
        [!ELSE!][!CODE!][!"$partitionUsed"!][!ENDCODE!][!ENDIF!][!//
    [!ELSE!]
        [!CODE!]0xFFFF[!ENDCODE!]
    [!ENDIF!][!//
[!ELSE!]
    [!CODE!]0xFFFF[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!]