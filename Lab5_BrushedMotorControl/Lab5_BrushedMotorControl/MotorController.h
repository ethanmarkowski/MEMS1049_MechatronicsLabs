// MotorController.h

#ifndef _MotorController_h
#define _MotorController_h

#include <avr/io.h>

class Motorcontroller
{
private:
	void PortBSetup() const;
	void PortCSetup() const;
	void PortDSetup() const;
	
public:
	enum Mode { STOPPED, REVERSE, FORWARD };
		
	void Setup() const;
	void LedWrite(uint8_t index) const;
	uint8_t AnalogRead() const;
	bool ButtonRead() const;
	void SetMotor(uint8_t speed, Mode mode) const;
};

#endif