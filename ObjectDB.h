#ifndef OBJECTDB_H
#define OBJECTDB_H

#include "Object.h"
#include <map>
#include "defs.h"
#include <vector>

typedef std::map<unsigned int, Object *>  typeObjectDBMap;
typedef std::vector<Object*> typeObjectPtrArray;
typedef std::list<Object*> typeObjectPtrList;

class ObjectDB
{
protected:
    typeObjectDBMap _db;
public:
    ObjectDB();
    virtual ~ObjectDB();
    void set(Object * obj);
    Object * get(unsigned int id);
    Object * remove_and_get(unsigned int id);
    bool remove_and_delele(unsigned int id);
    typeUIntList keys() const;
    typeObjectPtrArray values() const;
    typeObjectDBMap & db();
    const typeObjectDBMap & const_db() const;
};

#endif // OBJECTDB_H
