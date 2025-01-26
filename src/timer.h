#pragma once

class Timer {

public:
	Timer();
	Timer(long timerDuration);

	void start();
	bool stillCounting();
	long getTimeLeft();
	void printTimeLeftDebug();

private:
	long startTime;
	long duration;
};