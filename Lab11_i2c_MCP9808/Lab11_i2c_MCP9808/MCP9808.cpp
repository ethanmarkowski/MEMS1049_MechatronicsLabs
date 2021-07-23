/*
 * MCP9808.cpp
 *
 * Created: 7/23/2021 12:29:01 AM
 *  Author: Ethan Markowski
 */ 

#include "MCP9808.h"

// Set up MCP9808
void MCP9808::Setup() const
{
	// Set up I2C object
	i2c.Setup();
	
	// Set resolution of MCP9808 temperature sensor to 0.5 degrees C
	i2c.Start();
	i2c.WriteAddress(0x18);
	i2c.WriteData(0x08);
	i2c.WriteData(0b00);
	i2c.Stop();
}

// Convert Celsius temperature to Fahrenheit
float MCP9808::CtoF(float value) const { return value * 9 / 5 + 32; }
	
// Read temperature value in Fahrenheit from MCP9808
float MCP9808::Read() const
{
	// Read ambient temperature register
	i2c.Start();
	i2c.WriteAddress(0x18);
	i2c.WriteData(0x05);
	i2c.Start();
	i2c.ReadAddress(0x18);
	uint8_t upperByte = i2c.ReadData(true) & 0x1F; // Read and clear flag bits
	uint8_t lowerByte = i2c.ReadData(false);
	i2c.Stop();
	
	// Convert register data to temperature in Celsius
	float tempInC;
	if ((upperByte & 0x10) == 0x10)
	{
		upperByte &= 0x0F; // Clear SIGN bit
		tempInC = 256 - (upperByte * 16 + (float)lowerByte / 16);
	}
	
	else
	{
		tempInC = upperByte * 16 + (float)lowerByte / 16;
	}
	
	// Return temperature in Fahrenheit
	return CtoF(tempInC);
}
