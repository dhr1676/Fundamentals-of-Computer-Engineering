//
// Created by DING on 2018/1/29.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
    Shape(std::string name);

//    virtual ~Shape(void);
    ~Shape(void);

    virtual float GetArea(void) = 0;

    std::string GetName(void);

    virtual void Draw(void);

protected:
    std::string name;
};
#endif