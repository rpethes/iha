#ifndef OBJECT_H
#define OBJECT_H

class Object
{
protected:
    unsigned int _id;
public:
    unsigned int id() const
    {
        return _id;
    }

    Object(unsigned int id) : _id(id)
    {}

    virtual ~Object()
    {}
};

#endif // OBJECT_H
