#ifndef DEFAULTEVENTFILTER_H
#define DEFAULTEVENTFILTER_H

#include "EventFilterBase.h"

class DefaultEventFilter : public EventFilterBase
{
public:
    virtual bool filterEvent(const Event & event)
    {
        return true;
    }

    virtual bool filterSubEvent(const Event & event, const Event & subEvent)
    {
        return true;
    }
};

#endif // DEFAULTEVENTFILTER_H
