/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530
*
* Copyright 2020-2025 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may
* only be used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_I2C_CFG_H
#define CDD_I2C_CFG_H

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
[!CODE!]#include "CDD_I2c_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!]#include "CDD_I2c_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_I2C_VENDOR_ID_CFG                    43
#define CDD_I2C_MODULE_ID_CFG                    255
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFG     4
#define CDD_I2C_AR_RELEASE_MINOR_VERSION_CFG     7
#define CDD_I2C_AR_RELEASE_REVISION_VERSION_CFG  0
#define CDD_I2C_SW_MAJOR_VERSION_CFG             3
#define CDD_I2C_SW_MINOR_VERSION_CFG             0
#define CDD_I2C_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h header file are of the same module */
#if (CDD_I2C_MODULE_ID_CFG  != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_MODULE_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h have different module ids"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_[!"."!]_PBcfg.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_I2C_SW_MINOR_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_SW_MINOR_VERSION) || \
     (CDD_I2C_SW_PATCH_VERSION_CFG != CDD_I2C_[!"text:toupper(.)"!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same module */
#if (CDD_I2C_MODULE_ID_CFG  != CDD_I2C_PBCFG_MODULE_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h have different module ids"
#endif
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same vendor */
#if (CDD_I2C_VENDOR_ID_CFG != CDD_I2C_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same Autosar version */
#if ((CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFG != CDD_I2C_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_MINOR_VERSION_CFG != CDD_I2C_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_I2C_AR_RELEASE_REVISION_VERSION_CFG != CDD_I2C_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same Software version */
#if ((CDD_I2C_SW_MAJOR_VERSION_CFG != CDD_I2C_PBCFG_SW_MAJOR_VERSION) || \
     (CDD_I2C_SW_MINOR_VERSION_CFG != CDD_I2C_PBCFG_SW_MINOR_VERSION) || \
     (CDD_I2C_SW_PATCH_VERSION_CFG != CDD_I2C_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!] [!//
/**
* @brief   macro contains all PB configuration macros.
*/
#define I2C_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantIndex"="0"!][!//
[!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
 I2C_CONFIG_[!"text:toupper(.)"!]_PB [!IF "$variantIndex < $variantNumber"!]\[!ENDIF!]
[!ENDLOOP!][!//
[!ELSE!][!//
 I2C_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(GeneralConfiguration/I2cCallback)"!][!//
/**
* @brief            The callback configured by the user for i2c events.
*/

#define I2C_MODULE_CALLBACK(Event, Channel) ([!"normalize-space(GeneralConfiguration/I2cCallback)"!](Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c events.
*/
extern void I2C_MODULE_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
[!ENDIF!][!//

[!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!][!//
/**
* @brief            The callback configured by the user for i2c error events.
*/

#define I2C_ERROR_CALLBACK(Event, Channel) ([!"normalize-space(GeneralConfiguration/I2cErrorCallback)"!](Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c error events.
*/
extern void I2C_ERROR_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
[!ENDIF!][!//

[!MACRO "I2cExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(I2cGlobalConfig)"!][!//
[!CODE!][!//

/**
* @brief            Pre-Compile structure from CDD_I2c_Cfg.c file.
*/
#define I2C_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern const I2c_ConfigType [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern const I2c_ConfigType [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "I2cExportDriverConfiguration"!]
[!ENDIF!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHERS
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

/** @} */

#endif /* CDD_I2C_CFG_H */

