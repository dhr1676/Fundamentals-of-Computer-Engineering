//
// Created by DING on 2018/1/29.
//

#include "Shape.h"
Shape::Shape(std::string name)
{
    this->name = name;
    std::cout << "shape '" << name << "' created" << std::endl;
}

Shape::~Shape()
{
    std::cout << "shape '" << name << "' destroyed" << std::endl;
}

std::string Shape::GetName(void)
{
    return name;
}

void Shape::Draw() {
}

//  Use GetArea to return the area value
bool Shape::Compare(Object *other) {
    return GetArea() < dynamic_cast<Shape *>(other)->GetArea();
}

//  Print out the name and the area
void Shape::Print() {
    std::cout << "Name is: " << name << " Area is:" << GetArea() << std::endl;
}