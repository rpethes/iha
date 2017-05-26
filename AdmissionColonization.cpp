#include "AdmissionColonization.h"

AdmissionColonization::AdmissionColonization(typeDistrSamplerPtr sampler, typePathogenPtr pathogen) :
    _sampler(sampler), _pathogen(pathogen)
{}

AdmissionColonization::~AdmissionColonization()
{
}

Colonization * AdmissionColonization::isColonized(double current_time)
{
    double s = _sampler->sample();
    Colonization * colonization = 0;
    if (s > 0.0) {
        colonization = new Colonization(_pathogen, current_time, ctAdmission, 0);
    }
    return colonization;
}


typePathogenPtr AdmissionColonization::pathogen()
{
    return _pathogen;
}


