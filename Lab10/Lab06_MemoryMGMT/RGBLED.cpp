#include "RGBLED.h"
#include "Globals.h"

RGBLED::RGBLED(int rPinNum, int gPinNum, int bPinNum) : rChannel(rPinNum, OUTPUT), gChannel(gPinNum, OUTPUT), bChannel(bPinNum, OUTPUT){
	this->pChannels[eIdRed] = &rChannel;
	this->pChannels[eIdGreen] = &gChannel;
	this->pChannels[eIdBlue] = &bChannel;
	rgbValues[ELightState::eBright][EDistanceState::eVeryClose]._R = MJUC_LED_STRENGTH_STRONG;
	rgbValues[ELightState::eBright][EDistanceState::eClose]._G = MJUC_LED_STRENGTH_STRONG;
	rgbValues[ELightState::eBright][EDistanceState::eFar]._G = MJUC_LED_STRENGTH_STRONG;
	rgbValues[ELightState::eBright][EDistanceState::eVeryFar]._B = MJUC_LED_STRENGTH_STRONG;
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
	this->pChannels[eIdRed]->write(this->rgbValues[this->eLishtStateIndex_][this->eDistanceStateIndex_]._R);
	this->pChannels[eIdGreen]->write(this->rgbValues[this->eLishtStateIndex_][this->eDistanceStateIndex_]._G);
	this->pChannels[eIdBlue]->write(this->rgbValues[this->eLishtStateIndex_][this->eDistanceStateIndex_]._B);
}

void RGBLED::setState(int eLishtStateIndex, int eDistanceStateIndex) {
	this->eLishtStateIndex_ = eLishtStateIndex;
	this->eDistanceStateIndex_ = eDistanceStateIndex;
}
