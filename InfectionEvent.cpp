#include "InfectionEvent.h"
#include <sstream>

InfectionEvent::InfectionEvent(double time, unsigned int id, const char * pathogen, double colonization_time) :
    Event(time, "Infection"), _id(id), _pathogen(pathogen), _colonization_time(colonization_time)
{}

unsigned int InfectionEvent::id() const
{
    return _id;
}

const std::string & InfectionEvent::pathogen() const
{
    return _pathogen;
}

double InfectionEvent::colonization_time() const
{
    return _colonization_time;
}

std::string InfectionEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " patient: " << _id << " pathogen: " << _pathogen.c_str() << " colonization_time: " << _colonization_time;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

typeEventPtr InfectionEvent::createEvent(double time, unsigned int id, const char * pathogen, double colonization_time)
{
    return typeEventPtr(new InfectionEvent(time, id, pathogen, colonization_time));
}
