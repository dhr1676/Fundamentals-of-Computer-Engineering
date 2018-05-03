//
// Created by DING on 2018/2/12.
//

#ifndef VECTOR_H
#define VECTOR_H

#include "Object.h"

class Vector {
    Object **objects;
    int size; // Number of elements allocated
    int length; // Number of elements present
    void Grow();

public:
    Vector(int size = 5);

    ~Vector();

    int GetLength();

    void Insert(int index, Object *object);

//    void Insert_Shape(int index, float area);

    Object *Delete(int index);

    Object *Get(int index);

    void Exchange(int index1, int index2);

    void Print(void);
};

#endif