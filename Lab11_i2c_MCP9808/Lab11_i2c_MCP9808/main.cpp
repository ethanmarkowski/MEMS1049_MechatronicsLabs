/*
 * Lab11_i2c_MCP9808.cpp
 *
 * Created: 7/22/2021 11:55:04 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "Timer0.h"
#include "LedDisplay.h"
#include "MCP9808.h"

float test;

int main()
{
	Timer0 timer;
	LedDisplay display;
	MCP9808 tempSensor;
	
	display.Setup();
	tempSensor.Setup();

	while (1)
	{
		test = tempSensor.Read();
		//display.On();
		//
		//display.Write(2, 0);
		//display.Write(1, 7);
		//timer.Delay(500);
		//
		//display.Write(2, 2);
		//display.Write(1, 0);
		//timer.Delay(500);
		//
		//display.Off();
		//timer.Delay(1000);
	}
}