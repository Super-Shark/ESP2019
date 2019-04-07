#include "Timer.h"

Timer::Timer(int interval) : interval(interval) {}
Timer::~Timer() {}

void Timer::initialize() {
	this->startTime = micros();
}
void Timer::finalize() {}

bool Timer::isTime() {
	boolean result = false;
	if (micros() - startTime > interval) {
		result = true;
		startTime = micros();
	}
	return result;
}