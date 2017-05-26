#include "DefaultEventRegister.h"
#include <sstream>
#include "log.h"

DefaultEventRegister::DefaultEventRegister(const char * path, const char * baseName, EventFilterBase * filter) :
    _path(path),_baseName(baseName), _filter(filter), _iterNr(0), _os(0)
{}

DefaultEventRegister::~DefaultEventRegister()
{
    stop();
    delete _os;
    delete _filter;
}

void DefaultEventRegister::start()
{
    ++_iterNr;
    std::stringstream ss;
    ss <<_path << "/" << _baseName << "_" << _iterNr;
    if (_os) {
        delete _os;
        _os = 0;
    }
    _os = new std::ofstream(ss.str().c_str());
}

void DefaultEventRegister::stop()
{
    if (_os) {
        _os->flush();
        _os->close();
        delete _os;
        _os = 0;
    }
}

void DefaultEventRegister::addEvent(typeEventPtr event)
{
    if (_os) {
        if (_filter->filterEvent(*event)) {
            (*_os) << event->str() << std::endl;
        }
    }else {
        ERR << "DefaultEventRegister is not started!";
    }
}

void DefaultEventRegister::addSubEvent(typeEventPtr event, typeEventPtr subEvent)
{
    if (_os) {
        if (_filter->filterSubEvent(*event, *subEvent)) {
            event->addSubEvent(subEvent);
        }
    }else {
        ERR << "DefaultEventRegister is not started!";
    }
}

void DefaultEventRegister::addSubEvents(typeEventPtr event, typeEventPtrList subEvents)
{
    if (_os) {
       typeEventPtrList::iterator it = subEvents.begin(), end = subEvents.end();
       for (; it!= end; ++it) {
           if (_filter->filterSubEvent(*event, **it)) {
               event->addSubEvent(*it);
           }
       }
    }else {
        ERR << "DefaultEventRegister is not started!";
    }
}
