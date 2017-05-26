#include "AbsGaussDistrSampler.h"

AbsGaussDistrSampler::AbsGaussDistrSampler(double mean, double standard_deviation) :
    _mean(mean),
    _standard_deviation(standard_deviation),
    _gaussDistrSampler(mean, standard_deviation)
{}

double AbsGaussDistrSampler::sample()
{
    return _gaussDistrSampler.sample();
}

DistrSampler * AbsGaussDistrSampler::clone() const
{
    return new AbsGaussDistrSampler(_mean, _standard_deviation);
}
