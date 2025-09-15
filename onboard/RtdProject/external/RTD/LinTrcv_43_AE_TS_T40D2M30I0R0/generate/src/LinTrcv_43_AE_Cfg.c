/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
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
*   @file    LinTrcv_43_AE_Cfg.c
*
*   @defgroup lintrcv_driver LINTRCV Driver
*   @addtogroup  lintrcv_driver LINTRCV Driver
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

#include "Std_Types.h"
#include "LinTrcv_43_AE_Cfg.h"
#include "LinTrcv_43_AE_Ipw_Cfg.h"
#include "LinTrcv_43_AE_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINTRCV_43_AE_CFG_VENDOR_ID_C                     43
#define LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION_C      7
#define LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define LINTRCV_43_AE_CFG_SW_MAJOR_VERSION_C              3
#define LINTRCV_43_AE_CFG_SW_MINOR_VERSION_C              0
#define LINTRCV_43_AE_CFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against LinTrcv_43_AE_Cfg.h */
#if (LINTRCV_43_AE_CFG_VENDOR_ID_C != LINTRCV_43_AE_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_CFG_SW_MAJOR_VERSION_C != LINTRCV_43_AE_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_MINOR_VERSION_C != LINTRCV_43_AE_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_PATCH_VERSION_C != LINTRCV_43_AE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Cfg.h are different"
#endif

/* Checks against LinTrcv_43_AE_Types.h */
#if (LINTRCV_43_AE_CFG_VENDOR_ID_C != LINTRCV_43_AE_TYPES_VENDOR_ID)
    #error "LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Types.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Types.h are different"
#endif
#if ((LINTRCV_43_AE_CFG_SW_MAJOR_VERSION_C != LINTRCV_43_AE_TYPES_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_MINOR_VERSION_C != LINTRCV_43_AE_TYPES_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_PATCH_VERSION_C != LINTRCV_43_AE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Types.h are different"
#endif


/* Checks against LinTrcv_43_AE_Ipw_Cfg.h */
#if (LINTRCV_43_AE_CFG_VENDOR_ID_C != LINTRCV_43_AE_IPW_CFG_VENDOR_ID)
    #error "LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h have different vendor ids"
#endif
#if ((LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION_C    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION_C    != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION_C != LINTRCV_43_AE_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif
#if ((LINTRCV_43_AE_CFG_SW_MAJOR_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_MAJOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_MINOR_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_MINOR_VERSION) || \
     (LINTRCV_43_AE_CFG_SW_PATCH_VERSION_C != LINTRCV_43_AE_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LinTrcv_43_AE_Cfg.c and LinTrcv_43_AE_Ipw_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION_C  != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of LinTrcv_43_AE_Cfg.c and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
LINTRCV_43_AE_IPW_CONFIG_EXT

#define LINTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/**
* @brief        All PartitionIDs are supported by LINTRCV driver.
*/
[!NOCODE!]
[!LOOP "./LinTrcvGeneral/LinTrcvEcucPartitionRef/*"!][!//
    [!VAR "PartitionRef"="node:value(.)"!][!//
    [!VAR "PartitionName"="count(text:split($PartitionRef,'/'))"!]
    [!VAR "PartitionName"="text:split($PartitionRef,'/')[num:i($PartitionName)]"!]
    [!VAR "PartitionName"="text:toupper($PartitionName)"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
        [!IF "$PartitionRef = node:value(./OsAppEcucPartitionRef)"!][!//
            [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                [!CODE!]
#define LINTRCV_43_AE_[!"$PartitionName"!]_ID     ((uint32)[!"node:pos(.)"!]U)
                [!ENDCODE!]
            [!ENDSELECT!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!]
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define LINTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

[!NOCODE!]
[!LOOP "LinTrcvChannel/*"!][!//
    [!IF "node:exists(./LinTrcvChannelEcucPartitionRef)"!]
        [!VAR "PartitionName"="count(text:split(./LinTrcvChannelEcucPartitionRef,'/'))"!]
        [!VAR "PartitionName"="text:split(./LinTrcvChannelEcucPartitionRef,'/')[num:i($PartitionName)]"!]
    [!ELSE!]
        [!VAR "PartitionName"="'UnAllocatedPar'"!]
    [!ENDIF!]

[!CODE!]
/**
* @brief          Configuration for LinTrcv Channel [!"LinTrcvChannelId"!]
*
*
*
*/
static const LinTrcv_43_AE_ChannelConfigType LinTrcv_43_AE_[!"$PartitionName"!] =
{
    (uint8)[!"LinTrcvChannelId"!]U, /* LinTrcv Channel ID */
    &LinTrcv_43_AE_Ipw_pxHwConfigPB_[!"LinTrcvChannelId"!], /* Pointer to the hardware configuration*/

    LINTRCV_43_AE_[!"text:toupper($PartitionName)"!]_ID,         /* Partition core id of channel */

[!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!][!//
    (boolean)[!IF "$PartitionName = 'UnAllocatedPar'"!]FALSE[!ELSE!]TRUE[!ENDIF!],
[!ELSE!][!//
    (boolean)TRUE,
[!ENDIF!]
    (boolean)[!IF "LinTrcvChannelUsed"!]TRUE[!ELSE!]FALSE[!ENDIF!]  /* Shall the related LIN transceiver channel be used. */
#if (LINTRCV_43_AE_WAKEUP_DETECTION == STD_ON)
    ,(boolean)[!IF "LinTrcvWakeupByBusUsed"!]TRUE[!ELSE!]FALSE[!ENDIF!] /* Is wake up by bus supported. */
    [!IF "(node:exists(LinTrcvWakeupSourceRef) = 'true') and (node:value(LinTrcvWakeupSourceRef) != '')"!]
    ,(EcuM_WakeupSourceType)([!"bit:shl(1,as:ref(LinTrcvWakeupSourceRef)/EcuMWakeupSourceId)"!]U) /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
    [!ELSE!]
    ,(EcuM_WakeupSourceType)LINTRCV_43_AE_NONE_ECUM_WAKEUP_SOURCE_REF /* None Wakeup Source was referred */
    [!ENDIF!]
#endif
#if (LINTRCV_43_AE_ICU_USED == STD_ON)
    [!IF "(node:exists(LinTrcvIcuChannelRef) = 'true') and (node:value(LinTrcvIcuChannelRef) != '')"!]
    ,(uint16)[!"as:ref(LinTrcvIcuChannelRef)/IcuChannelId"!]U                           /**!< @brief Reference to the IcuChannel to enable/disable the interrupts for wakeups.*/
    [!ELSE!]
    ,(uint16)0U /* None IcuChannel Source was referred */
    [!ENDIF!]
#endif
};
[!ENDCODE!]
[!ENDLOOP!][!//
[!ENDNOCODE!]

[!NOCODE!][!//
[!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!]
    [!VAR "LinTrcvNumOfPars"="count(LinTrcvGeneral/LinTrcvEcucPartitionRef/*)"!]
[!ELSE!]
    [!VAR "LinTrcvNumOfPars"="1"!]
[!ENDIF!]
[!FOR "LinTrcvCountPars"="0" TO "$LinTrcvNumOfPars - 1"!]
    [!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!]
        [!VAR "PartitionRef"="LinTrcvGeneral/LinTrcvEcucPartitionRef/*[number($LinTrcvCountPars + 1)]"!]
        [!VAR "PartitionName"="count(text:split($PartitionRef,'/'))"!]
        [!VAR "PartitionName"="text:split($PartitionRef,'/')[num:i($PartitionName)]"!]
        [!VAR "PartitionNameUnderScore"="concat('_',$PartitionName)"!]
        [!VAR "NumOfChannelInPar"="count(LinTrcvChannel/*[contains(./LinTrcvChannelEcucPartitionRef,$PartitionRef)])"!]
    [!ELSE!]
        [!VAR "PartitionName"="'UnAllocatedPar'"!]
        [!VAR "PartitionNameUnderScore"="string(null)"!]
        [!VAR "NumOfChannelInPar"="1"!]
    [!ENDIF!]
    [!IF "$NumOfChannelInPar > 0"!]
[!CODE!]
/**
* @brief          LinTrcv Configuration data for [!"$PartitionNameUnderScore"!].
*
*/
static const LinTrcv_43_AE_ConfigType LinTrcv_43_AE_Config[!"$PartitionNameUnderScore"!] =
{
    LINTRCV_43_AE_[!"text:toupper($PartitionName)"!]_ID,            /** Partition Id */

    {[!//
[!ENDCODE!][!//
    [!VAR "Count"="0"!]
    [!VAR "MaxChannelNr" = "num:i(count(LinTrcvChannel/*))"!]
    [!FOR "Count" = "0" TO "$MaxChannelNr - 1"!]
        [!LOOP "LinTrcvChannel/*"!]
            [!IF "$Count = num:i(LinTrcvChannelId)"!]
                 [!IF "node:exists(./LinTrcvChannelEcucPartitionRef)"!]
                    [!VAR "ChPartitionName"="count(text:split(./LinTrcvChannelEcucPartitionRef,'/'))"!]
                    [!VAR "ChPartitionName"="text:split(./LinTrcvChannelEcucPartitionRef,'/')[num:i($ChPartitionName)]"!]
                [!ELSE!]
                    [!VAR "ChPartitionName"="'UnAllocatedPar'"!]
                [!ENDIF!]
[!CODE!]
        /**
        * @brief   Configuration for LinTrcv Channel [!"LinTrcvChannelId"!].
        */
        &LinTrcv_43_AE_[!"$ChPartitionName"!][!IF "num:i($Count + 1) < $MaxChannelNr"!],[!ENDIF!][!//
[!ENDCODE!][!//
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
[!CODE!]
    }
};[!ENDCODE!]
[!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!]

[!NOCODE!]
[!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!]
[!VAR "MaxPartitionId"="count(as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*) - 1"!]
[!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
[!CODE!][!//
/**
* @brief          LinTrcv Configuration data for LinTrcv_43_AE_apxPBCfgVariantPredefined[LINTRCV_43_AE_MAX_PARTITIONS].
*
*/
const LinTrcv_43_AE_ConfigType * const LinTrcv_43_AE_apxPBCfgVariantPredefined[LINTRCV_43_AE_MAX_PARTITIONS] =
{
[!ENDCODE!][!//
[!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!]
    [!VAR "LinTrcvNumOfPars"="count(LinTrcvGeneral/LinTrcvEcucPartitionRef/*)"!]
    [!VAR "FirstPartition"="1"!]
    [!FOR "LinTrcvCountPartitionId"="0" TO "$MaxPartitionId"!]
        [!VAR "TempPartitionIdUpdated"="'false'"!]
        [!LOOP "./LinTrcvGeneral/LinTrcvEcucPartitionRef/*"!][!//
            [!VAR "PartitionRef"="node:value(.)"!]
            [!VAR "PartitionName"="count(text:split($PartitionRef,'/'))"!]
            [!VAR "PartitionName"="text:split($PartitionRef,'/')[num:i($PartitionName)]"!]
            [!VAR "NumOfChannelInPar"="count(../../../LinTrcvChannel/*[contains(./LinTrcvChannelEcucPartitionRef,$PartitionRef)])"!]
            [!IF "$NumOfChannelInPar > 0"!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "$PartitionRef = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsAppEcucPartitionRef)"!][!//
                            [!IF "($LinTrcvCountPartitionId = node:pos(.))"!]
                                [!VAR "TempPartitionIdUpdated"="'true'"!]
                                [!VAR "PartitionNameUpdated"="$PartitionName"!]
                            [!ENDIF!]
                        [!ENDSELECT!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!CODE!]
    [!IF "$FirstPartition = 0"!],[!ENDIF!][!VAR "FirstPartition"="0"!]
        [!ENDCODE!]
        [!IF "$TempPartitionIdUpdated = 'true'"!]
            [!CODE!]
    &LinTrcv_43_AE_Config_[!"$PartitionNameUpdated"!]
            [!ENDCODE!]
        [!ELSE!]
            [!CODE!]
    NULL_PTR
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ELSE!][!//LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'false'
    [!CODE!]
    &LinTrcv_43_AE_Config
    [!ENDCODE!]
[!ENDIF!][!//LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'
[!CODE!][!//
};
[!ENDCODE!]
[!ENDNOCODE!]
#define LINTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinTrcv_43_AE_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

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
