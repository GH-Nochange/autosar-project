#include "GpioDrv.h"

// Cấu hình phần cứng từng GPIO
#define LED_R_GPIO   PTD
#define LED_G_GPIO   PTD
#define LED_B_GPIO   PTD

#define LED_R_PORT   PORTD
#define LED_G_PORT   PORTD
#define LED_B_PORT   PORTD

#define LED_R_PIN    (0U)
#define LED_G_PIN    (15U)
#define LED_B_PIN    (16U)

#define LED_MASK     ((1UL << LED_R_PIN) | (1UL << LED_G_PIN) | (1UL << LED_B_PIN))

// Cấu hình pin đầu ra ban đầu
static const pin_settings_config_t g_boardPins[] = {
    {
        .base = LED_R_PORT, .pinPortIdx = LED_R_PIN,
        .mux = PORT_MUX_AS_GPIO, .gpioBase = LED_R_GPIO,
        .direction = GPIO_OUTPUT_DIRECTION, .initValue = 1U,
        .intConfig = PORT_DMA_INT_DISABLED, .digitalFilter = false
    },
    {
        .base = LED_G_PORT, .pinPortIdx = LED_G_PIN,
        .mux = PORT_MUX_AS_GPIO, .gpioBase = LED_G_GPIO,
        .direction = GPIO_OUTPUT_DIRECTION, .initValue = 1U,
        .intConfig = PORT_DMA_INT_DISABLED, .digitalFilter = false
    },
    {
        .base = LED_B_PORT, .pinPortIdx = LED_B_PIN,
        .mux = PORT_MUX_AS_GPIO, .gpioBase = LED_B_GPIO,
        .direction = GPIO_OUTPUT_DIRECTION, .initValue = 1U,
        .intConfig = PORT_DMA_INT_DISABLED, .digitalFilter = false
    }
};

static const uint32_t g_boardPinsCount = sizeof(g_boardPins) / sizeof(g_boardPins[0]);

static phDriverGpio_Callback_t g_gpioCallbacks[PH_GPIO_NUM] = { 0 };

void phDriverGpio_Init(void)
{
    PINS_DRV_Init(g_boardPinsCount, g_boardPins);

    for (phDriverGpio_Name_t i = 0; i < g_boardPinsCount; i++) {
        const pin_settings_config_t *cfg = &g_boardPins[i];
        PINS_DRV_SetPins(cfg->gpioBase, 1U << cfg->pinPortIdx);
    }
}

void phDriverGpio_DeInitPin(phDriverGpio_Name_t pinConfig)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];

        PINS_DRV_SetPins(cfg->gpioBase, 1U << cfg->pinPortIdx);

        PINS_DRV_SetPinDirection(cfg->gpioBase, cfg->pinPortIdx, GPIO_INPUT_DIRECTION);

#ifdef FEATURE_PINS_DRIVER_USING_PORT
        PINS_DRV_SetMuxModeSel(cfg->base, cfg->pinPortIdx, PORT_PIN_DISABLED);
#endif
    }
}

void phDriverGpio_DeInit(void)
{
    for (phDriverGpio_Name_t i = 0; i < g_boardPinsCount; i++) {
        phDriverGpio_DeInitPin(i);
    }
}


void phDriverGpio_SetPinLevel(phDriverGpio_Name_t pinConfig, phDriverGpio_PinLevel_t pinLevel)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];
        if (pinLevel == PH_GPIO_LOW)
            PINS_DRV_ClearPins(cfg->gpioBase, 1U << cfg->pinPortIdx);
        else
            PINS_DRV_SetPins(cfg->gpioBase, 1U << cfg->pinPortIdx);
    }
}

void phDriverGpio_TogglePin(phDriverGpio_Name_t pinConfig)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];
        PINS_DRV_TogglePins(cfg->gpioBase, 1U << cfg->pinPortIdx);
    }
}

phDriverGpio_PinLevel_t phDriverGpio_GetPinLevel(phDriverGpio_Name_t pinConfig)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];
        uint32_t pinState = PINS_DRV_ReadPins(cfg->gpioBase);
        uint32_t pinMask = 1U << cfg->pinPortIdx;

        return (pinState & pinMask) ? PH_GPIO_HIGH : PH_GPIO_LOW;
    }

    return PH_GPIO_LOW;
}

void phDriverGpio_SetInterrupt(phDriverGpio_Name_t pinConfig, phDriverGpio_IrqConfig_t irqConfig)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];

        PINS_DRV_SetPinIntSel(cfg->base, cfg->pinPortIdx, irqConfig.intConfig);

        if (irqConfig.digitalFilterEnable)
        {
#ifdef FEATURE_PORT_HAS_DIGITAL_FILTER
            PINS_DRV_EnableDigitalFilter(cfg->base, 1U << cfg->pinPortIdx);
#endif
        }
         if (cfg->base == PORTA) {
            INT_SYS_EnableIRQ(PORTA_IRQn);
        } else if (cfg->base == PORTB) {
            INT_SYS_EnableIRQ(PORTB_IRQn);
        } else if (cfg->base == PORTC) {
            INT_SYS_EnableIRQ(PORTC_IRQn);
        } else if (cfg->base == PORTD) {
            INT_SYS_EnableIRQ(PORTD_IRQn);
        } else if (cfg->base == PORTE) {
            INT_SYS_EnableIRQ(PORTE_IRQn);
        }
    }
}

void phDriverGpio_ClearInterrupt(phDriverGpio_Name_t pinConfig)
{
    if (pinConfig < g_boardPinsCount)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pinConfig];
        PINS_DRV_ClearPinIntFlagCmd(cfg->base, cfg->pinPortIdx);
    }
}

void phDriverGpio_RegisterCallback(phDriverGpio_Name_t pinConfig, phDriverGpio_Callback_t callbackFunc)
{
    if (pinConfig < g_boardPinsCount)
    {
        g_gpioCallbacks[pinConfig] = callbackFunc;
    }
}

static void phDriverGpio_CommonIRQHandler(PORT_Type *port)
{
    uint32_t flags = PINS_DRV_GetPortIntFlag(port);

    for (phDriverGpio_Name_t pin = 0; pin < g_boardPinsCount; pin++)
    {
        const pin_settings_config_t *cfg = &g_boardPins[pin];

        // So khớp PORT
        if (cfg->base == port && ((flags >> cfg->pinPortIdx) & 1U))
        {
            PINS_DRV_ClearPinIntFlagCmd(cfg->base, cfg->pinPortIdx);

            if (g_gpioCallbacks[pin])
            {
                g_gpioCallbacks[pin]();  
            }
        }
    }
}

void PORTA_IRQHandler(void)
{
    phDriverGpio_CommonIRQHandler(PORTA);
}

void PORTB_IRQHandler(void)
{
    phDriverGpio_CommonIRQHandler(PORTB);
}

void PORTC_IRQHandler(void)
{
    phDriverGpio_CommonIRQHandler(PORTC);
}

void PORTD_IRQHandler(void)
{
    phDriverGpio_CommonIRQHandler(PORTD);
}

void PORTE_IRQHandler(void)
{
    phDriverGpio_CommonIRQHandler(PORTE);
} 