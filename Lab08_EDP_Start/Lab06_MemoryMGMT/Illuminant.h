#ifndef _ILLUMINANT_h
#define _ILLUMINANT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"
#include "AnalogChannel.h"

class Illuminant: public Sensor{
public:
private:
	AnalogChannel channel;
public:
	Illuminant(int pinNum);
	~Illuminant();
	void initialize();
	void finalize();
	int getVal();
};

#endif

