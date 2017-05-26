#include "GammaDistrSampler.h"

boost::mt19937 GammaDistrSampler::_random_generator;

GammaDistrSampler::GammaDistrSampler(double alpha, double beta) :
    _alpha(alpha), _beta(beta), _gamma_distr(alpha, beta)
{}

double GammaDistrSampler::sample()
{
    return _gamma_distr(_random_generator);
}

DistrSampler * GammaDistrSampler::clone() const
{
    return new GammaDistrSampler(_alpha, _beta);
}

double GammaDistrSampler::alpha() const
{
    return _alpha;
}

double GammaDistrSampler::beta() const
{
    return _beta;
}
