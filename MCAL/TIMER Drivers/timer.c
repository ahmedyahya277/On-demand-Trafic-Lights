/*
 * timer.c
 *
 * Created: 9/30/2022 1:05:28 AM
 *  Author: Ahmed
 */ 

#include "timer.h"

// Timer0 Functions
void TIMER0_init(uint8_t timerMode)
{
	// Check For the inputs
	if(timerMode <= FAST_PWM_MODE)
	{
		switch(timerMode)
		{
			case NORMAL_MODE:		
				TCCR0 = 0x00; break;
			case PHASE_CORRECT_MODE:	
				TCCR0 = 0x40; break; //16^1*4
			case CTC_MODE:				
				TCCR0 = 0x08; break; //8*16^0
			case FAST_PWM_MODE:			
				TCCR0 = 0x48; break; // 40+8=48
		}
	}
	else
	{
		// Error Handling
	}
}

void TIMER0_start(uint8_t timerPrescaler, uint8_t Initial_Value)
{
	// Set Initial Timer Value
	TCNT0 = Initial_Value;
	
	// Check For the input validation
	if(timerPrescaler <= PRESCALER_1024)
	{
		switch(timerPrescaler)
		{
			case NO_PRESCALER:	//001
			SET_BIT(TCCR0, CS00); 
			CLR_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_8:	//010
			CLR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_64:	//011
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLR_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_256:	//100
			CLR_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_1024: //101
			SET_BIT(TCCR0, CS00);
			CLR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		}
	}
}

void TIMER0_stop(void)
{
	TCCR0 = 0x00;
}

void TIMER0_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows)
{
	// Reset The Over Flow Counter
	uint32_t overFlowCounter   = 0;
	
	// Start TIMER 0 (calling the start function in this function)
	TIMER0_start(timerPrescaler, initialValue);
	
	// Wait Until The Number Of Over Flows are Reached (busy loop)
	while( overFlowCounter < numberOfOverFlows)
	{
		/* T tick = Prescaler / FCPU
		 * FCPU = 10^(6)  
		 * One Overflow -> 256 microsecond ( NO_PRESCALER ) = 1
		 * One Overflow -> 2048 microsecond ( PRESCALER_8 )
		 * One Overflow -> 16384 microsecond ( PRESCALER_64 ) ---> application to delay 1 sec
		 * One Overflow -> 65536 microsecond ( PRESCALER_256 )
		 * One Overflow -> 262144 microsecond ( PRESCALER_1024 )
		 */
		
		/* tick				= Prescaler / F_CPU = 64 us
		 * t_max_delay		= 2^(8)* tick = 16.384 ms
		 * overflows		= delay_need / t_max_delay = 1 sec / 16.384 ms = 61.035 = 61 + 0.035 initial value
		 * initial_value	= 1 - 0.035 = 0.965 * 256 = 247.04 almost 247
		 */
		
		// wait until the overflow flag to be set (busy while)
		while(GET_BIT(TIFR,TOV0) == 0); 
		
		// Clear the overflow flag
		CLR_BIT(TIFR,TOV0);
		
		overFlowCounter++;	
	}
	
	overFlowCounter = 0;
	// calling the stop function to stop the timer
	TIMER0_stop();

}

// Timer2 Functions
void TIMER2_init(uint8_t timerMode)
{
	// Check For Valid Inputs
	if(timerMode <= FAST_PWM_MODE)
	{
		switch(timerMode) // same as timer0 but using the TCCR2 instead of TCCR0
		{
			case NORMAL_MODE:			TCCR2 = 0x00; break;
			case PHASE_CORRECT_MODE:	TCCR2 = 0x40; break;
			case CTC_MODE:				TCCR2 = 0x08; break;
			case FAST_PWM_MODE:			TCCR2 = 0x48; break;
		}
	}
	else
	{
		// Error Handling
	}
}

void TIMER2_start(uint8_t timerPrescaler, uint8_t Initial_Value)
{
	// Set Initial Timer Value
	TCNT2 = Initial_Value;
	
	// Check For Valid Inputs
	if(timerPrescaler <= PRESCALER_1024)
	{
		switch(timerPrescaler)
		{
			case NO_PRESCALER: // 001
			
			SET_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			CLR_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_8:
			
			CLR_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			CLR_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_64:
			
			SET_BIT(TCCR2,	CS20);
			SET_BIT(TCCR2,	CS21);
			CLR_BIT(TCCR2,	CS22);
			break;
			
			case PRESCALER_256:
			
			CLR_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_1024:
			
			SET_BIT(TCCR2, CS20);
			CLR_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		}
	}
}

void TIMER2_stop(void)
{
	TCCR2 = 0x00;
}

void TIMER2_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows)
{
	// Reset The Over Flow Counter
	uint32_t overFlowCounter  = 0;
	
	// Start TIMER2
	TIMER2_start(timerPrescaler, initialValue); // calling the start function in this function
	
	// Wait Until The Number Of Over Flows are Reached
	while( overFlowCounter < numberOfOverFlows)
	{
		
		// wait until the overflow flag to be set
		while(GET_BIT(TIFR,TOV2) == 0);
		
		// Clear the overflow flag
		CLR_BIT(TIFR,TOV2);
		overFlowCounter++;
		
	}
	
	overFlowCounter = 0;
	
	TIMER2_stop();
}


