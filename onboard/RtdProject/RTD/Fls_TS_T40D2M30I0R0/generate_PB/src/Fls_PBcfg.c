[!NOCODE!][!//
[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!////////////////////////   VARIABLE DEFINE FOR EB TRESOS       ///////////////////////////////////
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantName" = "concat($postBuildVariant, '_')"!][!//
    [!VAR "variantNameUpperCase" = "text:toupper($variantName)"!][!//
[!ENDIF!][!//

[!//////////////////////////////////////////////////////////////////////////////////////////////////
[!///////////////////////    FUNCTION (MACRO) FOR EB TRESOS      ///////////////////////////////////


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

/**
 *   @file       Fls_[!"$variantName"!]PBcfg.c
 *
 *   @addtogroup FLS
 *   @implements Fls_PBcfg.c_Artifact
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
#include "Fls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID_CFG_C                      43
#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION_CFG_C               3
#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION_CFG_C               0
#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_[!"$variantName"!]PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID_CFG_C != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION_CFG_C != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION_CFG_C != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION_CFG_C != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_[!"$variantName"!]PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
[!INCLUDE "Fls_VersionCheck.m"!][!//

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
[!INDENT "0"!][!//
[!IF "node:exists(FlsConfigSet/FlsReadFunctionCallout) or node:exists(FlsConfigSet/FlsJobEndNotification) or node:exists(FlsConfigSet/FlsJobErrorNotification) or node:exists(FlsConfigSet/FlsMCoreTimeoutNotification) or node:exists(FlsConfigSet/FlsACCallback)"!][!//
    #define FLS_START_SEC_CODE
    #include "Fls_MemMap.h"

    [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsJobEndNotification | FlsConfigSet/FlsJobErrorNotification | FlsConfigSet/FlsACCallback))))"!][!//
        /* Declaration of Fls notification function ([!"."!]())*/
        extern void [!"."!]( void );

    [!ENDLOOP!][!//
    [!IF "(FlsGeneral/FlsECCHandlingProtectionHook = 'true') and node:exists(FlsConfigSet/FlsReadFunctionCallout)"!][!//
        /* Declaration of Fls read callout function */
        extern void [!"FlsConfigSet/FlsReadFunctionCallout"!]( void );

    [!ENDIF!][!//
    #define FLS_STOP_SEC_CODE
    #include "Fls_MemMap.h"
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/
[!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!][!//
    [!IF "count(text:grep(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer, '^(\s*NULL_PTR\s*)|(\s*NULL\s*)$')) != count(FlsConfigSet) * 2"!][!//
        [!INDENT "0"!][!//
        #define FLS_START_SEC_CODE
        #include "Fls_MemMap.h"

        [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer))))"!][!//
            [!IF ". != 'NULL_PTR' and . != 'NULL'"!][!//
                /* Declaration of Fls Access Code Pointer ([!"."!])*/
                extern void [!"."!](void);

            [!ENDIF!][!//
        [!ENDLOOP!][!//
        #define FLS_STOP_SEC_CODE
        #include "Fls_MemMap.h"
        [!ENDINDENT!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "FlsQspiHyperflashEnVar" = "'false'"!][!//
[!IF "//AutosarExt/FlsQspiHyperflashEnable ='true'"!][!//
    [!VAR "FlsQspiHyperflashEnVar" = "'true'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('FLS_CFG_GENERIC_MACROS_M4'))"!][!//
[!NOCODE!][!//
    [!VAR "FLS_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsAccCrc","FlsData32"!][!//
    [!NOCODE!][!//
    [!IF "65535 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:shr($FlsData32,16))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDIF!][!//
    [!IF "255 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:and($FlsData32,65535))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ELSE!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,8),bit:and($FlsData32,255))"!][!//
        [!CALL "FlsCalcCrcRemainder8bit"!][!//
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsFinishCrc"!][!//
    [!NOCODE!][!//
        [!VAR "FlsCrcReminder" = "bit:shl($FlsCrcReminder,16)"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder16bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$FlsCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder8bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
        [!VAR "Rem8LeadingOne" = "8388608"!][!//
        [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem8LeadingOne,$FlsCrcReminder) = $Rem8LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem8CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
            [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetSectorHwCh","FlsHwChName"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsHwChName" = "4294967295"!][!//
        [!IF "$FlsHwChName='FLS_CH_INTERN'"!][!//
            [!VAR "OutFlsHwChName" = "0"!][!//
        [!ELSEIF "$FlsHwChName='FLS_CH_QSPI'"!][!//
            [!VAR "OutFlsHwChName" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsHwChName" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetHwUnitName","FlsHwUnitName"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsHwUnitName" = "4294967295"!][!//
        [!IF "$FlsHwUnitName='FLS_QSPI_0'"!][!//
            [!VAR "OutFlsHwUnitName" = "0"!][!//
        [!ELSEIF "$FlsHwUnitName='FLS_QSPI_1'"!][!//
            [!VAR "OutFlsHwUnitName" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsHwUnitName" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiReadMode","FlsQspiReadMode"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiReadMode" = "4294967295"!][!//
        [!IF "$FlsQspiReadMode='FLS_SDR'"!][!//
            [!VAR "OutFlsQspiReadMode" = "0"!][!//
        [!ELSEIF "$FlsQspiReadMode='FLS_DDR'"!][!//
            [!VAR "OutFlsQspiReadMode" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiReadMode" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingMode","FlsQspiSamplingMode"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiSamplingMode" = "4294967295"!][!//
        [!IF "$FlsQspiSamplingMode='FLS_INTERNAL_DQS'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingMode='FLS_EXTERNAL_DQS'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "1"!][!//
        [!ELSEIF "$FlsQspiSamplingMode='FLS_INTERNAL_4X'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "2"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiSamplingMode" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingEdge","FlsQspiSamplingEdge"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiSamplingEdge" = "4294967295"!][!//
        [!IF "$FlsQspiSamplingEdge='FLS_RISING'"!][!//
            [!VAR "OutFlsQspiSamplingEdge" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingEdge='FLS_FALLING'"!][!//
            [!VAR "OutFlsQspiSamplingEdge" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiSamplingEdge" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingDly","FlsQspiSamplingDly"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiSamplingDly" = "4294967295"!][!//
        [!IF "$FlsQspiSamplingDly='FLS_1SAMPLE_DLY'"!][!//
            [!VAR "OutFlsQspiSamplingDly" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingDly='FLS_2SAMPLE_DLY'"!][!//
            [!VAR "OutFlsQspiSamplingDly" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiSamplingDly" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiIntDqsRefClk","FlsQspiIntDqsRefClk"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiIntDqsRefClk" = "4294967295"!][!//
        [!IF "$FlsQspiIntDqsRefClk='FLS_INVERTED_CLK'"!][!//
            [!VAR "OutFlsQspiIntDqsRefClk" = "0"!][!//
        [!ELSEIF "$FlsQspiIntDqsRefClk='FLS_NONINVERTED_CLK'"!][!//
            [!VAR "OutFlsQspiIntDqsRefClk" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiIntDqsRefClk" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiCoarseDly","FlsQspiCoarseDly"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiCoarseDly" = "4294967295"!][!//
        [!IF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_0'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "0"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1_PER_2'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "2"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "3"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "4"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_3_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "5"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_3_PER_2'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "6"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_5_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "7"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiCoarseDly" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiTdh","FlsQspiTdh"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiTdh" = "4294967295"!][!//
        [!IF "$FlsQspiTdh='FLS_ALIGNED_INT_REF_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "0"!][!//
        [!ELSEIF "$FlsQspiTdh='FLS_ALIGNED_2X_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "1"!][!//
        [!ELSEIF "$FlsQspiTdh='FLS_ALIGNED_4X_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "2"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiTdh" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiEndian","FlsQspiEndian"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiEndian" = "4294967295"!][!//
        [!IF "$FlsQspiEndian='FLS_BIG_ENDIAN_64'"!][!//
            [!VAR "OutFlsQspiEndian" = "0"!][!//
        [!ELSEIF "$FlsQspiEndian='FLS_LITTLE_ENDIAN_32'"!][!//
            [!VAR "OutFlsQspiEndian" = "1"!][!//
        [!ELSEIF "$FlsQspiEndian='FLS_BIG_ENDIAN_32'"!][!//
            [!VAR "OutFlsQspiEndian" = "2"!][!//
        [!ELSEIF "$FlsQspiEndian='FLS_LITTLE_ENDIAN_64'"!][!//
            [!VAR "OutFlsQspiEndian" = "3"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiEndian" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiReadBufferMode","FlsQspiReadBufferMode"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiReadBufferMode" = "4294967295"!][!//
        [!IF "$FlsQspiReadBufferMode='FLS_AHB_READ_MODE'"!][!//
            [!VAR "OutFlsQspiReadBufferMode" = "0"!][!//
        [!ELSEIF "$FlsQspiReadBufferMode='FLS_IP_READ_MODE'"!][!//
            [!VAR "OutFlsQspiReadBufferMode" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiReadBufferMode" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiRxBufferAccessMode","FlsQspiRxBufferAccessMode"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiRxBufferAccessMode" = "4294967295"!][!//
        [!IF "$FlsQspiRxBufferAccessMode='FLS_RXBUFFER_AHB_BUS_ACCESS'"!][!//
            [!VAR "OutFlsQspiRxBufferAccessMode" = "0"!][!//
        [!ELSEIF "$FlsQspiRxBufferAccessMode='FLS_RXBUFFER_IP_BUS_ACCESS'"!][!//
            [!VAR "OutFlsQspiRxBufferAccessMode" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiRxBufferAccessMode" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiAhbBufferInstance","FlsQspiAhbBufferInstance"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsQspiAhbBufferInstance" = "4294967295"!][!//
        [!IF "$FlsQspiAhbBufferInstance='AHB_BUFFER_0'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "0"!][!//
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_1'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "1"!][!//
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_2'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "2"!][!//
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_3'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "3"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTInstruction","FlsLUTInstruction"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsLUTInstruction" = "4294967295"!][!//
        [!IF "$FlsLUTInstruction='FLS_LUT_INSTR_STOP'"!][!//
            [!VAR "OutFlsLUTInstruction" = "0"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CMD'"!][!//
            [!VAR "OutFlsLUTInstruction" = "1"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_ADDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "2"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_DUMMY'"!][!//
            [!VAR "OutFlsLUTInstruction" = "3"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE'"!][!//
            [!VAR "OutFlsLUTInstruction" = "4"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE2'"!][!//
            [!VAR "OutFlsLUTInstruction" = "5"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE4'"!][!//
            [!VAR "OutFlsLUTInstruction" = "6"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_READ'"!][!//
            [!VAR "OutFlsLUTInstruction" = "7"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_WRITE'"!][!//
            [!VAR "OutFlsLUTInstruction" = "8"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_JMP_ON_CS'"!][!//
            [!VAR "OutFlsLUTInstruction" = "9"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_ADDR_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "10"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "11"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE2_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "12"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE4_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "13"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_READ_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "14"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_WRITE_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "15"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_DATA_LEARN'"!][!//
            [!VAR "OutFlsLUTInstruction" = "16"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CMD_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "17"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CADDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "18"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CADDR_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "19"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsLUTInstruction" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTPad","FlsLUTPad"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsLUTPad" = "4294967295"!][!//
        [!IF "$FlsLUTPad='FLS_LUT_PAD_1_PAD'"!][!//
            [!VAR "OutFlsLUTPad" = "0"!][!//
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_2_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "1"!][!//
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_4_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "2"!][!//
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_8_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "3"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsLUTPad" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetIpSide","QspiIpSide"!][!//
    [!NOCODE!][!//
        [!VAR "OutQspiIpSide" = "4294967295"!][!//
        [!IF "$QspiIpSide='QSPI_IP_SIDE_A1'"!][!//
            [!VAR "OutQspiIpSide" = "0"!][!//
        [!ELSEIF "$QspiIpSide='QSPI_IP_SIDE_A2'"!][!//
            [!VAR "OutQspiIpSide" = "1"!][!//
        [!ELSEIF "$QspiIpSide='QSPI_IP_SIDE_B1'"!][!//
            [!VAR "OutQspiIpSide" = "2"!][!//
        [!ELSEIF "$QspiIpSide='QSPI_IP_SIDE_B2'"!][!//
            [!VAR "OutQspiIpSide" = "3"!][!//
        [!ELSE!][!//
            [!VAR "OutQspiIpSide" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsAccCrc_LutIndex", "SeqNo" = "0"!]
    [!NOCODE!][!//
        [!IF "node:exists($SeqNo)"!]
            [!VAR "FlsLutIdx" = "0"!][!//
            [!VAR "FlsLutSelect" = "node:ref($SeqNo)/FlsLUTIndex"!][!//
            [!LOOP "node:order(./FlsLUT/*, 'node:value(./FlsLUTIndex)')"!][!// Iterate through the Fls LUT Index
                [!IF "$FlsLutSelect <= node:value(./FlsLUTIndex)"!][!BREAK!][!ENDIF!]
                [!VAR "FlsLutIdx" = "$FlsLutIdx + count(./FlsInstructionOperandPair/*) + 1"!][!//
            [!ENDLOOP!][!//
        [!ELSE!]
            [!VAR "FlsLutIdx" = "65535"!][!//
        [!ENDIF!]
        [!CALL "FlsAccCrc","FlsData32"="$FlsLutIdx"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!]
    [!//
    [!//
    [!MACRO "FlsAccCrc_LutIndex_Op", "SeqNo" = "0"!]
    [!NOCODE!][!//
        [!IF "node:exists($SeqNo)"!]
            [!VAR "FlsLutIdx" = "0"!][!//
            [!VAR "FlsLutSelect" = "node:ref($SeqNo)/FlsLUTIndex"!][!//
            [!LOOP "node:order(../../FlsLUT/*, 'node:value(./FlsLUTIndex)')"!][!// Iterate through the Fls LUT Index
                [!IF "$FlsLutSelect <= node:value(./FlsLUTIndex)"!][!BREAK!][!ENDIF!]
                [!VAR "FlsLutIdx" = "$FlsLutIdx + count(./FlsInstructionOperandPair/*) + 1"!][!//
            [!ENDLOOP!][!//
        [!ELSE!]
            [!VAR "FlsLutIdx" = "65535"!][!//
        [!ENDIF!]
        [!CALL "FlsAccCrc","FlsData32"="$FlsLutIdx"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!]
    [!//
    [!//
    [!MACRO "QspiGetReadMode","ReadMode"!][!//
    [!NOCODE!][!//
        [!VAR "OutReadMode" = "4294967295"!][!//
        [!IF "$ReadMode='QSPI_IP_READ_MODE_INTERNAL_DQS'"!][!//
            [!VAR "OutReadMode" = "0"!][!//
        [!ELSEIF "$ReadMode='QSPI_IP_READ_MODE_LOOPBACK'"!][!//
            [!VAR "OutReadMode" = "1"!][!//
        [!ELSEIF "$ReadMode='QSPI_IP_READ_MODE_LOOPBACK_DQS'"!][!//
            [!VAR "OutReadMode" = "2"!][!//
        [!ELSEIF "$ReadMode='QSPI_IP_READ_MODE_EXTERNAL_DQS'"!][!//
            [!VAR "OutReadMode" = "3"!][!//
        [!ELSE!][!//
            [!VAR "OutReadMode" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetOpType","OpType"!][!//
    [!NOCODE!][!//
        [!VAR "OutOpType" = "4294967295"!][!//
        [!IF "$OpType='QSPI_IP_OP_TYPE_CMD'"!][!//
            [!VAR "OutOpType" = "0"!][!//
        [!ELSEIF "$OpType='QSPI_IP_OP_TYPE_WRITE_REG'"!][!//
            [!VAR "OutOpType" = "1"!][!//
        [!ELSEIF "$OpType='QSPI_IP_OP_TYPE_RMW_REG'"!][!//
            [!VAR "OutOpType" = "2"!][!//
        [!ELSEIF "$OpType='QSPI_IP_OP_TYPE_READ_REG'"!][!//
            [!VAR "OutOpType" = "3"!][!//
        [!ELSEIF "$OpType='QSPI_IP_OP_TYPE_QSPI_CFG'"!][!//
            [!VAR "OutOpType" = "4"!][!//
        [!ELSE!][!//
            [!VAR "OutOpType" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "GetTrueFalse","boolean"!][!//
    [!NOCODE!][!//
        [!VAR "Outboolean" = "4294967295"!][!//
        [!IF "$boolean"!][!//
            [!VAR "Outboolean" = "1"!][!//
        [!ELSE!][!//
            [!VAR "Outboolean" = "0"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetSampleDelay","SampleDelay"!][!//
    [!NOCODE!][!//
        [!VAR "OutSampleDelay" = "4294967295"!][!//
        [!IF "$SampleDelay='QSPI_IP_SAMPLE_DELAY_SAME_DQS'"!][!//
            [!VAR "OutSampleDelay" = "0"!][!//
        [!ELSEIF "$SampleDelay='QSPI_IP_SAMPLE_DELAY_HALFCYCLE_EARLY_DQS'"!][!//
            [!VAR "OutSampleDelay" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutSampleDelay" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetSamplePhase","SamplePhase"!][!//
    [!NOCODE!][!//
        [!VAR "OutSamplePhase" = "4294967295"!][!//
        [!IF "$SamplePhase='QSPI_IP_SAMPLE_PHASE_NON_INVERTED'"!][!//
            [!VAR "OutSamplePhase" = "0"!][!//
        [!ELSEIF "$SamplePhase='QSPI_IP_SAMPLE_PHASE_INVERTED'"!][!//
            [!VAR "OutSamplePhase" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutSamplePhase" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetAlignData","AlignData"!][!//
    [!NOCODE!][!//
        [!VAR "OutAlignData" = "4294967295"!][!//
        [!IF "$AlignData='QSPI_IP_FLASH_DATA_ALIGN_REFCLK'"!][!//
            [!VAR "OutAlignData" = "0"!][!//
        [!ELSEIF "$AlignData='QSPI_IP_FLASH_DATA_ALIGN_2X_REFCLK'"!][!//
            [!VAR "OutAlignData" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutAlignData" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//

    [!//
    [!//
    [!MACRO "QspiGetOutputDriverStrength", "DriverStrength"!][!//
    [!NOCODE!][!//
            [!IF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_000'"!][!VAR "OutDriverStrengthData" = "0"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_001'"!][!VAR "OutDriverStrengthData" = "1"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_002'"!][!VAR "OutDriverStrengthData" = "2"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_003'"!][!VAR "OutDriverStrengthData" = "3"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_004'"!][!VAR "OutDriverStrengthData" = "4"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_005'"!][!VAR "OutDriverStrengthData" = "5"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_006'"!][!VAR "OutDriverStrengthData" = "6"!][!//
        [!ELSEIF "$DriverStrength = 'QSPI_IP_HF_DRV_STRENGTH_007'"!][!VAR "OutDriverStrengthData" = "7"!][!//
        [!ELSE!][!VAR "OutDriverStrengthData" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetReadLatency", "ReadLatency"!][!//
    [!NOCODE!][!//
            [!IF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_5_CLOCKS'"!] [!VAR "OutReadLatencyData" = "0"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_6_CLOCKS'"!] [!VAR "OutReadLatencyData" = "1"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_7_CLOCKS'"!] [!VAR "OutReadLatencyData" = "2"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_8_CLOCKS'"!] [!VAR "OutReadLatencyData" = "3"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_9_CLOCKS'"!] [!VAR "OutReadLatencyData" = "4"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_10_CLOCKS'"!][!VAR "OutReadLatencyData" = "5"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_11_CLOCKS'"!][!VAR "OutReadLatencyData" = "6"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_12_CLOCKS'"!][!VAR "OutReadLatencyData" = "7"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_13_CLOCKS'"!][!VAR "OutReadLatencyData" = "8"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_14_CLOCKS'"!][!VAR "OutReadLatencyData" = "9"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_15_CLOCKS'"!][!VAR "OutReadLatencyData" = "10"!][!//
        [!ELSEIF "$ReadLatency = 'QSPI_IP_HF_READ_LATENCY_16_CLOCKS'"!][!VAR "OutReadLatencyData" = "11"!][!//
        [!ELSE!][!VAR "OutReadLatencyData" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetParamSectorMap", "ParamSectorMap"!][!//
    [!NOCODE!][!//
            [!IF "$ParamSectorMap = 'QSPI_IP_HF_PARAM_AND_PASSWORD_MAP_LOW'"!]        [!VAR "OutParamSectorMapData" = "0"!][!//
        [!ELSEIF "$ParamSectorMap = 'QSPI_IP_HF_PARAM_AND_PASSWORD_MAP_HIGH'"!]       [!VAR "OutParamSectorMapData" = "1"!][!//
        [!ELSEIF "$ParamSectorMap = 'QSPI_IP_HF_UNIFORM_SECTORS_READ_PASSWORD_LOW'"!] [!VAR "OutParamSectorMapData" = "2"!][!//
        [!ELSEIF "$ParamSectorMap = 'QSPI_IP_HF_UNIFORM_SECTORS_READ_PASSWORD_HIGH'"!][!VAR "OutParamSectorMapData" = "3"!][!//
        [!ELSE!][!VAR "OutParamSectorMapData" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "QspiGetDataRate","DataRate"!][!//
    [!NOCODE!][!//
        [!VAR "OutDataRate" = "4294967295"!][!//
        [!IF "$DataRate='QSPI_IP_DATA_RATE_SDR'"!][!//
            [!VAR "OutDataRate" = "0"!][!//
        [!ELSEIF "$DataRate='QSPI_IP_DATA_RATE_DDR'"!][!//
            [!VAR "OutDataRate" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutDataRate" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"!][!//
    [!NOCODE!][!//
        [!VAR "LutSeqIdNodeFound" = "'false'"!][!//
        [!LOOP "./FlsQspiLutSeqIdRefs/*"!][!//
            [!IF "node:name(.)=$FlsQspiLutSeqIdName"!][!//
                [!VAR "LutSeqIdNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//
                        [!IF "node:refvalid(.)"!][!//
                            [!CODE!][!"as:ref(.)/FlsLUTIndex"!]U[!ENDCODE!]
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $FlsQspiLutSeqIdName"!][!//
                        [!ENDIF!][!//
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $FlsQspiLutSeqIdName"!]
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!CODE!]0U[!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$LutSeqIdNodeFound='false'"!]
            [!CODE!]0U[!ENDCODE!]
        [!ENDIF!]
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTsCount","FlsLUTsCount"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsLUTsCount" = "0"!][!//
        [!IF "node:exists(./FlsQspiLutSeqIdRefs)"!][!//     If node exists(!= Hyperflash mode), then count the LUTs
            [!VAR "OutFlsLUTsCount" = "$FlsLUTsCount"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsLUTsCount" = "0"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsAccCrcReadId", "ReadIdSettings" = ""!]
    [!NOCODE!][!//
        [!VAR "IdSizeMax"        = "num:i(4)"!][!//
        [!VAR "FlsQspiDeviceId"  = "node:ref($ReadIdSettings)/FlsQspiDeviceId"!][!//
        [!VAR "IdExpected"       = "text:replaceAll(substring($FlsQspiDeviceId, 3), ':', '')"!][!//
        [!VAR "MemCfgReadIdSize" = "node:ref($ReadIdSettings)/MemCfgReadIdSize"!]
        [!IF "not(node:exists(node:ref($ReadIdSettings)/MemCfgReadIdLUT))"!]
            [!VAR "MemCfgReadIdSize" = "num:i(0)"!][!// If the Read Id LUT index reference is not enabled, ignore the user configuration
        [!ENDIF!]
        /* CRC - Accumulate MemCfgReadIdSize */
        [!CALL "FlsAccCrc", "FlsData32" = "$MemCfgReadIdSize"!][!//
        /* Calculate user value */
        [!FOR "Idx" = "1" TO "$MemCfgReadIdSize"!][!//
            [!VAR "Start"  = "string-length($IdExpected) - ($Idx * 2) + 1"!][!//
            [!VAR "IdByte" = "substring($IdExpected, $Start, 2)"!][!//
            [!VAR "IdByte" = "concat('0x', $IdByte)"!][!//
            [!CALL "FlsAccCrc", "FlsData32" = "num:hextoint($IdByte)"!][!//
        [!ENDFOR!][!//
        /* Calculate unused bytes with 0xFF */
        [!FOR "Idx" = "$MemCfgReadIdSize + 1" TO "$IdSizeMax"!][!//
            [!CALL "FlsAccCrc", "FlsData32" = "255"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsCalcCrc"!][!//
        [!NOCODE!][!//
        [!VAR "FlsCrcReminder" = "0"!][!// Reset CRC reminder

        /* CRC - Accumulate eDefaultMode*/
            [!CALL "FlsGetMemifModeValue","FlsEnumName"="./FlsDefaultMode"!][!//
            [!CALL "FlsAccCrc","FlsData32"="$OutMemifModeValue"!][!//
        /* CRC - Accumulate u32MaxReadFastMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadFastMode"!][!//
        /* CRC - Accumulate u32MaxReadNormalMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadNormalMode"!][!//
        /* CRC - Accumulate u32MaxWriteFastMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteFastMode"!][!//
        /* CRC - Accumulate u32MaxWriteNormalMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteNormalMode"!][!//
        /* CRC - Accumulate u32SectorCount */
            [!CALL "FlsAccCrc","FlsData32"="num:i(count(FlsSectorList/FlsSector/*))"!][!//

        [!VAR "FlsQspiSectors" = "number(node:value(as:modconf('Fls')[1]/AutosarExt/FlsExternalSectorsConfigured) = 'true')"!][!// The configuration contains external QSPI sectors or not.
        /* Iterate through the sector-dependent params */
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!// Iterate through the sector-dependent params.
            /* CRC - Accumulate paSectorEndAddr */
                [!CALL "FlsAccCrc","FlsData32"="num:i((./FlsSectorSize * ./FlsNumberOfSectors) + ./FlsSectorStartaddress - 1)"!][!//
            /* CRC - Accumulate FlsSectorSize  */
                [!CALL "FlsAccCrc","FlsData32"="num:i(./FlsSectorSize)"!][!//
            /* CRC - Accumulate pSectorList */
                [!IF "text:contains(string(./FlsPhysicalSector),'FLS_EXT_')"!][!//
                [!ELSE!][!//
                    [!CALL "FlsGetSectorId","FlsEnumName"="./FlsPhysicalSector"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="$OutFlsSectorId"!][!//
                    [!CALL "FlsPhysicalInternalSectorHardwareAddress","FlashSectorSize"="./FlsSectorSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="$InternalSectorHardwareAddress"!][!//
                [!ENDIF!][!//
            /* CRC - Accumulate paSectorFlags */
                [!VAR "FlsFlag" = "0"!][!//
                [!IF "./FlsSectorEraseAsynch"!]
                    [!VAR "FlsFlag" = "1"!]
                [!ENDIF!][!//

                [!IF "./FlsPageWriteAsynch"!]
                    [!IF "$FlsFlag = 1"!]
                        [!VAR "FlsFlag" = "3"!]
                    [!ELSE!]
                        [!VAR "FlsFlag" = "2"!]
                    [!ENDIF!]
                [!ENDIF!][!//
                [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!//

                [!IF " $FlsQspiSectors = 1"!][!//
            /* CRC - Accumulate paHwCh */
                [!CALL "FlsGetSectorHwCh","FlsHwChName"="./FlsHwCh"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsHwChName"!][!//
            /* CRC - Accumulate paSectorHwAddress */
                [!CALL "FlsAccCrc","FlsData32"="./FlsSectorHwAddress"!][!//
                [!ENDIF!][!//
        [!ENDLOOP!][!//

        [!IF " $FlsQspiSectors = 1"!][!//
            [!VAR "SerialflashCfgCount" = "num:i(count(FlsExternalDriver/MemCfg/*))"!][!//
            [!VAR "HyperflashCfgCount"  = "num:i(count(FlsExternalDriver/HyperflashCfg/*))"!][!//
            [!VAR "FlashConfigCount"    = "num:i($SerialflashCfgCount + $HyperflashCfgCount)"!][!//
                /*  CRC - Accumulate Number of serial flash instances u8FlashUnitsCount */
            [!CALL "FlsAccCrc","FlsData32"="num:i(count(FlsExternalDriver/FlsMem/*))"!][!//
            [!LOOP "FlsExternalDriver/FlsMem/*"!][!//
                /* CRC - Accumulate (*paFlashConnectionCfg)[] */
                [!CALL "FlsAccCrc","FlsData32"="num:i( substring-after(node:ref(./qspiInstance)/ControllerName, 'FLS_QSPI_') )"!][!//
                [!CALL "FlsGetIpSide","QspiIpSide"="./connectionType"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutQspiIpSide"!][!//
            [!ENDLOOP!][!//
            /* CRC - Accumulate (*u8FlashConfig)[] */
            [!LOOP "FlsExternalDriver/FlsMem/*"!][!//
                [!IF "./FlsMemUseSfdp ='true'"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "255"!][!//
                [!ELSE!][!//
                    [!VAR "FlsMemCfgPos" = "node:pos(node:ref(./FlsMemCfgRef))"!][!//
                    [!IF "text:contains(node:path(node:ref(./FlsMemCfgRef)), 'HyperflashCfg') = 'true'"!][!//
                        [!VAR "FlsMemCfgPos" = "$FlsMemCfgPos + $SerialflashCfgCount"!][!//
                    [!ENDIF!][!//
                    [!CALL "FlsAccCrc","FlsData32"="num:i($FlsMemCfgPos)"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            /* CRC - Accumulate u8FlashConfigCount */
            [!CALL "FlsAccCrc","FlsData32"="$FlashConfigCount"!][!//
            /* CRC - Accumulate paFlashCfg[] */
            [!IF "num:i(count(FlsExternalDriver/MemCfg/*)) > 0"!][!// CRC for Serialflash configurations
                [!LOOP "FlsExternalDriver/MemCfg/*"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgPageSize"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgReadLUT), ./MemCfgReadLUT)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgWriteLUT), ./MemCfgWriteLUT)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgRead0xxLUT), ./MemCfgRead0xxLUT)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgRead0xxLUTAHB), ./MemCfgRead0xxLUTAHB)"!]

                    /* CRC - Accumulate MemCfgReadIdSettings */
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgReadIdSettings/MemCfgReadIdLUT), ./MemCfgReadIdSettings/MemCfgReadIdLUT)"!]
                    [!CALL "FlsAccCrcReadId", "ReadIdSettings" = "node:path(./MemCfgReadIdSettings)"!]

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase1LUT), ./MemCfgEraseSettings/MemCfgErase1LUT)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgEraseSettings/MemCfgErase1Size"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase2LUT), ./MemCfgEraseSettings/MemCfgErase2LUT)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgEraseSettings/MemCfgErase2Size"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase3LUT), ./MemCfgEraseSettings/MemCfgErase3LUT)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgEraseSettings/MemCfgErase3Size"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/MemCfgErase4LUT), ./MemCfgEraseSettings/MemCfgErase4LUT)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./MemCfgEraseSettings/MemCfgErase4Size"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./MemCfgEraseSettings/ChipEraseLUT), ./MemCfgEraseSettings/ChipEraseLUT)"!]

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./statusConfig/statusRegReadLut), ./statusConfig/statusRegReadLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./statusConfig/statusRegWriteLut), ./statusConfig/statusRegWriteLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./statusConfig/writeEnableSRLut), ./statusConfig/writeEnableSRLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./statusConfig/writeEnableLut), ./statusConfig/writeEnableLut)"!]

                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/regSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/busyOffset"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/busyValue"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/writeEnableOffset"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/blockProtectionOffset"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="./statusConfig/blockProtectionWidth"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./suspendSettings/eraseSuspendLut), ./suspendSettings/eraseSuspendLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./suspendSettings/eraseResumeLut), ./suspendSettings/eraseResumeLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./suspendSettings/programSuspendLut), ./suspendSettings/programSuspendLut)"!]
                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./suspendSettings/programResumeLut), ./suspendSettings/programResumeLut)"!]

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./resetSettings/resetCmdLut), ./resetSettings/resetCmdLut)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./resetSettings/resetCmdCount"!][!//

                    [!CALL "FlsAccCrc_LutIndex", "SeqNo" = "node:when(node:exists(./initResetSettings/resetCmdLut), ./initResetSettings/resetCmdLut)"!]
                    [!CALL "FlsAccCrc","FlsData32"="./initResetSettings/resetCmdCount"!][!//

                    [!CALL "FlsAccCrc","FlsData32"="num:i(count(./initConfiguration/*))"!][!//

                    [!IF "num:i(count(./initConfiguration/*)) > 0"!]
                        [!LOOP "./initConfiguration/*"!][!//
                            [!CALL "QspiGetOpType","OpType" = "./opType"!][!//
                            [!CALL "FlsAccCrc","FlsData32"="$OutOpType"!][!//

                            [!CALL "FlsAccCrc_LutIndex_Op", "SeqNo" = "node:when(node:exists(./command1Lut), ./command1Lut)"!]
                            [!CALL "FlsAccCrc_LutIndex_Op", "SeqNo" = "node:when(node:exists(./command2Lut), ./command2Lut)"!]
                            [!CALL "FlsAccCrc_LutIndex_Op", "SeqNo" = "node:when(node:exists(./weLut), ./weLut)"!]

                            [!CALL "FlsAccCrc","FlsData32" = "./addr"!][!//
                            [!CALL "FlsAccCrc","FlsData32" = "./size"!][!//
                            [!CALL "FlsAccCrc","FlsData32" = "./shift"!][!//
                            [!CALL "FlsAccCrc","FlsData32" = "./width"!][!//
                            [!CALL "FlsAccCrc","FlsData32" = "./value"!][!//
                        [!ENDLOOP!][!//
                    [!ENDIF!]
                    [!VAR "FlsLutSize" = "0"!][!//
                    [!LOOP "./FlsLUT/*"!][!//
                        [!VAR "FlsLutSize" = "$FlsLutSize + count(./FlsInstructionOperandPair/*) + 1"!][!//
                    [!ENDLOOP!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$FlsLutSize"!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
            [!IF "num:i(count(FlsExternalDriver/HyperflashCfg/*)) > 0"!][!// CRC for Hyperflash configurations
                [!LOOP "FlsExternalDriver/HyperflashCfg/*"!][!//
                    [!CALL "FlsAccCrc", "FlsData32"="./MemCfgSize"!][!//
                    [!CALL "FlsAccCrc", "FlsData32"="./MemCfgPageSize"!][!//

                    [!CALL "QspiGetOutputDriverStrength", "DriverStrength" = "./outputDriverStrength"!][!//
                    [!CALL "FlsAccCrc", "FlsData32" = "$OutDriverStrengthData"!][!//

                    [!CALL "GetTrueFalse", "boolean" = "./RWDSLowOnDualError"!][!//
                    [!CALL "FlsAccCrc", "FlsData32"  = "$Outboolean"!][!//

                    [!CALL "GetTrueFalse", "boolean" = "./secureRegionUnlocked"!][!//
                    [!CALL "FlsAccCrc", "FlsData32"  = "$Outboolean"!][!//

                    [!CALL "QspiGetReadLatency", "ReadLatency" = "./readLatency"!][!//
                    [!CALL "FlsAccCrc", "FlsData32" = "$OutReadLatencyData"!][!//

                    [!CALL "QspiGetParamSectorMap", "ParamSectorMap" = "./paramSectorMap"!][!//
                    [!CALL "FlsAccCrc", "FlsData32" = "$OutParamSectorMapData"!][!//

                    [!CALL "FlsAccCrc", "FlsData32" = "./MemCfgReadIdSettings/MemCfgReadIdWordAddr"!][!//

                    /* CRC - Accumulate readIdSettings (not include readIdLut) */
                    [!CALL "FlsAccCrcReadId", "ReadIdSettings" = "node:path(./MemCfgReadIdSettings)"!]

                [!ENDLOOP!][!//
            [!ENDIF!][!//

            /* CRC - Accumulate u8QspiUnitsCount */
            [!CALL "FlsAccCrc","FlsData32" = "num:i(count(FlsExternalDriver/FlsController/*))"!][!//
            /* CRC - Accumulate (*u8QspiConfig)[] */
            [!LOOP "FlsExternalDriver/FlsController/*"!][!//
                [!IF "node:refvalid(./FlsControllerCfgRef)"!]
                    [!CALL "FlsAccCrc","FlsData32" = "node:pos(node:ref(./FlsControllerCfgRef))"!][!//
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32" = "255"!][!//
                [!ENDIF!]
            [!ENDLOOP!][!//
            /* CRC - Accumulate u8QspiConfigCount */
                [!CALL "FlsAccCrc","FlsData32" = "num:i(count(FlsExternalDriver/ControllerCfg/*))"!][!//
            [!IF "num:i(count(FlsExternalDriver/ControllerCfg/*)) > 0"!][!//
                [!LOOP "FlsExternalDriver/ControllerCfg/*"!][!//
                    [!CALL "QspiGetDataRate","DataRate" = "./FlsHwUnitReadMode"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutDataRate"!][!//  /* dataRate */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsSerialFlashA1Size"!][!//  /* memSizeA1 */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsSerialFlashA2Size"!][!//  /* memSizeA2 */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsSerialFlashB1Size"!][!//  /* memSizeB1 */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsSerialFlashB2Size"!][!//  /* memSizeB2 */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsHwUnitTcsh"!][!//  /* csHoldTime */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsHwUnitTcss"!][!//  /* csSetupTime */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsHwUnitColumnAddressWidth"!][!//  /* columnAddr */
                    [!CALL "GetTrueFalse","boolean" = "./FlsHwUnitWordAddressable"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//              /* wordAddresable */
                    [!CALL "QspiGetReadMode","ReadMode" = "./FlsHwUnitSamplingModeA"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutReadMode"!][!//              /* readModeA */
                    [!CALL "QspiGetReadMode","ReadMode" = "./FlsHwUnitSamplingModeB"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutReadMode"!][!//                                /* readModeB */
                    [!CALL "QspiGetSampleDelay","SampleDelay" = "./FlsHwUnitSamplingDly"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutSampleDelay"!][!//    /* sampleDelay */

                    [!CALL "QspiGetSamplePhase","SamplePhase" = "./FlsHwUnitSamplingEdge"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutSamplePhase"!][!//    /* SamplePhase */

                    [!CALL "GetTrueFalse","boolean" = "./FlsHwUnitDqsLatencyEnable"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//    /* dqsLatency */
                    [!CALL "QspiGetAlignData","AlignData" = "./FlsHwUnitTdh"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$OutAlignData"!][!//    /* dataAlign */
                    [!CALL "GetTrueFalse","boolean" = "./IdleSignalDriveIOFA2HighLvl"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//    /* io2IdleValueA */

                    [!CALL "GetTrueFalse","boolean" = "./IdleSignalDriveIOFA3HighLvl"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//    /* io3IdleValueA */
                    [!CALL "GetTrueFalse","boolean" = "./IdleSignalDriveIOFB2HighLvl"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//    /* io2IdleValueB */

                    [!CALL "GetTrueFalse","boolean" = "./IdleSignalDriveIOFB3HighLvl"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//    /* io3IdleValueB */

                    /* AHB Config Master ID */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[1]/FlsAhbBufferMasterId"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[2]/FlsAhbBufferMasterId"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[3]/FlsAhbBufferMasterId"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[4]/FlsAhbBufferMasterId"!][!//

                    /* AHB Config Size */
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[1]/FlsAhbBufferSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[2]/FlsAhbBufferSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[3]/FlsAhbBufferSize"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "./FlsAhbBuffer/*[4]/FlsAhbBufferSize"!][!//
                    /* allMasters */
                    [!CALL "GetTrueFalse","boolean" = "./FlsAhbBuffer/*[4]/FlsAhbBufferAllMasters"!][!//
                    [!CALL "FlsAccCrc","FlsData32" = "$Outboolean"!][!//


                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('FLS_CFG_SPECIFIC_MACROS_M4'))"!][!//
[!NOCODE!][!//
    [!VAR "FLS_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsGetWritePageSizeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='FLS_WRITE_DOUBLE_WORD'"!][!//
            [!VAR "OutWritePageSize" = "8"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "32"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_QUAD_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "128"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_128BYTES_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "128"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_256BYTES_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "256"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_512BYTES_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "512"!][!//
        [!ELSE!][!//
            [!VAR "OutWritePageSize" = "0"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsGetSectorId","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsSectorId" = "4294967295"!][!//
        [!VAR "LocationStartCodeSector" = "ecu:get('Fls.NumberOfSectorData')"!][!//
        [!VAR "SectorTotal" = "num:i(count(ecu:list('Fls.Sector.Physical.List')))"!][!//
        [!IF "contains($FlsEnumName, 'DATA') = 'true'"!][!//
            [!VAR "OutFlsSectorId" = "num:i(substring-after(substring-after($FlsEnumName, 'Y'), 'S'))"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsSectorId" = "num:i(substring-after(substring-after($FlsEnumName, 'Y'), 'S')) + $LocationStartCodeSector"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
[!INDENT "0"!][!//
    [!MACRO "FlsPhysicalSectorlist","FlashSectorSize"!][!//
    [!IF "contains(./FlsPhysicalSector,'DATA') = 'true'"!][!//
        [!WS "4"!](FLS_DATA_FLASH_BASE_ADDR + 0x[!"text:toupper(text:replace(num:inttohex(num:i($OutFlsSectorId * $FlashSectorSize),6), '0x', ''))"!]UL),  /* pSectorStartAddressPtr */
        [!WS "4"!][!"num:i($OutFlsSectorId)"!]U  /* Sector location to calculate cfgCRC */
    [!ELSE!][!//
        [!WS "4"!](FLS_PROGRAM_FLASH_BASE_ADDR + 0x[!"text:toupper(text:replace(num:inttohex(num:i(($OutFlsSectorId - $LocationStartCodeSector) * $FlashSectorSize),6), '0x', ''))"!]UL),  /* pSectorStartAddressPtr */
        [!WS "4"!][!"num:i($OutFlsSectorId)"!]U  /* Sector location to calculate cfgCRC */
    [!ENDIF!][!// ToDo: implement for AC code
    [!ENDMACRO!][!//
[!ENDINDENT!][!//
    [!//
    [!MACRO "FlsPhysicalInternalSectorHardwareAddress","FlashSectorSize"!][!//
    [!NOCODE!][!//
        [!VAR "InternalSectorHardwareAddress" = "4294967295"!][!//
        [!IF "contains(./FlsPhysicalSector,'DATA') = 'true'"!]
            [!VAR "InternalSectorHardwareAddress" = "num:hextoint('0x10000000') + num:i($OutFlsSectorId * $FlashSectorSize)"!][!//
        [!ELSEIF "contains(./FlsPhysicalSector,'CODE') = 'true'"!]
            [!VAR "CurrentCodeSectorID" = " num:i($OutFlsSectorId - $LocationStartCodeSector)"!][!//
            [!VAR "InternalSectorHardwareAddress" = "num:hextoint('0x00000000') + num:i($CurrentCodeSectorID * $FlashSectorSize)"!][!//
        [!ELSE!][!// Utest areas
            [!VAR "InternalSectorHardwareAddress" = "num:hextoint('0x1B000000')"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!MACRO "FlsGetMemifModeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='MEMIF_MODE_SLOW'"!][!//
            [!VAR "OutMemifModeValue" = "0"!][!//
        [!ELSEIF "$FlsEnumName='MEMIF_MODE_FAST'"!][!//
            [!VAR "OutMemifModeValue" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutMemifModeValue" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!//
[!VAR "CommentAlignment" = "69"!][!//
[!VAR "PaddingSpaces" = "'                                                                               '"!][!//
[!MACRO "PrintAlign", "Tabs" = "1", "Str" = "''", "Cmt" = "''", "Comma" = "1"!][!//
    [!VAR "StrOut" = "''"!][!// Init the output string
    [!FOR "i" = "1" TO "$Tabs"!][!// Add tabs
        [!VAR "StrOut" = "concat($StrOut, '    ')"!][!//
    [!ENDFOR!][!//
    [!VAR "StrOut" = "concat($StrOut, $Str)"!][!//
    [!IF "$Comma = 1"!][!VAR "StrOut" = "concat($StrOut, ',')"!][!ENDIF!][!//
    [!VAR "StrOut" = "concat($StrOut, $PaddingSpaces)"!][!// Padding spaces for alignment
    [!VAR "StrOut" = "substring($StrOut, 1, $CommentAlignment)"!][!// Perform the alignment
    [!VAR "StrOut" = "concat($StrOut, $Cmt)"!][!//
    [!CODE!][!"$StrOut"!][!CR!][!ENDCODE!][!// Print the output string
[!ENDMACRO!][!//
[!//
[!MACRO "PrintNotif", "Tabs" = "1", "Str" = "", "Cmt" = "''", "Comma" = "1"!][!//
    [!VAR "NotifOut" = "'NULL_PTR'"!][!// Init the notify string
    [!IF "$Str != 'false'"!][!VAR "NotifOut" = "concat('&', $Str)"!][!ENDIF!][!//
    [!CALL "PrintAlign", "Tabs" = "$Tabs", "Str" = "$NotifOut", "Cmt" = "$Cmt", "Comma" = "$Comma"!][!// Print the output string
[!ENDMACRO!][!//
[!//
[!MACRO "PrintACFun", "Tabs" = "1", "ACEnable" = "'false'", "ACType" ="", "ACInteger" = "", "ACPointer" = "", "Cmt" = "''", "Comma" = "1"!][!//
[!NOCODE!][!//
    [!VAR "ACFuncOut" = "'NULL_PTR'"!][!// Init the AC string
    [!IF "$ACEnable = 'true'"!][!//
        [!IF "normalize-space($ACPointer) = 'NULL_PTR' or normalize-space($ACPointer) = 'NULL'"!][!//
            [!VAR "ACFuncOut" = "concat(text:replace(text:toupper(num:inttohex($ACInteger, 8)), 'X', 'x'), 'U')"!]
        [!ELSE!][!//
            [!VAR "ACFuncOut" = "concat('&', $ACPointer)"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!CALL "PrintAlign", "Tabs" = "1", "Str" = "concat($ACType, $ACFuncOut)", "Cmt" = "$Cmt", "Comma" = "$Comma"!][!// Print the output string
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!INDENT "0"!][!//
[!VAR "configName" = "as:name(FlsConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "VSName" = "concat('_', $postBuildVariant)"!][!//
[!ELSE!][!//
    [!VAR "VSName" = "''"!][!//
[!ENDIF!][!//
[!VAR "configVSName" = "concat($configName, $VSName)"!][!// Global variable name used for all structure name
[!//
[!LOOP "FlsConfigSet"!][!//
[!AUTOSPACING!][!//
[!VAR "Current_ConfigSet"="@name"!][!//
[!VAR "FlsAhbBufferCount" = "0"!][!//
[!VAR "FlsLUTSeqsCount" = "0"!][!//
[!VAR "SerialflashCfgCount" = "num:i(count(FlsExternalDriver/MemCfg/*))"!][!//
[!VAR "HyperflashCfgCount"  = "num:i(count(FlsExternalDriver/HyperflashCfg/*))"!][!//
[!VAR "FlashConfigCount"    = "num:i($SerialflashCfgCount + $HyperflashCfgCount)"!][!//

    #define FLS_START_SEC_CONFIG_DATA_8
    #include "Fls_MemMap.h"

    /* aFlsSectorFlags */
    static const uint8 [!"$configName"!]_[!"$variantName"!]aFlsSectorFlags[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!VAR "FlsFlag" = "0"!][!//
        [!IF "./FlsSectorEraseAsynch"!][!WS "4"!](uint8)FLS_SECTOR_ERASE_ASYNCH[!VAR "FlsFlag" = "1"!][!ENDIF!][!//
        [!IF "./FlsPageWriteAsynch"!][!IF "$FlsFlag = 1"!] | [!ELSE!][!WS "4"!][!VAR "FlsFlag" = "1"!][!ENDIF!] (uint8)FLS_PAGE_WRITE_ASYNCH[!ENDIF!][!//
        [!IF "$FlsFlag = 0"!][!WS "4"!]0U[!ENDIF!]
        [!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

    #define FLS_STOP_SEC_CONFIG_DATA_8
    #include "Fls_MemMap.h"



    #define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Fls_MemMap.h"

    /* aFlsSectorEndAddr */
    static const Fls_AddressType [!"$configName"!]_[!"$variantName"!]aFlsSectorEndAddr[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_AddressType)[!"num:i((./FlsSectorSize * ./FlsNumberOfSectors) + ./FlsSectorStartaddress - 1)"!]U[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

    /* paSectorSize */
    static const Fls_LengthType [!"$configName"!]_[!"$variantName"!]aFlsSectorSize[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_LengthType)[!"./FlsSectorSize"!]U[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

    /* paSectorPageSize */
    static const Fls_LengthType [!"$configName"!]_[!"$variantName"!]aFlsSectorPageSize[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_LengthType)[!"./FlsPageSize"!]U[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
   };

    /* Info structure (reg prot, ecc trigger, etc) for each internal flash sector. */
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//     /* Loop all configured sectors. */
        [!IF "not(text:contains(string(./FlsPhysicalSector),'FLS_EXT_'))"!][!//                    /* If the current sector is an internal flash one. */
            static const Fls_Flash_InternalSectorInfoType [!"node:name(.)"!]_[!"$configName"!]_[!"$variantName"!]sInternalSectorInfo =
            [!WS "0"!]{
                [!CALL "FlsGetSectorId","FlsEnumName"="./FlsPhysicalSector"!][!//       /* Returns $OutFlsSectorId, which is the flash sector position inside the entire sector list, used for unique identification for CRC calculation. */
                [!CALL "FlsPhysicalSectorlist","FlashSectorSize"="./FlsSectorSize"!][!//
            [!WS "0"!]};
            [!CR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//

    /* FLASH physical sectorization description */
    static const Fls_Flash_InternalSectorInfoType * const [!"$configName"!]_[!"$variantName"!]aSectorList[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!IF "text:contains(string(./FlsPhysicalSector),'FLS_EXT_')"!][!//
            [!WS "4"!]NULL_PTR[!//
        [!ELSE!][!//
            [!WS "4"!]&[!"node:name(.)"!]_[!"$configName"!]_[!"$variantName"!]sInternalSectorInfo[!//
        [!ENDIF!][!//
        [!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!][!//
        [!WS "2"!]/* [!"./FlsPhysicalSector"!] */
        [!ENDLOOP!][!//
    };

    /* paHwCh */
    static const Fls_HwChType [!"$configName"!]_[!"$variantName"!]paHwCh[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!][!"./FlsHwCh"!][!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

    /* paSectorHwAddress */
    static const Fls_AddressType [!"$configName"!]_[!"$variantName"!]paSectorHwAddress[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!](Fls_AddressType)[!"./FlsSectorHwAddress"!]U[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

[!IF "//AutosarExt/FlsExternalSectorsConfigured='true'"!][!//
    /* External QSPI flash parameters. */

    /* u8SectFlashUnit */
    static const uint8 [!"$configName"!]_[!"$variantName"!]u8SectFlashUnit[[!"num:i(count(FlsSectorList/FlsSector/*))"!]U] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](uint8)[!IF "./FlsHwCh = 'FLS_CH_QSPI'"!][!"node:pos(node:ref(./flashInstance))"!]U[!ELSE!]FLS_DEVICE_INSTANCE_INVALID[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!]  /* [!"node:name(.)"!] */
    [!ENDLOOP!][!//
    };

    [!IF "num:i(count(FlsExternalDriver/FlsController/*)) > 0"!][!//
    /* u8QspiInstance */
    static const uint8 [!"$configName"!]_[!"$variantName"!]u8QspiInstance[[!"num:i(count(FlsExternalDriver/FlsController/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsController/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsController/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!][!"substring-after(./ControllerName, 'FLS_QSPI_')"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
    };

    /* u8QspiConfig */
    static const uint8 [!"$configName"!]_[!"$variantName"!]u8QspiConfig[[!"num:i(count(FlsExternalDriver/FlsController/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsController/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsController/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!IF "node:refvalid(./FlsControllerCfgRef)"!]
                [!WS "4"!][!"node:pos(node:ref(./FlsControllerCfgRef))"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
            [!ELSE!]
                [!WS "4"!]0xFFU[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
            [!ENDIF!]
        [!ENDLOOP!][!//
    };
    [!ENDIF!][!//

    [!IF "num:i(count(FlsExternalDriver/FlsMem/*)) > 0"!][!//
    /* u8FlashConfig */
    static const uint8 [!"$configName"!]_[!"$variantName"!]u8FlashConfig[[!"num:i(count(FlsExternalDriver/FlsMem/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsMem/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsMem/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!IF "./FlsMemUseSfdp ='true'"!][!//
                [!WS "4"!]0xFFU[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* uses SFDP */[!CR!]
            [!ELSE!][!//
                [!VAR "FlsMemCfgPos" = "node:pos(node:ref(./FlsMemCfgRef))"!][!//
                [!IF "text:contains(node:path(node:ref(./FlsMemCfgRef)), 'HyperflashCfg') = 'true'"!][!//
                    [!VAR "FlsMemCfgPos" = "$FlsMemCfgPos + $SerialflashCfgCount"!][!//
                [!ENDIF!][!//
                [!WS "4"!][!"num:i($FlsMemCfgPos)"!]U[!IF "$FlsLoopIt != 0"!],[!ELSE!][!WS!][!ENDIF!]  /* uses FlsMemCfg */[!CR!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    };
    [!ENDIF!][!//

    /* paAHBReadCfg */
    [!IF "num:i(count(FlsExternalDriver/FlsMem/*)) > 0"!][!//
    static const boolean [!"$configName"!]_[!"$variantName"!]paAHBReadCfg[[!"num:i(count(FlsExternalDriver/FlsMem/*))"!]U] =
    {
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsMem/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsMem/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!][!IF "./AHBReadEnable"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
    };
    [!ENDIF!][!//

    /* pFlsQspiCfgConfig */
    static const Fls_QspiCfgConfigType Fls_QspiConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!WS!] =
    {
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_u8SectFlashUnit')"           , "Cmt"="'/* (*u8SectFlashUnit)[] */'           "!]
        [!CALL "PrintAlign", "Str"="concat(count(FlsExternalDriver/FlsMem/*), 'U')"           , "Cmt"="'/* u8FlashUnitsCount */'              "!]
    [!IF "num:i(count(FlsExternalDriver/FlsMem/*)) > 0"!][!//
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paFlashConnectionCfg')"      , "Cmt"="'/* (*paFlashConnectionCfg)[] */'      "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_u8FlashConfig')"             , "Cmt"="'/* (*u8FlashConfig)[] */'             "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paAHBReadCfg')"              , "Cmt"="'/* (*paAHBReadCfg)[] */'              "!]
    [!ELSE!][!//
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*paFlashConnectionCfg)[] */'      "!]
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*u8FlashConfig)[] */'             "!]
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*paAHBReadCfg)[] */'              "!]
    [!ENDIF!][!//
        [!CALL "PrintAlign", "Str"="concat($FlashConfigCount, 'U')"                           , "Cmt"="'/* u8FlashConfigCount */'             "!]
    [!IF "$FlashConfigCount > 0"!][!//
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paFlashCfg')"                , "Cmt"="'/* (*paFlashCfg)[] */'                "!]
    [!ELSE!][!//
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*paFlashCfg)[] */'                "!]
    [!ENDIF!][!//
        [!CALL "PrintAlign", "Str"="concat(count(FlsExternalDriver/FlsController/*), 'U')"    , "Cmt"="'/* u8QspiUnitsCount */'               "!]
    [!IF "num:i(count(FlsExternalDriver/FlsController/*)) > 0"!][!//
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_u8QspiInstance')"            , "Cmt"="'/* (*u8QspiInstance)[] */'            "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_u8QspiConfig')"              , "Cmt"="'/* (*u8QspiConfig)[] */'              "!]
    [!ELSE!][!//
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*u8QspiInstance)[] */'            "!]
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*u8QspiConfig)[] */'              "!]
    [!ENDIF!][!//
        [!CALL "PrintAlign", "Str"="concat(count(FlsExternalDriver/ControllerCfg/*), 'U')"    , "Cmt"="'/* u8QspiConfigCount */'              "!]
    [!IF "num:i(count(FlsExternalDriver/ControllerCfg/*)) > 0"!][!//
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paQspiUnitCfg')"             , "Cmt"="'/* (*paQspiUnitCfg)[] */'", "Comma"="0"!]
    [!ELSE!][!//
        [!CALL "PrintAlign", "Str"="'NULL_PTR'"                                               , "Cmt"="'/* (*paQspiUnitCfg)[] */'", "Comma"="0"!]
    [!ENDIF!][!//
    };
[!ENDIF!][!//

    [!CALL "FlsCalcCrc"!][!//
    [!CALL "FlsFinishCrc"!][!//

    /**
    * @brief        Structure used to set function pointers notification, working mode
    */
    /* Fls module initialization data ([!"$configName"!])*/
    const Fls_ConfigType Fls_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!WS!] =
    {
#if (STD_ON == FLS_AC_LOAD_ON_JOB_START)
        [!CALL "PrintACFun", "ACEnable"="../FlsGeneral/FlsAcLoadOnJobStart", "ACType"="'(Fls_AcErasePtrType)'", "ACInteger"="./FlsAcErase", "ACPointer"="./FlsAcErasePointer", "Cmt"="'/* FlsAcErase */'"!]
        [!CALL "PrintACFun", "ACEnable"="../FlsGeneral/FlsAcLoadOnJobStart", "ACType"="'(Fls_AcWritePtrType)'", "ACInteger"="./FlsAcWrite", "ACPointer"="./FlsAcWritePointer", "Cmt"="'/* FlsAcWrite */'"!]
#endif
        [!CALL "PrintNotif", "Str"="node:when(node:exists(FlsACCallback),               ./FlsACCallback)"              , "Cmt"="'/* FlsACCallback */'              "!]
        [!CALL "PrintNotif", "Str"="node:when(node:exists(FlsJobEndNotification),       ./FlsJobEndNotification)"      , "Cmt"="'/* FlsJobEndNotification */'      "!]
        [!CALL "PrintNotif", "Str"="node:when(node:exists(FlsJobErrorNotification),     ./FlsJobErrorNotification)"    , "Cmt"="'/* FlsJobErrorNotification */'    "!]
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
        [!CALL "PrintNotif", "Str"="node:when(node:exists(FlsReadFunctionCallout) and (../FlsGeneral/FlsECCHandlingProtectionHook = 'true'), ./FlsReadFunctionCallout)", "Cmt"="'/* FlsReadFunctionCallout */'"!]
#endif
        [!CALL "PrintAlign", "Str"="./FlsDefaultMode"                                                                  , "Cmt"="'/* FlsDefaultMode */'             "!]
        [!CALL "PrintAlign", "Str"="concat(./FlsMaxReadFastMode,             'U')"                                     , "Cmt"="'/* FlsMaxReadFastMode */'         "!]
        [!CALL "PrintAlign", "Str"="concat(./FlsMaxReadNormalMode,           'U')"                                     , "Cmt"="'/* FlsMaxReadNormalMode */'       "!]
        [!CALL "PrintAlign", "Str"="concat(./FlsMaxWriteFastMode,            'U')"                                     , "Cmt"="'/* FlsMaxWriteFastMode */'        "!]
        [!CALL "PrintAlign", "Str"="concat(./FlsMaxWriteNormalMode,          'U')"                                     , "Cmt"="'/* FlsMaxWriteNormalMode */'      "!]
        [!CALL "PrintAlign", "Str"="concat(count(FlsSectorList/FlsSector/*), 'U')"                                     , "Cmt"="'/* FlsSectorCount */'             "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_aFlsSectorEndAddr')"                                  , "Cmt"="'/* (*paSectorEndAddr)[] */'       "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_aFlsSectorSize')"                                     , "Cmt"="'/* (*paSectorSize)[] */'          "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_aSectorList')"                                        , "Cmt"="'/* (*pSectorList)[] */'           "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_aFlsSectorFlags')"                                    , "Cmt"="'/* (*paSectorFlags)[] */'         "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_aFlsSectorPageSize')"                                 , "Cmt"="'/* (*paSectorPageSize)[] */'      "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paHwCh')"                                             , "Cmt"="'/* (*paHwCh)[] */'                "!]
        [!CALL "PrintAlign", "Str"="concat('&', $configVSName, '_paSectorHwAddress')"                                  , "Cmt"="'/* (*paSectorHwAddress)[] */'     "!]
        [!CALL "PrintAlign", "Str"="node:when(//AutosarExt/FlsExternalSectorsConfigured = 'true', concat('&Fls_QspiConfigSet', $VSName), 'NULL_PTR')", "Cmt"="'/* FlsQspiConfig */'"!]
        [!CALL "PrintAlign", "Str"="node:when(//AutosarExt/FlsInternalSectorsConfigured = 'true', concat('&', $configVSName, '_InitCfg'), 'NULL_PTR')", "Cmt"="'/* FlsInternalConfig */'   "!]
#if (STD_ON == FLS_CHECK_CFG_CRC)
        [!CALL "PrintAlign", "Str"="concat($FlsCrcReminder, 'U')"                                                      , "Cmt"="'/* configCrc */'"     , "Comma"="0"!]
#endif
    };


    #define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Fls_MemMap.h"

[!ENDLOOP!][!//
[!ENDINDENT!][!//

#ifdef __cplusplus
}
#endif

/** @}*/

