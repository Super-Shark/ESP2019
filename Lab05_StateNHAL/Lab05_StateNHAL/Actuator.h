#ifndef _ACTUATOR_h
#define _ACTUATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

    #include "Device.h"

class Actuator : public Device {
public:
	virtual void initialize()=0;
	virtual void finalize()=0;
	virtual bool act()=0;
};

#endif

