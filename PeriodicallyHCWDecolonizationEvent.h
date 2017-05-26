#ifndef PERIODICALLYHCWDECOLONIZATIONEVENT_H
#define PERIODICALLYHCWDECOLONIZATIONEVENT_H

#include "Event.h"

class PeriodicallyHCWDecolonizationEvent : public Event
{
protected:
    unsigned int _hcw_id;
    PeriodicallyHCWDecolonizationEvent(double time, unsigned int hcw_id);
public:
    virtual std::string str() const;
    unsigned int hcw_id() const;
    static typeEventPtr createEvent(double time, unsigned int hcw_id);
};

#endif // PERIODICALLYHCWDECOLONIZATIONEVENT_H
