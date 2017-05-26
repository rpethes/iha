#include "PatientToHCWColonizationEvent.h"
#include <sstream>

PatientToHCWColonizationEvent::PatientToHCWColonizationEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id) :
    ColonizationEvent(time, "PatientToHCWColonization", pathogen, hcw_id), _patient_id(patient_id)
{}

std::string PatientToHCWColonizationEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " patient: " << _patient_id << " hcw: " << _target_id << " pathogen: " << _pathogen;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

typeEventPtr PatientToHCWColonizationEvent::createEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id)
{
    return typeEventPtr(new PatientToHCWColonizationEvent(time, pathogen, patient_id, hcw_id));
}
