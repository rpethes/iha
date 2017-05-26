#ifndef COHORTSTRATEGYBASE_H
#define COHORTSTRATEGYBASE_H

#include "defs.h"
#include "ObjectDB.h"
#include "Patient.h"

class CohortStrategyBase
{
public:
    virtual typeUIntList availableHCWs(const ObjectDB & hcwDB, unsigned int patientID) = 0;
    virtual void patientAdmission(Patient & patient, ObjectDB & hcwDB) = 0;
    virtual void patientDischarge(Patient & patient) = 0;
    virtual ~CohortStrategyBase() {}
};

#endif // COHORTSTRATEGYBASE_H
