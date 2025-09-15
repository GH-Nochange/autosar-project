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

/**
*   @file Mpu_Ip_PBcfg.c
*
*   @addtogroup MPU_IP MPU IPV Driver
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
#include "Mpu_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION_C              3
#define CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip_Cfg.h */
#if (CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_MPU_IP_CFG_VENDOR_ID)
    #error "Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h have different vendor ids"
#endif
#if ((CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg.h are different"
#endif
#if ((CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_MPU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.c and Mpu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

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
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]
[!IF "GeneralConfiguration/PlatformMpuConfigurable"!] /* Mpu settings */

/* Check  available master in resource */
[!VAR "Master0Support" = "ecu:get('Platform.Mpu.Master0.CoreSupport')"!]
[!VAR "Master1Support" = "ecu:get('Platform.Mpu.Master1.DebuggerSupport')"!]
[!VAR "Master2Support" = "ecu:get('Platform.Mpu.Master2.DMASupport')"!]
[!VAR "Master3Support" = "ecu:get('Platform.Mpu.Master3.EnetSupport')"!]

[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]

/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "numPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]

[!IF "$numPartition = 0"!]
    [!ERROR!] At least one EcucPartition needs to be defined when PlatformMulticoreSupport node is enabled [!ENDERROR!]
[!ENDIF!]

[!FOR "CurrentPartitionId" = "0" TO "$numPartition - 1"!]
    [!VAR "PartitionIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "CurrentPartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!]
            [!IF "$CurrentPartitionShortName = node:name(.)"!]
                [!IF "$CurrentPartitionId = node:pos(.)"!]
                    [!VAR "PartitionIdConfigured" = "1"!]
                    [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                    [!VAR "PartitionRefName" = "$CurrentPartitionRefName"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!IF "$PartitionIdConfigured = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
        [!VAR "MpuRegionCfgExist" = "0"!]
        [!VAR "MpuRegionCfgCount" = "0"!]
        [!LOOP "Mpu_Configuration/MpuRegionConfig/*[node:exists(PlatformMpuEcucPartitionRef)]"!]
            [!IF "./PlatformMpuEcucPartitionRef = $PartitionRefName "!]
                [!VAR "MpuRegionCfgExist" = "1"!]
                [!VAR "MpuRegionCfgCount" = "$MpuRegionCfgCount + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MpuRegionCfgExist = 1"!]
[!SELECT "./Mpu_Configuration"!][!//
[!CODE!]
const Mpu_Ip_RegionConfigType [!"@name"!]_RegionConfig[!"$PartitionShortName"!][[!"num:i($MpuRegionCfgCount)"!]] =
{
[!ENDCODE!]
[!VAR "MpuLoopIt" = "$MpuRegionCfgCount"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
[!IF "./PlatformMpuEcucPartitionRef = $PartitionRefName "!]
    [!/* Get the MxUM, MxSM values which are depended on the available master */!]
    [!IF "$Master0Support = 'true'"!]
        [!VAR "M0UM" = "node:current()/UserModeAccessBusMaster0"!]
        [!VAR "M0SM" = "node:current()/SupervisorModeAccessBusMaster0"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M0UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M0UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master1Support = 'true'"!]
        [!VAR "M1UM" = "node:current()/UserModeAccessBusMaster1"!]
        [!VAR "M1SM" = "node:current()/SupervisorModeAccessBusMaster1"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M1UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M1UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master2Support = 'true'"!]
        [!VAR "M2UM" = "node:current()/UserModeAccessBusMaster2"!]
        [!VAR "M2SM" = "node:current()/SupervisorModeAccessBusMaster2"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M2UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M2UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master3Support = 'true'"!]
        [!VAR "M3UM" = "node:current()/UserModeAccessBusMaster3"!]
        [!VAR "M3SM" = "node:current()/SupervisorModeAccessBusMaster3"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M3UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M3UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

[!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
[!CODE!]
    /* Region Configuration [!"node:current()/RegionNumber"!] */
    {
        [!"node:current()/StartAddress"!]UL,
        [!"node:current()/EndAddress"!]UL,
[!IF "(node:current()/ProcessIdentifierEnableMaster0 = 'true') and ($Master0Support = 'true')"!][!//
        (MPU_RGD_WORD2_M0PE_MASK) | \
[!ENDIF!][!//
[!IF "(node:current()/ProcessIdentifierEnableMaster1 = 'true') and ($Master1Support = 'true')"!][!//
        (MPU_RGD_WORD2_M1PE_MASK) | \
[!ENDIF!][!//
        ([!"$M0SM"!] << MPU_RGD_WORD2_M0SM_SHIFT) | \
        ([!"$M1SM"!] << MPU_RGD_WORD2_M1SM_SHIFT) | \
        ([!"$M2SM"!] << MPU_RGD_WORD2_M2SM_SHIFT) | \
        ([!"$M3SM"!] << MPU_RGD_WORD2_M3SM_SHIFT) | \
        ([!"$M0UM"!] << MPU_RGD_WORD2_M0UM_SHIFT) | \
        ([!"$M1UM"!] << MPU_RGD_WORD2_M1UM_SHIFT) | \
        ([!"$M2UM"!] << MPU_RGD_WORD2_M2UM_SHIFT) | \
        ([!"$M3UM"!] << MPU_RGD_WORD2_M3UM_SHIFT),
        ([!"node:current()/ProcessIdentifier"!]U),
        ([!"node:current()/ProcessIdentifierMask"!]U)
    }[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDCODE!]
[!ENDIF!]
[!ENDLOOP!][!//
[!CODE!]
};

static const uint8 [!"@name"!]_RegionNumber[!"$PartitionShortName"!][[!"num:i($MpuRegionCfgCount)"!]] =
{
[!ENDCODE!]
[!VAR "MpuLoopIt" = "$MpuRegionCfgCount"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
    [!IF "./PlatformMpuEcucPartitionRef = $PartitionRefName "!]
    [!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
[!CODE!]
    [!"node:current()/RegionNumber"!]U[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!CODE!]
};

const Mpu_Ip_ConfigType Mpu_Config[!"$PartitionShortName"!] =
{
    [!"num:i($MpuRegionCfgCount)"!]U,
    [!"@name"!]_RegionConfig[!"$PartitionShortName"!],
    [!"@name"!]_RegionNumber[!"$PartitionShortName"!]
};
[!ENDCODE!][!//
[!ENDSELECT!][!//
        [!ENDIF!][!// MpuRegionCfgExist == 1
[!CODE!]
/*===============================END Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
    [!ENDIF!][!//[!IF "$PartitionIdConfigured = 1"!]
[!ENDFOR!]
[!ELSE!] [!// [!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]

[!CODE!]
[!SELECT "./Mpu_Configuration"!][!//
const Mpu_Ip_RegionConfigType [!"@name"!]_RegionConfig[[!"num:i(count(MpuRegionConfig/*))"!]] =
{
[!VAR "MpuLoopIt" = "count(node:current()/MpuRegionConfig/*)"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
[!NOCODE!]
    [!/* Get the MxUM, MxSM values which are depended on the available master */!]
    [!IF "$Master0Support = 'true'"!]
        [!VAR "M0UM" = "node:current()/UserModeAccessBusMaster0"!]
        [!VAR "M0SM" = "node:current()/SupervisorModeAccessBusMaster0"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M0UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M0UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M0SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master1Support = 'true'"!]
        [!VAR "M1UM" = "node:current()/UserModeAccessBusMaster1"!]
        [!VAR "M1SM" = "node:current()/SupervisorModeAccessBusMaster1"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M1UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M1UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M1SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master2Support = 'true'"!]
        [!VAR "M2UM" = "node:current()/UserModeAccessBusMaster2"!]
        [!VAR "M2SM" = "node:current()/SupervisorModeAccessBusMaster2"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M2UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M2UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M2SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$Master3Support = 'true'"!]
        [!VAR "M3UM" = "node:current()/UserModeAccessBusMaster3"!]
        [!VAR "M3SM" = "node:current()/SupervisorModeAccessBusMaster3"!]
    [!ELSE!]
        [!IF "node:current()/RegionNumber = '0'"!]
            [!VAR "M3UM" = "'MPU_USER_MODE_RWX'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_AS_USER_MODE'"!]
        [!ELSE!]
            [!VAR "M3UM" = "'MPU_USER_MODE_NONE'"!]
            [!VAR "M3SM" = "'MPU_SUPERVISOR_MODE_RWX'"!]
        [!ENDIF!]
    [!ENDIF!]

[!ENDNOCODE!][!//
[!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
    /* Region Configuration [!"node:current()/RegionNumber"!] */
    {
        [!"node:current()/StartAddress"!]UL,
        [!"node:current()/EndAddress"!]UL,
[!IF "(node:current()/ProcessIdentifierEnableMaster0 = 'true') and ($Master0Support = 'true')"!][!//
        (MPU_RGD_WORD2_M0PE_MASK) | \
[!ENDIF!][!//
[!IF "(node:current()/ProcessIdentifierEnableMaster1 = 'true') and ($Master1Support = 'true')"!][!//
        (MPU_RGD_WORD2_M1PE_MASK) | \
[!ENDIF!][!//
        ([!"$M0SM"!] << MPU_RGD_WORD2_M0SM_SHIFT) | \
        ([!"$M1SM"!] << MPU_RGD_WORD2_M1SM_SHIFT) | \
        ([!"$M2SM"!] << MPU_RGD_WORD2_M2SM_SHIFT) | \
        ([!"$M3SM"!] << MPU_RGD_WORD2_M3SM_SHIFT) | \
        ([!"$M0UM"!] << MPU_RGD_WORD2_M0UM_SHIFT) | \
        ([!"$M1UM"!] << MPU_RGD_WORD2_M1UM_SHIFT) | \
        ([!"$M2UM"!] << MPU_RGD_WORD2_M2UM_SHIFT) | \
        ([!"$M3UM"!] << MPU_RGD_WORD2_M3UM_SHIFT),
        ([!"node:current()/ProcessIdentifier"!]U),
        ([!"node:current()/ProcessIdentifierMask"!]U)
    }[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDLOOP!][!//
};

static const uint8 [!"@name"!]_RegionNumber[[!"num:i(count(MpuRegionConfig/*))"!]] =
{
[!VAR "MpuLoopIt" = "count(node:current()/MpuRegionConfig/*)"!][!//
[!LOOP "node:current()/MpuRegionConfig/*"!][!//
[!VAR "MpuLoopIt" = "$MpuLoopIt - 1"!][!//
    [!"node:current()/RegionNumber"!]U[!IF "$MpuLoopIt != 0"!],[!ENDIF!]
[!ENDLOOP!][!//
};

const Mpu_Ip_ConfigType Mpu_Config =
{
    [!"num:i(count(MpuRegionConfig/*))"!]U,
    [!"@name"!]_RegionConfig,
    [!"@name"!]_RegionNumber
};
[!ENDSELECT!][!//

[!ENDCODE!][!//

[!ENDIF!] [!// multi-partition
[!ENDIF!][!//* Mpu settings */
[!ENDNOCODE!][!//
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
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

