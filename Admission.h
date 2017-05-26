#ifndef ADMISSION_H
#define ADMISSION_H

#include "PatientFactory.h"
#include "DistrSampler.h"
#include "AdmissionColonization.h"
#include "PatientModif.h"
#include "ObjectDB.h"
#include <memory>

class Admission
{
protected:
    typePatientFactoryPtr _patientFactory;
    typeDistrSamplerPtr _losSampler;
    typeAdmissionColonizationPtrList _admissionColonizationList;
    typeDistrSamplerPtr _admissionWaitingTimeSampler;
    double _next_admission_time;
public:
    Admission(typePatientFactoryPtr patientFactory,
              typeDistrSamplerPtr losSampler,
              typeAdmissionColonizationPtrList & admissionColonizationList,
              typeDistrSamplerPtr admissionWaitingTimeSampler,
              double next_admission_time);

    virtual ~Admission();

    virtual void admission(double current_time, ObjectDB & patientDB, PatientModif & patientModif, unsigned int ward_id, const typeTreatmentList & defaultTreatmentList);

};


typedef std::shared_ptr<Admission> typeAdmissionPtr;
#endif // ADMISSION_H
