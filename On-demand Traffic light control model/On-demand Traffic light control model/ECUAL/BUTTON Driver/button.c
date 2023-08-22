


#include "button.h"



buttonErrors BUTTON_read(uint8 buttonpin, uint8 *value)
{
	
	buttonErrors returnedError;
	if (DIO_enuReadPin( buttonpin , value) != E_OK)
	{
		returnedError = BUTTON_ERROR;
	}
	else
	{
		returnedError = BUTTON_OK;
	}
	
	return returnedError;

}





														/************************************************************************/
														/*				test modules for the driver's APIs                      */
														/************************************************************************/

/*
#define F_CPU	8000000UL
#include <util/delay.h>
int main(void)
{
	uint8 value;
	DIO_voidInit();
	while(1)
	{
		BUTTON_read(2, &value);
		if(value==HIGH)
		{
			ledOn(1);
		}
		else 
		{
			ledOff(1);
		}
	}
}
*/