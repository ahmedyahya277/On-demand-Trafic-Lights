/*
 * timer.h
 *
 * Created: 9/30/2022 1:05:39 AM
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/interrupts.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/typedefs.h"

// TIMER Modes
#define NORMAL_MODE			0
#define PHASE_CORRECT_MODE  1
#define CTC_MODE			2
#define FAST_PWM_MODE		3

// Prescaler Macros
#define NO_PRESCALER	0
#define PRESCALER_8		1
#define PRESCALER_64	2
#define PRESCALER_256	3
#define PRESCALER_1024	4

//TIMSK register
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

// TCCR0 register
#define CS00 0
#define CS01 1
#define CS02 2

// TCCR2 register
#define CS20 0
#define CS21 1
#define CS22 2

// TIFR register
#define TOV0 0
#define TOV2 6

// Timer0 functions 

void TIMER0_init(uint8_t timerMode);
/* initialize the time by choosing its mode */
void TIMER0_start(uint8_t timerPrescaler, uint8_t Initial_Value);
/* start the timer by setting the Prescaler and the initial value of the timer */
void TIMER0_stop(void);
/* stop the timer from counting */
void TIMER0_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows);	
/* use this timer to generate delay time based on the equations of the timer and the mode we have been chosen */
// Timer2 functions
void TIMER2_init(uint8_t timerMode);
/* same as timer0 but instead of register TCCR0 we use TCCR2 */
void TIMER2_start(uint8_t timerPrescaler, uint8_t Initial_Value);

void TIMER2_stop(void);

void TIMER2_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows);


#endif /* TIMER_H_ */