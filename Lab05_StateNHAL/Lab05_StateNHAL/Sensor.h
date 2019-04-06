#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

	#include "Device.h"

class Sensor : public Device {
public:
	int val;
	virtual void initialize()=0;
	virtual void finalize()=0;
	virtual void sense()=0;
	int getVal() {
		return val;
	}
};

#endif
