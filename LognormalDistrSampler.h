#ifndef LOGNORMALDISTRSAMPLER_H
#define LOGNORMALDISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/lognormal_distribution.hpp>

class LognormalDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;
    double _m;
    double _s;
    boost::lognormal_distribution<double> _lognormal_distr;

public:
    LognormalDistrSampler(double m, double s);
    virtual double sample();
    virtual DistrSampler * clone() const;
    double m() const;
    double s() const;
};

#endif // LOGNORMALDISTRSAMPLER_H
