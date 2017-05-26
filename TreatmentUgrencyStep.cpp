#include "TreatmentUgrencyStep.h"

TreatmentUgrencyStep::TreatmentUgrencyStep(double lastTreatmentTime, double waitingTime) :
    TreatmentUrgencyBase(lastTreatmentTime), _waitingTime(waitingTime)
{}

double TreatmentUgrencyStep::urgency(double current_time) const
{
    if (current_time - _lastTreatmentTime >= _waitingTime)
        return 1.0;

    return 0.0;
}


TreatmentUrgencyBase * TreatmentUgrencyStep::clone()
{
    return new TreatmentUgrencyStep(_lastTreatmentTime, _waitingTime);
}
