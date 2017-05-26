#include "Agent.h"
#include "Colonization.h"


Agent::Agent(unsigned int id) : Object(id)
{}

Agent::~Agent()
{
    typeColonizationMap::iterator it = _colonizationMap.begin(), end = _colonizationMap.end();
    for (; it != end; ++it) {
        delete it->second;
    }
}

void Agent::addColonization(Colonization * colonization)
{
    _colonizationMap[colonization->pathogen()->id()] = colonization;
}

void Agent::removeColonization(unsigned int pathogenID)
{
   typeColonizationMap::iterator it = _colonizationMap.find(pathogenID);
   if (it != _colonizationMap.end()) {
       delete it->second;
       _colonizationMap.erase(it);
   }
}

void Agent::removeAllColonization()
{
    typeColonizationMap::iterator it = _colonizationMap.begin(), end = _colonizationMap.end();
    for (; it != end; ++it) {
        delete it->second;
    }
    _colonizationMap.clear();
}

bool Agent::isColonizedWith(unsigned int pathogenID)
{
    typeColonizationMap::iterator it = _colonizationMap.find(pathogenID);

    bool isColonized = (it != _colonizationMap.end());

    return isColonized;
}

typeColonizationMap & Agent::colonizationMap()
{
    return _colonizationMap;
}

Properties & Agent::properties()
{
    return _properties;
}
