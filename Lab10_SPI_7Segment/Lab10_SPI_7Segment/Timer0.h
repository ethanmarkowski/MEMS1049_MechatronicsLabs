/*
 * Timer0.h
 *
 * Created: 7/12/2021 2:21:58 PM
 *  Author: Ethan Markowski
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/io.h>

class Timer0
{
public:
	// Use Timer0 to create a blocking delay for the specified number of milliseconds
	void Delay(volatile uint16_t milliseconds) const;
};

#endif