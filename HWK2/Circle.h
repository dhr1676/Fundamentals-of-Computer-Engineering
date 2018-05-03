#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(std::string name, float radius);

    ~Circle(void);

    float GetArea(void);

private:
    float radius;
};

#endif