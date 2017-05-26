#ifndef TREATMETSCHEDULERBASE_H
#define TREATMETSCHEDULERBASE_H


#include "TreatmentAssign.h"
#include <list>
#include "ObjectDB.h"
#include "Patient.h"
#include <memory>

class TreatmentSchedulerBase
{
public:
    virtual void doSchedule(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB,  typeTreatmentAssignList & treatmentAssignList) = 0;
    virtual ~TreatmentSchedulerBase() {}
};

typedef std::shared_ptr<TreatmentSchedulerBase> typeTreatmentSchedulerBasePtr;
#endif // TREATMETSCHEDULERBASE_H
