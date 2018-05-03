//
// Created by DING on 2018/2/12.
//

#ifndef HEAP_H
#define HEAP_H

#include "Vector.h"

class Heap : public Vector {
    int Left(int i);

    int Right(int i);

    int Parent(int i);

public:
    void MaxHeapify(int i, int size);

    void BuildMaxHeap();

    void HeapSort();

};

#endif