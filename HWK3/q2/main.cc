#include <iostream>
#include "Heap.h"
#include "Integer.h"

int main() {
// Create heap
    Heap heap;
// Insert 7 elements
    heap.Insert(0, new Integer(5));
    heap.Insert(1, new Integer(3));
    heap.Insert(2, new Integer(6));
    heap.Insert(3, new Integer(1));
    heap.Insert(4, new Integer(2));
    heap.Insert(5, new Integer(0));
    heap.Insert(6, new Integer(4));
    heap.Insert(7, new Integer(7));
    heap.Insert(8, new Integer(8));
//    Print all elements
    std::cout << "Input heap: " << std::endl;
    heap.Print();
    std::cout << '\n';

    std::cout << "Use iterative MaxHeapify approach to build MaxHeap." << std::endl;
    heap.BuildMaxHeap();
    std::cout << "MaxHeap: " << std::endl;
    heap.Print();
    std::cout << '\n';

    std::cout << "Then we test the ExtractMax() function\n"
            "Extract the Max element of the heap" << std::endl;
    heap.ExtractMax()->Print();
    std::cout << '\n';
    std::cout << "After extraction" << std::endl;
    heap.Print();
    std::cout << '\n';

    std::cout << "Then we test the HeapInsert() function" << std::endl;
    Integer *number;
    number = new Integer(8);
    heap.HeapInsert(number);
    std::cout << '\n';
    std::cout << "After Insert: " << std::endl;
    heap.Print();
    std::cout << std::endl;

// Sort them and print again
    heap.HeapSort();
    std::cout << "After Sort: " << std::endl;
    heap.Print();
// Free elements
    for (int i = 0; i < heap.GetLength(); i++)
        delete (Integer *) heap.Get(i);
// End
    return 0;
}