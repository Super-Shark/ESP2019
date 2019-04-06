#ifndef _ULTRASONICWAVE_h
#define _ULTRASONICWAVE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Sensor.h"
#include "DigitalChannel.h"

class UltrasonicWave : public Sensor{
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
	DigitalChannel trigChannel, echoChannel;
	Channel *pChannels[eNumChannelIds];
	unsigned long startTime_, elapsedTime_;
public:
	UltrasonicWave(int trigPinNum, int echoPinNum);
	~UltrasonicWave();
	void initialize();
	void finalize();
	void sense();
	void initUSS();
	int getState();
};

#endif
