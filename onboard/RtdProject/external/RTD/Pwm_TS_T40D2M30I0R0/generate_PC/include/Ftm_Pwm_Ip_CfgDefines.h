[!CODE!][!//
[!AUTOSPACING!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FTM_PWM_IP_CFGDEFINES_H
#define FTM_PWM_IP_CFGDEFINES_H

/**
*   @file       Ftm_Pwm_Ip_CfgDefines.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Standard Types */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_CFGDEFINES_VENDOR_ID                    43
#define FTM_PWM_IP_CFGDEFINES_MODULE_ID                    121
#define FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FTM_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FTM_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION             3
#define FTM_PWM_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FTM_PWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief        Switch to enable the notifications feature */
#define FTM_PWM_IP_NOTIFICATION_SUPPORT             ([!IF "PwmGeneral/PwmNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* FTM INSTANCE FEATURES */
/* @brief Ftm module has fault control mode */
#define FTM_PWM_IP_HAS_FAULT                           ([!IF "ecu:get('Pwm.FTM_PWM_HAS_FAULT') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief Ftm module has two channels share the same IRQ */
#define FTM_PWM_IP_MODULE_SINGLE_INTERRUPT             ([!IF "ecu:get('Pwm.FTM_PWM_HAS_MODULE_SINGLE_INTERRUPT') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief Pair channel has deadtime on the PWM signal */
#define FTM_PWM_IP_HAS_PAIR_DEADTIME                   ([!IF "ecu:get('Pwm.FTM_PWM_HAS_PAIR_DEADTIME') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The modified combine feature on the PWM signal */
#define FTM_PWM_IP_HAS_MODIFIED_COMBINE_MODE           ([!IF "ecu:get('Pwm.FTM_PWM_HAS_MODIFIED_COMBINE_MODE') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM half cycle reload feature */
#define FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD               ([!IF "ecu:get('Pwm.FTM_PWM_HAS_HALF_CYCLE_RELOAD') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has reload point feature */
#define FTM_PWM_IP_HAS_RELOAD_POINT                    ([!IF "ecu:get('Pwm.FTM_PWM_HAS_RELOAD_POINT') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has the global load mechanism feature */
#define FTM_PWM_IP_HAS_GLOBAL_LOAD_MECHANISM           ([!IF "ecu:get('Pwm.FTM_PWM_HAS_GLOBAL_LOAD_MECHANISM') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has the fixed clock source */
#define FTM_PWM_IP_HAS_FIXED_CLOCK_SOURCE              ([!IF "ecu:get('Pwm.FTM_PWM_HAS_FIXED_CLOCK_SOURCE') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has the external clock source */
#define FTM_PWM_IP_HAS_EXTERNAL_CLOCK                  ([!IF "ecu:get('Pwm.FTM_PWM_HAS_EXTERNAL_CLOCK') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has the system integration module to select the external clock */
#define FTM_PWM_IP_HAS_SIM_EXT_CLK                     ([!IF "ecu:get('Pwm.FTM_PWM_HAS_SIM_EXT_CLK') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The FTM has the PWM channel output is enabled or disabled */
#define FTM_PWM_IP_HAS_CHANNEL_PWM_ENABLE              ([!IF "ecu:get('Pwm.FTM_PWM_HAS_CHANNEL_PWM_ENABLE') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The dithering is available */
#define FTM_PWM_IP_HAS_DITHERING                       ([!IF "ecu:get('Pwm.FTM_PWM_HAS_DITHERING') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The dithering is available on the instance 0 */
#define FTM_PWM_IP_HAS_DITHERING_INSTANCE0             ([!IF "ecu:get('Pwm.FTM_PWM_HAS_DITHERING_INSTANCE0') = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* @brief The peripheral clock which is used the system clock for the FTM counter */
#define FTM_PWM_IP_PERIPHERAL_CLOCK
/* @brief Re-define the peripheral clock name */
#define PERI_CLK ([!"text:toupper(ecu:get('Pwm.PERI_CLK'))"!])
/* @brief Re-define the external clock name for flexTimer 0 */
#define FTIMER0_EXT_CLK ([!"text:toupper(ecu:get('Pwm.FTIMER0_EXT_CLK'))"!])
/* @brief Re-define the external clock name for flexTimer 1 */
#define FTIMER1_EXT_CLK ([!"text:toupper(ecu:get('Pwm.FTIMER1_EXT_CLK'))"!])
/* @brief    Support for Sim module is available */
#define FTM_PWM_IP_SIM_AVAILABLE                       ([!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m2')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_CFGDEFINES_H */

[!ENDCODE!]
