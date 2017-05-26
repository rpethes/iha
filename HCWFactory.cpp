#include "HCWFactory.h"

HCWFactory::HCWFactory() : _next_id(1)
{}

HCW * HCWFactory::create(double start_shift_time,
             double stop_shift_time,
             bool is_working,
             const typeUIntSet & treatmentIDSet,
             const typeUIntList & wardIDList,
             ObjectDB & db)
{
    HCW * obj = new HCW(_next_id,
                        start_shift_time,
                        stop_shift_time,
                        is_working,
                        treatmentIDSet,
                        wardIDList);
    ++_next_id;
    db.set(obj);
    return obj;
}
