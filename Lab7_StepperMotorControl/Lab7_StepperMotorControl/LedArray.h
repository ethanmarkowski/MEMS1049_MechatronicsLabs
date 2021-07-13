/*
 * LedArray.h
 *
 * Created: 7/12/2021 5:25:28 PM
 * Author: Ethan Markowski
 */ 

#ifndef _LedArray_h
#define _LedArray_h

#include <avr/io.h>

class LedArray
{
public:	

	// Setup led array
	void Setup() const;
	
	// Set index of led array (between 0 and 1, or -1 to turn off LEDs)
	void SetIndex(int8_t index) const;
};

#endif