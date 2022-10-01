/*
 * led.c
 *
 * Created: 9/30/2022 3:56:32 PM
 *  Author: Ahmed
 */ 

#include "led.h"

void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	DIO_init(ledPin,ledPort,OUT); // initialize the pin of this led
}

void LED_on(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin,ledPort,HIGH); // write high on the pin in order to turn the led on
}

void LED_off(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin,ledPort,LOW); // write low on the pin in order to turn the led off
}

void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	DIO_toggle(ledPin,ledPort); // toggle the value of the pin from low --> high --> low... sequence
}