/*
 * Lab5_BrushedMotorControl.cpp
 *
 * Created: 6/28/2021 2:57:22 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>

// Set-up LED outputs in Port B
void portBSetup();

// Set-up ADC and digital input in Port C
void portCSetup();

// Set-up H-bridge control in Port D
void portDSetup();

// Write to LED array
void ledWrite(uint8_t);

// Read analog input on PC0
uint8_t analogRead();

// Read digital input on PC1
bool digitalRead();

enum Mode { STOPPED, REVERSE, FORWARD };

int main(void)
{	
	while (1)
	{
		
	}
}

// Set-up LED array on PB0 - PB4
void portBSetup()
{
	DDRB = 0xFF; // Set Port B to output for the LEDs
	PORTB = 0xFF; // Set initial state of each LED to off
}

// Set-up ADC on PC0 and digital input on PC1
void portCSetup()
{
	DDRC = 0x0; // Set Port C to input for the potentiometer
	PORTC = 0x0; // Disable Port C pull-up resistors
	PRR = 0x0; // Enable power to the ADC
	ADCSRA = 1 << ADEN | 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0; // Enable ADC and set clock prescaler to 128 (~10 kHz sampling rate)
	ADMUX = 0 << REFS1 | 1 << REFS0 | 1 << ADLAR; //0x60; // Set reference voltage to AVcc, ADC channel to 0 (PC0), and make results left justified	
}

// Set-up H-bridge forward, reverse, and enable pins on PD0, PD1, and PD6
void portDSetup()
{
	DDRD = 0xFF; // Set Port D to output for H-bridge motor control
	PORTD = 0X0; // Set initial state of motor to stopped
	
	OCR0A = 0x0; // Load 0x0 into OCR0 to set initial duty cycle to 0 (motor speed = 0)
	TCCR0A = 1 << COM0A1 | 0 << COM0A0 | 1 << WGM01 | 1 << WGM00; // Set non-inverting mode on OC0A pin
	TCCR0B = 0 << CS02 | 1 << CS01 | 1 << CS00; // Set clock prescaler to 64 (~1 kHz PWM frequency)
}

// Set LED array index (between 0 and 4)
void ledWrite(uint8_t index)
{
	PORTB = ~(1 << index);
}

// Read analog input on PC0
uint8_t analogRead()
{
	ADCSRA |= (1 << ADSC); // Start A/D conversion
	while ((ADCSRA & (1 << ADIF)) == 0); // Blocking delay to wait for the A/D conversion
	
	return ADCH; // Keep high byte of 10-bit result (throw away lowest two bits)
}

// Read digital input on PC1
bool digitalRead()
{
	return PINC & 1 << PINC1;
}

// Update motor control based on mode and 8-bit speed setting
void setMotorSpeed(uint8_t speed, Mode mode)
{
	PORTD = mode; // Set H-bridge forward and reverse pins based on motor mode
	OCR0A = speed; // Update PWM signal to match motor speed
	
}