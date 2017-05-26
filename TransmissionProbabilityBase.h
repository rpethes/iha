#ifndef TRANSMISSIONRATE_H
#define TRANSMISSIONRATE_H

#include <memory>

class TransmissionProbabilityBase
{
public:
    virtual double probability(double contact_length) = 0;
    virtual ~TransmissionProbabilityBase(){}
};

typedef std::shared_ptr<TransmissionProbabilityBase> typeTransmissionProbabilityBasePtr;
#endif // TRANSMISSIONRATE_H
