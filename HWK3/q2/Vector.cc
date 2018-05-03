//
// Created by DING on 2018/2/12.
//

#include <cstdlib>
#include <algorithm>
#include "Vector.h"

Vector::Vector(int size) {
    this->size = size;
    length = 0;
    objects = new Object *[size];
}

Vector::~Vector(void) {
    delete objects;
}

int Vector::GetLength(void) {
    return length;
}

void Vector::Grow(void) {
// Allocate new space
    int new_size = size * 2;
    Object **new_object_array = new Object *[new_size];
// Copy objects
    for (int i = 0; i < size; i++)
        new_object_array[i] = objects[i];
// Assign new values
    delete objects;
    objects = new_object_array;
    size = new_size;
}

void Vector::Insert(int index, Object *object) {
// Check index
    if (index < 0 || index > length)
        throw "Invalid index";
// Grow if necessary
    if (length == size)
        Grow();
// Shift elements after index
    for (int i = length - 1; i >= index; i--)
        objects[i + 1] = objects[i];
// Insert new element
    objects[index] = object;
    length++;
}

Object *Vector::Delete(int index) {
    int i;
    Object *object;
// Check index
    if (index < 0 || index >= length)
        throw "Invalid index";
// Shift element after index
    object = objects[index];
    for (i = index + 1; i < length; i++)
        objects[i - 1] = objects[i];
// Return element
    length--;
    return object;
}

Object *Vector::Get(int index) {
// Check index
    if (index < 0 || index >= length)
        throw "Invalid index";
// Return element
    return objects[index];
}

void Vector::Exchange(int index1, int index2) {
// Check index 1
    if (index1 < 0 || index1 >= length)
        throw "Invalid index 1";
// Check index 2
    if (index2 < 0 || index2 >= length)
        throw "Invalid index 2";
// Exchange elements
    std::swap(objects[index1], objects[index2]);
}

void Vector::Print(void) {
    for (int i = 0; i < length; i++)
        objects[i]->Print();
}