#ifndef PH_GPIODRV_H_
#define PH_GPIODRV_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pins_driver.h"
#include "device_registers.h"

/**
 * @brief Logical GPIO handle (index into config table).
 */
typedef uint8_t phGpio_Handle_t;
#define PH_GPIO_INVALID_HANDLE ((phGpio_Handle_t)0xFF)

/**
 * @brief Logical pin level.
 */
typedef enum {
    PH_GPIO_LOW  = 0U,
    PH_GPIO_HIGH = 1U
} phGpio_Level_t;

/**
 * @brief Optional interrupt callback with user context.
 */
typedef void (*phGpio_IrqCb_t)(phGpio_Handle_t handle, void *user_param);

/**
 * @brief Per-pin interrupt options.
 */
typedef struct
{
    port_interrupt_config_t int_config;  /* rising/falling/both/level */
    bool digital_filter_enable;
} phGpio_IrqConfig_t;

/**
 * @brief One GPIO configuration entry.
 * @note  Filled by application, no hard-coded board pins here.
 */
typedef struct
{
    GPIO_Type *gpio_base;         /* GPIO base address */
    PORT_Type *port_base;         /* PORT base address */
    uint32_t   pin;               /* Pin number */
    port_mux_t  mux;               /* Mux mode */
    bool       is_output;         /* Direction at init */
    phGpio_Level_t init_level;    /* Initial level if output */
    phGpio_IrqConfig_t irq;       /* IRQ settings */
    phGpio_IrqCb_t irq_cb;        /* Optional ISR callback */
    void *irq_user_param;         /* Context for callback */
} phGpio_PinConfig_t;

/**
 * @brief Initialize GPIO driver with a config table.
 * @param table  Config table (array).
 * @param count  Number of entries.
 */
void phGpioDrv_Init(const phGpio_PinConfig_t table[], uint32_t count);

/**
 * @brief Deinitialize all configured GPIOs (safe state).
 */
void phGpioDrv_DeInit(void);

/**
 * @brief Set pin output level.
 */
void phGpioDrv_Set(phGpio_Handle_t h, phGpio_Level_t lvl);

/**
 * @brief Toggle pin output level.
 */
void phGpioDrv_Toggle(phGpio_Handle_t h);

/**
 * @brief Read current pin level.
 */
phGpio_Level_t phGpioDrv_Get(phGpio_Handle_t h);

/**
 * @brief Reconfigure interrupt for a pin.
 */
void phGpioDrv_SetInterrupt(phGpio_Handle_t h,
                         phGpio_IrqConfig_t cfg,
                         phGpio_IrqCb_t cb,
                         void *ctx,
                         uint8_t priority);

/**
 * @brief Clear interrupt flag for a pin (call inside ISR).
 */
void phGpioDrv_ClearInterrupt(phGpio_Handle_t h);

#ifdef __cplusplus
}
#endif

#endif /* PH_GPIODRV_H_ */
