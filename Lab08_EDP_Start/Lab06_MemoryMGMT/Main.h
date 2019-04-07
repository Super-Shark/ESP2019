#ifndef _MAIN_h
#define _MAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SensorComponent.h"
#include "ActuatorComponent.h"
#include "Globals.h"

#include "Illuminant.h"
#include "Illuminant_MT.h"

#include "UltrasonicWave.h"
#include "USS_MT.h"

#include "RGBLED.h"
#include "RGBLED_MT.h"

class Main{
public:
	
private:
	int nowSave = 0;
	int nowRead = 0;
	int nowAct = 0;
	typedef struct _MSG {
		boolean on = false;
		int type = 0;
		int	state = 0;
	} MSG;
	MSG msgs[MSG_NUM];

	enum ESC {
		eIlluminant,
		eUSS,
		eNumSC
	};
	SensorComponent Illuminant_SC, USS_SC;
	SensorComponent *scs[eNumSC];

	enum EAC {
		eRGBLED,
		eNumAC
	};
	ActuatorComponent RGBLED_AC;
	ActuatorComponent *acs[eNumAC];
	
public:
	Main() :
		Illuminant_SC(light, new Illuminant(MJUC_CHANNEL_ILLUMINANT), light_Time, new IlluminantMT()),
		USS_SC(Distance, new UltrasonicWave(MJUC_CHANNEL_USS_TRIG, MJUC_CHANNEL_USS_ECHO), Distance_Time, new USSMT()),
		RGBLED_AC(new RGBLED(MJUC_CHANNEL_RGBLED_RED, MJUC_CHANNEL_RGBLED_GREEN, MJUC_CHANNEL_RGBLED_BLUE), new RGBLED_MT())
	{
		scs[eIlluminant] = &Illuminant_SC;
		scs[eUSS] = &USS_SC;

		acs[eRGBLED] = &RGBLED_AC;
	}
	~Main() {}

	void initialize() {
		for (SensorComponent* sc : this->scs) {
			sc->initialize();
		}
		for (ActuatorComponent* ac : this->acs) {
			ac->initialize();
		}
	}

	void finalize() {
		for (SensorComponent* sc : this->scs) {
			sc->finalize();
		}
		for (ActuatorComponent* ac : this->acs) {
			ac->finalize();
		}
	}

	void run() {
		pinMode(2, OUTPUT);
		
		while (true) {

			for (SensorComponent* sc : this->scs) {
				if (sc->ready()) {
					generateMSG(sc);
				}
			}
			for (ActuatorComponent* ac : this->acs) {
				if (msgs[nowRead].on) {
					ac->takeMSG(msgs[nowRead].type, msgs[nowRead].type);
					msgs[nowRead].on = false;
				}
			}
			nowRead++;
			if (nowRead = MSG_NUM) {
				nowAct = 0;
			}

			acs[nowAct]->act();
			nowAct++;
			if (nowAct = eNumAC) {
				nowAct = 0;
			}
		}
	}

	void generateMSG(SensorComponent* sc) {
		MSG newMSG;
		newMSG.on = true;
		newMSG.type = sc->getType();
		newMSG.state = sc->getState();
		msgs[nowSave] = newMSG;
		nowSave++;
		if (nowSave = MSG_NUM) {
			nowSave = 0;
		}
	}
};

#endif