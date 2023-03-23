/*
 * menu.c
 *
 *  Created on: Aug 10, 2021
 *      Author: Internship
 */
#include "menu.h"
#include "problema1.h"
#include "problema2.h"

int arrow=1;

void MenuSelection() /* Function for rendering the main Menu */
{
	if(arrow>NR_OPTIUNI)
	{
		arrow=1;
	}
	printf("\f\n\n");
	printf("Internship AROBS 2021\n\n");
	MOVE_CURSOR8;
	printf("MENU\n\n");
	MOVE_CURSOR6;
	printf("Program 1");
	if(arrow==1)
	{
		printf(" <<");
	}
	printf("\n\n");
	MOVE_CURSOR6;
	printf("Program 2");
	if(arrow==2)
	{
		printf(" <<");
	}
	printf("\n\n");
	MOVE_CURSOR6;
	printf("Program 3");
	if(arrow==3)
	{
	printf(" <<");
	}
	printf("\n\n\n\t PB1- choose\n\t PB0- select");
}

void Menu_Init()
{
	state=menuShow;
}
/* Using the PB0 and PB1 buttons to choose a problem */
void Menu()
{
	live_button0_state=stare_pb0;
	live_button1_state=stare_pb1;
	switch(state)
	{
	case menuShow:
		MenuSelection();
		state=menuSelect;
		break;
	case menuSelect:
		if(live_button1_state==0 && past_button1_state==1)
		{
			past_button1_state=0;
			arrow++;
			state=menuShow;
		}
		if(live_button0_state==0 && arrow==1 && past_button0_state==1)
		{
			past_button0_state=0;
			state=problema1;
		}
		if(live_button0_state==0 && arrow==2 && past_button0_state==1)
				{
					past_button0_state=0;
					state=problema2;
				}
		if(live_button0_state==0 && arrow==3 && past_button0_state==1)
				{
					past_button0_state=0;
					state=problema3;
				}
		if(live_button1_state==1)
			{
				past_button1_state=1;
			}
		if(live_button0_state==1)
			{
				past_button0_state=1;
			}
		break;
	case problema1:
			Problema1();
			break;
	case problema2:
			Problema2();
			break;
	case problema3:
			Problema3();
			break;
	}
}
