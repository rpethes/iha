#include "TreatmentUrgencyBase.h"

TreatmentUrgencyBase::TreatmentUrgencyBase(double lastTreatmentTime) : _lastTreatmentTime(lastTreatmentTime)
{}

TreatmentUrgencyBase::~TreatmentUrgencyBase()
{}


void TreatmentUrgencyBase::setLastTreatmenTime(double lastTreatmentTime)
{
    _lastTreatmentTime = lastTreatmentTime;
}

double TreatmentUrgencyBase::lastTreatmentTime() const
{
    return _lastTreatmentTime;
}

