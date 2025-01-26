#pragma once

#include <Arduino.h>
#include "timer.h"

class Relay
{
public:
	Relay(int unit, int index);
	~Relay();

	void executeCommand(char commandType);
	void beginPulse();
	void endPulse();

private:
	int index;
	HardwareSerial* serialPort;
	Timer pulseClock;
	bool currentlyInAPulse;
};