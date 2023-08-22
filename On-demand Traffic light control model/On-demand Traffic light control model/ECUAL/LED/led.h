

#ifndef FAN_H_
#define FAN_H_

#include "../../Utilities/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/registers.h"

void ledOn(uint8 num);
void ledOff(uint8 num);
void ledToggle(uint8 num);

#endif /* FAN_H_ */