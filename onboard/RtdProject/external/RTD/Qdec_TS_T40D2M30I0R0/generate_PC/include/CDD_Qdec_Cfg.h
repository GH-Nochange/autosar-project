[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
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

#ifndef CDD_QDEC_CFG_H
#define CDD_QDEC_CFG_H

/**
*   @file       CDD_Qdec_Cfg.h
*
*   @brief      AUTOSAR Qdec - contains the configuration data of the Qdec driver
*   @details    Contains the configuration data of the Qdec driver
*
*   @addtogroup qdec Qdec Driver
*   @brief      Qdec HLD
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
[!CODE!]
/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "CDD_Qdec_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "CDD_Qdec_PBcfg.h"
[!ENDIF!]
[!ENDCODE!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_QDEC_CFG_VENDOR_ID                          43
#define CDD_QDEC_CFG_AR_RELEASE_MAJOR_VERSION           4
#define CDD_QDEC_CFG_AR_RELEASE_MINOR_VERSION           7
#define CDD_QDEC_CFG_AR_RELEASE_REVISION_VERSION        0
#define CDD_QDEC_CFG_SW_MAJOR_VERSION                   3
#define CDD_QDEC_CFG_SW_MINOR_VERSION                   0
#define CDD_QDEC_CFG_SW_PATCH_VERSION                   0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((CDD_QDEC_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_QDEC_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of CDD_Qdec_Cfg.h and Std_Types.h are different."
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
/* Check if header file and QDEC configuration header file are of the same vendor */
#if (CDD_QDEC_CFG_VENDOR_ID != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
    #error "CDD_Qdec_Cfg.h and CDD_Qdec_[!"."!]_PBcfg.h have different vendor IDs"
#endif
    /* Check if header file and Qdec configuration header file are of the same Autosar version */
#if ((CDD_QDEC_CFG_AR_RELEASE_MAJOR_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC_CFG_AR_RELEASE_MINOR_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC_CFG_AR_RELEASE_REVISION_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Qdec_Cfg.h and CDD_Qdec_[!"."!]_PBcfg.h are different"
#endif
/* Check if header file and Qdec configuration header file are of the same software version */
#if ((CDD_QDEC_CFG_SW_MAJOR_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_QDEC_CFG_SW_MINOR_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
     (CDD_QDEC_CFG_SW_PATCH_VERSION != CDD_QDEC_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Qdec_Cfg.h and CDD_Qdec_[!"."!]_PBcfg.h are different"
#endif
    [!ENDLOOP!]
[!ELSE!]
/* Check if header file and QDEC configuration header file are of the same vendor */
#if (CDD_QDEC_CFG_VENDOR_ID != CDD_QDEC_PBCFG_VENDOR_ID)
    #error "CDD_Qdec_Cfg.h and CDD_Qdec_PBcfg.h have different vendor IDs"
#endif
    /* Check if header file and Qdec configuration header file are of the same Autosar version */
#if ((CDD_QDEC_CFG_AR_RELEASE_MAJOR_VERSION != CDD_QDEC_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC_CFG_AR_RELEASE_MINOR_VERSION != CDD_QDEC_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC_CFG_AR_RELEASE_REVISION_VERSION != CDD_QDEC_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Qdec_Cfg.h and CDD_Qdec_PBcfg.h are different"
#endif
/* Check if header file and Qdec configuration header file are of the same software version */
#if ((CDD_QDEC_CFG_SW_MAJOR_VERSION != CDD_QDEC_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_QDEC_CFG_SW_MINOR_VERSION != CDD_QDEC_PBCFG_SW_MINOR_VERSION) || \
     (CDD_QDEC_CFG_SW_PATCH_VERSION != CDD_QDEC_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Qdec_Cfg.h and CDD_Qdec_PBcfg.h are different"
#endif
[!ENDIF!]

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!]
#define QDEC_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
        QDEC_CONFIG_[!"text:toupper(.)"!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
        QDEC_CONFIG_PB \
[!ENDIF!]
[!ENDIF!]

/**
 *   @brief Pre-compile configuration constants
 */
#define QDEC_PRECOMPILE_SUPPORT     ([!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*           STD_ON: Enabled.
*           STD_OFF: Disabled.
*/
#define QDEC_DEV_ERROR_DETECT       ([!IF "QdecGeneral/QdecDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (QDEC_DEV_ERROR_DETECT == STD_ON)
/**
 *   @brief Maximum number of QDEC instances configured
 */
#define QDEC_MAX_INSTANCE           ((uint8)[!"num:i(count(QdecInstanceConfig/*))"!]U)
#endif

/**
*   @brief      Adds or removes the service Qdec_DeInit() from the code.
*               STD_ON:  Qdec_DeInit() can be used.
*               STD_OFF: Qdec_DeInit() can not be used.
*/
#define QDEC_DEINIT_API             ([!IF "QdecConfigurationOfOptionalApis/QdecDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define QDEC_MULTIPARTITION_ENABLED      ([!IF "QdecGeneral/QdecMultiPartitionEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!]
[!VAR "QdecEcucPartitionRefCount" = "num:i(count(as:modconf('Qdec')[1]/QdecGeneral/QdecEcucPartitionRef/*))"!]
            [!IF "$QdecEcucPartitionRefCount != 0 "!]
                [!VAR "QdecEcucPartitionRefNum" = "$QdecEcucPartitionRefCount"!]
                [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
                    [!VAR "maxPartition" = "0"!]
                    [!LOOP "./QdecGeneral/QdecEcucPartitionRef/*"!]
                        [!VAR "QdecCrtPart" = "node:value(.)"!]
                            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                                [!IF "$QdecCrtPart = node:value(./OsAppEcucPartitionRef)"!]
                                    [!SELECT "node:ref(./OsAppEcucPartitionRef)"!]
                                        [!IF "$maxPartition < node:pos(.)"!]
                                            [!VAR "maxPartition" = "node:pos(.)"!]
                                        [!ENDIF!]
                                    [!ENDSELECT!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                    [!ENDLOOP!]
                [!ELSE!]
                    [!VAR "maxPartition" = "0"!]
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                        [!SELECT "node:ref(./OsAppEcucPartitionRef)"!]
                            [!IF "$maxPartition < node:pos(.)"!]
                                [!VAR "maxPartition" = "node:pos(.)"!]
                            [!ENDIF!]
                        [!ENDSELECT!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "maxPartition" = "0"!]
                [!VAR "QdecEcucPartitionRefNum" = "1"!]
            [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
#if (QDEC_MULTIPARTITION_ENABLED == STD_ON)
/**
* @brief        QDEC_MAX_PARTITIONS.
* @details      Number of maximum partitions.
*/
#define QDEC_MAX_PARTITIONS         ([!"num:i($maxPartition + 1)"!]U)
#endif
[!ENDCODE!]

/**
*   @brief      Qdec instance symbolic names
*   @details    Get All Symbolic Names from configuration tool
*/
[!INDENT "0"!]
[!NOCODE!]
    [!LOOP "QdecInstanceConfig/*"!]
        [!CODE!]
         #define [!"node:name(.)"!]                                 (QdecConf_QdecInstanceConfig_[!"node:name(.)"!])[!CR!]
         #define QdecConf_QdecInstanceConfig_[!"node:name(.)"!]     ((uint8)[!"QdecHardwareModuleId"!]U)[!CR!]

        [!ENDCODE!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDINDENT!]

#ifndef QDEC_SET_CLOCK_MODE_API
/** @brief  Switch for enabling the dual clock functionality (Qdec_SetClockMode() API) */
#define QDEC_SET_CLOCK_MODE_API      ([!IF "QdecGeneral/QdecEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#define QDEC_NOTIFICATION_SUPPORTED  ([!IF "QdecGeneral/QdecOverFlowNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

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

/**@}*/

#endif    /* CDD_QDEC_CFG_H */
[!ENDCODE!]