#include "BernoulliDistrSampler.h"


boost::mt19937 BernoulliDistrSampler::_random_generator;

BernoulliDistrSampler::BernoulliDistrSampler(double p):
    _p(p),  _distr(p)
{}

double BernoulliDistrSampler::sample()
{
    return _distr(_random_generator);
}

DistrSampler * BernoulliDistrSampler::clone() const
{
    return new BernoulliDistrSampler(_p);
}

