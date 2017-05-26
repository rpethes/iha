#include "Patient.h"

Patient::Patient(unsigned int id, unsigned int ward_id, double admission_time, double discharge_time, const typeTreatmentList & treatmentList) :
    Agent(id),
    _ward_id(ward_id),
    _admission_time(admission_time),
    _discharge_time(discharge_time),
    _treatmentList(treatmentList)
{}

unsigned int Patient::ward_id() const
{
    return _ward_id;
}

double Patient::admission_time() const
{
    return _admission_time;
}

double Patient::discharge_time() const
{
    return _discharge_time;
}

typeTreatmentList & Patient::treatmentList()
{
    return _treatmentList;
}

void Patient::setDischargeTime(double discharge_time)
{
    _discharge_time = discharge_time;
}

void Patient::addTreatment(const Treatment & treatment)
{
    _treatmentList.push_back(treatment);
}
