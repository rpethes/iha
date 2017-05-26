#include "InitPatientEvent.h"

#include <sstream>

InitPatientEvent::InitPatientEvent(double time, unsigned int patient_id, unsigned int ward_id, double los) :
    Event(time, "InitPatient"), _patient_id(patient_id), _ward_id(ward_id), _los(los)
{}

std::string InitPatientEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  0 << " " << _name << " patient: " << _patient_id << " ward: " << _ward_id << " admission_time: " << _time << " los: " << _los;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

unsigned int InitPatientEvent::patient_id() const
{
    return _patient_id;
}

unsigned int InitPatientEvent::ward_id() const
{
    return _ward_id;
}

typeEventPtr InitPatientEvent::createEvent(double time, unsigned int patient_id, unsigned int ward_id, double los)
{
    return typeEventPtr(new InitPatientEvent(time, patient_id, ward_id, los));
}

double InitPatientEvent::los() const
{
    return _los;
}

