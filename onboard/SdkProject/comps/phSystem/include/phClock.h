#ifndef PH_CLOCKS_H_
#define PH_CLOCKS_H_
/**
 * @file phClocks.h
 * @brief Basic clock and watchdog configuration APIs for S32K1xx.
 *
 * Provides functions to configure oscillator, PLL, run mode,
 * and disable watchdog.
 */

/**
 * @brief Initialize system clocks for S32K144:
 *        - Disable WDOG
 *        - Enable SOSC @ 8 MHz (external XTAL)
 *        - Configure SPLL = 160 MHz
 *        - Switch to Normal RUN: Core=80MHz, Bus=40MHz, Flash≈26.7MHz
 */
void system_clock_init(void);

#endif /* PH_CLOCKS_H_ */
