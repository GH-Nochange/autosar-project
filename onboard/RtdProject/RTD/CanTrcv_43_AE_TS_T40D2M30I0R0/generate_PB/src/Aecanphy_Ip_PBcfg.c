
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
*   @file Aecanphy_Ip_PBcfg.c
*
*   @addtogroup
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
#include "Aecanphy_Ip.h"
[!AUTOSPACING!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C                     43
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C              3
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C              0
#define AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same vendor */
#if (AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_VENDOR_ID_C != AECANPHY_IP_VENDOR_ID)
    #error "Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h have different vendor ids"
#endif
/* Check if Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same Autosar version */
#if ((AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AECANPHY_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AECANPHY_IP_AR_RELEASE_MINOR_VERSION) || \
     (AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != AECANPHY_IP_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are different"
#endif
/* Check if Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are of the same Software version */
#if ((AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MAJOR_VERSION_C != AECANPHY_IP_SW_MAJOR_VERSION) || \
     (AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_MINOR_VERSION_C != AECANPHY_IP_SW_MINOR_VERSION) || \
     (AECANPHY_IP[!"text:toupper($postBuildVariantNameUnderscore)"!]_PBCFG_SW_PATCH_VERSION_C != AECANPHY_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Aecanphy_Ip[!"$postBuildVariantNameUnderscore"!]_PBcfg.c and Aecanphy_Ip.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CANTRCV_43_AE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"

[!VAR "CtrlConfigCount" = "num:i(count(./CanTrcvConfigSet/CanTrcvChannel/*))"!]
const Aecanphy_Ip_ConfigType Aecanphy_aConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$CtrlConfigCount"!]U]=
{
    [!VAR "CtrlIdx" = "num:i(0)"!]
    [!VAR "Spi_Timeout" = "num:i(CanTrcvConfigSet/CanTrcvSPICommTimeout)"!]
    [!VAR "Spi_ReTries_Num" = "num:i(CanTrcvConfigSet/CanTrcvSPICommRetries)"!]
    [!LOOP "node:order(./CanTrcvConfigSet/CanTrcvChannel/*, './CanTrcvChannelId')"!]
    {
        /* .SpiConfig */
        {
            /* .SpiCommRetries */
            (uint8)[!"$Spi_ReTries_Num"!]U
        },
        /* .DeviceModeAfterInit */
        AE_CANPHY_OFFLINE_MODE
    }[!IF "num:i($CtrlIdx + 1) < $CtrlConfigCount"!],[!ENDIF!][!CR!]
    [!ENDLOOP!]
};

#define CANTRCV_43_AE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_AE_MemMap.h"
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
