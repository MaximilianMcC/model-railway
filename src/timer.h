class Timer {

public:
	Timer();
	Timer(long timerDuration);

	void start();
	bool hasExpired();
	long getTimeLeft();
	void printTimeLeftDebug();

private:
	long startTime;
	long duration;
};