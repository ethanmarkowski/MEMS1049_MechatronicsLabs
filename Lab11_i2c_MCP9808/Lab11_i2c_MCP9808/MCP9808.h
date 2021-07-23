/*
 * MCP9808.h
 *
 * Created: 7/23/2021 12:27:26 AM
 *  Author: Ethan Markowski
 */ 

#ifndef MCP9808_H_
#define MCP9808_H_

#include <avr/io.h>
#include "I2C.h"

class MCP9808
{
private:
	I2C i2c;
	
	// Convert Celsius temperature to Fahrenheit
	float CtoF(float value) const;
public:
	// Set up MCP9808
	void Setup() const;
	
	// Read temperature value in Fahrenheit from MCP9808
	float Read() const;
};

#endif