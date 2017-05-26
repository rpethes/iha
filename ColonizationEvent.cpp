#include "ColonizationEvent.h"

ColonizationEvent::ColonizationEvent(double time, const char * name, const char * pathogen, unsigned int target_id) :
    Event(time, name), _pathogen(pathogen), _target_id(target_id)
{}

const std::string & ColonizationEvent::pathogen() const
{
    return _pathogen;
}

unsigned int ColonizationEvent::target_id() const
{
    return _target_id;
}
