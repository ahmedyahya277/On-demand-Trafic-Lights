/*
 * led.h
 *
 * Created: 9/30/2022 3:56:42 PM
 *  Author: Ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Drivers/dio.h"
#include "../../MCAL/TIMER Drivers/timer.h"

void LED_init(uint8_t ledPin, uint8_t ledPort);
/* there are 2 inputs the led pin and the led port and it's defined as output */
void LED_on(uint8_t ledPin, uint8_t ledPort);
/* there are 2 inputs the led pin and the led port and it's defined as output and we write HIGH on this pin at that port */
void LED_off(uint8_t ledPin, uint8_t ledPort);
/* there are 2 inputs the led pin and the led port and it's defined as output and we write LOW on this pin at that port */
void LED_toggle(uint8_t ledPin, uint8_t ledPort);
/* there are 2 inputs the led pin and the led port and it's defined as output and we toggle the value on this pin at that port */


#endif /* LED_H_ */