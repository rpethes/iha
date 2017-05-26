#ifndef CONSTANTTRANSMISSIONPROBABILITY_H
#define CONSTANTTRANSMISSIONPROBABILITY_H

#include "TransmissionProbabilityBase.h"

class ConstantTransmissionProbability : public TransmissionProbabilityBase
{
protected:
    double _prob;
public:
    ConstantTransmissionProbability(double prob);
    virtual double probability(double contact_length);
};

#endif // CONSTANTTRANSMISSIONPROBABILITY_H
