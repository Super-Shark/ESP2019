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
		return val > MJUC_LIGHT_DISTINCTION ? ELightState::eDark : ELightState::eBright;
	}
};

#endif