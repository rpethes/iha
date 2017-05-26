#ifndef AGENT_H
#define AGENT_H

#include "Object.h"
#include <map>
#include "Properties.h"

class Colonization;

typedef std::map<unsigned int, Colonization *> typeColonizationMap;


class Agent : public Object
{
protected:
    Properties _properties;
    typeColonizationMap _colonizationMap;
public:
    Agent(unsigned int id);
    virtual ~Agent();
    void addColonization(Colonization * colonization);
    void removeColonization(unsigned int pathogenID);
    void removeAllColonization();
    bool isColonizedWith(unsigned int pathogenID);
    typeColonizationMap & colonizationMap();
    Properties & properties();

};

#endif // AGENT_H
