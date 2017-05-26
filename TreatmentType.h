#ifndef TREATMENTTYPE_H
#define TREATMENTTYPE_H

#include <string>
#include "Object.h"

class TreatmentType : public Object
{
protected:
    std::string _name;
public:
    TreatmentType(unsigned int id);
    TreatmentType(unsigned int id, const char * treatmentName);
    const std::string & name() const;
    virtual ~TreatmentType();
};

#endif // TREATMENTTYPE_H
