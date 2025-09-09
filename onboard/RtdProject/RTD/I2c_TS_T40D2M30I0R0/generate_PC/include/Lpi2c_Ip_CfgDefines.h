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

#ifndef LPI2C_IP_CFGDEFINES_H
#define LPI2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION LPI2C Driver Configurations
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
#include "[!"ecu:get('I2c.Lpi2c.I2cHeaderName')"!].h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_CFGDEFINES_VENDOR_ID                     43
#define LPI2C_IP_CFGDEFINES_MODULE_ID                     255
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      7
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION              3
#define LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION              0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

[!IF "ecu:get('I2c.I2cUnifiedInterrupts') = 'TRUE'"!]
/**
* @brief   Unified Interrupt.
*/
#define LPI2C_IP_COMMON_IRQ_MASTER_AND_SLAVE
[!ENDIF!]

/**
* @brief            Error detection for IP layer
*/
#define LPI2C_IP_DEV_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]

/**
* @brief            Error events of the i2c module enable/disabled
*/
#define LPI2C_IP_EVENT_ERROR_DETECT   [!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!](STD_ON)  /* Enable Development Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Development Error Detection for IP */[!ENDIF!]

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define LPI2C_IP_DMA_TRANSFER_ERROR_DETECT   [!IF "GeneralConfiguration/I2cDmaTransferErrorDetect"!](STD_ON)  /* Enable Dma Transfer Error Detection for IP */[!ELSE!](STD_OFF) /* Disable Dma Transfer Error Detection for IP */[!ENDIF!]

/**
* @brief            Dma support enable/disabled
*/
#define LPI2C_IP_DMA_FEATURE_AVAILABLE [!IF "GeneralConfiguration/I2cDmaUsed"!](STD_ON)  /* Enable DMA support for IP */[!ELSE!](STD_OFF) /* Disable DMA support for IP */[!ENDIF!]

/**
* @brief            LPI2C timeout type
*/
#define I2C_TIMEOUT_TYPE                ([!"GeneralConfiguration/I2cTimeoutMethod"!])

/**
* @brief            The offset value will start with the first Lpi2c instance of the hardware
*/
#define LPI2C_IP_OFFSET_INSTANCE                ([!"ecu:get('I2c.Lpi2c.OffsetValue')"!]U)

[!IF "ecu:get('I2c.Lpi2c.DetectSTARTAvailable') = 'TRUE'"!]

/**
* @brief            Support detect start condition
*/

#define LPI2C_IP_FEATURE_DETECT_START_CONDITION
[!ENDIF!]

[!IF "ecu:get('I2c.Lpi2c.RelaxModeAvailable') = 'TRUE'"!]

/**
* @brief            Support Relax Mode
*/

#define LPI2C_IP_FEATURE_RELAX_MODE_AVAILABLE
[!ENDIF!]

/**
* @brief   Lpi2c Support High-speed mode for Controller.
*/
#define LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE    [!IF "ecu:get('I2c.Lpi2c.HsModeControllerAvailable') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*
* @brief   ERR052121: LPI2C: NACK Detect Flag can be set when IGNACK=1.
*/
#define ERRATA_ERR052121          [!IF "ecu:get('I2c.Lpi2c.ERRATA_ERR052121') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
 * @brief The reset value of the MSR register
 */
#define LPI2C_IP_MSR_RESET_VALUE ([!"ecu:get('I2c.Lpi2c.MSR.Reset.Value.U32')"!])

/**
 * @brief The reset value of the SSR register
 */
#define LPI2C_IP_SSR_RESET_VALUE ([!"ecu:get('I2c.Lpi2c.SSR.Reset.Value.U32')"!])

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPI2C_IP_CFGDEFINES_H */
