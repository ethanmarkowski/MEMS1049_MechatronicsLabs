/*
 * Timer0.cpp
 *
 * Created: 7/12/2021 2:23:55 PM
 *  Author: Ethan Markowski
 */ 

#include "Timer0.h"

// Use Timer0 to create a blocking delay for the specified number of milliseconds
void Timer0::Delay(volatile uint16_t milliseconds) const
{
	// Assumes a 16MHz clock frequency
	while (milliseconds > 0)
	{
		TCCR0A = 0x00; // clears WGM00 and WGM01 (bits 0 and 1) to ensure Timer/Counter is in normal mode.
		TCNT0 = 0; // preload value for testing on count = 250
		TCCR0B = 0b00000011; //1<<CS01 | 1<<CS00; TCCR0B = 0x03; // Start TIMER0, Normal mode, crystal clock, prescaler = 64

		while (TCNT0 < 0xFA); // exits when count = 250 (requires preload of 0 to make count = 250)
		TCCR0B = 0x00; // Stop TIMER0

		milliseconds--;
	}
}