#ifndef _DEVICE_h
#define _DEVICE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Device {
public:
	virtual void initialize() = 0;
	virtual void finalize() = 0;
};

#endif


