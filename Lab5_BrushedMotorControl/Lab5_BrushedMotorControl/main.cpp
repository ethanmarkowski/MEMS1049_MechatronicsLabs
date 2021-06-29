/*
 * Lab5_BrushedMotorControl.cpp
 *
 * Created: 6/28/2021 2:57:22 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "MotorController.h"

int main(void)
{
	Motorcontroller controller;
	controller.Setup();
	uint8_t slow = 125;
	
	enum States { REVERSE_FAST, REVERSE_SLOW, STOPPED, FORWARD_SLOW, FORWARD_VARIABLE } state = STOPPED;
	
	while (1)
	{		
		// Read potentiometer and button and update program state
		uint8_t input = controller.AnalogRead();
		switch (input / (0xFF / 5))
		{
			case 0:
			(controller.ButtonRead()) ? state = REVERSE_SLOW : state = REVERSE_FAST;
			break;
			
			case 1:
			(controller.ButtonRead()) ? state = STOPPED : state = REVERSE_SLOW;
			break;
			
			case 2:
			state = STOPPED;
			break;
			
			case 3:
			(controller.ButtonRead()) ? state = STOPPED : state = FORWARD_SLOW;
			break;
			
			case 4:
			(controller.ButtonRead()) ? state = FORWARD_SLOW : state = FORWARD_VARIABLE;
			break;
		}
		
		// Update LED array
		controller.LedWrite(state);
		
		// Program states
		switch (state)
		{
			case REVERSE_FAST:
			controller.SetMotor(255, Motorcontroller::REVERSE);
			break;
			
			case REVERSE_SLOW:
			controller.SetMotor(slow, Motorcontroller::REVERSE);
			break;
			
			case STOPPED:
			controller.SetMotor(0, Motorcontroller::STOPPED);
			break;
			
			case FORWARD_SLOW:
			controller.SetMotor(slow, Motorcontroller::FORWARD);
			break;
			
			case FORWARD_VARIABLE:
			controller.SetMotor((input - (255 * 4 / 5)) * 5, Motorcontroller::FORWARD);
			break;
		}
	}
}