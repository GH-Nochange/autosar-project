[!NOCODE!][!//

/*!
*   @file    Ocu_VersionCheck_Src.m
*   @version 3.0.0
*
*   @brief   AUTOSAR Ocu macro to check for notification config, variant post-build
*   @details    macro to check for notification config, variant pre-compile
*
*   @addtogroup   ocu_driver Ocu Driver
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
[!ENDNOCODE!][!//


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('OCU_VERSION_CHECK_SRC_M'))"!]
[!VAR "OCU_VERSION_CHECK_SRC_M"="'true'"!]


[!VAR "OCU_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCU_AR_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "OCU_AR_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "OCU_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "OCU_SW_MINOR_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!ASSERT "ArReleaseMajorVersion   = num:i($OCU_AR_MAJOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR major version number of the Basic Software Module Description file (Ocu.epd version [!"ArReleaseMajorVersion"!]) and the Code template files (Ocu_Cfg.c version [!"num:i($OCU_AR_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseMinorVersion  = num:i($OCU_AR_MINOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR minor version number of the Basic Software Module Description file (Ocu.epd version [!"ArReleaseMinorVersion"!]) and the Code template files ( Ocu_Cfg.c version [!"num:i($OCU_AR_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($OCU_AR_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseRevisionVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_AR_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!ASSERT "SwMajorVersion = num:i($OCU_SW_MAJOR_VERSION_TEMPLATE)"!]
        **** The software major number of the Basic Software Module Description file (Ocu.epd version [!"SwMajorVersion"!]) and the Code template files (Ocu_Cfg.c version [!"num:i($OCU_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMinorVersion = num:i($OCU_SW_MINOR_VERSION_TEMPLATE)"!]
        **** The software minor number of the Basic Software Module Description file (Ocu.epd version [!"SwMinorVersion"!]) and the Code template files ( Ocu_Cfg.c version [!"num:i($OCU_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//


[!ENDIF!][!// avoid multiple inclusion ENDIF

