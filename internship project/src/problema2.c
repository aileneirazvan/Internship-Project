/*
 * problema2.c
 *
 *  Created on: Aug 6, 2021
 *      Author: Internship
 */

#include "problema2.h"
#include "menu.h"
#include "problema1.h"

int intensity=0, i_step=25;
bool problema2_show=true;

void Init_timer() /* Initialize timer for the pwm control */
{
	// Create the object initializer for LED PWM
	TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
	timerCCInit.mode = timerCCModePWM;
	timerCCInit.cmoa = timerOutputActionToggle;
	// Configure TIMER0 CC channel 1
	TIMER_InitCC(TIMER0, TIMER_CHANNEL, &timerCCInit);
	// Route CC1 to location 1
	TIMER0->ROUTE |= (TIMER_ROUTE_CC1PEN | TIMER_ROUTE_LOCATION_LOC1);
	// Set Top Value
	TIMER_TopSet(TIMER0, TIMER_TOP);
	// Create a timerInit object, based on the API default
	TIMER_Init_TypeDef timerInit2 = TIMER_INIT_DEFAULT;
	timerInit2.prescale = timerPrescale256;
	TIMER_Init(TIMER0, &timerInit2);
	TIMER_CompareBufSet(TIMER0, TIMER_CHANNEL, 0);
}

void problema2_print()
{
	Init_timer();
	printf("\f");
	printf("\n Problema2\n\n Control intensity\n with capacitive\n sensors.\n\n Press PB0+PB1 to go\n back.\n\n\n");
}

void Problema2()
{
	if(problema2_show==true)
	{
		problema2_print();
		problema2_show=false;
	}
	past_cap0_state = live_cap0_state;
	past_cap1_state = live_cap1_state;
	live_cap0_state= stare_cap0;
	live_cap1_state = stare_cap1;
	/*Setting the intensity by using the capacitive sensors */
	if ( live_cap1_state==true && past_cap1_state==false){
		if(intensity<MAX_INTENSITY){
			intensity+=i_step;
		}
		printf("\r  Intensity: %3d", intensity);
	}
	if ( live_cap0_state==true && past_cap0_state==false) {
		if(intensity>MIN_INTENSITY){
			intensity-=i_step;
		}
		printf("\r  Intensity: %3d", intensity);
	}
	switch (intensity){
			case 0:
				TIMER0->CC[1].CCV = intensity;
			break;
			case 25:
				TIMER0->CC[1].CCV = intensity;
			break;
			case 50:
				TIMER0->CC[1].CCV = intensity;
			break;
			case 75:
				TIMER0->CC[1].CCV = intensity;
			break;
			case 100:
				TIMER0->CC[1].CCV = intensity;
			break;
	}
	/* Go back to the menu */
	if(live_button0_state==0 && live_button1_state==0){
		BSP_LedClear(0);
		BSP_LedClear(1);
		TIMER0->CC[1].CCV = 0;
		intensity=0;
		problema2_show=true;
		state=menuShow;
	}
}
