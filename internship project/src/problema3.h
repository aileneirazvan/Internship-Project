/*
 * problema3.h
 *
 *  Created on: Aug 12, 2021
 *      Author: Internship
 */

#ifndef SRC_PROBLEMA3_H_
#define SRC_PROBLEMA3_H_

#include <stdlib.h>
#include <stdio.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_leuart.h"
#include "em_dma.h"
#include "dmactrl.h"

#include "em_adc.h"
#include "em_gpio.h"
#include "display.h"
#include "capsense_touchh3.h"
#include "textdisplay.h"
#include "capsenseconfig_spaceinvaders.h"
#include "retargettextdisplay.h"
#include "../emlib/em_timer.h"

/** DMA Configurations            */
#define DMA_CHANNEL       0          /* DMA channel is 0 */

#define TIMER_TOP3				30
#define TIMER_CHANNEL			1
#define NUMBER_OF_LEDS			16
#define NUMBER_OF_BITS			24
#define stare_pb0 GPIO_PinInGet(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN)
#define MAX_LED 16
#define NUM_TRANSFER      (NUMBER_OF_BITS*MAX_LED)+50       /* Number of transfers per DMA cycle */
/** DMA callback structure */
 DMA_CB_TypeDef dmaCallBack;

void setupDma(void);
void basicTransferComplete(unsigned int channel, bool primary, void *user);
void setupLeuart(void);
void Problema3();
void Set_LED (int LEDnum, int Red, int Green, int Blue);
void Set_Colors();
void problema3_print();
#endif /* SRC_PROBLEMA3_H_ */
