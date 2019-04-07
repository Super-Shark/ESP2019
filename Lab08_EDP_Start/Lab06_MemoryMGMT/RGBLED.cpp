#include "RGBLED.h"
#include "Globals.h"

RGBLED::RGBLED(int rPinNum, int gPinNum, int bPinNum) : rChannel(rPinNum, OUTPUT), gChannel(gPinNum, OUTPUT), bChannel(bPinNum, OUTPUT){
	this->pChannels[eIdRed] = &rChannel;
	this->pChannels[eIdGreen] = &gChannel;
	this->pChannels[eIdBlue] = &bChannel;
}
RGBLED::~RGBLED() {}

void RGBLED::initialize() {
	for (Channel *pChannel : this->pChannels) {
		pChannel->initialize();
	}
}

void RGBLED::finalize() {
	for (Channel *pChannel : this->pChannels) {
		pChannel->finalize();
	}
}

void RGBLED::actuate() {
	this->pChannels[eIdRed]->write(Rvalue);
	this->pChannels[eIdGreen]->write(Gvalue);
	this->pChannels[eIdBlue]->write(Bvalue);
}

void RGBLED::setValue(int r, int g, int b) {
	Rvalue = r;
	Gvalue = g;
	Bvalue = b;
}

void RGBLED:: setState(int state) {
	if (state == RGBLEDState::eOff) {
		this->setValue(0, 0, 0);
	}
	else if (state == RGBLEDState::eRedOn) {
		this->setValue(255, 0, 0);
	}
	else if (state == RGBLEDState::eGreenOn) {
		this->setValue(0, 255, 0);
	}
	else if (state == RGBLEDState::eBlueOn) {
		this->setValue(0, 0, 255);
	}
}

