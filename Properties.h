#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "Variable.h"

class Properties
{
protected:
    typeVariablePtrMap _variables;
public:
    Properties();
    Properties(const Properties & theOther);
    Properties & operator=(const Properties & theOther);
    ~Properties();

    void clear();
    bool deleteProperty(const char * key);

    template <typename T>
    void set(const char * key, const T & value)
    {
        typeVariablePtrMap::iterator it = _variables.find(key);
        if (it == _variables.end()) {
            VariableBase * variable = new Variable<T>(key, value);
            _variables[key] = variable;
        } else {
            Variable<T> * variable = dynamic_cast<Variable<T> *>(it->second);
            if (variable != 0) {
                variable->set(value);
            } else {
                delete it->second;
                variable = new Variable<T>(key, value);
                _variables[key] = variable;
            }
        }
    }

    template <typename T>
    bool get(const char * key, T & value)
    {
        typeVariablePtrMap::iterator it = _variables.find(key);
        if (it != _variables.end()) {
            Variable<T> * variable = dynamic_cast<Variable<T> *>(it->second);
            if (variable != 0) {
                value = variable->value();
                return true;
            }
        }
        return false;
    }

};

#endif // PROPERTIES_H
