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
 * @brief Initialize System Oscillator (SOSC) to 8 MHz.
 */
void SOSC_init_8MHz(void);

/**
 * @brief Initialize System PLL (SPLL) with 160 MHz output.
 */
void SPLL_init_160MHz(void);

/**
 * @brief Set Normal RUN mode with core clock 80 MHz.
 */
void NormalRUNmode_80MHz(void);

/**
 * @brief Disable Watchdog (WDOG).
 */
void WDOG_disable(void);

#endif /* PH_CLOCKS_H_ */
