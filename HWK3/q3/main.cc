#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "Shape.h"
#include "Heap.h"

int main() {
    Heap heap;

    Rectangle *r1;
    Rectangle *r2;
    Rectangle *r3;
    Circle *c1;
    Circle *c2;
    Circle *c3;
    Triangle *t1;
    Triangle *t2;
    Square *s1;
    Square *s2;

    r1 = new Rectangle("rect1", 8, 4);
    r2 = new Rectangle("rect2", 4, 4);
    r3 = new Rectangle("rect3", 3, 4);
    c1 = new Circle("circle1", 5);
    c2 = new Circle("circle2", 4);
    c3 = new Circle("circle3", 3);
    t1 = new Triangle("triangle1", 10, 5);
    t2 = new Triangle("triangle2", 5, 5);
    s1 = new Square("square1", 10);
    s2 = new Square("square2", 3);

    std::cout << std::endl;

    heap.Insert(0, r1);
    heap.Insert(1, r2);
    heap.Insert(2, r3);
    heap.Insert(3, c1);
    heap.Insert(4, c2);
    heap.Insert(5, c3);
    heap.Insert(6, t1);
    heap.Insert(7, t2);
    heap.Insert(8, s1);
    heap.Insert(9, s2);

    heap.Print();
    std::cout << std::endl;

    heap.HeapSort();
    heap.Print();
    std::cout << std::endl;

    for (int i = 0; i < heap.GetLength(); i++)
        delete (Shape *) heap.Get(i);

    return 0;
}