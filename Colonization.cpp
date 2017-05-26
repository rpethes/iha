#include "Colonization.h"

Colonization::Colonization(typePathogenPtr pathogen,
             double colonizationTime,
             ColonizationType colonizationType,
             unsigned int sourceID) :
    _pathogen(pathogen),
    _colonizationTime(colonizationTime),
    _colonizationType(colonizationType),
    _sourceID(sourceID),
    _isSympthomatic(false)
{}

Colonization::~Colonization()
{}

typePathogenPtr Colonization::pathogen()
{
    return _pathogen;
}


double Colonization::colonizationTime() const
{
    return _colonizationTime;
}


ColonizationType Colonization::colonizationType() const
{
    return _colonizationType;
}

unsigned int Colonization::sourceID() const
{
    return _sourceID;
}


bool Colonization::isSympthomatic() const
{
    return _isSympthomatic;
}

void Colonization::setSympthomatic(bool isSympthomatic)
{
    _isSympthomatic = isSympthomatic;
}
