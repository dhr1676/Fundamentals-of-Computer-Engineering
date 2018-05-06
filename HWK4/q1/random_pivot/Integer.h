//
// Created by DING on 2018/2/12.
//

#ifndef INTEGER_H
#define INTEGER_H
#include "Object.h"
class Integer : public Object
{
public:
    int value;
    Integer(int value);
    void Print(void);
    bool Compare(Object *other);
};
#endif