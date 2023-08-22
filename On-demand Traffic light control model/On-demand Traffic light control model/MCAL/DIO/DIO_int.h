
#ifndef  DIO_INT_H
#define  DIO_INT_H
#include "../../Utilities/STD_Types.h"
#include "../../Utilities/BIT_Math.h"

void DIO_voidInit(void);

tenuErrorStatus DIO_enuWritePin(uint8  u8PinNumCpy ,uint8 u8PinValueCpy);

tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8 * pu8PinValueCpy);

tenuErrorStatus DIO_enuActivatePullUp(uint8 u8PinNumCpy, uint8 u8PinStateCpy);

tenuErrorStatus DIO_enutogglePin(uint8 u8PinNumCpy );


#endif 



















