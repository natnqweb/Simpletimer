#ifndef Simpletimer_h
#define Simpletimer_h
#include <Arduino.h>

class Simpletimer // my timer function helps to manage tasks  non blocking way
{
public:
	typedef void (*callback)(void);
	Simpletimer() {}
	~Simpletimer() { delete[] timerz; }

	bool timer(unsigned long waitTime); //manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
	void register_callback(callback cb);
	void run(unsigned long timing = 0);
	
	void register_multiple_callbacks(callback *, unsigned long *timeperiod, size_t number_of_callbacks);

private:
	callback _cb;
	unsigned long *_time_periods;
	unsigned long before;
	bool multiple_callbacks = false;

	size_t _number_of_registered_callbacks;
	Simpletimer *timerz = nullptr;
};
#endif