#ifndef UNIFORMDISTRSAMPLER_H
#define UNIFORMDISTRSAMPLER_H

#include "DistrSampler.h"
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>

class UniformDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;
    double _min;
    double _max;
    boost::uniform_real<double> _distr;

public:
    UniformDistrSampler(double minVal, double maxVal);
    virtual double sample();
    virtual DistrSampler * clone() const;
};

#endif // UNIFORMDISTRSAMPLER_H
