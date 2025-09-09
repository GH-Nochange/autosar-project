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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
[!NOCODE!]
[!VAR "McmAvailable" = "0"!]
[!IF "GeneralConfiguration/PlatformMcmConfigurable"!]
    [!IF "count(McmConfig/*) > 0"!]
        [!VAR "McmAvailable" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "IntCtrlAvailable" = "0"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!VAR "IntCtrlAvailable" = "1"!]
[!ENDIF!]

[!VAR "PlatformMpuAvailable" = "0"!]
[!IF "GeneralConfiguration/PlatformMpuConfigurable"!]
    [!IF "count(Mpu_Configuration/MpuRegionConfig/*) > 0"!]
        [!VAR "PlatformMpuAvailable" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Platform_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C              3
#define CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_IPW_CFG_VENDOR_ID_C != CDD_PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]


[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "numPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]

[!IF "$numPartition = 0"!]
    [!ERROR!] At least one EcucPartition needs to be defined when Platform MultiPartition Support node is enabled [!ENDERROR!]
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
[!IF "$PartitionIdConfigured  = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!VAR "McmConfigAvailable" = "0"!]
[!IF "$McmAvailable = 1"!] /* System settings */
    [!VAR "McmConfigAvailable" = "0"!]
    [!LOOP "McmConfig/*"!]
        [!IF "./PlatformMcmEcucPartitionRef = $PartitionRefName "!]
            [!VAR "McmConfigAvailable" = "1"!]
            [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for system interrupts */
static const Platform_SystemIrqConfigType aSysIrqCfg[!"$PartitionShortName"!][] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] }[!IF "not(node:islast())"!],[!ENDIF!][!ENDLOOP!]
};

/* system configurations for [!"$PartitionShortName"!]*/
static const Platform_SystemConfigType SystemConfig[!"$PartitionShortName"!] =
{
    aSysIrqCfg[!"$PartitionShortName"!],
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U,
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE[!ELSE!]TRUE[!ENDIF!]
};
#endif
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]

[!VAR "NvicConfigAvailable" = "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!VAR "NvicConfigAvailable" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]

[!VAR "MpuConfigAvailable" = "0"!]
[!IF "$PlatformMpuAvailable = 1"!] /* System settings */
    [!VAR "MpuConfigAvailable" = "0"!]
    [!LOOP "Mpu_Configuration/MpuRegionConfig/*"!]
        [!IF "./PlatformMpuEcucPartitionRef = $PartitionRefName "!]
            [!VAR "MpuConfigAvailable" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]

[!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig[!"$PartitionShortName"!] = {
[!IF "(GeneralConfiguration/PlatformEnableIntCtrlConfiguration = 'true')"!][!//
    [!IF "$NvicConfigAvailable = 1"!]&intCtrlConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR [!ENDIF!] , /* Interrupt controller configuration */
[!ENDIF!][!//
[!IF "(GeneralConfiguration/PlatformMcmConfigurable = 'true')"!][!//
    [!IF "$McmConfigAvailable = 1"!]&SystemConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR [!ENDIF!] , /* System settings */
[!ENDIF!]
[!IF "(GeneralConfiguration/PlatformMpuConfigurable = 'true')"!][!//
    [!IF "$MpuConfigAvailable = 1"!]&Mpu_Config[!"$PartitionShortName"!][!ELSE!]NULL_PTR[!ENDIF!] /* Mpu Configuration */
[!ENDIF!]
};
/*================================== End Partition [!"$PartitionShortName"!] ==============================*/



[!ENDCODE!]

[!ENDIF!]
[!ENDFOR!]

[!ELSE!][!//multicore
    [!IF "$McmAvailable = 1"!] /* System settings */
    [!SELECT "McmConfig/*[1]"!]
        [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for CM7 system interrupts */
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
static const Platform_SystemIrqConfigType aSysIrqCfg[] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] },[!ENDLOOP!]
};
[!ENDIF!][!//
/* system configurations */
static const Platform_SystemConfigType SystemConfig =
{
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
    aSysIrqCfg,
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U,
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE [!ELSE!] TRUE [!ENDIF!]
};
#endif
    [!ENDCODE!]
    [!ENDSELECT!][!//SELECT "McmConfig/*[1]"
    [!ENDIF!][!// McmAvailable

[!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig = {
[!IF "(GeneralConfiguration/PlatformEnableIntCtrlConfiguration = 'true')"!][!//
    [!IF "$IntCtrlAvailable = 1"!]&intCtrlConfig[!ELSE!]NULL_PTR[!ENDIF!] , /* Interrupt controller configuration */
[!ENDIF!][!//
[!IF "(GeneralConfiguration/PlatformMcmConfigurable = 'true')"!][!//
    [!IF "$McmAvailable = 1"!]&SystemConfig [!ELSE!]NULL_PTR[!ENDIF!] , /* System settings */
[!ENDIF!][!//
[!IF "(GeneralConfiguration/PlatformMpuConfigurable = 'true')"!][!//
    [!IF "$PlatformMpuAvailable = 1"!]&Mpu_Config[!ELSE!]NULL_PTR[!ENDIF!] /* Mpu Configuration */
[!ENDIF!]
};
[!ENDCODE!]

[!ENDIF!][!//multicore
[!ENDNOCODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
