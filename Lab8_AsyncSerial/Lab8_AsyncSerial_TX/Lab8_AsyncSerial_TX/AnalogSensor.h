/*
 * AnalogSensor.h
 *
 * Created: 7/18/2021 2:52:21 PM
 *  Author: Ethan Markowski
 */ 

#ifndef ANALOGSENSOR_H_
#define ANALOGSENSOR_H_

#include <avr/io.h>

class AnalogSensor
{
public:
	// Set up registers to read analog sensor on PC0
	void Setup() const;
	
	// Read value from ADC and return top byte of data
	uint8_t AnalogRead() const;
};

#endif