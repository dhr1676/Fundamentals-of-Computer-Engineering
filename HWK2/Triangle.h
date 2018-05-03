#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(std::string name, float base, float height);

    ~Triangle(void);

    float GetArea(void);

private:
    float base;
    float height;
};

#endif