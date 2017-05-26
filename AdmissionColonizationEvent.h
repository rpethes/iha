#ifndef ADMISSIONCOLONIZATIONEVENT_H
#define ADMISSIONCOLONIZATIONEVENT_H

#include "ColonizationEvent.h"

class AdmissionColonizationEvent : public ColonizationEvent
{
protected:
    AdmissionColonizationEvent(double time, const char * pathogen, unsigned int target_id);
public:

    virtual std::string str() const;

    static typeEventPtr createEvent(double time, const char * pathogen, unsigned int target_id);
};

#endif // ADMISSIONCOLONIZATIONEVENT_H
