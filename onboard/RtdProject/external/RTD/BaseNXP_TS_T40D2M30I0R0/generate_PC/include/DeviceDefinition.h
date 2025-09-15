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
*   @file    DeviceDefinition.h
*   @version 3.0.0
*
*   @brief   AUTOSAR BaseNXP - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/
/**
* @file        DeviceDefinition.h
*/

#ifndef DEVICEDEFINITION_H
#define DEVICEDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define DEVICEDEFINITION_VENDOR_ID                       43
#define DEVICEDEFINITION_MODULE_ID                       0
#define DEVICEDEFINITION_AR_RELEASE_MAJOR_VERSION_H      4
#define DEVICEDEFINITION_AR_RELEASE_MINOR_VERSION_H      7
#define DEVICEDEFINITION_AR_RELEASE_REVISION_VERSION_H   0
#define DEVICEDEFINITION_SW_MAJOR_VERSION_H              3
#define DEVICEDEFINITION_SW_MINOR_VERSION_H              0
#define DEVICEDEFINITION_SW_PATCH_VERSION_H              0
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
        [!CODE!][!WS "0"!]
/** 
* @brief This macro define specific derivative and sub derivative.
*/
        [!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K116')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K116
#define S32K116
#endif

#ifndef DERIVATIVE_S32K116
#define DERIVATIVE_S32K116
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K118')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K118
#define S32K118
#endif

#ifndef DERIVATIVE_S32K118
#define DERIVATIVE_S32K118
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K142W')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K142W
#define S32K142W
#endif

#ifndef DERIVATIVE_S32K142W
#define DERIVATIVE_S32K142W
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K142')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K142
#define S32K142
#endif

#ifndef DERIVATIVE_S32K142
#define DERIVATIVE_S32K142
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K144W')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K144W
#define S32K144W
#endif

#ifndef DERIVATIVE_S32K144W
#define DERIVATIVE_S32K144W
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K144')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K144
#define S32K144
#endif

#ifndef DERIVATIVE_S32K144
#define DERIVATIVE_S32K144
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K146')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K146
#define S32K146
#endif

#ifndef DERIVATIVE_S32K146
#define DERIVATIVE_S32K146
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K148')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32K148
#define S32K148
#endif

#ifndef DERIVATIVE_S32K148
#define DERIVATIVE_S32K148
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M244')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32M244
#define S32M244
#endif

#ifndef DERIVATIVE_S32M244
#define DERIVATIVE_S32M244
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M242')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32M242
#define S32M242
#endif

#ifndef DERIVATIVE_S32M242
#define DERIVATIVE_S32M242
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M241')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32M241
#define S32M241
#endif

#ifndef DERIVATIVE_S32M241
#define DERIVATIVE_S32M241
#endif

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M243')"!][!//
        [!CODE!][!WS "0"!]
#ifndef S32M243
#define S32M243
#endif

#ifndef DERIVATIVE_S32M243
#define DERIVATIVE_S32M243
#endif

        [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//


        [!CODE!][!WS "0"!]

/** 
* @brief This macro define specific platform.
*/
#ifndef S32K1XX
#define S32K1XX
#endif
        [!CR!][!ENDCODE!][!//

[!ENDIF!][!//
[!ENDNOCODE!][!//

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

#endif /* DDEVICEDEFINITION_H */

/** @} */

