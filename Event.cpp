#include "Event.h"
#include <algorithm>

Event::Event(double time, const char * name) :
    _time(time), _name(name)
{}


void Event::addSubEvent(typeEventPtr event)
{
    _subEvents.push_back(event);
}

void Event::addSubEvents(const typeEventPtrList & events)
{
    std::copy(events.begin(), events.end(), std::back_inserter(_subEvents));
}

Event::~Event()
{

}

const std::string & Event::name() const
{
    return _name;
}

double Event::time() const
{
    return _time;
}

