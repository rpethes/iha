#include "DischargeEvent.h"
#include <sstream>
#include "Colonization.h"
#include "utils.h"

DischargeEvent::DischargeEvent(double time, Patient & patient) :
    Event(time, "Discharge")
{
    _patient_id = patient.id();
    typeColonizationMap & colonizations = patient.colonizationMap();

    typeColonizationMap::iterator it = colonizations.begin(), end = colonizations.end();
    for (; it!=end; ++it) {
        Colonization * colonization = it->second;
        _colonizedPathogens.push_back(colonization->pathogen()->name());
    }

    _los = patient.discharge_time() - patient.admission_time();
}

unsigned int DischargeEvent::patient_id() const
{
    return _patient_id;
}

const typeStringList & DischargeEvent::colonizedPathogens() const
{
    return _colonizedPathogens;
}

double DischargeEvent::los() const
{
    return _los;
}

typeEventPtr DischargeEvent::createEvent(double time, Patient & patient)
{
    return typeEventPtr(new DischargeEvent(time, patient));
}

std::string DischargeEvent::str() const
{
    std::stringstream ss;
    std::string pathogens = iterableToString(_colonizedPathogens,";");
    if (pathogens.empty())
        pathogens = "-";
    ss << " [ " <<  _time << " " << _name << " patient_id: " << _patient_id;
    ss << " colonized_with: " << pathogens;


    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}
