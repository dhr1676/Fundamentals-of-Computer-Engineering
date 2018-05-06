//
// Created by DING on 2018/3/10.
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Object.h"
#include "cstdlib"

class HashTable {

    struct Node {
        Object *key = NULL;
        Object *data = NULL;
        bool state = false;
    };
    Node **nodes;
//    int content;
    int length;     // stores the numbers of nodes in the table
    int size;       // the limit of the table
    static const float max_load_factor;

public:
    HashTable(int size = 10);

    ~HashTable();

    void Print();

    void Insert_openadd(Object *key, Object *data);

    Object *Search_openadd(Object *key);

    Object *Delete_openadd(Object *key);

};

#endif