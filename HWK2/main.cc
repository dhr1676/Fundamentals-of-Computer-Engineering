#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"
#include "Shape.h"

int main() {
    Rectangle *r;
    Circle *c;
    Triangle *t;
    Square *s;

    Shape *shapes[4];
    Shape *shape;

    int i;

    r = new Rectangle("rect1", 8, 4);
    c = new Circle("circle1", 5);
    t = new Triangle("triangle1", 10, 5);
    s = new Square("square1", 10);

    shapes[0] = r;
    shapes[1] = c;
    shapes[2] = t;
    shapes[3] = s;

    for (i = 0; i < 4; i++) {
        shape = shapes[i];
        std::cout << shape->GetName() << ".area = " << shape->GetArea()
                  << std::endl;
    }

    shapes[0]->Draw();
    shapes[3]->Draw();


    for (i = 0; i < 4; i++)
        delete shapes[i];

    return 0;
}