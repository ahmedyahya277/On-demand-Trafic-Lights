/*
 * registers.h
 *
 * Created: 9/29/2022 10:40:08 PM
 *  Author: Ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

/************************************************************************/
/*							  DIO Registers                             */
/************************************************************************/

// PORTA Registers
#define PORTA *((volatile uint8_t*)0x3B) // 8 bit register
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

// PORTB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

/************************************************************************/
/*							  Timer Registers                           */
/************************************************************************/

#define TIFR   *((volatile uint8_t*)0x58)

// Timer 0 Registers
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)

// Timer 2 Registers
#define TCCR2  *((volatile uint8_t*)0x45)
#define TCNT2  *((volatile uint8_t*)0x44)


/************************************************************************/
/*						  Interrupt Registers                           */
/************************************************************************/

#define SREG	*((volatile uint8_t*)0x5F)
#define MCUCR	*((volatile uint8_t*)0x55)
#define MCUCSR	*((volatile uint8_t*)0x54)
#define GICR	*((volatile uint8_t*)0x5B)
#define GIFR	*((volatile uint8_t*)0x5A)
#define TIMSK	*((volatile uint8_t*)0x59)


#endif /* REGISTERS_H_ */