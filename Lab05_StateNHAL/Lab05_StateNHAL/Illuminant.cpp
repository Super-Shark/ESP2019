#ifndef _ILLUMINANT_
#define _ILLUMINANT_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Sensor.h"
#include "AnalogChannel.h"

class Illuminant : public Sensor{
public:
private:
	AnalogChannel inputChannel;
public:
	Illuminant(int pinNum) : inputChannel(pinNum, INPUT) {};
	~Illuminant() {};
	void initialize() {
		this->inputChannel.initialize();
	}
	void finalize() {
		this->inputChannel.finalize();
	}
	void sense() {
		this->val = this->inputChannel.read();
	}
	int getVal2() {
		return this->getVal();
	}
};
#endif
