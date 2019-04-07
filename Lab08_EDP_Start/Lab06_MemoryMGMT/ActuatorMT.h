#ifndef _ActuatorMT_h
#define _ActuatorMT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ActuatorMT {
public:
	virtual int getState() = 0;
	virtual void takeMSG(int type, int state) = 0;
};

#endif