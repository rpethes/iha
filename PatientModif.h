#ifndef PATIENTMODIF_H
#define PATIENTMODIF_H

#include "Patient.h"
#include <memory>

class PatientModif
{
public:
    PatientModif();
    virtual ~PatientModif();
    virtual void modifyPatient(Patient & patient);
};

typedef std::shared_ptr<PatientModif> typePatientModifPtr;

#endif // PATIENTMODIF_H
