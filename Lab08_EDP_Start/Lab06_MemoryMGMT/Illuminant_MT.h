#ifndef _ILLMINANT_MT_h
#define _ILLMINANT_MT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorMT.h"
#include "Globals.h"

class IlluminantMT : public SensorMT {
public:
	int getState(int val) {
		/*if (val > MJUC_LIGHT_DISTINCTION) {
			digitalWrite(2, HIGH);
		}
		else {
			digitalWrite(2, LOW);
		}*/
		return val > MJUC_LIGHT_DISTINCTION ? ELightState::eDark : ELightState::eBright;
	}
};

#endif