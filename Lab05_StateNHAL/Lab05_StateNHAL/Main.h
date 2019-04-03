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
#include "LEDManager.cpp"

//Iluminant
#define _ANALOG_PIN_NUM_FOR_ILLUMINANT				    0

//Ultra Sonic
#define _DIGITAL_PIN_NUM_FOR_ULTRASONIC_VCC				7
#define _DIGITAL_PIN_NUM_FOR_ULTRASONIC_ECHO			6

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
		ledManager(illuminant, ultrasonicWave)
	{
		this->sensors[eIlluminant] = &illuminant;
		this->sensors[eUltraSonic] = &ultrasonicWave;

		this->domains[eLEDManager] = &ledManager;
	}
	~Main() {}
	void initialize() {
		for (Sensor *sensor : this->sensors) {
			sensor->initialize();
		}
		for (Domain *domian : this->domains) {
			domian->initialize();
		}
	}
	void finalize() {
		for (Sensor *sensor : this->sensors) {
			sensor->finalize();
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
		}
	}
};

#endif