#ifndef PATHOGEN_H
#define PATHOGEN_H

#include <string>
#include "Object.h"
#include "TransmissionProbabilityBase.h"
#include "InfectionProcessBase.h"
#include <memory>

class InfectionProcessBase;

class Pathogen : public Object
{
protected:
    std::string _name;
    typeTransmissionProbabilityBasePtr _transmissionProbability;
    typeInfectionProcessBasePtr _infectionProcess;
public:
    Pathogen(unsigned int id, typeTransmissionProbabilityBasePtr transmissionProbability, typeInfectionProcessBasePtr infectionProcess);
    Pathogen(unsigned int id, const char * name, typeTransmissionProbabilityBasePtr transmissionProbability, typeInfectionProcessBasePtr infectionProcess);
    const std::string & name() const;
    typeTransmissionProbabilityBasePtr transmissionProbability();
    typeInfectionProcessBasePtr infectionProcess();
    virtual ~Pathogen();
};

typedef std::shared_ptr<Pathogen> typePathogenPtr;
#endif // PATHOGEN_H
