[!CODE!][!//
/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K14X
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530
*
* Copyright 2020-2025 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file    modules.h
*   @version 3.0.0
*
*   @brief   AUTOSAR BaseNXP - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/
/**
* @file        modules.h
*/

#ifndef MODULES_H
#define MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        modules.h
* @brief Include Standard types & defines
*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define MODULES_VENDOR_ID                       43
#define MODULES_MODULE_ID                       0
#define MODULES_AR_RELEASE_MAJOR_VERSION_H      4
#define MODULES_AR_RELEASE_MINOR_VERSION_H      7
#define MODULES_AR_RELEASE_REVISION_VERSION_H   0
#define MODULES_SW_MAJOR_VERSION_H              3
#define MODULES_SW_MINOR_VERSION_H              0
#define MODULES_SW_PATCH_VERSION_H              0
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((MODULES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MODULES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of modules.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This constant used for other modules to check if ADC is present in the project.   
*/
#define USE_ADC_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Adc")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Ae is present in the project.   
*/
#define USE_AE_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Ae")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CAN is present in the project.   
*/
#define USE_CAN_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Can")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CAN_43_FLEXCAN is present in the project.   
*/
#define USE_CAN_43_FLEXCAN_MODULE   ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'FLEXCAN')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if CAN_43_CANEXCEL is present in the project.   
*/
#define USE_CAN_43_CANEXCEL_MODULE  ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'CANEXCEL')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CAN_43_LLCE is present in the project.   
*/
#define USE_CAN_43_LLCE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Can")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CANTRCV_43_AE is present in the project.   
*/
#define USE_CANTRCV_43_AE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("CanTrcv")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'AE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRC is present in the project.   
*/
#define USE_CRC_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Crc")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO is present in the project.   
*/
#define USE_CRYPTO_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_HSE is present in the project.   
*/
#define USE_CRYPTO_43_HSE_MODULE    ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'HSE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CRYPTO_43_ACE is present in the project.   
*/
#define USE_CRYPTO_43_ACE_MODULE    ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Crypto")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'ACE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if CSEC is present in the project.   
*/
#define USE_CSEC_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Csec")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if DIO is present in the project.   
*/
#define USE_DIO_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Dio")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if DPGA is present in the project.   
*/
#define USE_DPGA_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Dpga")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if EEP is present in the project. 
*/
#define USE_EEP_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Eep")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH is present in the project. 
*/
#define USE_ETH_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_ENET is present in the project. 
*/
#define USE_ETH_43_ENET_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'ENET')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_GMAC is present in the project. 
*/
#define USE_ETH_43_GMAC_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'GMAC')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETH_43_NETC is present in the project. 
*/
#define USE_ETH_43_NETC_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Eth")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'NETC')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ETHSWT_43_NETC is present in the project. 
*/
#define USE_ETHSWT_43_NETC_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("EthSwt")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'NETC')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if FEE is present in the project.   
*/
#define USE_FEE_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Fee")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if FLS is present in the project.   
*/
#define USE_FLS_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Fls")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Fr is present in the project.   
*/
#define USE_FR_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Fr")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Fr_43_LLCE is present in the project.   
*/
#define USE_FR_43_LLCE_MODULE       ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Fr")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if GDU is present in the project.   
*/
#define USE_GDU_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Gdu")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if GPT is present in the project.   
*/
#define USE_GPT_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Gpt")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if I2C is present in the project.   
*/
#define USE_I2C_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("I2c")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if I2S is present in the project.   
*/
#define USE_I2S_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("I2s")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if ICU is present in the project.   
*/
#define USE_ICU_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Icu")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if LIN is present in the project.   
*/
#define USE_LIN_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if Lin_43_LPUART_FLEXIO is present in the project.   
*/
#define USE_LIN_43_LPUART_FLEXIO_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LPUART')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if Lin_43_LINFLEXD is present in the project.   
*/
#define USE_LIN_43_LINFLEXD_MODULE           ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LINFLEXD')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Lin_43_LLCE is present in the project.   
*/
#define USE_LIN_43_LLCE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Lin")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'LLCE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if LinTrcv_43_AE is present in the project.   
*/
#define USE_LINTRCV_43_AE_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("LinTrcv")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'AE')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MESSAGING is present in the project. 
*/
#define USE_MESSAGING_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Messaging")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCEM_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Mcem")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCEM is present in the project.   
*/
#define USE_MCL_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Mcl")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MCU is present in the project.   
*/
#define USE_MCU_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Mcu")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if MemAcc is present in the project.   
*/
#define USE_MEMACC_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("MemAcc")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Mem_Eep is present in the project.   
*/
#define USE_MEM_43_EEP_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mem")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'EEP')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Mem_ExFls is present in the project.   
*/
#define USE_MEM_43_EXFLS_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mem")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'EXFLS')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if Mem_InFls is present in the project.   
*/
#define USE_MEM_43_INFLS_MODULE      ([!VAR "MDL_DEF" = "0"!][!LOOP "as:modconf("Mem")"!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and (CommonPublishedInformation/VendorApiInfix = 'INFLS')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])  

/** 
* @brief This constant used for other modules to check if OCU is present in the project. 
*/
#define USE_OCU_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Ocu")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if OCOTP is present in the project. 
*/
#define USE_OCOTP_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Ocotp")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if PCIE is present in the project.   
*/
#define USE_PCIE_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Pcie")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if PORT is present in the project.   
*/
#define USE_PORT_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Port")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if PSI5 is present in the project.   
*/
#define USE_PSI5_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Psi5")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if PWM is present in the project.   
*/
#define USE_PWM_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Pwm")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if QDEC is present in the project.   
*/
#define USE_QDEC_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Qdec")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/**
* @brief This constant used for other modules to check if Rem_Cm is present in the project.   
*/
#define USE_REM_CM_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Rem_cm")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if RM is present in the project.   
*/
#define USE_RM_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Rm")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if SENT is present in the project.   
*/
#define USE_SENT_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Sent")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if SERDES is present in the project.   
*/
#define USE_SERDES_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Serdes")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if SPI is present in the project.   
*/
#define USE_SPI_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Spi")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if THERMAL is present in the project.   
*/
#define USE_THERMAL_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Thermal")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/** 
* @brief This constant used for other modules to check if UART is present in the project.   
*/
#define USE_UART_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Uart")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

[!VAR "isAnyWdgInstanceUsed" = "0"!][!//
/** 
* @brief This constant used for other modules to check if WDG is present in the project.   
*/
#define USE_WDG_MODULE    ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = 'Instance0')"!][!VAR "MDL_DEF" = "1"!][!VAR "isAnyWdgInstanceUsed" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!//

[!FOR "i" = "1" TO "26"!]
 /**
 * @brief This constant used for other modules to check if WDG Instance [!"$i"!] is present in the project.
 */
#define USE_WDG_INSTANCE[!"$i"!]     ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = concat('Instance',string($i)))"!][!VAR "MDL_DEF" = "1"!][!VAR "isAnyWdgInstanceUsed" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDFOR!][!//

/**
 * @brief This constant used for other modules to check if any WDG Instance is present in the project.
 */
#define USE_WDG_INSTANCE_ANY     ([!IF "$isAnyWdgInstanceUsed = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if WDG for chip vr5510 is present in the project.   
*/
#define USE_WDG_43_VR5510_MODULE      ([!VAR "MDL_DEF" = "0"!][!//
[!LOOP "as:modconf("Wdg")"!][!//
[!IF "(CommonPublishedInformation/VendorId = num:i(43))"!][!//
[!IF "(CommonPublishedInformation/VendorApiInfix = 'VR5510')"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief This constant used for other modules to check if ZIPWIRE is present in the project.   
*/
#define USE_ZIPWIRE_MODULE              ([!VAR "MDL_DEF" = "0"!][!VAR "MDL_DEF2" = "0"!][!LOOP "as:modconf("Zipwire")"!][!IF "node:exists(CommonPublishedInformation/VendorApiInfix)"!][!IF "(CommonPublishedInformation/VendorApiInfix = '')"!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!ELSE!][!VAR "MDL_DEF2" = "1"!][!ENDIF!][!IF "(CommonPublishedInformation/VendorId = num:i(43)) and ($MDL_DEF2 = 1)"!][!VAR "MDL_DEF" = "1"!][!ENDIF!][!ENDLOOP!][!IF "$MDL_DEF = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */

[!ENDCODE!][!//

