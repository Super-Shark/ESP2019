// LEDManager.h

#ifndef _LEDMANAGER_h
#define _LEDMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Component.h"
#include "AnalogChannel.h"
#include "DigitalChannel.h"
#include "Illuminant.h"
#include "UltrasonicWave.h"
#include "RGBLED.h"

class LEDManager: public Component
{
public:
	enum EState {
		eReady,
		eRunning,
		eNumStates
	};
private:
	EState eState;

	AnalogChannel illuminantChannel;//Input

	DigitalChannel ultrasonicWaveChannelTransmitter;//Output
	DigitalChannel ultrasonicWaveChannelReceiver;//Input

	AnalogChannel rgbLEDchannelRed;//Output
	AnalogChannel rgbLEDchannelGreen;//Output
	AnalogChannel rgbLEDchannelBlue;//Output

	Illuminant illuminant;
	UltrasonicWave ultrasonicWave;

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

