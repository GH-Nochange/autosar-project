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

#ifndef CDD_I2C_CFGDEFINES_H
#define CDD_I2C_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup I2c_driver_config I2c Driver Configuration
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
#define CDD_I2C_VENDOR_ID_CFGDEFINES                    43
#define CDD_I2C_MODULE_ID_CFGDEFINES                    255
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define CDD_I2C_AR_RELEASE_MINOR_VERSION_CFGDEFINES     7
#define CDD_I2C_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define CDD_I2C_SW_MAJOR_VERSION_CFGDEFINES             3
#define CDD_I2C_SW_MINOR_VERSION_CFGDEFINES             0
#define CDD_I2C_SW_PATCH_VERSION_CFGDEFINES             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*/
#define I2C_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief   Total number of I2c channel configured.
*/
#define I2C_HW_MAX_CONFIG           ([!"num:i(count(I2cGlobalConfig/I2cChannel/*))"!]U)

/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_HW_MAX_MODULES          ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')))"!]U)

/**
* @brief   Total number of available hardware Lpi2c channels.
*/
#define I2C_LPI2C_MAX_MODULES       ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')[contains(., 'LPI2C')]))"!]U)

/**
* @brief            This is the ID of the first FLEXIO channel.
*/
#define I2C_FLEXIO_FIRST_CHANNEL_U8   (I2C_LPI2C_MAX_MODULES)

/**
* @brief            TIMEOUT for sync transmissions
*/
#define I2C_TIMEOUT ([!"GeneralConfiguration/I2cTimeoutDuration"!]U)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*/
#define I2C_DEV_ERROR_DETECT      [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
*/
#define I2C_VERSION_INFO_API      [!IF "GeneralConfiguration/I2cVersionInfoApi"!](STD_ON)  /* Enable API I2c_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API I2c_GetVersionInfo     */[!ENDIF!]

/**
* @brief   I2c Support High-speed mode for Controller.
*/
#define I2C_CTRL_HS_MODE_AVAILABLE       (LPI2C_IP_FEATURE_CTRL_HS_MODE_AVAILABLE)

[!NOCODE!]
[!IF "variant:size()<=1"!][!//
[!CODE!]
/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
*/
[!ENDCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('I2c.I2cGlobalConfig.I2cChannel'))-1"!]
    [!VAR "ChannelFound" = "0"!]
    [!VAR "I2cEcuHwChannel" = "string((ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel'))[$index+1])"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!]
        [!VAR "HardwareChannel" = "string(I2cHwChannel)"!]
        [!IF "$I2cEcuHwChannel = $HardwareChannel"!]
            [!IF "$ChannelFound = 0"!]
[!CODE!]
#define I2C_[!"$I2cEcuHwChannel"!]    ([!"num:i($index)"!]U)
[!ENDCODE!]
                [!VAR "ChannelFound" = "1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!CODE!]
/**
* @brief  I2c channel name to logic channel id mapping
*/
[!ENDCODE!]
    [!VAR "I2cMasterNumber" = "num:i(0)"!]
    [!VAR "I2cSlaveNumber" = "num:i(0)"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!][!//
        [!VAR "I2cMasterSlave" = "node:value(I2cMasterSlaveConfiguration)"!]
            [!CODE!]
#define [!"@name"!]                 ([!"node:value(I2cChannelId)"!]U)[!CR!][!//
            [!ENDCODE!]
        [!IF "$I2cMasterSlave = 'MASTER_MODE'"!]
            [!CODE!]
#define I2C_MASTER_[!"$I2cMasterNumber"!]             [!"@name"!][!CR!][!//
            [!VAR "I2cMasterNumber" = "num:i($I2cMasterNumber + 1)"!]
            [!ENDCODE!]
        [!ELSE!]
            [!CODE!]
#define I2C_SLAVE_[!"$I2cSlaveNumber"!]               [!"@name"!][!CR!][!//
            [!VAR "I2cSlaveNumber" = "num:i($I2cSlaveNumber + 1)"!]
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDNOCODE!]

[!IF "as:modconf('I2c')[1]/GeneralConfiguration/I2cMultipartitionSupport='true'"!]
[!CODE!]
/**
* @brief          Unallocate partition id.
* @details        If have any channel not allocate to partition
*
* @api
*/
#define I2C_UNALLOCATED_PARTITION_ID    ([!"num:i(255)"!]U)
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!]
/**
* @brief          Spurious partition id.
* @details        If multi partition support disable
*
* @api
*/
#define I2C_SPURIOUS_PARTITION_ID        ([!"num:i(0)"!]U)
[!ENDCODE!][!//
[!ENDIF!][!//

/**
* @brief          Symbolic names for configured channels.
*/
[!LOOP "I2cGlobalConfig/I2cChannel/*"!][!//
#define I2cConf_I2cChannel_[!"node:name(.)"!]  ([!"I2cChannelId"!]U)
[!ENDLOOP!][!//


/**
* @brief          FlexIO is used (STD_ON/STD_OFF)
*/
#define I2C_FLEXIO_USED   [!IF "(GeneralConfiguration/I2cFlexIOUsed='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!//

[!LOOP "I2cGlobalConfig/*/I2cChannel/*"!][!//
[!IF "contains(I2cHwChannel, 'FLEXIO')"!][!//
#define I2C_[!"node:value(I2cHwChannel)"!]_USED
#define I2C_[!"node:value(I2cHwChannel)"!]_ISR_USED
#define I2C_FLEXIO_0_PIN_[!"substring-after(I2cFlexIOConfiguration/I2cFlexIOSclPin,'FXIO_D')"!]_USED
#define I2C_FLEXIO_0_PIN_[!"substring-after(I2cFlexIOConfiguration/I2cFlexIOSdaPin,'FXIO_D')"!]_USED
[!ENDIF!][!//
[!ENDLOOP!][!//

/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define I2C_DISABLE_DEM_REPORT_ERROR_STATUS   [!IF "(GeneralConfiguration/I2cDisableDemReportErrorStatus='false')"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!][!//

/**
* @brief            Enable/Disable Multi Partition Support.
*/
#define I2C_MULTIPARTITION_SUPPORT  [!IF "(GeneralConfiguration/I2cMultipartitionSupport='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            DMA is used for at least one channel (STD_ON/STD_OFF)
*/
[!CODE!][!//
#define I2C_DMA_USED   [!IF "(GeneralConfiguration/I2cDmaUsed='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#if (I2C_MULTIPARTITION_SUPPORT == STD_ON)
    #define I2c_GetUserID()            OsIf_GetUserId()
#else
    #define I2c_GetUserID()            ((uint32)0UL)
#endif /* (I2C_MULTIPARTITION_SUPPORT == STD_ON) */

[!ENDCODE!][!//

[!IF "node:exists(GeneralConfiguration/I2cCallback)"!]
[!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!]
/**
* @brief            I2c slave bit error event
*/
#define  I2C_EVENT_BIT_ERROR_SLAVE  (0x00U)

/**
* @brief            I2c slave underrun event
*/
#define  I2C_EVENT_UNDERRUN_SLAVE  (0x01U)

/**
* @brief            I2c slave overrun event
*/
#define  I2C_EVENT_OVERRUN_SLAVE  (0x02U)
[!ENDIF!]
/**
* @brief            I2c slave rx buffer full
*/
#define  I2C_EVENT_RX_FULL_SLAVE  (0x03U)

/**
* @brief            I2c slave tx buffer empty
*/
#define  I2C_EVENT_TX_EMPTY_SLAVE  (0x04U)

/**
* @brief            I2c slave tx request
*/
#define  I2C_EVENT_TX_REQ_SLAVE (0x05U)

/**
* @brief            I2c slave rx request
*/
#define  I2C_EVENT_RX_REQ_SLAVE (0x06U)

/**
* @brief            I2c slave stop transfer
*/
#define  I2C_EVENT_STOP_SLAVE (0x07U)
[!IF "node:exists(GeneralConfiguration/I2cErrorCallback)"!]
/**
* @brief            I2c NACK event
*/
#define  I2C_EVENT_NACK_MASTER  (0x08U)

/**
* @brief            I2c master arbitration lost event
*/
#define  I2C_EVENT_ARBITRATION_LOST_MASTER  (0x09U)

/**
* @brief            I2c master fifo error
*/
#define  I2C_EVENT_ERROR_FIFO_MASTER  (0x0AU)
[!ENDIF!]
/**
* @brief            I2c master end transfer
*/
#define I2C_EVENT_END_TRANSFER_MASTER  (0x0BU)

/**
* @brief            I2c master pin low timeout
*/
#define I2C_EVENT_PIN_LOW_TIMEOUT_MASTER  (0x0CU)

/**
* @brief            I2c master dma transfer error event
*/
#define I2C_EVENT_DMA_TRANSFER_ERROR_MASTER (0x0DU)

/**
* @brief            I2c slave dma transfer error event
*/
#define I2C_EVENT_DMA_TRANSFER_ERROR_SLAVE (0x0EU)
[!ENDIF!]

/**
* @brief        Variable storing number of maximum partitions using in configuration.
*/
[!NOCODE!][!//
[!VAR "MaxPartition"="0"!]
[!IF "as:modconf('I2c')[1]/GeneralConfiguration/I2cMultipartitionSupport='true'"!][!//
[!IF "node:containsValue(OsIfGeneral/OsIfUseGetUserId, 'GET_PARTITION_ID')"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
        [!VAR "MaxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
    [!ENDIF!]
[!ELSE!]
    [!LOOP "as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*"!][!//
            [!IF "$MaxPartition < node:value(./EcucCoreId)"!]
                [!VAR "MaxPartition"="node:value(./EcucCoreId)"!]
            [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//

#define I2C_MAX_PARTITION_ID     ((uint8)[!"num:i($MaxPartition+1)"!]U)

/**
* @brief    The value initialization un init for each partition.
*/
#define I2C_UNINIT_PARTITION \
{[!//
[!NOCODE!]
    [!VAR "FirstPartition"="num:i(1)"!]
    [!FOR "Partitionid"="0" TO "$MaxPartition"!]
[!IF "$FirstPartition = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstPartition"="num:i(0)"!][!ENDIF!][!CODE!] I2C_UNINIT[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}

/**
* @brief    The value initialization null pointer for each partition.
*/
#define I2C_NULL_PTR \
{[!//
[!NOCODE!]
    [!VAR "FirstPartition"="num:i(1)"!]
    [!FOR "Partitionid"="0" TO "$MaxPartition"!]
[!IF "$FirstPartition = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstPartition"="num:i(0)"!][!ENDIF!][!CODE!] NULL_PTR[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}

[!NOCODE!][!//
[!VAR "HwMaxChannel" = "num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')))"!]
[!ENDNOCODE!][!//
/**
* @brief        The value initialization Hardware Map.
*/
#define I2C_HW_MAP_INIT \
{[!//
[!NOCODE!]
    [!VAR "FirstChannel"="num:i(1)"!]
    [!FOR "Channel"="0" TO "$HwMaxChannel - 1"!]
[!IF "$FirstChannel = num:i(0)"!][!CODE!],[!ENDCODE!][!ELSE!][!VAR "FirstChannel"="num:i(0)"!][!ENDIF!][!CODE!] 0xFFU[!ENDCODE!][!//
    [!ENDFOR!]
[!ENDNOCODE!][!//
}
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
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

#endif /* CDD_I2C_CFGDEFINES_H */
