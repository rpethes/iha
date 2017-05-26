#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <list>
#include <memory>

class Event;

typedef std::shared_ptr<Event> typeEventPtr;
typedef std::list<typeEventPtr> typeEventPtrList;


class Event
{

private:
    // NOT COPIABLE
    Event(const Event & event){}
    Event & operator=(const Event & rhs) {return *this;}
protected:
    double _time;
    std::string _name;
    typeEventPtrList _subEvents;
    Event(double time, const char * name);

public:
    void addSubEvent(typeEventPtr event);
    void addSubEvents(const typeEventPtrList & events);

    virtual ~Event();
    const std::string & name() const;
    double time() const;
    virtual std::string str() const = 0;

};



#endif // EVENT_H
