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


#ifndef WDG_IPW_CFG_DEFINES_H
#define WDG_IPW_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup  Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "num:i($i) = 0"!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#include "Wdog_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 1"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#include "Ewm_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 2"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#include "AeWdog_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_CFG_DEFINES_VENDOR_ID                    43
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION             3
#define WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "num:i($i) = 2"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != AEWDOG_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and AeWdog_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and AeWdog_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and AeWdog_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 1"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != EWM_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != EWM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != EWM_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 0"!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != WDOG_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != WDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != WDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != WDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != WDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!VAR "WdgInstanceCount" = "0"!][!//
/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "num:i($i) = 2"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE2      (AEWDOG_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 1"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE1      (EWM_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 0"!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE0      (WDOG_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
  * @brief  This constant specifies the hardware used or not.
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!VAR "isAeWdogAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "num:i($i) = 2"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#define AEWDOG_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 1"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define EWM_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 0"!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDOG_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!IF "num:i($i) = 2"!]
            [!IF "$isAeWdogAvailable = 0"!]
                [!VAR "isAeWdogAvailable" = "1"!]
                [!CODE!]#define AEWDOG_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 1"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define EWM_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "num:i($i) = 0"!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDOG_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
    [!IF "$isAeWdogAvailable = 0"!]
        [!CODE!]#define AEWDOG_IP_USED   (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
    [!IF "$isEwmAvailable = 0"!]
        [!CODE!]#define EWM_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
    [!IF "$isWdogAvailable = 0"!]
        [!CODE!]#define WDOG_IP_USED     (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdgDisableForbid"     = "0"!]
[!VAR "isWdgDisableAllowed"    = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "contains(ecu:list('Wdg.WdgInstance')[$i + 1], 'EWM')"!]
        [!ELSE!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgDisableAllowed'))"!]
                [!VAR "isWdgDisableAllowed" = "1"!]
                [!IF "num:i($isWdgDisableForbid) = 1"!]
                    [!ERROR!]The "Wdg Disable Allowed" node must be enabled or disabled for all instances[!ENDERROR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "isWdgDisableForbid" = "1"!]
                [!IF "num:i($isWdgDisableAllowed) = 1"!]
                    [!ERROR!]The "Wdg Disable Allowed" node must be enabled or disabled for all instances[!ENDERROR!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
[!CODE!]#define WDG_IPW_DEINIT ([!IF "$isWdgDisableAllowed = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]

/**
* @brief  Defines indicating for which Wdg instances the ISR for is supported
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "enableISR" = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "ecu:list('Wdg.WdgInstance')[$i + 1] != 'AEWDOG'"!]
            [!IF "num:i($i) > 0"!]
                [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
            [!ELSE!]
                [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
            [!ENDIF!]
            [!IF "node:exists($xPathModule)"!]
                    [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED ([!"ecu:list('Wdg.WdgInstance')[$i + 1]"!]_IP_ISR0_USED)[!ENDCODE!][!CR!]
            [!ELSE!]
                [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "num:i(ecu:get('Wdg.Num.Of.Instances')) = 1"!]
        [!CODE!]#define WDG_IPW_ISR1_USED (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Defines indicating for which Wdg instances the Direct Service Mode is supported
*/
[!NOCODE!]
[!VAR "isEnableDirectService"     = "0"!]
[!VAR "isDisableDirectService"    = "0"!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))"!]
            [!VAR "isEnableDirectService"     = "1"!]
            [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
            [!IF "num:i($isDisableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isDisableDirectService" = "1"!]
            [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
            [!IF "num:i($isEnableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
/**
* @brief  This variable will indicate if the Wdg Direct Service feature is activated
*/

#define WDG_IPW_DIRECT_SERVICE ([!IF "$isEnableDirectService = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INDENT "0"!]
    [!VAR "isDirectServiceAvailable" = "1"!]
    [!VAR "checkVersionInforAPI" = "1"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists($xPathModule)"!]
            [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgVersionInfoApi'))"!]
                [!VAR "checkVersionInforAPI" = "0"!]
            [!ENDIF!]

            [!VAR "getInitialTimeoutValue" = "node:value(concat($xPathModule,'/WdgGeneral/WdgInitialTimeout'))"!]
            [!VAR "getTimeoutMaxValue" = "node:value(concat($xPathModule,'/WdgGeneral/WdgMaxTimeout'))"!]

            [!IF "node:exists(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef'))"!]
                [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgEnableDirectService'))='false'"!]
                    [!VAR "isDirectServiceAvailable" = "0"!]
                    [!VAR "GptChannelInitialTickValue" = "node:value(node:ref(node:value(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef')))/GptChannelTickFrequency)"!]
                    [!VAR "GptChannelTickValueMax" = "node:value(node:ref(node:value(concat($xPathModule,'/WdgSettingsConfig/WdgExternalTriggerCounterRef')))/GptChannelTickValueMax)"!]
                    [!IF "$getTimeoutMaxValue > ($GptChannelTickValueMax div $GptChannelInitialTickValue)"!]
                        [!ERROR!][!//
                        [!"'Must set Wdg Max Timeout [s] lest than or equal to '"!][!"$GptChannelTickValueMax div $GptChannelInitialTickValue"!]
                        [!ENDERROR!][!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!CODE!]
            /**
            * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
            */
            #define WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/WdgGeneral/WdgInitialTimeout')) * 1000)"!])
            #define WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/WdgGeneral/WdgMaxTimeout')) * 1000)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_IPW_CFG_DEFINES_H */
