/*
 * dio.c
 *
 * Created: 9/29/2022 10:50:28 PM
 *  Author: Ahmed
 */ 
#include "dio.h"

void DIO_init(uint8_t pinNumber ,uint8_t portNumber, uint8_t direction)
{
	switch (portNumber)
	{
		case PORT_A:
		if (direction == IN)
		{
			CLR_BIT(DDRA,pinNumber);
			/*DDRA &= ~(1<<pinNumber); // input 0*/
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRA,pinNumber);
			//DDRA |= (1<<pinNumber); // output 1
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_B:
		if (direction == IN)
		{
			CLR_BIT(DDRB,pinNumber);
			//DDRB &= ~(1<<pinNumber); // input 0
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRB,pinNumber);
			//DDRB |= (1<<pinNumber); // output 1
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_C:
		if (direction == IN)
		{
			CLR_BIT(DDRC,pinNumber);
			//DDRC &= ~(1<<pinNumber); // input 0
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRC,pinNumber);
			//DDRC |= (1<<pinNumber); // output 1
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_D:
		if (direction == IN)
		{
			CLR_BIT(DDRD,pinNumber);
			//DDRD &= ~(1<<pinNumber); // input 0
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRD,pinNumber);
			//DDRD |= (1<<pinNumber); // output 1
		}
		else
		{
			// Error handling
		}
		break;
	}
}

void DIO_write(uint8_t pinNumber ,uint8_t portNumber, uint8_t value)
{
	switch (portNumber)
	{
		case PORT_A:
		if (value == LOW)
		{
			CLR_BIT(PORTA,pinNumber);	//PORTA &= ~(1<<pinNumber); // Write 0
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);	//PORTA |= (1<<pinNumber); // write 1
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_B:
		if (value == LOW)
		{
			CLR_BIT(PORTB,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_C:
		if (value == LOW)
		{
			CLR_BIT(PORTC,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
		case PORT_D:
		if (value == LOW)
		{
			CLR_BIT(PORTD,pinNumber);
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
			// Error handling
		}
		break;
	}
}

void DIO_read(uint8_t pinNumber ,uint8_t portNumber, uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNumber))>>pinNumber; // get state -> read bit gives 0 or 1
		break;
		case PORT_B:
		*value = (PINB & (1<<pinNumber))>>pinNumber; // get state -> read bit gives 0 or 1
		break;
		case PORT_C:
		*value = (PINC & (1<<pinNumber))>>pinNumber; // get state -> read bit gives 0 or 1
		break;
		case PORT_D:
		*value = (PIND & (1<<pinNumber))>>pinNumber; // get state -> read bit gives 0 or 1
		break;
		default:
		// Error handling
		break;
	}
}

void DIO_toggle(uint8_t pinNumber ,uint8_t portNumber)
{
	switch (portNumber)
	{
		case PORT_A:
		TOGG_BIT(PORTA,pinNumber);
		break;
		
		case PORT_B:
		TOGG_BIT(PORTB,pinNumber);
		break;
		
		case PORT_C:
		TOGG_BIT(PORTC,pinNumber);
		break;
		
		case PORT_D:
		TOGG_BIT(PORTD,pinNumber);
		break;
	}
}


