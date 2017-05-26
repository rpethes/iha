#ifndef DEFAULTTREATMENTPROCESSING_H
#define DEFAULTTREATMENTPROCESSING_H

#include "TreatmentProcessingBase.h"
#include "TransmissionBase.h"

class DefaultTreatmentProcessing : public TreatmentProcessingBase
{
protected:
    typeTreatmentAssignList _runningTreatments;
    typeTransmissionBasePtr  _transmission;
public:
    DefaultTreatmentProcessing(typeTransmissionBasePtr transmission);
    virtual void startNewTreatments(double current_time, typeTreatmentAssignList & newTreatments);
    virtual void processTreatments(double current_time, ObjectDB & patientDB, ObjectDB & hcwDB, ObjectDB & treatedPatientDB, ObjectDB & workingHCWDB);

};

#endif // DEFAULTTREATMENTPROCESSING_H
