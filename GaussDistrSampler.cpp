#include "GaussDistrSampler.h"


boost::mt19937 GaussDistrSampler::_random_generator;

GaussDistrSampler::GaussDistrSampler(double mean, double standard_deviation) :
    _mean(mean), _standard_deviation(standard_deviation), _normal_distr(mean, standard_deviation)
{}

double GaussDistrSampler::sample()
{
    return _normal_distr(_random_generator);
}

DistrSampler * GaussDistrSampler::clone() const
{
    return new GaussDistrSampler(_mean, _standard_deviation);
}
