#ifndef   TIM0_INT_H
#define   TIM0_INT_H

#include "../../Utilities/STD_Types.h"
#include "../../Utilities/BIT_Math.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"


								/************************************************************************/
								/*							Drivers' Functions		                    */
								/************************************************************************/
																

void  TIM0_voidInit(void);
void  TIM0_voidWF_Of_OC0(uint8 u8WfModeValueCpy);								/*the Output Compare pin (OC0) behavior*/
void  TIM0_voidStartTimeValue(uint8 u8TimerValueCpy);							/* setting the beginning value of timer to overflow */
void  TIM0_voidCompareValue_non_PWM(uint8 u8CompValueCpy);						/* setting the compare match value */
void  TIM0_voidPWM_Generator( uint8 u8dutyCycleCopy );							/* in this func send the duty cycle persentage without % ex; 50 */
void  TIM0_voidDoing_CTC_OutputNow(void);										/* Forcing timer to do OC0 functionality now without clearing the comparing value or entering an interrupt, Only in (CTC OR NORMAL) mode */
tenuErrorStatus  TIM0_enuOvfIntControl(uint8 interruptStatus);					/* Write (ENABLE OR DISABLE) */
tenuErrorStatus  TIM0_enuCmpIntControl(uint8 interruptStatus);					/* Write (ENABLE OR DISABLE) */
void  TIM0_enuSetCallbackOvf(pf pfCpy);											/* Send an address of function taking void and return void */ 
void  TIM0_enuSetCallbackCmp(pf pfCpy);											/* Send an address of function taking void and return void */
uint8 TIM0_u8GetTimeValue(void);												/* Reading the current counter value */
void  TIM0_Stop (void);															/* Disable the timer */


								/************************************************************************/
								/*			    For changing timer mode in run time                     */
								/************************************************************************/					
#define NORMAL					     0
#define CTC						     1
#define PWM_PHASE				     2
#define FAST_PWM					 3
void  TIM0_voidChange_timer_mode_now(uint8 timer0Mode);




								/************************************************************************/
								/*			 Hardware actions on OC0 pin and Hardware PWM generator     */
								/*				The input of {TIM0_voidWF_Of_OC0} function				*/                   
								/************************************************************************/


#define TIM0_WF_TOGGLE_PIN         0					/*Toggle OC0 on compare match*/
#define TIM0_WF_CLR_PIN            1					/*Clear OC0 on compare match*/
#define TIM0_WF_SET_PIN            2					/*Set OC0 on compare match*/
#define TIM0_WF_SET_CMP_CLR_TOP    3					/*Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
#define TIM0_WF_CLR_CMP_SET_TOP    4					/*Clear OC0 on compare match, set OC0 at BOTTOM,(nin-inverting mode)*/
#define TIM0_WF_SET_UPC_CLR_DNC    5					/*Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.*/
#define TIM0_WF_SET_DNC_CLR_UPC    6					/*Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.*/
#define TIM0_WF_OFF                7					/*Normal port operation, OC0 disconnected(Work as DIO)*/



#endif

																/* Testing Code */
																
/*
void Call_ya_3am(void);
void ledOn(uint8_t num);
void ledOff(uint8_t num);
void ledToggle(uint8_t num);


int main (void)
{
	uint8 x;
	uint16 y;
	DIO_voidInit();
	GIE_voidEnable();
	TIM0_enuOvfIntControl(ENABLE);
	TIM0_enuSetCallbackOvf(&Call_ya_3am);
	TIM0_voidInit();
	TIM0_voidWF_Of_OC0(TIM0_WF_TOGGLE_PIN);	
	TIM0_voidCompareValue_non_PWM(235);       /* toggle every 30 ms (output of OC0)*/
	/*
	while(1)
	{


	}
	return 0;
}



void ledToggle(uint8_t num)
{
	if (DIO_enutogglePin(num) != E_OK)
	{
		return;
	}
	else
	{
		
	}
}




void ledOff(uint8_t num)
{
	if (DIO_enuWritePin(num,0) != E_OK)
	{
		return;
	}
	else
	{
		
	}
}

void ledOn(uint8_t num)
{
	if (DIO_enuWritePin(num,1) != E_OK)
	{
		return;
	}
	else
	{
		
	}
}

void Call_ya_3am(void)
{
	static uint16 count =0;
	if(count < 153)
	{
		ledOn(1);
		ledOff(2);
		ledOff(3);
	} 
	else if((count>152)&&(count<214))
	{
		ledOn(2);
		ledOff(1);
		ledOff(3);
	}
	else if((count>213)&&(count<366))
	{
		ledOn(3);
		ledOff(1);
		ledOff(2);
	}
	else
	{
		count=0;
	}
	count++;
	
}

*/														