/*
 * AnalogSensor.cpp
 *
 * Created: 7/18/2021 2:52:35 PM
 *  Author: Ethan Markowski
 */ 

#include "AnalogSensor.h"

// Set-up ADC on PC0
void AnalogSensor::Setup() const
{
	DDRC = 0x0; // Set Port C to input for the analog sensor
	PORTC = 0x0; // Disable Port C pull-up resistors
	PRR = 0x0; // Enable power to the ADC
	ADCSRA = 1 << ADEN | 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0; // Enable ADC and set clock prescaler to 128 (~10 kHz sampling rate)
	ADMUX = 0 << REFS1 | 1 << REFS0 | 1 << ADLAR; // Set reference voltage to AVcc, ADC channel to 0 (PC0), and make results left justified
}

// Read analog input on PC0 and return top byte of data
uint8_t AnalogSensor::AnalogRead() const
{
	ADCSRA |= (1 << ADSC); // Start A/D conversion
	while ((ADCSRA & (1 << ADIF)) == 0); // Blocking delay to wait for the A/D conversion
	
	return ADCH; // Keep high byte of 10-bit result (throw away lowest two bits)
}