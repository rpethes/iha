#include "TreatmentUrgencyExp.h"
#include <math.h>

TreatmentUrgencyExp::TreatmentUrgencyExp(double lastTreatmentTime, double lambda) :
    TreatmentUrgencyBase(lastTreatmentTime), _lambda(lambda)
{}

double TreatmentUrgencyExp::urgency(double current_time) const
{
    if (current_time < _lastTreatmentTime)
        return 0.0;

    double dt = current_time - _lastTreatmentTime;
    return 1.0 - exp(-_lambda*dt);
}

TreatmentUrgencyBase * TreatmentUrgencyExp::clone()
{
    return new TreatmentUrgencyExp(_lastTreatmentTime, _lambda);
}
