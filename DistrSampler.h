#ifndef DISTRSAMPLER_H
#define DISTRSAMPLER_H

#include <memory>

class DistrSampler
{
public:
    virtual double sample() = 0;
    virtual DistrSampler * clone() const = 0;
    virtual ~DistrSampler(){}
};

typedef std::shared_ptr<DistrSampler> typeDistrSamplerPtr;

#endif // DISTRSAMPLER_H
