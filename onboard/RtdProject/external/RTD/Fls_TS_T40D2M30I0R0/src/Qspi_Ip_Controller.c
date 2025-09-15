/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP02_D2505_ASR_REL_4_4_REV_0000_20250530
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
 *   @file       Qspi_Ip_Controller.c
 *
 *   @addtogroup IPV_QSPI QSPI IPV Driver
 *   @implements Qspi_Ip_Controller.c_Artifact
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "OsIf.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Controller.h"
#include "Qspi_Ip_HwAccess.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_CONTROLLER_VENDOR_ID_C                       43
#define QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C        4
#define QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C        4
#define QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C     0
#define QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C                3
#define QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C                0
#define QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Mcal.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and OsIf.h are different"
    #endif
#endif

/* Check if current file and Qspi_Ip_Controller header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_CONTROLLER_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip_Controller.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_Controller.h are different"
#endif
/* Check if current file and Qspi_Ip_Controller header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_Controller.h are different"
#endif

/* Check if current file and Qspi_Ip_HwAccess header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_HW_ACCESS_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_HwAccess header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h are different"
#endif
/* Check if current file and Qspi_Ip_HwAccess header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip_HwAccess.h are different"
#endif

/* Check if current file and Qspi_Ip header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.c and Qspi_Ip.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip.h are different"
#endif
/* Check if current file and Qspi_Ip header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.c and Qspi_Ip.h are different"
#endif

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if defined(FEATURE_QSPI_CHIP_OPTIONS_S32K148)
    /* Bit-fields of chip-specific MCR[SCLKCFG] field */
    #define QSPI_MCR_SCLKCFG_INPUT_EN             0x80U    /* Enable input buffer of QSPI pads */
    #define QSPI_MCR_SCLKCFG_CLK_MOD              0x40U    /* Quadspi Clocking mode selection  */
    #define QSPI_MCR_SCLKCFG_EXT_DQS              0x20U    /* Use external DQS (HyperRAM mode) */
    #define QSPI_MCR_SCLKCFG_CLK_SRC              0x10U    /* QuadSPI source clock selection   */
    #define QSPI_MCR_SCLKCFG_DQS_INV_B            0x08U    /* B-side DQS invert                */
    #define QSPI_MCR_SCLKCFG_DQS_SEL_B            0x04U    /* B-side DQS select                */
    #define QSPI_MCR_SCLKCFG_DQS_INV_A            0x02U    /* A-side DQS invert                */
    #define QSPI_MCR_SCLKCFG_DQS_SEL_A            0x01U    /* A-side DQS select                */

    /* Bit-fields of chip-specific SOCCR[SOCCFG] field */
    /* Programmable Divider Selection */
    #define QuadSPI_SOCCR_PD_MASK                 0xE0000000u
    #define QuadSPI_SOCCR_PD_SHIFT                29u
    #define QuadSPI_SOCCR_PD(x)                   (((uint32)(((uint32)(x))<<QuadSPI_SOCCR_PD_SHIFT))&QuadSPI_SOCCR_PD_MASK)
    /* Programmable Divider Disable */
    #define QuadSPI_SOCCR_PDD_MASK                0x10000000u

    #define QuadSPI_SOCCR_DSQ_DEL_B               8u
    #define QuadSPI_SOCCR_DSQ_DEL_A               0u
#endif /* (FEATURE_QSPI_CHIP_OPTIONS_S32K148) */


/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @cond DRIVER_INTERNAL_USE_ONLY */

/* Mask of QuadSPI IP-related error flags */
#ifndef QuadSPI_FR_IPAEF_MASK
    #define QuadSPI_FR_IPAEF_MASK  (0U)
#endif

#define QSPI_ERR_FLAGS_MASK    (QuadSPI_FR_TBUF_MASK | \
                                QuadSPI_FR_ILLINE_MASK | \
                                QuadSPI_FR_RBOF_MASK | \
                                QuadSPI_FR_IPAEF_MASK | \
                                QuadSPI_FR_IPIEF_MASK)


#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

/* Table of base addresses for QuadSPI instances. */
static QuadSPI_Type * const Qspi_Ip_BaseAddress[QuadSPI_INSTANCE_COUNT] = IP_QuadSPI_BASE_PTRS;
/* Table of AHB addresses for QuadSPI instances. */
static const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"

/* The padding bytes information to handle unaligned read/write operation for QuadSPI instances:
   - For read:
        [7:0] the number of padding bytes to handle read from unaligned address
   - For write:
        [7:4] the number of pre-padding bytes to handle write from unaligned start address
        [3:0] the number of post-padding bytes to handle write from unaligned end address
 */
uint8 Qspi_Ip_MemoryPadding[QuadSPI_INSTANCE_COUNT];

#define FLS_STOP_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static inline uint32 Qspi_Ip_GetWordSize(uint32 sizeRemaining);


inline static void Qspi_Ip_ResetAllRegisters(QuadSPI_Type *BaseAddr);

static Qspi_Ip_StatusType Qspi_Ip_CmdWaitComplete(uint32 instance);

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetWordSize
 * Description   : Calculates the word size for the up coming loop
 */
static inline uint32 Qspi_Ip_GetWordSize(uint32 sizeRemaining)
{
    return (sizeRemaining > 4U) ? 4U : sizeRemaining;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataRead
 * Description   : Processes read data
 * @implements     Qspi_Ip_ProcessDataRead_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataRead(uint8 *dataRead,
                                                         uint32 size,
                                                         const QuadSPI_Type *baseAddr,
                                                         uint32 padding
                                                        )
{
    uint8 * data = dataRead;
    uint32 cnt = 0U;
    uint32 recvData;
    const uint8 *recvDataPtr = (uint8 *)(&recvData);
    uint32 wordSize;
    uint32 byteCnt;
    uint32 sizeRemaining = size;
    uint32 paddingBytes = padding;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = baseAddr->RBDR[cnt];
        cnt++;
        /* Get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);

        /* Ignore padding bytes and copy the rest to buffer */
        for (byteCnt = paddingBytes; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            *data = recvDataPtr[3U - byteCnt];
            #else
            *data = recvDataPtr[byteCnt];
            #endif

            data++;
        }
        sizeRemaining -= wordSize;
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)data & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed up read */
        while (sizeRemaining >= 4U)
        {
            *((uint32 *)((Qspi_Ip_UintPtrType)data)) = baseAddr->RBDR[cnt];  /* Casting through uint32 to avoid Misra 11.3 */
            data = &(data[4U]);
            cnt++;
            sizeRemaining -= 4U;
        }
    }

    /* Process remaining bytes one by one */
    while (sizeRemaining > 0U)
    {
        /* Get next received word */
        recvData = baseAddr->RBDR[cnt];
        /* get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
#if (defined(CORE_BIG_ENDIAN))
            *data = (uint8)(recvData >> 24U);
            recvData <<= 8U;
#else
            *data = (uint8)(recvData & 0xFFU);
            recvData >>= 8U;
#endif
            data++;
            sizeRemaining--;
        }
        cnt++;
    }
    return STATUS_QSPI_IP_SUCCESS;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataVerify
 * Description   : Processes program verify data
 * @implements     Qspi_Ip_ProcessDataVerify_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataVerify(const uint8 *dataCmp,
                                                           uint32 size,
                                                           const QuadSPI_Type *baseAddr,
                                                           uint32 padding
                                                          )
{
    const uint8 * roData = dataCmp;
    uint32 cnt = 0U;
    uint32 recvData;
    uint8 recvByte;
    const uint8 *recvDataPtr = (uint8 *)(&recvData);
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 byteCnt;
    uint32 wordSize;
    uint32 paddingBytes = padding;
    uint32 sizeRemaining = size;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = baseAddr->RBDR[cnt];
        cnt++;
        /* Get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        sizeRemaining -= wordSize;

        /* Ignore padding bytes and compare the rest with user buffer */
        for (byteCnt = paddingBytes; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            recvByte = recvDataPtr[3U - byteCnt];
            #else
            recvByte = recvDataPtr[byteCnt];
            #endif

            /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            roData++;
        }
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)roData & 0x3U) == 0U)
    {
        while (sizeRemaining >= 4U)
        {
            /* Process 4 bytes at a time to speed up read */
            if (*((const uint32 *)((Qspi_Ip_UintPtrType)roData)) != baseAddr->RBDR[cnt])
            {
                /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            /* Update the roData to 4 bytes next */
            roData = &roData[4U];
            cnt++;
            sizeRemaining -= 4U;
        }
    }

    /* Process remaining bytes one by one */
    while (sizeRemaining > 0U)
    {
        /* Get next received word */
        recvData = baseAddr->RBDR[cnt];
        /* get wordSize for the loop */
        wordSize = Qspi_Ip_GetWordSize(sizeRemaining);
        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
#if (defined(CORE_BIG_ENDIAN))
            recvByte = (uint8)(recvData >> 24U);
            recvData <<= 8U;
#else
            recvByte = (uint8)(recvData & 0xFFU);
            recvData >>= 8U;
#endif
            /* return STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY if the data is not match */
            if (*roData != recvByte)
            {
                status = STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY;
                sizeRemaining = 0U;
                break;
            }
            else
            {
                /* update the roData, sizeRemaining */
                roData++;
                sizeRemaining--;
            }
        }
        cnt++;
    }
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ProcessDataBlankCheck
 * Description   : Processes blank check data
 * @implements     Qspi_Ip_ProcessDataBlankCheck_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ProcessDataBlankCheck(uint32 size,
                                                               const QuadSPI_Type *baseAddr,
                                                               uint32 padding
                                                              )
{
    uint32 cnt = 0U;
    uint32 recvData = 0U;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 dataSize;
    uint32 sizeRemaining = size;
    uint32 paddingBytes = padding;

    if (0U != paddingBytes)
    {
        /* Ignore all padding words, jump to the fist data */
        cnt            = paddingBytes >> 2U;
        sizeRemaining -= cnt << 2U;
        paddingBytes  &= 0x3U;

        /* Get first received word */
        recvData = ~(baseAddr->RBDR[cnt]);
        cnt++;
        /* Get wordSize for the blank check */
        dataSize = Qspi_Ip_GetWordSize(sizeRemaining);
        sizeRemaining -= dataSize;

        /* Mask data: ignore padding at the beginning and unused bytes at the end */
#if (defined(CORE_BIG_ENDIAN))
        recvData &= 0xFFFFFFFFUL << ((4UL - dataSize) * 8UL);
        recvData &= 0xFFFFFFFFUL >> (paddingBytes * 8UL);
#else
        recvData &= 0xFFFFFFFFUL >> ((4UL - dataSize) * 8UL);
        recvData &= 0xFFFFFFFFUL << (paddingBytes * 8UL);
#endif
        if (recvData != 0U)
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR;
            sizeRemaining = 0U;
        }
    }

    /* Blank check */
    while (sizeRemaining >= 4U)
    {
        if (baseAddr->RBDR[cnt] != 0xFFFFFFFFU)
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR;
            sizeRemaining = 0U;
            break;
        }
        cnt++;
        sizeRemaining -= 4U;
    }

    if (sizeRemaining != 0U)
    {
        /* Process last few bytes */
        recvData = baseAddr->RBDR[size >> 2U];
#if (defined(CORE_BIG_ENDIAN))
        if ((~recvData & ~(((uint32)1U << (((uint32)4U - sizeRemaining) * 8U)) - 1U)) != 0U)
#else
        if ((~recvData & (((uint32)1U << (sizeRemaining * 8U)) - 1U)) != 0U)
#endif
        {
            /* The data is not blank */
            status = STATUS_QSPI_IP_ERROR;
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_FillTxBuf
 * Description   : Fill Tx buffer with the specified number of 4-byte entries
 * Qspi_Ip_FillTxBuf_Activity */
static void Qspi_Ip_FillTxBuf(QuadSPI_Type *baseAddr,
                              const uint8 *roData,
                              uint32 size,
                              uint32 paddingInfo
                             )
{
    uint32 sizeLeft = size;
    uint32 wordSize;
    uint32 data = 0xFFFFFFFFUL;
    uint8 *dataPtr = (uint8 *)(&data);
    uint32 byteCnt;
    const uint8 * roDataPtr = roData;

    uint32 prePadding   = paddingInfo >> 4U;
    uint32 postPadding  = paddingInfo & 0x0FU;

    /* Insert prePadding words */
    while (prePadding >= 4U)
    {
        Qspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
        prePadding -= 4U;
    }

    if (prePadding != 0U)
    {
        wordSize = prePadding + sizeLeft;

        if (wordSize > 4U)
        {
            wordSize  = 4U;
            sizeLeft -= (4U - prePadding);
        }
        else
        {
            /* Note for special case: prePadding + Data + postPadding are fit into a word
               Decreaseing postPadding is not needed because out of user data, all branches below will be skipped
             */
            sizeLeft = 0U;
        }

        /* Fill user data between prePadding and postPadding */
        for (byteCnt = prePadding; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            dataPtr[3U - byteCnt] = *roDataPtr;
            #else
            dataPtr[byteCnt] = *roDataPtr;
            #endif

            roDataPtr++;
        }
        Qspi_Ip_WriteTxData(baseAddr, data);
    }

    /* Check user buffer alignment */
    if (((Qspi_Ip_UintPtrType)roDataPtr & 0x3U) == 0U)
    {
        /* Process 4 bytes at a time to speed things up */
        while (sizeLeft >= 4U)
        {
            data = *(const uint32 *)((Qspi_Ip_UintPtrType)roDataPtr);  /* Casting through uint32 to avoid Misra 11.3 */
            sizeLeft -= 4U;
            roDataPtr = &(roDataPtr[4U]);
            Qspi_Ip_WriteTxData(baseAddr, data);
        }
    }

    /* Process remaining bytes one by one */
    while (sizeLeft > 0U)
    {
        /* Processes last few data bytes (less than 4) */
        data = 0xFFFFFFFFUL;
        wordSize = Qspi_Ip_GetWordSize(sizeLeft);

        for (byteCnt = 0U; byteCnt < wordSize; byteCnt++)
        {
            #if (defined(CORE_BIG_ENDIAN))
            dataPtr[3U - byteCnt] = *roDataPtr;
            #else
            dataPtr[byteCnt] = *roDataPtr;
            #endif

            roDataPtr++;
        }
        Qspi_Ip_WriteTxData(baseAddr, data);
        sizeLeft -= wordSize;
    }

    /* Insert postPadding words */
    while (postPadding >= 4U)
    {
        Qspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFUL);
        postPadding -= 4U;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ErrorCheck
 * Description   : Checks if there were errors during IP command execution
* @implements      Qspi_Ip_ErrorCheck_Activity */
static inline Qspi_Ip_StatusType Qspi_Ip_ErrorCheck(QuadSPI_Type *baseAddr)
{
    Qspi_Ip_StatusType status;

    if ((baseAddr->FR & QSPI_ERR_FLAGS_MASK) != 0U)
    {
        /* clear error flags */
        baseAddr->FR = QSPI_ERR_FLAGS_MASK;
        status = STATUS_QSPI_IP_ERROR;
    }
    else
    {
        status = STATUS_QSPI_IP_SUCCESS;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SwResetDelay
 * Description   : Insert waiting loops after changing the value of the software reset bits
 */
static inline void Qspi_Ip_SwResetDelay(void)
{
    volatile uint32 u32CurrentTicks;
    /* Prepare timeout counter */
    u32CurrentTicks = QSPI_IP_SOFTWARE_RESET_DELAY;
    /* Insert delay after changing the value of the software reset bits. */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SwReset
 * Description   : Resets the QuadSPI device
* @implements      Qspi_Ip_SwReset_Activity */
static void Qspi_Ip_SwReset(QuadSPI_Type *baseAddr)
{
    /* Software reset AHB domain and Serial Flash domain at the same time. */
    Qspi_Ip_SwResetOn(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Qspi_Ip_SwResetDelay();
    /* Disable QuadSPI module before de-asserting the reset bits. */
    Qspi_Ip_Disable(baseAddr);
    /* De-asset Software reset AHB domain and Serial Flash domain bits. */
    Qspi_Ip_SwResetOff(baseAddr);
    /* Re-enable QuadSPI module after reset. */
    Qspi_Ip_Enable(baseAddr);
    /* Insert delay after changing the value of the reset bits. */
    Qspi_Ip_SwResetDelay();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_AhbFlush
 * Description   : Reset AHB buffers
 */
static Qspi_Ip_StatusType Qspi_Ip_AhbFlush(QuadSPI_Type *baseAddr)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

#ifdef QuadSPI_SPTRCLR_ABRT_CLR_MASK
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Use the AHB buffer clear bit to avoid losing the DLL lock */
    Qspi_Ip_ClearAhbBuf(baseAddr);

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);

    /* Wait for clearing the AHB buffer pointers */
    while (!Qspi_Ip_GetClrAhbStatus(baseAddr))
    {
        /* An exit point for safety purpose only, because this loop is not expected to happen in practice */
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        if (u32ElapsedTicks >= u32TimeoutTicks)
        {
            status = STATUS_QSPI_IP_TIMEOUT;
            break;
        }
    }

#else
    /* Otherwise use the software reset */
    Qspi_Ip_SwReset(baseAddr);
#endif

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IsSideAvailableB
 * Description   : Check support Side B in user configuration
 *
 *END**************************************************************************/
static inline boolean Qspi_Ip_IsSideAvailableB(const Qspi_Ip_ControllerConfigType *userConfigPtr)
{
    boolean Status = FALSE;

    if ((userConfigPtr->memSizeB1 + userConfigPtr->memSizeB2) > 0U)
    {
        Status = TRUE;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureChipOptions
 * Description   : Configures chip-specific settings, e.g. SOCCR
 ***********************************************************************/
static void Qspi_Ip_ConfigureChipOptions(QuadSPI_Type *baseAddr,
                                         const Qspi_Ip_ControllerConfigType *userConfigPtr
                                        )
{
#if defined(FEATURE_QSPI_CHIP_OPTIONS_S32K148)
    /* always enable pads input buffers */
    uint8 clkOption = QSPI_MCR_SCLKCFG_INPUT_EN;
    uint32 chipOption = 0U;

    /* Configure MCR_SCLKCFG options */
    /* Configure module clock selection */
    if (QSPI_IP_CLK_SRC_BUS_CLK == userConfigPtr->clockSrc)
    {
        clkOption |= QSPI_MCR_SCLKCFG_CLK_MOD;
    }
    /* Configure internal reference clock selection */
    if (QSPI_IP_CLK_REF_FIRC_DIV1 == userConfigPtr->clockRef)
    {
        clkOption |= QSPI_MCR_SCLKCFG_CLK_SRC;
    }
    /* Configure external DQS mode for Flash B (HyperRAM Enabled) */
    if (QSPI_IP_READ_MODE_EXTERNAL_DQS == userConfigPtr->readModeB)
    {
        clkOption |= QSPI_MCR_SCLKCFG_EXT_DQS;
    }
    /* Select reference clock for DQS for each side */
    if (QSPI_IP_READ_MODE_LOOPBACK == userConfigPtr->readModeA)
    {
        clkOption |= (uint8)(QSPI_MCR_SCLKCFG_DQS_SEL_A);
    }
    if (QSPI_IP_READ_MODE_LOOPBACK == userConfigPtr->readModeB)
    {
        clkOption |= (uint8)(QSPI_MCR_SCLKCFG_DQS_SEL_B);
    }
    /* Configure inverted DQS: 0-Inverted / 1-Not Inverted */
    if ((boolean)FALSE == userConfigPtr->dqsInvertA)
    {
        clkOption |= (uint8)(QSPI_MCR_SCLKCFG_DQS_INV_A);
    }
    if ((boolean)FALSE == userConfigPtr->dqsInvertB)
    {
        clkOption |= (uint8)(QSPI_MCR_SCLKCFG_DQS_INV_B);
    }
    Qspi_Ip_SetClockOptions(baseAddr, clkOption);

    /* Configure SOCCR options */
    /* Disable divider before configuring it */
    Qspi_Ip_SetChipOptions(baseAddr, QuadSPI_SOCCR_PDD_MASK);
    chipOption |= QuadSPI_SOCCR_PD((uint32)userConfigPtr->clockRefDiv - 1U);
    chipOption |= ((uint32)userConfigPtr->dqsDelayA << QuadSPI_SOCCR_DSQ_DEL_A) +
                  ((uint32)userConfigPtr->dqsDelayB << QuadSPI_SOCCR_DSQ_DEL_B);
    /* Write configuration, keep divider disabled */
    Qspi_Ip_SetChipOptions(baseAddr, chipOption | QuadSPI_SOCCR_PDD_MASK);
    /* Enable divider */
    Qspi_Ip_SetChipOptions(baseAddr, chipOption);

#elif defined(FEATURE_QSPI_CHIP_OPTIONS_S32K3)
    (void)userConfigPtr;
    Qspi_Ip_SetChipOptions(baseAddr, 0x0000000E);  /* set ibe=1, obe=1, dse=1 and sre=0 */

#else
    /* Do nothing */
    (void)userConfigPtr;
    (void)baseAddr;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureReadOptions
 * Description   : Configures data read settings
 * Qspi_Ip_ConfigureReadOptions_Activity */
static void Qspi_Ip_ConfigureReadOptions(QuadSPI_Type *baseAddr,
                                         const Qspi_Ip_ControllerConfigType *userConfigPtr
                                        )
{
    /* Always enable DQS */
    QSPI_DQS_Enable(baseAddr);
    QSPI_DQS_LatEnable(baseAddr, userConfigPtr->dqsLatency);

    if (QSPI_IP_DATA_RATE_SDR == userConfigPtr->dataRate)
    {
#ifdef QuadSPI_MCR_DDR_EN_MASK
        QSPI_DDR_Disable(baseAddr);
#endif /* QuadSPI_MCR_DDR_EN_MASK */
#ifdef QuadSPI_FLSHCR_TDH_MASK
        /* Ignore output data align setting in SDR mode */
        Qspi_Ip_SetDataInHoldTime(baseAddr, QSPI_IP_FLASH_DATA_ALIGN_REFCLK);
#endif /* QuadSPI_FLSHCR_TDH_MASK */
    }
    else  /* QSPI_IP_DATA_RATE_DDR */
    {
#ifdef QuadSPI_MCR_DDR_EN_MASK
        QSPI_DDR_Enable(baseAddr);
#endif /* QuadSPI_MCR_DDR_EN_MASK */
#ifdef QuadSPI_FLSHCR_TDH_MASK
        Qspi_Ip_SetDataInHoldTime(baseAddr, userConfigPtr->dataAlign);
#endif /* QuadSPI_FLSHCR_TDH_MASK */
    }



    if (TRUE == Qspi_Ip_IsSideAvailableB(userConfigPtr))
    {

    }

    (void)userConfigPtr;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_AhbSetup
 * Description   : Sets up AHB accesses to the serial flash
* @implements      Qspi_Ip_AhbSetup_Activity */
static Qspi_Ip_StatusType Qspi_Ip_AhbSetup(uint32 instance,
                                           const Qspi_Ip_ControllerAhbConfigType *config
                                          )
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(0U == (config->sizes[0U] & 7U));
    QSPI_IP_DEV_ASSERT(((uint32)config->sizes[0U] +
                        (uint32)config->sizes[1U] +
                        (uint32)config->sizes[2U] +
                        (uint32)config->sizes[3U]) <= FEATURE_QSPI_AHB_BUF_SIZE);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* configure AHB transfer sizes to match the buffer sizes */
    /* Set AHB buffer 0 */
    Qspi_Ip_SetAhbBuf0(baseAddr, config->sizes[0U], config->masters[0U]);
    /* Set AHB buffer 1 */
    Qspi_Ip_SetAhbBuf1(baseAddr, config->sizes[1U], config->masters[1U]);
    /* Set AHB buffer 2 */
    Qspi_Ip_SetAhbBuf2(baseAddr, config->sizes[2U], config->masters[2U]);
    /* Set AHB buffer 3 */
    Qspi_Ip_SetAhbBuf3(baseAddr, config->sizes[3U], config->masters[3U], config->allMasters);
    /* Set AHB buffer index 0 */
    Qspi_Ip_SetAhbBuf0Ind(baseAddr, (uint32)config->sizes[0U]);
    /* Set AHB buffer index 1 */
    Qspi_Ip_SetAhbBuf1Ind(baseAddr, (uint32)config->sizes[0U] + (uint32)config->sizes[1U]);
    /* Set AHB buffer index 2 */
    Qspi_Ip_SetAhbBuf2Ind(baseAddr, (uint32)config->sizes[0U] + (uint32)config->sizes[1U] + (uint32)config->sizes[2U]);

    return STATUS_QSPI_IP_SUCCESS;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the SFAR & IPCR registers.
 *
 * @param[in] BaseAddress base address of the given QuadSPI instance
 * @param[in] Address address to be written into SFAR
 * @param[in] DataSize data size to be written into IPCR
 * @param[in] SeqId sequence id where the command is stored in the physical lut
 *
 * @retval STATUS_QSPI_IP_SUCCESS SFAR and IPCR writes passed the MDAD checks
 * @retval STATUS_QSPI_IP_ERROR a common or a queue error has occurred
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static void Qspi_Ip_NewIpsTransaction
(
    QuadSPI_Type * BaseAddress,
    uint32 Address,
    uint16 DataSize,
    uint8 SeqId)
{

    Qspi_Ip_SetIpAddr(BaseAddress, Address);
    Qspi_Ip_IpTrigger(BaseAddress, SeqId, DataSize);
}


/*! @endcond */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetLut
 * Description   : Configures a pair of LUT commands in the specified LUT register
 *
 *END**************************************************************************/
void Qspi_Ip_SetLut(uint32 instance,
                    uint8 LutRegister,
                    Qspi_Ip_InstrOpType operation0,
                    Qspi_Ip_InstrOpType operation1
                   )
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance    < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(LutRegister < QuadSPI_LUT_COUNT);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];
    /* Set Lut config */
    baseAddr->LUT[LutRegister] = QSPI_IP_PACK_LUT_REG(operation0, operation1);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_WriteLuts_Privileged
 * Description   : Configures pairs of LUT commands from the specified LUT register
 *
 *END**************************************************************************/
void Qspi_Ip_WriteLuts_Privileged(uint32 Instance,
                                  uint8 StartLutRegister,
                                  const uint32 *Data,
                                  uint8 Size
                                 )
{
    QuadSPI_Type *BaseAddr = Qspi_Ip_BaseAddress[Instance];
    uint8 Index;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(Instance                   < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(StartLutRegister           < QuadSPI_LUT_COUNT);
    QSPI_IP_DEV_ASSERT((StartLutRegister + Size) <= QuadSPI_LUT_COUNT);
    QSPI_IP_DEV_ASSERT(Size                      <= FEATURE_QSPI_LUT_SEQUENCE_SIZE);
#endif

    for (Index = 0U; Index < Size; Index++)
    {
        BaseAddr->LUT[StartLutRegister + Index] = Data[Index];
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetAhbSeqId_Privileged
 * Description   : Sets sequence ID for AHB operations
 *
 *END**************************************************************************/
void Qspi_Ip_SetAhbSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   )
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* Initialize driver status structure */
    baseAddr = Qspi_Ip_BaseAddress[instance];
    /* Set sequence ID for AHB */
    baseAddr->BFGENCR =  QuadSPI_BFGENCR_SEQID(seqID);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetSerialFlashAddr
 * Description   : Configure the Serial Flash Memory Address
 *
 *END**************************************************************************/
static inline void Qspi_Ip_SetSerialFlashAddress(QuadSPI_Type *baseAddr,
                                                 const Qspi_Ip_ControllerConfigType * userConfigPtr
                                                )
{
    Qspi_Ip_SetAddrOptions(baseAddr, userConfigPtr->columnAddr, userConfigPtr->wordAddresable);

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_SetCsTime
 * Description   : Configure the CS holdtime and CS setup time
 *
 *END**************************************************************************/
static inline void Qspi_Ip_SetCsTime(QuadSPI_Type *baseAddr,
                                     const Qspi_Ip_ControllerConfigType * userConfigPtr
                                    )
{
    /* Configure the CS holdtime and CS setup time */
    Qspi_Ip_SetCsHoldTime(baseAddr, userConfigPtr->csHoldTime);
    Qspi_Ip_SetCsSetupTime(baseAddr, userConfigPtr->csSetupTime);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureBuffers
 * Description   : Configure the Tx, Rx and AHB buffers
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureBuffers(uint32 instance,
                                            QuadSPI_Type *baseAddr,
                                            const Qspi_Ip_ControllerConfigType * userConfigPtr
                                           )
{
#ifdef QuadSPI_RBCT_RXBRD_MASK
    /* Read Rx buffer through RBDR registers */
    Qspi_Ip_SetRxBufReadout(baseAddr, QSPI_IP_RX_READOUT_IP);
#endif
    /* Set watermarks */
    Qspi_Ip_SetTxWatermark(baseAddr, 1U);
    Qspi_Ip_SetRxWatermark(baseAddr, 1U);
    /* Configure AHB buffers settings */
    (void)Qspi_Ip_AhbSetup(instance, &(userConfigPtr->ahbConfig));
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureControllerA
 * Description   : Configure for side A
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureControllerA(uint32 instance,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr)
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    uint32 AhbAddress = Qspi_Ip_AhbAddress[instance];

    /* Configure external flash memory map Size A */
    Qspi_Ip_SetMemMapSizeA(AhbAddress, baseAddr, userConfigPtr->memSizeA1, userConfigPtr->memSizeA2);

    /* Configure idle line value side A */
    Qspi_Ip_SetIdleLineValuesA(baseAddr, userConfigPtr->io2IdleValueA, userConfigPtr->io3IdleValueA);


}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureControllerB
 * Description   : Configure for side B
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureControllerB(uint32 instance,
                                                const Qspi_Ip_ControllerConfigType *userConfigPtr)
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Configure external flash memory map Side B,
       the end address of side B must be greater than or equal to the end address of side A2
    */
    Qspi_Ip_SetMemMapSizeB(baseAddr, userConfigPtr->memSizeB1, userConfigPtr->memSizeB2);
    /* Check Size B is available */
    if (TRUE == Qspi_Ip_IsSideAvailableB(userConfigPtr))
    {
        /* Unused side lines are "no matter" so just repeat idle settings on both sides */
        Qspi_Ip_SetIdleLineValuesB(baseAddr, userConfigPtr->io2IdleValueB, userConfigPtr->io3IdleValueB);


    }
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ConfigureController
 * Description   : Configure the controller register following user configurations
 *
 *END**************************************************************************/
static inline void Qspi_Ip_ConfigureController(uint32 instance,
                                               const Qspi_Ip_ControllerConfigType * userConfigPtr
                                              )
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];

    Qspi_Ip_ConfigureControllerA(instance, userConfigPtr);

    Qspi_Ip_ConfigureControllerB(instance, userConfigPtr);

    /* Configure the Serial Flash Memory Address */
    Qspi_Ip_SetSerialFlashAddress(baseAddr, userConfigPtr);

    Qspi_Ip_SetRxCfg(baseAddr, userConfigPtr->sampleDelay, userConfigPtr->samplePhase);

    /* Configure the CS holdtime and CS setup time */
    Qspi_Ip_SetCsTime(baseAddr, userConfigPtr);

    /* Configure buffers */
    Qspi_Ip_ConfigureBuffers(instance, baseAddr, userConfigPtr);

    /* Configure read options */
    Qspi_Ip_ConfigureReadOptions(baseAddr, userConfigPtr);

    /* Configure chip-specific options */
    Qspi_Ip_ConfigureChipOptions(baseAddr, userConfigPtr);

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerInit
 * Description   : Initializes the qspi controller
 * @implements     Qspi_Ip_ControllerInit_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerInit(uint32 instance,
                                          const Qspi_Ip_ControllerConfigType * userConfigPtr
                                         )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance       < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(userConfigPtr != NULL_PTR);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Ensure module is disabled */
    Qspi_Ip_Disable(baseAddr);

    /* Ensure all registers contain their reset value */
    Qspi_Ip_ResetAllRegisters(baseAddr);

    /* Configure the controller following the user configurations */
    Qspi_Ip_ConfigureController(instance, userConfigPtr);

    /* Enable QuadSPI module */
    Qspi_Ip_Enable(baseAddr);

    /* Reset serial flash and AHB domains */
    Qspi_Ip_SwReset(baseAddr);


    /* Workaround to clear CRC and ECC errors flags */
    baseAddr->FR = (uint32)0xFFFFFFFFUL;

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerDeinit
 * Description   : De-initialize the qspi driver
 * @implements     Qspi_Ip_ControllerDeinit_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerDeinit(uint32 instance)
{
    QuadSPI_Type *baseAddr;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Disable QuadSPI module */
    Qspi_Ip_Disable(baseAddr);


    return STATUS_QSPI_IP_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_Abort
 * Description   : Force the Qspi controller to cancel any on-going transactions by performing the software reset requence.
 *                 This can be used to recover the hardware controller from being stuck in BUSY state.
 *                 Re-configure DLL is needed to avoid side-effects on the DLL after the S/W reset.
 */
Qspi_Ip_StatusType Qspi_Ip_Abort(uint32 instance)
{
#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* Get the base address base on the instance */
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Reset serial flash and AHB domains */
    Qspi_Ip_SwReset(baseAddr);


    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_GetBaseAdress
 * Description   : Returns the physical base address of a flash device on the AHB bus.
 *                 The controller must be initialized prior to calling this function.
 * @implements     Qspi_Ip_GetBaseAdress_Activity */
uint32 Qspi_Ip_GetBaseAdress(uint32 instance,
                             Qspi_Ip_ConnectionType connectionType
                            )
{
    const QuadSPI_Type *baseAddr;
    uint32 address = 0U;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    switch (connectionType)
    {
        case QSPI_IP_SIDE_A1:
            /* get base address of side A1 */
            address = Qspi_Ip_AhbAddress[instance];
            break;
        case QSPI_IP_SIDE_A2:
            /* get base address of side A2 */
            address = baseAddr->SFA1AD;
            break;
        case QSPI_IP_SIDE_B1:
            /* get base address of side B1 */
            address = baseAddr->SFA2AD;
            break;
        case QSPI_IP_SIDE_B2:
            /* get base address of side B2 */
            address = baseAddr->SFB1AD;
            break;
        default:
            ; /* Not possible */
            break;
    }

    return address;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpCommand
 * Description   : Launches a simple IP command
 * @implements     Qspi_Ip_IpCommand_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpCommand(uint32 instance,
                                     uint8 SeqId,
                                     uint32 addr
                                    )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(SeqId    < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Reset AHB buffers to force re-read from memory after erase operation */
    status = Qspi_Ip_AhbFlush(baseAddr);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Launch the IP command */
        Qspi_Ip_NewIpsTransaction(baseAddr, addr, 0U, SeqId);

        /* Add Fault Injection point for FR_ILLINE flag */
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPCOMMAND);

        status = Qspi_Ip_CmdWaitComplete(instance);

        /* Make sure there is no garbage in Rx fifo in case of triggering a dummy READ instruction.
        This clears RBSR[RDBFL] to ensure QuadSPI is idle from SFP point of view and avoid the Master timeout error.
        */
        Qspi_Ip_ClearRxBuf(baseAddr);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_CmdWaitComplete
 * Description   : Wait until Qspi controller is not busy or timeout
 */
static Qspi_Ip_StatusType Qspi_Ip_CmdWaitComplete(uint32 instance)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32  u32ElapsedTicks = 0UL;
    uint32  u32TimeoutTicks;
    uint32  u32CurrentTicks;

    /* Prepare timeout counter */
    u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);

    MCAL_FAULT_INJECTION_POINT(QSPI_IP_FMEA_WAIT_TRANSACTION_COMPLETE);

    /* Wait for command to be completed */
    do
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        status = Qspi_Ip_ControllerGetStatus(instance);
    }
    while ((u32ElapsedTicks < u32TimeoutTicks) && (STATUS_QSPI_IP_BUSY == status));

    if (STATUS_QSPI_IP_BUSY == status)
    {
        status = STATUS_QSPI_IP_TIMEOUT;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpRead
 * Description   : Launches an IP read command
 * @implements     Qspi_Ip_IpRead_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpRead(uint32 instance,
                                  uint8 SeqId,
                                  uint32 addr,
                                  uint8 * dataRead,
                                  const uint8 * dataCmp,
                                  uint32 size
                                 )
{
    Qspi_Ip_StatusType status;
    QuadSPI_Type *baseAddr;
    uint32 padding;
    uint16 Idatsz = 0U;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(SeqId    < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
    QSPI_IP_DEV_ASSERT(size    <= FEATURE_QSPI_RX_BUF_SIZE);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];
    padding  = (uint32)(Qspi_Ip_MemoryPadding[instance]);

    /* If size is odd, round up to even size; this is needed in octal DDR mode */
    Idatsz = (uint16)((size + 1U) & (~1U));

    /* Make sure there is no garbage in Rx fifo */
    Qspi_Ip_ClearRxBuf(baseAddr);

    Qspi_Ip_NewIpsTransaction(baseAddr, addr, Idatsz, SeqId);

    /* Add Fault Injection point for FR_ILLINE flag */
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPREAD);

    /* Wait until the command is sent */
    status = Qspi_Ip_CmdWaitComplete(instance);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Process received data */
        if (dataRead != NULL_PTR)
        {
            /* Normal read */
            status = Qspi_Ip_ProcessDataRead(dataRead, size, baseAddr, padding);
        }
        else if (dataCmp != NULL_PTR)
        {
            /* Verify */
            status = Qspi_Ip_ProcessDataVerify(dataCmp, size, baseAddr, padding);
        }
        else
        {
            /* Blank check */
            status = Qspi_Ip_ProcessDataBlankCheck(size, baseAddr, padding);
        }
    }

    /* Reset Rx fifo */
    Qspi_Ip_ClearRxBuf(baseAddr);

    /* Clear padding, only needed for the first read */
    Qspi_Ip_MemoryPadding[instance] = 0U;

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_InvalidateTxBuf
 * Description   : Invalidates the TX buffer content and wait until it is completed or timed out
 * Qspi_Ip_InvalidateTxBuf_Activity */
static inline void Qspi_Ip_InvalidateTxBuf(uint32 instance)
{
    QuadSPI_Type *baseAddr = Qspi_Ip_BaseAddress[instance];
    volatile uint32 u32CurrentTicks;

    /* Start TX FIFO reset */
    Qspi_Ip_ClearTxBuf(baseAddr);

    /* Prepare timeout counter */
    u32CurrentTicks = QSPI_IP_TX_BUFFER_RESET_DELAY;
    /* Insert delay to ensure TX FIFO reset is complete */
    while (u32CurrentTicks > 0U)
    {
        u32CurrentTicks--;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_PadTxBuf
 * Description   : Pad Tx buffer up to a minimum number of entries required
 *                 by the device for transmission to start
 *
 *END**************************************************************************/
static void Qspi_Ip_PadTxBuf(QuadSPI_Type *baseAddr)
{
#if (FEATURE_QSPI_TX_MIN_BUF_FILL > 1)
    uint32 bufFill = Qspi_Ip_GetTxBufFill(baseAddr);
    /* Pad buffer will blank data */
    while ((bufFill < FEATURE_QSPI_TX_MIN_BUF_FILL) || ((bufFill & 3U) != 0U))
    {
        Qspi_Ip_WriteTxData(baseAddr, 0xFFFFFFFFU);
        bufFill++;
    }
#else
    /* Remove unused variable */
    (void)baseAddr;
#endif
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_IpWrite
 * Description   : Launches an IP write command
 * @implements     Qspi_Ip_IpWrite_Activity */
Qspi_Ip_StatusType Qspi_Ip_IpWrite(uint32 instance,
                                   uint8 SeqId,
                                   uint32 addr,
                                   const uint8 * data,
                                   uint32 size
                                  )
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;
    uint32 padding;
    uint16 TotalSize = 0U;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT(instance < QuadSPI_INSTANCE_COUNT);
    QSPI_IP_DEV_ASSERT(size    <= (uint16)FEATURE_QSPI_TX_BUF_SIZE);
    QSPI_IP_DEV_ASSERT(SeqId    < (QuadSPI_LUT_COUNT / FEATURE_QSPI_LUT_SEQUENCE_SIZE));
    QSPI_IP_DEV_ASSERT(data    != NULL_PTR);
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    /* Reset AHB buffers to force re-read from memory after write operation */
    status = Qspi_Ip_AhbFlush(baseAddr);

    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        /* Ensure there is no garbage in Tx FIFO */
        Qspi_Ip_InvalidateTxBuf(instance);

        padding = Qspi_Ip_MemoryPadding[instance];
        TotalSize = (uint16)(size + (padding >> 4U) + (padding & 0x0FU));
        Qspi_Ip_MemoryPadding[instance] = 0U;  /* Clear padding */

        /* Set write address */
        Qspi_Ip_SetIpAddr(baseAddr, addr);

        /* Fill Tx buffer */
        Qspi_Ip_FillTxBuf(baseAddr, data, size, padding);

        /* Pad Tx buffer up to the minimum number of entries required by the device */
        Qspi_Ip_PadTxBuf(baseAddr);

        /* Trigger IP command with specified sequence and size */
        Qspi_Ip_IpTrigger(baseAddr, SeqId, TotalSize);

        /* Add Fault Injection point for FR_TBUF flag */
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_IPWRITE);

        /* Wait until the command is sent */
        status = Qspi_Ip_CmdWaitComplete(instance);
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Qspi_Ip_ControllerGetStatus
 * Description   : Checks the status of the currently running IP command
 * @implements     Qspi_Ip_ControllerGetStatus_Activity */
Qspi_Ip_StatusType Qspi_Ip_ControllerGetStatus(uint32 instance)
{
    QuadSPI_Type *baseAddr;
    Qspi_Ip_StatusType status;

#if (QSPI_IP_DEV_ERROR_DETECT == STD_ON)
    QSPI_IP_DEV_ASSERT((instance < QuadSPI_INSTANCE_COUNT));
#endif

    /* Get the base address base on the instance */
    baseAddr = Qspi_Ip_BaseAddress[instance];

    MCAL_FAULT_INJECTION_POINT(QSPI_IP_FMEA_CONTROLLER_GET_STATUS);
    /* Check device for busy status */
    if (Qspi_Ip_GetBusyStatus(baseAddr))
    {
        status = STATUS_QSPI_IP_BUSY;
    }
    else
    {
        /* Check for errors reported by the QuadSPI */
        status = Qspi_Ip_ErrorCheck(baseAddr);
    }
    return status;
}


/*
 * Set all hardware registers to their reset value
 */
inline static void Qspi_Ip_ResetAllRegisters(QuadSPI_Type *BaseAddr)
{
    uint8 cnt = 0U;

    /* reset MCR register */
    BaseAddr->MCR     = (uint32)0x000F400CUL;
    /* reset IPCR register */
    BaseAddr->IPCR    = (uint32)0x00000000UL;
    /* reset FLSHCR register */
    BaseAddr->FLSHCR  = (uint32)0x00000303UL;
    /* reset BUF0CR register */
    BaseAddr->BUF0CR  = (uint32)0x00000003UL;
    /* reset BUF1CR register */
    BaseAddr->BUF1CR  = (uint32)0x00000002UL;
    /* reset BUF2CR register */
    BaseAddr->BUF2CR  = (uint32)0x00000001UL;
    /* reset BUF3CR register */
    BaseAddr->BUF3CR  = (uint32)0x80000000UL;
    /* reset BFGENCR register */
    BaseAddr->BFGENCR = (uint32)0x00000000UL;
    /* reset SOCCR register */
    BaseAddr->SOCCR   = (uint32)0x00000000UL;
    /* reset BUF0IND register */
    BaseAddr->BUF0IND = (uint32)0x00000000UL;
    /* reset BUF1IND register */
    BaseAddr->BUF1IND = (uint32)0x00000000UL;
    /* reset BUF2IND register */
    BaseAddr->BUF2IND = (uint32)0x00000000UL;
    /* reset SFAR register */
    BaseAddr->SFAR    = (uint32)0x00000000UL;
    /* reset SFACR register */
    BaseAddr->SFACR   = (uint32)0x00000000UL;
    /* reset SMPR register */
    BaseAddr->SMPR    = (uint32)0x00000000UL;
    /* reset RBCT register */
    BaseAddr->RBCT    = (uint32)0x00000000UL;
    /* reset TBDR register */
    BaseAddr->TBDR    = (uint32)0x00000000UL;
    /* reset TBCT register */
    BaseAddr->TBCT    = (uint32)0x00000000UL;
    /* reset FR register - Write 1 to clear */
    BaseAddr->FR      = (uint32)0x0C83F0C1UL;
    /* reset RSER register */
    BaseAddr->RSER    = (uint32)0x00000000UL;
    /* reset SPTRCLR register: clear both IP and AHB sequence pointers */
    BaseAddr->SPTRCLR = (uint32)QuadSPI_SPTRCLR_BFPTRC_MASK | (uint32)QuadSPI_SPTRCLR_IPPTRC_MASK;
    /* For S32K148, these bits should be programmed two times */
    BaseAddr->SPTRCLR = (uint32)QuadSPI_SPTRCLR_BFPTRC_MASK | (uint32)QuadSPI_SPTRCLR_IPPTRC_MASK;
    /* reset SFA1AD register */
    BaseAddr->SFA1AD  = (uint32)0x6C000000UL;
    /* reset SFA2AD register */
    BaseAddr->SFA2AD  = (uint32)0x6C000000UL;
    /* reset SFB1AD register */
    BaseAddr->SFB1AD  = (uint32)0x70000000UL;
    /* reset SFB2AD register */
    BaseAddr->SFB2AD  = (uint32)0x70000000UL;
    /* reset LUTKEY register */
    BaseAddr->LUTKEY  = (uint32)0x5AF05AF0UL;
    /* reset LCKCR register */
    BaseAddr->LCKCR   = (uint32)0x00000002UL;
    /* reset LUT0 register */
    BaseAddr->LUT[0]  = (uint32)0x08180403UL;
    /* reset LUT1 register */
    BaseAddr->LUT[1]  = (uint32)0x24001C08UL;
    for (cnt = 2U; cnt < QuadSPI_LUT_COUNT; cnt++)
    {
        BaseAddr->LUT[cnt] = (uint32)0x00000000UL;
    }

    /* avoid warning unused variable */
    (void)cnt;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#endif /* (QSPI_IP_MEM_INSTANCE_COUNT > 0) */


#ifdef __cplusplus
}
#endif

/** @} */
