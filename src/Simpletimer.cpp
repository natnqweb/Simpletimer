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
    if (_run_limit_is_set && _run_count >= _run_limit)
    {
        return false;
    }

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

void Simpletimer::set_run_limit(unsigned long run_x_times)
{
    _run_limit = run_x_times;
    _run_limit_is_set = true;
}
void Simpletimer::reset_run_limit()
{
    _run_limit = 0;
    _run_limit_is_set = false;
}

SimpletimerManager::SimpletimerManager(Simpletimer* timer): _simpleTimer(timer)
{
}

void SimpletimerManager::limit_all_tasks_run_counts(unsigned long limit)
{
    if (!get_timer())
    {
        return;
    }
    TimersArray arr = get_timer()->get_timers();
    auto timer = arr.p_timer;
    auto number_of_timers = arr.n_size;
    for (unsigned int i = 0; i < number_of_timers; i++)
    {
        timer[i].set_run_limit(limit);
    }

    get_timer()->set_run_limit(limit);
}

void SimpletimerManager::restart_all_run_counts()
{
    if (!get_timer())
    {
        return;
    }

    TimersArray arr = get_timer()->get_timers();
    auto timer = arr.p_timer;
    auto number_of_timers = arr.n_size;
    for (unsigned int i = 0; i < number_of_timers; i++)
    {
        timer[i].reset_run_limit();
    }

    get_timer()->reset_run_limit();
}

bool SimpletimerManager::limit_number_of_calls_to_callback(unsigned int callback_index, unsigned long number_of_calls_limit)
{
    auto timer = get_timer(callback_index);
    if (!timer) return false;

    timer->set_run_limit(number_of_calls_limit);
    return true;
}

bool SimpletimerManager::reset_number_of_calls_limit(unsigned int callback_index)
{
    auto timer = get_timer(callback_index);
    if (!timer) return false;

    timer->reset_run_limit();
    return true;
}


Simpletimer* SimpletimerManager::get_timer(unsigned int index)
{
    if (!get_timer()) return nullptr;
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
