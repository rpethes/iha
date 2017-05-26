#include "HCW.h"

HCW::HCW(unsigned int id,
    double start_shift_time,
    double stop_shift_time,
    bool is_working,
    const typeUIntSet & treatmentIDSet,
    const typeUIntList & wardIDList) :
    Agent(id),
    _start_shift_time(start_shift_time),
    _stop_shift_time(stop_shift_time),
    _is_working(is_working),
    _patient_id(0),
    _treatmentIDSet(treatmentIDSet),
    _wardIDList(wardIDList)
{}

HCW::~HCW()
{}

void HCW::setStartShiftTime(double start_shift_time)
{
    _start_shift_time = start_shift_time;
}

void HCW::setStopShiftTime(double stop_shift_time)
{
    _stop_shift_time = stop_shift_time;
}

void HCW::setIsWorking(bool is_working)
{
    _is_working = is_working;
}

void HCW::setPatientID(unsigned int id)
{
    _patient_id = id;
}

const typeUIntSet & HCW::treatmentIDSet() const
{
    return _treatmentIDSet;
}

const typeUIntList & HCW::wardIDList() const
{
    return _wardIDList;
}

bool HCW::isWorking() const
{
    return _is_working;
}

bool HCW::isAvailable() const
{
    return _is_working && (_patient_id == 0);
}
