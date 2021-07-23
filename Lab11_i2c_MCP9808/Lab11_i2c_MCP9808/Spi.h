/*
 * Spi.h
 *
 * Created: 7/20/2021 9:42:14 AM
 *  Author: Ethan Markowski
 */ 

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

class Spi
{
public:
	// Set up registers for main SPI communication
	void Setup() const;
	
	// Transmit command and data bytes
	void Write(uint8_t command, uint8_t data) const;
};

#endif