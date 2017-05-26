#ifndef DEFS_H
#define DEFS_H

#include <list>
#include <set>
#include <string>

typedef std::list<unsigned int> typeUIntList;
typedef std::set<unsigned int> typeUIntSet;
typedef std::list<std::string> typeStringList;

struct RetrieveKey
{
    template <typename T>
    typename T::first_type operator()(T keyValuePair) const
    {
        return keyValuePair.first;
    }
};

struct RetrieveValue
{
    template <typename T>
    typename T::second_type operator()(T keyValuePair) const
    {
        return keyValuePair.second;
    }
};

#endif // DEFS_H
