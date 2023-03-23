/***************************************************************************//**
 * @file
 * @brief Capacitive touch example for EFM32ZG-STK3200
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "em_device.h"
#include "em_adc.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

#include "display.h"
#include "textdisplay.h"
#include "retargettextdisplay.h"
#include "em_timer.h"
#include "menu.h"
#include "capsense_touchh3.h"
#include "bspconfig.h"
#include "bsp.h"

#include "Problema3.h"
#include "Problema2.h"
#include "Problema1.h"

#define CAPSENSE_UPDATE_PERIOD  5
static volatile uint32_t msTicks; /* counts 1ms timeTicks */
static int capsenseUpdateCount = 0;
/***************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter
 ******************************************************************************/
void SysTick_Handler(void)
{
  msTicks++;
  if (++capsenseUpdateCount == CAPSENSE_UPDATE_PERIOD) {
      capsenseUpdateCount = 0;

      /* Update capsense module */
      CAPSENSE_timerEventHandler();
    }
  /* increment counter necessary in Delay()*/
}
/***************************************************************************//**
 * @brief Delays number of msTick Systicks (typically 1 ms)
 * @param dlyTicks Number of ticks to delay
 ******************************************************************************/
static void Delay(uint32_t dlyTicks)
{
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks) ;
}
/***************************************************************************//**
 * @brief  Main function
 ******************************************************************************/
int main(void)
{
  /* Chip errata */
  CHIP_Init();
  /* Setup SysTick timer for 1 msec interrupts  */
  if (SysTick_Config(SystemCoreClockGet() / 1000)) {
    while (1) ;
  }
  /* Initialize the display module. */
  DISPLAY_Init();
  /* Initialize Capacitive sensors*/
  CAPSENSE_Init();
  /* Initialize Leds*/
  BSP_LedsInit();
  /* Retarget stdio to the display. */
  RETARGET_TextDisplayInit();
  /* Initialize Clocks*/
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_TIMER0, true);
  /* Setting button pins*/
  GPIO_PinModeSet(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN , gpioModeInput,  0);
  GPIO_PinModeSet(BSP_GPIO_PB1_PORT,BSP_GPIO_PB1_PIN , gpioModeInput,  0);
  /* Setting Led pin for intensity control of it */
  GPIO_PinModeSet(LED_PORT, LED_PIN, gpioModePushPull, 0);
  /* Initialize Menu state */
  Menu_Init();
  while (1) {
	  Menu();
	  Delay(10);
  }
}
