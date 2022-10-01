/*
 * button.h
 *
 * Created: 9/30/2022 3:52:16 PM
 *  Author: Ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Drivers/dio.h"
#include "../../MCAL/TIMER Drivers/timer.h"

//button state macros
#define LOW		0
#define HIGH	1

// initialize
void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort);
/* initialize the button by DIO_initialize function and write INPUT as the button is input */
// button read
void BUTTON_read(uint8_t buttonPin ,uint8_t buttonPort, uint8_t *value);
/* 3 inputs the pin and the port that contain this pin and the value on that pin and store it in the third parameter */

#endif /* BUTTON_H_ */