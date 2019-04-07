#ifndef _SENSOR_COMPONENT_h
#define _SENSOR_COMPONENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"
#include "Timer.h"
#include "SensorMT.h"

class SensorComponent {
private:
	Sensor* sensor;
	Timer timer;
	SensorMT * mt;
	int type;
public:
	SensorComponent(int type, Sensor* sensor, int interval, SensorMT * mt);
	~SensorComponent();
	void initialize();
	void finalize();

	bool ready();
	int getType();
	int getState();
};

#endif