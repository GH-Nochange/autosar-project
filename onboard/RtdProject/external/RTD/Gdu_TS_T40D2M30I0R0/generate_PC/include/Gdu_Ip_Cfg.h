/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_GDU
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

#ifndef GDU_IP_CFG_H
#define GDU_IP_CFG_H

/**
*   @file    Gdu_Ip_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Gdu - IPV_GDU precompile configuration header.
*
*   @addtogroup IPV_GDU
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Gdu_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Gdu_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GDU_IP_CFG_VENDOR_ID                    43
#define GDU_IP_CFG_MODULE_ID                    123
#define GDU_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define GDU_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define GDU_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define GDU_IP_CFG_SW_MAJOR_VERSION             3
#define GDU_IP_CFG_SW_MINOR_VERSION             0
#define GDU_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]
/* Checks against Gdu_Ip_[!"."!]_PBcfg.h */
#if (GDU_IP_CFG_VENDOR_ID != GDU_IP_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
    #error "Gdu_Ip_Cfg.h and Gdu_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((GDU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != GDU_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_CFG_AR_RELEASE_MINOR_VERSION    != GDU_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_CFG_AR_RELEASE_REVISION_VERSION != GDU_IP_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gdu_Ip_Cfg.h and Gdu_Ip_[!"."!]_PBcfg.h are different"
#endif
#if ((GDU_IP_CFG_SW_MAJOR_VERSION != GDU_IP_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_IP_CFG_SW_MINOR_VERSION != GDU_IP_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
     (GDU_IP_CFG_SW_PATCH_VERSION != GDU_IP_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gdu_Ip_Cfg.h and Gdu_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]
/* Checks against Gdu_Ip_PBcfg.h */
#if (GDU_IP_CFG_VENDOR_ID != GDU_IP_PBCFG_VENDOR_ID)
    #error "Gdu_Ip_Cfg.h and Gdu_Ip_PBcfg.h have different vendor ids"
#endif
#if ((GDU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != GDU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GDU_IP_CFG_AR_RELEASE_MINOR_VERSION    != GDU_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (GDU_IP_CFG_AR_RELEASE_REVISION_VERSION != GDU_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gdu_Ip_Cfg.h and Gdu_Ip_PBcfg.h are different"
#endif
#if ((GDU_IP_CFG_SW_MAJOR_VERSION != GDU_IP_PBCFG_SW_MAJOR_VERSION) || \
     (GDU_IP_CFG_SW_MINOR_VERSION != GDU_IP_PBCFG_SW_MINOR_VERSION) || \
     (GDU_IP_CFG_SW_PATCH_VERSION != GDU_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gdu_Ip_Cfg.h and Gdu_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** The configured notification functions */
#define GDU_IP_HDHVD_NOTIFICATION [!IF "node:exists(GduGeneral/GduHDHighVoltageDetectNotification)"!]&[!"GduGeneral/GduHDHighVoltageDetectNotification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSHS0_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationHighSide0Notification)"!]&[!"GduGeneral/GduDesaturationHighSide0Notification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSHS1_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationHighSide1Notification)"!]&[!"GduGeneral/GduDesaturationHighSide1Notification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSHS2_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationHighSide2Notification)"!]&[!"GduGeneral/GduDesaturationHighSide2Notification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSLS0_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationLowSide0Notification)"!]&[!"GduGeneral/GduDesaturationLowSide0Notification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSLS1_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationLowSide1Notification)"!]&[!"GduGeneral/GduDesaturationLowSide1Notification"!][!ELSE!]NULL_PTR[!ENDIF!]
#define GDU_IP_DSLS2_NOTIFICATION [!IF "node:exists(GduGeneral/GduDesaturationLowSide2Notification)"!]&[!"GduGeneral/GduDesaturationLowSide2Notification"!][!ELSE!]NULL_PTR[!ENDIF!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!]
[!IF "(node:exists(GduGeneral/GduHDHighVoltageDetectNotification) and (GduGeneral/GduHDHighVoltageDetectNotification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide0Notification) and (GduGeneral/GduDesaturationHighSide0Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide1Notification) and (GduGeneral/GduDesaturationHighSide1Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide2Notification) and (GduGeneral/GduDesaturationHighSide2Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide0Notification) and (GduGeneral/GduDesaturationLowSide0Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide1Notification) and (GduGeneral/GduDesaturationLowSide1Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide2Notification) and (GduGeneral/GduDesaturationLowSide2Notification != 'NULL_PTR'))"!]
[!CODE!]
#define GDU_START_SEC_CODE
#include "Gdu_MemMap.h"


[!ENDCODE!]
[!ENDIF!]

[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//

[!IF "node:exists(GduGeneral/GduHDHighVoltageDetectNotification) and (GduGeneral/GduHDHighVoltageDetectNotification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduHDHighVoltageDetectNotification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduHDHighVoltageDetectNotification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduHDHighVoltageDetectNotification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]

[!IF "node:exists(GduGeneral/GduDesaturationHighSide0Notification) and (GduGeneral/GduDesaturationHighSide0Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationHighSide0Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationHighSide0Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationHighSide0Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]

[!IF "node:exists(GduGeneral/GduDesaturationHighSide1Notification) and (GduGeneral/GduDesaturationHighSide1Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationHighSide1Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationHighSide1Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationHighSide1Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]
[!IF "node:exists(GduGeneral/GduDesaturationHighSide2Notification) and (GduGeneral/GduDesaturationHighSide2Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationHighSide2Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationHighSide2Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationHighSide2Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]
[!IF "node:exists(GduGeneral/GduDesaturationLowSide0Notification) and (GduGeneral/GduDesaturationLowSide0Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationLowSide0Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationLowSide0Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationLowSide0Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]
[!IF "node:exists(GduGeneral/GduDesaturationLowSide1Notification) and (GduGeneral/GduDesaturationLowSide1Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationLowSide1Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationLowSide1Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationLowSide1Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]
[!IF "node:exists(GduGeneral/GduDesaturationLowSide2Notification) and (GduGeneral/GduDesaturationLowSide2Notification != 'NULL_PTR')"!]
    [!IF "contains($AlreadyParsedNotification, concat(GduGeneral/GduDesaturationLowSide2Notification,'|')) = false()"!][!//
    [!CODE!]
/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        This is the notification called when GDU_INT is asserted.
*
* @pre          GDU is initialized and the triggered interrupt flags are enabled
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
[!"concat('extern void ', GduGeneral/GduDesaturationLowSide2Notification,'(void);')"!]
    [!ENDCODE!]
    [!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,GduGeneral/GduDesaturationLowSide2Notification,'|')"!][!//
    [!ENDIF!]
[!ENDIF!]


[!IF "(node:exists(GduGeneral/GduHDHighVoltageDetectNotification) and (GduGeneral/GduHDHighVoltageDetectNotification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide0Notification) and (GduGeneral/GduDesaturationHighSide0Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide1Notification) and (GduGeneral/GduDesaturationHighSide1Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationHighSide2Notification) and (GduGeneral/GduDesaturationHighSide2Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide0Notification) and (GduGeneral/GduDesaturationLowSide0Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide1Notification) and (GduGeneral/GduDesaturationLowSide1Notification != 'NULL_PTR')) or (node:exists(GduGeneral/GduDesaturationLowSide2Notification) and (GduGeneral/GduDesaturationLowSide2Notification != 'NULL_PTR'))"!]
[!CODE!]
#define GDU_STOP_SEC_CODE
#include "Gdu_MemMap.h"
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GDU_IP_CFG_H */
