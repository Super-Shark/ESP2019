
#include "Channel.h"
#include "DigitalChannel.h"

#define _TIME_OUT				1000000
#define _WAIT_TIME				10

class UltrasonicWave : public Sensor {
public:
	enum EState {
		eWaitForDeviceReady,
		eWaitForMeasuring,
		eMeasuring,
		eNumStates
	};
	enum EChannelId {
		eIdVCC,
		eIdEcho,
		eNumChannelIds
	};
private:
	EState eState;
	DigitalChannel vccChannel;
	DigitalChannel echoChannel;
	Channel *pChannels[eNumChannelIds];
	unsigned long startTime_;
public:
	UltrasonicWave(int vccPinNum, int echoPinNum) : vccChannel(vccPinNum, OUTPUT), echoChannel(echoPinNum, INPUT){
		this->pChannels[eIdVCC] = &vccChannel;
		this->pChannels[eIdEcho] = &echoChannel;
	}
	~UltrasonicWave() {}
	void initialize() {
		for (Channel *pChannel : this->pChannels) {
			pChannel->initialize();
		}
		this->initUSS();
	}
	void finalize() {
		for (Channel *pChannel : this->pChannels) {
			pChannel->finalize();
		}
	}

	void initUSS() {
		this->pChannels[eIdVCC]->write(HIGH);
		this->startTime_ = micros();
		this->eState = EState::eWaitForDeviceReady;
	}
	void sense() {
		if (micros() - this->startTime_ > _TIME_OUT) {
			val = 0;
			this->initUSS();
			return;
		}

	    if (this->eState == EState::eWaitForDeviceReady) {
			if (micros() - this->startTime_ > _WAIT_TIME) {
				this->pChannels[eIdVCC]->write(LOW);
				this->eState = EState::eWaitForMeasuring;
			}
		}else if (this->eState == EState::eWaitForMeasuring) {
			if (this->pChannels[eIdEcho]->read() == HIGH) {
				this->startTime_ = micros();
				this->eState = EState::eMeasuring;
			}
		}else if (this->eState == EState::eMeasuring) {
			if (this->pChannels[eIdEcho]->read() == LOW) {
				val = micros() - this->startTime_;
				this->initUSS();
			}
		}
	}
	unsigned long getElapsedTime() {
		return val;
	}
};


