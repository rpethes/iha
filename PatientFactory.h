#ifndef PATIENTFACTORY_H
#define PATIENTFACTORY_H

#include "Patient.h"
#include "ObjectDB.h"
#include <memory>

class PatientFactory
{
protected:
    unsigned int _next_id;

public:
    PatientFactory();
    Patient * create(unsigned int ward_id, double admission_time, double discharge_time, const typeTreatmentList & treatmentList, ObjectDB & db);

};

typedef std::shared_ptr<PatientFactory> typePatientFactoryPtr;

#endif // PATIENTFACTORY_H
