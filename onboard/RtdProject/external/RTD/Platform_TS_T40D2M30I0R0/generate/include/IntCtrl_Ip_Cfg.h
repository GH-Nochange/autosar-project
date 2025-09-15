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

#ifndef INTCTRL_IP_CFG_H_
#define INTCTRL_IP_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_TypesDef.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION        0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION                   0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION != CDD_PLATFORM_INTCTRL_IP_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.h and IntCtrl_Ip_TypesDef.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!IF "GeneralConfiguration/PlatformEnableIntCtrlConfiguration"!] /* IntCtrl settings */
[!NOCODE!]
[!CODE!]
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]
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
[!NOCODE!]
[!VAR "NvicVectorAvailable" = "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!VAR "NvicVectorAvailable" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
  
[!IF "$NvicVectorAvailable = 1"!]
/* Definition of the configuration structure for Platform IPW */
extern const IntCtrl_Ip_CtrlConfigType intCtrlConfig[!"$PartitionShortName"!];
[!ENDIF!]


/*================================== End Partition [!"$PartitionShortName"!] ==============================*/
[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ELSE!]
[!IF "count(IntCtrlConfig/*) > 0"!]
[!CODE!]
/* Definition of the configuration structure for Platform IPW */
extern const IntCtrl_Ip_CtrlConfigType intCtrlConfig;
[!ENDCODE!]
[!ENDIF!] [!// count(IntCtrlConfig/*) > 0
[!CODE!]

[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/* Declaration of interrupt handlers 
 * NOTE: For application specific handlers, these functions must be implemented in the application code!
 */
[!NOCODE!]

[!VAR "tempHandlersList"!][!ENDVAR!]
[!LOOP "IntCtrlConfig/*"!]
[!LOOP "./PlatformIsrConfig/*"!]
    [!VAR "tempHandlersList" = "concat($tempHandlersList, IsrHandler, ' ')"!]
[!ENDLOOP!]
[!ENDLOOP!]

[!VAR "uniqueHandlers"!][!ENDVAR!]
[!VAR "uniqueHandlers" = "concat(' ',$uniqueHandlers)"!]
[!LOOP "text:split($tempHandlersList)"!]
    [!IF "contains($uniqueHandlers, concat(' ', . , ' ')) = 0"!]     
        [!VAR "uniqueHandlers" = "concat($uniqueHandlers, . , ' ')"!]
        [!IF "contains(. , 'NULL_PTR') and (contains(text:split($uniqueHandlers), 'undefined_handler') = 0) or (contains(. , 'undefined_handler') and contains(text:split($uniqueHandlers), 'NULL_PTR') = 0)"!]  
            [!CODE!]extern void undefined_handler(void);[!CR!][!ENDCODE!]           
        [!ELSE!]
            [!IF "contains(. , 'undefined_handler') = 0 and (contains(. , 'NULL_PTR') = 0)"!]
                [!CODE!]extern void [!"."!](void);[!CR!][!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]

[!CODE!]
#if  (PLATFORM_IP_ENABLE_INT_CTRL == STD_ON)
    #if (INT_CTRL_IP_CORTEXR == STD_ON)
    #if (defined(INT_CTRL_CORE_SPECIFIC_VTABLE) && (INT_CTRL_CORE_SPECIFIC_VTABLE == STD_ON))
extern IntCtrl_Ip_IrqHandlerType *const R52VtableRefArray[INT_CTRL_NUM_CORE_R52];
    #endif
    #endif
#endif /* PLATFORM_IP_ENABLE_INT_CTRL == STD_ON */
[!ENDCODE!]

[!CODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!ENDCODE!]

[!ENDNOCODE!]
[!ENDIF!] /* IntCtrl settings */
#endif /* INTCTRL_IP_CFG_H_ */

