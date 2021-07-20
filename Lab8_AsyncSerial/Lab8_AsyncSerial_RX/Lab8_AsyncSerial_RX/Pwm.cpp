/*
 * Pwm.cpp
 *
 * Created: 7/18/2021 4:22:46 PM
 *  Author: Ethan Markowski
 */ 

#include "Pwm.h"

// Set whether duty cycle should be inverted
Pwm::Pwm(bool inverting) : _inverting(inverting) {}

// Set up registers
void Pwm::Setup() const
{
	DDRD |= 1 << PORTD6; // Set Port D to output
	OCR0A = (_inverting) ? ~0x00 : 0x00; // Set initial duty cycle to 0 accounting for duty cycle inversion
	TCCR0B = 0 << CS02 | 1 << CS01 | 1 << CS00; // Set clock prescaler to 64 (~1 kHz PWM frequency)
	TCCR0A = 1 << COM0A1 | 0 << COM0A0 | 1 << WGM01 | 1 << WGM00; // Set non-inverting mode on OC0A pin
}

// Output PWM signal
void Pwm::Write(uint8_t value) const
{
	OCR0A = (_inverting) ? ~value : value;
}