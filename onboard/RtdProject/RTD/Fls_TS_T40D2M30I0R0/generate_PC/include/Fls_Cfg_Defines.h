[!NOCODE!][!//

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////

[!MACRO "FeatureGetValue", "FeatureName"!][!//
[!NOCODE!][!//
[!IF "ecu:has($FeatureName)"!][!//
    [!CODE!][!"ecu:get($FeatureName)"!][!ENDCODE!]
[!ELSE!][!//
    [!CODE!]0[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!ENDNOCODE!][!//
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

#ifndef FLS_CFG_DEFINES_H
#define FLS_CFG_DEFINES_H

/**
 *   @file       Fls_Cfg_Defines.h
 *
 *   @addtogroup FLS
 *   @implements Fls_Cfg_Defines.h_Artifact
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


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_DEFINES                    43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define FLS_SW_MAJOR_VERSION_CFG_DEFINES             3
#define FLS_SW_MINOR_VERSION_CFG_DEFINES             0
#define FLS_SW_PATCH_VERSION_CFG_DEFINES             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* STD_ON: Flash access code loaded on job start / unloaded on job end or error */
#define FLS_AC_LOAD_ON_JOB_START             ([!IF "FlsGeneral/FlsAcLoadOnJobStart"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
    /* Cleaning cache after loading access code to RAM */
    #define FLS_CLEAN_CACHE_AFTER_LOAD_AC    ([!IF "FlsGeneral/FlsCleanCacheAfterLoadAc"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/* Enable calculates CRC for items of Fls Configuration */
#define FLS_CHECK_CFG_CRC                    ([!IF "FlsGeneral/FlsEnableCheckCfgCrc"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Cancel function */
#define FLS_CANCEL_API                       ([!IF "FlsGeneral/FlsCancelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Compare function */
#define FLS_COMPARE_API                      ([!IF "FlsGeneral/FlsCompareApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_BlankCheck function */
#define FLS_BLANK_CHECK_API                  ([!IF "FlsGeneral/FlsBlankCheckApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable and disable development error detection */
#define FLS_DEV_ERROR_DETECT                 ([!IF "FlsGeneral/FlsDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetJobResult function */
#define FLS_GET_JOB_RESULT_API               ([!IF "FlsGeneral/FlsGetJobResultApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetStatus function */
#define FLS_GET_STATUS_API                   ([!IF "FlsGeneral/FlsGetStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_SetMode function */
#define FLS_SET_MODE_API                     ([!IF "FlsGeneral/FlsSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define FLS_VERSION_INFO_API                 ([!IF "FlsGeneral/FlsVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to report data storage (ECC) errors to the flash driver */
#define FLS_ECC_CHECK                        ([!IF "FlsGeneral/FlsECCCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define FLS_ECC_CHECK_BY_AUTOSAR_OS          ([!IF "FlsGeneral/FlsECCHandlingProtectionHook"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* External QSPI sectors are present or not in the current configuration. */
#define FLS_QSPI_SECTORS_CONFIGURED          ([!IF "AutosarExt/FlsExternalSectorsConfigured"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
/* Enable the hang recovery feature for the external QuadSPI controller. */
#define FLS_QSPI_HANG_RECOVERY               ([!IF "AutosarExt/FlsQspiHangRecovery"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/* Pre-processor switch to enable / disable the erase blank check */
#define FLS_ERASE_VERIFICATION_ENABLED       ([!IF "FlsGeneral/FlsEraseVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the write verify check */
#define FLS_WRITE_VERIFICATION_ENABLED       ([!IF "FlsGeneral/FlsWriteVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if ((STD_ON == FLS_ERASE_VERIFICATION_ENABLED) && (STD_ON == FLS_QSPI_SECTORS_CONFIGURED))
/* The maximum number of bytes to blank check in one cycle of the flash driver job processing function */
#define FLS_MAX_ERASE_BLANK_CHECK            ([!"FlsGeneral/FlsMaxEraseBlankCheck"!]U)
#endif

/* Timeout handling enabled */
#define FLS_TIMEOUT_SUPERVISION_ENABLED      ([!IF "FlsGeneral/FlsTimeoutSupervisionEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!INDENT "0"!][!//
[!IF "FlsGeneral/FlsTimeoutSupervisionEnabled"!]

#if ((FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) && (FLS_QSPI_SECTORS_CONFIGURED == STD_ON))
/* Timeout value for Erase and Write operation - QSPI flash operations. */
#define FLS_QSPI_SYNC_WRITE_TIMEOUT          ([!"FlsGeneral/FlsQspiSyncWriteTimeout"!]U)
#define FLS_QSPI_SYNC_ERASE_TIMEOUT          ([!"FlsGeneral/FlsQspiSyncEraseTimeout"!]U)
#define FLS_QSPI_ASYNC_WRITE_TIMEOUT         ([!"FlsGeneral/FlsQspiAsyncWriteTimeout"!]U)
#define FLS_QSPI_ASYNC_ERASE_TIMEOUT         ([!"FlsGeneral/FlsQspiAsyncEraseTimeout"!]U)
#endif
[!ENDIF!]
[!ENDINDENT!][!//

/* Internal sectors are present or not in the current configuration. */
#define FLS_INTERNAL_SECTORS_CONFIGURED      ([!IF "AutosarExt/FlsInternalSectorsConfigured"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Base address of code flash */
#define FLS_PROGRAM_FLASH_BASE_ADDR          ([!CALL "FeatureGetValue", "FeatureName"="'Fls.PFlashBaseAddr'"!]UL)
/* Base address of data flash */
#define FLS_DATA_FLASH_BASE_ADDR             ([!CALL "FeatureGetValue", "FeatureName"="'Fls.DFlashBaseAddr'"!]UL)
#
/* Internal flash write register size */
#define FLS_INTERNAL_WRITE_SIZE              ([!CALL "FeatureGetValue", "FeatureName"="'Fls.Internal.WriteSize'"!]UL)

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLS_CFG_DEFINES_H */

