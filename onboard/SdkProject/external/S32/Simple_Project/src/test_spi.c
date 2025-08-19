/*
 * test_spi.c
 * 2025-08-17
 * S32K144 LPSPI1 (SPI1) Slave - Mode 0, 8-bit, re-arm in main loop
 * Pins (PORTB ALT3):
 *   PTB14 = LPSPI1_SCK
 *   PTB15 = LPSPI1_SIN  (MOSI -> Slave)
 *   PTB16 = LPSPI1_SOUT (MISO <- Slave)
 *   PTB17 = LPSPI1_PCS3 (CS)
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "device_registers.h"
#include "lpspi_slave_driver.h"
#include "phSpiDrv.h"

#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS 4u
#endif

/* ---- Config ---- */
#define BUF_SZ              16u

/* ---- LPSPI1 select ---- */
#define LPSPIx_IDX          1
#define LPSPIx_IRQn         LPSPI1_IRQn
#define LPSPIx_BASE         LPSPI1
#define PCC_LPSPIx_INDEX    PCC_LPSPI1_INDEX

/* ---- SPI1 pins on PORTB ALT3 ---- */
#define LPSPIx_SCK_PCR      PORTB->PCR[14]  /* PTB14 */
#define LPSPIx_SIN_PCR      PORTB->PCR[15]  /* PTB15 */
#define LPSPIx_SOUT_PCR     PORTB->PCR[16]  /* PTB16 */
#define LPSPIx_PCS3_PCR     PORTB->PCR[17]  /* PTB17 */

/* ---- LED ---- */
#define LED_PORT            PORTD
#define LED_GPIO            PTD
#define LED_GREEN_PIN       16u  /* xanh: nháy trong callback (active-low) */
#define LED_RED_PIN         15u  /* đỏ: báo CS và lỗi (active-low) */

static uint8_t g_tx[BUF_SZ];
static uint8_t g_rx[BUF_SZ];

/* Debug */
static volatile bool     g_cbDone     = false;
static volatile bool     g_need_rearm = false;
static volatile uint32_t g_frame      = 0;
static volatile uint32_t g_last_sr    = 0;

/* CS/SCK monitor */
static volatile bool     g_cs_low     = false;
static volatile uint32_t g_sck_edges  = 0;

static inline void NVIC_EnableIRQ_(IRQn_Type irqn, uint8_t prio)
{
    S32_NVIC->ICPR[irqn >> 5u] = (1u << (irqn & 31u));
    S32_NVIC->IP[irqn]         = (uint8_t)((prio << (8u - __NVIC_PRIO_BITS)) & 0xFFu);
    S32_NVIC->ISER[irqn >> 5u] = (1u << (irqn & 31u));
}

static inline void Led_Init(void)
{
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;
    LED_PORT->PCR[LED_GREEN_PIN] = PORT_PCR_MUX(1);
    LED_PORT->PCR[LED_RED_PIN]   = PORT_PCR_MUX(1);
    LED_GPIO->PDDR |= (1u<<LED_GREEN_PIN) | (1u<<LED_RED_PIN);
    LED_GPIO->PSOR  = (1u<<LED_GREEN_PIN) | (1u<<LED_RED_PIN); /* OFF */
}
static inline void LedG_On(void){  LED_GPIO->PCOR = (1u<<LED_GREEN_PIN); }
static inline void LedG_Off(void){ LED_GPIO->PSOR = (1u<<LED_GREEN_PIN); }
static inline void LedG_Tgl(void){ LED_GPIO->PTOR = (1u<<LED_GREEN_PIN); }
static inline void LedR_On(void){  LED_GPIO->PCOR = (1u<<LED_RED_PIN); }
static inline void LedR_Off(void){ LED_GPIO->PSOR = (1u<<LED_RED_PIN); }

/* Clock: PORTB + LPSPI1 from SPLL_DIV2 */
static inline void Clk_Init_SPI1(void)
{
    /* pin mux clocks */
    PCC->PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK;
    /* LPSPI1 functional clock: PCS=6 (SPLL2_DIV2), enable */
    PCC->PCCn[PCC_LPSPIx_INDEX] = PCC_PCCn_PCS(6) | PCC_PCCn_CGC_MASK;
}

/* Pin mux ALT3 + drive/pull */
static inline void Mux_PortB_LPSPI1_ALT3(void)
{
    LPSPIx_SCK_PCR  = (LPSPIx_SCK_PCR  & ~PORT_PCR_MUX_MASK)  | PORT_PCR_MUX(3);
    LPSPIx_SIN_PCR  = (LPSPIx_SIN_PCR  & ~PORT_PCR_MUX_MASK)  | PORT_PCR_MUX(3) | PORT_PCR_PE_MASK;
    LPSPIx_SOUT_PCR = (LPSPIx_SOUT_PCR & ~PORT_PCR_MUX_MASK)  | PORT_PCR_MUX(3) | PORT_PCR_DSE_MASK;
    LPSPIx_PCS3_PCR = (LPSPIx_PCS3_PCR & ~PORT_PCR_MUX_MASK)  | PORT_PCR_MUX(3);
}

/* CS/SCK monitor: PTB17 (PCS3) both edges, PTB14 (SCK) rising */
static inline void cs_sck_monitor_init(void)
{
    LPSPIx_PCS3_PCR = (LPSPIx_PCS3_PCR & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(3);
    LPSPIx_SCK_PCR  = (LPSPIx_SCK_PCR  & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(3);

    /* add IRQ configs */
    LPSPIx_PCS3_PCR |= PORT_PCR_IRQC(0b1011);  /* both edges */
    LPSPIx_SCK_PCR  |= PORT_PCR_IRQC(0b1001);  /* rising edge */

    PORTB->ISFR = (1u<<17) | (1u<<14);
    NVIC_EnableIRQ_(PORTB_IRQn, 1);
}

/* ISR PORTB: LED đỏ theo CS, đếm xung SCK khi CS=LOW */
void PORTB_IRQHandler(void)
{
    uint32_t isfr = PORTB->ISFR;

    if (isfr & (1u<<17)) { /* CS edge */
        g_cs_low = ((PTB->PDIR & (1u<<17)) == 0);
        if (g_cs_low) {
            g_sck_edges = 0;
            LedR_On();
        } else {
            LedR_Off();
            /* Nếu đủ 128 xung mà callback không nháy, ta sẽ thấy xanh không đổi */
        }
    }
    if (isfr & (1u<<14)) { /* SCK rising */
        if (g_cs_low) g_sck_edges++;
    }

    PORTB->ISFR = isfr; /* clear flags */
}

/* TX pattern: A0..AF, B0..BF,... */
static void refill_tx(void)
{
    uint8_t base = (uint8_t)(0xA0 + ((g_frame & 0x0F) << 4));
    for (uint32_t i=0; i<BUF_SZ; i++) g_tx[i] = (uint8_t)(base + i);
}

/* LPSPI slave callback: nháy LED xanh khi hoàn tất 1 frame */
static void slave_cb(void *param)
{
    (void)param;
    g_last_sr = LPSPIx_BASE->SR;
    g_frame++;
    g_cbDone     = true;
    g_need_rearm = true;
    LedG_Tgl(); /* DEBUG: đã complete 16 byte */
}

int spi_test(void)
{
    system_clock_init();  /* SOSC 8MHz → SPLL 160MHz → RUN Core 80/Bus 40 */
    Led_Init();
    Clk_Init_SPI1();
    Mux_PortB_LPSPI1_ALT3();
    cs_sck_monitor_init();

    /* Ưu tiên ngắt cao cho LPSPI1 */
    NVIC_EnableIRQ_(LPSPIx_IRQn, 0);

    lpspi_slave_config_t cfg;
    LPSPI_DRV_SlaveGetDefaultConfig(&cfg);
    cfg.bitcount     = 8;
    cfg.clkPhase     = LPSPI_CLOCK_PHASE_1ST_EDGE;   /* CPHA=0 */
    cfg.clkPolarity  = LPSPI_SCK_ACTIVE_HIGH;        /* CPOL=0 → Mode 0 */
    cfg.lsbFirst     = false;
    cfg.whichPcs     = LPSPI_PCS3;                   /* *** PCS3 cho PTB17 *** */
    cfg.pcsPolarity  = LPSPI_ACTIVE_LOW;
    cfg.transferType = LPSPI_USING_INTERRUPTS;
    cfg.rxDMAChannel = 0xFF;
    cfg.txDMAChannel = 0xFF;
    cfg.callback     = slave_cb;
    cfg.callbackParam= NULL;

    PhTypes_ErrorCode_t er_init = LpspiSlave_Init(LPSPIx_IDX, &cfg);
    if (er_init != 0) { LedR_On(); /* báo lỗi init */ for(;;){} }

    /* ARM lần đầu trước khi master clock */
    g_frame = 0;
    refill_tx();
    memset(g_rx, 0, sizeof(g_rx));
    PhTypes_ErrorCode_t er0 = LpspiSlave_Transfer(LPSPIx_IDX, g_tx, g_rx, BUF_SZ);
    if (er0 != 0) { LedR_On(); LedG_On(); /* arm fail */ for(;;){} }

    for (;;)
    {
        if (g_cbDone) {
            g_cbDone = false;
            /* TODO: xử lý g_rx nếu cần */
        }

        if (g_need_rearm) {
            g_need_rearm = false;
            refill_tx();
            memset(g_rx, 0, sizeof(g_rx));
            PhTypes_ErrorCode_t er = LpspiSlave_Transfer(LPSPIx_IDX, g_tx, g_rx, BUF_SZ);
            if (er != 0) {
                g_need_rearm = true; /* thử lại vòng sau */
            }
        }

        __asm("nop");
    }
}
