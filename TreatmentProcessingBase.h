#ifndef TREATMENTPROCESSINGBASE_H
#define TREATMENTPROCESSINGBASE_H

#include "TreatmentAssign.h"
#include "ObjectDB.h"
#include <memory>

class TreatmentProcessingBase
{
public:

    virtual void startNewTreatments(double current_time, typeTreatmentAssignList & newTreatments) = 0;
    virtual void processTreatments(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB) = 0;
    virtual ~TreatmentProcessingBase()
    {}
};

typedef std::shared_ptr<TreatmentProcessingBase> typeTreatmentProcessingBasePtr;
#endif // TREATMENTPROCESSINGBASE_H
