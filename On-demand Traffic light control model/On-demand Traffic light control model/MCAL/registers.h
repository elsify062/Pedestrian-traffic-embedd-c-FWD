#ifndef REGISTERS_H
#define REGISTERS_H
#include "GIE/GIE_int.h"
#include "interrupt/EXIT_int.h"
#include "TIMER0/TIM0_int.h"

//PORTA Registers
#define PORTA *((volatile uint8 *) 0X3B)
#define DDRA *((volatile uint8 *) 0X3A)
#define PINA *((volatile uint8 *) 0X39)

//PORTB Registers
#define PORTB *((volatile uint8 *) 0X38)
#define DDRB *((volatile uint8 *) 0X37)
#define PINB *((volatile uint8 *) 0X36)

//PORTC Registers
#define PORTC *((volatile uint8 *) 0X35)
#define DDRC *((volatile uint8 *) 0X34)
#define PINC *((volatile uint8 *) 0X33)

//PORTD Registers
#define PORTD *((volatile uint8 *) 0X32)
#define DDRD *((volatile uint8 *) 0X31)
#define PIND *((volatile uint8 *) 0X30)




#define ADMUX 				 *((volatile uint8 *) 0x27 )
#define ADCSRA 				 *((volatile uint8 *) 0x26 )
#define SFIOR 			     *((volatile uint8 *) 0x50 )
#define ADCH   				 *((volatile uint8 *) 0x25 )
#define ADCL  			     *((volatile uint8 *) 0x24 )

/* Casting for reg ADCL to read 10 bits in right and left adjust without shifting ..*/
#define ADCL_READ_10_BITS    *((volatile uint16 *) 0x24 )



#endif