[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
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
#ifndef CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_H
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_H

/**
*   @file       CDD_Qdec[!"$VS_number"!]_PBcfg.h
*
*   @brief      AUTOSAR Qdec - PostBuild configuration.
*   @details    Contains the PostBuild configuration used by QDEC driver.
*
*   @addtogroup qdec Qdec Driver
*   @brief      Qdec HLD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Qdec_Ipw[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID                          43
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION           4
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION           7
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION        0
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION                   3
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION                   0
#define CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION                   0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same vendor */
#if (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
#error "CDD_Qdec[!"($VS_number)"!]_PBcfg.h and CDD_Qdec_Ipw[!"($VS_number)"!]_PBcfg.h have different vendor IDs"
#endif
/* Check if header file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same Autosar version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.h and CDD_Qdec_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif
/* Check if header file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same Software Version */
#if ((CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION != CDD_QDEC_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Qdec[!"$VS_number"!]_PBcfg.h and CDD_Qdec_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!]
    [!VAR "VariantsNo" = "variant:size()"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!CODE!]#define QDEC_CONFIG[!"text:toupper($VS_number)"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!]#define QDEC_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "QdecConfiguredPartitions" = "num:i((count(QdecGeneral/QdecEcucPartitionRef/*)))"!]
    [!IF "$QdecConfiguredPartitions > 0"!]
        [!LOOP "QdecGeneral/QdecEcucPartitionRef/*"!]
            [!VAR "CurrentPartionName" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!]
            [!CODE!][!WS "0"!]extern const Qdec_ConfigType Qdec_Config[!"$VS_number"!]_[!"$CurrentPartionName"!]; \[!CR!][!ENDCODE!]
        [!ENDLOOP!]
[!ELSE!]
    [!CODE!][!WS "0"!]extern const Qdec_ConfigType Qdec_Config[!"$VS_number"!];[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

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

/**@}*/

#endif    /* CDD_QDEC[!"text:toupper($VS_number)"!]_PBCFG_H */
[!ENDCODE!]