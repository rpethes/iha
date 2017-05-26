#ifndef TESTSIMULATIONFACTORY_H
#define TESTSIMULATIONFACTORY_H

#include "SimulationFactory.h"

class TestSimulationFactory : public SimulationFactory
{
public:
    TestSimulationFactory();
    virtual typeSimulationPtr createSimulation();
};

#endif // TESTSIMULATIONFACTORY_H
