/*
 * problema1.h
 *
 *  Created on: Aug 5, 2021
 *      Author: Internship
 */
#include <stdlib.h>
#include <stdio.h>
#include "em_device.h"
#include <stdint.h>
#include "em_chip.h"
#include "em_cmu.h"
#include "bsp.h"

#include "em_adc.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "display.h"
#include "capsense_touchh3.h"
#include "textdisplay.h"
#include "capsenseconfig_spaceinvaders.h"
#include "retargettextdisplay.h"
#include "../emlib/em_timer.h"
#include "bspconfig.h"

#ifndef SRC_PROBLEMA1_H_
#define SRC_PROBLEMA1_H_

#define DEBOUNCE_TIME 30
#define long_press 70
#define short_press 50
#define stare_pb0 GPIO_PinInGet(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN)
#define stare_pb1 GPIO_PinInGet(BSP_GPIO_PB1_PORT,BSP_GPIO_PB1_PIN)

bool pressed_btn0, pressed_btn1, past_button0_state, past_button1_state, problema1_show,live_button0_state, live_button1_state;
int count_btn0, count_btn1, blink_led0_count, blink_led1_count, count_time, blink_state0_show, blink_state1_show, blink_state0, blink_state1;

void Problema1();
void problema1_print();
void debounce_pb0();
void debounce_pb1();

#endif /* SRC_PROBLEMA1_H_ */
