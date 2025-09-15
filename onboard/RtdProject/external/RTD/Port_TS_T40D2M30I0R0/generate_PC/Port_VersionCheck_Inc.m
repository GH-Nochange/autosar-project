[!NOCODE!][!//
/*==================================================================================================
*   file                 : Port_VersionCheck_Inc.m
*   version              : 3.0.0
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
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

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PORT_VERSION_CHECK_INC_M'))"!]
[!VAR "PORT_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "PORT_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "PORT_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "PORT_SW_PATCH_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($PORT_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Port.epd version [!"SwMajorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($PORT_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Port.epd version [!"SwMinorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($PORT_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Port.epd version [!"SwPatchVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//
