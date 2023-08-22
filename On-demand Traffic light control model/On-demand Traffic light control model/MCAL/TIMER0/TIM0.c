
#include "TIM0_int.h"

uint8 u8WfModeValueGlobalCpy;
pf TIM0_pfOvfFun ;
pf TIM0_pfCmpFun ;
void TIM0_voidInit(void)
{
	TCCR0 &= 0b11111000;
	TCCR0 |= TIM0_PPRESCALLER;
	TIM0_voidTIMER_mode();
}
static void TIM0_voidTIMER_mode(void)
{
	switch(TIM0_MODE)
	{
		case NORMAL:
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;
		
		case CTC:
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		break;
		
		case PWM_PHASE:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
		
		case FAST_PWM:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
		
	}
	
}

void TIM0_voidWF_Of_OC0(uint8 u8WfModeValueCpy)
{
	u8WfModeValueGlobalCpy = u8WfModeValueCpy;
	switch(u8WfModeValueCpy)
	{
		case TIM0_WF_TOGGLE_PIN      : 
		SET_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
		break ; 
		case TIM0_WF_CLR_PIN         :  
		SET_BIT(TCCR0 ,5);
		CLR_BIT(TCCR0 ,4);
		break ;
		case TIM0_WF_SET_PIN         : 
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_CMP_CLR_TOP :
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_CLR_CMP_SET_TOP : 
		CLR_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_UPC_CLR_DNC :
		SET_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_SET_DNC_CLR_UPC : 
		CLR_BIT(TCCR0 ,4);
		SET_BIT(TCCR0 ,5);
		break ;
		case TIM0_WF_OFF             : 
        CLR_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
		break ;
		default :
		/* No waveform generated*/
		CLR_BIT(TCCR0 ,4);
		CLR_BIT(TCCR0 ,5);
	
		
	}
}

void  TIM0_Stop (void)
{
	CLR_BIT(TCCR0 ,0);
	CLR_BIT(TCCR0 ,1);
	CLR_BIT(TCCR0 ,2);
}

void  TIM0_voidStartTimeValue(uint8 u8TimerValueCpy)
{
	TCNT0 = u8TimerValueCpy;
}

void  TIM0_voidCompareValue_non_PWM(uint8 u8CompValueCpy)
{
	if((TIM0_MODE == NORMAL) || (TIM0_MODE == CTC)){OCR0 = u8CompValueCpy;}	
}

uint8 TIM0_u8GetTimeValue( void)
{
	return TCNT0;
}

void TIM0_voidPWM_Generator( uint8 u8dutyCycleCopy )
{
	uint8 OCR_Value;
	if(TIM0_MODE == FAST_PWM)
	{
		if(u8WfModeValueGlobalCpy == TIM0_WF_SET_CMP_CLR_TOP)
		{
			OCR_Value = 256-((u8dutyCycleCopy/100.0f)*256);
			OCR0 = OCR_Value;
		}
		else
		{
			OCR_Value = ((u8dutyCycleCopy/100.0f)*256);
			OCR0 = OCR_Value;
		}
		
	}
	else if(TIM0_MODE == PWM_PHASE)
	{
		if(u8WfModeValueGlobalCpy == TIM0_WF_SET_UPC_CLR_DNC)
		{
			OCR_Value = 510-((u8dutyCycleCopy/100.0f)*510);
			OCR0 = (OCR_Value/2);
		}
		else
		{
			OCR_Value =((u8dutyCycleCopy/100.0f)*510);
			OCR0 = (OCR_Value/2);
		}
	}
	
}

void  TIM0_voidDoing_CTC_Output_Now(void)
{
	TCCR0 |= 0b10000000;
}

tenuErrorStatus  TIM0_enuOvfIntControl(uint8 interruptStatus)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	if(interruptStatus<2)
	{
		if(interruptStatus==ENABLE)
		{
			SET_BIT(TIMSK,0);
		}
		else
		{
			CLR_BIT(TIMSK,0);
		}
	}
	
	else 
	{
		enuReturnStatusLoc=E_NOK_PARAM_OUT_OF_RANGE;
	}

	return enuReturnStatusLoc;
}

tenuErrorStatus TIM0_enuCmpIntControl(uint8 interruptStatus)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	if(interruptStatus<2)
	{
		if(interruptStatus==ENABLE)
		{
			SET_BIT(TIMSK,1);
		}
		else
		{
			CLR_BIT(TIMSK,1);
		}
	}
	
	else 
	{
		enuReturnStatusLoc=E_NOK_PARAM_OUT_OF_RANGE;
	}

	return enuReturnStatusLoc;
}

void TIM0_enuSetCallbackOvf(pf pfCpy)
{

		TIM0_pfOvfFun = pfCpy;
}


void TIM0_enuSetCallbackCmp(pf pfCpy)
{
		TIM0_pfCmpFun = pfCpy;

}

void __vector_10 (void) __attribute__ ((signal ,used));
void __vector_10 (void)
{
	TIM0_pfCmpFun();
}

/*OVF interrupt*/
void __vector_11 (void) __attribute__ ((signal ,used));
void __vector_11 (void)
{
	TIM0_pfOvfFun();
}


void TIM0_voidChange_timer_mode_now(uint8 timer0Mode)
{
	switch(timer0Mode)
	{
		case NORMAL:
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;
		
		case CTC:
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		break;
		
		case PWM_PHASE:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
		
		case FAST_PWM:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
		
	}
	TCCR0 &= 0b11111000;
	TCCR0 |= TIM0_PPRESCALLER;
}

