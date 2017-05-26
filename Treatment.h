#ifndef TREATMENT_H
#define TREATMENT_H

#include "DistrSampler.h"
#include "TreatmentUrgencyBase.h"
#include <list>

class Treatment
{
protected:
    unsigned int _treatmentTypeID;
    double _startTime;
    double _stopTime;
    bool _isActive;
    typeDistrSamplerPtr _treatmentPeriodSampler;
    typeTreatmentUrgencyBasePtr _treatmentUrgency;
    int _nr_of_necessary_hcws;

public:
    Treatment(unsigned int treatmentTypeID,
              typeDistrSamplerPtr treatmentPeriodSampler,
              typeTreatmentUrgencyBasePtr treatmentUrgency,
              int nr_of_necessary_hcws = 1);

    Treatment(const Treatment & theOther);
    Treatment & operator=(const Treatment & theOther);
    virtual ~Treatment();
    virtual void startTreatment(double current_time);
    virtual void stopTreatment(double current_time);
    bool isActive() const;
    unsigned int treatmentTypeID() const;
    double startTime() const;
    double stopTime() const;
    double urgency(double current_time) const;
    int nr_of_necessary_hcws() const;
};

#endif // TREATMENT_H
