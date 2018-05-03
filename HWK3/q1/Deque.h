//
// Created by DING on 2018/2/14.
//

#ifndef DEQUE_TEST_DEQUE_H
#define DEQUE_TEST_DEQUE_H

#define initial_size 5

class Deque {
    int front, back, size;
    int data[initial_size * 2];

public:
    Deque();

    void push_back(int _temp);

    void push_front(int _temp);

    int pop_back();

    int pop_front();

    void clear();

    int get_front();

    int get_back();

    int getLength();

    bool isEmpty();

    bool isFull();

    void Print();
};
#endif //DEQUE_TEST_DEQUE_H
