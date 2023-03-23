/*
 * problema2.h
 *
 *  Created on: Aug 6, 2021
 *      Author: Internship
 */
#include <stdlib.h>
#include <stdio.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_adc.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "display.h"
#include "capsense_touchh3.h"
#include "textdisplay.h"
#include "capsenseconfig_spaceinvaders.h"
#include "retargettextdisplay.h"
#include "../emlib/em_timer.h"

#ifndef SRC_PROBLEMA2_H_
#define SRC_PROBLEMA2_H_

#define LED_PORT	gpioPortA
#define LED_PIN		1			// PIN PA1
#define stare_cap0	CAPSENSE_getPressed(BUTTON0_CHANNEL)
#define stare_cap1	CAPSENSE_getPressed(BUTTON1_CHANNEL)

#define TIMER_TOP				100
#define TIMER_CHANNEL			1
#define MAX_INTENSITY           100
#define MIN_INTENSITY			0

bool live_cap0_state, live_cap1_state ,past_cap0_state ,past_cap1_state,problema2_state, problema2_show;
int intensity, i_step;

void Problema2();
void Init_timer();
void problema2_print();

#endif /* SRC_PROBLEMA2_H_ */
