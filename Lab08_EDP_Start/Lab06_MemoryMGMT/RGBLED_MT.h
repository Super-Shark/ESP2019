#ifndef _RGBLED_MT_h
#define _RGBLED_MT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorMT.h"
#include "Globals.h"

class RGBLED_MT : public ActuatorMT {
	int lightState;
	int DistanceState;
public:
	void takeMSG(int type, int state) {
		if (type == light) {
			lightState = state;
		}
		else if (type == Distance) {
			DistanceState = state;
		}
	}
	int getState() {
		if (lightState == ELightState::eBright) {
			if (DistanceState == EDistanceState::eClose) {
				return RGBLEDState::eRedOn;
			}
			else if (DistanceState == EDistanceState::eFar) {
				return RGBLEDState::eGreenOn;
			}
			else if (DistanceState == EDistanceState::eVeryFar) {
				return RGBLEDState::eBlueOn;
			}
			return RGBLEDState::eOff;
		}
		else {
			return RGBLEDState::eOff;
		}
	}
};

#endif