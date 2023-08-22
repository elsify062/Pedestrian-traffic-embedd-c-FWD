

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO_int.h"

/*Button state..*/
#define LOW 0
#define HIGH 1


/*user expected errors*/
typedef enum ButtonErrors
{
	BUTTON_ERROR,BUTTON_OK
}buttonErrors;


/*reading button state*/
buttonErrors BUTTON_read(uint8 buttonpin, uint8 *value);


#endif 