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

int main()
{
	Timer0 timer;
	LedDisplay display;
	MCP9808 tempSensor;
	
	display.Setup();
	tempSensor.Setup();
	
	display.On();

	while (1)
	{
		// Read temperature sensor and cast reading as 8-bit integer
		uint8_t temperature = tempSensor.Read();
		
		// Write temperature to LCD display
		display.Write(2, temperature / 10);
		display.Write(1, temperature - 10 * (temperature / 10));

		// Delay 1 second
		timer.Delay(1000);
	}
}