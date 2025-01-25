#ifndef LEVER_H
#define LEVER_H

#include <Arduino.h>

class Lever {
public:
	Lever();
	Lever(int pin, int relayUnit, int relayOpenIndex);

	void update();

private:
	int pin;
	int relayUnit;
	int relayOpenIndex;
};

#endif
