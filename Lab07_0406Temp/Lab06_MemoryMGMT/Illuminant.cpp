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

void Illuminant::sense() {
	this->cdsLight_ = this->channel.read();
}

int Illuminant::getState() {
	return this->cdsLight_ > MJUC_LIGHT_DISTINCTION ? ELightState::eDark : ELightState::eBright;
}
