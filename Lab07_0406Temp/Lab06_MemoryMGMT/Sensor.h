#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Sensor{
public:
	virtual void initialize()=0;
	virtual void finalize()=0;
	virtual void sense()=0;
	virtual int getState()=0;
};

#endif

