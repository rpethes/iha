#include "PeriodicallyHCWDecolonizationEvent.h"
#include <sstream>

PeriodicallyHCWDecolonizationEvent::PeriodicallyHCWDecolonizationEvent(double time, unsigned int hcw_id):
    Event(time, "PeriodicallyHCWDecolonization"), _hcw_id(hcw_id)
{}


std::string PeriodicallyHCWDecolonizationEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " hcw: " << _hcw_id;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}
unsigned int PeriodicallyHCWDecolonizationEvent::hcw_id() const
{
    return _hcw_id;
}

typeEventPtr PeriodicallyHCWDecolonizationEvent::createEvent(double time, unsigned int hcw_id)
{
    return typeEventPtr(new PeriodicallyHCWDecolonizationEvent(time, hcw_id));
}
