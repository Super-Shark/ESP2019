#ifndef _MAIN_h
#define _MAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

//#include "LEDManager.h"

#include "SensorComponent.h"
#include "Globals.h"

#include "Illuminant.h"
#include "Illuminant_MT.h"

class Main{
private:
	//LEDManager ledManager;
	SensorComponent Illuminant_SC;

public:
	Main() : // type, sensor, time interval, mapping table
		Illuminant_SC(light, new Illuminant(MJUC_CHANNEL_ILLUMINANT), 10, new IlluminantMT())
	{}
	~Main() {}

	void initialize() {
		Serial.begin(9600);
		this->Illuminant_SC.initialize();
		//this->ledManager.initialize();
	}

	void finalize() {
		//this->ledManager.finalize();
	}

	void run() {
		while (true) {
			if (ELightState::eBright==this->Illuminant_SC.getState()) {
				Serial.begin(1);
			}
			//this->ledManager.run();
		}
	}
};

#endif