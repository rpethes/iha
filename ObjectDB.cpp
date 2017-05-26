#include "ObjectDB.h"
#include <algorithm>

ObjectDB::ObjectDB()
{}

ObjectDB::~ObjectDB()
{}

void ObjectDB::set(Object * obj)
{
    _db[obj->id()] = obj;
}

Object * ObjectDB::get(unsigned int id)
{
    typeObjectDBMap::iterator it = _db.find(id);
    if (it == _db.end())
        return 0;
    return it->second;
}

Object * ObjectDB::remove_and_get(unsigned int id)
{
    typeObjectDBMap::iterator it = _db.find(id);
    if (it == _db.end())
        return 0;
    Object * obj = it->second;

    _db.erase(it);

    return obj;
}

bool ObjectDB::remove_and_delele(unsigned int id)
{
    typeObjectDBMap::iterator it = _db.find(id);
    if (it == _db.end())
        return false;

    delete it->second;

    _db.erase(it);
    return true;
}

typeUIntList ObjectDB::keys() const
{
    typeUIntList keys;
    std::transform(_db.begin(), _db.end(), back_inserter(keys), RetrieveKey());
    return keys;
}

typeObjectPtrArray ObjectDB::values() const
{
    typeObjectPtrArray values;
    std::transform(_db.begin(), _db.end(), back_inserter(values), RetrieveValue());
    return values;
}

typeObjectDBMap & ObjectDB::db()
{
    return _db;
}

const typeObjectDBMap & ObjectDB::const_db() const
{
    return _db;
}
