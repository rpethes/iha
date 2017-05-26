#ifndef INFECTIONPROCESSBASE_H
#define INFECTIONPROCESSBASE_H

#include "Agent.h"
#include <memory>
#include "Properties.h"
class InfectionProcessBase
{
public:
    virtual bool infectionProcess(double current_time, Agent & agent, Colonization & colonization) = 0;
};

typedef std::shared_ptr<InfectionProcessBase> typeInfectionProcessBasePtr;
#endif // INFECTIONPROCESSBASE_H
