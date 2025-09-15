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
*   @file         Ocu_Ipw[!"$VS_number"!]_PBcfg.c
*
*   @internal     
*   @addtogroup   ocu_ipw Ocu IPW
*   @brief        Ocu IPW Postbuild configuration source file.
*   @details
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

#include "Ocu_Ipw[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C                       43
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C                3
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C                0
#define OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_VENDOR_ID)
    #error "Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ocu_Ipw[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MAJOR_VERSION) || \
     (OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_MINOR_VERSION) || \
     (OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION_C != OCU_IPW[!"text:toupper($VS_number)"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw[!"$VS_number"!]_PBcfg.c and Ocu_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!NOCODE!]
[!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]
[!VAR "numOcuChannels" = "num:i(count(../../OcuConfigSet/OcuChannel/*))"!]
[!VAR "numFtmHwModules" = "ecu:get('Ocu.Num_Ftm_Hw_Modules')"!]
[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!VAR "OcuEcucPartitionChannel" = "''"!]
    [!VAR "AlreadyParsedFtmInstances" = "''"!]
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
    [!LOOP "../../OcuConfigSet/OcuChannel/*"!]
        [!IF "$max_number_ocu_cfg != 0"!]
            [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
        [!ENDIF!]
        [!IF "$OcuEcucPartitionRefName = $OcuEcucPartitionChannel"!]
            [!IF "contains(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), 'FTM')"!]
                [!VAR "FtmInstanceNo" = "text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2]"!]
                [!IF "contains($AlreadyParsedFtmInstances, $FtmInstanceNo) = false()"!]
                    [!VAR "AlreadyParsedFtmInstances" = "concat($AlreadyParsedFtmInstances, $FtmInstanceNo)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!CODE!][!CR!][!CR!]
/** @brief    Ocu IPL configuration array for hardware instances configured within partition[!"$OcuEcucPartitionIndex"!] */
static const Ftm_Ocu_Ip_ModuleConfigType * const Ftm_Ocu_Ip_ConfigTypeCfgPB[!"$VS_number"!][!"$OcuEcucPartitionName"!][[!"$numFtmHwModules"!]] = {[!CR!]
[!ENDCODE!]
[!FOR "Idx" = "0" TO "$numFtmHwModules - 1"!]
    [!IF "contains($AlreadyParsedFtmInstances, $Idx) = true()"!]
        [!CODE!]
            &Ftm_Ocu_Ip_[!"$Idx"!]_ModuleCfgPB[!"$VS_number"!],[!CR!]
        [!ENDCODE!]
    [!ELSE!]
        [!CODE!]
            NULL_PTR,[!CR!]
        [!ENDCODE!]
    [!ENDIF!]
[!ENDFOR!]  
[!CODE!]
};
[!ENDCODE!]
[!ENDFOR!]
[!CODE!][!CR!][!ENDCODE!]
[!ENDSELECT!]

[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!IF "$max_number_ocu_cfg != 0"!]
        [!IF "$OcuPartitionId_temp = $max_number_ocu_cfg"!] [!BREAK!] [!ENDIF!] 
        [!VAR "OcuEcucPartitionRefName" = "node:value(./*[$OcuPartitionId_temp + 1])"!]
        [!VAR "OcuEcucPartitionName_Temp" = "text:split($OcuEcucPartitionRefName,'/')[5]"!]
        [!VAR "OcuEcucPartitionName" = "concat('_',$OcuEcucPartitionName_Temp)"!]
    [!ELSE!]
        [!VAR "OcuEcucPartitionRefName" = "''"!]
        [!VAR "OcuEcucPartitionName" = "''"!]
    [!ENDIF!]

[!CODE!][!CR!]
/** @brief    Ocu channels IP related configuration array */
[!ENDCODE!]

[!CODE!]
static const Ocu_Ipw_IpChannelConfigType Ocu_Ipw_IpChCfgPB[!"$VS_number"!][!"$OcuEcucPartitionName"!][OCU_CONF_CHANNELS_PB] = {
[!ENDCODE!]

[!VAR "VarChannelIndex" = "0"!]
[!VAR "numOcuChannels" = "num:i(count(../../OcuConfigSet/OcuChannel/*))"!]
[!VAR "OcuEcucPartitionChannel" = "''"!]
[!FOR "VarChannelIndex" = "0" TO "$numOcuChannels"!]
    [!LOOP "../../OcuConfigSet/OcuChannel/*"!]
        [!IF "OcuChannelId = $VarChannelIndex"!]
            [!IF "$max_number_ocu_cfg != 0"!]
                [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
            [!ENDIF!]
            [!VAR "OcuHwElementSelected" = "node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements)"!]

            [!CODE!]
            [!WS "4"!]/** @brief [!"$OcuHwElementSelected"!] [!"node:name(.)"!] */[!CR!]
            [!WS "4"!]{[!CR!]
            [!WS "8"!]/** @brief IP type of this channel */[!CR!]
            [!WS "8"!]OCU_FTM_CHANNEL,[!CR!]
            [!WS "8"!]/** @brief IP instance used for this OCU channel */[!CR!]
            [!WS "8"!](uint8)[!"text:split($OcuHwElementSelected,'_')[2]"!]U,[!CR!]
            [!WS "8"!]/** @brief Index in the configuration table of OCU FTM channels */[!CR!]
            [!ENDCODE!]

            [!IF "$OcuEcucPartitionRefName = $OcuEcucPartitionChannel"!]
                [!VAR "VarChannelIndexTemp" = "0"!]
                [!LOOP "../../../OcuConfigSet/OcuChannel/*"!]
                    [!IF "OcuChannelId < $VarChannelIndex"!]
                        [!IF "text:split($OcuHwElementSelected, "_")[2] = text:split(node:value(node:ref(./OcuHWSpecificSettingsRef)/OcuHardwareElements), "_")[2]"!]
                            [!VAR "VarChannelIndexTemp" = "$VarChannelIndexTemp + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!CODE!]
                    [!WS "8"!](uint8)[!"num:i($VarChannelIndexTemp)"!]U[!CR!]
                    [!WS "4"!]},[!CR!]
                [!ENDCODE!]
            [!ELSE!]
                [!CODE!]
                [!WS "8"!](uint8)[!"num:i(255)"!]U[!CR!]
                [!WS "4"!]},[!CR!]
                [!ENDCODE!]
            [!ENDIF!]

        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]
[!ENDFOR!]
[!ENDSELECT!]


[!SELECT "./OcuGeneral/OcuEcucPartitionRef"!]
[!FOR "OcuPartitionId_temp" = "0" TO "$max_number_ocu_cfg"!]
    [!VAR "OcuEcucPartitionChannel" = "''"!]
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
/** @brief    Ocu channels IPW configuration array for partition[!"$OcuEcucPartitionIndex"!] */
const Ocu_Ipw_IpConfigType Ocu_Ipw_IpCfgPB[!"$VS_number"!][!"$OcuEcucPartitionName"!] = {[!CR!]
    &Ftm_Ocu_Ip_ConfigTypeCfgPB[!"$VS_number"!][!"$OcuEcucPartitionName"!],
    &Ocu_Ipw_IpChCfgPB[!"$VS_number"!][!"$OcuEcucPartitionName"!]
[!ENDCODE!]
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]
[!ENDFOR!]
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
