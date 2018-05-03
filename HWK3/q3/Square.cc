//
// Created by DING on 2018/1/30.
//

#include <iostream>
#include "Square.h"

Square::Square(std::string name, float length) : Rectangle(name, length, length)
{
    this->length = length;
    std::cout << "Square '" << name << "' created" << std::endl;
}

Square::~Square(void) {
    std::cout << "square '" << name << "' destroyed" << std::endl;
}

float Square::GetArea(void) {
    return length * length;
}

void Square::Draw(void) {
    std::cout << "Shape " << name << std::endl;
    std::cout << "Length = " << length << std::endl;

    for (int i = 0; i < length; i++){
        if ( i == 0 || i == length - 1){
            for(int j = 0; j < length; j++)
                std::cout << "*";
            std::cout << std::endl;
        }
        else{
            std::cout << "*";
            for(int k = 0; k < length - 2; k++)
                std::cout << " ";
            std::cout << "*";
            std::cout << std::endl;
        }
    }
}