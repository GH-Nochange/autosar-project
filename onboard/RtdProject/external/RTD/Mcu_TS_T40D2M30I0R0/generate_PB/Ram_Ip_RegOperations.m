[!NOCODE!]
/**
    @file    Ram_Ip_RegOperations.m
    @version 3.0.0

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.7
    Platform CORTEXM
    Peripheral 
    Dependencies none

    ARVersion 4.7.0
    ARRevision ASR_REL_4_7_REV_0000
    ARConfVariant
    SWVersion 3.0.0
    BuildVersion S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_7_REV_0000_20250530

    Copyright 2020-2025 NXP

    NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
 */
[!MACRO "Ram_Ip_LinkerSymbols","Type"!][!//
[!NOCODE!][!//
    [!VAR "SymbolTable" = "''"!]
    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
        [!IF "McuRamSectionSizeLinkerSym != ''"!]
            [!VAR "Externs_SL" = "concat('extern uint32 ',McuRamSectionSizeLinkerSym,'[1U];')"!]
            [!IF "not(text:contains(text:split($SymbolTable), McuRamSectionSizeLinkerSym))"!]
[!CODE!][!//
[!"$Externs_SL"!]
[!ENDCODE!][!//
            [!VAR "SymbolTable" = "concat($SymbolTable, ' ', McuRamSectionSizeLinkerSym)"!]
            [!ENDIF!]
        [!ENDIF!][!//McuRamSectionSizeLinkerSym != ''

        [!IF "McuRamSectionBaseAddrLinkerSym != ''"!]
            [!VAR "Externs_BAL" = "concat('extern uint8 ',McuRamSectionBaseAddrLinkerSym,'[1U];')"!]
            [!IF "not(text:contains(text:split($SymbolTable), McuRamSectionBaseAddrLinkerSym))"!]
[!CODE!][!//
[!"$Externs_BAL"!]
[!ENDCODE!][!//
            [!VAR "SymbolTable" = "concat($SymbolTable, ' ', McuRamSectionSizeLinkerSym)"!]
            [!ENDIF!]
        [!ENDIF!][!//McuRamSectionBaseAddrLinkerSym != ''
    [!ENDLOOP!][!//McuRamSectorSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Ram_Ip_Ram_Config","Type"!][!//
[!NOCODE!]
    [!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]
        [!VAR "RamSector"= "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))-1"!]
[!CODE!]
#ifndef MCU_MAX_NORAMCONFIGS
[!ENDCODE!]


[!CODE!]
/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitRamSection() API.
*
*/
const Ram_Ip_RamConfigType Mcu_aRamConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]] =
{
[!ENDCODE!]
    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
        [!VAR "PCindex" = "@index"!]
            [!IF "node:exists(McuRamEcucPartitionRef)"!]
            [!VAR "PartitionRefName" = "node:value("McuRamEcucPartitionRef")"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($PartitionRefName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
            [!LOOP "as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*"!]
                [!IF "$CurrentPartitionShortName = node:name(.)"!]                 
                    [!VAR "CurrentPartitionId" = "node:pos(.)"!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!ENDIF!]
[!CODE!]
    {
[!IF "node:exists(McuRamEcucPartitionRef)"!]
#if (RAM_IP_MULTIPARTITION_SUPPORT == STD_ON)
        /* The ID for Partition. */
        (uint8)RAM_IP_PARTITION_[!"num:i($CurrentPartitionId)"!],
#endif
[!ENDIF!] 
        /* The ID for Ram Sector configuration. */
        (Ram_Ip_RamSectionType)[!"num:i(McuRamSectorId)"!]U,

        /* RAM section base address: Start of Mcu_aRamConfig[[!"@index"!]]. */

        [!IF "McuRamSectionBaseAddrLinkerSym = ''"!](uint8 (*)[1U])[!"num:inttohex(McuRamSectionBaseAddress,8)"!]U[!ELSE!](uint8 (*)[1U])[!"McuRamSectionBaseAddrLinkerSym"!][!ENDIF!],

        /* RAM section size: Section base address (must be aligned to 4 bytes). */

        [!IF "McuRamSectionSizeLinkerSym = ''"!](Ram_Ip_RamSizeType *)[!"num:inttohex(McuRamSectionSize,8)"!]U,[!ELSE!](Ram_Ip_RamSizeType *)[!"McuRamSectionSizeLinkerSym"!],[!ENDIF!]

        /* RAM default value. */
        (uint8) [!"num:inttohex(McuRamDefaultValue, 2)"!]U,

        /* RAM section write size (maximum allowed: 8). */
        (Ram_Ip_RamWriteSizeType)[!"num:i(McuRamSectionWriteSize)"!]U

    }[!IF "$PCindex < $RamSector"!],[!ENDIF!] /* End of Mcu_aRamConfig[!"$Type"!][[!"@index"!]]. */
[!ENDCODE!]
    [!ENDLOOP!][!//McuRamSectorSettingConf/*
[!CODE!]
};
#endif /* ifndef MCU_MAX_NORAMCONFIGS */
[!ENDCODE!]
    [!ENDIF!][!//num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0
[!ENDNOCODE!]
[!ENDMACRO!][!//




[!ENDNOCODE!]