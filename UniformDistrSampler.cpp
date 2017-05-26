#include "UniformDistrSampler.h"

boost::mt19937 UniformDistrSampler::_random_generator;

UniformDistrSampler::UniformDistrSampler(double minVal, double maxVal) :
    _min(minVal), _max(maxVal), _distr(minVal, maxVal)
{}

double UniformDistrSampler::sample()
{
    return _distr(_random_generator);
}

DistrSampler * UniformDistrSampler::clone() const
{
    return new UniformDistrSampler(_min, _max);
}
