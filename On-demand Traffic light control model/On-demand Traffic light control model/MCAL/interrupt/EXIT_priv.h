#ifndef EXIT_PRIV_H
#define EXIT_PRIV_H


#define MCUCSR	*((volatile uint8 *) 0x54)
#define GICR	*((volatile uint8 *) 0x5B)
#define MCUCR	*((volatile uint8 *) 0x55)
#define GIFR	*((volatile uint8 *) 0x5A)
#endif