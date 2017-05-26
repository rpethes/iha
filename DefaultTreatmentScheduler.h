#ifndef DEFAULTTREATMENTSCHEDULER_H
#define DEFAULTTREATMENTSCHEDULER_H

#include "TreatmentSchedulerBase.h"

class DefaultTreatmentScheduler : public TreatmentSchedulerBase
{
protected:
    double _urgency_threshold;
public:
    DefaultTreatmentScheduler(double urgency_threshold);
    virtual void doSchedule(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB,  typeTreatmentAssignList & treatmentAssignList);
};

#endif // DEFAULTTREATMENTSCHEDULER_H
