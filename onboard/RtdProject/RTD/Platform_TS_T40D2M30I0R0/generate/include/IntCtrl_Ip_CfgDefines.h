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

#ifndef INTCTRL_IP_CFG_DEFINES_H_
#define INTCTRL_IP_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Interrupt Controller feature enablement.
*/
#define PLATFORM_IP_ENABLE_INT_CTRL ([!IF "(GeneralConfiguration/PlatformEnableIntCtrlConfiguration = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!// Include headers for System_Ip_DeviceRegister.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32G274A_NVIC.h"
        #include "S32G274A_MSCM.h"
        #include "S32G274A_SCB.h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32G399A_NVIC.h"
        #include "S32G399A_MSCM.h"
        #include "S32G399A_SCB.h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K3') or contains($DerivativeName, 'S32M27')"!][!//
        [!IF "contains($DerivativeName, 'S32K344')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K344_NVIC.h"
        #include "S32K344_MSCM.h"
        #include "S32K344_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K342')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K342_NVIC.h"
        #include "S32K342_MSCM.h"
        #include "S32K342_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K341')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K341_NVIC.h"
        #include "S32K341_MSCM.h"
        #include "S32K341_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K324')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K324_NVIC.h"
        #include "S32K324_MSCM.h"
        #include "S32K324_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K314')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K314_NVIC.h"
        #include "S32K314_MSCM.h"
        #include "S32K314_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K312')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K312_NVIC.h"
        #include "S32K312_MSCM.h"
        #include "S32K312_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K322')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K322_NVIC.h"
        #include "S32K322_MSCM.h"
        #include "S32K322_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394') or contains($DerivativeName, 'S32K364') or contains($DerivativeName, 'S32K366')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K39_NVIC.h"
        #include "S32K39_MSCM.h"
        #include "S32K39_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K376') or contains($DerivativeName, 'S32K374')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K37_NVIC.h"
        #include "S32K37_MSCM.h"
        #include "S32K37_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348') or contains($DerivativeName, 'S32K358')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K358_NVIC.h"
        #include "S32K358_MSCM.h"
        #include "S32K358_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K388')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K388_NVIC.h"
        #include "S32K388_MSCM.h"
        #include "S32K388_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K311') or contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K311_NVIC.h"
        #include "S32K311_MSCM.h"
        #include "S32K311_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32M27x_NVIC.h"
        #include "S32M27x_MSCM.h"
        #include "S32M27x_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
        [!CODE!][!WS "0"!]

        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32K5')"!][!//
        [!IF "contains($DerivativeName, 'S32K566')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K566_NVIC.h"
        #include "S32K566_SCB.h"
            [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//

    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32R45_NVIC.h"
        #include "S32R45_MSCM.h"
        #include "S32R45_SCB.h"
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32R41.h"
        #include "S32R41_NVIC.h"
        #include "S32R41_MSCM.h"
        #include "S32R41_SCB.h"

        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]
        #include "SAF85xx.h"
        #include "SAF85xx_NVIC.h"
        #include "SAF85xx_MSCM.h"
        #include "SAF85xx_SCB.h"
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'SAF86')"!][!//
        [!CODE!][!WS "0"!]
        #include "SAF86xx.h"
        #include "SAF86xx_NVIC.h"
        #include "SAF86xx_MSCM.h"
        #include "SAF86xx_SCB.h"
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'SAF9')"!][!//
        [!CODE!][!WS "0"!]
        #include "SAF900X.h"
        #include "SAF900X_NVIC.h"
        #include "SAF900X_SCB.h"
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32M24x.h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SJA1110')"!][!//
        [!CODE!][!WS "0"!]
        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32E2') or contains($DerivativeName, 'S32S2')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32E2_COMMON.h"
        #include "S32E2_GIC.h"
        #include "S32E2_MPU.h"
        #include "S32E2_SCB.h"
        #include "S32E2_MSCM.h"
        #include "S32E2_NVIC.h"
        #define IRQn_Type IRQn_Type
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32Z2')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32Z2_COMMON.h"
        #include "S32Z2_GIC.h"
        #include "S32Z2_MPU.h"
        #include "S32Z2_SCB.h"
        #include "S32Z2_MSCM.h"
        #include "S32Z2_NVIC.h"
        #define IRQn_Type IRQn_Type
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32N55')"!][!//
[!CODE!][!WS "0"!]
#include "S32N55_COMMON.h"
#include "S32N55_MPU.h"
#include "S32N55_SCB.h"
#define IRQn_Type IRQn_Type
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32N79')"!][!//
[!CODE!][!WS "0"!]
#include "S32N79_COMMON.h"
#include "S32N79_MPU.h"
#include "S32N79_SCB.h"
#define IRQn_Type IRQn_Type
[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32J100')"!][!//
[!CODE!][!WS "0"!]
#include "S32J100_COMMON.h"
#include "S32J100_GIC.h"

#define INT_CTRL_NUM_CORE_R52            (4U)
#define IRQn_Type                        RTU_IRQn_Type
#define INT_CTRL_CORE_SPECIFIC_VTABLE    (STD_ON)
#define INT_CTRL_IP_GIC500_MIN_SPI_ID    (32U)
[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Development error detection */
#define INT_CTRL_IP_DEV_ERROR_DETECT              ([!IF "GeneralConfiguration/PlatformDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* VTOR address configuration enable */
#define INT_CTRL_IP_ENABLE_VTOR_CONFIG            ([!IF "GeneralConfiguration/PlatformEnableVtorConfiguration"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "GeneralConfiguration/PlatformEnableIntCtrlConfiguration"!] /* IntCtrl settings */


/* INCT CTRL IP standalone APIs */
#define INT_CTRL_IP_STANDALONE_APIS               ([!IF "GeneralConfiguration/PlatformIpAPIsAvailable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* First implemented interrupt vector */
#define INT_CTRL_IP_IRQ_MIN                       ([!"ecu:list('Platform.irqsList')[position()=1]"!])
    [!VAR "maxIrq" = "ecu:get('Platform.irqCount')"!]
/* Last implemented interrupt vector */
#define INT_CTRL_IP_IRQ_MAX                       ([!"ecu:list('Platform.irqsList')[position()=$maxIrq]"!])
/* The interrupt counter value*/
#define INT_CTRL_IP_IRQ_COUNT                     ([!"ecu:get('Platform.irqCount')"!]U)
/* Arm Cortex M4 */
#define INT_CTRL_IP_CORTEXM                      ([!"ecu:get('Platform.ArmCortexM')"!])
#define INT_CTRL_IP_CORTEXM0PLUS                 ([!"ecu:get('Platform.ArmCortexM0Plus')"!])
#define INT_CTRL_IP_CORTEXR                      (STD_OFF)
#define INT_CTRL_IP_CORTEXA                      (STD_OFF)
/* Number of nvic priority bits implemented */
#define INT_CTRL_IP_NVIC_PRIO_BITS                ([!"ecu:get('Platform.irqPrioBits')"!]U)

/*Interrupt Router Shared Peripheral Routing Control Register*/
#define INT_CTRL_IP_ROUTING_CONTROL_REGISTER      ([!"ecu:get('Platform.mscmIrqRouter')"!])

/* This instruction invalidates the entire instruction cache or caches */
#define INT_CTRL_IP_INVALIDATE_CACHE              ([!"ecu:get('Platform.InvalidateCache')"!])
[!ENDIF!] /* IntCtrl settings */
/* User mode support */
[!IF "(GeneralConfiguration/PlatformEnableUserModeSupport)"!][!//
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_ON)
[!ELSE!]
#define INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]
#endif /* INTCTRL_IP_CFG_DEFINES_H_ */

