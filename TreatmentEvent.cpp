#include "TreatmentEvent.h"
#include <sstream>
#include "utils.h"

TreatmentEvent::TreatmentEvent(double time, TreatmentAssign & assign) :
    Event(time, "Treatment")
{
    _patient_id = assign.patient().id();
    _treatmentTypeID = assign.treatment().treatmentTypeID();
    _treatmentStopTime = assign.treatment().stopTime();

    typeHCWPtrList & hcws = assign.hcws();
    typeHCWPtrList::iterator it = hcws.begin(), end = hcws.end();

    for (; it!=end; ++it) {
        HCW * hcw = *it;
        _hcws.push_back(hcw->id());
    }

}

std::string TreatmentEvent::str() const
{
    std::stringstream ss;

    ss << " [ " <<  _time << " " << _name << " patient: " << _patient_id << " treatment: " << _treatmentTypeID;
    std::string strHCWs = iterableToString(_hcws,";");
    ss << " stop_time: " << _treatmentStopTime << " hcws: " << strHCWs;

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();
}

typeEventPtr TreatmentEvent::createEvent(double time, TreatmentAssign & assign)
{
    return typeEventPtr(new TreatmentEvent(time, assign));
}
