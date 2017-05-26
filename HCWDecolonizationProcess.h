#ifndef HCWDECOLONIZATIONPROCESS_H
#define HCWDECOLONIZATIONPROCESS_H

#include "ObjectDB.h"
#include <memory>

class HCWDecolonizationProcess
{
public:
    virtual void decolonizationProcess(double current_time, ObjectDB & hcwDB) = 0;
    virtual ~HCWDecolonizationProcess()
    {}
};

typedef std::shared_ptr<HCWDecolonizationProcess> typeHCWDecolonizationProcessPtr;

#endif // HCWDECOLONIZATIONPROCESS_H
