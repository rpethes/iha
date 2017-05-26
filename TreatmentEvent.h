#ifndef TREATMENTEVENT_H
#define TREATMENTEVENT_H

#include "Event.h"
#include "TreatmentAssign.h"
#include "defs.h"

class TreatmentEvent : public Event
{
protected:
    unsigned int _patient_id;
    unsigned int _treatmentTypeID;
    double _treatmentStopTime;
    typeUIntList _hcws;
    TreatmentEvent(double time, TreatmentAssign & assign);
public:

    virtual std::string str() const;

    static typeEventPtr createEvent(double time, TreatmentAssign & assign);
};

#endif // TREATMENTEVENT_H
