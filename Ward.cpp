#include "Ward.h"

Ward::Ward(unsigned int id, typeAdmissionPtr admission, int bed_number) :
    _wardID(id), _admission(admission), _bed_number(bed_number)
{}

Ward::~Ward()
{}

unsigned int Ward::wardID() const
{
    return _wardID;
}

typeAdmissionPtr Ward::admission()
{
    return _admission;
}

int Ward::bed_number() const
{
    return _bed_number;
}
