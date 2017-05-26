#ifndef EXPDISTRSAMPLER_H
#define EXPDISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/exponential_distribution.hpp>

class ExpDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;
    double _lambda;
    boost::exponential_distribution<double> _distr;

public:
    ExpDistrSampler(double lambda);
    virtual double sample();
    virtual DistrSampler * clone() const;
};

#endif // EXPDISTRSAMPLER_H
