/*
 * LedArray.cpp
 *
 * Created: 7/12/2021 5:27:30 PM
 * Author: Ethan Markowski
 */ 


#include "LedArray.h" 

// Set-up LED array on PB0 - PB1
void LedArray::Setup() const
{
	DDRB = 0xFF; // Set Port B to output for the LEDs
	PORTB = 0xFF; // Set initial state of each LED to off (active-low)
}

// Set LED array index (between 0 and 1, or -1 to turn off LEDs)
void LedArray::SetIndex(int8_t index) const
{
	PORTB = (index >= 0) ? ~(1 << index) : 0xFF ;
}