#ifndef _COMPONENT_h
#define _COMPONENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Component
{
public:
	virtual void initialize()=0;
	virtual void finalize()=0;
	virtual void run()=0;
	virtual void start()=0;
	virtual bool wait()=0;
	virtual void sense()=0;
	virtual void process()=0;
	virtual void actuate()=0;
};

#endif