/*
 * StepperMotor.cpp
 *
 * Created: 7/12/2021 6:48:29 PM
 *  Author: Ethan Markowski
 */ 

#include "StepperMotor.h"
#include <stdlib.h>

// Set the angle between steps and initialize the phase step number
StepperMotor::StepperMotor(float stepAngle) : _stepAngle(stepAngle), _phaseStep(0) {}

// Setup registers
void StepperMotor::Setup() const
{
	DDRD = 0xFF; // Set Port D to output
	PORTD = 0x00; // Set initial state of H-Bridge inputs
}

// Step a single step clockwise
void StepperMotor::StepCW()
{
	switch (_phaseStep)
	{
		case 0:
		PORTD = 0b00000001;
		_phaseStep = 1;
		break;
		
		case 1:
		PORTD = 0b00001000;
		_phaseStep = 2;
		break;
		
		case 2:
		PORTD = 0b00000010;
		_phaseStep = 3;
		break;
		
		case 3:
		PORTD = 0b00000100;
		_phaseStep = 0;
		break;
	}
}

// Step a single step counter-clockwise
void StepperMotor::StepCCW()
{
	switch (_phaseStep)
	{
		case 0:
		PORTD = 0b00000001;
		_phaseStep = 3;
		break;
		
		case 1:
		PORTD = 0b00001000;
		_phaseStep = 0;
		break;
		
		case 2:
		PORTD = 0b00000010;
		_phaseStep = 1;
		break;
		
		case 3:
		PORTD = 0b00000100;
		_phaseStep = 2;
		break;
	}
}

// Move motor the specified number of degrees (positive is clockwise, negative is counter-clockwise) using the specified delay interval between steps
 void StepperMotor::Step(float angle, uint8_t stepDelay)
 {	
	 // Calculate number of steps needed based on desired angular displacement and angle between steps		 
	 for (uint16_t steps = abs(angle / _stepAngle); steps > 0; --steps)
	 {
		 // Set direction based on the sign of the angle parameter
		 if (angle > 0) { StepCW(); }
		 else { StepCCW(); }

		 Delay(stepDelay);
	 }
 }
