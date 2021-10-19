#ifndef Simpletimer_h
#define Simpletimer_h
#include <Arduino.h>
typedef void (*callback)(void);
class Simpletimer                       // my timer function helps to manage tasks  non blocking way
{
	public:
	Simpletimer(){}
	
    bool timer(unsigned long waitTime);//manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
	void register_callback(callback cb);
	void call_callback(unsigned long timing);
	
	private:
	callback _cb;
	unsigned long before;

};
#endif