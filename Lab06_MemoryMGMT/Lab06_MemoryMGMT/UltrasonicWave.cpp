#include "UltrasonicWave.h"
#include "Globals.h"

UltrasonicWave::UltrasonicWave(EChannelId eIdTransmitter, Channel *pChannelTransmitter,
	EChannelId eIdReceiver, Channel *pChannelReceiver) {
	this->pChannels[eIdTransmitter] = pChannelTransmitter;
	this->pChannels[eIdReceiver] = pChannelReceiver;
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

void UltrasonicWave::sense() {
	if (micros() - this->startTime_ > MJUC_TIME_OUT_OF_MEASURING_IN_MICROSECOND) {
		this->elapsedTime_ = 0;
		this->initUSS();
		return;
	}

	if (this->eState == EState::eWaitForDeviceReady) {
		if (micros() - this->startTime_ > MIN_WAIT_TIME) {
			this->pChannels[eIdTransmitter]->write(LOW);
			this->eState = EState::eWaitForMeasuring;
		}
	}
	else if (this->eState == EState::eWaitForMeasuring) {
		if (this->pChannels[eIdReceiver]->read() == HIGH) {
			this->startTime_ = micros();
			this->eState = EState::eMeasuring;
		}
	}
	else if (this->eState == EState::eMeasuring) {
		if (this->pChannels[eIdReceiver]->read() == LOW) {
			this->elapsedTime_ = micros() - this->startTime_;
			this->initUSS();
		}
	}
}

int UltrasonicWave::getState() {
	int distance = this->elapsedTime_ / MJUC_DIVISOR_FOR_DISTANCE_CALCULATION;

	if (distance < MJUC_DISTANCE_TOO_CLOSE) {
		return EDistanceState::eTooClose;
	}
	else if (distance < MJUC_DISTANCE_VERY_CLOSE) {
		return EDistanceState::eVeryClose;
	}
	else if (distance < MJUC_DISTANCE_CLOSE) {
		return EDistanceState::eClose;
	}
	else if (distance < MJUC_DISTANCE_FAR) {
		return EDistanceState::eFar;
	}
	else if (distance < MJUC_DISTANCE_VERY_FAR) {
		return EDistanceState::eVeryFar;
	}
	return EDistanceState::eUnknown;
}
