#ifndef HCWFACTORY_H
#define HCWFACTORY_H

#include "HCW.h"
#include "ObjectDB.h"
#include <memory>

class HCWFactory
{
protected:
    unsigned int _next_id;

public:
    HCWFactory();
    HCW * create(double start_shift_time,
                 double stop_shift_time,
                 bool is_working,
                 const typeUIntSet & treatmentIDSet,
                 const typeUIntList & wardIDList,
                 ObjectDB & db);

};

typedef std::shared_ptr<HCWFactory> typeHCWFactoryPtr;
#endif // HCWFACTORY_H
