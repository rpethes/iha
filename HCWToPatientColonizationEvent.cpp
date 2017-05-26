#include "HCWToPatientColonizationEvent.h"

#include <sstream>

HCWToPatientColonizationEvent::HCWToPatientColonizationEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id) :
    ColonizationEvent(time, "HCWToPatientColonization", pathogen, patient_id), _hcw_id(hcw_id)
{}

std::string HCWToPatientColonizationEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " hcw: " << _hcw_id << " patient: " << _target_id << " pathogen: " << _pathogen;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

typeEventPtr HCWToPatientColonizationEvent::createEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id)
{
    return typeEventPtr(new HCWToPatientColonizationEvent(time, pathogen, patient_id, hcw_id));
}

