#ifndef PATIENT_H
#define PATIENT_H

#include "Agent.h"
#include "Treatment.h"
#include <list>

typedef std::list<Treatment> typeTreatmentList;

class Patient : public Agent
{
    friend class PatientFactory;

protected:
    unsigned int _ward_id;
    double _admission_time;
    double _discharge_time;
    typeTreatmentList _treatmentList;

    Patient(unsigned int id, unsigned int ward_id, double admission_time, double discharge_time, const typeTreatmentList & treatmentList);
public:

    unsigned int ward_id() const;
    double admission_time() const;
    double discharge_time() const;
    typeTreatmentList & treatmentList();

    void setDischargeTime(double discharge_time);
    void addTreatment(const Treatment & treatment);
};

typedef std::list<Patient *> typePatientPtrList;

#endif // PATIENT_H
