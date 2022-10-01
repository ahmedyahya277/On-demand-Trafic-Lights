/*
 * dio.h
 *
 * Created: 9/29/2022 10:50:18 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/interrupts.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/typedefs.h"

 // pin configurations
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// port configuration
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction defines
#define INPUT 0
#define OUTPUT 1
#define IN 0
#define OUT 1

// value defines
#define LOW 0
#define HIGH 1

void DIO_init(uint8_t pinNumber ,uint8_t portNumber, uint8_t direction); // initialize dio direction
/* there are 3 inputs the port and the pin in that port and the direction of that pin. */

void DIO_write(uint8_t pinNumber ,uint8_t portNumber, uint8_t value); // write data to dio
/* there are 3 inputs the port and the pin in that port and the value(HIGH,LOW) of that pin. */

void DIO_read(uint8_t pinNumber ,uint8_t portNumber, uint8_t *value); // read data from dio
/* there are 3 inputs the port and the pin in that port and the value on that pin. */

void DIO_toggle(uint8_t pinNumber ,uint8_t portNumber); // toggle dio
/* there are 2 inputs the port and the pin in that will toggle the value on this pin */

#endif /* DIO_H_ */