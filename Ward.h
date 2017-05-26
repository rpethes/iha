#ifndef WARD_H
#define WARD_H

#include "Admission.h"
#include <list>

class Ward
{
protected:
    unsigned int _wardID;
    typeAdmissionPtr _admission;
    int _bed_number;
public:
    Ward(unsigned int id, typeAdmissionPtr admission, int bed_number);
    virtual ~Ward();
    unsigned int wardID() const;
    typeAdmissionPtr admission();
    int bed_number() const;
};

typedef std::list<Ward*> typeWardList;

#endif // WARD_H
