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
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantName" = "concat($postBuildVariant, '_')"!][!//
[!VAR "variantNameUpperCase" = "text:toupper($variantName)"!][!//
[!ENDIF!][!//

#ifndef FLS_[!"$variantNameUpperCase"!]PBCFG_H
#define FLS_[!"$variantNameUpperCase"!]PBCFG_H

/**
 *   @file       Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
 *
 *   @addtogroup FLS
 *   @implements Fls_PBcfg.h_Artifact
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


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_[!"$variantNameUpperCase"!]PBCFG_VENDOR_ID                    43

#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_MINOR_VERSION     4
#define FLS_[!"$variantNameUpperCase"!]PBCFG_AR_RELEASE_REVISION_VERSION  0

#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MAJOR_VERSION             3
#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_MINOR_VERSION             0
#define FLS_[!"$variantNameUpperCase"!]PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/

[!NOCODE!]
[!VAR "variantSize" = "variant:size()"!][!//
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and ($variantSize <= 1))"!] [!//
    [!IF "var:defined('postBuildVariant')"!][!//
        [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
        [!CODE!]#define FLS_CONFIG_[!"text:toupper($postBuildVariant)"!]_PB \[!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
        [!CODE!]#define FLS_CONFIG_PB \[!CR!][!ENDCODE!]
    [!ENDIF!][!//
    [!CODE!][!WS "4"!]extern const Fls_ConfigType Fls_Config[!"$postBuildVariantNameUnderscore"!];[!ENDCODE!][!CR!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

[!INDENT "0"!] [!//
[!LOOP "FlsConfigSet"!][!//
    [!IF "num:i(count(FlsExternalDriver/FlsMem/*)) > 0"!][!//
        [!VAR "FlsSfdpIt" = "0"!][!//
        [!LOOP "FlsExternalDriver/FlsMem/*"!][!//
            [!IF "./FlsMemUseSfdp ='true'"!][!//
            [!VAR "FlsSfdpIt" = "$FlsSfdpIt + 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!WS "0"!]/* Number of flash devices using SFDP */
        [!WS "0"!]#define FLS_DEVICES_USING_SFDP    [!"num:i($FlsSfdpIt)"!]U
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/**@}*/

#endif    /* #ifndef FLS_[!"$variantNameUpperCase"!]PBCFG_H */

