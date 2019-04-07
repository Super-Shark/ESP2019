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

class RGBLED : public Actuator{
public:
	enum EChannelId {
		eIdRed,
		eIdGreen,
		eIdBlue,
		eNumChannelIds
	};
	int Rvalue=0;
	int Gvalue =0;
	int Bvalue =0;
private:
	AnalogChannel rChannel, gChannel, bChannel;
	Channel *pChannels[eNumChannelIds];
public:
	RGBLED(int rPinNum, int gPinNum, int bPinNum);
	~RGBLED();
	void initialize();
	void finalize();
	void actuate();
	void setState(int state);
	void setValue(int r, int g, int b);
};
#endif
