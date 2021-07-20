/*
 * Lab10_SPI_7Segment.cpp
 *
 * Created: 7/20/2021 9:41:55 AM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "Timer0.h"
#include "LedDisplay.h"

int main(void)
{
	Timer0 timer;
	LedDisplay display;
	
	display.Setup();

    while (1) 
    {
		display.On();
		
		display.Write(2, 0);
		display.Write(1, 7);
		timer.Delay(500);
		
		display.Write(2, 2);
		display.Write(1, 0);
		timer.Delay(500);
		
		display.Off();
		timer.Delay(1000);
    }
}