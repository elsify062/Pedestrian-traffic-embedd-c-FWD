#ifndef   TIM0_PRIV_H
#define   TIM0_PRIV_H

#define TIMER_STOPED				 0
#define NO_PRESCALER				 1
#define PRESCALER_8					 2
#define PRESCALER_64				 3
#define PRESCALER_256				 4
#define PRESCALER_1024				 5
#define TIM0_EXTCLK_FALLING			 6
#define TIM0_EXTCLK_RISING			 7
									 
									 								 
#define NORMAL					     0
#define CTC						     1
#define PWM_PHASE				     2
#define FAST_PWM					 3


#define DISABLE				   	     0
#define ENABLE				   	     1


static void TIM0_voidTIMER_mode(void);

#define TCCR0 *((volatile uint8*)0x53)
#define TCNT0 *((volatile uint8*)0x52)
#define OCR0  *((volatile uint8*)0x5c)
#define TIMSK *((volatile uint8*)0x59)

#endif
