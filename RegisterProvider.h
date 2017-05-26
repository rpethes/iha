#ifndef REGISTERPROVIDER_H
#define REGISTERPROVIDER_H

#include "EventRegisterBase.h"

class RegisterProvider : public EventRegisterBase
{
private:
    EventRegisterBase * _eventRegister;
    RegisterProvider();
public:
    static RegisterProvider & instance();
    void set(EventRegisterBase * eventRegister);
    EventRegisterBase * get();
    ~RegisterProvider();

    virtual void start();
    virtual void stop();
    virtual void addEvent(typeEventPtr event);
    virtual void addSubEvent(typeEventPtr event, typeEventPtr subEvent);
    virtual void addSubEvents(typeEventPtr event, typeEventPtrList subEvents);

};

#endif // REGISTERPROVIDER_H
