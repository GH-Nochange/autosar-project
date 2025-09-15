[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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

#ifndef OCU[!"text:toupper($VS_number)"!]_PBCFG_H
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_H

/**
*   @file           Ocu[!"$VS_number"!]_PBcfg.h
*
*   @addtogroup     ocu_driver Ocu Driver
*   @brief          Ocu HLD configuration header file.
*   @details        PostBuild parameters and extern configuration.
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ocu_Types.h"

/*==================================================================================================
*                              HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID                       43
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION        4
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION        7
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION     0
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION                3
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION                0
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID != OCU_TYPES_VENDOR_ID)
    #error "Ocu[!"$VS_number"!]_PBcfg.h and Ocu_Types.h have different vendor ids"
#endif

/* Check if header file and Ocu_Types.h file are of the same Autosar version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION != OCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION != OCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION != OCU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu[!"$VS_number"!]_PBcfg.h and Ocu_Types.h are different"
#endif

/* Check if header file and Ocu_Types.h file are of the same Software version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION != OCU_TYPES_SW_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION != OCU_TYPES_SW_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION != OCU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu[!"$VS_number"!]_PBcfg.h and Ocu_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
[!CODE!]
#define OCU_CONFIG[!"text:toupper($VS_number)"!]_PB \
[!ENDCODE!]
[!VAR "OcuConfiguredPartitions" = "num:i((count(OcuGeneral/OcuEcucPartitionRef/*)))"!][!//
[!VAR "IndexPartitions" = "0"!][!//
[!IF "$OcuConfiguredPartitions > 0"!][!//
    [!LOOP "OcuGeneral/OcuEcucPartitionRef/*"!][!//
        [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
        [!CODE!][!WS "4"!]extern const Ocu_ConfigType Ocu_Config[!"$VS_number"!]_[!"$currentPartition"!];[!IF "$IndexPartitions < ($OcuConfiguredPartitions - 1)"!] \[!ENDIF!][!CR!][!ENDCODE!]
        [!VAR "IndexPartitions" = "$IndexPartitions + 1"!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
        [!CODE!][!WS "4"!]extern const Ocu_ConfigType Ocu_Config[!"$VS_number"!];[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!]

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* OCU[!"text:toupper($VS_number)"!]_PBCFG_H */
