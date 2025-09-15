/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : AE
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/
/**
*   @file    CanTrcv_43_AE_Ipw_PBcfg.c
*
*   @addtogroup CANTRCV_43_AE_DRIVER Can Transceiver Driver
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
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]

#include "CanTrcv_43_AE_Ipw_Types.h"
#include "Aecanphy_Ip.h"
#include "CanTrcv_43_AE_Ipw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C                     43
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C              3
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C              0
#define CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h are of the same vendor */
#if (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C != CANTRCV_43_AE_IPW_TYPES_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_IPW_TYPES_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h are different"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h are of the same Software version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C != CANTRCV_43_AE_IPW_TYPES_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C != CANTRCV_43_AE_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw_Types.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same vendor */
#if (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C != AECANPHY_IP_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AECANPHY_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AECANPHY_IP_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != AECANPHY_IP_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are different"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same Software version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C != AECANPHY_IP_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C != AECANPHY_IP_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C != AECANPHY_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are different"
#endif

/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h are of the same vendor */
#if (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C != CANTRCV_43_AE_IPW_VENDOR_ID)
    #error "CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h have different vendor ids"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h are of the same Autosar version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != CANTRCV_43_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != CANTRCV_43_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_AE_IPW_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h are different"
#endif
/* Check if CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h are of the same Software version */
#if ((CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MAJOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C != CANTRCV_43_AE_IPW_SW_MINOR_VERSION) || \
     (CANTRCV_43_AE_IPW[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C != CANTRCV_43_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CanTrcv_43_AE_Ipw[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and CanTrcv_43_AE_Ipw.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

/**
* @brief   Export PHY_AE10 configurations.
*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!SELECT "CanTrcvConfigSet"!]
[!VAR "CtrlConfigCount" = "num:i(count(./CanTrcvChannel/*))"!]
[!VAR "ChnIdx" = "num:i(0)"!]
[!LOOP "node:order(./CanTrcvChannel/*, './CanTrcvChannelId')"!]
[!CODE!]const CanTrcv_43_AE_Ipw_TransceiverConfigType CanTrcv_43_AE_Ipw_TransceiverConfig[!"$postBuildVariantNameUnderscore"!]_Chn[!"$ChnIdx"!] =
{
    &Aecanphy_aConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$ChnIdx"!]U][!ENDCODE!]
    [!VAR "ChnIdx" = "num:i($ChnIdx + 1)"!]
[!CODE!]
};
[!ENDCODE!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
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
