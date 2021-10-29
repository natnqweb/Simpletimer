#include <Simpletimer.h>

    bool Simpletimer::timer(unsigned long waitTime)//manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
    {
        if (micros() - before >= waitTime*1000U)
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
		_cb=cb;
	}
	void Simpletimer::run(unsigned long timing)
	{
		if (timer(timing)){
			_cb();
		}
	}