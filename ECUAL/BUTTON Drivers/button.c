/*
 * button.c
 *
 * Created: 9/30/2022 3:52:27 PM
 *  Author: Ahmed
 */ 


#include "button.h"

// initialize
void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort)
{
	DIO_init(buttonPin,buttonPort,IN); // initialize the pin that the button on it and mark it as input 
}

// button read
void BUTTON_read(uint8_t buttonPin ,uint8_t buttonPort, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value); // read the value of the pin and store it in "value" which is low or high
}