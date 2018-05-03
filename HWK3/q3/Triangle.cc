#include "Triangle.h"

Triangle::Triangle(std::string name, float base, float height)
        : Shape(name) {
    this->base = base;
    this->height = height;
    std::cout << "triangle '" << name << "' created" << std::endl;
}

Triangle::~Triangle(void) {
    std::cout << "triangle '" << name << "' destroyed" << std::endl;
}

float Triangle::GetArea(void) {
    return base * height / 2.0;
}