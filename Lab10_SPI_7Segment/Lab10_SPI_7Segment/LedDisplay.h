/*
 * LedDisplay.h
 *
 * Created: 7/20/2021 10:52:35 AM
 *  Author: Ethan Markowski
 */ 


#ifndef LEDDISPLAY_H_
#define LEDDISPLAY_H_

#include <avr/io.h>
#include "Spi.h"

class LedDisplay
{
private:
	Spi _spi;	
	
public:
	// Set up two 7-segment LED displays
	void Setup() const;
	
	// Turn off displays
	void Off() const;
	
	// Turn on displays
	void On() const;
	
	// Set the specified display to the desired digit
	void Write(uint8_t index, uint8_t value) const;
};

#endif