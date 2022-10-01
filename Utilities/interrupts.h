/*
 * interrupts.h
 *
 * Created: 9/29/2022 10:43:10 PM
 *  Author: Ahmed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

// MCUCR register bits we are using
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

// MCUCSR register
#define ISC2 6

// GICR register
#define INT0 6
#define INT2 5


// GIFR register
#define INTF0 6
#define INTF2 5

// SREG register
#define GIE 7

/************************************************************************/
/*							Interrupts	Vectors				     		*/
/************************************************************************/

#define EXT_INT_0		__vector_1
#define TIMER0_COMP		__vector_10
#define TIMER0_OVF		__vector_11

#define EXT_INT_2		__vector_3
#define TIMER_2_COMP	__vector_4
#define TIMER_2_OVF		__vector_5


// interrupt handler
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void) // interrupt service routine(ISR)


// PIN Editing
#define SET_BIT(Register,bit) Register|=(1<<bit)
#define CLR_BIT(Register,bit) Register&=~(1<<bit)
#define GET_BIT(Register,bit) ((Register>>bit)&1)
#define TOGG_BIT(Register,bit) Register^=(1<<bit) 


#endif /* INTERRUPTS_H_ */