#ifndef _MAIN_h
#define _MAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

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
	{
	}
	~Main() {}

	void initialize() {
		/*s = &Illuminant(MJUC_CHANNEL_ILLUMINANT);
		sMT = new IlluminantMT();*/
		this->Illuminant_SC.initialize();
	}

	void finalize() {
	}

	void run() {
		while (true) {
			pinMode(2, OUTPUT);
			if (ELightState::eBright==this->Illuminant_SC.getState()) {
				digitalWrite(2, HIGH);
			}
			else {
				digitalWrite(2, LOW);
			}
			//else {}
		}
	}
};

#endif