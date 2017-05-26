#include "ConstantTransmissionProbability.h"

ConstantTransmissionProbability::ConstantTransmissionProbability(double prob) :
    _prob(prob)
{}

double ConstantTransmissionProbability::probability(double contact_length)
{
    return _prob;
}
