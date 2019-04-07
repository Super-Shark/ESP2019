#ifndef _USS_MT_h
#define _USS_MT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorMT.h"
#include "Globals.h"

class USSMT : public SensorMT {
public:

	int getState(int val) {
	if (val < MJUC_DISTANCE_CLOSE) {
		return EDistanceState::eClose;
	}else if (val < MJUC_DISTANCE_FAR) {
		return EDistanceState::eFar;
	}else if (val < MJUC_DISTANCE_VERY_FAR) {
		digitalWrite(2, HIGH);
		return EDistanceState::eVeryFar;
	}
		return EDistanceState::eUnknown;
	}
};

#endif