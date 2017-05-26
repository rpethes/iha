#ifndef COLONIZATION_H
#define COLONIZATION_H

#include "Pathogen.h"

enum ColonizationType
{
    ctUndefined = 0,
    ctHCW = 1,
    ctPatient = 2,
    ctAdmission = 3
};


class Colonization
{
protected:
    typePathogenPtr _pathogen;
    double _colonizationTime;
    ColonizationType _colonizationType;
    unsigned int _sourceID;
    bool _isSympthomatic;
public:
    Colonization(typePathogenPtr pathogen,
                 double colonizationTime,
                 ColonizationType colonizationType,
                 unsigned int sourceID);

    virtual ~Colonization();

    typePathogenPtr pathogen();
    double colonizationTime() const;
    ColonizationType colonizationType() const;
    unsigned int sourceID() const;
    bool isSympthomatic() const;
    void setSympthomatic(bool isSympthomatic);

};

#endif // COLONIZATION_H
