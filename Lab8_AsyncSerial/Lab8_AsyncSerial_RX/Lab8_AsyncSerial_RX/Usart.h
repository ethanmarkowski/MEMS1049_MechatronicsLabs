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
	
	// Check if Usart is available
	bool IsAvailable() const;
	
	// Check if new data has been received
	bool IsReceived() const;
	
	// Transmit data
	void Write(uint8_t data) const;
	
	// Read data
	uint8_t Read() const;
};

#endif