//
// Created by DING on 2018/2/23.
//

#ifndef STRING_H
#define STRING_H

#include "Object.h"
#include <iostream>

class String : public Object {
public:
    std::string s;

    String(std::string s);

    void Print();

    bool Compare(Object *object);

    unsigned int Hash();

};
#endif //STRING_H
