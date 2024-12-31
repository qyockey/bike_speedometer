#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "../inc/num_types.h"

static volatile u32 millis_elapsed;

/* Count milliseconds elapsed */
ISR(TIMER0_COMPA_vect) 
{
	++millis_elapsed;
}

/* Initialize timer 0 to count milliseconds */
void millis_init(void)
{
	power_timer0_enable();	// Use timer0 for millis

	cli();	// Disable interrupts during configuration

	millis_elapsed = 0;

	// Set Timer0 to CTC (Clear Timer on Compare Match) mode
	// Set prescaler to 64
	TCCR0A = 0;
	TCCR0B = _BV(WGM02) | _BV(CS01) | _BV(CS00);

	// Set compare match value for 1 kHz
	// (16 MHz clock / 64 prescaler / 250 = 1 kHz)
	OCR0A = 249;

	// Enable Timer0 compare match interrupt
	TIMSK0 = _BV(OCIE0A);

	sei();	// Re-enable interrupts
}

u32 millis(void)
{
	return millis_elapsed;
}

