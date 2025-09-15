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

/**
*    @file       CDD_Qdec[!"$VS_number"!]_PBcfg.c
*
*    @brief      AUTOSAR Qdec - QDEC post-build configuration file.
*    @details    Post-build configuration structure instances.
*
*    @addtogroup qdec Qdec Driver
*    @brief      Qdec HLD
*   @{
*/

[!NOCODE!][!//​
/* Variable storing number of FTM Modules available on the current platform */
[!VAR "numFtmModules" = "num:i(ecu:get('Qdec.Num_Ftm_Hw_Modules'))"!]
[!ENDNOCODE!]

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Qdec[!"$VS_number"!]_PBcfg.h"
#include "CDD_Qdec_Ipw.h"
#include "CDD_Qdec.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C                          43
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C        0
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C                   3
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C                   0
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C                   0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and CDD_Qdec[!"$VS_number"!]_PBcfg header file are of the same vendor */
#if (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
#error "CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec[!"$VS_number"!]_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and CDD_Qdec[!"$VS_number"!]_PBcfg header file are of the same Autosar version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec[!"$VS_number"!]_PBcfg.h are different"
#endif
/* Check if source file and CDD_Qdec[!"$VS_number"!]_PBcfg header file are of the same Software Version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and CDD_Qdec_Ipw header file are of the same vendor */
#if (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != CDD_QDEC_IPW_VENDOR_ID)
#error "CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec_Ipw.h have different vendor IDs"
#endif
/* Check if source file and CDD_Qdec_Ipw header file are of the same Autosar version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_QDEC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_QDEC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDD_QDEC_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec_Ipw.h are different"
#endif
/* Check if source file and CDD_Qdec_Ipw header file are of the same Software Version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != CDD_QDEC_IPW_SW_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != CDD_QDEC_IPW_SW_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != CDD_QDEC_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec_Ipw.h are different"
#endif

/* Check if source file and CDD_Qdec header file are of the same vendor */
#if (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != CDD_QDEC_VENDOR_ID)
    #error "CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec.h have different vendor IDs"
#endif
/* Check if source file and CDD_Qdec header file are of the same AutoSar version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_QDEC_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_QDEC_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDD_QDEC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec.h are different"
#endif
/* Check if source file and CDD_Qdec header file are of the same Software version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != CDD_QDEC_SW_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != CDD_QDEC_SW_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != CDD_QDEC_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.c and CDD_Qdec.h are different"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define QDEC_START_SEC_CODE
#include "Qdec_MemMap.h"

#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
[!LOOP "QdecInstanceConfig/*"!]
    [!IF "node:exists('QdecOverflowNotification')"!]
        [!IF "(QdecOverflowNotification = '') or (QdecOverflowNotification = 'NULL_PTR') or (QdecOverflowNotification = 'NULL')"!]
        [!ELSE!]
extern void [!"QdecOverflowNotification"!](void);
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
#endif

#define QDEC_STOP_SEC_CODE
#include "Qdec_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define QDEC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

[!VAR "QdecEcucPartitionRefCount" = "num:i(count(as:modconf('Qdec')[1]/QdecGeneral/QdecEcucPartitionRef/*))"!]
[!IF "$QdecEcucPartitionRefCount != 0 "!]
    [!VAR "QdecEcucPartitionRefNum" = "$QdecEcucPartitionRefCount"!]
[!ELSE!]
    [!VAR "QdecEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!FOR "PartitionIdx" = "1" TO "$QdecEcucPartitionRefNum"!]
    [!VAR "QdecInstOnPartition" = "num:i(count(QdecInstanceConfig/*))"!]
    [!VAR "CurrentPartionName" = "''"!]
    [!VAR "CurrentPartitionIndex" = "''"!]
    [!IF "$QdecEcucPartitionRefCount != 0 "!]
        [!VAR "CurrentPartionName" = "node:name(node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "CurrentPartitionIndex" = "substring-after($CurrentPartionName,'_')"!]
        [!VAR "QdecEcucPartitionRefName" = "node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)])"!]
        [!VAR "QdecInstOnPartition"  = "num:i(count(QdecInstanceConfig/*/QdecInstanceEcucPartitionRef/*[. = $QdecEcucPartitionRefName]))"!]
    [!ENDIF!]
    [!SELECT "QdecInstanceConfig"!]
        [!VAR "Comma" = "1"!]
/**
* @brief    Configurations for QDEC instances on Partition [!"$CurrentPartitionIndex"!]
*/
static const Qdec_InstanceConfigType Qdec_InstanceConfig[!"$VS_number"!][!IF "$QdecEcucPartitionRefCount != 0 "!]_[!"$CurrentPartionName"!][!ENDIF!][[!"num:i($QdecInstOnPartition)"!]U] =
{
        [!LOOP "../QdecInstanceConfig/*"!]
            [!IF "(($QdecEcucPartitionRefCount = 0) or (node:value(./QdecInstanceEcucPartitionRef/*[1]) = $QdecEcucPartitionRefName))"!]
    /* [!"@name"!] -> [!"QdecFtmModule"!] */
    {
        (Qdec_EncodingModeType) [!"node:value(./QdecEncodingMode)"!],   /** @brief */
        (uint16) [!"node:value(./QdecMinCounterValue)"!],   /** @brief Minimum counter value */
        (uint16) [!"node:value(./QdecMaxCounterValue)"!],   /** @brief Maximum counter value */
        (boolean) [!"text:toupper(node:value(./QdecEnTofIsr))"!],   /** @brief Timer Overflow Interrupt */
        /** @brief Configuration of input phase A */
        {
            (boolean) [!"text:toupper(node:value(./QdecmEnAPhaseFilter))"!],    /** @brief Enables the filter for the quadrature decoder phase A,B inputs */
            (uint8) [!"node:value(./QdecmAPhaseFilterVal)"!],   /** @brief Filter value (if input filter is enabled) */
            (Qdec_PhasePolarityType) [!"node:value(./QdecmAPhasePolarity)"!]    /** @brief Phase polarity */
        },
        /** @brief Configuration of input phase B */
        {
            (boolean) [!"text:toupper(node:value(./QdecmEnBPhaseFilter))"!],    /** @brief Enables the filter for the quadrature decoder phase A,B inputs */
            (uint8) [!"node:value(./QdecmBPhaseFilterVal)"!],   /** @brief Filter value (if input filter is enabled) */
            (Qdec_PhasePolarityType) [!"node:value(./QdecmBPhasePolarity)"!]    /** @brief Phase polarity */
        },
#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief  Qdec notification function */
        [!IF "node:exists('QdecOverflowNotification')"!]
            [!IF "(QdecOverflowNotification = '') or (QdecOverflowNotification = 'NULL_PTR') or (QdecOverflowNotification = 'NULL')"!]
            NULL_PTR
            [!ELSE!]
            &[!"QdecOverflowNotification"!]
            [!ENDIF!]
        [!ELSE!]
            NULL_PTR
        [!ENDIF!]
#endif
    }[!IF "(num:i($Comma))<(num:i($QdecInstOnPartition))"!],[!ENDIF!][!CR!][!VAR "Comma"="$Comma + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
};

    [!ENDSELECT!]
[!ENDFOR!]

[!FOR "PartitionIdx" = "1" TO "$QdecEcucPartitionRefNum"!]
    [!VAR "CurrentPartionName" = "''"!]
    [!VAR "CurrentPartitionIndex" = "''"!]
    [!VAR "QdecInstOnPartition" = "num:i(count(QdecInstanceConfig/*))"!]
    [!IF "$QdecEcucPartitionRefCount != 0 "!]
        [!VAR "CurrentPartionName" = "node:name(node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "CurrentPartitionIndex" = "substring-after($CurrentPartionName,'_')"!]
        [!VAR "QdecEcucPartitionRefName" = "node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)])"!]
        [!VAR "QdecInstOnPartition"  = "num:i(count(QdecInstanceConfig/*/QdecInstanceEcucPartitionRef/*[. = $QdecEcucPartitionRefName]))"!]
    [!ENDIF!]
    [!SELECT "QdecInstanceConfig"!]
        [!VAR "MaximumPartitionId" = "0"!]
        [!VAR "CurrentPartitionId" = "0"!]
        [!VAR "OutRespectivePartitionId" = "0"!]
        [!IF "$QdecEcucPartitionRefCount != 0 "!]
            [!LOOP "../QdecGeneral/QdecEcucPartitionRef/*"!]
                [!VAR "QdecPartRefName" = "node:value(.)"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "$QdecPartRefName = node:value(./OsAppEcucPartitionRef)"!]
                        [!SELECT "node:ref(./OsAppEcucPartitionRef)"!]
                            [!IF "$QdecPartRefName = $QdecEcucPartitionRefName"!]
                                [!VAR "OutRespectivePartitionId" = "node:pos(.)"!]
                            [!ENDIF!]
                            [!VAR "CurrentPartitionId" = "node:pos(.)"!]
                            [!IF "num:i($MaximumPartitionId) < num:i($CurrentPartitionId)"!]
                                [!VAR "MaximumPartitionId" = "$CurrentPartitionId"!]
                            [!ENDIF!]
                        [!ENDSELECT!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDLOOP!]
        [!ENDIF!]
        [!IF "((../IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1)) or (../IMPLEMENTATION_CONFIG_VARIANT ='VariantPostBuild' and (variant:size() <= 0)))"!]
            [!IF "(../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
/*
*   @brief Pre-Compile Default Configuration for Partition [!"$CurrentPartitionIndex"!]
*/
#if (STD_ON == QDEC_PRECOMPILE_SUPPORT)
            [!ENDIF!]
[!IF "$QdecEcucPartitionRefCount != 0 "!]
const Qdec_ConfigType Qdec_Config_[!"$CurrentPartionName"!] =
[!ELSE!]
const Qdec_ConfigType Qdec_Config =
[!ENDIF!]
        [!ELSE!]
/*
*   @brief Postbuild Configuration for Partition [!"$CurrentPartitionIndex"!]
*/
[!IF "$QdecEcucPartitionRefCount != 0 "!]
const Qdec_ConfigType Qdec_Config[!"$VS_number"!]_[!"$CurrentPartionName"!] =
[!ELSE!]
const Qdec_ConfigType Qdec_Config[!"$VS_number"!] =
[!ENDIF!]
        [!ENDIF!]
{
    (uint8) [!"num:i($OutRespectivePartitionId)"!]U,    /* Partition index */
    (uint8) [!"num:i($QdecInstOnPartition)"!]U, /* Number of QDEC instances on this Partition */
    &Qdec_InstanceConfig[!"$VS_number"!][!IF "$QdecEcucPartitionRefCount != 0 "!]_[!"$CurrentPartionName"!][!ENDIF!],   /* Qdec_InstanceConfigTypePtr */
    Qdec_Ipw_Config[!"$VS_number"!][!IF "$QdecEcucPartitionRefCount != 0 "!]_[!"$CurrentPartionName"!][!ENDIF!]

};
        [!IF "(../IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!]
#endif /*STD_ON == QDEC_PRECOMPILE_SUPPORT*/
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDFOR!]
[!IF "$QdecEcucPartitionRefCount != 0 "!]
    [!SELECT "QdecInstanceConfig"!]
        [!IF "(../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
            [!VAR "QdecEcucPartitionRefCount" = "num:i(count(as:modconf('Qdec')[1]/QdecGeneral/QdecEcucPartitionRef/*))"!]
            [!IF "$QdecEcucPartitionRefCount != 0 "!]
                [!VAR "QdecEcucPartitionRefNum" = "$QdecEcucPartitionRefCount"!]
                [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
                    [!VAR "maxPartition" = "0"!]
                    [!LOOP "../QdecGeneral/QdecEcucPartitionRef/*"!]
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
#if (STD_ON == QDEC_PRECOMPILE_SUPPORT)
const Qdec_ConfigType* const Qdec_Config[QDEC_MAX_PARTITIONS] =
{
[!NOCODE!]
            [!FOR "CurrentPartitionId" = "0" TO "num:i($maxPartition)"!]
                [!VAR "HasCore" = "0"!]
                [!VAR "HasPartition" = "0"!]
                [!VAR "foundPartition" = "0"!]
                [!LOOP "as:modconf('Qdec')[1]/QdecGeneral/QdecEcucPartitionRef/*"!]
                    [!IF "num:i($foundPartition) = 0"!]
                        [!VAR "QdecEcucPartitionRefName" = "node:value(.)"!]
                        [!VAR "CurrentPartionName" = "node:name(node:value(.))"!]
                        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                            [!IF "$QdecEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                                [!SELECT "node:ref(./OsAppEcucPartitionRef)"!]
                                    [!VAR "OsPartitionId" = "node:pos(.)"!]
                                    [!IF "num:i($OsPartitionId) = num:i($CurrentPartitionId)"!]
                                        [!VAR "HasCore" = "1"!]
                                        [!LOOP "as:modconf('Qdec')[1]/QdecInstanceConfig/*"!]
                                            [!LOOP "./QdecInstanceEcucPartitionRef/*"!]
                                                [!VAR "QdecInstanceEcucPartitionRefName" = "node:value(.)"!]
                                                [!IF "$QdecInstanceEcucPartitionRefName = $QdecEcucPartitionRefName"!]
                                                    [!VAR "HasPartition" = "1"!]
                                                    [!VAR "foundPartition" = "1"!]
                                                [!ENDIF!]
                                            [!ENDLOOP!]
                                        [!ENDLOOP!]
                                    [!ENDIF!]
                                [!ENDSELECT!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$HasCore = 1"!]
                    [!IF "$HasPartition = 1"!]
            [!CODE!][!WS "4"!]/** @brief  Pointer to configuration structure of QDEC for partition [!"num:i($CurrentPartitionId)"!] */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]&Qdec_Config_[!"$CurrentPartionName"!][!ENDCODE!]
                    [!ELSE!]
            [!CODE!][!WS "4"!]/** @brief  No configuration structure of QDEC refered by partition [!"num:i($CurrentPartitionId)"!] */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]NULL_PTR[!ENDCODE!]
                    [!ENDIF!]
                [!ELSE!]
        [!CODE!][!WS "4"!]/** @brief  No configuration structure of QDEC refered by partition [!"num:i($CurrentPartitionId)"!] */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!] NULL_PTR[!ENDCODE!]
                [!ENDIF!]
                [!IF "$CurrentPartitionId < num:i($maxPartition)"!][!CODE!],[!ENDCODE!][!ENDIF!][!CR!]
            [!ENDFOR!]
[!ENDNOCODE!]
};
#endif /*STD_ON == QDEC_PRECOMPILE_SUPPORT*/
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDIF!]

#define QDEC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

 #ifdef __cplusplus
}
#endif

/**@}*/
[!ENDCODE!]