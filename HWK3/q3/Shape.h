//
// Created by DING on 2018/1/29.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "Object.h"

// Inheriting from the Object,
// which makes every child shape class, like Rectangle, Circle,
// into the subclass of Object

class Shape : public Object
{
public:
    Shape(std::string name);

//    virtual ~Shape(void);
    ~Shape();

    virtual float GetArea(void) = 0;

    std::string GetName(void);

    virtual void Draw(void);

//  Implement the virtual function in the Object
//  Otherwise, you cannot instantiate the child class
    bool Compare(Object *other);

    void Print(void);

protected:
    std::string name;
};
#endif