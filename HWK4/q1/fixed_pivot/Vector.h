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

    void QuickSort(int left, int right);
    int QuickSortPartition(int left, int right);

    void QuickSortRandomPivot(int left, int right);
    int QuickSortPartitionRandomPivot(int left, int right);

public:
    Vector(int size = 5);

    ~Vector();

    int GetLength();

    void Insert(int index, Object *object);

    Object *Delete(int index);

    Object *Get(int index);

    void Exchange(int index1, int index2);

    void Print(void);

    void QuickSort();

    void QuickSortRandomPivot();
};

#endif