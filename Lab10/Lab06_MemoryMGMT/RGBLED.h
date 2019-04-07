#ifndef _RGBLED_h
#define _RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Actuator.h"
#include "AnalogChannel.h"
#include "Globals.h"

class RGBLED: public Actuator{
public:
	enum EChannelId {
		eIdRed,
		eIdGreen,
		eIdBlue,
		eNumChannelIds
	};
	typedef struct _RBGValue {
		int _R=0;
		int _G=0;
		int _B=0;
	} RGBValue;
private:
	AnalogChannel rChannel, gChannel, bChannel;
	Channel *pChannels[eNumChannelIds];
	int eLishtStateIndex_, eDistanceStateIndex_;
	RGBValue rgbValues[ELightState::eNumLightStates][EDistanceState::eNumDistanceStates];
public:
	RGBLED(int rPinNum, int gPinNum, int bPinNum);
	~RGBLED();
	void initialize();
	void finalize();
	void actuate();
	void setState(int eLishtStateIndex, int eDistanceStateIndex);
};
#endif
