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
*   @file        Ftm_Ocu_Ip_Irq.c
*
*   @addtogroup  ocu_ip Ocu IPL
*   @brief       Ocu FTM source file support for OCU driver.
*   @details     Ftm source file support for OCU driver.
*
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Ocu_Ip_HwAccess.h"
#include "Ftm_Ocu_Ip_Irq.h"
#include "SchM_Ocu.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP_IRQ_VENDOR_ID_C                       43
#define FTM_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define FTM_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_OCU_IP_IRQ_SW_MAJOR_VERSION_C                3
#define FTM_OCU_IP_IRQ_SW_MINOR_VERSION_C                0
#define FTM_OCU_IP_IRQ_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_OCU_IP_IRQ_VENDOR_ID_C != FTM_OCU_IP_IRQ_VENDOR_ID)
    #error "Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_Irq.h have different vendor ids"
#endif

/* Check if  source file and Ftm_Ocu_Ip_Irq.h file are of the same Autosar version */
#if ((FTM_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FTM_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FTM_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FTM_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_Irq.h are different"
#endif

/* Check if source file and Ftm_Ocu_Ip_Irq.h file are of the same Software version */
#if ((FTM_OCU_IP_IRQ_SW_MAJOR_VERSION_C != FTM_OCU_IP_IRQ_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP_IRQ_SW_MINOR_VERSION_C != FTM_OCU_IP_IRQ_SW_MINOR_VERSION) || \
     (FTM_OCU_IP_IRQ_SW_PATCH_VERSION_C != FTM_OCU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_Irq.h are different"
#endif

#if (FTM_OCU_IP_IRQ_VENDOR_ID_C != FTM_OCU_IP_HWACCESS_VENDOR_ID)
    #error "Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if  source file and Ftm_Ocu_Ip_HwAccess.h file are of the same Autosar version */
#if ((FTM_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != FTM_OCU_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != FTM_OCU_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FTM_OCU_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_HwAccess.h are different"
#endif

/* Check if source file and Ftm_Ocu_Ip_HwAccess.h file are of the same Software version */
#if ((FTM_OCU_IP_IRQ_SW_MAJOR_VERSION_C != FTM_OCU_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP_IRQ_SW_MINOR_VERSION_C != FTM_OCU_IP_HWACCESS_SW_MINOR_VERSION) || \
     (FTM_OCU_IP_IRQ_SW_PATCH_VERSION_C != FTM_OCU_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip_Irq.c and Ftm_Ocu_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this source file and SchM_Ocu.h file are of the same Autosar version */
    #if ((FTM_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_OCU_AR_RELEASE_MAJOR_VERSION) || \
        (FTM_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_OCU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Ocu_Ip_Irq.c and SchM_Ocu.h are different"
    #endif
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

/**
 * @brief Clear FLAG bit from FTM UC Status register n (Ftm_Sn).
 * @details: The FLAG bit is set when a match event in the comparators occurred.
 *            The FLAG bit must be cleared by writing a 1 to it.
 *              0 FLAG cleared
 *              1 FLAG set event has occurred
 *
 * @param[in] InstNum - Instance number of FTM module
 * @param[in] NumChannel - The channel in the FTM instance
 * @return none
 *
 */
static void Ftm_Ocu_Ip_Irq_ClearChannelInterrupt(uint8 InstNum, uint8 NumChannel);

/**
 * @brief   Driver routine to process all the interrupts of Ftm.
 * @details Support function used by interrupt service routines to implement Ftm specific operations
 *          and call the FTM_OCU_IP upper layer handler to implement non-hardware specific operations.
 *
 *
 * @param[in] InstNum Instance number of Ftm module
 * @param[in] ChIdx The channel in the instance
 *
 * @implements  Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt_Activity
 */
static void Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(uint8 InstNum, uint8 ChIdx);

#endif

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

/**
 * @brief Clear FLAG bit from FTM UC Status register n (Ftm_Sn).
 *
 */
static void Ftm_Ocu_Ip_Irq_ClearChannelInterrupt(uint8 InstNum, uint8 NumChannel)
{
    if((NumChannel < OCU_FTM_CHANNEL_COUNT) && (InstNum < OCU_FTM_INSTANCE_COUNT))
    {
        /* enter critical section */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_10();

        /* Clear the Channel (n) Flag (CHF)*/
        Ftm_Ocu_Ip_ClearChannelEventFlag(Ftm_Ocu_Ip_gapcxBase[InstNum], NumChannel);

        /* Clears the channel event status */
        Ftm_Ocu_Ip_ClearChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[InstNum], NumChannel);

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_10();
    }
}

/**
 * @brief   Driver routine to process all the interrupts of Ftm.
 *
 */
static void Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(uint8 InstNum, uint8 ChIdx)
{
    boolean IsChEvEnabled;
    boolean HasChEvOccurred;
    const Ftm_Ocu_Ip_ChStateType * const pChannelState = &Ftm_Ocu_Ip_gaxChState[InstNum][ChIdx];

    /* enter critical section */
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_15();

    /* check if channel event is enabled */
    IsChEvEnabled = (0U != (Ftm_Ocu_Ip_gapcxBase[InstNum]->CONTROLS[ChIdx].CSC & FTM_CSC_CHIE_MASK)) ? TRUE : FALSE;

    /* check if channel event has occurred */
    HasChEvOccurred = (0U != (Ftm_Ocu_Ip_gapcxBase[InstNum]->CONTROLS[ChIdx].CSC & FTM_CSC_CHF_MASK)) ? TRUE : FALSE;

    if (IsChEvEnabled && HasChEvOccurred)
    {
        /* Clear pending interrupts */
        Ftm_Ocu_Ip_Irq_ClearChannelInterrupt(InstNum, ChIdx);
    }

    /* exit critical section */
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_15();

    /* Check for spurious interrupts */
    if (IsChEvEnabled && HasChEvOccurred)
    {
        /* Check if driver is initialised and notification is enabled*/
        if((TRUE == pChannelState->mChannelInit) && (TRUE == pChannelState->mNotifEnabled))
        {
            /* Call upper layer handler */
            if(NULL_PTR != pChannelState->mCallbackFunc)
            {
                pChannelState->mCallbackFunc(pChannelState->mCallbackParam);
            }
        }
    }
}


#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

#if (defined OCU_FTM_0_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0
*
* @isr
*/
ISR(FTM_0_ISR)
{
    uint8 FtmChIdx;

    if (0UL != Ftm_Ocu_Ip_GetEventStatus(Ftm_Ocu_Ip_gapcxBase[0U]))
    {
        for (FtmChIdx = 0U; FtmChIdx < OCU_FTM_CHANNEL_COUNT; ++FtmChIdx)
        {
            if (Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[0U], FtmChIdx))
            {
                Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(0U, FtmChIdx);
            }
        }
    }
#if (defined(MCU_S32K116) || defined(MCU_S32K118))
    EXIT_INTERRUPT();
#endif
}
#endif /* OCU_FTM_0_ISR_USED */

#if (defined OCU_FTM_1_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1
*
* @isr
*/
ISR(FTM_1_ISR)
{
    uint8 FtmChIdx;

    if (0UL != Ftm_Ocu_Ip_GetEventStatus(Ftm_Ocu_Ip_gapcxBase[1U]))
    {
        for (FtmChIdx = 0U; FtmChIdx < OCU_FTM_CHANNEL_COUNT; ++FtmChIdx)
        {
            if (Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[1U], FtmChIdx))
            {
                Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(1U, FtmChIdx);
            }
        }
    }
#if (defined(MCU_S32K116) || defined(MCU_S32K118))
    EXIT_INTERRUPT();
#endif
}
#endif /* OCU_FTM_1_ISR_USED */

#if (defined OCU_FTM_4_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4
*
* @isr
*/
ISR(FTM_4_ISR)
{
    uint8 FtmChIdx;
    uint8 moduleIndex = 4U;

    if (0UL != Ftm_Ocu_Ip_GetEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex]))
    {
        for (FtmChIdx = 0U; FtmChIdx < OCU_FTM_CHANNEL_COUNT; ++FtmChIdx)
        {
            if (Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], FtmChIdx))
            {
                Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, FtmChIdx);
            }
        }
    }
#if (defined(MCU_S32K116) || defined(MCU_S32K118))
    EXIT_INTERRUPT();
#endif
}
#endif /* OCU_FTM_4_ISR_USED */

#if (defined OCU_FTM_5_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4
*
* @isr
*/
ISR(FTM_5_ISR)
{
    uint8 FtmChIdx;
    uint8 moduleIndex = 5U;

    if (0UL != Ftm_Ocu_Ip_GetEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex]))
    {
        for (FtmChIdx = 0U; FtmChIdx < OCU_FTM_CHANNEL_COUNT; ++FtmChIdx)
        {
            if (Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], FtmChIdx))
            {
                Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, FtmChIdx);
            }
        }
    }
#if (defined(MCU_S32K116) || defined(MCU_S32K118))
    EXIT_INTERRUPT();
#endif
}
#endif /* OCU_FTM_5_ISR_USED */

#if (defined OCU_FTM_0_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 0 - channel 1.
 */
ISR(FTM_0_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 2 - channel 3.
 */
ISR(FTM_0_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 4 - channel 5.
 */
ISR(FTM_0_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 6 - channel 7.
 */
ISR(FTM_0_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 0 - channel 1.
 */
ISR(FTM_1_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 2 - channel 3.
 */
ISR(FTM_1_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 4 - channel 5.
 */
ISR(FTM_1_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 6 - channel 7.
 */
ISR(FTM_1_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 0 - channel 1.
 */
ISR(FTM_2_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 2 - channel 3.
 */
ISR(FTM_2_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 4 - channel 5.
 */
ISR(FTM_2_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 6 - channel 7.
 */
ISR(FTM_2_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 0 - channel 1.
 */
ISR(FTM_3_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 2 - channel 3.
 */
ISR(FTM_3_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 4 - channel 5.
 */
ISR(FTM_3_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 6 - channel 7.
 */
ISR(FTM_3_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 0 - channel 1.
 */
ISR(FTM_4_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 2 - channel 3.
 */
ISR(FTM_4_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 4 - channel 5.
 */
ISR(FTM_4_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 6 - channel 7.
 */
ISR(FTM_4_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 0 - channel 1.
 */
ISR(FTM_5_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 2 - channel 3.
 */
ISR(FTM_5_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 4 - channel 5.
 */
ISR(FTM_5_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 6 - channel 7.
 */
ISR(FTM_5_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_6_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 0 - channel 1.
 */
ISR(FTM_6_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 6U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_6_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 2 - channel 3.
 */
ISR(FTM_6_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 6U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_6_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 4 - channel 5.
 */
ISR(FTM_6_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 6U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_6_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 6 - channel 7.
 */
ISR(FTM_6_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 6U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_7_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 0 - channel 1.
 */
ISR(FTM_7_CH_0_CH_1_ISR)
{
    uint8  moduleIndex  = 7U;
    uint8  channelIndex = 0U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_7_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 2 - channel 3.
 */
ISR(FTM_7_CH_2_CH_3_ISR)
{
    uint8  moduleIndex  = 7U;
    uint8  channelIndex = 2U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_7_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 4 - channel 5.
 */
ISR(FTM_7_CH_4_CH_5_ISR)
{
    uint8  moduleIndex  = 7U;
    uint8  channelIndex = 4U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_7_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 6 - channel 7.
 */
ISR(FTM_7_CH_6_CH_7_ISR)
{
    uint8  moduleIndex  = 7U;
    uint8  channelIndex = 6U;
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    ++channelIndex;
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }
    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 0.
 */
ISR(FTM_0_CH_0_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 1.
 */
ISR(FTM_0_CH_1_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 2.
 */
ISR(FTM_0_CH_2_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 3.
 */
ISR(FTM_0_CH_3_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 4.
 */
ISR(FTM_0_CH_4_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_0_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 5.
 */
ISR(FTM_0_CH_5_ISR)
{
    uint8  moduleIndex  = 0U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 0.
 */
ISR(FTM_1_CH_0_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 1.
 */
ISR(FTM_1_CH_1_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 2.
 */
ISR(FTM_1_CH_2_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 3.
 */
ISR(FTM_1_CH_3_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 4.
 */
ISR(FTM_1_CH_4_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_1_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 5.
 */
ISR(FTM_1_CH_5_ISR)
{
    uint8  moduleIndex  = 1U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 0.
 */
ISR(FTM_2_CH_0_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 1.
 */
ISR(FTM_2_CH_1_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 2.
 */
ISR(FTM_2_CH_2_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 3.
 */
ISR(FTM_2_CH_3_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 4.
 */
ISR(FTM_2_CH_4_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_2_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 5.
 */
ISR(FTM_2_CH_5_ISR)
{
    uint8  moduleIndex  = 2U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 0.
 */
ISR(FTM_3_CH_0_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 1.
 */
ISR(FTM_3_CH_1_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 2.
 */
ISR(FTM_3_CH_2_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 3.
 */
ISR(FTM_3_CH_3_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 4.
 */
ISR(FTM_3_CH_4_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_3_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 5.
 */
ISR(FTM_3_CH_5_ISR)
{
    uint8  moduleIndex  = 3U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 0.
 */
ISR(FTM_4_CH_0_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 1.
 */
ISR(FTM_4_CH_1_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 2.
 */
ISR(FTM_4_CH_2_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 3.
 */
ISR(FTM_4_CH_3_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 4.
 */
ISR(FTM_4_CH_4_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 5.
 */
ISR(FTM_4_CH_5_ISR)
{
    uint8  moduleIndex  = 4U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 0.
 */
ISR(FTM_5_CH_0_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 0U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 1.
 */
ISR(FTM_5_CH_1_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 1U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 2.
 */
ISR(FTM_5_CH_2_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 2U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 3.
 */
ISR(FTM_5_CH_3_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 3U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 4.
 */
ISR(FTM_5_CH_4_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 4U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#if (defined OCU_FTM_5_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 5.
 */
ISR(FTM_5_CH_5_ISR)
{
    uint8  moduleIndex  = 5U;
    uint8  channelIndex = 5U;
    
    /* Read data from status and control register. */
    if ( Ftm_Ocu_Ip_GetChannelEventStatus(Ftm_Ocu_Ip_gapcxBase[moduleIndex], channelIndex))
    {
        Ftm_Ocu_Ip_Irq_ProcessChannelInterrupt(moduleIndex, channelIndex);
    }

    EXIT_INTERRUPT();
}
#endif

#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
