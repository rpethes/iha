#ifndef GAUSSDISTRSAMPLER_H
#define GAUSSDISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
class GaussDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;

    double _mean;
    double _standard_deviation;
    boost::normal_distribution<double> _normal_distr;

public:
    GaussDistrSampler(double mean, double standard_deviation);
    virtual double sample();
    virtual DistrSampler * clone() const;
};

#endif // GAUSSDISTRSAMPLER_H
