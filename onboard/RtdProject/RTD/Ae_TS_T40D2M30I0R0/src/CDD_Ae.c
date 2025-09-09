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
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file       Ae.c
*   @version    3.0.0
*
*   @brief      AUTOSAR Ae - Implements the AUTOSAR AE driver functionality.
*
*   @addtogroup AE_DRIVER Ae Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ae.h"
#include "CDD_Ae_Ipw.h"

#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_AE_VENDOR_ID_C                      43
#define CDD_AE_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_AE_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_AE_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_AE_SW_MAJOR_VERSION_C               3
#define CDD_AE_SW_MINOR_VERSION_C               0
#define CDD_AE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ae.h */
#if (CDD_AE_VENDOR_ID_C != CDD_AE_VENDOR_ID)
    #error "CDD_Ae.c and CDD_Ae.h have different vendor ids"
#endif
#if ((CDD_AE_AR_RELEASE_MAJOR_VERSION_C    != CDD_AE_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_AR_RELEASE_MINOR_VERSION_C    != CDD_AE_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_AR_RELEASE_REVISION_VERSION_C != CDD_AE_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Ae.c and CDD_Ae.h are different"
#endif
#if ((CDD_AE_SW_MAJOR_VERSION_C != CDD_AE_SW_MAJOR_VERSION) || \
     (CDD_AE_SW_MINOR_VERSION_C != CDD_AE_SW_MINOR_VERSION) || \
     (CDD_AE_SW_PATCH_VERSION_C != CDD_AE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ae.c and CDD_Ae.h are different"
#endif

/* Checks against Ae_Ipw.h */
#if (CDD_AE_VENDOR_ID_C != CDD_AE_IPW_VENDOR_ID)
    #error "CDD_Ae.c and CDD_Ae_Ipw.h have different vendor ids"
#endif
#if ((CDD_AE_AR_RELEASE_MAJOR_VERSION_C    != CDD_AE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_AE_AR_RELEASE_MINOR_VERSION_C    != CDD_AE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_AE_AR_RELEASE_REVISION_VERSION_C != CDD_AE_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Ae.c and CDD_Ae_Ipw.h are different"
#endif
#if ((CDD_AE_SW_MAJOR_VERSION_C != CDD_AE_IPW_SW_MAJOR_VERSION) || \
     (CDD_AE_SW_MINOR_VERSION_C != CDD_AE_IPW_SW_MINOR_VERSION) || \
     (CDD_AE_SW_PATCH_VERSION_C != CDD_AE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ae.c and CDD_Ae_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Det.h */
    #if ((CDD_AE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_AE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of CDD_Ae.c and Det.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define AE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"

#if STD_ON == AE_DEV_ERROR_DETECT
/**
* @brief         State of the AE initialization.
* @details       Used to store state of the AE Initialization driver. It is initialized to AE_STATE_UNINIT
*/
extern Ae_StateType Ae_axInitState;
Ae_StateType Ae_axInitState;
#endif

static const Ae_ConfigType * Ae_apxAeConfigPtr[AE_MAX_PARTITIONS];

#define AE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ae_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define AE_START_SEC_CODE
#include "Ae_MemMap.h"
static inline Std_ReturnType Ae_CheckInit(const Ae_ConfigType *ConfigPtr,
                                           uint32 AeID);
                                           #if (AE_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType Ae_InitCheckDemError(uint32 AeID,
                                            const Ae_ConfigType *ConfigPtr);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (AE_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   Check Dem report error in Init function.
* @details Check Dem report error in Init function.
*
* @param[in]      AeID      ID of Partition
* @return Std_ReturnType
*
*
*/
static Std_ReturnType Ae_InitCheckDemError(uint32 AeID,
                                            const Ae_ConfigType *ConfigPtr)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;

    if (NULL_PTR != Ae_apxAeConfigPtr[AeID])
    {
        /* Call Det_ReportError */
        (void)Det_ReportError(CDD_AE_MODULE_ID,0,AE_SID_INIT,AE_E_ALREADY_INITIALIZED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #if (AE_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_INIT, AE_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #else /* (AE_CONFIG_VARIANT == AE_VARIANT_PRECOMPILE) */
    else if (NULL_PTR != ConfigPtr)
    {
        /* Call Det_ReportError */
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_INIT, AE_E_INIT_FAILED);
        CheckStatus = (Std_ReturnType)E_NOT_OK;
    }
    #endif /*(AE_PRECOMPILE_SUPPORT == STD_OFF)*/
    else
    {
        /* Do nothing */
    }

    return CheckStatus;
}
#endif

/**
* @brief   This function checks parameters for initialization of AE driver.
* @details This function checks parameters for initialization of AE driver.
*
* @param[in]     ConfigPtr       Specifies the pointer to the configuration set
* @param[out]    CheckStatus      Specifies status of checking
*               - E_OK: The parameters are valid
*               - E_NOT_OK: The parameters are invalid
*
*/
static inline Std_ReturnType Ae_CheckInit(const Ae_ConfigType *ConfigPtr,
                                           uint32 AeID)
{
    Std_ReturnType CheckStatus = (Std_ReturnType)E_OK;

#if (AE_PRECOMPILE_SUPPORT == STD_OFF)
    if (AeID != ConfigPtr->AeCorePartitionUse)
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (AE_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError(CDD_AE_MODULE_ID,0U,AE_SID_INIT,AE_E_PARAM_CONFIG);
#endif
    }
#else /* (AE_CONFIG_VARIANT == AE_VARIANT_PRECOMPILE) */
    (void)ConfigPtr;
    if (AeID != Ae_xPredefinedConfig[AeID]->AeCorePartitionUse )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (AE_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        (void)Det_ReportError(CDD_AE_MODULE_ID,0U,AE_SID_INIT,AE_E_PARAM_CONFIG);
#endif
    }
#endif /* (AE_PRECOMPILE_SUPPORT == STD_OFF) */

    return CheckStatus;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief            Ae driver initialization function.
* @details          This routine initializes the AE Driver.
*                   The intention of this function is to make the configuration setting for AEC
*                   and HVM sections visible within the AE Driver.
* @param[in]        ConfigPtr   Pointer to configuration structure.
*
* @return           void
*
* @api
*
* @implements Ae_Init_Activity
*/
void Ae_Init(const Ae_ConfigType *CfgPtr)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;
    uint32 AeID;
    AeID = Ae_GetID;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    ReturnStatus = Ae_InitCheckDemError(AeID, CfgPtr);
    if ((Std_ReturnType)E_OK == ReturnStatus)
    {
#endif /*(AE_DEV_ERROR_DETECT == STD_ON)*/
        ReturnStatus = Ae_CheckInit(CfgPtr, AeID);
        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
#if (AE_PRECOMPILE_SUPPORT == STD_OFF)
            Ae_apxAeConfigPtr[AeID] = CfgPtr;
#else /* (AE_CONFIG_VARIANT == AE_VARIANT_PRECOMPILE) */
            Ae_apxAeConfigPtr[AeID] = Ae_xPredefinedConfig[AeID];
#endif /* (AE_PRECOMPILE_SUPPORT == STD_OFF) */
#if (STD_ON == AE_DEV_ERROR_DETECT)
            Ae_axInitState = AE_STATE_UNINIT;
#endif
            ReturnStatus = Ae_Ipw_Init(Ae_apxAeConfigPtr[AeID]->Ae_pIpwConfig);
        }
        else
        {
            /*Do nothing. Should not enter here*/
        }
#if (STD_ON == AE_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
            Ae_axInitState = AE_STATE_INIT;
        }
        else
        {
            /* Call Det_ReportError */
            (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_INIT, AE_E_INIT_FAILED);
        }
#else
        (void)ReturnStatus;
#endif
#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /*(AE_DEV_ERROR_DETECT == STD_ON)*/
}

/*================================================================================================*/

/**
 * @brief            Read register value
 *
 * @param[in]        RegAddr    Address of the register
 * @param[in]        DataWidth  Size data
 *
 * @param[out]       RegValPtr  Value received from register
 *
 * @return           Status of transmission
 *
 * @retval           E_OK        Successful transmission
 * @retval           E_NOT_OK    Transmission failed
 *
 * @implements Ae_ReadRegister_Activity
 */
Std_ReturnType Ae_ReadRegister(uint32 RegAddr,
                               uint8 DataWidth,
                               uint32 *RegValPtr
                              )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;


#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == RegValPtr)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_READREGISTER, AE_E_PARAM_POINTER);
    }
    else if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_READREGISTER, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        ReturnStatus = Ae_Ipw_ReadReg(RegAddr, DataWidth, RegValPtr);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/**
 * @brief               Write register value.
 *
 * @param[in] RegAddr   Address of the register
 * @param[in] DataWidth Size data
 *
 * @param[out] RegVal   Value received from register
 *
 * @return              Status of transmission
 *
 * @retval              E_OK        Successful transmission
 * @retval              E_NOT_OK    Transmission failed
 *
 * @implements Ae_WriteRegister_Activity
 */
Std_ReturnType Ae_WriteRegister (uint32 RegAddr,
                                 uint8 DataWidth,
                                 uint32 RegVal
                                )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_WRITEREGISTER, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        ReturnStatus = Ae_Ipw_WriteReg(RegAddr, DataWidth, RegVal);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/**
 * @brief Return status of global health.
 *
 * @return return legend for global health status
 *
 * @implements Ae_DecodeGlobalHealthStatus_Activity
 */
uint16 Ae_DecodeGlobalHealthStatus(void)
{
    uint16 Status = 0U;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_DECODEGLOBALHEALTHSTATUS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Status = Ae_Ipw_DecodeGlobalHealthStatus();

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return Status;
}

/*================================================================================================*/
/**
 * @brief Verify for correctness the received frame counter.
 *
 * @param IsVerify  if this variable is TRUE this function will compare frame count in GHS and actually received frame count
 *                  if this variable is FALSE this function does not compare frame count in GHS and actually received frame count
 *
 * @param[in] ExpectedFrameCount Expected frame count
 * @param[out] ActualFrameCount Actual frame count in GHS
 *
 * @return Return status after verify is correct or not
 *
 * @implements Ae_Frame_Counter_Activity
 */
boolean Ae_Frame_Counter(boolean IsVerify,
                         uint8 ExpectedFrameCount,
                         uint8 *ActualFrameCount
                        )
{
    boolean Status = (boolean)FALSE;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_FRAMECOUNTER, AE_E_UNINIT);
    }
    else if (NULL_PTR == ActualFrameCount)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_FRAMECOUNTER, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    Status = Ae_Ipw_Frame_Counter(IsVerify, ExpectedFrameCount, ActualFrameCount);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return Status;
}

/*================================================================================================*/
/**
 * @brief Initializes the configuration for analog input for measurement.
 *
 * @param[in] pHviHighVoltConfig Pointer to configuration structure.
 * @param[in] AnalogInputSelect Select one source to measure its voltage
 *
 * @return Status of transmission
 *
 * @implements Ae_AdcMeasureConfig_Activity
 */
Std_ReturnType  Ae_AdcMeasureConfig(const Ae_HviHighVoltageInputConfig *pHviHighVoltConfig,
                                    Ae_AnalogInputType AnalogInputSelect
                                    )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_ADCMEASURECONFIG, AE_E_UNINIT);
    }
    else if (NULL_PTR == pHviHighVoltConfig)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_ADCMEASURECONFIG, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        ReturnStatus = Ae_Ipw_AdcMeasureConfig(pHviHighVoltConfig, AnalogInputSelect);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/**
 * @brief Initializes the configuration for digital input.
 *
 * @param[in] pAeHviChannelConfig Pointer to configuration structure.
 *
 * @return Status of transmission
 *
 * @implements Ae_DigitalInputEventConfig_Activity
 */
Std_ReturnType  Ae_DigitalInputEventConfig(const Ae_HviChannelConfig *pAeHviChannelConfig)
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pAeHviChannelConfig)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_DIGITALINPUTCONFIG, AE_E_PARAM_POINTER);
    }
    else if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_DIGITALINPUTCONFIG, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        ReturnStatus = Ae_Ipw_DigitalInputEventConfig(pAeHviChannelConfig);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/

/**
 * @brief Initializes the configuration for High/Low Voltage detect.
 *
 * @param[in] pAeVmConfig        Pointer to configuration structure.
 * @param[in] pHighVoltageInput  Pointer to configuration structure.
 *
 * @return Status of transmission
 *
 * @implements Ae_VoltageMonitorConfig_Activity
 */
Std_ReturnType  Ae_VoltageMonitorConfig(const Ae_VmConfig *pAeVmConfig,
                                        const Ae_HviHighVoltageInputConfig *pHighVoltageInput
                                        )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;

#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_VOLTAGEMONITORCONFIG, AE_E_UNINIT);
    }
    else if ((NULL_PTR == pAeVmConfig) || (NULL_PTR == pHighVoltageInput))
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_VOLTAGEMONITORCONFIG, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        ReturnStatus = Ae_Ipw_VoltageMonitorConfig(pAeVmConfig, pHighVoltageInput);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

    return ReturnStatus;
}

/*================================================================================================*/
/**
 * @brief Check and clear interrupt flag used in interrupt mode.
 *
 * @return void
 *
 * @implements Ae_FaultsEventsProccess_Activity
 *
 */
void Ae_FaultsEventsProccess(void)
{
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_FAULTSEVENTSPROCCESS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Ae_Ipw_FaultsEventsProccess();

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
}

/*================================================================================================*/
/**
 * @brief Check status flag used in polling mode for digital input, high/low voltage detect.
 *
 * @return void
 *
 * @implements Ae_ReadFaultsEventsStatus_Activity
 *
 */
void  Ae_ReadFaultsEventsStatus(void)
{
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_READFAULTSEVENTSSTATUS, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Ae_Ipw_ReadFaultsEventsStatus();

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
}
/*================================================================================================*/
/**
 * @brief Enable/Disable read after write.
 *
 * @param Activate Enable/Disable bit raw
 *
 * @return void
 *
 * @implements Ae_SetRaw_Activity
 */
void Ae_SetRaw(boolean Activate)
{
#if (AE_DEV_ERROR_DETECT == STD_ON)
    if (AE_STATE_UNINIT == Ae_axInitState)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_SETRAW, AE_E_UNINIT);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT == STD_ON */

        Ae_Ipw_SetRaw(Activate);

#if (AE_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* AE_DEV_ERROR_DETECT == STD_ON */
}

#if STD_ON == AE_VERSION_INFO_API
/*================================================================================================*/
/**
* @brief         Returns the version information of this module.
*
* implements    Ae_GetVersionInfo_Activity
*/
void Ae_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
#if STD_ON == AE_DEV_ERROR_DETECT
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(CDD_AE_MODULE_ID, 0U, AE_SID_GETVERSIONINFO, AE_E_PARAM_POINTER);
    }
    else
    {
#endif /* AE_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (uint16)CDD_AE_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)CDD_AE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_AE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_AE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_AE_SW_PATCH_VERSION;
#if STD_ON == AE_DEV_ERROR_DETECT
    }
#endif /* AE_DEV_ERROR_DETECT */
}
#endif /* AE_VERSION_INFO_API */

#if(STD_ON == AE_USE_NMI_INTERRUPT)
void Ae_NMISetupEventFaultHandler(void)
{
    /* Disable NMI and trigger an interrupt */
    Ae_Ipw_NMISetupEventFaultHandler();
}

void Ae_InterruptSetupEventFaultHandler(void)
{
    /* Enable NMI and execute Events/Faults */
    Ae_Ipw_InterruptSetupEventFaultHandler();
}
#endif

#define AE_STOP_SEC_CODE
#include "Ae_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

