#ifndef GPIODRV_H_
#define GPIODRV_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pins_driver.h"
#include "device_registers.h"

/**
 * @brief Danh sách các chân GPIO điều khiển (output, interrupt...)
 */
typedef enum {
    PH_GPIO_RED_LED = 0,     /**< Đèn LED đỏ */
    PH_GPIO_GREEN_LED,       /**< Đèn LED xanh lá */
    PH_GPIO_BLUE_LED,        /**< Đèn LED xanh dương */
    PH_GPIO_NUM              /**< Tổng số GPIO được cấu hình */
} phDriverGpio_Name_t;

/**
 * @brief Giá trị mức logic của chân GPIO
 */
typedef enum {
    PH_GPIO_LOW  = 0U,        /**< Mức thấp (0V) */
    PH_GPIO_HIGH = 1U         /**< Mức cao (3.3V hoặc 5V tuỳ mạch) */
} phDriverGpio_PinLevel_t;

/** 
 * @brief Kiểu callback cho GPIO interrupt, không có tham số.
 */
typedef void (*phDriverGpio_Callback_t)(void);

/**
 * @brief Cấu hình ngắt cho một chân GPIO
 */
typedef struct
{
    port_interrupt_config_t intConfig;  /**< Loại ngắt: rising, falling, both edge, logic level... */
    bool digitalFilterEnable;           /**< Bật/tắt bộ lọc nhiễu kỹ thuật số */
} phDriverGpio_IrqConfig_t;

/**
 * @brief Khởi tạo toàn bộ các chân GPIO đã được định nghĩa trong driver
 * 
 * Bao gồm thiết lập mux, hướng xuất (output), giá trị khởi tạo và driver control.
 * Thường dùng khi khởi động hệ thống.
 */
void phDriverGpio_Init(void);

/**
 * @brief Giải phóng các chân GPIO, đưa về trạng thái an toàn
 * 
 * Đặt mức cao (để tắt LED nếu active-low), đổi hướng chân về input và tắt mux.
 */
void phDriverGpio_DeInit(void);

/**
 * @brief Thiết lập mức logic cho một chân GPIO
 * 
 * @param pinConfig    Tên chân GPIO theo enum `phDriverGpio_Name_t`
 * @param pinLevel     Mức logic cần đặt: `PH_GPIO_LOW` hoặc `PH_GPIO_HIGH`
 */
void phDriverGpio_SetPinLevel(phDriverGpio_Name_t pinConfig, phDriverGpio_PinLevel_t pinLevel);

/**
 * @brief Đảo trạng thái mức logic của chân GPIO
 * 
 * Nếu đang HIGH sẽ chuyển sang LOW, và ngược lại.
 * 
 * @param pinConfig    Tên chân GPIO
 */
void phDriverGpio_TogglePin(phDriverGpio_Name_t pinConfig);

/**
 * @brief Đọc mức logic hiện tại của chân GPIO
 * 
 * @param pinConfig    Tên chân GPIO
 * @return PH_GPIO_LOW hoặc PH_GPIO_HIGH tuỳ theo trạng thái thực tế
 */
phDriverGpio_PinLevel_t phDriverGpio_GetPinLevel(phDriverGpio_Name_t pinConfig);

/**
 * @brief Cấu hình ngắt cho chân GPIO
 * 
 * @param pinConfig    Tên chân GPIO
 * @param irqConfig    Cấu hình ngắt: kiểu ngắt và bật/tắt bộ lọc nhiễu
 */
void phDriverGpio_SetInterrupt(phDriverGpio_Name_t pinConfig, phDriverGpio_IrqConfig_t irqConfig);

/**
 * @brief Xoá cờ ngắt cho chân GPIO (thường gọi trong ISR)
 * 
 * @param pinConfig    Tên chân GPIO
 */
void phDriverGpio_ClearInterrupt(phDriverGpio_Name_t pinConfig);

#ifdef __cplusplus
}
#endif

#endif /* GPIODRV_H_ */
