#ifndef PATIENTTOHCWCOLONIZATION_H
#define PATIENTTOHCWCOLONIZATION_H

#include "ColonizationEvent.h"


class PatientToHCWColonizationEvent : public ColonizationEvent
{
protected:
    unsigned int _patient_id;
    PatientToHCWColonizationEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id);
public:
    virtual std::string str() const;
    static typeEventPtr createEvent(double time, const char * pathogen, unsigned int patient_id, unsigned int hcw_id);
};

#endif // PATIENTTOHCWCOLONIZATION_H
