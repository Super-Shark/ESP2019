#ifndef _MSG_GENERATOR_h
#define _MSG_GENERATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Globals.h"
#include "SensorComponent.h"

class MSG_generator {
public:
	MSG generateMSG(SensorComponent* sc) {
		MSG newMSG;
		newMSG.type = sc->getType();
		newMSG.state = sc->getState();
		return newMSG;
	}
};

#endif