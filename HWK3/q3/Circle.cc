#include "Circle.h"

Circle::Circle(std::string name, float radius)
        : Shape(name)
{
    this->radius = radius;
    std::cout << "circle '" << name << "' created" << std::endl;
}

Circle::~Circle(void)
{
    std::cout << "circle '" << name << "' destroyed" << std::endl;
}

float Circle::GetArea(void)
{
    return 3.141592 * radius * radius;
}