#include "Treatment.h"

Treatment::Treatment(unsigned int treatmentTypeID,
          typeDistrSamplerPtr treatmentPeriodSampler,
          typeTreatmentUrgencyBasePtr treatmentUrgency,
          int nr_of_necessary_hcws) :
    _treatmentTypeID(treatmentTypeID),
    _startTime(0.0),
    _stopTime(0.0),
    _isActive(false),
    _treatmentPeriodSampler(treatmentPeriodSampler),
    _treatmentUrgency(treatmentUrgency),
    _nr_of_necessary_hcws(nr_of_necessary_hcws)

{}

Treatment::Treatment(const Treatment & theOther)
{
    _treatmentTypeID = theOther._treatmentTypeID;
    _startTime = theOther._startTime;
    _stopTime = theOther._stopTime;
    _isActive = theOther._isActive;
    _treatmentPeriodSampler.reset(theOther._treatmentPeriodSampler->clone());
    _treatmentUrgency.reset(theOther._treatmentUrgency->clone());
    _nr_of_necessary_hcws = theOther._nr_of_necessary_hcws;
}

Treatment & Treatment::operator=(const Treatment & theOther)
{
    if (this == &theOther)
        return *this;

    _treatmentTypeID = theOther._treatmentTypeID;
    _startTime = theOther._startTime;
    _stopTime = theOther._stopTime;
    _isActive = theOther._isActive;

    _treatmentPeriodSampler.reset(theOther._treatmentPeriodSampler->clone());
    _treatmentUrgency.reset(theOther._treatmentUrgency->clone());
    _nr_of_necessary_hcws = theOther._nr_of_necessary_hcws;

    return *this;
}


Treatment::~Treatment()
{}

void Treatment::startTreatment(double current_time)
{
    _isActive = true;
    double treatmentPeriod = _treatmentPeriodSampler->sample();
    _startTime = current_time;
    _stopTime = _startTime + treatmentPeriod;
}

void Treatment::stopTreatment(double current_time)
{
    if (_isActive && _stopTime <= current_time) {
        _treatmentUrgency->setLastTreatmenTime(_stopTime);
        _isActive = false;
    }
}

bool Treatment::isActive() const
{
    return _isActive;
}


unsigned int Treatment::treatmentTypeID() const
{
    return _treatmentTypeID;
}


double Treatment::startTime() const
{
    return _startTime;
}


double Treatment::stopTime() const
{
    return _stopTime;
}


double Treatment::urgency(double current_time) const
{
    return _treatmentUrgency->urgency(current_time);
}

int Treatment::nr_of_necessary_hcws() const
{
    return _nr_of_necessary_hcws;
}
