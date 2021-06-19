/*
 * Lab3_Interrupts.cpp
 *
 * Created: 6/7/2021 5:00:09 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void delay(volatile int);

uint8_t debounce = 50;

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
	uint8_t temp_portc = PORTC; // Store copy of LED register before starting the ISR
	uint8_t temp_tcnt0 = TCNT0; // Store copy of timing register before starting the ISR
	TCCR0B = 0x00; // Stop TIMER0
	
	// Turn off all LEDs for 2 seconds
	PORTC = 0xFF;	
	delay(2000);
	
	// Display 0 through 15 on the LED array in binary
	for (uint8_t count = 0; count <= 15; ++count)
	{
		PORTC = ~count;
		delay(250);
	}
	
	TCCR0B = 0b00000011; //1<<CS01 | 1<<CS00; TCCR0B = 0x03; // Start TIMER0, Normal mode, crystal clock, prescaler = 64
	TCNT0 = temp_tcnt0; // Restore timing register to state from before the ISR execution
	
	PORTC = temp_portc; // Restore PORTC to state from before the ISR execution
	
	EIFR = 0b00000001; // Clear the INT0 flag to ensure consecutive ISRs are not triggered
}

ISR(INT1_vect)
{
	uint8_t temp_portc = PORTC; // Store copy of LED register before starting the ISR
	uint8_t temp_tcnt0 = TCNT0; // Store copy of timing register before starting the ISR
	TCCR0B = 0x00; // Stop TIMER0
	
	// Debounce Interrupt Pin 1
	delay(debounce);
	EIFR = 0b00000010;
	
	// Turn on all LEDs for 2 second
	PORTC = 0x0;
	delay(2000);
	
	// Turn LEDs off one at a time
	uint8_t count = 0b1111;
	while (1)
	{
		count = count >> 1;
		PORTC = ~count;
		
		if (count == 0) { break; }
		delay(500);
	}
	
	delay(1000);
	
	TCCR0B = 0b00000011; //1<<CS01 | 1<<CS00; TCCR0B = 0x03; // Start TIMER0, Normal mode, crystal clock, prescaler = 64
	TCNT0 = temp_tcnt0; // Restore timing register to state from before the ISR execution
	
	PORTC = temp_portc; // Restore PORTC to state from before the ISR execution
	EIFR = 0b00000001; // Clear the INT0 flag to ensure an INT0 ISR execution does not immediately follow the INT1 ISR. However repeats of INT1 are allowed
}