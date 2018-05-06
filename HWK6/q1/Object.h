//
// Created by DING on 2018/2/12.
//

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
    virtual void Print(void) = 0;

    virtual bool Compare(Object *) = 0;

    virtual unsigned int Hash();

    virtual bool Equals(Object *);
};

#endif