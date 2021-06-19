/*
 * Lab4_AD-Conversion.cpp
 *
 * Created: 6/19/2021 12:59:11 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0xFF; // Set PORTB to output for the LEDs
	PORTB = 0xFF; // Set initial state of each LED to off
	
    while (1) 
    {
    }
}

