#include "LognormalDistrSampler.h"
#include <math.h>

boost::mt19937 LognormalDistrSampler::_random_generator;


LognormalDistrSampler::LognormalDistrSampler(double m, double s) :
    _m(m),
    _s(s),
    _lognormal_distr(_m, _s)
{}

double LognormalDistrSampler::sample()
{
    return _lognormal_distr(_random_generator);
}

DistrSampler * LognormalDistrSampler::clone() const
{
    return new LognormalDistrSampler(_m,_s);
}


double LognormalDistrSampler::m() const
{
    return _m;
}

double LognormalDistrSampler::s() const
{
    return _s;
}

