/*
 * I2C.h
 *
 * Created: 7/22/2021 11:58:10 PM
 *  Author: Ethan Markowski
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

class I2C
{
public:
	// Set up registers
	void Setup() const;
	
	// Send start command
	void Start() const;
	
	// Send stop command
	void Stop() const;
	
	// Write an address byte to the I2C2 bus in form of SLA_W (address to write to)
	void WriteAddress( uint8_t address) const;
	
	// Write an address byte to the I2C bus in form of SLA_R (address to read from)
	void ReadAddress(uint8_t address) const;
	
	// Write data byte to the I2C2 bus
	void WriteData( uint8_t data) const;
	
	// Read a byte of data from a secondary on the I2C2 bus
	uint8_t ReadData(bool ACK) const;
};

#endif