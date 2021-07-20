/*
 * LedDisplay.cpp
 *
 * Created: 7/20/2021 10:56:21 AM
 *  Author: Ethan Markowski
 */ 

#include "LedDisplay.h"

// Set up two 7-segment LED displays
void LedDisplay::Setup() const
{
	_spi.Setup();
	_spi.Write(0b00001011, 0b00000011); // Set scanning limit to displays 0 and 1
	_spi.Write(0b00001001, 0b00000011); // Set numeric decoding for displays 0 and 1
}

// Turn off displays
void LedDisplay::Off() const { _spi.Write(0b00001100, 0b00000000); }


// Turn on displays
void LedDisplay::On() const { _spi.Write(0b00001100, 0b00000001); }

// Set the specified display to the desired digit
void LedDisplay::Write(uint8_t index, uint8_t value) const
{
	_spi.Write(index, value);
}