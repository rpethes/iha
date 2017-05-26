#ifndef DEFAULTEVENTREGISTER_H
#define DEFAULTEVENTREGISTER_H

#include <string>
#include "EventRegisterBase.h"
#include "EventFilterBase.h"
#include <fstream>

class DefaultEventRegister : public EventRegisterBase
{

protected:
    std::string _path;
    std::string _baseName;
    EventFilterBase * _filter;
    unsigned int _iterNr;
    std::ofstream * _os;
public:
    DefaultEventRegister(const char * path, const char * baseName, EventFilterBase * filter);
    virtual ~DefaultEventRegister();

    virtual void start();
    virtual void stop();
    virtual void addEvent(typeEventPtr event);
    virtual void addSubEvent(typeEventPtr event, typeEventPtr subEvent);
    virtual void addSubEvents(typeEventPtr event, typeEventPtrList subEvents);
};

#endif // DEFAULTEVENTREGISTER_H
