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


#ifndef CRC_CFG_H
#define CRC_CFG_H

/**
*   @file       Crc_Cfg.h
*   @implements Crc_Cfg.h_Artifact
*   @version    3.0.0
*
*   @brief      AUTOSAR Crc Configuration file for the driver.
*   @details    Precompile parameters and extern configuration.
*
*   @addtogroup CRC_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crc_Types.h"
#include "Crc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC_CFG_VENDOR_ID                      43
#define CRC_CFG_AR_RELEASE_MAJOR_VERSION       4
#define CRC_CFG_AR_RELEASE_MINOR_VERSION       7
#define CRC_CFG_AR_RELEASE_REVISION_VERSION    0
#define CRC_CFG_SW_MAJOR_VERSION               3
#define CRC_CFG_SW_MINOR_VERSION               0
#define CRC_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Crc_Types.h file are of the same vendor */
#if (CRC_CFG_VENDOR_ID != CRC_TYPES_VENDOR_ID)
    #error "Crc_Cfg.h and Crc_Types.h have different vendor ids"
#endif

/* Check if header file and Crc_Types.h file are of the same Autosar version */
#if ((CRC_CFG_AR_RELEASE_MAJOR_VERSION != CRC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_MINOR_VERSION != CRC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_REVISION_VERSION != CRC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Cfg.h and Crc_Types.h are different"
#endif

/* Check if header file and Crc_Types.h file are of the same Software version */
#if ((CRC_CFG_SW_MAJOR_VERSION != CRC_TYPES_SW_MAJOR_VERSION) || \
     (CRC_CFG_SW_MINOR_VERSION != CRC_TYPES_SW_MINOR_VERSION) || \
     (CRC_CFG_SW_PATCH_VERSION != CRC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Crc_Cfg.h and Crc_Types.h are different"
#endif

/* Check if header file and Crc_Ip_Cfg.h file are of the same vendor */
#if (CRC_CFG_VENDOR_ID != CRC_IP_CFG_VENDOR_ID)
    #error "Crc_Cfg.h and Crc_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Crc_Ip_Cfg.h file are of the same Autosar version */
#if ((CRC_CFG_AR_RELEASE_MAJOR_VERSION != CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_MINOR_VERSION != CRC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Cfg.h and Crc_Ip_Cfg.h are different"
#endif

/* Check if header file and Crc_Ip_Cfg.h file are of the same Software version */
#if ((CRC_CFG_SW_MAJOR_VERSION != CRC_IP_CFG_SW_MAJOR_VERSION) || \
     (CRC_CFG_SW_MINOR_VERSION != CRC_IP_CFG_SW_MINOR_VERSION) || \
     (CRC_CFG_SW_PATCH_VERSION != CRC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Crc_Cfg.h and Crc_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!VAR "AutosarCrcLibraryIsAvailable" = "'false'"!]
[!/* Check Any Channel Enable Autosar Library */!]
[!IF "(./CrcGeneral/Crc8Mode) or (./CrcGeneral/Crc8H2FMode) or (./CrcGeneral/Crc16Mode) or (./CrcGeneral/Crc16ARCMode) or (./CrcGeneral/Crc32Mode) or (./CrcGeneral/Crc32P4Mode) or (./CrcGeneral/Crc64Mode)"!]
    [!VAR "AutosarCrcLibraryIsAvailable" = "'true'"!]
[!ENDIF!]

[!VAR "NonAutosarCrcLibraryIsAvailable" = "'false'"!]
[!/* Check Any Channel Enable Non-Autosar Library */!]
[!IF "node:exists(./CrcGeneral/Crc32CMode)"!]
    [!VAR "NonAutosarCrcLibraryIsAvailable" = "'true'"!]
[!ENDIF!]
[!ENDNOCODE!][!//
#define CRC_AUTOSAR_LIBRARY_IS_AVAILABLE         [!IF "$AutosarCrcLibraryIsAvailable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define CRC_NONAUTOSAR_LIBRARY_IS_AVAILABLE      [!IF "$NonAutosarCrcLibraryIsAvailable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define CRC_NUM_CHANNEL_MAX                      (CRC_IP_NUM_LOGIC_CHANNEL_MAX)

/*! @brief  DMA Supported. */
#define CRC_DMA_IS_AVAILABLE              [!IF "CrcGeneral/CrcDmaSupportEnable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Enables or disables PRE-COMPILE SUPPORT. */
#define CRC_PRECOMPILE_SUPPORT               [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Error detect. */
#define CRC_DET_IS_AVAILABLE                 [!IF "CrcGeneral/CrcDetectError"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Enables or disables User Mode use Register Protect. */
#define CRC_ENABLE_USER_MODE_SUPPORT         [!IF "CrcGeneral/CrcEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CRC_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running CRC in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == CRC_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*! @brief  Enables or disables MultiPartition feature. */
#define CRC_MULTIPARTITION_SUPPORT_ENABLED        [!IF "(./CrcGeneral/CrcMultiPartitionEnable = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Enables or disables get Version Info. */
#define CRC_VERSION_INFO_API_ENABLE          [!IF "CrcGeneral/CrcVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*! @brief  Number of configured partitions. */
#define CRC_CORE_NOF_PARTITION               ([!IF "(./CrcGeneral/CrcMultiPartitionEnable = 'true')"!][!"num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!ELSE!]1[!ENDIF!]U)

/*! @brief  Core Default. */
#define CRC_CORE_DEFAULT                     (0U)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.h"

/* Crc Autosar Channel */
extern const uint32 Crc_au32Crc8BitSaeJ1850[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc8BitH2f[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc16BitCcittFalse[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc16BitArc[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc32BitEthernet[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc32BitE2ep4[CRC_CORE_NOF_PARTITION];
extern const uint32 Crc_au32Crc64BitEcma[CRC_CORE_NOF_PARTITION];

/* Crc Non-Autosar Channel */
extern const uint32 Crc_au32Crc32BitCastagnoli[CRC_CORE_NOF_PARTITION];

#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.h"


#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/* Crc Partition Configuration */
[!IF "(./CrcGeneral/CrcMultiPartitionEnable = 'true')"!][!//
extern const Crc_PartitionType * const Crc_pxPartitionConfig[CRC_CORE_NOF_PARTITION];
[!ELSE!][!//
extern const Crc_PartitionType Crc_xConfigPartition;
[!ENDIF!][!//

/* Configure CRC driver initialization */
extern const Crc_InitType Crc_xConfigInit;

#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_CFG_H */
