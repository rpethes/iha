#ifndef ADMISSIONCOLONIZATION_H
#define ADMISSIONCOLONIZATION_H

#include "DistrSampler.h"
#include "Pathogen.h"
#include "Colonization.h"
#include <list>

class AdmissionColonization
{
protected:
    typeDistrSamplerPtr _sampler;
    typePathogenPtr _pathogen;
public:
    AdmissionColonization(typeDistrSamplerPtr sampler, typePathogenPtr pathogen);
    virtual ~AdmissionColonization();
    typePathogenPtr  pathogen();
    virtual Colonization * isColonized(double current_time);
};

typedef std::list<AdmissionColonization *> typeAdmissionColonizationPtrList;

#endif // ADMISSIONCOLONIZATION_H
