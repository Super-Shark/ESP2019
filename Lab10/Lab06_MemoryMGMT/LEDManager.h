#ifndef _LEDMANAGER_h
#define _LEDMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "AnalogChannel.h"
#include "DigitalChannel.h"
#include "Illuminant.h"
#include "UltrasonicWave.h"
#include "RGBLED.h"

class LEDManager{
public:
	enum EState {
		eReady,
		eRunning,
		eNumStates
	};
private:
	EState eState;

	Illuminant illuminant;
	//UltrasonicWave ultrasonicWave;

	RGBLED rgbLED;

	Sensor* arrSensor[2];
	Actuator* arrActuator[1];

public:
	LEDManager();
	~LEDManager();
	void initialize();
	void finalize();
	void run();
	void start();
	bool wait();
	void sense();
	void process();
	void actuate();
};

#endif

