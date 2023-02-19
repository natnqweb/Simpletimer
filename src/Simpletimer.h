#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <Arduino.h>

class class_with_callbacks
{
public:
	typedef void (*callback)(void);
};

class Simpletimer: public class_with_callbacks
{
public:
	struct RunOnce
	{
		RunOnce() {}
		~RunOnce() {}
		bool __flag__ = true;
		template <typename T>
		void Run(T&& yourcode)
		{
			if (__flag__)
				yourcode();
			__flag__ = false;
		}
		void Reset()
		{
			__flag__ = true;
		}
	};
	Simpletimer();
	~Simpletimer();

	bool timer(unsigned long waitTime); //manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
	void register_callback(callback cb);
	void run(unsigned long timing = 0);
	unsigned long get_run_count();

	void register_multiple_callbacks(callback*, unsigned long* timeperiod, unsigned int number_of_callbacks = 1);
	struct { Simpletimer* p_timer; unsigned int n_size; } get_timers();

private:
	unsigned long _run_count{0};
	callback _cb{};
	unsigned long* _time_periods{ nullptr };
	unsigned long _before{ 0 };
	bool _multiple_callbacks = false;
	RunOnce _OnlyOnce{};
	unsigned int _number_of_registered_callbacks{ 0 };
	Simpletimer* _timerz = nullptr;
};

class SimpletimerManager
{
	Simpletimer* _simpleTimer;
public:
	SimpletimerManager(Simpletimer*);
	bool run(unsigned long timing, unsigned int amount_of_times_to_run);
	bool run(unsigned long timing, unsigned int amount_of_times_to_run, unsigned int index_of_timer);
	void run(unsigned long timing);
	void run(unsigned int* run_constrains);

	Simpletimer* get_timer(unsigned int index);
	Simpletimer* get_timer();
};

#endif // SIMPLETIMER_H