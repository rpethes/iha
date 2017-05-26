#include "TreatmentType.h"

TreatmentType::TreatmentType(unsigned int id) : Object(id)
{}

TreatmentType::TreatmentType(unsigned int id, const char * treatmentName):
    Object(id), _name(treatmentName)
{}

const std::string & TreatmentType::name() const
{
    return _name;
}

TreatmentType::~TreatmentType()
{}
