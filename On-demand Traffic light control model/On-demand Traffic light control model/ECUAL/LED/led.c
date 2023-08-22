
#include "led.h"



void ledToggle(uint8 num)
{
	
	if (DIO_enutogglePin(num) != E_OK)
	{
		return;
	}
	else
	{
		
	}
}

void ledOff(uint8 num)
{
	if (DIO_enuWritePin(num,0) != E_OK)
	{
		return;
	}
	else
	{
		
	}
		
	
}


													/************************************************************************/
													/*				test modules for the driver's APIs                      */
													/************************************************************************/


/*

#define F_CPU	8000000UL
#include <util/delay.h>
int main()
{
	DIO_voidInit();
	while(1)
	{
	ledOn(1);
	_delay_ms(1000);
	ledOff(1);
	_delay_ms(1000);
	ledToggle(2);

	}
	return 0;
}*/

