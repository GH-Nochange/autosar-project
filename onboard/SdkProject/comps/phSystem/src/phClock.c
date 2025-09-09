#include "phClock.h"
#include "clock.h"

// ============================================================================
// Peripheral Clock Configuration (instance 0)
// ============================================================================
peripheral_clock_config_t peripheralClockConfig0[NUM_OF_PERIPHERAL_CLOCKS_0] = {
    {.clockName = ADC0_CLK, .clkGate = true, .clkSrc = CLK_SRC_SIRC_DIV2, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = ADC1_CLK, .clkGate = true, .clkSrc = CLK_SRC_SIRC_DIV2, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = DMAMUX0_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FTFC0_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FTM0_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FTM1_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FTM2_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FTM3_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = LPSPI0_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV2, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = LPSPI1_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV2, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = LPSPI2_CLK, .clkGate = true, .clkSrc = CLK_SRC_FIRC_DIV2, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = PORTA_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = PORTB_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = PORTC_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = PORTD_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = PORTE_CLK, .clkGate = true, .clkSrc = CLK_SRC_OFF, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FlexCAN0_CLK, .clkGate = true, .clkSrc = CLK_SRC_SOSC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
    {.clockName = FlexCAN1_CLK, .clkGate = true, .clkSrc = CLK_SRC_SOSC_DIV1, .frac = MULTIPLY_BY_ONE, .divider = DIVIDE_BY_ONE},
};

// ============================================================================
// Clock Manager User Configuration (instance 0)
// ============================================================================
clock_manager_user_config_t clockMan1_InitConfig0 = {
    .scgConfig = {
        .sircConfig = {
            .initialize = true,
            .enableInStop = false,
            .enableInLowPower = true,
            .locked = false,
            .range = SCG_SIRC_RANGE_HIGH,
            .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,
            .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,
        },
        .fircConfig = {
            .initialize = true,
            .regulator = true,
            .locked = false,
            .range = SCG_FIRC_RANGE_48M,
            .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,
            .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,
        },
        .rtcConfig = {
            .initialize = true,
            .rtcClkInFreq = 0U,
        },
        .soscConfig = {
            .initialize = true,
            .freq = 8000000U,
            .monitorMode = SCG_SOSC_MONITOR_DISABLE,
            .locked = false,
            .extRef = SCG_SOSC_REF_OSC,
            .gain = SCG_SOSC_GAIN_LOW,
            .range = SCG_SOSC_RANGE_MID,
            .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,
            .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,
        },
        .spllConfig = {
            .initialize = true,
            .monitorMode = SCG_SPLL_MONITOR_DISABLE,
            .locked = false,
            .prediv = (uint8_t)SCG_SPLL_CLOCK_PREDIV_BY_1,
            .mult = (uint8_t)SCG_SPLL_CLOCK_MULTIPLY_BY_28,
            .src = 0U,
            .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,
            .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,
        },
        .clockOutConfig = {
            .initialize = true,
            .source = SCG_CLOCKOUT_SRC_FIRC,
        },
        .clockModeConfig = {
            .initialize = true,
            .rccrConfig = {
                .src = SCG_SYSTEM_CLOCK_SRC_FIRC,
                .divCore = SCG_SYSTEM_CLOCK_DIV_BY_1,
                .divBus = SCG_SYSTEM_CLOCK_DIV_BY_2,
                .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_2,
            },
            .vccrConfig = {
                .src = SCG_SYSTEM_CLOCK_SRC_SIRC,
                .divCore = SCG_SYSTEM_CLOCK_DIV_BY_2,
                .divBus = SCG_SYSTEM_CLOCK_DIV_BY_1,
                .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_4,
            },
            .hccrConfig = {
                .src = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,
                .divCore = SCG_SYSTEM_CLOCK_DIV_BY_1,
                .divBus = SCG_SYSTEM_CLOCK_DIV_BY_2,
                .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_4,
            },
        },
    },
    .pccConfig = {
        .peripheralClocks = peripheralClockConfig0,
        .count = NUM_OF_PERIPHERAL_CLOCKS_0,
    },
    .simConfig = {
        .clockOutConfig = {
            .initialize = true,
            .enable = false,
            .source = SIM_CLKOUT_SEL_SYSTEM_SCG_CLKOUT,
            .divider = SIM_CLKOUT_DIV_BY_1,
        },
        .lpoClockConfig = {
            .initialize = true,
            .enableLpo1k = true,
            .enableLpo32k = true,
            .sourceLpoClk = SIM_LPO_CLK_SEL_LPO_128K,
            .sourceRtcClk = SIM_RTCCLK_SEL_SOSCDIV1_CLK,
        },
        .platGateConfig = {
            .initialize = true,
            .enableMscm = true,
            .enableMpu = true,
            .enableDma = true,
            .enableErm = true,
            .enableEim = true,
        },
        .qspiRefClkGating = {
            .enableQspiRefClk = false,
        },
        .tclkConfig = {
            .initialize = true,
            .tclkFreq[0] = 0U,
            .tclkFreq[1] = 0U,
            .tclkFreq[2] = 0U,
        },
        .traceClockConfig = {
            .initialize = true,
            .divEnable = true,
            .source = CLOCK_TRACE_SRC_CORE_CLK,
            .divider = 0U,
            .divFraction = false,
        },
    },
    .pmcConfig = {
        .lpoClockConfig = {
            .initialize = true,
            .enable = true,
            .trimValue = 0,
        },
    },
};

// ============================================================================
// Global configuration arrays
// ============================================================================
clock_manager_user_config_t const *g_clockManConfigsArr[] = {
    &clockMan1_InitConfig0};

clock_manager_callback_user_config_t *g_clockManCallbacksArr[] = {
    (void *)0};

void phClockInit(void)
{
  CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
}
