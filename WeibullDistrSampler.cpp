#include "WeibullDistrSampler.h"

boost::mt19937 WeibullDistrSampler::_random_generator;

WeibullDistrSampler::WeibullDistrSampler(double a, double b) :
    _a(a), _b(b), _weibull_distr(a,b)
{}

double WeibullDistrSampler::sample()
{
    return _weibull_distr(_random_generator);
}

DistrSampler * WeibullDistrSampler::clone() const
{
    return new WeibullDistrSampler(_a, _b);
}

double WeibullDistrSampler::a() const
{
    return _a;
}

double WeibullDistrSampler::b() const
{
    return _b;
}
