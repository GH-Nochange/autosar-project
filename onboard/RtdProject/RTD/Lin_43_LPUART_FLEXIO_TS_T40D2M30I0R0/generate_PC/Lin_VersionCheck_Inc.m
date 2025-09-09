[!NOCODE!][!//
/**
    @file    LIN_VersionCheck_Inc.m
    @version 3.0.0

    @brief   AUTOSAR Lin_43_LPUART_FLEXIO - Brief description.
    @details Version check variables vor Lin_Cfg.h

    Project RTD AUTOSAR 4.7
    Patform CORTEXM
    Peripheral LPUART_FLEXIO
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530

    Copyright 2020-2025 NXP

    NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms. If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
*/
/*==================================================================================================
==================================================================================================*/
[!VAR "LIN_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "LIN_AR_MINOR_VERSION_TEMPLATE"="7"!][!//
[!VAR "LIN_AR_PATCH_VERSION_TEMPLATE"="0"!][!//
[!VAR "LIN_SW_MAJOR_VERSION_TEMPLATE"="3"!][!//
[!VAR "LIN_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "LIN_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "num:i(ArReleaseMajorVersion) != num:i($LIN_AR_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR major version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Lin_Cfg.h  version [!"num:i($LIN_AR_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseMinorVersion)  != num:i($LIN_AR_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR minor version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Lin_Cfg.h  version [!"num:i($LIN_AR_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(ArReleaseRevisionVersion)  != num:i($LIN_AR_PATCH_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** AUTOSAR patch version number of the Basic Software Module Description file (Lin.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Lin_Cfg.h version [!"num:i($LIN_AR_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMajorVersion) != num:i($LIN_SW_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** The software major number of the Basic Software Module Description file (Lin.epd version [!"SwMajorVersion"!]) and the Code template file (Lin_Cfg.h version [!"num:i($LIN_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "num:i(SwMinorVersion) != num:i($LIN_SW_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
          **** The software minor number of the Basic Software Module Description file (Lin.epd version [!"SwMinorVersion"!]) and the Code template file (Lin_Cfg.h version [!"num:i($LIN_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($LIN_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
      **** The software patch number of the Basic Software Module Description file (Lin.epd version [!"SwPatchVersion"!]) and the Code template file (Lin_Cfg.h version [!"num:i($LIN_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//
