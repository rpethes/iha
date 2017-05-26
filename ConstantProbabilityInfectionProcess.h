#ifndef CONSTANTPROBABILITYINFECTIONPROCESS_H
#define CONSTANTPROBABILITYINFECTIONPROCESS_H

#include "InfectionProcessBase.h"
#include <boost/random.hpp>
#include <boost/random/bernoulli_distribution.hpp>

class ConstantProbabilityInfectionProcess : public InfectionProcessBase
{
protected:
    double _prob;
    boost::mt19937 _random_generator;
public:
    ConstantProbabilityInfectionProcess(double prob);
    virtual bool infectionProcess(double current_time, Agent & agent, Colonization & colonization);
};

#endif // CONSTANTPROBABILITYINFECTIONPROCESS_H
