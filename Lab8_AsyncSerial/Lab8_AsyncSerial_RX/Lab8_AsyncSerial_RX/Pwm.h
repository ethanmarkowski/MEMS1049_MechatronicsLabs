/*
 * Pwm.h
 *
 * Created: 7/18/2021 4:19:35 PM
 *  Author: Ethan Markowski
 */ 

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

class Pwm
{
private:
	bool _inverting;
	
public:
	// Set whether duty cycle should be inverted
	Pwm(bool inverting);
	
	// Set up registers
	void Setup() const;
	
	// Output PWM signal
	void Write(uint8_t value) const;
};

#endif