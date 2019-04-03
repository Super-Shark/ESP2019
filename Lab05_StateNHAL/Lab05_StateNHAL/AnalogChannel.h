#ifndef _ANALOGCHANNEL_h
#define _ANALOGCHANNEL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Channel.h"

class AnalogChannel : public Channel{
public:
	AnalogChannel(int pinNum, int type) : Channel(pinNum, type){}
	~AnalogChannel() {}
	void initialize() {}
	void finalize() {}

	int read() {
		return analogRead(Channel::pinNum_);
	}

	void write(int toWrite) {
		analogWrite(Channel::pinNum_, toWrite);
	}
};
#endif

