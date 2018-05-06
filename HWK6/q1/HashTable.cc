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
// The '()' notation in dynamic array initializations in C++ sets the
// initial content of the array elements to 0 (NULL).
    nodes = new Node *[size]();
//    number = 0;
}

HashTable::~HashTable() {
    delete[] nodes;
}

void HashTable::Grow() {
    int old_size;
    int index;
    int i;

    Node **old_nodes;
    Node *node;

// Save old array
    old_size = size;
    old_nodes = nodes;

// Allocate new array
    size = old_size * 2;
    nodes = new Node *[size]();

// Move elements to new vector
    for (i = 0; i < old_size; i++) {
        // Notice that the condition in the 'while' loop contains an
        // assignment (=) and not a comparison (==). Since this is
        // a common unintended mistake, the compiler will suggest you
        // to insert additional parentheses around the assignment.
        while ((node = old_nodes[i])) {
            // Remove from old array
            old_nodes[i] = node->next;
            // Insert in new array
            index = node->key->Hash() % size;
            node->next = nodes[index];
            nodes[index] = node;
        }
    }
    // Free old array
    delete[] old_nodes;
}

void HashTable::Print() {
    for (int i = 0; i < size; i++) {
        for (Node *node = nodes[i]; node; node = node->next) {
            std::cout << '\n';
            std::cout << "Key: ";
            node->key->Print();
            node->data->Print();
        }
    }
}

void HashTable::Insert(Object *key, Object *data) {
    // Rehashing
    if (length > size * max_load_factor)
        Grow();
    // Element must not exist
    if (Search(key))
        throw "Element already exists";
    // Create new element
    Node *node = new Node;
    node->key = key;
    node->data = data;
    // Insert into array
//    std::cout << "It is insert step" << std::endl;
    key->Print();
    unsigned int temp = key->Hash();
    std::cout << "the key hash is: " << temp << '\n';
    unsigned int index = temp % size;
//    std::cout << "the index is: " << index << '\n';
    node->next = nodes[index];
    nodes[index] = node;
    length++;
}

Object* HashTable::Succ(Object *key) {
    unsigned int key_hash = key->Hash();
    unsigned int index = key_hash % size;
    unsigned int hash_succ = key_hash;
    unsigned int hash_temp = 0;
    bool flag = true;

    if (!nodes[index])
        throw "Element not found";

    for (int i = 0; i < size; i++) {
        for (Node *node = nodes[i]; node; node = node->next) {
            hash_temp = node->key->Hash();
            if (flag && (int)hash_succ < (int)hash_temp) {
                hash_succ = hash_temp;
                flag = false;
            } else if( hash_temp > key_hash && (hash_succ > hash_temp)) {
                hash_succ = hash_temp;
            }
        }
    }

    if (hash_succ != key_hash) {
        return nodes[hash_succ % size]->key;
    } else
        return NULL;
}

Object *HashTable::Search(Object *key) {
    unsigned int index;
    Node *node;
/* Search element */
//    std::cout << "It is search step" << std::endl;
//    key->Print();
    index = key->Hash() % size;
    for (node = nodes[index]; node; node = node->next)
        if (key->Equals(node->key))
            break;
// Return data if found, or NULL if not
    return node ? node->data : NULL;
}

Object *HashTable::Delete(Object *key) {
    // Calculate hash index
    unsigned int index = key->Hash() % size;

    // Find element
    Node *prev = NULL;
    Node *node = nodes[index];
    while (node && !key->Equals(node->key)) {
        prev = node;
        node = node->next;
    }

    // Not found
    if (!node)
        throw "Element not found";
    // Delete it
    if (prev)
        prev->next = node->next;
    else
        nodes[index] = node->next;
    // Free element
    Object *data = node->data;
    delete node;
    // Return the data
    return data;
}