/*
 * Lab8_AsyncSerial_TX.cpp
 *
 * Created: 7/18/2021 2:48:18 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "AnalogSensor.h"

uint8_t test;

int main(void)
{
	AnalogSensor pot;
	
	pot.Setup();
	
    while (1) 
    {
		test = pot.AnalogRead();
    }
}

