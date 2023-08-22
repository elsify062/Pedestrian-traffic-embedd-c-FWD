
#include "app.h"

#define		CAR_RED_ON			0
#define		CAR_GREEN_ON		1
	
uint16 *ptr;
uint8 my_status;	
volatile uint8 interruptFlag =0;

void main_timerCallBack(void);
void interruptCallBack(void);
void interrupt_timerCallBack(void);
static void select_leds_on_off_off(uint8 led1, uint8 led2, uint8 led3);
static void select_leds_on_tog_off(uint8 led1, uint8 led2, uint8 led3);

void APP_void_int(void)
{
	DIO_voidInit();
	GIE_voidEnable();
	EXT_VoidInit();
	EXITenable(EX_INT0, EX_INT_RISING_EDGE);
	EXIT0SetCallBack(&interruptCallBack);
	TIM0_enuOvfIntControl(ENABLE);
	TIM0_enuSetCallbackOvf(&main_timerCallBack);
	TIM0_voidInit();
}

void APP_void_start(void)
{
	
	if (interruptFlag == 0)
	{
		TIM0_enuSetCallbackOvf(&main_timerCallBack);
	} 
	else
	{
		TIM0_enuSetCallbackOvf(&interrupt_timerCallBack);
	}
	
}


void main_timerCallBack(void)
{
	static uint16 count =0;
	ptr = &count;
	if(count < 153)									//let car cross the road for 5 s
	{
		my_status = CAR_GREEN_ON;					//flag give state during the pressing on the crosswalk
		select_leds_on_off_off(0,1,2);				//for cars
		select_leds_on_off_off(7,6,5);				//for pedestrian
	}
	else if((count>152)&&(count<306))				//planking to change another state for 5s with toggle 
	{
		select_leds_on_tog_off(0,1,2);				 
		select_leds_on_tog_off(7,6,5);				 
	}
	else if((count>305)&&(count<459))               //let car stop for 5s  
	{
		my_status = CAR_RED_ON;
		select_leds_on_off_off(2,1,0);			
		select_leds_on_off_off(5,6,7);
	}
	else if((count>458)&&(count<612))				//back to :	let car cross the road for 5 s
	{
		my_status = CAR_GREEN_ON;
		select_leds_on_tog_off(2,1,0);
		select_leds_on_tog_off(5,6,7);
	}
	else
	{
		count=0;
	}
	count++;
}

void interrupt_timerCallBack(void)
{
	static uint16 count =0;
	if (my_status == CAR_RED_ON)
	{
		if(count<153)
		{
			select_leds_on_off_off(2,1,0);
			select_leds_on_off_off(5,6,7);
		}
		else if((count>152)&&(count<306))
		{
			select_leds_on_tog_off(5,1,2);
			select_leds_on_tog_off(5,6,7);
		}
		else if((count>305)&&(count<459))
		{
			select_leds_on_off_off(0,1,2);			
			select_leds_on_off_off(7,6,5);
		}
		else{interruptFlag=0;count=0;*ptr=153;}	
	} 
	else if(my_status == CAR_GREEN_ON)
	{
		if (count<153)
		{
			select_leds_on_tog_off(0,1,2);
			select_leds_on_tog_off(7,6,5);
		} 
		else if((count>152)&&(count<306))
		{
			select_leds_on_off_off(2,1,0);
			select_leds_on_off_off(5,6,7);
		}
		else if((count>305)&&(count<459))
		{
			select_leds_on_tog_off(5,1,2);
			select_leds_on_tog_off(5,6,7);
		}
		else if((count>458)&&(count<612))
		{
			select_leds_on_off_off(0,1,2);			
			select_leds_on_off_off(7,6,5);
		}
		else{interruptFlag=0;count=0;*ptr=153;}
	}
	count++;
}


void interruptCallBack(void)
{
	interruptFlag = 1;
}

static void select_leds_on_off_off(uint8 led1, uint8 led2, uint8 led3)
{
	
	ledOn(led1);
	ledOff(led2);
	ledOff(led3);
}
static void select_leds_on_tog_off(uint8 led1, uint8 led2, uint8 led3)
{
	static uint8 count=0;
	ledOn(led1);
	if ((count>13)&&(count<16)){ledToggle(led2);} 
	else if(count>15){count=0;}
	ledOff(led3);
	count++;
}