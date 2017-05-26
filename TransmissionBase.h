#ifndef TRANSMISSIONBASE_H
#define TRANSMISSIONBASE_H

#include "TreatmentAssign.h"
#include "Event.h"

class TransmissionBase
{
public:
    virtual typeEventPtrList transmission(double current_time, TreatmentAssign & treatmentAssign) = 0;
    virtual ~TransmissionBase() {}
};

typedef std::shared_ptr<TransmissionBase> typeTransmissionBasePtr;

#endif // TRANSMISSIONBASE_H
