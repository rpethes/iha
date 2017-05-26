#ifndef ABSGAUSSDISTRSAMPLER_H
#define ABSGAUSSDISTRSAMPLER_H

#include "GaussDistrSampler.h"

class AbsGaussDistrSampler : public DistrSampler
{
protected:
    double _mean;
    double _standard_deviation;
    GaussDistrSampler _gaussDistrSampler;
public:
    AbsGaussDistrSampler(double mean, double standard_deviation);
    virtual double sample();
    virtual DistrSampler * clone() const;
};

#endif // ABSGAUSSDISTRSAMPLER_H
