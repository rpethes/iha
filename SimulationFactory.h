#ifndef SIMULATIONFACTORY_H
#define SIMULATIONFACTORY_H

#include "Simulation.h"
#include <memory>

class SimulationFactory
{
public:
    virtual typeSimulationPtr createSimulation() = 0;
    virtual ~SimulationFactory() {}
};

typedef std::shared_ptr<SimulationFactory> typeSimulationFactoryPtr;
#endif // SIMULATIONFACTORY_H
