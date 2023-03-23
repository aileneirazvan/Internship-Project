/*
 * menu.h
 *
 *  Created on: Aug 10, 2021
 *      Author: Internship
 */
#include <stdio.h>
#include <stdlib.h>

#include "em_device.h"
#include "em_adc.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bspconfig.h"
#include "bsp.h"

#include "capsense.h"
#include "display.h"
#include "textdisplay.h"
#include "retargettextdisplay.h"
#include "em_timer.h"

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#define NR_OPTIUNI 3
#define SPACE 8
#define MOVE_CURSOR6 for(int i=0;i<SPACE-2;i++) printf(TEXTDISPLAY_ESC_SEQ_CURSOR_RIGHT_ONE_CHAR)
#define MOVE_CURSOR8 for(int i=0;i<SPACE;i++) printf(TEXTDISPLAY_ESC_SEQ_CURSOR_RIGHT_ONE_CHAR)
int arrow;
typedef enum _menuState{
menuShow,
menuSelect,
problema1,
problema2,
problema3
} MenuState;
volatile MenuState state;
void Menu();
void MenuSelection();
void Menu_Init();
#endif /* SRC_MENU_H_ */
