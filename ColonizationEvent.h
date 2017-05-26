#ifndef COLONIZATIONEVENT_H
#define COLONIZATIONEVENT_H

#include "Event.h"

class ColonizationEvent : public Event
{
protected:
    std::string _pathogen;
    unsigned int _target_id;
    ColonizationEvent(double time, const char * name, const char * pathogen, unsigned int target_id);
public:

    const std::string & pathogen() const;
    unsigned int target_id() const;

};

#endif // COLONIZATIONEVENT_H
