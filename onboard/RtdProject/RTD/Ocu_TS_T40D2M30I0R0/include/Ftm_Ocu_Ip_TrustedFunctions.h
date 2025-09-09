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

#ifndef FTM_OCU_IP_TRUSTEDFUNCTIONS_H
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file         Ftm_Ocu_Ip_TrustedFunctions.h
*
*   @addtogroup   ocu_ip Ocu IPL
*   @brief        Ocu FTM driver header file.
*   @details      FTM driver interface.
*
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
#include "Ftm_Ocu_Ip_CfgDefines.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                3
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_OCU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FTM_OCU_IP_CFGDEFINES_VENDOR_ID)
    #error "Ftm_Ocu_Ip_TrustedFunctions.h and Ftm_Ocu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if header file and Ftm_Ocu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FTM_OCU_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip_TrustedFunctions.h and Ftm_Ocu_Ip_CfgDefines.h are different"
#endif

/* Check if header file and Ftm_Ocu_Ip_CfgDefines.h file are of the same Software version */
#if ((FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FTM_OCU_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FTM_OCU_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FTM_OCU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != FTM_OCU_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip_TrustedFunctions.h and Ftm_Ocu_Ip_CfgDefines.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if ((STD_ON == MCAL_FTM_REG_PROT_AVAILABLE) && (STD_ON == FTM_OCU_IP_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief        Enables FTM registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the FTM IP allowing FTM registers writing in User Mode
 *
 * @param[in]    FtmBaseAddr
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 */
extern void Ftm_Ocu_Ip_SetUserAccessAllowed(uint32 FtmBaseAddr);
#endif

#if ((STD_ON == OCU_SIM_AVAILABLE) && (STD_ON == FTM_OCU_IP_ENABLE_USER_MODE_SUPPORT))
/*!
 * @brief   Set OBE CTRL bit in SIM module to set all channel pin of respective instance is output mode
 *
 * @param[in] The FTM peripheral Instance number
 *
 *
 */
extern void Ftm_Ocu_Ip_SetOutputPinCtrlBit(uint8 InstNum);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_OCU_IP_TRUSTEDFUNCTIONS_H */
