/*
 * Lab8_AsyncSerial_TX.cpp
 *
 * Created: 7/18/2021 2:48:18 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "AnalogSensor.h"
#include "Usart.h"

int main(void)
{
	AnalogSensor pot;
	Usart usart;
	
	pot.Setup();
	usart.Setup();
	usart.EnableTx();
	
    while (1)
    {
	    if (usart.IsAvailable()) { usart.Write(pot.AnalogRead()); }
    }
}
