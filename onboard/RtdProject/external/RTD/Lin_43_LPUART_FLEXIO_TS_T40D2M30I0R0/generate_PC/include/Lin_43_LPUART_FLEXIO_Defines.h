/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPUART_FLEXIO
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

#ifndef LIN_43_LPUART_FLEXIO_DEFINES_H
#define LIN_43_LPUART_FLEXIO_DEFINES_H

/**
*   @file
*
*   @defgroup lin_driver LIN Driver
*   @addtogroup  lin_driver LIN Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_DEFINES_VENDOR_ID                     43
#define LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION      7
#define LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define LIN_43_LPUART_FLEXIO_DEFINES_SW_MAJOR_VERSION              3
#define LIN_43_LPUART_FLEXIO_DEFINES_SW_MINOR_VERSION              0
#define LIN_43_LPUART_FLEXIO_DEFINES_SW_PATCH_VERSION              0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_43_LPUART_FLEXIO_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Lin_43_LPUART_FLEXIO_Defines.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
[!NOCODE!]
[!VAR "LinMasterNodeUsed"= "'false'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "contains(node:value(LinNodeType),'MASTER')"!]
        [!VAR "LinMasterNodeUsed"= "'true'"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
/**
* @brief          Pre-compile Support.
*
*
*/
#define LIN_43_LPUART_FLEXIO_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!] (STD_ON) [!ELSE!] (STD_OFF) [!ENDIF!]

/**
* @brief   No of Channels configured.
*
*
*/
#define LIN_43_LPUART_FLEXIO_HW_MAX_MODULES ([!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U)

/**
* @brief   Total number of available hardware lin channels.
*
*
*/
#define LIN_43_LPUART_FLEXIO_HW_MAX_AVAILABLE_MODULES ([!"num:i(ecu:get('Lin.LinGlobalConfig.LinChannel'))"!]U)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT [!IF "LinGeneral/LinDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF)   /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief   Switches the Production Error Detection and Notification OFF
*
*
*/
[!NOCODE!]
[!VAR "LinDemErrorEnable" = "'false'"!]
[!IF "AutosarExt/LinDisableDemReportErrorStatus ='false'"!][!//
    [!IF "node:exists(LinDemEventParameterRefs)"!]
        [!VAR "LinDemErrorEnable" = "'true'"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
#define LIN_43_LPUART_FLEXIO_DISABLE_DEM_REPORT_ERROR_STATUS [!IF "$LinDemErrorEnable"!] (STD_OFF) /* Enable Production Error Detection */ [!ELSE!] (STD_ON) /* Disable Production Error Detection */ [!ENDIF!]

/**
* @brief          Lin Master Node Used
* @details        When LinGlobalConfig/LinChannel/LinNodeType contains at least one MASTER channel.
*
*
*/
#define LIN_43_LPUART_FLEXIO_MASTER_NODE_USED [!IF "$LinMasterNodeUsed = 'true'"!] (STD_ON) /* Used Master Node */[!ELSE!] (STD_OFF) /* Not Used Master Node */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the Lin_GetVersionInfo() API ON or OFF.
*
*
*/
#define LIN_43_LPUART_FLEXIO_VERSION_INFO_API [!IF "LinGeneral/LinVersionInfoApi"!](STD_ON)  /* Enable API Lin_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API Lin_GetVersionInfo     */[!ENDIF!]

/**
* @brief        All PartitionIDs are supported by LIN driver.
*/
[!NOCODE!]
[!VAR "MaxPartitionID"="0"!]
[!IF "node:value(LinGeneral/LinMultiPartitionSupport)='true'"!]
    [!VAR "MaxPartitionID"="count(as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*) - 1"!]
[!ENDIF!]
[!ENDNOCODE!]
#define LIN_43_LPUART_FLEXIO_MAX_PARTITIONS     ((uint32)[!"num:i($MaxPartitionID + 1)"!]U)

/**
* @brief          MultiPartition is enabled or not
*/
#define LIN_43_LPUART_FLEXIO_MULTIPARTITION_SUPPORT   [!IF "node:fallback(as:modconf('Lin')[1]/LinGeneral/LinMultiPartitionSupport, 'false') = 'false'"!](STD_OFF) /* MultiPartition is disabled */[!ELSE!](STD_ON) /* MultiPartition is enabled */[!ENDIF!]

/**
* @brief          Enable Non-Autosar API for Dual-Clock support.
* @details        Enable/Disable API Lin_SetClockMode() to set the
*                 clock to be used by the LIN driver (Normal clock: default mode;
*                 Alternate clock: when the driver is in Low-Power mode).
*                 This can be set to STD_ON only if it is activated from xdm file:
*                 LinClockRef_Alternate is enable.
*
* @api
*/
[!NOCODE!]
[!VAR "DualClockEnabled"= "'false'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!]
    [!IF "(node:exists(LinClockRef_Alternate))"!]
        [!VAR "DualClockEnabled"= "'true'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
#define LIN_43_LPUART_FLEXIO_DUAL_CLOCK_MODE [!IF "$DualClockEnabled = 'true'"!] (STD_ON) /* Enable API Lin_SetClockMode */ [!ELSE!] (STD_OFF) /* Disable API Lin_SetClockMode */ [!ENDIF!]

#if (STD_ON == LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT)
/**
*
* @internal
* @brief          Instance number assigned to the driver
* @details        InstanceId of this module instance. If only one instance is present it shall have the Id 0
*
*/
#define LIN_43_LPUART_FLEXIO_DRIVER_INSTANCE             ([!"num:i(LinGeneral/LinIndex)"!]U)    /* Instance number assigned to the driver */
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define LIN_43_LPUART_FLEXIO_UNALLOCATEDPAR_ID  [!IF "as:modconf('Lin')[1]/LinGeneral/LinMultiPartitionSupport = 'true'"!]((uint32)0xFFU)[!ELSE!]((uint32)0x00U)[!ENDIF!]

#if (STD_ON == LIN_43_LPUART_FLEXIO_MULTIPARTITION_SUPPORT)
    #define Lin_43_LPUART_FLEXIO_GetUserID() (OsIf_GetUserId())
#else
    #define Lin_43_LPUART_FLEXIO_GetUserID() (LIN_43_LPUART_FLEXIO_UNALLOCATEDPAR_ID)
#endif /* (STD_ON == LIN_43_LPUART_FLEXIO_MULTIPARTITION_SUPPORT) */

/**
* @brief          LIN driver status initialization variable.
*/
#define LIN_43_LPUART_FLEXIO_UNINIT_ARRAY  {[!FOR "idx" = "0" TO "$MaxPartitionID"!]LIN_43_LPUART_FLEXIO_UNINIT[!IF "$idx < $MaxPartitionID"!], [!ENDIF!][!ENDFOR!]}
[!NOCODE!]
[!VAR "HasFlexio" = "'STD_OFF'"!]
[!VAR "WakeupDetectionSupport" = "'STD_OFF'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "node:exists(LinFlexioTxControllerRef) and node:exists(LinFlexioRxControllerRef)"!]
        [!VAR "HasFlexio" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "node:exists(LinChannelWakeupSupport) and LinChannelWakeupSupport = 'true'"!]
        [!VAR "WakeupDetectionSupport" = "'STD_ON'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!NOCODE!][!// The marco only available on S32K and S32M
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32K') or contains($DerivativeName, 'S32M')"!][!//
[!CODE!]
/**
*
* @internal
* @brief          Lin FlexIO Used
* @details        When LinGlobalConfig/LinChannel/LinHwChannel contains FLEXIO.
*
*
*/
#define LIN_43_LPUART_FLEXIO_FLEXIO_USED ([!"$HasFlexio"!]) /* [!IF "$HasFlexio = 'STD_ON'"!]Flexio Used[!ELSE!]No Used Flexio[!ENDIF!] */
[!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
/**
*
* @internal
* @brief          Lin Wakeup detection feature
* @details        It is set to STD_ON when LinGlobalConfig/LinChannel/WakeupDetectionSupport is enabled.
*
*
*/
#define LIN_43_LPUART_FLEXIO_WAKEUP_DETECTION ([!"$WakeupDetectionSupport"!]) /* [!IF "$WakeupDetectionSupport = 'STD_ON'"!]Support wakeup detection[!ELSE!]Does not support wakeup detection[!ENDIF!] */

/**
* @brief      Symbolic names of logic channel index.
*/
[!FOR "idx" = "0" TO "count(LinGlobalConfig/LinChannel/*)-1"!][!//
    [!LOOP "LinGlobalConfig/LinChannel/*"!][!//
        [!IF "$idx = LinChannelId"!]
#define [!"name(.)"!]                                ((uint8)[!"LinChannelId"!]U)[!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!]
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LPUART_FLEXIO_DEFINES_H */
