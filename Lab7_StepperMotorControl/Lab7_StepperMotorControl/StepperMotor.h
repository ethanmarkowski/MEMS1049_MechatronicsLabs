/*
 * StepperMotor.h
 *
 * Created: 7/12/2021 6:47:23 PM
 *  Author: Ethan Markowski
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include <avr/io.h>
#include "Timer0.h"

class StepperMotor : protected Timer0
{
private:
	float _stepAngle;
	uint8_t _phaseStep;
	
	// Move motor a single step clockwise
	void StepCW();
	
	// Move motor a single step counter-clockwise
	void StepCCW();

public:
	StepperMotor(float stepAngle);
	
	// Setup registers
	void Setup() const;
	
	// Move motor the specified number of degrees (positive is clockwise, negative is counter-clockwise) using the specified delay interval between steps
	void Step(float angle, uint8_t stepDelay);
};

#endif