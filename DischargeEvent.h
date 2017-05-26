#ifndef DISCHARGEEVENT_H
#define DISCHARGEEVENT_H

#include "Event.h"
#include "Patient.h"
#include "defs.h"

class DischargeEvent : public Event
{
protected:
    unsigned int _patient_id;
    typeStringList _colonizedPathogens;
    double _los;
    DischargeEvent(double time, Patient & patient);
public:
    unsigned int patient_id() const;
    const typeStringList & colonizedPathogens() const;
    double los() const;
    static typeEventPtr createEvent(double time, Patient & patient);
    virtual std::string str() const;
};

#endif // DISCHARGEEVENT_H
