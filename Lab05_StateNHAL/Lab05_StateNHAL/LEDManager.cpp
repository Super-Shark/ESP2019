#ifndef _LEDMANAGER_
#define _LEDMANAGER_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Domain.h"

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
	RGBLED *rgbLED;
public:
	LEDManager(Sensor &illuminantSensor, Sensor &ultrasonicWaveSensor): lightSensor (&illuminantSensor), proximitySensor(&ultrasonicWaveSensor){}
	~LEDManager(){}
	void initialize() {}
	void finalize() {}

	void process() {
		int lightFactor = lightSensor->getVal() > BRIGHT ? 1 : DARK_LEVEL;
		int distance = proximitySensor->getVal() / CM_FACTOR;

		if (distance < DISTANCE_LEVEL_1) {
			rgbLED.setRGBValue(0, 0, 0);
		}else if (distance < DISTANCE_LEVEL_2) {
			rgbLED.setRGBValue(255 / lightFactor, 0, 0);
		}else if (distance < DISTANCE_LEVEL_3) {
			rgbLED.setRGBValue(0, 255 / lightFactor, 0);
		}else {
			rgbLED.setRGBValue(0, 0, 0);
		}
	}
	void order() {
		if (this->rgbLED.wait()) {
			this->rgbLED.start();
		}
	}
	void run() {
		this->process();
		this->order();
	}
};

#endif

