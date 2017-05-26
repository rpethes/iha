#ifndef EVENTREGISTERBASE_H
#define EVENTREGISTERBASE_H

#include "Event.h"

class EventRegisterBase
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void addEvent(typeEventPtr event) = 0;
    virtual void addSubEvent(typeEventPtr event, typeEventPtr subEvent) = 0;
    virtual void addSubEvents(typeEventPtr event, typeEventPtrList subEvents) = 0;

    virtual ~EventRegisterBase()
    {}
};

#endif // EVENTREGISTERBASE_H
