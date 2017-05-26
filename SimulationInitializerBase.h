#ifndef SIMULATIONINITIALIZERBASE_H
#define SIMULATIONINITIALIZERBASE_H

#include "ObjectDB.h"
#include "Ward.h"
#include <memory>

class SimulationInitializerBase
{
public:
    SimulationInitializerBase()
    {}

    virtual ~SimulationInitializerBase()
    {}

    virtual void initHCWDB(ObjectDB & hcwDB, typeWardList & wardList) = 0;
    virtual void initPatientDB(ObjectDB & patientDB, typeWardList & wardList) = 0;
};

typedef std::shared_ptr<SimulationInitializerBase> typeSimulationInitializerBasePtr;

#endif // SIMULATIONINITIALIZERBASE_H
