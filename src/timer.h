class Timer {

public:
	Timer();
	Timer(long timerDuration);

	void start();
	bool hasExpired();
	long timeLeft();

private:
	long startTime;
	long duration;
};