#include "ActuatorComponent.h"
#include "Globals.h"

ActuatorComponent::ActuatorComponent(Actuator* actuator, ActuatorMT * mt) : actuator(actuator), mt(mt){}
ActuatorComponent::~ActuatorComponent() {}

void ActuatorComponent::initialize() {
	this->actuator->initialize();
}

void ActuatorComponent::finalize() {
	this->actuator->finalize();
}

void ActuatorComponent::act() {
	this->actuator->setState(this->mt->getState());
	this->actuator->actuate();
}

void ActuatorComponent::takeMSG(int type, int state) {
	this->mt->takeMSG(type, state);
}
