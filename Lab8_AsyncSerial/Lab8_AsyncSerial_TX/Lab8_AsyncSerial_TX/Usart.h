/*
 * Usart.h
 *
 * Created: 7/18/2021 3:12:25 PM
 *  Author: Ethan Markowski
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>

class Usart
{
public:
	// Setup registers
	void Setup() const;
	
	// Enable data transmission
	void EnableTx() const;
	
	// Enable data reception
	void EnableRx() const;
	
	// Check if available
	bool IsAvailable() const;
	
	// Transmit data
	void Write(uint8_t data) const;
	
	// Read data
	uint8_t Read() const;
};

#endif