//
// Created by DING on 2018/1/30.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(std::string name, float width, float height);
    ~Rectangle(void);
    float GetArea(void);
    void Draw(void);
private:
    float width;
    float height;
};
#endif