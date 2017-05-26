#include "InitHCWEvent.h"
#include <sstream>
#include "utils.h"

InitHCWEvent::InitHCWEvent(double time, unsigned int hcw_id, const typeUIntList & wardIDList,const typeUIntSet treatmentIDSet) :
    Event(time, "InitHCW"), _hcw_id(hcw_id), _wardIDList(wardIDList), _treatmentIDSet(treatmentIDSet)
{}

std::string InitHCWEvent::str() const
{
    std::stringstream ss;
    std::string str_wards = iterableToString(_wardIDList,";");
    std::string str_treatments = iterableToString(_treatmentIDSet,";");
    ss << " [ " <<  _time << " " << _name << " hcw: " << _hcw_id << " wards: " << str_wards.c_str() << " treatments: " << str_treatments.c_str();

    typeEventPtrList::const_iterator it = _subEvents.begin(), end = _subEvents.end();

    for (; it != end; ++it) {
        ss << (*it)->str();
    }
    ss << " ]";

    return ss.str();

}

unsigned int InitHCWEvent::hcw_id() const
{
    return _hcw_id;
}

const typeUIntList & InitHCWEvent::wardIDList() const
{
    return _wardIDList;
}

const typeUIntSet & InitHCWEvent::treatmentIDSet() const
{
    return _treatmentIDSet;
}

typeEventPtr InitHCWEvent::createEvent(double time, unsigned int hcw_id, const typeUIntList & wardIDList,const typeUIntSet treatmentIDSet)
{
    return typeEventPtr(new InitHCWEvent(time, hcw_id, wardIDList, treatmentIDSet));
}
