/*
 * Lab7_StepperMotorControl.cpp
 *
 * Created: 7/12/2021 5:16:05 PM
 * Author : Ethan Markowski
 */ 

#include <avr/io.h>
#include "Timer0.h"
#include "Button.h"
#include "LedArray.h"
#include "StepperMotor.h"

float stepAngle = 7.5; // Angle between steps of stepper motor

Button button;
LedArray leds;
StepperMotor motor(stepAngle);
Timer0 timer0;

// Alternate motor sequence
void altMotor();

int main(void)
{	
	button.Setup();
	leds.Setup();
	motor.Setup();
	
    while (1) 
    {
		if (button.IsPressed())
		{			
			// Rotate stepper motor 180 degrees clockwise in 5 seconds
			for (uint8_t stepCount = 180 / stepAngle; stepCount > 0; --stepCount)
			{
				leds.SetIndex(0);
				motor.Step(7.5, 5000 / (180 / stepAngle));
				
				// Activate alternate motor sequence
				if (button.IsPressed()) { altMotor(); }
			}
			
			// Turn off LED array and wait 1 second
			leds.SetIndex(-1);
			timer0.Delay(1000);
			
			// Rotate stepper motor 360 degrees counter-clockwise in 5 seconds
			for (uint8_t stepCount = 360 / stepAngle; stepCount > 0; --stepCount)
			{
				leds.SetIndex(1);
				motor.Step(-7.5, 5000 / (360 / stepAngle));
				
				// Activate alternate motor sequence
				if (button.IsPressed()) { altMotor(); }
			}
		}
		
		// Turn off LED array
		leds.SetIndex(-1);
    }
}

// Alternate motor sequence
void altMotor()
{	
	// Rotate motor back and forth 45 degrees 3 times in 3 seconds and adjust LED array
	for (uint8_t count = 3; count > 0; --count)
	{
		leds.SetIndex(0);
		motor.Step(45, 3000 / (270 / stepAngle));
		
		leds.SetIndex(1);
		motor.Step(-45, 3000 / (270 / stepAngle));
	}
}