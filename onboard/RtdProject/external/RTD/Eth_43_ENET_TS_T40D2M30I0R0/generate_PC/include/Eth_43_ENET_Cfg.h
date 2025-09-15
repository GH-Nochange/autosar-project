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

#ifndef ETH_43_ENET_CFG_H
#define ETH_43_ENET_CFG_H

/**
*   @file
*   @implements Eth_Cfg.h_Artifact
*   @addtogroup ETH_43_ENET_DRIVER_CONFIGURATION Ethernet Driver Configuration
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
[!CODE!]#include "Eth_43_ENET_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Eth_43_ENET_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "Eth_GeneralTypes.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_ENET_CFG_VENDOR_ID                    43
#define ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_ENET_CFG_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_ENET_CFG_SW_MAJOR_VERSION             3
#define ETH_43_ENET_CFG_SW_MINOR_VERSION             0
#define ETH_43_ENET_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Eth_43_ENET_[!"."!]_PBcfg.h */
#if (ETH_43_ENET_CFG_VENDOR_ID != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_VENDOR_ID)
    #error "Eth_43_ENET_Cfg.h and Eth_43_ENET_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Eth_43_ENET_Cfg.h and Eth_43_ENET_[!"."!]_PBcfg.h are different"
#endif
#if ((ETH_43_ENET_CFG_SW_MAJOR_VERSION != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_CFG_SW_MINOR_VERSION != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_SW_MINOR_VERSION) || \
     (ETH_43_ENET_CFG_SW_PATCH_VERSION != ETH_43_ENET_PBCFG_[!"text:toupper(.)"!]_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Eth_43_ENET_Cfg.h and Eth_43_ENET_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Eth_43_ENET_PBcfg.h */
#if (ETH_43_ENET_CFG_VENDOR_ID != ETH_43_ENET_PBCFG_VENDOR_ID)
    #error "Eth_43_ENET_Cfg.h and Eth_43_ENET_PBcfg.h have different vendor ids"
#endif
#if ((ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION    != ETH_43_ENET_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION    != ETH_43_ENET_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ETH_43_ENET_CFG_AR_RELEASE_REVISION_VERSION != ETH_43_ENET_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Eth_43_ENET_Cfg.h and Eth_43_ENET_PBcfg.h are different"
#endif
#if ((ETH_43_ENET_CFG_SW_MAJOR_VERSION != ETH_43_ENET_PBCFG_SW_MAJOR_VERSION) || \
     (ETH_43_ENET_CFG_SW_MINOR_VERSION != ETH_43_ENET_PBCFG_SW_MINOR_VERSION) || \
     (ETH_43_ENET_CFG_SW_PATCH_VERSION != ETH_43_ENET_PBCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Eth_43_ENET_Cfg.h and Eth_43_ENET_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Eth_GeneralTypes.h */
    #if ((ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION != ETH_GENERALTYPES_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth_43_ENET_Cfg.h and Eth_GeneralTypes.h are different"
    #endif

    /* Checks against Mcal.h */
    #if ((ETH_43_ENET_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_ENET_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AUTOSAR Version Numbers of Eth_43_ENET_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
    [!VAR "DerivativeName" = "''"!]
    [!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
        [!VAR "DerivativeName" = "substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_')"!]
    [!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1))"!]
[!CODE!]#define ETH_43_ENET_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]ETH_43_ENET_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]ETH_43_ENET_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

/*! @brief InstanceId of this module instance. If only one instance is present it shall have the Id 0 */
#define ETH_43_ENET_DRIVER_INSTANCE             ([!"num:i(EthGeneral/EthIndex)"!]U)    /* Instance number assigned to the driver */

/*! @brief Enables / Disables user mode support */
#define ETH_43_ENET_ENABLE_USER_MODE_SUPPORT    ([!IF "EthGeneral/EthGeneralVendorSpecific/EthEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ETH_43_ENET_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ETH in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif /* (STD_ON == ETH_43_ENET_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*! @brief Enables / Disables multi-partition support */
#define ETH_43_ENET_MULTIPARTITION_SUPPORT           ([!IF "EthGeneral/EthGeneralVendorSpecific/EthMultiPartitionSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Number of partitions in the system as defined in EcuC */
#define ETH_43_ENET_MAX_PARTITIONIDX_SUPPORTED       ([!IF "EthGeneral/EthGeneralVendorSpecific/EthMultiPartitionSupport"!][!"num:i(node:fallback("->count(as:modconf('EcuC')/EcucPartitionCollection/*/EcucPartition/*)", 1))"!][!ELSE!]1[!ENDIF!]U)

/*! @brief Enables / Disables PreCompile support when there is a single configuration */
#define ETH_43_ENET_PRECOMPILE_SUPPORT          ([!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables DET development errors detection and reporting
*   implements EthDevErrorDetect_object */
#define ETH_43_ENET_DEV_ERROR_DETECT            ([!IF "EthGeneral/EthDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables DEM events detection and reporting */
#define ETH_43_ENET_DEM_EVENT_DETECT            ([!IF "EthGeneral/EthGeneralVendorSpecific/EthDisableDemEventDetect"!]STD_OFF[!ELSE!]STD_ON[!ENDIF!])

/*! @brief Enables / Disables hardware offloading for IPv4 checksums */
#define ETH_43_ENET_ENABLE_OFFLOAD_CRC_IPV4     ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumIPv4"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables hardware offloading for ICMP checksums */
#define ETH_43_ENET_ENABLE_OFFLOAD_CRC_ICMP     ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumICMP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables hardware offloading for TCP checksums */
#define ETH_43_ENET_ENABLE_OFFLOAD_CRC_TCP      ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumTCP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables hardware offloading for UDP checksums */
#define ETH_43_ENET_ENABLE_OFFLOAD_CRC_UDP      ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumUDP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables hardware offloading for checksums */
#define ETH_43_ENET_ENABLE_OFFLOAD_CRC          ([!IF "node:containsValue(EthGeneral/EthCtrlOffloading/*, 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables the Switch Management APIs */
#define ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API  ([!IF "EthGeneral/EthGeneralVendorSpecific/EthSwtManagementSupportApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_GetVersionInfo API */
#define ETH_43_ENET_VERSION_INFO_API            ([!IF "EthGeneral/EthVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_UpdatePhysAddrFilter API */
#define ETH_43_ENET_UPDATE_PHYS_ADDR_FILTER_API ([!IF "EthGeneral/EthGeneralVendorSpecific/EthUpdatePhysAddrFilterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_GetCounterValues API */
#define ETH_43_ENET_GET_COUNTER_API             ([!IF "EthGeneral/EthGetCounterValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_GetTxStats API */
#define ETH_43_ENET_GET_TXSTATS_API             ([!IF "EthGeneral/EthGetTxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_GetRxStats API */
#define ETH_43_ENET_GET_RXSTATS_API             ([!IF "EthGeneral/EthGetRxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables Eth_43_ENET_GetTxErrorCounterValues API */
#define ETH_43_ENET_GET_TXERROR_COUNTER_API     ([!IF "EthGeneral/EthGetTxErrorCounterValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables the GlobalTime APIs used amongst others by Global Time Synchronization over Ethernet */
#define ETH_43_ENET_GLOBAL_TIME_API             ([!IF "EthGeneral/EthGlobalTimeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables the Eth_43_ENET_SendMultiBufferFrame API */
#define ETH_43_ENET_SEND_MULTI_BUFFER_FRAME_API ([!IF "EthGeneral/EthSendMultiBufferFrameApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*! @brief Enables / Disables the Eth_43_ENET_GetSyncState API */
[!IF "node:exists(EthGeneral/EthGetSyncStateApi)"!][!//
#define ETH_43_ENET_GET_SYNC_STATE_API             ([!IF "EthGeneral/EthGetSyncStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_GET_SYNC_STATE_API             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables Eth_43_ENET_EthSetSiPhysAddr API */
[!IF "node:exists(EthGeneral/EthSetSiPhysAddrApi)"!][!//
#define ETH_43_ENET_SET_SI_PHYS_ADDR_API             ([!IF "EthGeneral/EthSetSiPhysAddrApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_SET_SI_PHYS_ADDR_API             (STD_OFF)
[!ENDIF!][!//

/*! @brief The maximum number of buffers that can be used for constructing a multi buffer frame */
#define ETH_43_ENET_MAX_BUFFS_IN_MULTI_BUFFER_FRAME ([!"num:i(EthGeneral/EthMaxBuffersInMultiBufferFrame)"!]U)

/* PreCompile parameters residing in container EthCtrlConfig which has attribute postBuildVariantMultiplicity = true */
#ifndef ETH_43_ENET_MDIO_CLAUSE22_API    /* Will eventually be defined in Eth_43_ENET_<PBVName>_PBcfg.h */
  /*! @brief Enables / Disables Management Data I/O (MDIO) Clause 22for transceiver accesses */
  #define ETH_43_ENET_MDIO_CLAUSE22_API         (STD_OFF)
#endif

#ifndef ETH_43_ENET_MDIO_CLAUSE45_API    /* Will eventually be defined in Eth_43_ENET_<PBVName>_PBcfg.h */
  /*! @brief Enables / Disables Management Data I/O (MDIO) Clause45 for transceiver accesses */
  #define ETH_43_ENET_MDIO_CLAUSE45_API         (STD_OFF)
#endif

#ifndef ETH_43_ENET_RX_IRQ_ENABLED    /* Will eventually be defined in Eth_43_ENET_<PBVName>_PBcfg.h */
  /*! @brief Enables / Disables channel interrupts on Rx */
  #define ETH_43_ENET_RX_IRQ_ENABLED            (STD_OFF)
#endif

#ifndef ETH_43_ENET_TX_IRQ_ENABLED    /* Will eventually be defined in Eth_43_ENET_<PBVName>_PBcfg.h */
  /*! @brief Enables / Disables channel interrupts on Tx */
  #define ETH_43_ENET_TX_IRQ_ENABLED            (STD_OFF)
#endif

/*! @brief Number of controllers configured by the driver */
#define ETH_43_ENET_MAX_CTRLIDX_SUPPORTED       ([!"num:i(EthGeneral/EthMaxCtrlsSupported)"!]U)     /* Maximum configured controller hardware index + 1 (might be different from the total number of hardware controllers available on the platform) */

/*! @brief Number of VLAN Priority Code Points */
#define ETH_43_ENET_MAX_VLAN_PCP                (8U)
[!NOCODE!]
[!VAR "FeatureControllerHasTXExternalBufferEnabled" = "''"!][!//
[!VAR "FeatureControllerHasRXExternalBufferEnabled" = "''"!][!//
[!VAR "FeatureDriverHasTXExternalBufferEnabled" = "'(STD_OFF)'"!]
[!VAR "FeatureDriverHasRXExternalBufferEnabled" = "'(STD_OFF)'"!]
[!VAR "FeatureControllerHasTXExternalBufferEnabled" = "concat('{', text:join(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateTxDataBuffers, ','), '}')"!]
[!VAR "FeatureControllerHasRXExternalBufferEnabled" = "concat('{', text:join(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlAllocateRxDataBuffers, ','), '}')"!]
[!IF "contains($FeatureControllerHasTXExternalBufferEnabled, 'false')"!][!//
    [!VAR "FeatureDriverHasTXExternalBufferEnabled" = "'(STD_ON)'"!][!//
[!ENDIF!][!//
[!IF "contains($FeatureControllerHasRXExternalBufferEnabled, 'false')"!][!//
    [!VAR "FeatureDriverHasRXExternalBufferEnabled" = "'(STD_ON)'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*! @brief Enables/Disables internal allocation of Tx Data Buffers */
#define ETH_43_ENET_HAS_EXTERNAL_TX_BUFFERS  [!"$FeatureDriverHasTXExternalBufferEnabled"!]

/*! @brief Enables/Disables internal allocation of Rx Data Buffers */
#define ETH_43_ENET_HAS_EXTERNAL_RX_BUFFERS  [!"$FeatureDriverHasRXExternalBufferEnabled"!]

[!NOCODE!]
[!VAR "FeatureControllerEnableRxReleaseResource" = "'{'"!][!//
[!VAR "FeatureControllerEnableRxReleaseResource" = "concat('{', text:join(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthCtrlReleaseResourceAfterReception, ','), '}')"!]
[!VAR "FeatureControllerEnableRxReleaseResource" = "text:replaceAll($FeatureControllerEnableRxReleaseResource, 'false', '(boolean) FALSE')"!]
[!VAR "FeatureControllerEnableRxReleaseResource" = "text:replaceAll($FeatureControllerEnableRxReleaseResource, 'true', '(boolean) TRUE')"!]
[!ENDNOCODE!]

#if (STD_ON == ETH_43_ENET_HAS_EXTERNAL_RX_BUFFERS)
/*! @brief Array of the feature of releasing resource after reception indexed at controller level */
    #define ETH_43_ENET_INST_ENABLE_RELEASE_RESOURCE_AFTER_RECEPTION  [!"$FeatureControllerEnableRxReleaseResource"!]
#endif

/*! @brief Enables / Disables Time Aware Shaper */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthTimeAwareShaper)"!][!//
#define ETH_43_ENET_TIME_AWARE_SHAPER             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthTimeAwareShaper"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_TIME_AWARE_SHAPER             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables Ingress Port Filter */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthIngressPortFilter)"!][!//
#define ETH_43_ENET_INGRESS_PORT_FILTER             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthIngressPortFilter"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_INGRESS_PORT_FILTER             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables TX/RX coalescing interrupt */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthCoalescingInterrupt)"!][!//
#define ETH_43_ENET_COALESCING_INTERRUPT             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthCoalescingInterrupt"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_COALESCING_INTERRUPT             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables Mac Sec Integration */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthEnableMACsec)"!][!//
#define ETH_43_ENET_MACSEC_SUPPORT             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthEnableMACsec"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_MACSEC_SUPPORT             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables Pulse-per-second signal outputs. */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthPPSOutputSupport)"!][!//
#define ETH_43_ENET_PPS_OUTPUT_SUPPORT             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthPPSOutputSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_PPS_OUTPUT_SUPPORT             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables Low Power Idle (LPI) mode */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthLPIModeEnable)"!][!//
#define ETH_43_ENET_LPI_ENABLE             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthLPIModeEnable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_LPI_ENABLE             (STD_OFF)
[!ENDIF!][!//

/*! @brief Enables / Disables the configuration of StartTSN API. */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthStartTSNSupport)"!][!//
#define ETH_43_ENET_START_TSN_SUPPORT             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthStartTSNSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_START_TSN_SUPPORT             (STD_OFF)
[!ENDIF!][!//

[!IF "contains($DerivativeName, 's32n')"!][!//
/*! @brief Enables / Disables access to APIs to get fill levels of Tx/Rx rings. */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthRingFillLevelApiSupport)"!][!//
#define ETH_43_ENET_FILL_LEVEL_API_ENABLE             ([!IF "EthGeneral/EthGeneralVendorSpecific/EthRingFillLevelApiSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//
[!ENDIF!][!//

#if (STD_ON == ETH_43_ENET_HAS_EXTERNAL_RX_BUFFERS)
/*! @brief Enables/Disables provide Rx buffer information with split header feature enabled. */
[!IF "node:exists(EthGeneral/EthGeneralVendorSpecific/EthRxHeaderSplit)"!][!//
#define ETH_43_ENET_PROVIDE_RXBUFFER_INFO_WITH_HEADER_SPLIT     ([!IF "EthGeneral/EthGeneralVendorSpecific/EthRxHeaderSplit"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
#define ETH_43_ENET_PROVIDE_RXBUFFER_INFO_WITH_HEADER_SPLIT     (STD_OFF)
[!ENDIF!][!//
#endif

#if (STD_ON == ETH_43_ENET_MACSEC_SUPPORT)
[!NOCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1))"!]
[!CODE!]#define MACSEC_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]MACSEC_CONFIG_[!"text:toupper(.)"!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!CODE!][!CR!][!ENDCODE!]
[!ELSE!][!//
    [!CODE!][!WS "4"!]MACSEC_CONFIG_PB[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
#endif

/* DET error codes */
#if STD_ON == ETH_43_ENET_DEV_ERROR_DETECT
    /*! @brief Development Error ID for "Invalid Controller Index" */
    /* implements Eth_DetErrorIds_define */
    #define ETH_43_ENET_E_INV_CTRL_IDX      ((uint8)0x01)
    /*! @brief Development Error ID for "Uninitialized Ethernet Controller" */
    #define ETH_43_ENET_E_UNINIT            ((uint8)0x02)
    /*! @brief Development Error ID for "Invalid (Null) Pointer Parameter" */
    #define ETH_43_ENET_E_PARAM_POINTER     ((uint8)0x03)
    /*! @brief Development Error ID for "Invalid Parameter" */
    #define ETH_43_ENET_E_INV_PARAM         ((uint8)0x04)
    /*! @brief Development Error ID for "Invalid Controller Mode" */
    #define ETH_43_ENET_E_INV_MODE          ((uint8)0x05)
    /*! @brief Development Error ID for "Invalid Partition ID" */
    #if (STD_ON == ETH_43_ENET_MULTIPARTITION_SUPPORT)
        #define ETH_43_ENET_E_PARAM_CONFIG      ((uint8)0x07)
    #endif
    /*! @brief Development Error ID for "Invalid Configuration pointer argument" */
    #define ETH_43_ENET_E_INIT_FAILED       ((uint8)0x08)
#endif

    /*! @brief Runtime Error ID for "Failure or incorrect communication with the Ethernet Controller" */
    #define ETH_43_ENET_E_COMMUNICATION       ((uint8)0x06)



/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (STD_ON == ETH_43_ENET_PPS_OUTPUT_SUPPORT)
/*!
 * @brief The PPS output commands.
 *
 */
typedef enum {
    ETH_43_ENET_NO_COMMAND                    = 0U,
    ETH_43_ENET_START_SINGLE_PULSE            = 1U,
    ETH_43_ENET_START_PULSE_TRAIN             = 2U,
    ETH_43_ENET_CANCEL_START                  = 3U,
    ETH_43_ENET_STOP_PULSE_TRAIN_AT_TIME      = 4U,
    ETH_43_ENET_STOP_PULSE_TRAIN_IMMEDIATELY  = 5U,
    ETH_43_ENET_CANCEL_STOP_PULSE_TRAIN       = 6U,
} Eth_43_ENET_PPSOutputCmd;
#endif /* STD_ON == ETH_43_ENET_PPS_OUTPUT_SUPPORT */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
[!NOCODE!]
    [!IF "contains($DerivativeName, 's32z') or contains($DerivativeName, 's32e')"!]
        [!CODE!][!WS "4"!]uint32 BufferCount;    /* Total number of buffers across all Tx FIFOs */[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!][!WS "4"!]uint16 BufferCount;    /* Total number of buffers across all Tx FIFOs */[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]
    uint8 FifoCount;        /* Total number of configured Tx FIFOs */
    uint8 VlanPcpToFifoIdx[ETH_43_ENET_MAX_VLAN_PCP];   /* Map between VLAN PCPs and Tx FIFOs */

} Eth_43_ENET_EgressCfgType;

typedef struct
{
[!NOCODE!]
    [!IF "contains($DerivativeName, 's32z') or contains($DerivativeName, 's32e')"!]
        [!CODE!][!WS "4"!]uint32 BufferCount;    /* Total number of buffers across all Rx FIFOs */[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!][!WS "4"!]uint16 BufferCount;    /* Total number of buffers across all Rx FIFOs */[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]
    uint8 FifoCount;        /* Total number of configured Rx FIFOs */

} Eth_43_ENET_IngressCfgType;

typedef struct
{
[!NOCODE!]
    [!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!// 
        [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!][!//
            [!CODE!][!WS "4"!]uint32 ModuleClock;                 /* Frequency of the application interface (in Hz) */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]uint32 TimeStampClockPeriodPs;      /* Number of picoseconds in a PTP clock period */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]uint32 TimeStampReqClockPeriodNs;   /* Number of nanoseconds in a PTP clock period for the required accuracy */[!CR!][!ENDCODE!]
        [!ELSE!]
            [!CODE!][!WS "4"!]uint32 ModuleClock;                 /* Frequency of the application interface (in Hz) */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]uint8 SubSecondInc;                 /* Default value for SSINC register. */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]uint8 SubNanoSecondsInc;            /* Default value for SNSINC register. */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]float64 MultiplyRatioCompensation;  /* Multiply ratio for computation of new value for TSAR register. */[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDNOCODE!]
} Eth_43_ENET_ClockCfgType;

#if STD_ON == ETH_43_ENET_DEM_EVENT_DETECT
/**
 * @brief    Type for holding DEM events
 * @details  It contains the necessary events to report to the DEM module
 */
typedef struct
{
    Mcal_DemErrorType ETH_E_ACCESS_Cfg;
    Mcal_DemErrorType ETH_E_RX_FRAMES_LOST_Cfg;
    Mcal_DemErrorType ETH_E_CRC_Cfg;
    Mcal_DemErrorType ETH_E_UNDERSIZEFRAME_Cfg;
    Mcal_DemErrorType ETH_E_OVERSIZEFRAME_Cfg;
    Mcal_DemErrorType ETH_E_ALIGNMENT_Cfg;
    Mcal_DemErrorType ETH_E_SINGLECOLLISION_Cfg;
    Mcal_DemErrorType ETH_E_MULTIPLECOLLISION_Cfg;
    Mcal_DemErrorType ETH_E_LATECOLLISION_Cfg;

} Eth_43_ENET_DemEventsType;
#endif

#if STD_ON == ETH_43_ENET_DEM_EVENT_DETECT
/**
 * @brief    Type for enumerating DEM error IDs
 * @details  It contains a mapping between DEM events to error IDs
 */
typedef enum
{
    ETH_E_ACCESS            = 0U,
    ETH_E_RX_FRAMES_LOST    = 1U,
    ETH_E_CRC               = 2U,
    ETH_E_UNDERSIZEFRAME    = 3U,
    ETH_E_OVERSIZEFRAME     = 4U,
    ETH_E_ALIGNMENT         = 5U,
    ETH_E_SINGLECOLLISION   = 6U,
    ETH_E_MULTIPLECOLLISION = 7U,
    ETH_E_LATECOLLISION     = 8U,
    ETH_NUMBER_OF_DEM_IDS   = 9U

} Eth_43_ENET_DemErrorIdType;
#endif


#if (STD_ON == ETH_43_ENET_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_ENET_MDIO_CLAUSE45_API)
/**
 * @brief    Type for holding function pointers to the EthTrcv
 * @details  It contains the needed function pointers to EthTrcv functions.
 */
typedef struct
{
    void (*readMiiIndicationFunction)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegValPtr);
    void (*writeMiiIndicationFunction)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx);

}Eth_43_ENET_EthTrcvFunctionsType;
#endif


#if STD_ON == ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API
/**
 * @brief    Type for holding function pointers to the EthSwt
 * @details  It contains the needed function pointers to EthSwt functions.
 */
typedef struct
{
    void (*TxAdaptBufferLengthFunction)(uint16* LengthPtr);
    Std_ReturnType (*TxPrepareFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr);
    Std_ReturnType (*TxProcessFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr);
    Std_ReturnType (*TxFinishedIndicationFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx);
    Std_ReturnType (*RxProcessFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr, boolean* IsMgmtFrameOnlyPtr);
    Std_ReturnType (*RxFinishedIndicationFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx);

}Eth_43_ENET_EthSwtFunctionsType;
#endif

/* Forward IPW structure declarations */
struct sEth_43_ENET_Ipw_CtrlConfigType;

#if (STD_ON == ETH_43_ENET_PPS_OUTPUT_SUPPORT)
/**
* @brief         Type used to express Pulse-per-second target time.
* @details       Variables of this type are used to express Pulse-per-second target time.
*
*/
typedef struct
{
    uint32 nanoseconds;  /*!< Nanoseconds part of the time. */
    uint32 seconds;      /*!< Seconds part of the time. */
} Eth_43_ENET_PPSTargetTime;

/**
* @brief         Type used to express configured parameter of Pulse-per-second configuration.
* @details       Variables of this type are used to express Pulse-per-second target time.
*
*/
typedef struct
{
    Eth_43_ENET_PPSOutputCmd PPSOutputCmd;        /*!< The PPS output commands */
    Eth_43_ENET_PPSTargetTime PPSTargetTime;      /*!< The PPS target time */
} Eth_43_ENET_PPSConfigType;
#endif /* STD_ON == ETH_43_ENET_PPS_OUTPUT_SUPPORT */

/**
* @brief         Type for Ethernet driver configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
*/
typedef struct
{
    const struct sEth_43_ENET_Ipw_CtrlConfigType *Eth_43_ENET_pIpwCtrlConfig;
    const Eth_43_ENET_EgressCfgType *Eth_43_ENET_pEgressConfig;
    const Eth_43_ENET_IngressCfgType *Eth_43_ENET_pIngressConfig;
    const Eth_43_ENET_ClockCfgType *Eth_43_ENET_pClockConfig;
    const uint8 EthCtrlEthIfIdx;    /**< @brief Index of the controller in context of EthIf driver */
    const uint8 EthCtrlIdx;    /**< @brief Index of the controller */
#if (STD_ON == ETH_43_ENET_DEM_EVENT_DETECT)
    const Eth_43_ENET_DemEventsType Eth_43_ENET_DemEventsList;
#endif
#if (STD_ON == ETH_43_ENET_MDIO_CLAUSE22_API) || (STD_ON == ETH_43_ENET_MDIO_CLAUSE45_API)
    const Eth_43_ENET_EthTrcvFunctionsType Eth_43_ENET_EthTrcvDriverFunctionList;  /**< @brief The structure with pointer functions to the EthTrcv driver functions */
#endif
#if STD_ON == ETH_43_ENET_SWT_MANAGEMENT_SUPPORT_API
    const Eth_43_ENET_EthSwtFunctionsType Eth_43_ENET_EthSwtDriverFunctionList; /**< @brief The structure with pointer functions to the EthSwt driver functions */
#endif

} Eth_43_ENET_CtrlCfgType;

/**
* @brief This type is used to group all multiple configurations.
* implements Eth_ConfigType_structure
*/
typedef struct
{
#if (STD_ON == ETH_43_ENET_MULTIPARTITION_SUPPORT)
    uint32 PartitionId;
#endif
    const Eth_43_ENET_CtrlCfgType *Eth_43_ENET_apCtrlConfig[ETH_43_ENET_MAX_CTRLIDX_SUPPORTED];

} Eth_43_ENET_ConfigType;

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

#endif /* ETH_43_ENET_CFG_H */

