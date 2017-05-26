#include "ExpDistrSampler.h"

boost::mt19937 ExpDistrSampler::_random_generator;

ExpDistrSampler::ExpDistrSampler(double lambda) :
    _lambda(lambda), _distr(lambda)
{}

double ExpDistrSampler::sample()
{
    return _distr(_random_generator);
}

DistrSampler * ExpDistrSampler::clone() const
{
    return new ExpDistrSampler(_lambda);
}
