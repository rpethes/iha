#ifndef UTILS_H
#define UTILS_H

#include <list>
#include <string>
#include <sstream>

using namespace std;

template <class T>
string iterableToString(const T & l, const char * delim)
{
    stringstream ss;

    typename T::const_iterator it = l.begin(), end = l.end();

    bool first = true;
    for (; it != end; ++it) {
        if (!first) {
            ss << delim;
        }else
            first = false;

        ss << *it;
    }
    return string(ss.str());
}

#endif // UTILS_H
