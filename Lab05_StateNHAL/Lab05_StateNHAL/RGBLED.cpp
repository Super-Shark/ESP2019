#ifndef _RGBLED_h
#define _RGBLED_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Actuator.h"
#include "Channel.h"
#include "AnalogChannel.h"

class RGBLED : public Actuator {
public:
	enum EChannelId {
		eIdRed,
		eIdGreen,
		eIdBlue,
		eNumChannelIds
	};
private:
	AnalogChannel rOutChannel, gOutChannel, bOutChannel;
	Channel *pChannels[eNumChannelIds];
	int _R, _G, _B;
public:
	RGBLED(int rPinNum, int gPinNum, int bPinNum) : rOutChannel(rPinNum, OUTPUT), gOutChannel(gPinNum, OUTPUT), bOutChannel(bPinNum, OUTPUT) {
		this->pChannels[eIdRed] = &rOutChannel;
		this->pChannels[eIdGreen] = &gOutChannel;
		this->pChannels[eIdBlue] = &bOutChannel;
	}
	~RGBLED() {}
	void initialize() {
		for (Channel *pChannel : this->pChannels) {
			pChannel->initialize();
		}
	}
	void finalize() {
		for (Channel *pChannel : this->pChannels) {
			pChannel->finalize();
		}
	}

	bool act() {
		_R = 255;
		_G = 0;
		_B = 0;
		this->pChannels[eIdRed]->write(this->_R);
		this->pChannels[eIdGreen]->write(this->_G);
		this->pChannels[eIdBlue]->write(this->_B);
	}
	void setRGBValue(int R, int G, int B) {
		this->_R = R;
		this->_G = G;
		this->_B = B;
	}
};
#endif

