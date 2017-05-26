#include "PatientFactory.h"

PatientFactory::PatientFactory() : _next_id(1)
{}

Patient * PatientFactory::create(unsigned int ward_id, double admission_time, double discharge_time, const typeTreatmentList & treatmentList,ObjectDB & db)
{
    Patient * obj = new Patient(_next_id, ward_id, admission_time, discharge_time, treatmentList);
    ++_next_id;
    db.set(obj);
    return obj;
}
