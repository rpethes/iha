#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <map>

class VariableBase
{
protected:
    std::string _name;

public:
    VariableBase(const char * name) :
        _name(name)
    {}

    const std::string & name() const
    {
        return _name;
    }

    virtual ~VariableBase()
    {}

    virtual VariableBase * clone() const = 0;
};



template <class T>
class Variable : public VariableBase
{
public:
    typedef T typeVariable;
protected:
    typeVariable _value;
public:
    Variable(const char * name, const typeVariable & value) :
        VariableBase(name), _value(value)
    {}

    typeVariable & value()
    {
        return _value;
    }

    void set(const typeVariable & value)
    {
        _value = value;
    }

    virtual VariableBase * clone() const
    {
        return new Variable<typeVariable>(_name.c_str(), _value);
    }
};

typedef Variable<bool> typeBoolVariable;
typedef Variable<double> typeDoubleVariable;
typedef Variable<int> typeIntVariable;
typedef Variable<std::string> typeStringVariable;

typedef std::map<std::string, VariableBase *> typeVariablePtrMap;

#endif // VARIABLE_H
