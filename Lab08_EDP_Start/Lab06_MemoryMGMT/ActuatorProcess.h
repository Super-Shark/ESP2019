#ifndef _ACTUATOR_P_h
#define _ACTUATOR_P_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorMT.h"
#include "RGBLED.h"
#include "Globals.h"

class ActuatorProcess {
public:
	virtual void setValue(int state, Actuator* target)=0;
};

#endif