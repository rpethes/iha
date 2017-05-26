#include "AdmissionColonizationEvent.h"
#include <sstream>

AdmissionColonizationEvent::AdmissionColonizationEvent(double time, const char * pathogen, unsigned int target_id) :
    ColonizationEvent(time, "AdmissionColonization", pathogen, target_id)
{}

std::string AdmissionColonizationEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " target: " << _target_id << " pathogen: " << _pathogen;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

typeEventPtr AdmissionColonizationEvent::createEvent(double time, const char * pathogen, unsigned int target_id)
{
    return typeEventPtr(new AdmissionColonizationEvent(time, pathogen, target_id));
}
