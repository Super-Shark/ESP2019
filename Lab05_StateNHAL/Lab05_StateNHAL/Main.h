// Main.h

#ifndef _MAIN_h
#define _MAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Illuminant.cpp"
#include "UltrasonicWave.cpp"
#include "RGBLED.cpp"
#include "LEDManager.cpp"

//Iluminant
#define _ANALOG_PIN_NUM_FOR_ILLUMINANT				    0

//Ultra Sonic
#define _DIGITAL_PIN_NUM_FOR_ULTRASONIC_VCC				7
#define _DIGITAL_PIN_NUM_FOR_ULTRASONIC_ECHO			6

//RGBLED
#define _ANALOG_PIN_NUM_FOR_RGBLED_R			        3
#define _ANALOG_PIN_NUM_FOR_RGBLED_G			        10
#define _ANALOG_PIN_NUM_FOR_RGBLED_B			        5

class Main{
private:
	enum ESensor {
		eIlluminant,
		eUltraSonic,
		eNumSeonsors
	};
	Illuminant illuminant;
	UltrasonicWave ultrasonicWave;
	Sensor *sensors[eNumSeonsors];

	enum EActuator {
		eRGBLED,
		eNumActuators
	};
	RGBLED rgbLED;
	Actuator *actuators[eNumActuators];

	enum EDomain {
		eLEDManager,
		eNumDomains
	};
	LEDManager ledManager;
	Domain *domains[eNumDomains];
public:
	Main() : 
		illuminant(_ANALOG_PIN_NUM_FOR_ILLUMINANT),
        ultrasonicWave(_DIGITAL_PIN_NUM_FOR_ULTRASONIC_VCC, _DIGITAL_PIN_NUM_FOR_ULTRASONIC_ECHO),
		rgbLED(_ANALOG_PIN_NUM_FOR_RGBLED_R, _ANALOG_PIN_NUM_FOR_RGBLED_G, _ANALOG_PIN_NUM_FOR_RGBLED_B),
		ledManager(illuminant, ultrasonicWave, rgbLED)
	{
		//Sensor
		this->sensors[eIlluminant] = &illuminant;
		this->sensors[eUltraSonic] = &ultrasonicWave;

		//Actuator
		this->actuators[eRGBLED] = &rgbLED;

		//Domain
		this->domains[eLEDManager] = &ledManager;
	}
	~Main() {}
	void initialize() {
		for (Sensor *sensor : this->sensors) {
			sensor->initialize();
		}
		for (Actuator *actuator : this->actuators) {
			actuator->initialize();
		}
		for (Domain *domian : this->domains) {
			domian->initialize();
		}
	}
	void finalize() {
		for (Sensor *sensor : this->sensors) {
			sensor->finalize();
		}
		for (Actuator *actuator : this->actuators) {
			actuator->finalize();
		}
		for (Domain *domian : this->domains) {
			domian->finalize();
		}
	}
	void run() {
		while (true){
			for (Sensor *sensor : this->sensors) {
				sensor->sense();
			}
			for (Domain *domian : this->domains) {
				domian->run();
			}
			/*for (Actuator *actuator : this->actuators) {
				actuator->act();
			}*/
		}
	}
};

#endif