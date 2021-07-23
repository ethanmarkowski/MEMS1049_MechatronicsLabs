/*
 * Spi.cpp
 *
 * Created: 7/20/2021 9:42:59 AM
 *  Author: Ethan Markowski
 */ 

#include "Spi.h"

// Set up registers for main SPI communication
void Spi::Setup() const
{
	DDRD = 0xFF; // Set DDRD to display data that comes in from Secondary
	DDRB = 1 << PORTB5 | 1 << PORTB3 | 1 << PORTB2;  // Set pins SCK, MOSI, and SS as output
	SPCR = 1 << SPE | 1 << MSTR | 1 << SPR0; // (SPIE = 0, SPE = 1, DORD = 0, MSTR = 1, CPOL = 0, CPHA = 0, SPR1 = 0, SPR0 = 1)
	// enable the SPI, set to Main mode 0, SCK = Fosc/16, lead with MSB
}

// Transmit data
void Spi::Write(uint8_t command, uint8_t data) const
{
	PORTB &= ~(1 << PORTB2);  // Clear the SS bit to enable Secondary
	SPDR = command; // Send the command
	while (!(SPSR & (1 << SPIF))); // Check the SPIF bit and wait for it to be set => transmit complete
	
	SPDR = data; // Send the data
	while (!(SPSR & (1 << SPIF))); // Check the SPIF bit and wait for it to be set => transmit complete

	PORTB |= 1 << PORTB2;  // Disable Secondary (this clears SBIF flag)
}