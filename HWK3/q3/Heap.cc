//
// Created by DING on 2018/2/12.
//

#include "Heap.h"

int Heap::Left(int i) {
    return i * 2 + 1;
}

int Heap::Right(int i) {
    return i * 2 + 2;
}

int Heap::Parent(int i) {
    return (i - 1) / 2;
}

//void Heap::MaxHeapify(int i, int size) {
//    int l;
//    int r;
//    int max;
//// Get children
//    l = Left(i);
//    r = Right(i);
//// Calculate max between i/left/right
//    if (l < size && Get(i)->Compare(Get(l)))
//        max = l;
//    else
//        max = i;
//    if (r < size && Get(max)->Compare(Get(r)))
//        max = r;
//    // If heap property is not satisfied for i
//    if (max != i) {
//        Exchange(i, max);
//        MaxHeapify(max, size);
//    }
//}

//    Iterate version of MaxHeapify
void Heap::MaxHeapify(int i, int size) {
    int l, r, max;
    for(int j = i; j < size; ) {
        // Get children
        l = Left(j);
        r = Right(j);
        if( l < size && Get(j)->Compare(Get(l)))
            max = l;
        else
            max = j;

        if( r < size && Get(max)->Compare(Get(r)))
            max = r;

        if( max != j) {
            Exchange(j, max);
            j = max;
        } else
            return;
    }
}

void Heap::BuildMaxHeap() {
    for (int i = Parent(GetLength() - 1); i >= 0; i--)
        MaxHeapify(i, GetLength());
}

void Heap::HeapSort() {
    BuildMaxHeap();
    for (int i = GetLength() - 1; i >= 1; i--) {
        Exchange(0, i);
        MaxHeapify(0, i);
    }
}
