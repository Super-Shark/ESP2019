#ifndef _ACTUATOR_COMPONENT_h
#define _ACTUATOR_COMPONENT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Actuator.h"
#include "Timer.h"
#include "ActuatorMT.h"

class ActuatorComponent {
private:
	Actuator* actuator;
	ActuatorMT * mt;
public:
	ActuatorComponent(Actuator* actuator, ActuatorMT * mt);
	~ActuatorComponent();
	void initialize();
	void finalize();
	void act();
	void takeMSG(int type, int state);
};

#endif