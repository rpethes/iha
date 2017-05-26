#include "Properties.h"

Properties::Properties()
{}

void Properties::clear()
{
    typeVariablePtrMap::iterator it = _variables.begin(), end = _variables.end();
    for (; it != end; ++it) {
        delete it->second;
    }
    _variables.clear();
}

Properties::~Properties()
{
    clear();
}


bool Properties::deleteProperty(const char * key)
{
    typeVariablePtrMap::iterator it = _variables.find(key);
    if (it != _variables.end()) {
        delete it->second;
        return true;
    }
    return false;
}

Properties::Properties(const Properties & theOther)
{
    typeVariablePtrMap::const_iterator it = theOther._variables.begin(), end = theOther._variables.end();

    for (; it != end; ++it) {
        VariableBase * variable = it->second->clone();
        _variables[variable->name()] = variable;
    }
}

Properties & Properties::operator=(const Properties & theOther)
{
    if (&theOther == this)
        return *this;

    clear();

    typeVariablePtrMap::const_iterator it = theOther._variables.begin(), end = theOther._variables.end();

    for (; it != end; ++it) {
        VariableBase * variable = it->second->clone();
        _variables[variable->name()] = variable;
    }

    return *this;
}
