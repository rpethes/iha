#include "RegisterProvider.h"
#include "log.h"


RegisterProvider::RegisterProvider() : _eventRegister(0)
{}

RegisterProvider & RegisterProvider::instance()
{
    static RegisterProvider provider;
    return provider;
}

void RegisterProvider::set(EventRegisterBase * eventRegister)
{
    if (_eventRegister) {
        _eventRegister->stop();
        delete _eventRegister;
        _eventRegister = 0;
    }

    _eventRegister = eventRegister;
}

EventRegisterBase * RegisterProvider::get()
{
    return _eventRegister;
}

RegisterProvider::~RegisterProvider()
{
    if (_eventRegister) {
        _eventRegister->stop();
    }

    delete _eventRegister;
    _eventRegister = 0;
}

void RegisterProvider::start()
{
    if (_eventRegister)
        _eventRegister->start();
    else
        ERR << "_eventRegister is NULL";
}

void RegisterProvider::stop()
{
    if (_eventRegister)
        _eventRegister->stop();
    else
        ERR << "_eventRegister is NULL";
}

void RegisterProvider::addEvent(typeEventPtr event)
{
    if (_eventRegister)
        _eventRegister->addEvent(event);
    else
        ERR << "_eventRegister is NULL";
}

void RegisterProvider::addSubEvent(typeEventPtr event, typeEventPtr subEvent)
{
    if (_eventRegister)
        _eventRegister->addSubEvent(event, subEvent);
    else
        ERR << "_eventRegister is NULL";
}

void RegisterProvider::addSubEvents(typeEventPtr event, typeEventPtrList subEvents)
{
    if (_eventRegister)
        _eventRegister->addSubEvents(event, subEvents);
    else
        ERR << "_eventRegister is NULL";
}
