#ifndef TREATMENTUGRENCYSTEP_H
#define TREATMENTUGRENCYSTEP_H

#include "TreatmentUrgencyBase.h"

class TreatmentUgrencyStep : public TreatmentUrgencyBase
{
protected:
    double _waitingTime;
public:
    TreatmentUgrencyStep(double lastTreatmentTime, double waitingTime);
    virtual double urgency(double current_time) const;
    virtual TreatmentUrgencyBase * clone();
};

#endif // TREATMENTUGRENCYSTEP_H
