#ifndef _LEDMANAGER_
#define _LEDMANAGER_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Domain.h"
#include "Sensor.h"
#include "Actuator.h"
//#include "RGBLED.cpp"

#define  BRIGHT				                800
#define  DARK_LEVEL				            3
#define  CM_FACTOR				            58.2

#define  DISTANCE_LEVEL_1				    10
#define  DISTANCE_LEVEL_2				    15
#define  DISTANCE_LEVEL_3				    20

class LEDManager : public Domain
{
private:
	Sensor *lightSensor;
	Sensor *proximitySensor;
	Actuator *rgbLED;
public:
	LEDManager(Sensor &illuminantSensor, Sensor &ultrasonicWaveSensor, Actuator &rgbLED) 
		: lightSensor(&illuminantSensor), proximitySensor(&ultrasonicWaveSensor), rgbLED(&rgbLED){}
	~LEDManager() {}
	void initialize() {}
	void finalize() {}

	void process() {
		int lightFactor = lightSensor->getVal() > BRIGHT ? 1 : DARK_LEVEL;
		int distance = proximitySensor->getVal() / CM_FACTOR;

		if (distance < DISTANCE_LEVEL_1) {
			//rgbLED->setRGBValue(0, 0, 0);
		}else if (distance < DISTANCE_LEVEL_2) {
			//rgbLED->setRGBValue(255 / lightFactor, 0, 0);
			rgbLED->act();
		}else if (distance < DISTANCE_LEVEL_3) {
			//rgbLED->setRGBValue(0, 255 / lightFactor, 0);
		}else {
			//rgbLED->setRGBValue(0, 0, 0);
		}
	}
	void act() {
		rgbLED->act();
	}
	void run() {
		this->process();
		this->act();
	}
};

#endif

