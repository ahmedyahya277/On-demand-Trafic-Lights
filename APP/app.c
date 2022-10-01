/*
 * app.c
 *
 * Created: 9/30/2022 4:03:18 PM
 *  Author: Ahmed
 */ 

#include "app.h"


// Counters
uint8_t seconds_Counter		= 0; // used to measure the 5 seconds delay
uint32_t overflow_Counter0	= 0; // used to measure the overflow of timer0
uint32_t overflow_Counter2	= 0; // used to measure the overflow of timer2

//Flags
uint8_t CAR_STATE		= 0;	// indicate the state of the car which is green, yellow or red
uint8_t YELLOW_FLAG		= 0;	// indicate the yellow signal to blink the lights
uint8_t PRESSED_BUTTON_FLAG	= 0;// indicate if the button is pressed or not


/************************************************************************/
/*							INITIALIZATION								*/
/************************************************************************/
void APP_init()
{
	/* DIO Initialization */
	
	// Set LEDs Direction OUTPUT
	DIO_init(CAR_GREEN_PIN	,	CAR_PORT, OUTPUT);
	DIO_init(CAR_YELLOW_PIN	,	CAR_PORT, OUTPUT);
	DIO_init(CAR_RED_PIN	,	CAR_PORT, OUTPUT);
	
	DIO_init(PED_GREEN_PIN	,	PED_PORT, OUTPUT);
	DIO_init(PED_YELLOW_PIN	,	PED_PORT, OUTPUT);
	DIO_init(PED_RED_PIN	,	PED_PORT, OUTPUT);
	
	// Set Button Direction INPUT
	BUTTON_init(BUTTON_PIN, BUTTON_PORT);
	
	
	/* Interrupts Initialization */
	
	// Enable Global Interrupt
	SET_BIT(SREG, GIE);
	
	
	// INT 0 Sense Any Logical Change ( to distinguish between long and short press)
	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
	
	// Enable INT0
	SET_BIT(GICR, INT0); 
	
	// Enable Overflow Interrupts for TIMER0 and TIMER2
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,TOIE2);
	
	// Timer 0 initialization
	TIMER0_init(NORMAL_MODE);
	
	// Timer 2 initialization
	TIMER2_init(NORMAL_MODE);
	
	// Timer 0 Start
	TIMER0_start(PRESCALER_64, TIMER0_INITIAL_VALUE);
}

/************************************************************************/
/*								APPLICATION								*/
/************************************************************************/

void APP_start()
{
	while (1)
	{
		// To Ensure GREEN --> YELLOW --> RED --> YELLOW --> GREEN... Loop
		if (CAR_STATE > CAR_YELLOW_2)
		{
			CAR_STATE = CAR_GREEN;
		}
		
		else
		{
			switch(CAR_STATE)
			{
				case CAR_GREEN:
				
					// Turn On Car GREEN led and Pedestrian RED led
					LED_on(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_YELLOW_PIN, CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_YELLOW_PIN,PED_PORT);
					LED_on(PED_RED_PIN,PED_PORT);
				
					YELLOW_FLAG = 0;
					break;
				
				case CAR_YELLOW_1:
				
					// Set The Yellow Flag So it can blink 
					YELLOW_FLAG = 1;
					
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					break;
				
				case CAR_RED:
				
					// Turn On Car RED led and Pedestrian GREEN led
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_YELLOW_PIN, CAR_PORT);
					LED_on(CAR_RED_PIN, CAR_PORT);
				
					LED_on(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_YELLOW_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					
					YELLOW_FLAG = 0;
					break;
				
				case CAR_YELLOW_2:
				
					// Set The Yellow Flag So it can blink 
					YELLOW_FLAG = 1;
					
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					break;
				
				default:
				// do nothing
				break;
			}
		}
	}
}


/**** TIMER 0 Overflow ISR ****/

ISR(TIMER0_OVF)
{
	// Check if the overflow counter reached the number of overflows to ( 1s ) 
	if (overflow_Counter0 < TIMER0_NumOfOverFlows)
	{
		overflow_Counter0++;
	}
	
	else if (overflow_Counter0 >= TIMER0_NumOfOverFlows)
	{
		// Increment a second
		seconds_Counter++;
		
		
		if (YELLOW_FLAG == 1)
		// If The Yellow Flag is Set Toggle Both YELLOW LEDs
		{
			LED_toggle(CAR_YELLOW_PIN,CAR_PORT);
			LED_toggle(PED_YELLOW_PIN,PED_PORT);
		}
		
		if (seconds_Counter == 5)
		{
			// If The Seconds Counter Counts 5 Seconds Switch To The Next Signal State
			CAR_STATE++;
			
			// Reset The Seconds Counter
			seconds_Counter = 0;
		}
		
		// Reset The Overflow Counter
		overflow_Counter0 = 0;
	}
}


/**** TIMER 2 Overflow ISR ****/

ISR(TIMER_2_OVF)
{
	// Just Increment The Overflow Counter
	overflow_Counter2++;
}


/**** EXT INT0 ISR ****/

ISR (EXT_INT_0)
{
	// Increment The Pressed Flag
	PRESSED_BUTTON_FLAG++;
	
	/* The Interrupt Is Set To Any Logical Change So That
	 * We Can Count The Time Between The 2 Logical Changes
	 * ( Rising Edge When Pressed and Falling When Released )
	 */
	
	switch(PRESSED_BUTTON_FLAG)
	{
		case PRESSED:
			
			// Start Timer2 At The Rising Edge 
			TIMER2_start(PRESCALER_64,47);
			break;
			
		case RELEASED:
		
			// Check The overflow Counter Counted More Than Half a Second Or Not
			if (overflow_Counter2 > TIMER2_NumOfOverFlows)
			{
				// The Button Was Not Released after 0.5 ( Long Press )
				// Do Nothing 
			}
			
			// The Button Was Released Before 0.5s ( Short Press )
			else
			{
				if (CAR_STATE == CAR_GREEN)
				{
					// If The Car Signal Is GREEN Switch It To YELLOW
					CAR_STATE++;
					
					// Reset The Counters
					seconds_Counter = 0;
					overflow_Counter0 = 0;
				}
				
				else
				{
					// The Car Signal Is Already YELLOW or RED
					// Do Nothing
				}
		}
		
		// Stop TIMER2
		TIMER2_stop();
		
		// Reset The Counter and The Flag
		overflow_Counter2	= 0;
		PRESSED_BUTTON_FLAG = 0;
		break;
	}
}