#ifndef EXPERIMENT_H
#define EXPERIMENT_H


#include "SimulationFactory.h"

class Experiment
{
protected:
    int _simulationNr;
    std::string _path;
    typeSimulationFactoryPtr _simulationFactory;
public:
    Experiment(int simulationNr, const char * path, typeSimulationFactoryPtr simulationFactory);
    virtual bool run();
};

#endif // EXPERIMENT_H
