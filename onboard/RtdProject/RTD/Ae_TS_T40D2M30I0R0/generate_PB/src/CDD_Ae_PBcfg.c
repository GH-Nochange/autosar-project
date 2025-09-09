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
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file CDD_Ae_PBcfg.c
*   @addtogroup AE_DRIVER_CONFIGURATION Ae Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ae.h"
#include "CDD_Ae_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C                     43
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Ae.h */
#if (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C != CDD_AE_VENDOR_ID)
    #error "CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae.h have different vendor ids"
#endif
#if ((CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != CDD_AE_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != CDD_AE_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != CDD_AE_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae.h are different"
#endif
#if ((CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C != CDD_AE_SW_MAJOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C != CDD_AE_SW_MINOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C != CDD_AE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae.h are different"
#endif

/* Checks against CDD_Ae_Ipw_Cfg.h */
#if (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C != CDD_AE_IPW_CFG_VENDOR_ID)
    #error "CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae_Ipw_Cfg.h have different vendor ids"
#endif
#if ((CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != CDD_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != CDD_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != CDD_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae_Ipw_Cfg.h are different"
#endif
#if ((CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C != CDD_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C != CDD_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (CDD_AE_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C != CDD_AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ae[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Ae_Ipw_Cfg.h are different"
#endif


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
AE_IPW_CONFIG_EXT

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!MACRO "GetConfigStructName"!][!//
[!NOCODE!]
    [!VAR "Mac_CtrlConfigStructureName" = "'NULL_PTR'"!]
    [!VAR "Mac_PostBuildVariantNameUnderscore" = "string(null)"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "Mac_PostBuildVariantNameUnderscore" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]
    [!VAR "Mac_CtrlConfigStructureName" = "concat('&Ae_Ipw_aConfigPB', $Mac_PostBuildVariantNameUnderscore, '')"!]
    [!CODE!][!"$Mac_CtrlConfigStructureName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Ae_ConfigurationInfo"!][!//
[!NOCODE!]
[!IF "node:exists(as:modconf('Ae')[1]/AeGeneral/AeMultipartitionSupport)"!]
[!VAR "MultiCorePartitionEnable" = "as:modconf('Ae')[1]/AeGeneral/AeMultipartitionSupport"!]
[!ENDIF!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!ENDIF!]
    [!VAR "AeConfiguredPartitions" = "num:i(count(AeGeneral/AeEcucPartitionRef/*))"!]
    [!VAR "TotalPartition" = "num:i(count(AeGeneral/AeEcucPartitionRef/*))"!]
    [!IF "$AeConfiguredPartitions = 0"!]
        [!VAR "TotalPartition" = "num:i(1)"!]
    [!ENDIF!]
    [!FOR "PartitionCount" = "1" TO "$TotalPartition"!]
        [!IF "$MultiCorePartitionEnable = 'true'"!]
            [!VAR "CurrentPartition" = "concat('_',node:name(node:ref(AeGeneral/AeEcucPartitionRef/*[num:i($PartitionCount)])))"!]
        [!ELSE!]
            [!VAR "CurrentPartition" = "string(null)"!]
        [!ENDIF!]
[!CODE!]
/** Compiler_Warning: In some cases, the partition configuration may not be used by the application. */
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!]static [!ENDIF!]const Ae_ConfigType Ae_Config[!IF "(IMPLEMENTATION_CONFIG_VARIANT ='VariantPostBuild') or (variant:size()>1)"!][!"$postBuildVariantNameUnderscore"!][!ENDIF!][!"$CurrentPartition"!]=
{
[!ENDCODE!]
[!IF "$MultiCorePartitionEnable = 'true'"!]
    [!VAR "CurrentPName" = "node:value(AeGeneral/AeEcucPartitionRef/*[num:i($PartitionCount)])"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
        [!IF "$CurrentPName = node:value(./OsAppEcucPartitionRef)"!][!//
        [!IF "node:exists(as:modconf('Ae')[1]/AeGeneral/AeMultipartitionSupport)"!]
            [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
        [!CODE!]    (uint32)[!"num:i(node:pos(.))"!]U, /* u32AeCorePartitionUse*/[!ENDCODE!]
            [!ENDSELECT!][!//
        [!ENDIF!][!//
        [!BREAK!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ELSE!]
[!CODE!]    (uint32)AE_SPURIOUS_ID_U32, /* u32AeCorePartitionUse */[!ENDCODE!]
[!ENDIF!]
[!CODE!]
        [!CALL "GetConfigStructName"!][!"$CurrentPartition"!], /* pcExternalDeviceConfig */
};
[!ENDCODE!]
    [!ENDFOR!]
[!CODE!]
[!VAR "numPartition" = "0"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "numPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]

[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' and (variant:size() <= 1))"!]
[!IF "$MultiCorePartitionEnable = 'true'"!]
const Ae_ConfigType * const Ae_xPredefinedConfig[[!"num:i($numPartition)"!]]=
{
[!NOCODE!]
    [!VAR "MaxCorePartitionId"="0"!]
    [!IF "node:exists(as:modconf('Ae')[1]/AeGeneral/AeMultipartitionSupport)"!]
    [!LOOP "as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!][!//
        [!IF "$MaxCorePartitionId < node:pos(.)"!]
            [!VAR "MaxCorePartitionId"="node:pos(.)"!]
        [!ENDIF!]
    [!ENDLOOP!][!//
    [!ENDIF!]
    [!VAR "MacNoPartitions" = "0"!][!//
    [!FOR "AeCorePartitionIdCount"="0" TO "$MaxCorePartitionId"!]
        [!VAR "CorePartitionIsMatch" = "'false'"!]
        [!VAR "Partitionname" = "0"!][!//
        [!LOOP "AeGeneral/AeEcucPartitionRef/*"!]
            [!VAR "MacPartNo" = "node:name(node:ref(.))"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "$MacPartNo = node:name(node:ref(./OsAppEcucPartitionRef))"!]
                        [!IF "node:exists(as:modconf('Ae')[1]/AeGeneral/AeMultipartitionSupport)"!]
                        [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                            [!IF "num:i($AeCorePartitionIdCount) = num:i(node:pos(.))"!]
                                [!VAR "CorePartitionIsMatch" = "'true'"!]
                                [!VAR "Partitionname" = "$MacPartNo"!]
                            [!ENDIF!]
                        [!ENDSELECT!]
                        [!ENDIF!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDLOOP!]
        [!ENDLOOP!][!//
        [!IF "$CorePartitionIsMatch = 'true'"!]
[!CODE!]
    &Ae_Config_[!"$Partitionname"!][!IF "$MacNoPartitions < num:i($MaxCorePartitionId)"!],[!VAR "MacNoPartitions" = "$MacNoPartitions + 1"!][!ENDIF!]
[!ENDCODE!]
        [!ELSE!]
[!CODE!]
    NULL_PTR[!IF "$MacNoPartitions < num:i($MaxCorePartitionId)"!],[!VAR "MacNoPartitions" = "$MacNoPartitions + 1"!][!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]
};
[!ELSE!]
const Ae_ConfigType * const Ae_xPredefinedConfig[AE_MAX_PARTITIONS]=
{
    &Ae_Config
};
[!ENDIF!]
[!ENDIF!]
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"

[!CALL "Ae_ConfigurationInfo"!]

#define AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
