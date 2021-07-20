/*
 * Usart.cpp
 *
 * Created: 7/18/2021 3:12:38 PM
 *  Author: Ethan Markowski
 */ 

#include "Usart.h"

// Setup registers
void Usart::Setup() const // function to set up USART
{
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00) ; // Asynchronous mode, 8-bit data; no parity; 1 stop bit
	UBRR0L = 0x67; // 9,600 baud if Fosc = 16MHz
}

// Enable data transmission
void Usart::EnableTx() const { UCSR0B = (1 << TXEN0); }
	
// Enable data reception
void Usart::EnableRx() const { UCSR0B = (1 << RXEN0); }

// Check if available
bool Usart::IsAvailable() const { return UCSR0A & (1 << UDRE0); }

// Transmit data
void Usart::Write(uint8_t data) const { UDR0 = data; }

// Read data
uint8_t Usart::Read() const { return UDR0; }