#include "SimulationTimer.h"

const int MINUTES_PER_DAY = 24*60;

SimulationTimer::SimulationTimer(double iterations_per_hour) :
    _iterations_per_hour(iterations_per_hour),
    _time_step( 60.0 / _iterations_per_hour),
    _current_time(0.0),
    _current_day(0),
    _time_in_current_day(0.0)
{}


double SimulationTimer::tick()
{
    _current_time += _time_step;
    _time_in_current_day += _time_step;
    if (_time_in_current_day >= MINUTES_PER_DAY) {
        _time_in_current_day -= MINUTES_PER_DAY;
        ++_current_day;
    }

    return _current_time;
}

double SimulationTimer::iterations_per_hour() const
{
    return _iterations_per_hour;
}

double SimulationTimer::time_step() const
{
    return _time_step;
}

double SimulationTimer::current_time() const
{
    return _current_time;
}

unsigned int SimulationTimer::current_day() const
{
    return _current_day;
}

double SimulationTimer::time_in_current_day() const
{
    return _time_in_current_day;
}
