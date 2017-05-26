#ifndef WEIBULLDISTRSAMPLER_H
#define WEIBULLDISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/weibull_distribution.hpp>

using namespace boost;
class WeibullDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;

    double _a;
    double _b;
    random::weibull_distribution<double> _weibull_distr;

public:
    WeibullDistrSampler(double a, double b);
    virtual double sample();
    virtual DistrSampler * clone() const;
    double a() const;
    double b() const;
};

#endif // WEIBULLDISTRSAMPLER_H
