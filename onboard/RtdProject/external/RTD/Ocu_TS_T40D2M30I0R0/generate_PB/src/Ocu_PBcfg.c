[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
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

/**
*   @file         Ocu[!"$VS_number"!]_PBcfg.c
*   @implements   Ocu_PBcfg.c_Artifact
*   @addtogroup   ocu_driver Ocu Driver
*   @brief        Ocu HLD Postbuild configuration source file.
*   @details      Postbuild configuration structure instances.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!][!//
#include "Ocu[!"$VS_number"!]_PBcfg.h"
#include "Ocu_Ipw[!"$VS_number"!]_PBcfg.h"
[!ELSE!]
#include "Ocu_PBcfg.h"
#include "Ocu_Ipw_PBcfg.h"
[!ENDIF!]
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C                       43
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C                3
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C                0
#define OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
    #error "Ocu[!"$VS_number"!]_PBcfg.c and Ocu[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ocu[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu[!"$VS_number"!]_PBcfg.c and Ocu[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ocu[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu[!"$VS_number"!]_PBcfg.c and Ocu[!"$VS_number"!]_PBcfg.h are different"
#endif

#if (OCU[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
    #error "Ocu[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (OCU[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

[!NOCODE!][!//​

/* Get max number partition is used */
[!VAR "maxPartition" = "num:i(0)"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!]

[!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]
[!VAR "max_number_partition" = "num:i($maxPartition)"!]

[!VAR "numOcuChannels" = "num:i(count(OcuConfigSet/OcuChannel/*))"!]

[!VAR "MacNumFtmChannels"="0"!]
[!VAR "MacNumEtimerChannels"="0"!]
[!VAR "MacNumEmiosChannels"="0"!]
[!VAR "MacNumGtmChannels"="0"!]

// Loop on all channels inside the same Configuration Set
[!LOOP "OcuConfigSet/OcuChannel/*"!][!//
    [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'ETIMER')"!][!//
        [!VAR "MacNumEtimerChannels"="$MacNumEtimerChannels + 1"!]
    [!ELSEIF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'FTM')"!][!//
        [!VAR "MacNumFtmChannels"="$MacNumFtmChannels + 1"!]
    [!ELSEIF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'EMIOS')"!][!//
        [!VAR "MacNumEmiosChannels"="$MacNumEmiosChannels + 1"!]
    [!ELSEIF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'GTM')"!][!//
        [!VAR "MacNumGtmChannels"="$MacNumGtmChannels + 1"!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

/* Variable storing number of maximum core_id of partitions using in configuration */
[!VAR "numPartition" = "0"!]
[!VAR "CurrentCoreId" = "0"!]

[!LOOP "OcuGeneral/OcuEcucPartitionRef/*"!]
    [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!IF "$OcuEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
            [!SELECT "node:ref(./OsApplicationCoreRef)"!]
            [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]
            [!IF "num:i($numPartition) < num:i($CurrentCoreId)"!]
                [!VAR "numPartition" = "$CurrentCoreId"!]
            [!ENDIF!]
            [!ENDSELECT!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]

[!VAR "numPartition" = "$numPartition + 1"!]

[!CODE!]
/*===============================================================================================
*                                       LOCAL MACROS
===============================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"
[!CR!][!ENDCODE!]
[!SELECT "OcuConfigSet"!]
[!CODE!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
[!ENDCODE!]
[!LOOP "OcuChannel/*"!]
    [!IF "node:exists('OcuNotification')"!]
        [!IF "(OcuNotification = '') or (OcuNotification = 'NULL_PTR') or (OcuNotification = 'NULL')"!]
        [!ELSE!]
[!CODE!]extern void [!"OcuNotification"!](void);[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
#endif
[!ENDCODE!]
[!CODE!]

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!ENDCODE!]

/*=========================================================================*/

[!VAR "numOcuChannelsInCfg" = "num:i(count(OcuChannel/*))"!]
[!IF "$max_number_ocu_cfg = 0"!]
[!CODE!]
/** @brief Number of configured Ocu channels */
#define NUMBER_CONF_CHANNEL[!"text:toupper($VS_number)"!] [!"$numOcuChannelsInCfg"!]U
[!CR!][!ENDCODE!]
[!ENDIF!]

[!LOOP "../OcuGeneral/OcuEcucPartitionRef/*"!]
    [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]
    [!VAR "channelMatched" = "0"!]

    [!LOOP "../../../OcuConfigSet/OcuChannel/*"!]
        [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
        [!VAR "OcuEcucPartitionName_Temp" = "text:split($OcuEcucPartitionRefName,'/')[5]"!]
        [!VAR "OcuEcucPartitionName" = "concat('_',$OcuEcucPartitionName_Temp)"!]
        [!VAR "OcuEcucPartitionIndex" = "substring-after($OcuEcucPartitionName_Temp,'_')"!]

        [!IF "($OcuEcucPartitionRefName = $OcuEcucPartitionChannel)"!]
            [!VAR "channelMatched"="$channelMatched + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

[!CODE!]
/** @brief  Number of configured Ocu channels in partition [!"$OcuEcucPartitionIndex"!] */
#define NUMBER_CONF_CHANNEL[!"text:toupper($VS_number)"!][!"$OcuEcucPartitionName"!]  ([!"num:i($channelMatched)"!]U)
[!CR!][!ENDCODE!]

[!ENDLOOP!]

/*============================================================
 * This MACRO will return CoreId and OcuPartitionId if it used
 * ============================================================*/
[!VAR "CoreIdDefault" = "num:i(0)"!]
 [!MACRO "Check_CoreID_Used", "Core_index"!]
     [!VAR "CoreId" = "255"!]
     [!VAR "OcuPartitionId" = "255"!]
     [!VAR "OcuPartitionId_temp" = "0"!]
[!IF "$max_number_ocu_cfg != 0"!]
     [!LOOP "../OcuGeneral/OcuEcucPartitionRef/*"!]
     [!VAR "currentPartition_temp" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
        [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$OcuEcucPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                [!IF "num:i(node:value(./EcucCoreId)) = num:i($Core_index)"!]
                    [!VAR "CoreId" = "node:value(./EcucCoreId)"!]
                    [!VAR "OcuPartitionId" = "num:i($OcuPartitionId_temp)"!]
                    [!VAR "currentPartition" = "concat('_',$currentPartition_temp)"!]
                 [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
            [!ENDLOOP!]
    [!VAR "OcuPartitionId_temp" = "num:i($OcuPartitionId_temp + 1)"!]
    [!ENDLOOP!]
[!ELSE!]
    [!IF "$Core_index = $CoreIdDefault"!]
            [!VAR "CoreId" = "$CoreIdDefault"!]
            [!VAR "OcuPartitionId" = "num:i(0)"!]
            [!VAR "currentPartition" = "''"!]
    [!ENDIF!]
[!ENDIF!]
 [!ENDMACRO!]

/*============================================================*/
/*  Macro used to generate the correspondence (translation) table between all available
    channels and the indexes of channels in the array of Ocu channels configured to use current IP */
[!MACRO "GenerateHwToLogicMap", "nameIpv", "nameIpvParticle", "numberHwChannels", "numberHwModules"!]
[!FOR "idx" = "0" TO "$numberHwModules - 1"!]
    [!VAR "maxNumChannels"="$numberHwChannels - 1"!]
    [!CODE!]
    /* Idx of channels 0 - [!"num:i($maxNumChannels)"!] of [!"$nameIpv"!] Module [!"$nameIpvParticle"!][!"num:i($idx)"!], in the array of logic Ocu channels */
    [!ENDCODE!]
    [!NOCODE!]
    /* Loop through all channels of current IP received as parameter */
    [!FOR "MacCurModChannel" = "0" TO "num:i($maxNumChannels)"!]

        [!VAR "MacChannelId" = "num:i(255)"!]

        /* Loop through all Ocu channels configured to use current IP */
        [!LOOP "OcuChannel/*"!]
            [!IF "(contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), $nameIpv))"!]

                /* Build the comment for the current Module */

                /* Get indexes of current IP and Channel of current looped Ocu channel */
                [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'GTM')"!]
                    [!VAR "MacIpModule"  = "num:i(text:split(text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements),'_')[2],'M')[2])"!]
                [!ELSE!]
                    [!VAR "MacIpModule"  = "num:i(substring-before(substring-after(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements),concat( $nameIpv ,'_')),'_CH_'))"!]
                [!ENDIF!]
                [!VAR "MacIpChannel" = "num:i(substring-after(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements),'_CH_'))"!]

                /* Check the match with the module received as parameter */
                [!IF "$MacIpModule = $idx"!]
                    /* Check the match with the channel loop var */
                    [!IF "num:i($MacIpChannel) = $MacCurModChannel"!]
                        /* Keep the index of the channel in the array of configured Ocu channels */
                        [!VAR "MacChannelId" = "num:i(./OcuChannelId)"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!CODE!]
        [!WS "4"!](Ocu_ChannelType)[!"$MacChannelId"!]U,    /* [!"$nameIpv"!]_[!"$nameIpvParticle"!][!"$idx"!]_CH_[!"$MacCurModChannel"!] */
        [!ENDCODE!]

    [!ENDFOR!]
    [!ENDNOCODE!]
[!ENDFOR!]
[!ENDMACRO!]

/*======================================================================*/
[!CODE!]
/** @brief Array of configured Ocu channels */
static const Ocu_ChannelConfigType Ocu_ConfiguredChannels_PB[!"$VS_number"!][OCU_CONF_CHANNELS_PB] = [!CR!]
{[!CR!]
[!ENDCODE!]

[!VAR "comma" = "1"!]

[!FOR "varCounter" = "0" TO "$numOcuChannels"!]
    [!LOOP "OcuChannel/*"!]
        [!IF "OcuChannelId = $varCounter"!]
            [!CODE!]
            [!WS "4"!]{
            [!WS "8"!]/** @brief [!"@name"!] OcuOutputPinUsed */
            [!IF "OcuOutputPinUsed = 'true'"!]
                [!WS "8"!](boolean)TRUE,
            [!ELSE!]
                [!WS "8"!](boolean)FALSE,
            [!ENDIF!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
            [!WS "8"!]/** @brief Ocu notification function */
            [!ENDCODE!]

            [!IF "node:exists('OcuNotification')"!]
                [!IF "(OcuNotification = '') or (OcuNotification = 'NULL_PTR') or (OcuNotification = 'NULL')"!]
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!]
                    [!WS "8"!]&[!"OcuNotification"!]
                    [!ENDCODE!]
                [!ENDIF!]
            [!ELSE!]
                [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!]
            [!ENDIF!]

            [!CODE!]
#endif
            [!WS "4"!]}[!IF "(num:i($comma))<(num:i($numOcuChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!]
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]

[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]

/*======================================================================*/
[!SELECT "../OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]

    [!IF "$max_number_ocu_cfg != 0"!]
        [!IF "$OcuPartitionId_temp = $max_number_ocu_cfg"!] [!BREAK!] [!ENDIF!]
        [!VAR "OcuEcucPartitionRefName" = "node:value(./*[$OcuPartitionId_temp + 1])"!]
        [!VAR "OcuEcucPartitionName_Temp" = "text:split($OcuEcucPartitionRefName,'/')[5]"!]
        [!VAR "OcuEcucPartitionName" = "concat('_',$OcuEcucPartitionName_Temp)"!]
        [!VAR "OcuEcucPartitionIndex" = "substring-after($OcuEcucPartitionName_Temp,'_')"!]
    [!ELSE!]
        [!VAR "OcuEcucPartitionRefName" = "''"!]
        [!VAR "OcuEcucPartitionName" = "''"!]
        [!VAR "OcuEcucPartitionIndex" = "''"!]
    [!ENDIF!]

[!CODE!][!CR!]
/** @brief    List of Ocu channel arrays used for partition [!"$OcuEcucPartitionIndex"!] */
static const Ocu_ChannelType Ocu_Channel_Use[!"$VS_number"!][!"$OcuEcucPartitionName"!][OCU_CONF_CHANNELS_PB] = [!CR!]
{[!CR!]
[!ENDCODE!]
    [!VAR "channelMatched" = "0"!]
    [!FOR "varCounter" = "0" TO "$numOcuChannels"!]
        [!LOOP "../../OcuConfigSet/OcuChannel/*"!]
            [!IF "OcuChannelId = $varCounter"!]
                [!VAR "channelMatched"="$channelMatched + 1"!]
                [!VAR "OcuEcucPartitionChannel" = "''"!]
                [!IF "$max_number_ocu_cfg != 0"!]
                    [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
                [!ENDIF!]

                [!CODE!][!WS "4"!]/** @brief [!"@name"!] */[!CR!][!ENDCODE!]

                [!IF "$OcuEcucPartitionRefName = $OcuEcucPartitionChannel"!]
                    [!CODE!][!WS "4"!](Ocu_ChannelType)OCU_VALID_CHANNEL_NUM,[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!][!WS "4"!](Ocu_ChannelType)OCU_INVALID_CHANNEL_NUM,[!CR!][!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]

[!ENDFOR!]
[!ENDSELECT!]
/* ==================================================================*/

[!CODE!][!CR!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/** @brief  Hw to logic channel map. Array containing a number of elements
            equal to total number of available channels on Ftm, eTimer, eMios, Gtm */
static const Ocu_ChannelType Ocu_InitHWMap_PB[!"$VS_number"!][OCU_NUM_HW_CHANNELS] = {[!CR!]
    [!CALL "GenerateHwToLogicMap", "nameIpv" = "'FTM'", "nameIpvParticle" = "''", "numberHwChannels" = "ecu:get('Ocu.Num_Ftm_Hw_Channels')", "numberHwModules" = "ecu:get('Ocu.Num_Ftm_Hw_Modules')"!]
    [!CALL "GenerateHwToLogicMap", "nameIpv" = "'ETIMER'", "nameIpvParticle" = "''", "numberHwChannels" = "ecu:get('Ocu.Num_Etimer_Hw_Channels')", "numberHwModules" = "ecu:get('Ocu.Num_Etimer_Hw_Modules')"!]
    [!CALL "GenerateHwToLogicMap", "nameIpv" = "'EMIOS'", "nameIpvParticle" = "''", "numberHwChannels" = "ecu:get('Ocu.Num_Emios_Hw_Channels')", "numberHwModules" = "ecu:get('Ocu.Num_Emios_Hw_Modules')"!]
    [!CALL "GenerateHwToLogicMap", "nameIpv" = "'GTM'", "nameIpvParticle" = "'TOM'", "numberHwChannels" = "ecu:get('Ocu.Num_Gtm_Tom_Hw_Channels')", "numberHwModules" = "ecu:get('Ocu.Num_Gtm_Tom_Hw_Modules')"!]
    [!CALL "GenerateHwToLogicMap", "nameIpv" = "'GTM'", "nameIpvParticle" = "'ATOM'", "numberHwChannels" = "ecu:get('Ocu.Num_Gtm_Atom_Hw_Channels')", "numberHwModules" = "ecu:get('Ocu.Num_Gtm_Atom_Hw_Modules')"!]
};
#endif
[!ENDCODE!]

/*=================================================================*/

[!FOR "PartitionIdx" = "0" TO "$max_number_partition - 1"!]
    [!CALL "Check_CoreID_Used", "Core_index" = "$PartitionIdx"!]
    
    [!IF "num:i($OcuPartitionId) != num:i(255)"!]

        [!IF "$currentPartition = ''"!]
        [!CODE!][!CR!]
/** @brief   Ocu high level configuration structure */
        [!ENDCODE!]
        [!ELSE!]
        [!CODE!][!CR!]
/** @brief   Ocu high level configuration structure for partition EcucPartition_[!"$PartitionIdx"!] */
        [!ENDCODE!]
        [!ENDIF!]
        [!NOCODE!]
        [!IF "(../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1) and (num:i($max_number_ocu_cfg) = 0)"!]
    [!CODE!]
static const Ocu_ConfigType Ocu_Config_Pc[!"$currentPartition"!] = {[!CR!]
    [!ENDCODE!]
        [!ELSE!]
    [!CODE!]
const Ocu_ConfigType Ocu_Config[!"$VS_number"!][!"$currentPartition"!] = {[!CR!]
    [!ENDCODE!]
        [!ENDIF!]
        [!ENDNOCODE!]
    [!CODE!]
    /** @brief Number of configured Ocu channels */
    (Ocu_ChannelType)NUMBER_CONF_CHANNEL[!"text:toupper($VS_number)"!][!"$currentPartition"!],
    /** @brief Pointer to array of Ocu channels */
    &Ocu_ConfiguredChannels_PB[!"$VS_number"!],[!CR!]
    [!NOCODE!]
        [!IF "((num:i($MacNumFtmChannels)) != 0) or ((num:i($MacNumEmiosChannels)) != 0) or ((num:i($MacNumEtimerChannels)) != 0) or ((num:i($MacNumGtmChannels)) != 0) "!]
        [!CODE!][!WS "4"!]/** @brief Pointer to the structure containing Ipw configuration */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Ocu_Ipw_IpCfgPB[!"$VS_number"!][!"$currentPartition"!],[!CR!][!ENDCODE!]
        [!ELSE!]
        [!CODE!][!WS "4"!]/** @brief No channel configured */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]NULL_PTR,[!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDNOCODE!]
        [!IF "node:exists(OcuCountdirection)"!]
            [!IF "OcuCountdirection = 'OCU_DOWNCOUNTING'"!]
#if (STD_ON == OCU_DOWNCOUNTING_SUPPORED)
    /** @brief Counter direction */
    OCU_DOWNCOUNTING,
#endif
            [!ENDIF!]
        [!ENDIF!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    &Ocu_InitHWMap_PB[!"$VS_number"!],
#endif
    &Ocu_Channel_Use[!"$VS_number"!][!"$currentPartition"!],
    /** @brief Index ECUC Partition [!"$PartitionIdx"!] */
    (uint8)[!"$PartitionIdx"!]U,
};[!CR!]
/*======================= End Partition [!"$PartitionIdx"!] ===========================*/[!CR!][!CR!]
    [!ENDCODE!]
    [!ELSE!]
        [!CODE!]/** @brief  No configuration structure of OCU refered by Partition [!"$PartitionIdx"!] */[!CR!]
/*======================= End Partition [!"$PartitionIdx"!] ===========================*/[!CR!][!CR!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]

/*====================================================*/

[!IF "(../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]
[!CODE!][!CR!][!CR!]
/** @brief   Array of pointers to Ocu high level config structures */
const Ocu_ConfigType * const Ocu_gapcxConfig[OCU_MAX_PARTITIONS] = {[!CR!]
[!ENDCODE!]

[!FOR "PartitionIdx" = "0" TO "$max_number_partition - 1"!]
    [!CALL "Check_CoreID_Used", "Core_index" = "$PartitionIdx"!]
    [!IF "num:i($OcuPartitionId) != num:i(255)"!]
    [!IF "(variant:size() <= 1) and (num:i($max_number_ocu_cfg) = 0)"!]
        [!CODE!][!WS "4"!]/** @brief  Pointer to configuration structure of Ocu for partition reference to partition [!"num:i($PartitionIdx)"!] */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Ocu_Config_Pc[!"$currentPartition"!],[!CR!][!ENDCODE!]
    [!ELSE!]
        [!CODE!][!WS "4"!]/** @brief  Pointer to configuration structure of Ocu for partition reference to partition [!"num:i($PartitionIdx)"!] */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Ocu_Config[!"$VS_number"!][!"$currentPartition"!],[!CR!][!ENDCODE!]
    [!ENDIF!]
    [!ELSE!]
        [!CODE!][!WS "4"!]/** @brief  No configuration structure of OCU refered by partition [!"num:i($PartitionIdx)"!] */
        [!WS "4"!]NULL_PTR,[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]

[!CODE!]
};
[!ENDCODE!]

[!ENDIF!]


[!ENDSELECT!]
[!ENDNOCODE!]

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
