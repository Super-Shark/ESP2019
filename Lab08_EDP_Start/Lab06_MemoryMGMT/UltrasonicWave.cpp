#include "UltrasonicWave.h"
#include "Globals.h"

UltrasonicWave::UltrasonicWave(int trigPinNum, int echoPinNum) : trigChannel(trigPinNum, OUTPUT), echoChannel(echoPinNum, INPUT) {
	this->pChannels[eIdTransmitter] = &trigChannel;
	this->pChannels[eIdReceiver] = &echoChannel;
}
UltrasonicWave::~UltrasonicWave() {}

void UltrasonicWave::initialize() {
	for (Channel *pChannel : this->pChannels) {
		pChannel->initialize();
	}
	this->initUSS();
}

void UltrasonicWave::finalize() {
	for (Channel *pChannel : this->pChannels) {
		pChannel->finalize();
	}
}

void UltrasonicWave::initUSS() {
	this->pChannels[eIdTransmitter]->write(HIGH);
	this->startTime_ = micros();
	this->eState = EState::eWaitForDeviceReady;
}

int  UltrasonicWave::getVal() {
	if (micros() - this->startTime_ > MJUC_TIME_OUT_OF_MEASURING_IN_MICROSECOND) {
		this->elapsedTime_ = 0;
		this->initUSS();
		return 0;
	}

	if (this->eState == EState::eWaitForDeviceReady) {
		if (micros() - this->startTime_ > WAIT_TIME) {
			this->pChannels[eIdTransmitter]->write(LOW);
			this->eState = EState::eWaitForMeasuring;
		}
	}else if (this->eState == EState::eWaitForMeasuring) {
		if (this->pChannels[eIdReceiver]->read() == HIGH) {
			this->startTime_ = micros();
			this->eState = EState::eMeasuring;
		}
	}else if (this->eState == EState::eMeasuring) {
		if (this->pChannels[eIdReceiver]->read() == LOW) {
			this->elapsedTime_ = micros() - this->startTime_;
			this->initUSS();
			return this->elapsedTime_;
		}
	}
	return 0;
}


