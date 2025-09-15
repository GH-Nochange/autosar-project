/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SYSTEM_IP_CFG_DEFINES_H_
#define SYSTEM_IP_CFG_DEFINES_H_
/**
*   @file
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types header file are of the same Autosar version */
#if ((CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of System_Ip_CfgDefines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!NOCODE!][!// Include headers for System_Ip_DeviceRegister.h
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32G274A_MCM.h"

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32G399A_MCM.h"

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION

        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K3') or contains($DerivativeName, 'S32M27')"!][!//
        [!IF "contains($DerivativeName, 'S32K344')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K344_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K342')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K342_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K341')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K341_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K324')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K324_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K314')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K314_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K312')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K312_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K322')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K322_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K396') or contains($DerivativeName, 'S32K394') or contains($DerivativeName, 'S32K364') or contains($DerivativeName, 'S32K366')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K39_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K376') or contains($DerivativeName, 'S32K374')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K37_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K328') or contains($DerivativeName, 'S32K338') or contains($DerivativeName, 'S32K348') or contains($DerivativeName, 'S32K358')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K358_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K388')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K388_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K311') or contains($DerivativeName, 'S32K310')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K311_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32M276') or contains($DerivativeName, 'S32M274')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32M27x_MCM_CM7.h"
            [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
        [!CODE!][!WS "0"!]
        #define MCM_ISCR_FIDCE_SHIFT          MCM_CM7_ISCR_FIDCE_SHIFT
        #define MCM_ISCR_FIXCE_SHIFT          MCM_CM7_ISCR_FIXCE_SHIFT
        #define MCM_ISCR_FUFCE_SHIFT          MCM_CM7_ISCR_FUFCE_SHIFT
        #define MCM_ISCR_FOFCE_SHIFT          MCM_CM7_ISCR_FOFCE_SHIFT
        #define MCM_ISCR_FDZCE_SHIFT          MCM_CM7_ISCR_FDZCE_SHIFT
        #define MCM_ISCR_FIOCE_SHIFT          MCM_CM7_ISCR_FIOCE_SHIFT
        #define MCM_ISCR_WABE_SHIFT           MCM_CM7_ISCR_WABE_SHIFT
        #define MCM_CPCR_CM7_AHBSPRI_MASK     MCM_CM7_CPCR_CM7_AHBSPRI_MASK
        #define MCM_ISCR_WABS_MASK            MCM_CM7_ISCR_WABS_MASK

        #define IP_MCM IP_MCM_0_CM7

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32K5')"!][!//
        [!IF "contains($DerivativeName, 'S32K566')"!][!//
            [!CODE!][!WS "0"!]
        #include "S32K566_MCM.h"
            [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//

        [!CODE!][!WS "0"!]
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32R45_MCM.h"


        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//

    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]

        #include "[!"$DerivativeName"!].h"
        [!CR!][!ENDCODE!][!//
        [!IF "contains($DerivativeName, 'S32K116')"!][!//
            [!CODE!][!WS "0"!]

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K118')"!][!//
            [!CODE!][!WS "0"!]

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K142W')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K142')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K144W')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K144')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K146')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ELSEIF "contains($DerivativeName, 'S32K148')"!][!//
            [!CODE!][!WS "0"!]
            #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
            #define FPU_INEXACT_IRQ_SUPPORTED
            #define FPU_UNDERFLOW_IRQ_SUPPORTED
            #define FPU_OVERFLOW_IRQ_SUPPORTED
            #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
            #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
            #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK

            [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSEIF "contains($DerivativeName, 'S32M24')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32M24x.h"
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32E2')"!][!//
        [!CODE!][!WS "0"!]

        #include "S32E2_MCM.h"
        #define IP_MCM IP_CE_MCM

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define CACHE_WRITE_BUFFER_ERROR_SUPPORTED
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32Z2')"!][!//
        [!CODE!][!WS "0"!]

        #include "S32Z2_MCM.h"
        #define IP_MCM IP_CE_MCM

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define CACHE_WRITE_BUFFER_ERROR_SUPPORTED
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]
        #include "S32R41_MCM.h"

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]
        #include "SAF85xx_MCM.h"

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF86')"!][!//
        [!CODE!][!WS "0"!]
        #include "SAF86xx_MCM.h"

        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32N55')"!][!//
        [!SELECT "as:modconf('Platform')[1]"!][!//
        [!IF "GeneralConfiguration/ARM_Core = 'ARM_M_ARCH_FSS'"!][!//
            [!VAR "McmBase" = "'IP_FSS__MCM'"!]
        [!ELSE!][!// /* assign to IP_CRS__MCM for RTD/CRS subsystem */
            [!VAR "McmBase" = "'IP_CRS__MCM'"!]
        [!ENDIF!][!//
        [!ENDSELECT!]
        [!CODE!][!WS "0"!]
        #include "S32N55_MCM.h"
        #define IP_MCM ([!"$McmBase"!])
        #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
        #define FPU_INEXACT_IRQ_SUPPORTED
        #define FPU_UNDERFLOW_IRQ_SUPPORTED
        #define FPU_OVERFLOW_IRQ_SUPPORTED
        #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
        #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
        #define TCM_WRITE_ABORT_IRQ_SUPPORTED

        #define MCM_HAS_WABS_SUPPORTED

        #define MCM_HAS_PLATFORM_REVISION
        [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* @brief System IP on Cortex M.
*/
#define SYSTEM_IP_ARM_CORTEXM              ([!"ecu:get('Platform.ArmCortexM')"!])
/**
* @brief FPU configuration feature enablement.
*/
#define SYSTEM_FPU_CFG                     ([!"ecu:get('Platform.fpu')"!])
/**
 * @brief Maximum number of core-related interrupts.
 *
 * This constant defines the upper limit for the number of interrupts
 * that are related to the core functionality of the system.
 */
#define SYSTEM_IP_MAX_CORE_INT             ([!"ecu:get('Platform.systemIrqsCount')"!]U)
/**
* @brief System IP feature enablement.
*/
#define PLATFORM_IP_ENABLE_SYSTEM          ([!IF "(GeneralConfiguration/PlatformMcmConfigurable = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if (PLATFORM_IP_ENABLE_SYSTEM == STD_ON)
    #if ((SYSTEM_IP_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
* @brief      Enumeration listing available core-related interrupt requests
*             defined per each platform.
* @implements System_Ip_IrqType_typedef
*/
typedef enum
{
        #ifdef FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    /** @brief FPU Input Denormal Interrupt */
    FPU_INPUT_DENORMAL_IRQ         = MCM_ISCR_FIDCE_SHIFT,
        #endif
        #ifdef FPU_INEXACT_IRQ_SUPPORTED
    /** @brief FPU Inexact Interrupt */
    FPU_INEXACT_IRQ                = MCM_ISCR_FIXCE_SHIFT,
        #endif
        #ifdef FPU_UNDERFLOW_IRQ_SUPPORTED
    /** @brief FPU Underflow Interrupt */
    FPU_UNDERFLOW_IRQ              = MCM_ISCR_FUFCE_SHIFT,
        #endif
        #ifdef FPU_OVERFLOW_IRQ_SUPPORTED
    /** @brief FPU Overflow Interrupt */
    FPU_OVERFLOW_IRQ               = MCM_ISCR_FOFCE_SHIFT,
        #endif
        #ifdef FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    /** @brief FPU Divide-by-Zero Interrupt */
    FPU_DIVIDE_BY_ZERO_IRQ         = MCM_ISCR_FDZCE_SHIFT,
        #endif
        #ifdef FPU_INVALID_OPERATION_IRQ_SUPPORTED
    /** @brief FPU Invalid Operation Interrupt */
    FPU_INVALID_OPERATION_IRQ      = MCM_ISCR_FIOCE_SHIFT,
        #endif
        #ifdef TCM_WRITE_ABORT_IRQ_SUPPORTED
    /** @brief TCM Write Abort Interrupt */
    TCM_WRITE_ABORT_IRQ            = MCM_ISCR_WABE_SHIFT,
        #endif
        #ifdef CACHE_WRITE_BUFFER_ERROR_SUPPORTED
    /** @brief Cache Write Buffer Error */
    CACHE_WRITE_BUFFER_ERROR       = MCM_ISCR_CWBEE_SHIFT
        #endif
}System_Ip_IrqType;
    #endif /* SYSTEM_IP_ARM_CORTEXM == STD_ON */
#endif /* PLATFORM_IP_ENABLE_SYSTEM */

#endif /* SYSTEM_IP_CFG_DEFINES_H_ */

/** @} */
