#ifndef EVENTFILTERBASE_H
#define EVENTFILTERBASE_H

#include "Event.h"

class EventFilterBase
{
public:
    virtual ~EventFilterBase() {}

    virtual bool filterEvent(const Event & event) = 0;
    virtual bool filterSubEvent(const Event & event, const Event & subEvent) = 0;
};

#endif // EVENTFILTERBASE_H
