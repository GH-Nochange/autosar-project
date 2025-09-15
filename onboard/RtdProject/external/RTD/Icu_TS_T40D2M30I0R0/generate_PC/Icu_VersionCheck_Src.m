[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ICU_VERSIONCHECK_SRC_M'))"!]
[!VAR "ICU_VERSIONCHECK_SRC_M"="'true'"!]
[!NOCODE!][!//
/**
*   @file    Icu_VersionCheck_Src.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Icu - version check macro.
*   @details Version checks.
*
*   @addtogroup ICU
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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
/*==================================================================================================
==================================================================================================*/

[!VAR "ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "ICU_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "ICU_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!/*
[!ASSERT "ArReleaseMajorVersion = num:i($ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release major version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Icu_Cfg.c version [!"num:i($ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseMinorVersion  = num:i($ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release minor version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Icu_Cfg.c version [!"num:i($ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseRevisionVersion  = num:i($ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]
        **** AUTOSAR release revision version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Icu_Cfg.c version [!"num:i($ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
*/!]
[!ASSERT "SwMajorVersion = num:i($ICU_SW_MAJOR_VERSION_TEMPLATE)"!]
        **** The software major number of the Basic Software Module Description file (Icu.epd version [!"SwMajorVersion"!]) and the Code template file (Icu_Cfg.c version [!"num:i($ICU_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMinorVersion = num:i($ICU_SW_MINOR_VERSION_TEMPLATE)"!]
        **** The software minor number of the Basic Software Module Description file (Icu.epd version [!"SwMinorVersion"!]) and the Code template file (Icu_Cfg.c version [!"num:i($ICU_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDIF!]