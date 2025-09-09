[!CODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef LPIT_ICU_IP_DEFINES_H
#define LPIT_ICU_IP_DEFINES_H

/**
 * @file    Lpit_Icu_Ip_Defines.h
 * @version 3.0.0
 *
 * @addtogroup lpit_icu_ip LPIT IPL
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_LPIT.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]#include "S32M24x_LPIT.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPIT_ICU_IP_DEFINES_VENDOR_ID                       43
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LPIT_ICU_IP_DEFINES_SW_MAJOR_VERSION                3
#define LPIT_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define LPIT_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Lpit_Icu_Ip.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//

[!MACRO "GenerateUniqueElements", "ListWithDuplicateElements"!][!//
    [!VAR "ListWithUniqueElements" = "''"!][!//
    [!FOR "index" = "0" TO "num:i(count(text:split($ListWithDuplicateElements)))"!][!//
        [!IF "not(text:contains(text:split($ListWithUniqueElements), text:split($ListWithDuplicateElements)[$index + 1]))"!][!//
            [!VAR "ListWithUniqueElements" = "concat($ListWithUniqueElements, ' ', text:split($ListWithDuplicateElements)[$index + 1])"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
    [!"$ListWithUniqueElements"!][!//
[!ENDMACRO!][!//

[!IF "count(./IcuConfigSet/IcuLpit/*) > '0'"!][!//
    [!VAR "ListOfUsedIrqs" = "''"!][!//
    [!CODE!][!WS "0"!]/* Macros that indicate LPIT instances used by ICU. */[!CR!][!ENDCODE!][!//
    [!SELECT "./IcuConfigSet"!][!//
        [!LOOP "IcuHwInterruptConfigList/*"!][!//
            [!IF "contains(IcuIsrHwId, 'LPIT')"!][!//
                [!VAR "lpitInstance" = "text:split(./IcuIsrHwId, '_')[2]"!][!//
                [!VAR "ListOfUsedIrqs" = "concat($ListOfUsedIrqs, ' ', $lpitInstance)"!][!//

                [!IF "contains($DerivativeName, 'S32K14') or contains($DerivativeName, 'S32M24')"!][!//
                    [!VAR "lpitChannel" = "text:split(./IcuIsrHwId, '_')[4]"!][!//
                    [!CODE!]
/** @brief LPIT [!"$lpitInstance"!] CH [!"$lpitChannel"!] ISR enable/disable */
#define LPIT_ICU_[!"$lpitInstance"!]_CH_[!"$lpitChannel"!]_ISR_USED                    (STD_ON)

                    [!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        
        [!VAR "UniqueUsedLpit"!][!CALL "GenerateUniqueElements", "ListWithDuplicateElements" = "$ListOfUsedIrqs"!][!ENDVAR!][!//
        [!IF "contains($DerivativeName, 'S32K11')"!][!//
            [!FOR "x" = "1" TO "num:i(count(text:split($UniqueUsedLpit, ' ')))"!][!//
                [!CODE!]
/** @brief LPIT [!"(text:split($UniqueUsedLpit, ' '))[num:i($x)]"!] ISR enable/disable */
#define LPIT_ICU_[!"(text:split($UniqueUsedLpit, ' '))[num:i($x)]"!]_ISR_USED                    (STD_ON)

                [!ENDCODE!]
            [!ENDFOR!][!//
        [!ENDIF!][!//

        [!FOR "x" = "1" TO "num:i(count(text:split($UniqueUsedLpit, ' ')))"!][!//
            [!CODE!]
#ifndef LPIT_[!"(text:split($UniqueUsedLpit, ' '))[num:i($x)]"!]_USED
    #define LPIT_[!"(text:split($UniqueUsedLpit, ' '))[num:i($x)]"!]_USED
#else
    #error "LPIT_[!"(text:split($UniqueUsedLpit, ' '))[num:i($x)]"!] instance cannot be used by ICU. Instance locked by another driver!"
#endif

            [!ENDCODE!]
        [!ENDFOR!][!//
        
    [!ENDSELECT!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
/* MIER start bit mask. */
#define LPIT_MIER_TIE_START_MASK                (uint32)0x1U

/* MSR start bit mask. */
#define LPIT_MSR_TIF_START_MASK                 (uint32)0x1U

/* Channels trigger select defines. */
#define LPIT_ICU_TRG_CH0                        ((uint8)0U)
#define LPIT_ICU_TRG_CH1                        ((uint8)1U)
#define LPIT_ICU_TRG_CH2                        ((uint8)2U)
#define LPIT_ICU_TRG_CH3                        ((uint8)3U)

/* Channels trigger source defines. */
#define LPIT_ICU_CH_INTERNAL_TRIGGER            ((uint8)1U)
#define LPIT_ICU_CH_EXTERNAL_TRIGGER            ((uint8)0U)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define LPIT_ICU_IP_DEV_ERROR_DETECT            ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define LPIT_ICU_DEINIT_API                     ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define LPIT_ICU_EDGE_DETECT_API                ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the timestamp functionality. */
#define LPIT_ICU_TIMESTAMP_API                  ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define LPIT_ICU_GET_INPUT_STATE_API            ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Define if global variables need to be placed in non-cache area or not */
#define LPIT_ICU_IP_NO_CACHE_USED               ([!IF "num:i(count(IcuGeneral/IcuEcucPartitionRef/*)) > 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* LPIT_ICU_IP_DEFINES_H */

/** @} */

[!ENDCODE!][!//
