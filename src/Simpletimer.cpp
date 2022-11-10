#include <Simpletimer.h>

Simpletimer::Simpletimer() = default;
Simpletimer::~Simpletimer()
{
    if (multiple_callbacks || timerz)
        delete[] timerz;
}

bool Simpletimer::timer(unsigned long waitTime) //manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
{
    if (micros() - before >= waitTime * 1000U)
    {
        before = micros();
        return true;
    }
    else
    {
        return false;
    }
}

void Simpletimer::register_callback(callback cb)
{
    _cb = cb;
    multiple_callbacks = false;
}

void Simpletimer::run(unsigned long timing)
{
    if (multiple_callbacks)
    {
        for (unsigned int i = 0; i < _number_of_registered_callbacks; i++)
        {
            timerz[i].run(_time_periods[i]);
        }
    }
    else
    {
        if (timer(timing))
        {
            _cb();
        }
    }
}

void Simpletimer::register_multiple_callbacks(callback* callbacks, unsigned long* timeperiods, unsigned int number_of_callbacks /*= 1*/)
{

    OnlyOnce.Run([&]()
        {
            timerz = new Simpletimer[number_of_callbacks];

            _number_of_registered_callbacks = number_of_callbacks;
        });
    _time_periods = timeperiods;
    for (unsigned int i = 0; i < number_of_callbacks; i++)
    {
        timerz[i].register_callback(callbacks[i]);
    }
    multiple_callbacks = true;
}
