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
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   3
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.C and IntCtrl_Ip_Cfg.h are different"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]

[!/* Get core id which is mapped to ParamPartitionRefName by Os */!]
[!MACRO "GetPartitionCoreId", "ParamPartitionRefName"!][!//
[!NOCODE!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!IF "$ParamPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
            [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                [!VAR "CoreId"="node:value(./EcucCoreId)"!]
            [!ENDSELECT!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!CODE!][!"$CoreId"!][!ENDCODE!]
    [!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "GeneralConfiguration/PlatformEnableIntCtrlConfiguration"!] /* IntCtrl settings */
[!IF "(GeneralConfiguration/ARM_Core = 'ARM_R_ARCH')"!][!//
[!VAR "tempHandlersList"!][!ENDVAR!]
[!FOR "ClusterIndex" = "0" TO "1"!]
    [!FOR "CoreIndex" = "0" TO "1"!]
        [!VAR "VectorName" = "concat('R52VtableMem_', 'Cluster', $ClusterIndex, '_Core', $CoreIndex)"!]
        [!IF "node:refexists(concat('GeneralConfiguration/',$VectorName))"!]
            [!VAR "tempHandlersList" = "concat($tempHandlersList, node:value(concat('GeneralConfiguration/',$VectorName)), ' ')"!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDFOR!]

[!VAR "uniqueHandlers"!][!ENDVAR!]
[!VAR "uniqueHandlers" = "concat(' ',$uniqueHandlers)"!]
[!LOOP "text:split($tempHandlersList)"!]
    [!IF "contains($uniqueHandlers, concat(' ', . , ' ')) = 0"!]
        [!VAR "uniqueHandlers" = "concat($uniqueHandlers, . , ' ')"!]
        [!IF "contains(. , 'NULL_PTR') = 0"!]
            [!CODE!]extern uint32 [!"."!][1U];[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]

[!ENDIF!]
[!CODE!]
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]


[!VAR "PlatformIrqConfig" = "'PlatformIsrConfig'"!]


[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "numPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]

[!IF "$numPartition = 0"!]
    [!ERROR!] At least one EcucPartition needs to be defined when PlatformMulticoreSupport node is enabled [!ENDERROR!]
[!ENDIF!]

[!VAR "PartitionCoreIdList"= "''"!]
[!VAR "IsSameCoreId"= "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!VAR "PartitionRefName" = "node:value(./PlatformNvicEcucPartitionRef)"!]
    [!VAR "CoreId"!][!CALL "GetPartitionCoreId", "ParamPartitionRefName" = "$PartitionRefName"!][!ENDVAR!]
    [!IF "(text:contains(text:split($PartitionCoreIdList), $CoreId))"!]
        [!VAR "IsSameCoreId"= "1"!]  
    [!ENDIF!]
    [!VAR "PartitionCoreIdList" = "concat($PartitionCoreIdList, ' ', $CoreId)"!]
[!ENDLOOP!]

[!IF "$IsSameCoreId = 1"!][!// Exist IntCtrl Partitions which are mapped to the same core id
    [!VAR "IntCtrlIsrNameList" = "''"!]
    [!VAR "IntCtrlIsrCoreList" = "''"!]
    [!FOR "IntCtrlPartitionIdx" = "1" TO "count(text:split($PartitionCoreIdList))"!]
        [!VAR "currentCoreId" = "text:split($PartitionCoreIdList)[num:i($IntCtrlPartitionIdx)]"!]
        [!LOOP "node:ref(concat('IntCtrlConfig/*[',$IntCtrlPartitionIdx,']/', $PlatformIrqConfig))/*"!]
            [!VAR "aIsrName" = "node:value(./IsrName)"!]
            [!VAR "IntCtrlIsrNameList" = "concat($IntCtrlIsrNameList, ' ', $aIsrName)"!]
            [!VAR "IntCtrlIsrCoreList" = "concat($IntCtrlIsrCoreList, ' ', $currentCoreId)"!]
        [!ENDLOOP!]
    [!ENDFOR!]

    [!FOR "xIsrIdx" = "1" TO "count(text:split($IntCtrlIsrNameList))-1"!]
        [!FOR "yIsrIdx" = "$xIsrIdx+1" TO "count(text:split($IntCtrlIsrNameList))"!]
            [!IF "text:split($IntCtrlIsrNameList)[num:i($yIsrIdx)] = text:split($IntCtrlIsrNameList)[num:i($xIsrIdx)]"!]
                [!IF "text:split($IntCtrlIsrCoreList)[num:i($yIsrIdx)] = text:split($IntCtrlIsrCoreList)[num:i($xIsrIdx)]"!]
                    [!ERROR!]Cannot configure [!"text:split($IntCtrlIsrNameList)[num:i($yIsrIdx)]"!] on multiple partitions which are mapped to the same core id [!"text:split($IntCtrlIsrCoreList)[num:i($yIsrIdx)]"!].[!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
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

[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!CODE!]

[!IF "(num:i(count(node:ref($PlatformIrqConfig)/*)) > 0)"!]
/* List of configurations for interrupts */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[!"$PartitionShortName"!][] = {
[!NOCODE!]
[!LOOP "node:ref($PlatformIrqConfig)/*"!]
[!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U, &[!"IsrHandler"!]},
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]};
[!ENDIF!]
/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig[!"$PartitionShortName"!] = {
    [!"num:i(count(node:ref($PlatformIrqConfig)/*))"!]U,
    [!IF "(./../../GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!]
    [!"./PlatformVtorAddressConfig"!]U [!ENDIF!]
    [!IF "(num:i(count(node:ref($PlatformIrqConfig)/*)) > 0)"!]
    aIrqConfiguration[!"$PartitionShortName"!]
    [!ELSE!]
    NULL_PTR
    [!ENDIF!]
};



        [!ENDCODE!]
    [!ENDIF!] [!//  [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
[!ENDLOOP!] [!//  [!LOOP "IntCtrlConfig/*"!]

[!CODE!]

/*===============================END Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ELSE!] [!// [!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!CODE!]
[!IF "(num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*)) > 0)"!]
/* List of configurations for interrupts */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
[!NOCODE!]
[!LOOP "node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*"!]
[!CODE!]    {[!"IsrName"!], (boolean)[!IF "IsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], [!"IsrPriority"!]U, &[!"IsrHandler"!]},
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]};
[!ENDIF!]
/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    [!"num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*))"!]U,
    [!IF "(GeneralConfiguration/PlatformEnableVtorConfiguration = 'true')"!] [!LOOP "IntCtrlConfig/*[1]"!]
    [!CODE!][!"PlatformVtorAddressConfig"!]U, [!ENDCODE!] [!ENDLOOP!]
    [!ENDIF!]
    [!IF "(num:i(count(node:ref(concat('IntCtrlConfig/*[1]/', $PlatformIrqConfig))/*)) > 0)"!]
    aIrqConfiguration
    [!ELSE!]
    NULL_PTR
    [!ENDIF!]
};
    [!ENDCODE!]
[!ENDIF!] [!// count(IntCtrlConfig/*) > 0

[!ENDIF!] [!// multi-partition

[!CODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]
[!ENDIF!]  /* IntCtrl settings */
[!ENDNOCODE!]
#ifdef __cplusplus
}
#endif
