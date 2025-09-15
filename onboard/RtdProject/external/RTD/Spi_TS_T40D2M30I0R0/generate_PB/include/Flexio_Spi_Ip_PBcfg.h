/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
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
[!CODE!][!//

#ifndef FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file     Flexio_Spi_Ip_PBcfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup FLEXIO_SPI_DRIVER_CONFIGURATION  Flexio_Spi Driver Configuration
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_PBCFG                        43
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_PBCFG         4
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_PBCFG         7
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_PBCFG      0
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_PBCFG                 3
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_PBCFG                 0
#define FLEXIO_SPI_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_PBCFG                 0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
[!CODE!]#define FLEXIO_SPI_IP_CONFIG_[!"$postBuildVariant"!]_PB[!ENDCODE!]
[!ELSE!][!//
[!CODE!]#define FLEXIO_SPI_IP_CONFIG_PB[!ENDCODE!]
[!ENDIF!][!//
    [!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
    [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!]
    [!VAR "extInstance"="node:value(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitMapping)"!]
    [!IF "contains($extInstance,'FLEXIO')"!]
        [!VAR "extInstanceIndex" = "substring-after($extInstance,'FLEXIO_SPI_')"!]
        [!CODE!] \[!CR!][!WS8!]extern const Flexio_Spi_Ip_ExternalDeviceType Flexio_Spi_Ip_DeviceAttributes_[!"@name"!]_Instance_[!"$extInstanceIndex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!]
    [!ENDIF!]
    [!ENDLOOP!]
    [!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
    [!IF "contains(node:value(SpiPhyUnitMapping),'FLEXIO_SPI')"!]
        [!VAR "InstanceIndex" = "substring-after(node:value(SpiPhyUnitMapping),'FLEXIO_SPI_')"!]
        [!CODE!] \[!CR!][!WS8!]extern const Flexio_Spi_Ip_ConfigType Flexio_Spi_Ip_PhyUnitConfig_[!"@name"!]_Instance_[!"$InstanceIndex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!ENDCODE!]
    [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif
/** @} */
[!ENDCODE!][!//

