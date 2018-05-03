//
// Created by DING on 2018/1/29.
//

#include "Shape.h"
Shape::Shape(std::string name)
{
    this->name = name;
    std::cout << "shape '" << name << "' created" << std::endl;
}

Shape::~Shape(void)
{
    std::cout << "shape '" << name << "' destroyed" << std::endl;
}

std::string Shape::GetName(void)
{
    return name;
}

void Shape::Draw() {
}