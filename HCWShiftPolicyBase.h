#ifndef HCWSHIFTPOLICYBASE_H
#define HCWSHIFTPOLICYBASE_H

#include "ObjectDB.h"

class HCWShiftPolicyBase
{
public:
    HCWShiftPolicyBase();
    virtual ~HCWShiftPolicyBase();
    virtual void doShift(ObjectDB & hcwDB, double current_time);

};

#endif // HCWSHIFTPOLICYBASE_H
