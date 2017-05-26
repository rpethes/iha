#include "Pathogen.h"
#include "InfectionProcessBase.h"


Pathogen::Pathogen(unsigned int id, typeTransmissionProbabilityBasePtr transmissionProbability, typeInfectionProcessBasePtr infectionProcess) :
    Object(id), _transmissionProbability(transmissionProbability), _infectionProcess(infectionProcess)
{}

Pathogen::Pathogen(unsigned int id, const char * name, typeTransmissionProbabilityBasePtr transmissionProbability, typeInfectionProcessBasePtr infectionProcess) :
    Object(id), _name(name),  _transmissionProbability(transmissionProbability), _infectionProcess(infectionProcess)
{}

const std::string & Pathogen::name() const
{
    return _name;
}

typeTransmissionProbabilityBasePtr Pathogen::transmissionProbability()
{
    return _transmissionProbability;
}

Pathogen::~Pathogen()
{
}

typeInfectionProcessBasePtr Pathogen::infectionProcess()
{
    return _infectionProcess;
}
