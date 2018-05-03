//
// Created by DING on 2018/2/13.
//

#include <iostream>
#include "Deque.h"

Deque::Deque() : front(initial_size-1), back(initial_size), size(0)
{

}

bool Deque::isEmpty() {
    return size == 0;
}

bool Deque::isFull() {
    return size == initial_size;
}

void Deque::clear() {
    this->size = 0;
    this->front = 0;
    this->back = 0;
}

int Deque::getLength() {
    return size;
}

void Deque::push_back(int _temp) {
    if(this->isFull()) {
        std::cout << "Full!" << std::endl;
    } else {
        data[back++] = _temp;
        size++;
    }
}

void Deque::push_front(int _temp) {
    if(this->isFull()) {
        std::cout << "Full!" << std::endl;
    } else {
        data[front--] = _temp;
        size++;
    }
}

int Deque::pop_back() {
    if(this->isEmpty()) {
        std::cout << "Empty! " << std::endl;
        return -1;
    } else{
        size--;
        return data[--back];
    }
}

int Deque::pop_front() {
    if(this->isEmpty()) {
        std::cout << "Empty!" << std::endl;
        return -1;
    } else {
        size--;
        return data[++front];
    }
}

int Deque::get_back() {
    int temp_back = back;
    return this->data[--temp_back];
}

int Deque::get_front() {
    int temp_front = front;
    return this->data[++temp_front];
}

void Deque::Print() {
    if(size == 0) {
        std::cout << "The deque is empty!" << std::endl;
    } else {
        std::cout << "The Deque is " << std::endl;

        for (int i = front+1; i < front+size+1; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
}