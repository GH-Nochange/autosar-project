#include "phGpio.h"
#include "device_registers.h"
#include "pins_driver.h"
#include <string.h>

typedef enum
{
    H_LED_R = 0,
    H_LED_G,
    H_LED_B,
    H_BTN_SW2,
    H_BTN_SW3,
    H_COUNT
} hw_handles_e;

static phGpioHwAb_Handles_t s_handles;
static uint8_t s_colorIdx7;

void sw2_irq_handler(void *param);
void sw3_irq_handler(void *param);

static const phGpio_PinConfig_t s_pins[H_COUNT] =
{
    {   /* LED R = PTD15 (active-low) */
        .port_base = PORTD,
        .gpio_base = PTD,
        .pin = 15u,
        .mux = PORT_MUX_AS_GPIO,
        .is_output = true,
        .init_level = PH_GPIO_HIGH,
        .irq = { .int_config = PORT_DMA_INT_DISABLED, .digital_filter_enable = false },
        .irq_cb = NULL,
        .irq_user_param = NULL,
    },
    {   /* LED G = PTD16 (active-low) */
        .port_base = PORTD,
        .gpio_base = PTD,
        .pin = 16u,
        .mux = PORT_MUX_AS_GPIO,
        .is_output = true,
        .init_level = PH_GPIO_HIGH,
        .irq = { .int_config = PORT_DMA_INT_DISABLED, .digital_filter_enable = false },
        .irq_cb = NULL,
        .irq_user_param = NULL,
    },
    {   /* LED B = PTD0 (active-low) */
        .port_base = PORTD,
        .gpio_base = PTD,
        .pin = 0u,
        .mux = PORT_MUX_AS_GPIO,
        .is_output = true,
        .init_level = PH_GPIO_HIGH,
        .irq = { .int_config = PORT_DMA_INT_DISABLED, .digital_filter_enable = false },
        .irq_cb = NULL,
        .irq_user_param = NULL,
    },
    {   /* SW2 = PTC12 (active-low) */
        .port_base = PORTC,
        .gpio_base = PTC,
        .pin = 12u,
        .mux = PORT_MUX_AS_GPIO,
        .is_output = false,
        .init_level = PH_GPIO_LOW,
        .irq = { .int_config = PORT_DMA_INT_DISABLED, .digital_filter_enable = true },
        .irq_cb = NULL, 
        .irq_user_param = NULL,
    },
    {   /* SW3 = PTC13 (active-low) */
        .port_base = PORTC,
        .gpio_base = PTC,
        .pin = 13u,
        .mux = PORT_MUX_AS_GPIO,
        .is_output = false,
        .init_level = PH_GPIO_LOW,
        .irq = { .int_config = PORT_DMA_INT_DISABLED, .digital_filter_enable = true },
        .irq_cb = NULL, 
        .irq_user_param = NULL,
    },
};

void phGpio_Init(void)
{
    phGpio_Init(s_pins, (uint32_t)H_COUNT);
    s_handles.led_r   = (phGpio_Handle_t)H_LED_R;
    s_handles.led_g   = (phGpio_Handle_t)H_LED_G;
    s_handles.led_b   = (phGpio_Handle_t)H_LED_B;
    s_handles.btn_sw2 = (phGpio_Handle_t)H_BTN_SW2;
    s_handles.btn_sw3 = (phGpio_Handle_t)H_BTN_SW3;
    s_colorIdx7 = 0u;

    phGpio_IrqConfig_t sw2_irq_config = {
        .int_config = PORT_INT_FALLING_EDGE,
        .digital_filter_enable = true
    };
    phGpio_SetInterrupt(s_handles.btn_sw2, sw2_irq_config, sw2_irq_handler, NULL, 3u); 

    phGpio_IrqConfig_t sw3_irq_config = {
        .int_config = PORT_INT_FALLING_EDGE,
        .digital_filter_enable = true
    };
    phGpio_SetInterrupt(s_handles.btn_sw3, sw3_irq_config, sw3_irq_handler, NULL, 3u); 
}

const phGpioHwAb_Handles_t* phGpioHwAb_GetHandles(void)
{
    return &s_handles;
}

static inline void led_apply(bool r, bool g, bool b)
{
    phGpio_Set(s_handles.led_r, r ? PH_GPIO_LOW : PH_GPIO_HIGH);
    phGpio_Set(s_handles.led_g, g ? PH_GPIO_LOW : PH_GPIO_HIGH);
    phGpio_Set(s_handles.led_b, b ? PH_GPIO_LOW : PH_GPIO_HIGH);
}

void phGpio_LedOff(void)
{
    led_apply(false, false, false);
}

void phGpio_LedSetRGB(bool r_on, bool g_on, bool b_on)
{
    led_apply(r_on, g_on, b_on);
}

void phGpio_LedSetColor(phLed_Color_t c)
{
    switch (c)
    {
        case PH_LED_COLOR_R: led_apply(true, false, false); break;
        case PH_LED_COLOR_G: led_apply(false, true, false); break;
        case PH_LED_COLOR_B: led_apply(false, false, true); break;
        case PH_LED_COLOR_Y: led_apply(true, true, false); break;
        case PH_LED_COLOR_M: led_apply(true, false, true); break;
        case PH_LED_COLOR_C: led_apply(false, true, true); break;
        case PH_LED_COLOR_W: led_apply(true, true, true); break;
        default:             led_apply(false, false, false); break;
    }
}

void phGpio_LedSetColorIndex(uint8_t idx7)
{
    static const phLed_Color_t map[7] = {
        PH_LED_COLOR_R, PH_LED_COLOR_G, PH_LED_COLOR_B,
        PH_LED_COLOR_Y, PH_LED_COLOR_M, PH_LED_COLOR_C, PH_LED_COLOR_W
    };
    phGpio_LedSetColor(map[idx7 % 7u]);
    s_colorIdx7 = (uint8_t)(idx7 % 7u);
}

void phGpio_LedNext7(void)
{
    s_colorIdx7 = (uint8_t)((s_colorIdx7 + 1u) % 7u);
    phGpio_LedSetColorIndex(s_colorIdx7);
}

static inline bool btn_pressed(phGpio_Handle_t h)
{
    return phGpio_Get(h) == PH_GPIO_LOW;
}

bool phGpio_ButtonSw2Pressed(void)
{
    return btn_pressed(s_handles.btn_sw2);
}

bool phGpio_ButtonSw3Pressed(void)
{
    return btn_pressed(s_handles.btn_sw3);
}

void sw2_irq_handler(void *param)
{
    s_colorIdx7 = (s_colorIdx7 + 1) % 7; 
    phGpio_LedSetColorIndex(s_colorIdx7);  
}

void sw3_irq_handler(void *param)
{
    s_colorIdx7 = (s_colorIdx7 - 1 + 7) % 7;  
    phGpio_LedSetColorIndex(s_colorIdx7);  
}
