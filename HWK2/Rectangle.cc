#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(std::string name, float width, float height)
: Shape(name)
{
    this->width = width;
    this->height = height;
    std::cout << "rectangle '" << name << "' created" << std::endl;
}

Rectangle::~Rectangle(void) {
    std::cout << "rectangle '" << name << "' destroyed" << std::endl;
}

float Rectangle::GetArea(void) {
    return width * height;
}

void Rectangle::Draw(void) {
    std::cout << "Shape " << name << std::endl;
    std::cout << "Width = " << width << std::endl;
    std::cout << "Height = " << height << std::endl;

    for (int i = 0; i < height; i++){
        if ( i == 0 || i == height - 1){
            for(int j = 0; j < width; j++)
                std::cout << "*";
            std::cout << std::endl;
        }
        else{
            std::cout << "*";
            for(int k = 0; k < width - 2; k++)
                std::cout << " ";
            std::cout << "*";
            std::cout << std::endl;
        }
    }
}