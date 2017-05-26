#ifndef DEFAULTTRANSMISSION_H
#define DEFAULTTRANSMISSION_H

#include "TransmissionBase.h"
#include <boost/random.hpp>
#include <boost/random/bernoulli_distribution.hpp>
#include "Colonization.h"

class DefaultTransmission : public TransmissionBase
{
protected:
    boost::mt19937 _random_generator;

    bool transmission(double current_time, double contact_length, ColonizationType cType, Agent & src, Agent & target, Colonization & colonizaton);
public:
    virtual typeEventPtrList transmission(double current_time, TreatmentAssign & treatmentAssign);
};

#endif // DEFAULTTRANSMISSION_H
