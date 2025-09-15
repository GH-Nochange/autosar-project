[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_4_REV_0000_20250530
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

#ifndef QSPI_IP_CFG_H
#define QSPI_IP_CFG_H

/**
 *   @file       Qspi_Ip_Cfg.h
 *
 *   @addtogroup IPV_QSPI QSPI IPV Driver
 *   @implements Qspi_Ip_Cfg.h_Artifact
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
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "Qspi_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "Qspi_Ip_PBcfg.h"
[!ENDIF!][!//
[!//
[!IF "FlsGeneral/FlsEnableDevAssert"!][!//
#include "Devassert.h"
[!ENDIF!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG     4
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG             3
#define QSPI_IP_SW_MINOR_VERSION_CFG             0
#define QSPI_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!// Default value
[!VAR "variantNumber" = "1"!][!//
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantNumber" = "variant:size()"!][!//
[!ENDIF!][!//
[!//
[!FOR "Index" = "1" TO "$variantNumber"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantName" = "concat(variant:all()[num:i($Index)], '_')"!][!//
[!VAR "variantNameUpperCase" = "text:toupper($variantName)"!][!//
[!ENDIF!][!//
/* Check if current file and Qspi_Ip_[!"$variantName"!]PBcfg.h header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_CFG != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID)
    #error "Qspi_Ip_Cfg.h and Qspi_Ip_[!"$variantName"!]PBcfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_[!"$variantName"!]PBcfg.h header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Qspi_Ip_Cfg.h and Qspi_Ip_[!"$variantName"!]PBcfg.h are different"
#endif
/* Check if current file and Qspi_Ip_[!"$variantName"!]PBcfg.h header file are of the same software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_CFG != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION) || \
     (QSPI_IP_SW_MINOR_VERSION_CFG != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION) || \
     (QSPI_IP_SW_PATCH_VERSION_CFG != QSPI_IP_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_Cfg.h and Qspi_Ip_[!"$variantName"!]PBcfg.h are different"
#endif

[!ENDFOR!][!//
[!//
[!IF "FlsGeneral/FlsEnableDevAssert"!][!//
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

[!ENDIF!][!//
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Maximum number of retries for Write Enable command */
#define QSPI_IP_MAX_RETRY                 ([!"FlsGeneral/FlsQspiWriteEnableRetries"!]U)

/* Development error detection for IP API */
#define QSPI_IP_DEV_ERROR_DETECT          ([!IF "FlsGeneral/FlsEnableDevAssert"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "FlsGeneral/FlsEnableDevAssert"!][!//
/* Pre-processor switch to enable/disable development error detection for IP API */
#define QSPI_IP_DEV_ASSERT(x)             DevAssert((x))
[!ENDIF!][!//

/* Number of serial flash devices */
#define QSPI_IP_MEM_INSTANCE_COUNT        ([!"num:i(count(FlsConfigSet/FlsExternalDriver/FlsMem/*))"!]U)


/* Timeout for QSPI command completion */
#define QSPI_IP_CMD_COMPLETE_TIMEOUT      ([!"FlsGeneral/FlsQspiCommandCompleteTimeout"!]U)


/* Timeout for external flash software reset completion */
#define QSPI_IP_RESET_TIMEOUT             ([!"FlsGeneral/FlsQspiResetTimeout"!]U)

/* Timeout for external flash startup initialization sequence completion */
#define QSPI_IP_FLS_INIT_TIMEOUT          ([!"FlsGeneral/FlsQspiFlashInitTimeout"!]U)

/* Timeout for a complete read operation */
#define QSPI_IP_READ_TIMEOUT              ([!"FlsGeneral/FlsQspiSyncReadTimeout"!]U)

/* OsIf counter type used in timeout detection for QSPI IP operations  */
#define QSPI_IP_TIMEOUT_TYPE              ([!"FlsGeneral/FlsQspiIpTimeoutOsifCounterType"!])

/* Delay after changing the value of the QSPI software reset bits */
#define QSPI_IP_SOFTWARE_RESET_DELAY      ([!"FlsGeneral/FlsQspiSoftwareResetDelay"!]U)

/*! @brief Minimum delay in CPU cycles between Tx FIFO reset and Tx FIFO push */
#define QSPI_IP_TX_BUFFER_RESET_DELAY     ([!"FlsGeneral/FlsQspiTxBufferResetDelay"!]U)


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_H */

