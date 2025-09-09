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

#ifndef LINTRCV_43_AE_CFG_H
#define LINTRCV_43_AE_CFG_H

/**
*   @file
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
#include "Mcal.h"

[!NOCODE!][!//
[!INCLUDE "LinTrcv_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINTRCV_43_AE_CFG_VENDOR_ID                    43
#define LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION     4
#define LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION     7
#define LINTRCV_43_AE_CFG_AR_RELEASE_REVISION_VERSION  0
#define LINTRCV_43_AE_CFG_SW_MAJOR_VERSION             3
#define LINTRCV_43_AE_CFG_SW_MINOR_VERSION             0
#define LINTRCV_43_AE_CFG_SW_PATCH_VERSION             0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((LINTRCV_43_AE_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LINTRCV_43_AE_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of LinTrcv_43_AE_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   No of Channels configured.
*
*
*/
#define LINTRCV_43_AE_HW_MAX_MODULES ([!"num:i(count(LinTrcvChannel/*))"!]U)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*
*/
#define LINTRCV_43_AE_DEV_ERROR_DETECT [!IF "LinTrcvGeneral/LinTrcvDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF)   /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the LinTrcv_43_AE_GetVersionInfo() API ON or OFF.
*
*
*/
#define LINTRCV_43_AE_VERSION_INFO_API [!IF "LinTrcvGeneral/LinTrcvVersionInfoApi"!](STD_ON)  /* Enable API LinTrcv_43_AE_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API LinTrcv_43_AE_GetVersionInfo     */[!ENDIF!]

/**
* @brief        All PartitionIDs are supported by LINTRCV driver.
*/
[!NOCODE!]
[!VAR "MaxPartitionId"="0"!]
[!IF "node:value(LinTrcvGeneral/LinTrcvMultiPartitionSupport)='true'"!]
    [!VAR "MaxPartitionId"="count(as:modconf('EcuC')[1]/EcucPartitionCollection/*[1]/EcucPartition/*) - 1"!]
[!ENDIF!]
[!ENDNOCODE!]
#define LINTRCV_43_AE_MAX_PARTITIONS     ((uint32)[!"num:i($MaxPartitionId+1)"!]U)

/**
* @brief          Multipartiton is enabled or not
*/
#define LINTRCV_43_AE_MULTIPARTITION_SUPPORT   [!IF "node:fallback(as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport, 'false') = 'false'"!](STD_OFF) /* Multipartiton is disabled */[!ELSE!](STD_ON) /* Multipartiton is enabled */[!ENDIF!]

/**
*
* @internal
* @brief          LinTrcv Wakeup detection feature
* @details        It is set to STD_ON when LinTrcvGeneral/LinTrcvWakeUpSupport is enabled.
*
*
*/
#define LINTRCV_43_AE_WAKEUP_DETECTION [!IF "LinTrcvGeneral/LinTrcvWakeUpSupport"!](STD_ON)  /* Enable wakeup detection */[!ELSE!](STD_OFF)   /* Disable wakeup detection */[!ENDIF!]

[!NOCODE!]
[!VAR "HasIcu" = "'STD_OFF'"!]
[!LOOP "LinTrcvChannel/*"!][!//
    [!IF "node:exists(LinTrcvIcuChannelRef)"!]
        [!VAR "HasIcu" = "'STD_ON'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
/**
*
* @internal
* @brief          LinTrcv Icu Used
* @details        When LinTrcvChannel/LinTrcvIcuChannelRef is used or not.
*
*
*/
#define LINTRCV_43_AE_ICU_USED ([!"$HasIcu"!]) /* [!IF "$HasIcu = 'STD_ON'"!]Icu Used[!ELSE!]No Used Icu[!ENDIF!] */

#define LINTRCV_43_AE_UNALLOCATEDPAR_ID  [!IF "as:modconf('LinTrcv')[1]/LinTrcvGeneral/LinTrcvMultiPartitionSupport = 'true'"!]((uint32)0xFFU)[!ELSE!]((uint32)0x00U)[!ENDIF!]

#if (STD_ON == LINTRCV_43_AE_MULTIPARTITION_SUPPORT)
    #define LinTrcv_43_AE_GetUserID() (OsIf_GetUserId())
#else
    #define LinTrcv_43_AE_GetUserID() (LINTRCV_43_AE_UNALLOCATEDPAR_ID)
#endif /* (STD_ON == LINTRCV_43_AE_MULTIPARTITION_SUPPORT) */

/**
* @brief          LINTRCV driver status initialization variable.
*/
#define LINTRCV_43_AE_UNINIT_ARRAY  {[!FOR "idx" = "0" TO "$MaxPartitionId"!]LINTRCV_43_AE_NOT_ACTIVE[!IF "$idx < $MaxPartitionId"!], [!ENDIF!][!ENDFOR!]}
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

/*==================================================================================================
*                                     EXTERNAL CONSTANTS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINTRCV_43_AE_CFG_H */
