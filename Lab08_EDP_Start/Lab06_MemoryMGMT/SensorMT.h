#ifndef _SensorMT_h
#define _SensorMT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SensorMT {
public:
	virtual int getState(int val)=0;
};

#endif