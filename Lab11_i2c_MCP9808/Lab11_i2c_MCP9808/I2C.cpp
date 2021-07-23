/*
 * I2C.cpp
 *
 * Created: 7/22/2021 11:58:22 PM
 *  Author: Ethan Markowski
 */ 

#include "I2C.h"

// Set up registers
void I2C::Setup() const
{
	//If needed, turn on TWI power: PRR = PRR & 0b01111111; // Ensure that TWI is powered on (PRTWI = 0)
	DDRC = 0b00000000; // Define all PORTC bits as input (specifically PC4 and PC5)
	PORTC = PORTC | 0b00110000;  // Set internal pull-up resistors on SCL and SDA lines (PC5 and PC4) of I2C bus

	TWSR = 0b00000000; // Prescaler is set to 1
	TWBR = 72; // Put 72 into TWBR to define SCL frequency as 100kHz for 16MHz oscillator
	TWCR = 0b00000100; // TWEN = 1 (enable TWI)
}

// Send start command
void I2C::Start() const
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // Initiate START condition -- write 1 to TWINT to clear it and initiate action, set TWSTA bit, set TWEN bit
	while (!(TWCR & (1 << TWINT))); // Wait for action to finish (poll TWINT bit)
}

// Send stop command
void I2C::Stop() const
{
	while (!(TWCR & (1 << TWINT))); // Wait for action to finish (poll TWINT bit)
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO); // Initiate STOP condition -- write 1 to TWINT to clear it and initiate action, set TWSTO bit and set TWEN bit
}

// Write an address byte to the I2C2 bus in form of SLA_W (address to write to)
void I2C::WriteAddress( uint8_t address) const
{
	uint8_t SLA_W = address << 1; // Create SLA_W byte by shifting address and leaving R/W bit clear
	while (!(TWCR & (1 << TWINT))); // Wait for idle condition -- TWINT bit must be high to proceed
	TWDR = SLA_W; // Load TWDR with address plus R/W bit
	TWCR = (1 << TWINT) | (1 << TWEN); // Initiate Write -- write 1 to TWINT to clear it and initiate action, and set TWEN
	while (!(TWCR & (1 << TWINT))); // Wait for action to finish (poll TWINT bit)
}

// Write an address byte to the I2C bus in form of SLA_R (address to read from)
void I2C::ReadAddress(uint8_t address) const
{
	uint8_t SLA_R = address << 1 | 1; // Create SLA_R byte by shifting address and setting R/W bit
	while (!(TWCR & (1 << TWINT))); // Wait for idle condition -- TWINT bit must be high to proceed
	TWDR = SLA_R; // Load TWDR with address plus R/W bit
	TWCR = (1 << TWINT) | (1 << TWEN); // Initiate Write -- write 1 to TWINT to clear it and initiate action, and set TWEN
	while (!(TWCR & (1<<TWINT))); // Wait for action to finish (poll TWINT bit)
}

// Write data byte to the I2C2 bus
void I2C::WriteData( uint8_t data) const
{
	while (!(TWCR & (1 << TWINT))); // Wait for idle condition -- TWINT bit must be high to proceed
	TWDR = data; // Load TWDR with data to be sent
	TWCR = (1 << TWINT) | (1 << TWEN); // Initiate Write -- write 1 to TWINT to clear it and initiate action, and set TWEN
	while (!(TWCR & (1 << TWINT))); // Wait for action to finish (poll TWINT bit)
}

// Read a byte of data from a secondary on the I2C2 bus
uint8_t I2C::ReadData(bool ACK) const
{
	uint8_t data;
	while (!(TWCR & (1 << TWINT))); // Wait for idle condition -- TWINT bit must be high to proceed
	
	// Check for whether ACK or NO_ACK should be sent upon receipt of byte from secondary
	if (ACK) { TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN); } // Initiate Read with ACK -- write 1 to TWINT to clear it and initiate action, and set TWEA and TWEN
	else { TWCR = (1 << TWINT) | (1 << TWEN); } // Initiate Read with NO_ACK-- write 1 to TWINT to clear it and initiate action, and set TWEN
		
	while (!(TWCR & (1 << TWINT))); // Wait for action to finish (poll TWINT bit)

	return(TWDR);
}