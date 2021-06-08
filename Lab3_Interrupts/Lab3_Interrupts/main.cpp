/*
 * Lab3_Interrupts.cpp
 *
 * Created: 6/7/2021 5:00:09 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void delay(volatile int);

enum Directions { LEFT, RIGHT };

int main(void)
{
	DDRC = 0xFF; // Set PORTC as output	(LEDs connected on PC0 - PC3)
	DDRD = 0x0; // Set PORTD as input (button connected on PD2 and PD3)
	
	PORTC = 0xFF;// Set initial state of LEDs as off
	PORTD = 0x0; // Disable internal pull-up resistors
	
	EICRA = 0b00001010; // Set Interrupts 0 and 1 to track falling edge
	EIMSK = 0b00000011; // Enable INT0 and INT1
	
	sei(); // Enable Global Interrupt
	
	uint8_t state = 0b0001; // Stores the current states of the four LEDs
	Directions shift = LEFT; // Stores the current shift direction of the LED array
	
	while (1)
	{
		PORTC = ~state; // Write current LED states to PORTC
		
		// Shift left and right through the LED array
		switch (shift)
		{
			case LEFT:
			state = state << 1;
			if (state == 0b1000) { shift = RIGHT; }
			break;
			
			case RIGHT:
			state = state >> 1;
			if (state == 0b0001) { shift = LEFT; }
			break;
		}
		
		delay(1000);
	}
}

void delay(volatile int multiple)
{
	// This subroutine creates a delay equal to multiple*T, where T is 1 msec
	// Assumes a 16MHz clock frequency ? FOR DIFFERENT CLOCK, CHANGE THE COUNT EXIT VALUE IN WHILE LOOP
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

ISR(INT0_vect)
{
	PORTC = 0x0;	
	delay(1000);
}

ISR(INT1_vect)
{
	PORTC = 0x0;
	delay(1000);
}