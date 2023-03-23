/*
 * problema1.c
 *
 *  Created on: Aug 5, 2021
 *      Author: Internship
 */
#include "problema1.h"
#include "menu.h"
int count_time=0,blink_led1_count=0,blink_led0_count=0,count_btn1=0,count_btn0=0,blink_state0_show=0,blink_state1_show=0,blink_state1=0,blink_state0=0,count_debounce0=0,count_debounce1=0;
bool past_button1_state=1,past_button0_state=1,pressed_btn1=1,pressed_btn0=1,problema1_show=true;


void debounce_pb0()
{
	live_button0_state=stare_pb0;
	if(	past_button0_state  != live_button0_state)
			{
				count_debounce0++;
				if(count_debounce0 >= DEBOUNCE_TIME)
				{
					count_debounce0 = 0;
				}
				else
				{
					live_button0_state = past_button0_state;
				}
			}
}

void debounce_pb1()
{
	live_button1_state=stare_pb1;
	if(	past_button1_state  != live_button1_state)
			{
				count_debounce1++;
				if(count_debounce1 >= DEBOUNCE_TIME)
				{
					count_debounce1 = 0;
				}
				else
				{
					live_button1_state = past_button1_state;
				}
			}
}

void problema1_print()
{
	printf("\f");
	printf("\n Problema1\n\n Control leds\n with PB0 and PB1\n\n Press PB0+PB1 to go\n back.");
}

void Problema1(){
if(problema1_show==true){
	problema1_print();
	problema1_show=false;
}

live_button0_state=stare_pb0;
live_button1_state=stare_pb1;

	/* Button PB0 pressing(Led toggle) and long press(Led blink 1 second frequency) */
if(live_button0_state==0){
	count_btn0++;
}
else{
	count_btn0=0;
}
if(count_btn0==long_press){
	blink_state0=1;
	blink_state0_show=1;
}
if(blink_state0==1){
	blink_led0_count++;
	if(blink_led0_count>100){
		BSP_LedToggle(0);
		blink_led0_count=0;
	}
}
if(blink_state0_show==1){
		blink_state0_show=0;
	}
if(live_button0_state==0 && past_button0_state==1){
	blink_state0=0;
	count_btn0=0;
	past_button0_state=0;
	pressed_btn0=!pressed_btn0;
	if(!pressed_btn0){
		BSP_LedToggle(0);
	}
	else{
		BSP_LedClear(0);
	}
}
if(live_button0_state == 1){
		past_button0_state = 1;
	}

	/* Button PB1 pressing(Led toggle) and double press(Led blink 2 seconds frequency) */
	if(count_btn1==1){
		count_time++;
	}
	if(count_time>short_press){
		count_btn1=0;
		count_time=0;
	}
	if(count_btn1==2 && count_time<short_press){
		blink_state1=1;
		count_time=0;
		blink_state1_show=1;
		count_btn1=0;
	}
	if(blink_state1==1){
		blink_led1_count++;
		if(blink_led1_count>200){
			BSP_LedToggle(1);
			blink_led1_count=0;
		}
	}
	if(blink_state1_show==1){
		blink_state1_show=0;
	}
	if(live_button1_state==0 && past_button1_state==1){
		blink_state1=0;
		past_button1_state=0;
		pressed_btn1=!pressed_btn1;
		count_btn1++;
		if(!pressed_btn1){
			BSP_LedToggle(1);
		}
		else{
			BSP_LedClear(1);
		}
	}
	if(live_button1_state==1){
		past_button1_state=1;
	}
	/* Go back to the menu */
	if(live_button0_state==0 && live_button1_state==0){
		BSP_LedClear(0);
		BSP_LedClear(1);
		problema1_show=true;
		state=menuShow;
	}
}
