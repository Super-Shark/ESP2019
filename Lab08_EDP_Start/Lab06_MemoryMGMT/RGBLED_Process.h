#ifndef _RGBLED_P_h
#define _RGBLED_P_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "ActuatorProcess.h"
#include "RGBLED.h"
#include "Globals.h"

class RGBLED_Process : ActuatorProcess {
public:
	void setValue(int state, Actuator* target)
	void setValue(int state, RGBLED* target) {
		if (state == RGBLEDState::eOff) {
			target->setValue(0, 0, 0);
		}
		else if (state == RGBLEDState::eRedOn) {
			target->setValue(255, 0, 0);
		}
		else if (state == RGBLEDState::eGreenOn) {
			target->setValue(0, 255, 0);
		}
		else if(state == RGBLEDState::eBlueOn) {
			target->setValue(0, 0, 255);
		}
	}
};

#endif