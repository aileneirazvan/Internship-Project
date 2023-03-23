/*
 * problema3.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Internship
 */
#include "problema3.h"
#include "problema1.h"
#include "menu.h"

uint16_t buffer[(NUMBER_OF_BITS*NUMBER_OF_LEDS)+50];
int test=0, index=0;
uint16_t color;
uint32_t LED_Data[MAX_LED][3];

 void basicTransferComplete(unsigned int channel, bool primary, void *user)
{
  (void) user; /* Unused parameter */
  /* Refresh DMA basic transaction cycle */
  DMA_ActivateBasic(channel,
                    primary,
                    false,
                    (void *)&TIMER0->CC[1].CCVB,
                    (void *)buffer,
                    (NUM_TRANSFER - 1));
}

void setupDma(void)
{
  /* DMA configuration structs */
  DMA_Init_TypeDef       dmaInit;
  DMA_CfgChannel_TypeDef channelCfg;
  DMA_CfgDescr_TypeDef   descrCfg;

  /* Initializing the DMA */
  dmaInit.hprot        = 0;
  dmaInit.controlBlock = dmaControlBlock;
  DMA_Init(&dmaInit);

  /* Set the interrupt callback routine */
  dmaCallBack.cbFunc = basicTransferComplete;
  /* Callback doesn't need userpointer */
  dmaCallBack.userPtr = NULL;

  /* Setting up channel */
  channelCfg.highPri   = false; /* Can't use with peripherals */
  channelCfg.enableInt = true;  /* Enabling interrupt to refresh DMA cycle*/

  /* Configure channel 0 */
  /*Setting up DMA transfer trigger request*/
  channelCfg.select = DMAREQ_TIMER0_CC1;
  /* Setting up callback function to refresh descriptors*/
  channelCfg.cb     = &dmaCallBack;
  DMA_CfgChannel(0, &channelCfg);

  /* Setting up channel descriptor */
  /* Destination is LEUART_Tx register and doesn't move */
  descrCfg.dstInc = dmaDataIncNone;

  /* Source is LEUART_RX register and transfers 8 bits each time */
  descrCfg.srcInc = dmaDataInc2;
  descrCfg.size   = dmaDataSize2;

  /* Default setting of DMA arbitration*/
  descrCfg.arbRate = dmaArbitrate1;
  descrCfg.hprot   = 0;

  /* Configure primary descriptor */
  DMA_CfgDescr(DMA_CHANNEL, true, &descrCfg);

  /* Enable Basic Transfer cycle */
  DMA_ActivateBasic(DMA_CHANNEL,
                    true,
                    false,
                    (void *)&TIMER0->CC[1].CCVB,
                    (void *) buffer,
                    (NUM_TRANSFER - 1));
}

void Problema3()
{
	live_button0_state=stare_pb0;
	if(test==0)
	{
		test=1;
		CMU_ClockEnable(cmuClock_HFPER, true);
		// Create the object initializer for LED PWM
		TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
		timerCCInit.mode = timerCCModePWM;
		timerCCInit.cmoa = timerOutputActionToggle;
		// Configure TIMER0 CC channel 1
		TIMER_InitCC(TIMER0, TIMER_CHANNEL, &timerCCInit);
		// Route CC2 to location 1 (PE3) and enable pin for cc2
		TIMER0->ROUTE |= (TIMER_ROUTE_CC1PEN | TIMER_ROUTE_LOCATION_LOC1);
		// Set Top Value
		TIMER_TopSet(TIMER0, TIMER_TOP3);
		// Create a timerInit object, based on the API default
		TIMER_Init_TypeDef timerInit2 = TIMER_INIT_DEFAULT;
		timerInit2.prescale = timerPrescale1;
		TIMER_Init(TIMER0, &timerInit2);
		// Setting the DMA
		setupDma();
	}
	// Setting the leds with color white
	for (int i=0;i<MAX_LED;i++){
			Set_LED(i,255,255,255);
			Set_Colors();
		}
	// Getting back to menu
	if(live_button0_state==0){
		state=menuShow;
	}
}

void Set_LED (int LEDnum, int Green, int Red, int Blue){
	LED_Data[LEDnum][0] = Green;
	LED_Data[LEDnum][1] = Red;
	LED_Data[LEDnum][2] = Blue;
	color = ((LED_Data[LEDnum][0]<<16) | (LED_Data[LEDnum][1]<<8) | (LED_Data[LEDnum][2]));
}

void Set_Colors()
{
	for(int j=23;j>=0;j--)
	{
		if(color & (1<<j))
		{
			buffer[index]=20;
		}
		else
		{
			buffer[index]=5;
		}
		index++;
	}
}


