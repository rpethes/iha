#ifndef GAMMADISTRSAMPLER_H
#define GAMMADISTRSAMPLER_H

#include "DistrSampler.h"

#include <boost/random.hpp>
#include <boost/random/gamma_distribution.hpp>

class GammaDistrSampler : public DistrSampler
{
protected:
    static boost::mt19937 _random_generator;

    double _alpha;
    double _beta;
    boost::gamma_distribution<double> _gamma_distr;

public:
    GammaDistrSampler(double alpha, double beta);
    virtual double sample();
    virtual DistrSampler * clone() const;
    double alpha() const;
    double beta() const;
};

#endif // GAMMADISTRSAMPLER_H
