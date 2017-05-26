#include "AdmissionEvent.h"
#include <sstream>

AdmissionEvent::AdmissionEvent(double time, unsigned int patient_id, unsigned int ward_id, double los) :
    Event(time, "Admission"), _patient_id(patient_id), _ward_id(ward_id), _los(los)
{}

std::string AdmissionEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " patient: " << _patient_id << " ward: " << _ward_id << " los: " << _los;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

unsigned int AdmissionEvent::patient_id() const
{
    return _patient_id;
}

unsigned int AdmissionEvent::ward_id() const
{
    return _ward_id;
}

typeEventPtr AdmissionEvent::createEvent(double time, unsigned int patient_id, unsigned int ward_id, double los)
{
    return typeEventPtr(new AdmissionEvent(time, patient_id, ward_id, los));
}

double AdmissionEvent::los() const
{
    return _los;
}
