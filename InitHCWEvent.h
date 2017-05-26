#ifndef INITHCWEVENT_H
#define INITHCWEVENT_H

#include "Event.h"
#include "defs.h"

class InitHCWEvent : public Event
{
protected:
    unsigned int _hcw_id;
    typeUIntList _wardIDList;
    typeUIntSet _treatmentIDSet;
    InitHCWEvent(double time, unsigned int hcw_id, const typeUIntList & wardIDList,const typeUIntSet treatmentIDSet);
public:
    virtual std::string str() const;
    unsigned int hcw_id() const;
    const typeUIntList & wardIDList() const;
    const typeUIntSet & treatmentIDSet() const;
    static typeEventPtr createEvent(double time, unsigned int hcw_id, const typeUIntList & wardIDList,const typeUIntSet treatmentIDSet);
};

#endif // INITHCWEVENT_H
