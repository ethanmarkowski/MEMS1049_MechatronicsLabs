/*
 * Button.h
 *
 * Created: 7/12/2021 5:25:20 PM
 * Author: Ethan Markowski
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>

class Button
{
public:
	// Setup button
	void Setup() const;
	
	// Return button state
	bool IsPressed() const;
};

#endif