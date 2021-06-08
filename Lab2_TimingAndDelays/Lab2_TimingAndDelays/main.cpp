/*
 * Lab2_TimingAndDelays.cpp
 *
 * Created: 5/31/2021 2:07:29 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>

void delay(volatile int);

enum Directions { LEFT, RIGHT };

int main(void)
{
    DDRC = 0xFF; // Set PORTC as output	(LEDs connected on DC0 - DC3)
	DDRD = 0x0; // Set PORTD as input (button connected on DD2)
	
	PORTC = 0xFF;// Set initial state of LEDs as off
	PORTD = 0x0; // Disable internal pull-up resistors
	
	uint8_t state = 0b00000001; // Stores the negated state of the PORTC bits
	Directions shift = LEFT; // Stores the current shift direction
	
    while (1) 
    {
		// If the active-low button on PD2 is pressed, turn off all LEDs. Otherwise, cycle through the LED array
		if (PIND & 0b00000100) { PORTC = ~state; }
		else { PORTC = 0xFF; continue; }
		
		// Shift left and right through the LED array
		switch (shift)
		{
			case LEFT:
			state = state << 1;
			if (state == 0b00001000) { shift = RIGHT; }
			break;
			
			case RIGHT:
			state = state >> 1;
			if (state == 0b00000001) { shift = LEFT; }
			break;
		}
		
		//delay(1000);
    }
}

void delay(volatile int multiple)
{
	// This subroutine creates a delay equal to multiple*T, where T is 1 msec
	// Assumes a 16MHz clock frequency – FOR DIFFERENT CLOCK, CHANGE THE COUNT EXIT VALUE IN WHILE LOOP
	while (multiple > 0)
	{
		TCCR0A = 0x00; // clears WGM00 and WGM01 (bits 0 and 1) to ensure Timer/Counter is in normal mode.

		TCNT0 = 0; // preload value for testing on count = 250

		TCCR0B = 0b00000011; //1<<CS01 | 1<<CS00; TCCR0B = 0x03; // Start TIMER0, Normal mode, crystal clock, prescaler = 64

		while (TCNT0 < 0xFA); // exits when count = 250 (requires preload of 0 to make count = 250) CHANGE THIS VALUE FOR CLOCK OTHER THAN 16MHz

		TCCR0B = 0x00; // Stop TIMER0

		multiple--;
	}
}