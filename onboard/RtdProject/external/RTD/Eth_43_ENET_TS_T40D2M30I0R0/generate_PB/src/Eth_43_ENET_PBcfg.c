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
/**
*   @file
*   @implements Eth_PBcfg.c_Artifact
*   @addtogroup ETH_43_ENET_DRIVER_CONFIGURATION Ethernet Driver Configuration
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
#include "Eth_43_ENET_Cfg.h"
#include "Eth_43_ENET_Ipw_Cfg.h"

#if defined(ETH_43_ENET_MACSEC_SUPPORT)
#if (STD_ON == ETH_43_ENET_MACSEC_SUPPORT)
#include "Eth_43_ENET_MACsec_Types.h"
#endif
#endif

#if STD_ON == ETH_43_ENET_DEM_EVENT_DETECT
    #include "Dem.h"
#endif

#if (STD_ON == ETH_43_ENET_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_ENET_MDIO_CLAUSE45_API)
[!NOCODE!]
[!VAR "EthTrcvHeaderTable" = "''"!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix != string(null)"!]
        [!VAR "HeaderName" = "concat('EthTrcv_', EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix)"!]
    [!ELSE!]
        [!VAR "HeaderName" = "'EthTrcv'"!]
    [!ENDIF!]
    [!IF "not(text:contains(text:split($EthTrcvHeaderTable), $HeaderName))"!]
[!CODE!][!//
    #include "[!"$HeaderName"!].h"
[!ENDCODE!]
    [!ENDIF!]
    [!VAR "EthTrcvHeaderTable" = "concat($EthTrcvHeaderTable, ' ', $HeaderName)"!]
[!ENDLOOP!]
[!ENDNOCODE!][!//
#endif

#if STD_ON == ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API
[!NOCODE!]
[!VAR "EthSwtHeaderTable" = "''"!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != string(null)"!]
        [!VAR "HeaderName" = "concat('EthSwt_', EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix)"!]
    [!ELSE!]
        [!VAR "HeaderName" = "'EthSwt'"!]
    [!ENDIF!]
    [!IF "not(text:contains(text:split($EthSwtHeaderTable), $HeaderName))"!]
[!CODE!][!//
    #include "[!"$HeaderName"!].h"
[!ENDCODE!]
    [!ENDIF!]
    [!VAR "EthSwtHeaderTable" = "concat($EthSwtHeaderTable, ' ', $HeaderName)"!]
[!ENDLOOP!]
[!ENDNOCODE!][!//
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C                     43
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      7
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C              3
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_43_ENET_Cfg.h */
#if (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C != ETH_43_ENET_CFG_VENDOR_ID)
    #error "Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != ETH_43_ENET_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Cfg.h are different"
#endif
#if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C != ETH_43_ENET_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C != ETH_43_ENET_CFG_SW_MINOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C != ETH_43_ENET_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Cfg.h are different"
#endif

/* Checks against Eth_43_ENET_Ipw_Cfg.h */
#if (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_VENDOR_ID_C != ETH_43_ENET_IPW_CFG_VENDOR_ID)
    #error "Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Ipw_Cfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != ETH_43_ENET_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != ETH_43_ENET_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != ETH_43_ENET_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Ipw_Cfg.h are different"
#endif
#if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MAJOR_VERSION_C != ETH_43_ENET_IPW_CFG_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_MINOR_VERSION_C != ETH_43_ENET_IPW_CFG_SW_MINOR_VERSION) || \
     (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_SW_PATCH_VERSION_C != ETH_43_ENET_IPW_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_Ipw_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if STD_ON == ETH_43_ENET_DEM_EVENT_DETECT
    /* Checks against Dem.h */
    #if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Dem.h are different"
    #endif
  #endif

  #if (STD_ON == ETH_43_ENET_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_ENET_MDIO_CLAUSE45_API)
[!NOCODE!]
    [!LOOP "text:split($EthTrcvHeaderTable)"!]
[!CODE!]
    /* Checks against [!"."!].h */
    #if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != [!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != [!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and [!"."!].h are different"
    #endif
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDNOCODE!]
  #endif

  #if STD_ON == ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API
[!NOCODE!]
    [!LOOP "text:split($EthSwtHeaderTable)"!]
[!CODE!]
    /* Checks against [!"."!].h */
    #if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != [!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != [!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and [!"."!].h are different"
    #endif
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDNOCODE!]
  #endif

#if defined(ETH_43_ENET_MACSEC_SUPPORT)
#if (STD_ON == ETH_43_ENET_MACSEC_SUPPORT)
[!CODE!]
    /* Checks against Eth_43_ENET_MACsec_Types.h */
    #if ((ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != ETH_43_ENET_MACSEC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != ETH_43_ENET_MACSEC_TYPES_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_PBcfg.c and Eth_43_ENET_MACsec_Types.h are different"
    #endif
[!ENDCODE!]
#endif
#endif
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/**
* @brief   Export IPW configurations.
*/
ETH_43_ENET_IPW_CONFIG_EXT


#if defined(ETH_43_ENET_MACSEC_SUPPORT)
#if (STD_ON == ETH_43_ENET_MACSEC_SUPPORT)
ETH_43_ENET_MACSEC_IPW_CONFIG_EXT

#endif
#endif

#define ETH_43_ENET_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!MACRO "GetIngressBufferCount"!][!//
[!NOCODE!]
    [!VAR "IngressBufferCount" = "num:i(0)"!]
    [!LOOP "EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!]
        [!VAR "IngressBufferCount" = "num:i($IngressBufferCount) + num:i(EthCtrlConfigIngressFifoBufTotal)"!]
    [!ENDLOOP!]
    [!CODE!][!"num:i($IngressBufferCount)"!]U[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetEgressBufferCount"!][!//
[!NOCODE!]
    [!VAR "EgressBufferCount" = "num:i(0)"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
        [!VAR "EgressBufferCount" = "num:i($EgressBufferCount) + num:i(EthCtrlConfigEgressFifoBufTotal)"!]
    [!ENDLOOP!]
    [!CODE!][!"num:i($EgressBufferCount)"!]U[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetVlanPcpToTxFifoIdxMap"!][!//
[!NOCODE!]
    [!FOR "Priority" = "0" TO "7"!]
        [!VAR "EgressFifoIdx" = "0"!]
        [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoPriorityAssignment/*"!]
            [!IF "num:i($Priority) = num:i(.)"!]
                [!VAR "EgressFifoIdx" = "num:i(../../EthCtrlConfigEgressFifoIdx)"!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!CODE!][!"num:i($EgressFifoIdx)"!]U[!IF "$Priority < 7"!], [!ENDIF!][!ENDCODE!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetDemEventError", "ErrorName"!][!//
[!NOCODE!]
    [!VAR "ErrorSymbolicName" = "num:i(0)"!]
    [!VAR "ErrorEnabled"      = "false()"!]

    [!IF "(node:value(../../../EthGeneral/EthGeneralVendorSpecific/EthDisableDemEventDetect) = 'false') and node:exists(EthDemEventParameterRefs)"!]
        [!SELECT "EthDemEventParameterRefs"!]
            [!IF "node:exists($ErrorName) and node:refvalid($ErrorName)"!]
                [!VAR "ErrorEnabled" = "true()"!]
                [!VAR "ErrorRef" = "node:ref($ErrorName)"!]
                [!VAR "ErrorSymbolicName" = "concat('DemConf_DemEventParameter_', node:name($ErrorRef))"!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDIF!]

    [!CODE!](uint32)[!IF "$ErrorEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!], [!"$ErrorSymbolicName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
[!CODE!]
static const Eth_43_ENET_EgressCfgType Eth_43_ENET_aEgressConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfEthCtrls)"!]U] =
{
[!ENDCODE!]

    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!CODE!][!//
    /* The configuration structure for Eth_43_ENET_aEgressConfigPB[[!"num:i(@index)"!]U] - IP_[!"num:i(EthCtrlIdx)"!] */
    {
        [!CALL "GetEgressBufferCount"!], /* Total number of buffers across all Tx FIFOs */
        [!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U, /* Total number of configured Tx FIFOs */
        { [!CALL "GetVlanPcpToTxFifoIdxMap"!] } /* Map between VLAN PCPs and Tx FIFOs */
    }[!IF "num:i($FirstCtrl) < num:i($NumOfEthCtrls)"!],[!ENDIF!][!VAR "FirstCtrl" = "$FirstCtrl + 1"!]
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
[!CODE!]
static const Eth_43_ENET_IngressCfgType Eth_43_ENET_aIngressConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfEthCtrls)"!]U] =
{
[!ENDCODE!]

    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!CODE!][!//
    /* The configuration structure for Eth_43_ENET_aIngressConfigPB[[!"num:i(@index)"!]U] - IP_[!"num:i(EthCtrlIdx)"!] */
    {
        [!CALL "GetIngressBufferCount"!], /* Total number of buffers across all Rx FIFOs */
        [!"num:i(count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*))"!]U /* Total number of configured Rx FIFOs */
    }[!IF "num:i($FirstCtrl) < num:i($NumOfEthCtrls)"!],[!ENDIF!][!VAR "FirstCtrl" = "$FirstCtrl + 1"!]
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
[!CODE!]
static const Eth_43_ENET_ClockCfgType Eth_43_ENET_aClockConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfEthCtrls)"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!CODE!][!//
    /* The configuration structure for Eth_43_ENET_aClockConfigPB[[!"num:i(@index)"!]U] - IP_[!"num:i(EthCtrlIdx)"!] */
    {
[!ENDCODE!]
[!NOCODE!][!//
    [!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!][!//
            [!CODE!][!//
                [!IF "node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthModuleReferenceClock)"!](uint32)[!"num:i(round(node:ref(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthModuleReferenceClock)/McuClockReferencePointFrequency))"!][!ELSE!](uint32)0[!ENDIF!]U, /* Frequency of the application interface (in Hz) */
                [!IF "node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampReferenceClock)"!](uint32)[!"num:i(round(1000000000000 div node:ref(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampReferenceClock)/McuClockReferencePointFrequency))"!][!ELSE!](uint32)0[!ENDIF!]U, /* Number of picoseconds in a PTP clock period */
                [!IF "node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampRequiredAccuracy)"!](uint32)[!"num:i(node:value(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampRequiredAccuracy))"!][!ELSE!](uint32)0[!ENDIF!]U  /* Number of nanoseconds in a PTP clock period for the required accuracy */
            [!ENDCODE!]
        [!ELSE!]

            [!VAR "TimeNominalNs"             = "0"!][!//
            [!VAR "MultiplyRatio"             = "0"!][!//
            [!VAR "SubSecondInc"              = "0"!][!//
            [!VAR "SubNanoSecondsInc"         = "0"!][!//
            [!VAR "TimeRequiredNs"            = "0"!][!//
            [!VAR "MultiplyRatioCompensation" = "0"!][!//
            [!VAR "McuClockReferencePointFrequencyVal" = "0"!][!//

            [!CODE!][!WS "8"!][!IF "node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthModuleReferenceClock)"!](uint32)[!"num:i(round(node:ref(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthModuleReferenceClock)/McuClockReferencePointFrequency))"!][!ELSE!](uint32)0[!ENDIF!]U, /* Frequency of the PTP reference clock (in Hz). */[!CR!][!ENDCODE!][!//
            [!IF "node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampReferenceClock) and
                node:exists(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthPtpTimeCounterMaxAdjustPercentage)"!][!//

                [!VAR "EthPtpTimeCounterMaxAdjustPercentageVal" = "node:value(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthPtpTimeCounterMaxAdjustPercentage)"!][!//
                [!VAR "McuClockReferencePointFrequencyVal" = "node:ref(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthTimeStampReferenceClock)/McuClockReferencePointFrequency"!][!//
                [!VAR "TimeNominalNs" = "1000000000 div $McuClockReferencePointFrequencyVal"!][!//
                [!VAR "MultiplyRatio" = "100 div (100 - $EthPtpTimeCounterMaxAdjustPercentageVal)"!][!//
                [!VAR "SubSecondInc" = "num:i($TimeNominalNs * $MultiplyRatio)"!][!//

                [!CODE!][!WS "8"!](uint8)[!"num:i($SubSecondInc)"!]U,[!ENDCODE!][!//
                [!CODE!][!WS "8"!]/* Default value for SSINC register. */[!CR!][!ENDCODE!][!//

                [!VAR "SubNanoSecondsInc" = "num:i(($TimeNominalNs * $MultiplyRatio - num:i($SubSecondInc)) * 256)"!][!//
                [!CODE!][!WS "8"!](uint8)[!"num:i($SubNanoSecondsInc)"!]U,[!ENDCODE!][!//
                [!CODE!][!WS "8"!]/* Default value for SNSINC register. */[!CR!][!ENDCODE!][!//

                [!VAR "TimeRequiredNs" = "$SubSecondInc + ($SubNanoSecondsInc div 256)"!][!//
                [!VAR "MultiplyRatioCompensation" = "$TimeRequiredNs div $TimeNominalNs"!][!//
                [!CODE!][!WS "8"!](float64)[!"$MultiplyRatioCompensation"!][!ENDCODE!][!//
                [!CODE!][!WS "8"!]/* Multiply ratio for computation of new value for TSAR register. */[!CR!][!ENDCODE!][!//

            [!ELSE!][!//
                [!CODE!][!WS "8"!](uint8)0U,        /* Default value for SSINC register. */[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "8"!](uint8)0U,        /* Default value for SNSINC register. */[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "8"!](float64)1.0        /* Multiply ratio for computation of new value for TSAR register. */[!CR!][!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDIF!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!CODE!][!//
    }[!IF "num:i($FirstCtrl) < num:i($NumOfEthCtrls)"!],[!ENDIF!][!VAR "FirstCtrl" = "$FirstCtrl + 1"!]
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
[!CODE!]
static const Eth_43_ENET_CtrlCfgType Eth_43_ENET_aCtrlConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i($NumOfEthCtrls)"!]U] =
{
[!ENDCODE!]

    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!CODE!][!//
    /* The configuration structure for Eth_43_ENET_aCtrlConfigPB[[!"num:i(@index)"!]U] - IP_[!"num:i(EthCtrlIdx)"!] */
    {
        &Eth_43_ENET_Ipw_aCtrlConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i(@index)"!]U],
        &Eth_43_ENET_aEgressConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i(@index)"!]U],
        &Eth_43_ENET_aIngressConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i(@index)"!]U],
        &Eth_43_ENET_aClockConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][[!"num:i(@index)"!]U],
        (uint8)[!"num:i(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlEthIfIdx)"!]U,
        (uint8)[!"num:i(EthCtrlIdx)"!]U
#if (STD_ON == ETH_43_ENET_DEM_EVENT_DETECT)
       ,{
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_ACCESS'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_RX_FRAMES_LOST'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_CRC'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_UNDERSIZEFRAME'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_OVERSIZEFRAME'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_ALIGNMENT'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_SINGLECOLLISION'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_MULTIPLECOLLISION'"!] },
            { [!CALL "GetDemEventError", "ErrorName" = "'ETH_E_LATECOLLISION'"!] }
        }
#endif
#if (STD_ON == ETH_43_ENET_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_ENET_MDIO_CLAUSE45_API)
       ,{
            &EthTrcv_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]ReadMiiIndication,
            &EthTrcv_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]WriteMiiIndication
        }
#endif
#if STD_ON == ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API
       ,{
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxAdaptBufferLength,
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxPrepareFrame,
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxProcessFrame,
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxFinishedIndication,
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxProcessFrame,
            &EthSwt_[!IF "EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxFinishedIndication
        }
#endif
    }[!IF "num:i($FirstCtrl) < num:i($NumOfEthCtrls)"!],[!ENDIF!][!VAR "FirstCtrl" = "$FirstCtrl + 1"!]
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

#define ETH_43_ENET_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!MACRO "GetCtrlConfigStructName", "CtrlHwIndex", "EcucPartitionRef"!][!//
[!NOCODE!]
    [!VAR "CtrlConfigStructureName" = "'NULL_PTR'"!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_', text:toupper($postBuildVariant))"!]
    [!ENDIF!]
    [!VAR "Position" = "string(null)"!]

    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
        [!IF "num:i(EthCtrlIdx) = num:i($CtrlHwIndex)"!]
            [!IF "$EcucPartitionRef != string(null)"!]
                [!IF "node:exists(EthCtrlEcucPartitionRef) and node:refvalid(EthCtrlEcucPartitionRef)"!]
                    [!IF "node:value(EthCtrlEcucPartitionRef) = $EcucPartitionRef"!]
                        [!VAR "Position" = "num:i(@index)"!]
                        [!VAR "CtrlConfigStructureName" = "concat('&Eth_43_ENET_aCtrlConfigPB', $postBuildVariantNameUnderscore, '[', $Position, 'U]')"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "Position" = "num:i(@index)"!]
                [!VAR "CtrlConfigStructureName" = "concat('&Eth_43_ENET_aCtrlConfigPB', $postBuildVariantNameUnderscore, '[', $Position, 'U]')"!]
            [!ENDIF!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$CtrlConfigStructureName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetConfigStructName", "EcucPartitionRef"!][!//
[!NOCODE!]
    [!VAR "ConfigStructureName" = "'NULL_PTR'"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
        [!IF "node:exists(EthCtrlEcucPartitionRef) and node:refvalid(EthCtrlEcucPartitionRef)"!]
            [!IF "node:value(EthCtrlEcucPartitionRef) = $EcucPartitionRef"!]
                [!VAR "CtrlPartitionShortName" = "node:name(node:ref(EthCtrlEcucPartitionRef))"!]
                [!VAR "ConfigStructureName"    = "concat('&Eth_43_ENET_xPredefinedConfig_', $CtrlPartitionShortName)"!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$ConfigStructureName"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPartitionId", "EcucPartitionRef"!][!//
[!NOCODE!]
    [!VAR "PartitionId" = "num:i(-1)"!]
    [!SELECT "as:modconf('Os')[1]/OsApplication/*/OsAppEcucPartitionRef"!]
        [!IF "node:value(.) = $EcucPartitionRef"!]
            [!VAR "PartitionId" = "num:i(node:pos(node:value(.)))"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDSELECT!]
    [!IF "$PartitionId = num:i(-1)"!][!ERROR!]The referenced ECUC partition [!"$EcucPartitionRef"!] in EthEcucPartitionRef is not associated with any OsApplication[!ENDERROR!][!ENDIF!]

    [!CODE!][!"$PartitionId"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetEcucPartitionRef", "PartitionId"!][!//
[!NOCODE!]
    [!VAR "EcucPartitionRef" = "string(null)"!]
    [!SELECT "as:modconf('Os')[1]/OsApplication/*/OsAppEcucPartitionRef"!]
        [!IF "node:refvalid(.) "!]
            [!IF "num:i(node:pos(node:value(.))) = num:i($PartitionId)"!]
                [!VAR "EcucPartitionRef" = "node:value(.)"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDSELECT!]

    [!CODE!][!"$EcucPartitionRef"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GenerateSinglePartitionConfig"!][!//
[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
[!CODE!]
const Eth_43_ENET_ConfigType [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]Eth_43_ENET_xPredefinedConfig[!ELSE!]Eth_43_ENET_Config[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][!ENDIF!] =
{
    {
[!ENDCODE!]
        [!VAR "MaxHwCtrlIdx" = "num:i(EthGeneral/EthMaxCtrlsSupported - 1)"!]
        [!FOR "CtrlHwIdx" = "0" TO "$MaxHwCtrlIdx"!]
[!CODE!]
        [!CALL "GetCtrlConfigStructName", "CtrlHwIndex" = "$CtrlHwIdx"!][!IF "$CtrlHwIdx!=$MaxHwCtrlIdx"!],[!ENDIF!] /* IP_[!"$CtrlHwIdx"!] */[!//
[!ENDCODE!]
        [!ENDFOR!][!// CtrlHwIdx
[!CODE!]
    }
};
[!ENDCODE!]
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GenerateMultiPartitionConfig"!][!//
[!NOCODE!]
    [!LOOP "EthGeneral/EthEcucPartitionRef/*"!]
        [!VAR "partitionRef"       = "node:value(.)"!]
        [!VAR "partitionShortName" = "node:name(node:ref(.))"!]
        [!VAR "partitionIdx"!][!CALL "GetPartitionId", "EcucPartitionRef" = "$partitionRef"!][!ENDVAR!]
        [!SELECT "../../.."!]
[!CODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!][!//
static const Eth_43_ENET_ConfigType Eth_43_ENET_xPredefinedConfig_[!"$partitionShortName"!] =
[!ELSE!][!//
const Eth_43_ENET_ConfigType Eth_43_ENET_Config[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!]_[!"$partitionShortName"!] =
[!ENDIF!][!//
{
    [!"num:i($partitionIdx)"!]U,
    {
[!ENDCODE!]
        [!VAR "MaxHwCtrlIdx" = "num:i(EthGeneral/EthMaxCtrlsSupported - 1)"!]
        [!FOR "CtrlHwIdx" = "0" TO "$MaxHwCtrlIdx"!]
[!CODE!]
        [!CALL "GetCtrlConfigStructName", "CtrlHwIndex" = "$CtrlHwIdx", "EcucPartitionRef" = "$partitionRef"!][!IF "$CtrlHwIdx!=$MaxHwCtrlIdx"!],[!ENDIF!] /* IP_[!"$CtrlHwIdx"!] */[!//
[!ENDCODE!]
        [!ENDFOR!][!// CtrlHwIdx
[!CODE!]
    }
};
[!ENDCODE!]
        [!ENDSELECT!]
    [!ENDLOOP!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GenerateMultiPartitionPredefinedConfig"!][!//
[!NOCODE!]
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!][!//
[!CODE!]
const Eth_43_ENET_ConfigType * const Eth_43_ENET_apxPredefinedConfig[ETH_43_ENET_MAX_PARTITIONIDX_SUPPORTED] =
{
[!ENDCODE!]
    [!VAR "MaxPartitionIdx"!][!"num:i((node:fallback("->count(as:modconf('EcuC')/EcucPartitionCollection/*/EcucPartition/*)", -1)) - 1)"!][!ENDVAR!]
    [!FOR "PartitionIdx" = "0" TO "$MaxPartitionIdx"!]
        [!VAR "OsEcucPartitionRef"!][!CALL "GetEcucPartitionRef", "PartitionId" = "$PartitionIdx"!][!ENDVAR!]
[!CODE!]
    [!CALL "GetConfigStructName", "EcucPartitionRef" = "$OsEcucPartitionRef"!][!IF "$PartitionIdx!=$MaxPartitionIdx"!],[!ENDIF!][!//
[!ENDCODE!]
    [!ENDFOR!][!// PartitionIdx
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_ENET_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

[!IF "EthGeneral/EthGeneralVendorSpecific/EthMultiPartitionSupport = 'true'"!]
    [!CALL "GenerateMultiPartitionConfig"!]
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]
        [!CALL "GenerateMultiPartitionPredefinedConfig"!]
    [!ENDIF!]
[!ELSE!]
    [!CALL "GenerateSinglePartitionConfig"!]
[!ENDIF!]
#if defined(ETH_43_ENET_MACSEC_SUPPORT)
#if (STD_ON == ETH_43_ENET_MACSEC_SUPPORT)
[!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!][!//
const Eth_43_ENET_MACsec_ConfigType Eth_43_ENET_xMacSecPredefinedConfig[1U] =
[!ELSE!]
const Eth_43_ENET_MACsec_ConfigType Eth_43_ENET_aMacSecCtrlConfig[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][1U] =
[!ENDIF!]
{
    {
        &Eth_43_ENET_Ipw_aMacSecCtrlConfig[!IF "var:defined('postBuildVariant')"!]_[!"text:toupper($postBuildVariant)"!][!ENDIF!][0U]
    }
};
#endif
#endif
#define ETH_43_ENET_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_ENET_MemMap.h"

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
