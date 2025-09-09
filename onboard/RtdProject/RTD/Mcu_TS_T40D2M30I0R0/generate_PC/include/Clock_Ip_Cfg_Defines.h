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

#ifndef CLOCK_IP_CFG_DEFINES_H
#define CLOCK_IP_CFG_DEFINES_H


/**
*   @file       Clock_Ip_Cfg_Defines.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
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
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k148')"!][!//
[!CODE!][!WS "0"!]#include "S32K148_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_QUADSPI.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K148_RCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k116')"!][!//
[!CODE!][!WS "0"!]#include "S32K116_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_CMU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K116_RCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k118')"!][!//
[!CODE!][!WS "0"!]#include "S32K118_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_CMU.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K118_RCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142')"!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w')"!][!//
[!CODE!][!WS "0"!]#include "S32K142W_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142W_RCM.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K142_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K142_RCM.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144')"!][!//
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w')"!][!//
[!CODE!][!WS "0"!]#include "S32K144W_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144W_RCM.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!WS "0"!]#include "S32K144_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K144_RCM.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k146')"!][!//
[!CODE!][!WS "0"!]#include "S32K146_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32K146_RCM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32m24')"!][!//
[!CODE!][!WS "0"!]#include "S32M24x_SIM.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_SCG.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_PCC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_SMC.h"[!CR!][!ENDCODE!][!//
[!CODE!][!WS "0"!]#include "S32M24x_RCM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_DEFINES_VENDOR_ID                       43
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define CLOCK_IP_DERIVATIVE_[!"ecu:get('MCU.Derivative')"!]

/**
* @brief            HW sseries used.
*/
#define CLOCK_IP_DERIVATIVE_NOT_SUPPORT_USER_MODE

/**
* @brief            Max number of internal oscillators
*/
#define CLOCK_IP_IRCOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.IRCOSC.List') ) )"!]U)

/**
* @brief            Max number of external oscillators
*/
#define CLOCK_IP_XOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.XOSC.List') ) )"!]U)

/**
* @brief            Max number of pll devices
*/
#define CLOCK_IP_PLLS_COUNT       ([!"num:i( count( ecu:list('MCU.PLL.List') ) )"!]U)

/**
* @brief            Max number of selectors
*/
#define CLOCK_IP_SELECTORS_COUNT       ([!"num:i( count( ecu:list('MCU.SELECTOR.Names.List') ) )"!]U)

/**
* @brief            Max number of dividers
*/
#define CLOCK_IP_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.Names.List') ) )"!]U)

/**
* @brief            Max number of divider triggers
*/
#define CLOCK_IP_DIVIDER_TRIGGERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.TRIGGER.Names.List') ) )"!]U)

/**
* @brief            Max number of fractional dividers
*/
#define CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.ClockDFS.List') ) )"!]U)

/**
* @brief            Max number of external clocks
*/
#define CLOCK_IP_EXT_CLKS_COUNT       ([!"num:i( count( ecu:list('MCU.ExtClock.List') ) )"!]U)

/**
* @brief            Max number of pcfs
*/
#define CLOCK_IP_PCFS_COUNT       ([!"num:i( count( ecu:list('MCU.CGM.CgmPcfs.List') ))"!]U)

/**
* @brief            Max number of clock gates
*/
#define CLOCK_IP_GATES_COUNT       ([!"num:i( count( ecu:list('MCU.GATE.Names.List') ) )"!]U)

/**
* @brief            Max number of clock monitoring units
*/
#define CLOCK_IP_CMUS_COUNT       ([!"num:i( count( ecu:list('MCU.CMU_FC.List') ) )"!]U)

/**
* @brief            Max number of configured frequencies values
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT       ([!"num:i(1 + num:i( count( ecu:list('MCU.ConfiguredFrequency.List') ) ) )"!]U)

/**
* @brief            Max number of specific peripheral (eMIOS) units
*/
#define CLOCK_IP_SPECIFIC_PERIPH_COUNT       ([!"num:i( count( ecu:list('MCU.SPECIFIC_PERIPHERAL_PRAMs.List') ) )"!]U)

/**
* @brief            Supported power mode.
*/

#define CLOCK_IP_HAS_RUN_MODE                0U

#define CLOCK_IP_LPO_128K_FREQUENCY          128000

#define CLOCK_IP_FIRC_FREQUENCY              48000000

#define CLOCK_IP_SIRC_FREQUENCY              8000000

#define CLOCK_IP_DEFAULT_SOSC_FREQUENCY      40000000

#define CLOCK_IP_HAS_LOW_GAIN                         0U

#define CLOCK_IP_HAS_HIGH_GAIN                        1U

#define CLOCK_IP_HAS_MONITOR_DISABLE                  0U

#define CLOCK_IP_HAS_MONITOR_INT                      1U

#define CLOCK_IP_HAS_MONITOR_RESET                    2U

#define CLOCK_IP_HAS_SAFE_CLOCK_DISABLEMENT           1U

#if CLOCK_IP_CMUS_COUNT > 0U
/**
* @brief            Cmu formula constant values.
*/
#define CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1               1U
#define CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1           3U
#define CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA2               7U
#define CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2           3U
#endif

/**
* @brief            Clock ip supports clock frequency
*/
#define CLOCK_IP_GET_FREQUENCY_API              [!IF "McuDebugConfiguration/McuGetClockFrequencyApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Clock ip supports ram wait states
*/
[!IF "McuGeneralConfiguration/McuDisableRamWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_RAM_WAIT_STATES
[!ENDIF!]

/**
* @brief            Clock ip supports flash wait states
*/
[!IF "McuGeneralConfiguration/McuDisableFlashWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_FLASH_WAIT_STATES
[!ENDIF!]

/**
* @brief            Supports wait states configuration
*/
#define CLOCK_IP_SUPPORTS_WAIT_STATES       STD_OFF

/**
* @brief            Clock ip supports power notifications
*/
#define CLOCK_IP_POWER_NOTIFICATIONS        [!IF "McuGeneralConfiguration/McuPowerNotifications = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


[!IF "McuGeneralConfiguration/McuRegisterValuesOptimization = 'ENABLED'"!][!//
[!VAR "Mac_NumberOfCmus" = "0"!][!//
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!][!//
    [!VAR "Mac_NumOfClkMonitor" = "0"!][!//
    [!IF "node:exists("McuClkMonitor")"!][!//
        [!LOOP "./McuClkMonitor/*"!][!//
            [!IF "node:value(./McuClockMonitorUnderMcuControl)"!][!//
                [!VAR "Mac_NumOfClkMonitor" = "$Mac_NumOfClkMonitor + 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
    [!VAR "Mac_NumberOfCmus" = "$Mac_NumberOfCmus + $Mac_NumOfClkMonitor"!][!//
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!IF "$Mac_NumberOfCmus > num:i(0)"!][!//
/**
* @brief            Clock ip number of register values when register value optimization is enabled
*/
#define CLOCK_IP_REGISTER_VALUES_COUNT       ([!"num:i($Mac_NumberOfCmus * 4)"!]U)
[!ENDIF!][!//
[!ENDIF!][!//

/**
* @brief            Supported clocks.
*/
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ProducerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ProducerClocks.List')[num:i($Index)]"!]         [!"num:i($Index)"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_PRODUCERS_NO         [!"num:i(1 + num:i( count( ecu:list('MCU.ProducerClocks.List') ) ) )"!]U
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ConsumerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ConsumerClocks.List')[num:i($Index)]"!]         [!"num:i(num:i($Index) + num:i(count(ecu:list('MCU.ProducerClocks.List'))) + 1)"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_NAMES_NO         [!"num:i(num:i(count(ecu:list('MCU.ProducerClocks.List'))) + num:i(count(ecu:list('MCU.ConsumerClocks.List'))) + 2)"!]U


[!IF "node:exists(McuGeneralConfiguration/McuMultiPartitionSupport)"!]
/**
* @brief        Support for MultiPartition.
*/
#define CLOCK_IP_MULTIPARTITION_SUPPORT                   ([!IF "McuGeneralConfiguration/McuMultiPartitionSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
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
#define CLOCK_IP_PARTITION_[!"num:i($CurrentPartitionId)"!]                 ((uint8)[!"num:i($CurrentPartitionId)"!]UL)
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
#define CLOCK_IP_PARTITION_0                 ((uint8)0UL)
[!ENDIF!][!//
[!ELSE!][!//
/**
* @brief        Support for MultiPartition.
*/
#define CLOCK_IP_MULTIPARTITION_SUPPORT      (STD_OFF)
#define CLOCK_IP_PARTITION_0                 ((uint8)0UL)
[!ENDIF!]

/*some clock defined specific*/
#define CLOCK_IP_HAS_RUN_PRI_DIV_SYS_CLK                 CLOCK_IP_HAS_SCS_RUN_CLK
#define CLOCK_IP_HAS_RUN_CORE_CLK                        CLOCK_IP_HAS_CORE_RUN_CLK
#define CLOCK_IP_HAS_RUN_SYS_CLK                         CLOCK_IP_HAS_CORE_RUN_CLK
#define CLOCK_IP_HAS_RUN_FLASH_CLK                       CLOCK_IP_HAS_SLOW_RUN_CLK
#define CLOCK_IP_HAS_RUN_BUS_CLK                         CLOCK_IP_HAS_BUS_RUN_CLK

#if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
#define CLOCK_IP_HAS_HSRUN_PRI_DIV_SYS_CLK               CLOCK_IP_HAS_SCS_HSRUN_CLK
#endif
#if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
#define CLOCK_IP_HAS_HSRUN_CORE_CLK                      CLOCK_IP_HAS_CORE_HSRUN_CLK
#define CLOCK_IP_HAS_HSRUN_SYS_CLK                       CLOCK_IP_HAS_CORE_HSRUN_CLK
#endif
#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
#define CLOCK_IP_HAS_HSRUN_FLASH_CLK                     CLOCK_IP_HAS_SLOW_HSRUN_CLK
#endif
#if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
#define CLOCK_IP_HAS_HSRUN_BUS_CLK                       CLOCK_IP_HAS_BUS_HSRUN_CLK
#endif
#define CLOCK_IP_HAS_VLPR_PRI_DIV_SYS_CLK                CLOCK_IP_HAS_SCS_VLPR_CLK
#define CLOCK_IP_HAS_VLPR_CORE_CLK                       CLOCK_IP_HAS_CORE_VLPR_CLK
#define CLOCK_IP_HAS_VLPR_SYS_CLK                        CLOCK_IP_HAS_CORE_VLPR_CLK
#define CLOCK_IP_HAS_VLPR_FLASH_CLK                      CLOCK_IP_HAS_SLOW_VLPR_CLK
#define CLOCK_IP_HAS_VLPR_BUS_CLK                        CLOCK_IP_HAS_BUS_VLPR_CLK

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
#endif /* #ifndef CLOCK_IP_CFG_DEFINES_H */

