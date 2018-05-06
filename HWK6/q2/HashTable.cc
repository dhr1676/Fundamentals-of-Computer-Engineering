//
// Created by DING on 2018/3/10.
//

#include "HashTable.h"
#include <iostream>
#include <cstdlib>

const float HashTable::max_load_factor = 0.7;

HashTable::HashTable(int size) {
    this->size = size;
    length = 0;

    nodes = new Node *[size]();
    for (int i = 0; i < size; i++) {
        nodes[i] = new Node();
    }
}

HashTable::~HashTable() {
    delete[] nodes;
}

void HashTable::Print() {
    for (int i = 0; i < size; i++) {
        if (nodes[i]->key != NULL) {
            std::cout << '\n';
            std::cout << "Key: ";
            nodes[i]->key->Print();
            nodes[i]->data->Print();
        }
    }
}

void HashTable::Insert_openadd(Object *key, Object *data) {
    if (length > size * max_load_factor)
        throw "Table is full!";

    unsigned int index = 0;
    for (int i = 0; i < size; i++) {
        index = key->Hash_openadd(i) % size;
//        std::cout << "index is " << index << '\n';
        if (nodes[index]->key == NULL) {
            nodes[index]->key = key;
            nodes[index]->data = data;
            nodes[index]->state = false;
            length++;
            return;
        }
    }
    std::cerr << "FULL TABLE!" << '\n';
}

Object *HashTable::Search_openadd(Object *key) {
    unsigned int index;

    for (int i = 0; i < size; i++) {
        index = key->Hash_openadd(i) % size;
        if (key->Equals(nodes[index]->key)) {
            return nodes[index]->data;
        }
        if (nodes[index]->key == NULL && !nodes[index]->state) {
            return NULL;
        }
    }
    return NULL;
}

Object *HashTable::Delete_openadd(Object *key) {
    unsigned int index = 0;
    for (int i = 0; i < size; i++) {
        index = key->Hash_openadd(i) % size;
        if (key->Equals(nodes[index]->key)){
            nodes[index]->key = NULL;
            Object *data = nodes[index]->data;
            nodes[index]->data = NULL;
            nodes[index]->state = true;
            length--;
            return data;
        } else if (nodes[index]->key == NULL && !nodes[index]->state) {
            std::cerr << "Not found!" << '\n';
        }
    }
    std::cerr << "Not found!" << '\n';
    return NULL;
}