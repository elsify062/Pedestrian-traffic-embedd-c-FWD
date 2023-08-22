#include "../../Utilities/STD_Types.h"
#include "../../Utilities/BIT_Math.h"

#include "EXIT_int.h"
#include "EXIT_cfg.h"
#include "EXIT_priv.h"
pf EXT0CallBack;
pf EXT1CallBack;
pf EXT2CallBack;
void EXT_VoidInit(void)
{
		/* clear event flag for interrupt 0 */
		SET_BIT(GIFR , 6);
		/*Disable int0*/
		CLR_BIT(GICR , 6) ;
		/* clear event flag for interrupt 1 */
		SET_BIT(GIFR , 7);
		/*Disable int1*/
		CLR_BIT(GICR , 7) ;
		/* clear event flag for interrupt 2 */
		SET_BIT(GIFR , 5);
		/*Disable int2*/
		CLR_BIT(GICR , 5) ;
		
	
}
tenuErrorStatus EXITenable(uint8 u8EXITindex,uint8 u8EdgeIndex)
	{
	  tenuErrorStatus ErrorStatusReturnLoc=E_OK;
	
	  switch(u8EXITindex)
	  {
		case EX_INT0:
		
			switch(u8EdgeIndex)
			{
				case EX_INT_LOW_LEVEL:
				CLR_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
				SET_BIT(GICR,6); //Enable EX_INT0
				break;
				case EX_INT_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
				SET_BIT(GICR,6); //Enable EX_INT0
				break;
				case EX_INT_FALLING_EDGE:
				CLR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
				SET_BIT(GICR,6); //Enable EX_INT0
				break;
				case EX_INT_RISING_EDGE :
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
				SET_BIT(GICR,6); //Enable EX_INT0
				break;
				default:ErrorStatusReturnLoc=E_NOK;
			}
		break;
		case EX_INT1:
			switch(u8EdgeIndex)
			{
				case EX_INT_LOW_LEVEL:
				CLR_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
				SET_BIT(GICR,7); //Enable EX_INT1
				break;
				case EX_INT_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,2);
				CLR_BIT(MCUCR,3);
				SET_BIT(GICR,7); //Enable EX_INT1
				break;
				case EX_INT_FALLING_EDGE:
				CLR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
				SET_BIT(GICR,7); //Enable EX_INT1
				break;
				case EX_INT_RISING_EDGE :
				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
				SET_BIT(GICR,7); //Enable EX_INT1
				break;
				default:ErrorStatusReturnLoc=E_NOK;	
				
			}
		break;
		case EX_INT2:
			switch(u8EdgeIndex)
			{
				case EX_INT_FALLING_EDGE:
				CLR_BIT(MCUCSR,6);
				SET_BIT(GICR,5); //enable EXIT2
				break;
				case EX_INT_RISING_EDGE:
				SET_BIT(MCUCSR,6);//enable EXIT2
				break;
				default:ErrorStatusReturnLoc=E_NOK;	
			}
		break;
		default :ErrorStatusReturnLoc=E_NOK_PARAM_OUT_OF_RANGE;
		
	  }
	return ErrorStatusReturnLoc;
}

tenuErrorStatus EXITdisable(uint8 u8EXITindex)
{
	tenuErrorStatus ErrorStatusReturnLoc=E_OK;
	switch(u8EXITindex)
	{
		case EX_INT0:
		CLR_BIT(GICR,6);
		break;
		case EX_INT1:
		CLR_BIT(GICR,7);
		break;
		case EX_INT2:
		CLR_BIT(MCUCSR,6);
		break;
		default: ErrorStatusReturnLoc = E_NOK_PARAM_OUT_OF_RANGE;
		
	}
	return ErrorStatusReturnLoc;
}
tenuErrorStatus EXIT0SetCallBack(pf EXT0PtrFunc)
{
	tenuErrorStatus ErrorStatusReturnLoc=E_OK;
	if (EXT0PtrFunc==NULL_PTR)
	{
		ErrorStatusReturnLoc =E_NOK_PARAM_NULL_POINTER;
	}
	else
	{
		EXT0CallBack = 	EXT0PtrFunc;
	}
	return ErrorStatusReturnLoc ;
}
void __vector_1 (void) __attribute__((signal ,used));
void __vector_1 (void)
{
	EXT0CallBack();
}


tenuErrorStatus EXIT1SetCallBack(pf EXT1PtrFunc)
{
		tenuErrorStatus ErrorStatusReturnLoc=E_OK;
		if (EXT1PtrFunc==NULL_PTR)
		{
			ErrorStatusReturnLoc =E_NOK_PARAM_NULL_POINTER;
		}
		else
		{
			EXT1CallBack = 	EXT1PtrFunc;
		}
		return ErrorStatusReturnLoc ;
}
void __vector_2 (void) __attribute__((signal ,used));
void __vector_2 (void)
{
	EXT1CallBack();
}

tenuErrorStatus EXIT2SetCallBack(pf EXT2PtrFunc)
{
		tenuErrorStatus ErrorStatusReturnLoc=E_OK;
		if (EXT2PtrFunc==NULL_PTR)
		{
			ErrorStatusReturnLoc =E_NOK_PARAM_NULL_POINTER;
		}
		else
		{
			EXT2CallBack = 	EXT2PtrFunc;
		}
		return ErrorStatusReturnLoc ;
}
void __vector_3 (void) __attribute__((signal ,used));
void __vector_3 (void)
{
	EXT2CallBack();
}