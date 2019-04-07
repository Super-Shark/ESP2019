#include "SC_Illuminant.h"

SC_Illuminant::SC_Illuminant(int pinNum, int time) : illuminant(pinNum){}
SC_Illuminant::~SC_Illuminant() {}

void SC_Illuminant::initialize() {
	this->illuminant.initialize();
}

void SC_Illuminant::finalize() {
	this->illuminant.finalize();
}

bool SC_Illuminant::ready() {//time check

}

void SC_Illuminant::sense() {//sense
	this->illuminant.sense();
	this->light = this->illuminant.getVal();
}

void SC_Illuminant::process() {//mapping

}