[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
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
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Inc.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Family'))=142)"!][!//
    [!INCLUDE "Port_S32K142_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=144)"!][!//
    [!INCLUDE "Port_S32K144_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=146)"!][!//
    [!INCLUDE "Port_S32K146_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=148)"!][!//
    [!INCLUDE "Port_S32K148_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=118)"!][!//
    [!INCLUDE "Port_S32K118_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=116)"!][!//
    [!INCLUDE "Port_S32K116_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('142w'))"!][!//
    [!INCLUDE "Port_S32K142w_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('144w'))"!][!//
    [!INCLUDE "Port_S32K144w_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('m241'))"!][!//
    [!INCLUDE "Port_S32M241_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('m242'))"!][!//
    [!INCLUDE "Port_S32M242_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('m243'))"!][!//
    [!INCLUDE "Port_S32M243_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('m244'))"!][!//
    [!INCLUDE "Port_S32M244_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                3
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                0

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Cfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if the files Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if the files Port_Cfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
const uint16 Port_au16PinDescription[[!"ecu:list('Port.PadModeNumber')[1]"!]][[!"ecu:list('Port.Pin16BlocksNo')[1]"!]] =
{
    [!IF "((ecu:get('Port.Package'))='Port_32QFN')"!][!//
        [!"$CHECK_1"!]
    [!ELSEIF "((ecu:get('Port.Package'))='Port_48LQFP')"!][!//
        [!"$CHECK_2"!]
    [!ELSEIF "((ecu:get('Port.Package'))='Port_64LQFP') and not(contains((ecu:get('Port.Family')), 'm24'))"!][!//
        [!"$CHECK_3"!]
    [!ELSEIF "((ecu:get('Port.Package'))='Port_100LQFP') or ((ecu:get('Port.Package'))='Port_100MAPBGA') or contains((ecu:get('Port.Family')), 'm24')"!][!//
        [!"$CHECK_4"!]
    [!ELSEIF "((ecu:get('Port.Package'))='Port_144LQFP')"!][!//
        [!"$CHECK_5"!]
    [!ELSEIF "((ecu:get('Port.Package'))='Port_176LQFP')"!][!//
        [!"$CHECK_6"!]
    [!ENDIF!][!//
};
#endif

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
[!ENDCODE!][!//
