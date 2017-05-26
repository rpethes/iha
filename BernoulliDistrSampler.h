#ifndef BERNOULLIDISTRSAMPLER_H
#define BERNOULLIDISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/bernoulli_distribution.hpp>

class BernoulliDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;
    double _p;
    boost::bernoulli_distribution<double> _distr;

public:
    BernoulliDistrSampler(double p);
    virtual double sample();
    virtual DistrSampler * clone() const;
};

#endif // BERNOULLIDISTRSAMPLER_H
