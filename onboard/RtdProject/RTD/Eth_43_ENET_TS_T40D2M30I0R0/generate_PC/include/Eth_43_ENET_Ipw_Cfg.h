/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ENET
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

#ifndef ETH_43_ENET_IPW_CFG_H
#define ETH_43_ENET_IPW_CFG_H

/**
*   @file
*
*   @addtogroup ETH_43_ENET_DRIVER_CONFIGURATION Ethernet Driver Configurations
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
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Eth_43_ENET_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Eth_43_ENET_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Eth_43_ENET_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_ENET_IPW_CFG_VENDOR_ID                    43
#define ETH_43_ENET_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_ENET_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_ENET_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_ENET_IPW_CFG_SW_MAJOR_VERSION             3
#define ETH_43_ENET_IPW_CFG_SW_MINOR_VERSION             0
#define ETH_43_ENET_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Eth_43_ENET_Ipw_[!"."!]_PBcfg.h */
#if (ETH_43_ENET_IPW_CFG_VENDOR_ID != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((ETH_43_ENET_IPW_CFG_SW_MAJOR_VERSION != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_MINOR_VERSION != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_PATCH_VERSION != ETH_43_ENET_IPW_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Eth_43_ENET_Ipw_PBcfg.h */
#if (ETH_43_ENET_IPW_CFG_VENDOR_ID != ETH_43_ENET_IPW_PBCFG_VENDOR_ID)
    #error "Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_ENET_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_ENET_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_ENET_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_PBcfg.h are different"
#endif
#if ((ETH_43_ENET_IPW_CFG_SW_MAJOR_VERSION != ETH_43_ENET_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_MINOR_VERSION != ETH_43_ENET_IPW_PBCFG_SW_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_PATCH_VERSION != ETH_43_ENET_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Eth_43_ENET_Cfg.h */
#if (ETH_43_ENET_IPW_CFG_VENDOR_ID != ETH_43_ENET_CFG_VENDOR_ID)
    #error "Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_ENET_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Cfg.h are different"
#endif
#if ((ETH_43_ENET_IPW_CFG_SW_MAJOR_VERSION != ETH_43_ENET_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_MINOR_VERSION != ETH_43_ENET_CFG_SW_MINOR_VERSION) || \
     (ETH_43_ENET_IPW_CFG_SW_PATCH_VERSION != ETH_43_ENET_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_43_ENET_Ipw_Cfg.h and Eth_43_ENET_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define ETH_43_ENET_IPW_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]ETH_43_ENET_IPW_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]ETH_43_ENET_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == ETH_43_ENET_DEM_EVENT_DETECT)
/**
 * @brief    Type for holding DEM events
 * @details  It contains the necessary events to report to the DEM module
 */
typedef struct
{
    Mcal_DemErrorType ETH_43_ENET_IPW_ETH_E_ERR_Cfg;

} Eth_43_ENET_Ipw_DemEventsType;
#endif

/* Forward IPW structure declarations */
struct sEnet_CtrlConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct sEth_43_ENET_Ipw_CtrlConfigType
{
    const struct sEnet_CtrlConfigType *Eth_43_ENET_Ipw_pEnetCtrlConfig;
#if (STD_ON == ETH_43_ENET_DEM_EVENT_DETECT)
    const Eth_43_ENET_Ipw_DemEventsType Eth_43_ENET_Ipw_DemEventsList;
#endif
#if (STD_ON == ETH_43_ENET_GLOBAL_TIME_API)
    uint32 CorectionCounter;
#endif
} Eth_43_ENET_Ipw_CtrlConfigType;

typedef struct Eth_43_ENET_axTxBufferIdxMapType
{
    uint8 FifoIdx;
    uint8* pu8BufferData;
    boolean bTxConfirmation;
    struct Eth_43_ENET_axTxBufferIdxMapType *pNextBuffer;

} Eth_43_ENET_axTxBufferIdxMapType;

typedef struct
{
    Eth_43_ENET_axTxBufferIdxMapType *pQueueHead;
    Eth_43_ENET_axTxBufferIdxMapType *pQueueTail;

} Eth_43_ENET_QueueInfo;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETH_43_ENET_IPW_CFG_H */
