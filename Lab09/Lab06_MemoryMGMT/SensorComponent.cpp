#include "SensorComponent.h"
#include "Globals.h"

SensorComponent::SensorComponent(int type, Sensor* sensor, int interval, SensorMT * mt) : type(type), sensor(sensor), timer(interval), mt(mt){}
SensorComponent::~SensorComponent() {}

void SensorComponent::initialize() {
	this->sensor->initialize();
	this->timer.initialize();
}

void SensorComponent::finalize() {
	this->sensor->finalize();
	this->timer.finalize();
}

bool SensorComponent::ready() {
	return this->timer.isTime();
}

int SensorComponent::getType() {
	return this->type;
}

int SensorComponent::getState() {
	return this->mt->getState(this->sensor->getVal());
}
