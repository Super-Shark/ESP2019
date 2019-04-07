#ifndef _CHANNEL_h
#define _CHANNEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Channel {
protected:
	int pinNum_, pinType_;
public:
	Channel(int pinNum, int type) : pinNum_(pinNum), pinType_(type) {
		pinMode(pinNum_, pinType_);
	}
	~Channel() {}
	virtual void initialize()= 0;
	virtual void finalize() = 0;

	virtual int read() = 0;
	virtual void write(int toWrite) = 0;
};

#endif
