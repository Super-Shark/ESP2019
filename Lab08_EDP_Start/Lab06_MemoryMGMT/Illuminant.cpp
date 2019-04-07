#include "Illuminant.h"
#include "Globals.h"

Illuminant::Illuminant(int pinNum) : channel(pinNum, INPUT){}
Illuminant::~Illuminant() {}

void Illuminant::initialize() {
	this->channel.initialize();
}

void Illuminant::finalize() {
	this->channel.finalize();
}

int Illuminant::getVal() {
	return this->channel.read();
}
