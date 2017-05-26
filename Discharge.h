#ifndef DISCHARGE_H
#define DISCHARGE_H

#include "ObjectDB.h"
#include <memory>

class Discharge
{
public:
    Discharge();
    virtual ~Discharge();
    virtual void discharge(double currentTime, ObjectDB & patientDB);
};

typedef std::shared_ptr<Discharge> typeDischargePtr;
#endif // DISCHARGE_H
