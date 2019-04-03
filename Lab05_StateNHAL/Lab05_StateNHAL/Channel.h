// Channel.h

#ifndef _CHANNEL_h
#define _CHANNEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Channel{
protected:
	int pinNum_;
	int pinType_;
public:
	Channel(int pinNum, int type) : pinNum_(pinNum), pinType_(type) {}
	~Channel() {}
	void initialize() {
		pinMode(pinNum_, pinType_);//생성자로 옮겨도 되나 확인.
	};
	virtual void finalize()=0;

	virtual int read()=0;
	virtual void write(int toWrite)=0;
};

#endif
