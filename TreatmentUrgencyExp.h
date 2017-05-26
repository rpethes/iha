#ifndef TREATMENTURGENCYEXP_H
#define TREATMENTURGENCYEXP_H

#include "TreatmentUrgencyBase.h"

class TreatmentUrgencyExp : public TreatmentUrgencyBase
{
protected:
    double _lambda;
public:
    TreatmentUrgencyExp(double lastTreatmentTime, double lambda);
    virtual double urgency(double current_time) const;
    virtual TreatmentUrgencyBase * clone();
};


#endif // TREATMENTURGENCYEXP_H
