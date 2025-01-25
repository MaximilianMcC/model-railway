#include "timer.h"
#include <Arduino.h>

Timer::Timer() {}
Timer::Timer(long timerDuration) {

	// Set the duration
	duration = timerDuration;
	startTime = 0;
}

void Timer::start() {

	// Set the start time to be the current time
	startTime = millis();
}

bool Timer::stillCounting() {

	// Check for how long the timer has been running
	long timeElapsed = millis() - startTime;

	// Return depending on the status
	return timeElapsed <= duration;
}

long Timer::getTimeLeft() {

	// Check for how long the timer has been running
	long timeElapsed = millis() - startTime;

	// Give back the time left
	return duration - timeElapsed;
}

void Timer::printTimeLeftDebug() {

	char output[100];
	sprintf(output, "Time left: %ldms", getTimeLeft());

	if (getTimeLeft() >= 0) Serial.println(output);
}