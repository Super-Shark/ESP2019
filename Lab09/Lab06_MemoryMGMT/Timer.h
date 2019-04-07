#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class Timer {
public:
private:
	int interval, startTime;
public:
	Timer(int interval);
	~Timer();
	void initialize();
	void finalize();
	bool isTime();
};

#endif