#ifndef EXIT_INT_H
#define EXIT_INT_H

#define EX_INT0   0
#define EX_INT1   1
#define EX_INT2   2

#define EX_INT_RISING_EDGE         0
#define EX_INT_FALLING_EDGE        1
#define EX_INT_ANY_LOGICAL_CHANGE  2
#define EX_INT_LOW_LEVEL           3


void EXT_VoidInit(void);
tenuErrorStatus EXITenable(uint8 u8EXITindex,uint8 u8EdgeIndex);
tenuErrorStatus EXITdisable(uint8 u8EXITindex);
tenuErrorStatus EXIT0SetCallBack(pf EXT0PtrFunc);
tenuErrorStatus EXIT1SetCallBack(pf EXT1PtrFunc);
tenuErrorStatus EXIT2SetCallBack(pf EXT2PtrFunc);


#endif