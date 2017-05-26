#ifndef SIMULATIONTIMER_H
#define SIMULATIONTIMER_H

class SimulationTimer
{
protected:
    double _iterations_per_hour;
    double _time_step;
    double _current_time;
    unsigned int _current_day;
    double _time_in_current_day;
public:
    SimulationTimer(double iterations_per_hour);
    double tick();
    double iterations_per_hour() const;
    double time_step() const;
    double current_time() const;
    unsigned int current_day() const;
    double time_in_current_day() const;

};

#endif // SIMULATIONTIMER_H
