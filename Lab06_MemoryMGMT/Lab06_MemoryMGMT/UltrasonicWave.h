#ifndef _ULTRASONICWAVE_h
#define _ULTRASONICWAVE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Sensor.h"
#include "Channel.h"

class UltrasonicWave : public Sensor
{
public:
	enum EState {
		eWaitForDeviceReady,
		eWaitForMeasuring,
		eMeasuring,
		eNumStates
	};
	enum EChannelId {
		eIdTransmitter,
		eIdReceiver,
		eNumChannelIds
	};
private:
	EState eState;
	Channel *pChannels[eNumChannelIds];
	unsigned long startTime_;
	unsigned long elapsedTime_;
public:
	UltrasonicWave(EChannelId eIdTransmitter, Channel *pChannelTransmitter,
		EChannelId eIdReceiver, Channel *pChannelReceiver);
	~UltrasonicWave();
	void initialize();
	void finalize();
	void sense();
	void initUSS();
	int getState();
};

#endif
