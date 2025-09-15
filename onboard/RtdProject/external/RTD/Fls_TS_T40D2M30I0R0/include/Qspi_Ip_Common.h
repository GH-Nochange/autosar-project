/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_4_REV_0000_20250530
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

#ifndef QSPI_IP_COMMON_H
#define QSPI_IP_COMMON_H

/**
 *   @file       Qspi_Ip_Common.h
 *
 *   @addtogroup IPV_QSPI QSPI IPV Driver
 *   @implements Qspi_Ip_Common.h_Artifact
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
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_COMMON_VENDOR_ID_H                       43
#define QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H        4
#define QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_COMMON_SW_MAJOR_VERSION_H                3
#define QSPI_IP_COMMON_SW_MINOR_VERSION_H                0
#define QSPI_IP_COMMON_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same vendor */
#if (QSPI_IP_COMMON_VENDOR_ID_H != QSPI_IP_VENDOR_ID_CFG)
    #error "Qspi_Ip_Common.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Autosar version */
#if ((QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Common.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Software version */
#if ((QSPI_IP_COMMON_SW_MAJOR_VERSION_H != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (QSPI_IP_COMMON_SW_MINOR_VERSION_H != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (QSPI_IP_COMMON_SW_PATCH_VERSION_H != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip_Common.h and Qspi_Ip_Cfg.h are different"
#endif

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/


/*******************************************************************************
* Definitions
******************************************************************************/

/*!
 * @brief Driver configuration structure
 *
 * This structure is used to provide configuration parameters for the external flash driver
 * at initialization time.
 */
typedef struct
{
    const Qspi_Ip_MemoryConfigType *configuration;      /*!< Serial flash device configuration                */
    const Qspi_Ip_MemoryConnectionType *connection;     /*!< Connection to a QSPI device                      */
    uint32 baseAddress;                                 /*!< Base address of serial flash device              */
    Qspi_Ip_LastCommandType lastCommand;                /*!< Last command sent to the flash device            */
    uint16 activeReadLut;                               /*!< LUT number for currently active read mode        */
    boolean isInXIPMode;                                /*!< Status of XIP mode (TRUE = Enabled/ FALSE = Disabled)       */
} Qspi_Ip_StateType;


/*******************************************************************************
 * External variable declarations.
 ******************************************************************************/

 /* Physical LUT seq to use for all flash commands */
#define QSPI_IP_COMMAND_LUT 0U
 /* Physical LUT seq to use for AHB reads */
#define QSPI_IP_AHB_LUT 1U


/*******************************************************************************
 * API
 ******************************************************************************/

#endif /* QSPI_IP_MEM_INSTANCE_COUNT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_COMMON_H */
