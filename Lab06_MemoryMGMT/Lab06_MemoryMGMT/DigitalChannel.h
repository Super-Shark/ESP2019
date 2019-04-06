#ifndef _DIGITALCHANNEL_h
#define _DIGITALCHANNEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Channel.h"

class DigitalChannel : public Channel
{
public:
	DigitalChannel(int pinNum, int type) : Channel(pinNum, type) {}
	~DigitalChannel() {}
	void initialize() {}
	void finalize() {}

	int read() {
		return digitalRead(Channel::pinNum_);
	}
	void write(int toWrite) {
		digitalWrite(Channel::pinNum_, toWrite);
	}
};

#endif


