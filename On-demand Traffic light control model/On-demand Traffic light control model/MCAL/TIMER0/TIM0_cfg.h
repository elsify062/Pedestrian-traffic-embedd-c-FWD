#ifndef   TIM0_CFG_H
#define   TIM0_CFG_H

/* TIMER_STOPED      NO_PRESCALER       PRESCALER_8       PRESCALER_64       
PRESCALER_256     PRESCALER_1024     TIM0_EXTCLK_FALLING	TIM0_EXTCLK_RISING */
#define TIM0_PPRESCALLER     PRESCALER_1024

/* NORMAL		PWM_PHASE		CTC		FAST_PWM */
#define TIM0_MODE		     NORMAL

#endif



											/*** Important Calculations***/ 
/*
----------------------------------------------------------------------------------------------
NO_PRESCALER		|		One tick time = 0.125  us		|		Overflow time = 32      us
PRESCALER_8			|		One tick time = 1      us		|		Overflow time = 256     us
PRESCALER_64		|		One tick time = 8      us		|		Overflow time = 2.048   ms
PRESCALER_256		|		One tick time = 32     us		|		Overflow time = 8.192   ms
PRESCALER_1024		|		One tick time = 128    us		|		Overflow time = 32.768  ms
----------------------------------------------------------------------------------------------
*/