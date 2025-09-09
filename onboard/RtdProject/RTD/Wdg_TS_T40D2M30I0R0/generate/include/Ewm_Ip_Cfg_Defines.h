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

#ifndef EWM_IP_CFG_DEFINES_H
#define EWM_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Ewm_Ip
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

#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EWM_IP_CFG_DEFINES_VENDOR_ID                    43
#define EWM_IP_CFG_DEFINES_MODULE_ID                    102
#define EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define EWM_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define EWM_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance1_','TS_T40D2M30I0R0/Wdg')"!][!//
[!IF "node:exists($xPathModule)"!][!//
[!NOCODE!]
[!INDENT "0"!]
[!VAR "EwmEnableDevErrorDetect" = "0"!][!//
[!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgDevErrorDetect'))"!]
    [!VAR "EwmEnableDevErrorDetect" = "1"!]
[!ENDIF!]
[!CODE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define EWM_IP_DEV_ERROR_DETECT ([!IF "$EwmEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
/**
* @brief  This constant specifies if the instance of the EWM is selected or not
*/
#define EWM_IP_ENABLE           (STD_ON)

[!ELSE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define EWM_IP_DEV_ERROR_DETECT (STD_OFF)
/**
* @brief  This constant specifies if the instance of the EWM is selected or not
*/
#define EWM_IP_ENABLE           (STD_OFF)
[!ENDIF!]

[!IF "node:exists($xPathModule)"!][!//
/**
* @brief  This variable will indicate if the ISR for EWM instances is used
*/
[!NOCODE!]
[!IF "node:value(concat($xPathModule,'/WdgSettingsConfig/WdgSettingsConfiguration/WdgInterruptEnable'))"!]
    [!CODE!]#define EWM_IP_ISR0_USED (STD_ON)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define EWM_IP_ISR0_USED (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDNOCODE!]
[!ENDIF!]
/**
* @brief  This variable will indicate RAM/ROM execution
*/
[!NOCODE!]
[!VAR "RunAreaROM" = "0"!]
[!VAR "RunAreaRAM" = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/Wdg_43_Instance',$i,'_','TS_T40D2M30I0R0/Wdg')"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('ASPathDataOfSchema:/','TS_T40D2M30I0R0/Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists($xPathModule)"!]
        [!IF "node:value(concat($xPathModule,'/WdgGeneral/WdgRunArea')) = 'ROM'"!]
            [!VAR "RunAreaROM" = "1"!]
            [!IF "num:i($RunAreaRAM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "RunAreaRAM" = "1"!]
            [!IF "num:i($RunAreaROM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($RunAreaROM) = 1"!]
    [!CODE!]#define WDG_ROM (1U)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_RAM (0U)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/**
 * @brief First byte of the EWM Service key
 */
#define EWM_IP_FEATURE_KEY_FIRST_BYTE_U8 ([!"ecu:get('Ewm.Ip.Feature.Key.First.Byte.U8')"!])

/**
 * @brief Second byte of the EWM Service key
 */
#define EWM_IP_FEATURE_KEY_SECOND_BYTE_U8 ([!"ecu:get('Ewm.Ip.Feature.Key.Second.Byte.U8')"!])

/**
 * @brief EWM Compare High register maximum value
 */
#define EWM_IP_FEATURE_CMPH_MAX_VALUE_U8 ([!"ecu:get('Ewm.Ip.Feature.Cmph.Max.Value.U8')"!])


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EWM_IP_CFG_DEFINES_H */
