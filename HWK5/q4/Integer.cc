//
// Created by DING on 2018/2/12.
//

#include <iostream>
#include "Integer.h"

Integer::Integer(int value) {
    this->value = value;
//    this->index = index;
}

void Integer::Print(void) {
    std::cout << value << std::endl;
}

bool Integer::Compare(Object *other) {
    return value < dynamic_cast<Integer *>(other)->value;
}