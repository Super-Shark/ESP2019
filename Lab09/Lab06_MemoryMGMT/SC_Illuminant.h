#ifndef _SC_ILLUMINANT_h
#define _SC_ILLUMINANT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorComponent.h"
#include "Illuminant.h"

class SC_Illuminant : public SensorComponent {
private:
	//Sensor
	Illuminant illuminant;
	//Timer

	//Map Tab

	int light;
public:
	SC_Illuminant(int pinNum, int time);
	~SC_Illuminant();
	void initialize();
	void finalize();
	bool ready();
	void sense();
	void process();
};

#endif