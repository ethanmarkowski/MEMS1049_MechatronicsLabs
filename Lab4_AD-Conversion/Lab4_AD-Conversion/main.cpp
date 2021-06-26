/*
 * Lab4_AD-Conversion.cpp
 *
 * Created: 6/19/2021 12:59:11 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>

// Read analog input
uint8_t analogRead();

int main(void)
{
	// Set-up 5 LED array
    DDRB = 0xFF; // Set Port B to output for the LEDs
	PORTB = 0xFF; // Set initial state of each LED to off
	
	// Set-up ADC to read potentiometer
	DDRC = 0x0; // Set Port C to input for the potentiometer
	PORTC = 0x0; // Disable Port C pull-up resistors
	PRR = 0x0; // Enable power to the ADC
	ADCSRA = 1<<ADEN | 1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0; // Enable ADC and set clock prescaler to 128 to achieve ~10 kHz sampling rate
	ADMUX = 0<<REFS1 | 1<<REFS0 | 1<<ADLAR; //0x60; // Set reference voltage to AVcc, ADC channel to 0 (PC0), and make results left justified
	
    while (1) 
    {
		PORTB = ~(1 << analogRead() / (0xFF / 4));		
    }
}

// Read analog input
uint8_t analogRead()
{
	ADCSRA = ADCSRA |= (1<<ADSC); // Start A/D conversion
	while ((ADCSRA & (1<<ADIF)) == 0); // Blocking delay to wait for the A/D conversion
	
	return ADCH; // Keep high byte of 10-bit result (throw away lowest two bits)
}