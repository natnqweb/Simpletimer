#include <Simpletimer.h>
struct TimersArray { Simpletimer* p_timer; unsigned int n_size; };
Simpletimer::Simpletimer() = default;
Simpletimer::~Simpletimer()
{
    if (_multiple_callbacks || _timerz)
        delete[] _timerz;
}

bool Simpletimer::timer(unsigned long waitTime) //manage your tasks enter time then timer function will return true every given time, remember that it returns true at the beggining of program
{
    if (micros() - _before >= waitTime * 1000U)
    {
        _before = micros();
        _run_count++;
        return true;
    }

    return false;
}

void Simpletimer::register_callback(callback cb)
{
    _cb = cb;
    _multiple_callbacks = false;
}

void Simpletimer::run(unsigned long timing)
{
    if (_multiple_callbacks)
    {
        for (unsigned int i = 0; i < _number_of_registered_callbacks; i++)
        {
            _timerz[i].run(_time_periods[i]);
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

    _OnlyOnce.Run([&]()
        {
            _timerz = new Simpletimer[number_of_callbacks];

            _number_of_registered_callbacks = number_of_callbacks;
        });
    _time_periods = timeperiods;
    for (unsigned int i = 0; i < number_of_callbacks; i++)
    {
        _timerz[i].register_callback(callbacks[i]);
    }
    _multiple_callbacks = true;
}

TimersArray Simpletimer::get_timers()
{
    if (!_timerz || !_multiple_callbacks)
        return { nullptr, 0 };

    return { _timerz, _number_of_registered_callbacks };
}

unsigned long Simpletimer::get_run_count()
{
    return _run_count;
}

SimpletimerManager::SimpletimerManager(Simpletimer* timer): _simpleTimer(timer)
{
}

bool SimpletimerManager::run(unsigned long timing, unsigned int amount_of_times_to_run)
{
    if (!get_timer())
        return false;

    if (get_timer()->get_run_count() >= amount_of_times_to_run)
    {
        return false;
    }

    get_timer()->run(timing);
    return true;
}

void SimpletimerManager::run(unsigned long timing)
{
    if (!get_timer())
        return;
    get_timer()->run(timing);
}

void SimpletimerManager::run(unsigned int* run_constrains)
{
    static const unsigned long constrains_size = sizeof(run_constrains) / sizeof(run_constrains[0]);
    for (unsigned long i = 0; i < constrains_size; i++)
    {
        (void)run(0, run_constrains[i], i);
    }
}

bool SimpletimerManager::run(unsigned long timing, unsigned int amount_of_times_to_run, unsigned int index_of_timer)
{
    auto timer = get_timer(index_of_timer);
    if (!timer)
        return false;

    if (timer->get_run_count() >= amount_of_times_to_run)
    {
        return false;
    }

    timer->run(timing);
    return true;
}

Simpletimer* SimpletimerManager::get_timer(unsigned int index)
{
    TimersArray arr = get_timer()->get_timers();
    auto timer = arr.p_timer;
    auto number_of_timers = arr.n_size;

    if (!timer || number_of_timers == 0 || index >= number_of_timers)
    {
        return nullptr;
    }

    return &timer[index];
}

Simpletimer* SimpletimerManager::get_timer()
{
    return _simpleTimer;
}
