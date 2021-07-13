/*
 * Button.cpp
 *
 * Created: 7/12/2021 5:27:20 PM
 * Author: Ethan Markowski
 */ 

#include "Button.h"

// Set up button registers
void Button::Setup() const
{
	DDRC = 0x00; // Set Port C to input
	PORTC = 0x00; // Disable pull-up resistors
}

// Check if button on PINC0 is pressed
bool Button::IsPressed() const { return !(PINC & 1 << PINC0); }