#ifndef DEFAULTCOHORTSTRATEGY_H
#define DEFAULTCOHORTSTRATEGY_H

#include "CohortStrategyBase.h"

class DefaultCohortStrategy : public CohortStrategyBase
{
public:
    virtual typeUIntList availableHCWs(const ObjectDB & hcwDB, unsigned int patientID);
    virtual void patientAdmission(Patient & patient, ObjectDB & hcwDB);
    virtual void patientDischarge(Patient & patient);
};


#endif // DEFAULTCOHORTSTRATEGY_H
