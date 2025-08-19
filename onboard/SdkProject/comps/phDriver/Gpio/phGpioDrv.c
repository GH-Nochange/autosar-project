#include "phGpioDrv.h"
#include "pins_driver.h"
#include <string.h>


#ifndef PH_GPIO_MAX_HANDLES
#define PH_GPIO_MAX_HANDLES 64u 
#endif

static const phGpio_PinConfig_t *s_table = NULL;
static uint32_t s_count = 0U;

static phGpio_IrqCb_t s_irq_cb[PH_GPIO_MAX_HANDLES];
static void          *s_irq_ctx[PH_GPIO_MAX_HANDLES];


static inline bool ph_is_valid_handle(phGpio_Handle_t h)
{
    return (s_table != NULL) && (h < s_count);
}

static inline pins_channel_type_t ph_bit(uint32_t pin)
{
    return (pins_channel_type_t)(1UL << pin);
}

static phGpio_Handle_t ph_find_handle_by_hw(const PORT_Type *port, uint32_t pin)
{
    if (!s_table) return PH_GPIO_INVALID_HANDLE;
    for (uint32_t i = 0; i < s_count; i++)
    {
        if ((s_table[i].port_base == port) && (s_table[i].pin == pin))
        {
            return (phGpio_Handle_t)i;
        }
    }
    return PH_GPIO_INVALID_HANDLE;
}

static void ph_configure_one_pin_(const phGpio_PinConfig_t *cfg)
{
    PINS_DRV_SetMuxModeSel(cfg->port_base, cfg->pin, cfg->mux);

    PINS_DRV_SetPinDirection(cfg->gpio_base, (pins_channel_type_t)cfg->pin,
                             (pins_level_type_t)(cfg->is_output ? 1U : 0U));

    if (cfg->is_output)
    {
        PINS_DRV_WritePin(cfg->gpio_base, (pins_channel_type_t)cfg->pin,
                          (pins_level_type_t)cfg->init_level);
    }

    PINS_DRV_SetPinIntSel(cfg->port_base, cfg->pin, cfg->irq.int_config);
    if (cfg->irq.digital_filter_enable)
        PINS_DRV_EnableDigitalFilter(cfg->port_base, cfg->pin);
    else
        PINS_DRV_DisableDigitalFilter(cfg->port_base, cfg->pin);
}

static void ph_dispatch_port_isr_(PORT_Type *port)
{
    uint32_t flags = PINS_DRV_GetPortIntFlag(port);
    if (flags == 0U) return;

    while (flags)
    {
        uint32_t pin = __builtin_ctz(flags);     
        flags &= ~(1UL << pin);                 

        phGpio_Handle_t h = ph_find_handle_by_hw(port, pin);
        if (ph_is_valid_handle(h))
        {
            if (h < PH_GPIO_MAX_HANDLES && s_irq_cb[h])
            {
                s_irq_cb[h](h, s_irq_ctx[h]);
            }
        }

        PINS_DRV_ClearPinIntFlagCmd(port, pin);
    }
}


void phGpioDrv_Init(const phGpio_PinConfig_t table[], uint32_t count)
{
    s_table = table;
    s_count = count;

    memset(s_irq_cb, 0, sizeof(s_irq_cb));
    memset(s_irq_ctx, 0, sizeof(s_irq_ctx));

    for (uint32_t i = 0; i < s_count; i++)
    {
        ph_configure_one_pin_(&s_table[i]);

        if (i < PH_GPIO_MAX_HANDLES)
        {
            s_irq_cb[i]  = s_table[i].irq_cb;
            s_irq_ctx[i] = s_table[i].irq_user_param;
        }
    }
}

void phGpioDrv_DeInit(void)
{
    if (!s_table) return;

    for (uint32_t i = 0; i < s_count; i++)
    {
        const phGpio_PinConfig_t *cfg = &s_table[i];

        PINS_DRV_SetPinDirection(cfg->gpio_base, (pins_channel_type_t)cfg->pin, (pins_level_type_t)0U);
        PINS_DRV_DisableDigitalFilter(cfg->port_base, cfg->pin);
        PINS_DRV_SetPinIntSel(cfg->port_base, cfg->pin, PORT_DMA_INT_DISABLED);
        PINS_DRV_ClearPinIntFlagCmd(cfg->port_base, cfg->pin);
    }

    s_table = NULL;
    s_count = 0U;
    memset(s_irq_cb, 0, sizeof(s_irq_cb));
    memset(s_irq_ctx, 0, sizeof(s_irq_ctx));
}

void phGpioDrv_Set(phGpio_Handle_t h, phGpio_Level_t lvl)
{
    if (!ph_is_valid_handle(h)) return;
    const phGpio_PinConfig_t *cfg = &s_table[h];
    PINS_DRV_WritePin(cfg->gpio_base, (pins_channel_type_t)cfg->pin, (pins_level_type_t)lvl);
}

void phGpioDrv_Toggle(phGpio_Handle_t h)
{
    if (!ph_is_valid_handle(h)) return;
    const phGpio_PinConfig_t *cfg = &s_table[h];
    PINS_DRV_TogglePins(cfg->gpio_base, ph_bit(cfg->pin));
}

phGpio_Level_t phGpioDrv_Get(phGpio_Handle_t h)
{
    if (!ph_is_valid_handle(h)) return PH_GPIO_LOW;
    const phGpio_PinConfig_t *cfg = &s_table[h];
    pins_channel_type_t v = PINS_DRV_ReadPins(cfg->gpio_base);
    return ( (v & ph_bit(cfg->pin)) != 0U ) ? PH_GPIO_HIGH : PH_GPIO_LOW;
}

static IRQn_Type ph_port_to_irqn(const PORT_Type *p)
{
    if (p == PORTA) return PORTA_IRQn;
    if (p == PORTB) return PORTB_IRQn;
    if (p == PORTC) return PORTC_IRQn;
    if (p == PORTD) return PORTD_IRQn;
    if (p == PORTE) return PORTE_IRQn;
    return (IRQn_Type)-1;
}

void phGpioDrv_SetInterrupt(phGpio_Handle_t h,
                         phGpio_IrqConfig_t cfg,
                         phGpio_IrqCb_t cb,
                         void *ctx,
                         uint8_t priority)
{
    if (!ph_is_valid_handle(h)) return;

    const phGpio_PinConfig_t *pin = &s_table[h];
    PINS_DRV_ClearPinIntFlagCmd(pin->port_base, pin->pin);
    PINS_DRV_SetPinIntSel(pin->port_base, pin->pin, cfg.int_config);

    if (cfg.digital_filter_enable)
        PINS_DRV_EnableDigitalFilter(pin->port_base, pin->pin);
    else
        PINS_DRV_DisableDigitalFilter(pin->port_base, pin->pin);

    if (h < PH_GPIO_MAX_HANDLES) {
        s_irq_cb[h]  = cb;
        s_irq_ctx[h] = ctx;
    }

    IRQn_Type irqn = ph_port_to_irqn(pin->port_base);
    if ((int)irqn >= 0) {
        S32_NVIC->ICPR[irqn >> 5u] = (1u << (irqn & 31u));
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS 4u
#endif
        uint8_t prio = (priority & ((1u << __NVIC_PRIO_BITS) - 1u));
        S32_NVIC->IP[irqn] = (uint8_t)((prio << (8u - __NVIC_PRIO_BITS)) & 0xFFu);
        S32_NVIC->ISER[irqn >> 5u] = (1u << (irqn & 31u));
    }
}


void phGpioDrv_ClearInterrupt(phGpio_Handle_t h)
{
    if (!ph_is_valid_handle(h)) return;
    const phGpio_PinConfig_t *cfg = &s_table[h];
    PINS_DRV_ClearPinIntFlagCmd(cfg->port_base, cfg->pin);
}

#ifdef PORTA
void PORTA_IRQHandler(void) { ph_dispatch_port_isr_(PORTA); }
#endif
#ifdef PORTB
void PORTB_IRQHandler(void) { ph_dispatch_port_isr_(PORTB); }
#endif
#ifdef PORTC
void PORTC_IRQHandler(void) { ph_dispatch_port_isr_(PORTC); }
#endif
#ifdef PORTD
void PORTD_IRQHandler(void) { ph_dispatch_port_isr_(PORTD); }
#endif
#ifdef PORTE
void PORTE_IRQHandler(void) { ph_dispatch_port_isr_(PORTE); }
#endif
