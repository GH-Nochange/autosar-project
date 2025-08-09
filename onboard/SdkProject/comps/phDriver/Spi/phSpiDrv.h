#ifndef PH_SPIDRV_H
#define PH_SPIDRV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "device_registers.h"
#include "flexio.h"
#include "edma_driver.h"
#include "callbacks.h"
#include "phTypes.h"

/* =========================================================================
 *  ENUM & STRUCT ĐỊNH NGHĨA CẤU HÌNH SPI
 * ========================================================================= */

/**
 * @brief Thứ tự truyền bit
 */
typedef enum
{
    phSpiDrv_TransferMsbFirst = 0u,  /**< MSB truyền trước */
    phSpiDrv_TransferLsbFirst = 1u   /**< LSB truyền trước */
} phSpiDrv_TransferBitOrder_t;

/**
 * @brief Kích thước dữ liệu truyền
 */
typedef enum
{
    phSpiDrv_Transfer1Byte = 1u, /**< 8-bit */
    phSpiDrv_Transfer2Byte = 2u, /**< 16-bit */
    phSpiDrv_Transfer4Byte = 4u  /**< 32-bit */
} phSpiDrv_TransferSize_t;

/**
 * @brief Cấu hình SPI Master
 * @note  Baudrate chỉ cấu hình tại Init, không thay đổi khi đang chạy.
 */
typedef struct
{
    uint32_t baudRate;                 /**< Tốc độ baud (Hz) */
    flexio_driver_type_t driverType;   /**< Kiểu driver: Polling, Interrupt, DMA */
    phSpiDrv_TransferBitOrder_t bitOrder; /**< Thứ tự bit truyền */
    phSpiDrv_TransferSize_t transferSize; /**< Kích thước dữ liệu truyền */
    uint8_t clockPolarity;             /**< CPOL: 0 = Idle Low, 1 = Idle High */
    uint8_t clockPhase;                /**< CPHA: 0 = Sample đầu, 1 = Sample sau */
    uint8_t mosiPin;                    /**< Chân MOSI */
    uint8_t misoPin;                    /**< Chân MISO */
    uint8_t sckPin;                     /**< Chân SCK */
    uint8_t ssPin;                      /**< Chân SS */
    spi_callback_t callback;           /**< Hàm callback khi truyền xong (có thể NULL) */
    void *callbackParam;               /**< Tham số truyền vào callback */
    uint8_t rxDMAChannel;               /**< Kênh DMA nhận (nếu dùng DMA) */
    uint8_t txDMAChannel;               /**< Kênh DMA truyền (nếu dùng DMA) */
} phSpiDrv_MasterConfig_t;

/**
 * @brief Cấu hình SPI Slave
 */
typedef struct
{
    flexio_driver_type_t driverType;   /**< Kiểu driver: Polling, Interrupt, DMA */
    phSpiDrv_TransferBitOrder_t bitOrder; /**< Thứ tự bit truyền */
    phSpiDrv_TransferSize_t transferSize; /**< Kích thước dữ liệu truyền */
    uint8_t clockPolarity;             /**< CPOL: 0 = Idle Low, 1 = Idle High */
    uint8_t clockPhase;                /**< CPHA: 0 = Sample đầu, 1 = Sample sau */
    uint8_t mosiPin;                    /**< Chân MOSI */
    uint8_t misoPin;                    /**< Chân MISO */
    uint8_t sckPin;                     /**< Chân SCK */
    uint8_t ssPin;                      /**< Chân SS */
    spi_callback_t callback;           /**< Hàm callback khi truyền xong (có thể NULL) */
    void *callbackParam;               /**< Tham số truyền vào callback */
    uint8_t rxDMAChannel;               /**< Kênh DMA nhận (nếu dùng DMA) */
    uint8_t txDMAChannel;               /**< Kênh DMA truyền (nếu dùng DMA) */
} phSpiDrv_SlaveConfig_t;

/* =========================================================================
 *  API CHO SPI MASTER
 * ========================================================================= */

/**
 * @brief Khởi tạo SPI Master
 * @param instance  Số instance FlexIO
 * @param cfg       Con trỏ tới cấu hình master
 * @return EER_OK nếu thành công
 */
PhTypes_ErrorCode_t phSpiDrv_MasterInit(uint32_t instance, const phSpiDrv_MasterConfig_t *cfg);

/**
 * @brief Giải phóng SPI Master
 */
PhTypes_ErrorCode_t phSpiDrv_MasterDeinit(uint32_t instance);

/**
 * @brief Truyền/Nhận dữ liệu không chặn (non-blocking)
 * @param tx   Buffer dữ liệu truyền (có thể NULL nếu chỉ nhận)
 * @param rx   Buffer dữ liệu nhận (có thể NULL nếu chỉ truyền)
 * @param len  Số byte cần truyền/nhận
 */
PhTypes_ErrorCode_t phSpiDrv_MasterTransfer(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len);

/**
 * @brief Truyền/Nhận dữ liệu chặn (blocking)
 * @param timeoutMs Thời gian chờ tối đa (ms)
 */
PhTypes_ErrorCode_t phSpiDrv_MasterTransferBlocking(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len, uint32_t timeoutMs);

/**
 * @brief Hủy truyền đang thực hiện
 */
PhTypes_ErrorCode_t phSpiDrv_MasterTransferAbort(uint32_t instance);

/**
 * @brief Lấy trạng thái truyền (non-blocking)
 * @param bytesRemaining Trả về số byte còn lại chưa truyền
 */
PhTypes_ErrorCode_t phSpiDrv_MasterGetStatus(uint32_t instance, uint32_t *bytesRemaining);

/* =========================================================================
 *  API CHO SPI SLAVE
 * ========================================================================= */

/**
 * @brief Khởi tạo SPI Slave
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveInit(uint32_t instance, const phSpiDrv_SlaveConfig_t *cfg);

/**
 * @brief Giải phóng SPI Slave
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveDeinit(uint32_t instance);

/**
 * @brief Truyền/Nhận dữ liệu không chặn (non-blocking)
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveTransfer(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len);

/**
 * @brief Truyền/Nhận dữ liệu chặn (blocking)
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveTransferBlocking(uint32_t instance, const uint8_t *tx, uint8_t *rx, uint32_t len, uint32_t timeoutMs);

/**
 * @brief Hủy truyền đang thực hiện
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveTransferAbort(uint32_t instance);

/**
 * @brief Lấy trạng thái truyền (non-blocking)
 * @param bytesRemaining Trả về số byte còn lại chưa truyền
 */
PhTypes_ErrorCode_t phSpiDrv_SlaveGetStatus(uint32_t instance, uint32_t *bytesRemaining);

#ifdef __cplusplus
}
#endif

#endif /* PH_SPIDRV_H */
