#ifndef PH_GPIO_H
#define PH_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "phGpioDrv.h"
#include "device_registers.h"
#include "pins_driver.h"

typedef enum
{
    PH_LED_COLOR_R = 0,
    PH_LED_COLOR_G,
    PH_LED_COLOR_B,
    PH_LED_COLOR_Y,   /* R+G */
    PH_LED_COLOR_M,   /* R+B */
    PH_LED_COLOR_C,   /* G+B */
    PH_LED_COLOR_W,   /* R+G+B */
    PH_LED_COLOR_OFF,
} phLed_Color_t;

typedef struct
{
    phGpio_Handle_t led_r;
    phGpio_Handle_t led_g;
    phGpio_Handle_t led_b;
    phGpio_Handle_t btn_sw2;
    phGpio_Handle_t btn_sw3;
} phGpioHwAb_Handles_t;

void phGpioHwAb_Init(void);
const phGpioHwAb_Handles_t* phGpioHwAb_GetHandles(void);

void phGpio_LedOff(void);
void phGpio_LedSetRGB(bool r_on, bool g_on, bool b_on);      
void phGpio_LedSetColor(phLed_Color_t c);
void phGpio_LedSetColorIndex(uint8_t idx7);                   
void phGpio_LedNext7(void);

bool phGpio_ButtonSw2Pressed(void);                         
bool phGpio_ButtonSw3Pressed(void);

#ifdef __cplusplus
}
#endif

#endif /* PH_GPIO_H */
