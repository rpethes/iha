#ifndef INFECTIONEVENT_H
#define INFECTIONEVENT_H

#include "Event.h"

class InfectionEvent : public Event
{
protected:
    unsigned int _id;
    std::string _pathogen;
    double _colonization_time;
    InfectionEvent(double time, unsigned int id, const char * pathogen, double colonization_time);
public:
    static typeEventPtr createEvent(double time, unsigned int id, const char * pathogen, double colonization_time);

    virtual std::string str() const;
    unsigned int id() const;
    const std::string & pathogen() const;
    double colonization_time() const;
};

#endif // INFECTIONEVENT_H
