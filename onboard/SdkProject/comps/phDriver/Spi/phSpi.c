#include "device_registers.h"
#include "lpspi_slave_driver.h"
#include "pins_driver.h"
#include "phSpiDrv.h"
#include "phTypes.h"
#include "phSpi.h"
#include <stdbool.h>
#include <stdint.h>

/* ---- Instance / IRQ / PCC mapping ---- */
#if (SPI_INSTANCE == 0)
#define LPSPIx_IRQn LPSPI0_IRQn
#define PCC_LPSPIx_IDX PCC_LPSPI0_INDEX
#elif (SPI_INSTANCE == 1)
#define LPSPIx_IRQn LPSPI1_IRQn
#define PCC_LPSPIx_IDX PCC_LPSPI1_INDEX
#elif (SPI_INSTANCE == 2)
#define LPSPIx_IRQn LPSPI2_IRQn
#define PCC_LPSPIx_IDX PCC_LPSPI2_INDEX
#endif

/* ---- PCS mapping theo chân SS ---- */
#if (SPI_SS_PIN == 17)
#define SPI_LPSPI_PCS LPSPI_PCS3
#elif (SPI_SS_PIN == 5)
#define SPI_LPSPI_PCS LPSPI_PCS0
#elif (SPI_SS_PIN == 6)
#define SPI_LPSPI_PCS LPSPI_PCS1
#elif (SPI_SS_PIN == 7)
#define SPI_LPSPI_PCS LPSPI_PCS2
#endif

/* ---- "Slave Ready" pin: PTC7 ---- */
#define SLAVE_READY_PORT PORTC
#define SLAVE_READY_GPIO PTC
#define SLAVE_READY_PIN 7u

static uint8_t s_inited = 0;
static volatile uint16_t s_armed_len = 0;

static inline void spi_pcc_enable_(void)
{
  PCC->PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK;
  PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;
  PCC->PCCn[PCC_LPSPIx_IDX] = PCC_PCCn_PCS(6) | PCC_PCCn_CGC_MASK;
}

static inline void spi_pins_init(void)
{
  static const pin_settings_config_t s_pins_cfg[] = {
      {
          .base = PORTB,
          .pinPortIdx = SPI_SCK_PIN,
          .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
          .passiveFilter = false,
          .driveSelect = PORT_HIGH_DRIVE_STRENGTH,
          .mux = PORT_MUX_ALT3,
          .pinLock = false,
          .intConfig = PORT_DMA_INT_DISABLED,
          .clearIntFlag = true,
          .gpioBase = NULL,
          .direction = GPIO_INPUT_DIRECTION,
          .initValue = 0u,
      },
      {
          .base = PORTB,
          .pinPortIdx = SPI_MOSI_PIN,
          .pullConfig = PORT_INTERNAL_PULL_UP_ENABLED,
          .passiveFilter = false,
          .driveSelect = PORT_HIGH_DRIVE_STRENGTH,
          .mux = PORT_MUX_ALT3,
          .pinLock = false,
          .intConfig = PORT_DMA_INT_DISABLED,
          .clearIntFlag = true,
          .gpioBase = NULL,
          .direction = GPIO_INPUT_DIRECTION,
          .initValue = 0u,
      },
      {
          .base = PORTB,
          .pinPortIdx = SPI_MISO_PIN,
          .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
          .passiveFilter = false,
          .driveSelect = PORT_HIGH_DRIVE_STRENGTH,
          .mux = PORT_MUX_ALT3,
          .pinLock = false,
          .intConfig = PORT_DMA_INT_DISABLED,
          .clearIntFlag = true,
          .gpioBase = NULL,
          .direction = GPIO_INPUT_DIRECTION,
          .initValue = 0u,
      },
      {
          .base = PORTB,
          .pinPortIdx = SPI_SS_PIN,
          .pullConfig = PORT_INTERNAL_PULL_UP_ENABLED,
          .passiveFilter = false,
          .driveSelect = PORT_HIGH_DRIVE_STRENGTH,
          .mux = PORT_MUX_ALT3,
          .pinLock = false,
          .intConfig = PORT_DMA_INT_DISABLED,
          .clearIntFlag = true,
          .gpioBase = NULL,
          .direction = GPIO_INPUT_DIRECTION,
          .initValue = 0u,
      },
      {
          .base = SLAVE_READY_PORT,
          .pinPortIdx = SLAVE_READY_PIN,
          .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
          .passiveFilter = false,
          .driveSelect = PORT_HIGH_DRIVE_STRENGTH,
          .mux = PORT_MUX_AS_GPIO,
          .pinLock = false,
          .intConfig = PORT_DMA_INT_DISABLED,
          .clearIntFlag = true,
          .gpioBase = SLAVE_READY_GPIO,
          .direction = GPIO_OUTPUT_DIRECTION,
          .initValue = 1u,
      },
  };

  PINS_DRV_Init((uint32_t)(sizeof(s_pins_cfg) / sizeof(s_pins_cfg[0])), s_pins_cfg);
}

void phSpi_SlaveInit(phSpi_Callback_t *cb)
{
  if (s_inited)
    return;

  spi_pcc_enable_();
  spi_pins_init();

  S32_NVIC->ICPR[LPSPIx_IRQn >> 5u] = (1u << (LPSPIx_IRQn & 31u));
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS 4u
#endif
  S32_NVIC->IP[LPSPIx_IRQn] = 0x00;
  S32_NVIC->ISER[LPSPIx_IRQn >> 5u] = (1u << (LPSPIx_IRQn & 31u));

  lpspi_slave_config_t cfg;
  LPSPI_DRV_SlaveGetDefaultConfig(&cfg);

  cfg.bitcount = (uint16_t)SPI_TRANSFER_SIZE;
  cfg.clkPolarity = (SPI_CLOCK_POLARITY == 0) ? LPSPI_SCK_ACTIVE_HIGH : LPSPI_SCK_ACTIVE_LOW;
  cfg.clkPhase = (SPI_CLOCK_PHASE == 0) ? LPSPI_CLOCK_PHASE_1ST_EDGE : LPSPI_CLOCK_PHASE_2ND_EDGE;
  cfg.lsbFirst = (SPI_BIT_ORDER != 0);
  cfg.whichPcs = SPI_LPSPI_PCS;
  cfg.pcsPolarity = LPSPI_ACTIVE_LOW;        /* Mặc định active-low */
  cfg.transferType = LPSPI_USING_INTERRUPTS; /* Interrupt mode */
  cfg.rxDMAChannel = 0xFF;
  cfg.txDMAChannel = 0xFF;
  cfg.callback = cb;

  (void)phSpiDrvSlave_Init(SPI_INSTANCE, &cfg);
  s_armed_len = 0;
  s_inited = 1;
}

void phSpi_SlaveDeinit(void)
{
  if (!s_inited)
    return;
  (void)phSpiDrvSlave_Deinit(SPI_INSTANCE);
  s_inited = 0;
}

PhTypes_ErrorCode_t phSpi_SlaveTransfer(uint8_t *tx, uint8_t *rx, uint32_t len)
{
  if (!s_inited || len == 0u || len > 0xFFFFu)
    return (PhTypes_ErrorCode_t)1;
  s_armed_len = (uint16_t)len;
  return phSpiDrvSlave_Transfer(SPI_INSTANCE, tx, rx, (uint16_t)len);
}

PhTypes_ErrorCode_t phSpi_SlaveGetStatus(uint32_t *bytesRemaining)
{
  if (!s_inited || !bytesRemaining)
    return (PhTypes_ErrorCode_t)1;
  uint32_t remain = 0u;
  PhTypes_ErrorCode_t er = LpspiSlave_GetStatus(SPI_INSTANCE, &remain);
  if (er == 0)
    *bytesRemaining = remain;
  return er;
}

void phSpi_SlaveSetReady(void)
{
  PINS_DRV_TogglePins(SLAVE_READY_GPIO, (pins_channel_type_t)(1UL << SLAVE_READY_PIN));
}

bool phSpi_SlaveIsCsHigh(void)
{
  uint32_t mask = (1UL << SPI_SS_PIN);
  return ((PTB->PDIR & mask) != 0u);
}

PhTypes_ErrorCode_t phSpi_SlaveAbort(void)
{
  if (!s_inited)
  {
    return PH_ERR_INVALID_ARG;
  }

  PhTypes_ErrorCode_t er = phSpiDrvSlave_Abort(SPI_INSTANCE);

  if (er == PH_ERR_OK)
  {
    s_armed_len = 0u;
  }

  return er;
}