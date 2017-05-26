#ifndef TREATMENTPATIENTPAIR_H
#define TREATMENTPATIENTPAIR_H

#include "Treatment.h"
#include "Patient.h"

#include <vector>

class TreatmentPatientPair
{
private:
    Treatment * _treatment;
    Patient * _patient;
    double _urgency;
public:
    TreatmentPatientPair(Treatment * treatment, Patient * patient, double current_time) :
        _treatment(treatment),
        _patient(patient)
    {
        _urgency = _treatment->urgency(current_time);
    }

    Treatment * treatment()
    {
        return _treatment;
    }

    Patient * patient()
    {
        return _patient;
    }

    double urgency() const
    {
        return _urgency;
    }

    friend bool operator < (const TreatmentPatientPair & lhs, const TreatmentPatientPair & rhs)
    {
        return lhs._urgency < rhs._urgency;
    }
};

typedef std::vector<TreatmentPatientPair> typeTreatmentPatientPairArray;



#endif // TREATMENTPATIENTPAIR_H
