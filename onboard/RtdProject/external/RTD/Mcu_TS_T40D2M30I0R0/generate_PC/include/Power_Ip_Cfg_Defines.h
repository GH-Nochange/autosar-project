/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef POWER_IP_CFG_DEFINES_H
#define POWER_IP_CFG_DEFINES_H

/**
*   @file       Power_Ip_Cfg_Defines.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k148')"!][!//
[!CODE!][!WS "0"!]#include "S32K148_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_SMC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k116')"!][!//
[!CODE!][!WS "0"!]#include "S32K116_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_SMC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k118')"!][!//
[!CODE!][!WS "0"!]#include "S32K118_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_SMC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142')"!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w')"!][!//
[!CODE!][!WS "0"!]#include "S32K142W_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_SMC.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K142_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_SMC.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144')"!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w')"!][!//
[!CODE!][!WS "0"!]#include "S32K144W_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_SMC.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K144_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_SMC.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k146')"!][!//
[!CODE!][!WS "0"!]#include "S32K146_PMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_SMC.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m24')"!][!// 
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m243') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m244')"!][!//
[!CODE!][!WS "0"!]#include "S32M24x_PMC.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_PMC_142.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!]
[!CODE!][!WS "0"!]#include "S32M24x_PMC_AE.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_AEC_AE.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_RCM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_SMC.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_DEFINES_VENDOR_ID                       43
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define POWER_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define POWER_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Cfg_Defines.h  and Std_Types.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define POWER_IP_DERIVATIVE_[!"ecu:get('MCU.Derivative')"!]

/**
* @brief            Support for Low Power mode.
*/
#if (defined(POWER_IP_DERIVATIVE_008) || defined(POWER_IP_DERIVATIVE_007) || defined(POWER_IP_DERIVATIVE_005) || defined(POWER_IP_DERIVATIVE_003))
  #define POWER_IP_HSRUN_SUPPORT    STD_ON
#else
  #define POWER_IP_HSRUN_SUPPORT    STD_OFF
#endif

/**
* @brief            Support for Low Power mode.
*/
#define POWER_IP_ENTER_LOW_POWER_MODE   [!IF "McuGeneralConfiguration/McuEnterLowPowerMode = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            define for interrupt CMU, PMC, SCG peripheral
*/
#define POWER_IP_CMU_PMC_SCG_INTERRUPT  [!IF "num:i(ecu:get('MCU.CMU.UNITS')) > num:i(0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief
*/
#define POWER_IP_PERFORM_RESET_API   [!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            ISR Mcu_VoltageError_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_VOLTAGE_ERROR_ISR_USED   [!IF "McuModuleConfiguration/McuInterruptEvents/McuVoltageErrorEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            ISR Mcu_ResetAlternate_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_RESET_ALTERNATE_ISR_USED            [!IF "McuModuleConfiguration/McuInterruptEvents/McuAlternateResetEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar Peripheral CMU.
*/
#define MCU_ENABLE_CMU_PERIPHERAL    [!IF "McuDebugConfiguration/McuEnablePeripheralCMU = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define POWER_IP_NO_PLL   [!IF "McuGeneralConfiguration/McuNoPll = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "ecu:get('MCU.SLEEPONEXIT.SUPPORT') = 'true'"!]
/**
* @brief           This define controls the availability of function Mcu_SleepOnExit
*/
#define POWER_IP_SLEEPONEXIT_SUPPORT    (STD_ON)
[!ENDIF!]

/**
* @brief            Low Voltage Detect Status and Control 1 Register support (PMC_LVDSC1).
*/
#define POWER_IP_PMC_LVDSC1_SUPPORT     [!IF "text:tolower(ecu:get('MCU.PMC.LVDSC1.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            PMC_AE Configuration Register (CONFIG) and PMC_AE Monitor Register (MONITOR).
*/
#define POWER_IP_PMC_AE_SUPPORT     [!IF "text:tolower(ecu:get('MCU.PMC.AE.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            AEC Configuration Register (RSTGEN_CFG).
*/
#define POWER_IP_AEC_SUPPORT     [!IF "text:tolower(ecu:get('MCU.AEC.RSTGENCFG.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerMode_State() for getting infos system platform configuration.
*/
#define POWER_IP_POWERMODE_STATE_API   [!IF "McuDebugConfiguration/McuGetPowerModeStatetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_SRAMRetentionConfig().
*/
#define POWER_IP_SRAM_RETEN_CONFIG_API    [!IF "McuDebugConfiguration/McuSRAMRetentionConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_PmcAeConfig().
*/
#define POWER_IP_PMCAECONFIG_API     [!IF "node:exists(McuDebugConfiguration/McuPmcAeConfigApi)"!][!IF "McuDebugConfiguration/McuPmcAeConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_ON)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_AecResetConfig().
*/
#define POWER_IP_AECRESETCONFIG_API     [!IF "node:exists(McuDebugConfiguration/McuAecResetConfigApi)"!][!IF "McuDebugConfiguration/McuAecResetConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_ON)[!ENDIF!]

[!IF "node:exists(McuGeneralConfiguration/McuVeryLowPowerStopAbortNotification)"!]
/**
* @brief            The notification procedure configured by the user.
*/
#define POWER_IP_VLPSA_NOTIFICATION
[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Reset Control Module (RMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_RCM_INIT   [!IF "McuGeneralConfiguration/McuDisableRcmInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_PMC_INIT      [!IF "McuGeneralConfiguration/McuDisablePmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the System Mode Controller (SMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_SMC_INIT   [!IF "McuGeneralConfiguration/McuDisableSmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:exists(McuGeneralConfiguration/McuMultiPartitionSupport)"!]
/**
* @brief        Support for MultiPartition.
*/
#define POWER_IP_MULTIPARTITION_SUPPORT                   ([!IF "McuGeneralConfiguration/McuMultiPartitionSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "McuGeneralConfiguration/McuMultiPartitionSupport = 'true'"!][!//
[!LOOP "McuGeneralConfiguration/McuEcucPartitionRef/*"!][!//
[!VAR "PartitionRefName" = "node:value(.)"!][!//
[!VAR "CurrentPartitionRefName" = "substring-after($PartitionRefName, '/')"!][!//
[!VAR "CurrentPartitionRefName" = "substring-after($CurrentPartitionRefName, '/')"!][!//
[!VAR "CurrentPartitionRefName" = "substring-after($CurrentPartitionRefName, '/')"!][!//
[!VAR "CurrentPartitionRefName" = "substring-after($CurrentPartitionRefName, '/')"!][!//
[!LOOP "as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!][!//
[!IF "$CurrentPartitionRefName = node:name(.)"!][!//[!//       
[!VAR "CurrentPartitionId" = "node:pos(.)"!][!//
#define POWER_IP_PARTITION_[!"num:i($CurrentPartitionId)"!]                 ((uint8)[!"num:i($CurrentPartitionId)"!]UL)
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
#define POWER_IP_PARTITION_0                 ((uint8)0UL)
[!ENDIF!][!//
[!ELSE!][!//
/**
* @brief        Support for MultiPartition.
*/
#define POWER_IP_MULTIPARTITION_SUPPORT      (STD_OFF)
#define POWER_IP_PARTITION_0                 ((uint8)0UL)
[!ENDIF!]
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_DEFINES_H */


