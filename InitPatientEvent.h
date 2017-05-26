#ifndef INITPATIENTEVENT_H
#define INITPATIENTEVENT_H

#include "Event.h"


class InitPatientEvent : public Event
{
protected:
    unsigned int _patient_id;
    unsigned int _ward_id;
    double _los;

    InitPatientEvent(double time, unsigned int patient_id, unsigned int ward_id, double los);
public:
    virtual std::string str() const;
    unsigned int patient_id() const;
    unsigned int ward_id() const;
    double los() const;
    static typeEventPtr createEvent(double time, unsigned int patient_id, unsigned int ward_id, double los);
};

#endif // INITPATIENTEVENT_H
