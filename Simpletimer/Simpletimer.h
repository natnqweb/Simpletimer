#ifndef Simpletimer_h
#define Simpletimer_h
#include <Arduino.h>
struct Simpletimer                       // my timer function helps to manage tasks  non blocking way
{
    unsigned long before;
    bool timer(unsigned long waitTime);//manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program

	

};
#endif