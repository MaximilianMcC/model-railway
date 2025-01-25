#include "lever.h"

Lever::Lever() {}

//? relayUnit is zero based. relayOpenIndex is not.
Lever::Lever(int pin, int relayUnit, int relayOpenIndex) {

	// TODO: Don't use this
	this->pin = pin;
	this->relayUnit = relayUnit;
	this->relayOpenIndex = relayOpenIndex;
}

void Lever::update() {

}
