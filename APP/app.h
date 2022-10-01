/*
 * app.h
 *
 * Created: 9/30/2022 4:03:11 PM
 *  Author: Ahmed
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/BUTTON Drivers/button.h"
#include "../ECUAL/LED Drivers/led.h"


// PORT Macros
#define CAR_PORT			PORT_A
#define PED_PORT			PORT_B
#define BUTTON_PORT			PORT_D

// PIN Macros
#define CAR_GREEN_PIN       PIN0
#define CAR_YELLOW_PIN      PIN1
#define CAR_RED_PIN         PIN2

#define PED_GREEN_PIN       PIN0
#define PED_YELLOW_PIN      PIN1
#define PED_RED_PIN         PIN2

#define BUTTON_PIN          PIN2

// Car Signal State Macros (Sequence of the normal mode)
#define CAR_GREEN				0
#define CAR_YELLOW_1			1
#define CAR_RED					2
#define CAR_YELLOW_2			3

// Timer Macros
#define TIMER0_INITIAL_VALUE	247
#define TIMER0_NumOfOverFlows	62

#define TIMER2_INITIAL_VALUE	47
#define TIMER2_NumOfOverFlows	30

// Button Macros
#define PRESSED		1
#define RELEASED	2

void APP_init(void);
void APP_start(void);

#endif /* APP_H_ */