//
// Created by DING on 2018/2/19.
//

#ifndef FCE_HWK_4_Q3_TEST_DOUBLYLINKEDLIST_H
#define FCE_HWK_4_Q3_TEST_DOUBLYLINKEDLIST_H

#include <iostream>
#include "Object.h"

class DoublyLinkedList {
private:

public:
    struct Node {
        Node(Object *);

        Object *m_data;
        Node *m_next;
        Node *m_prev;
    };

    Node *current;
    Node *m_head;
    Node *m_tail;
    int m_size;

    DoublyLinkedList();

    ~DoublyLinkedList();

//    Pointer operation
    void Head();

    void Tail();

    void Prev();

    void Next();

//    Insert and delete operatioin
    void push_front(Object *x);

    void push_back(Object *x);

    void pop_front();

    void pop_back();

    void Insert(Object *x);

    void Remove();

    Object * GetCurrent();

    bool isEmpty();

    void ClearList();

    void Print();

//    void PrintInverse();

};

#endif //FCE_HWK_4_Q3_TEST_DOUBLYLINKEDLIST_H
