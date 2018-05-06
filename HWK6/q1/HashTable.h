//
// Created by DING on 2018/3/10.
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Object.h"

class HashTable {

    struct Node {
        Object *key;
        Object *data;
        Node *next;
    };
    Node **nodes;
    int length;
    int size;
//    int number;
    static const float max_load_factor;

    void Grow();

public:
    HashTable(int size = 10);

    ~HashTable();

    void Print();

    void Insert(Object *key, Object *data);

    Object *Search(Object *key);

    Object *Delete(Object *key);

    Object *Succ(Object *key);
};

#endif