#ifndef __LED_H
#define __LED_H

#include <avr/io.h>

// Builtin LED on port C pin 7 (Arduino D0)
#define LED_PIN			(PC7)
#define LED_DDR 		(DDRC)
#define LED_PORT		(PORTC)

#endif // __LED_H

