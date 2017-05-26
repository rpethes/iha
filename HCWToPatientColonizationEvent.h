#ifndef HCWTOPATIENTCOLONIZATIONEVENT_H
#define HCWTOPATIENTCOLONIZATIONEVENT_H

#include "ColonizationEvent.h"

class HCWToPatientColonizationEvent : public ColonizationEvent
{
protected:
    unsigned int _hcw_id;
    HCWToPatientColonizationEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id);
public:
    virtual std::string str() const;
    static typeEventPtr createEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id);
};

#endif // HCWTOPATIENTCOLONIZATIONEVENT_H
