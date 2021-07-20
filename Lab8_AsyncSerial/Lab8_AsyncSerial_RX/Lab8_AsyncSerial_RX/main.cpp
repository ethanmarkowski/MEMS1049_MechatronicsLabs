/*
 * Lab8_AsyncSerial_RX.cpp
 *
 * Created: 7/18/2021 2:48:57 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "Pwm.h"
#include "Usart.h"

int main(void)
{
	Pwm led(true);
    Usart usart;
	
	led.Setup();
	usart.Setup();
	usart.EnableRx();
	
    while (1) 
    {
		if (usart.IsReceived()) { led.Write(usart.Read()); }
    }
}