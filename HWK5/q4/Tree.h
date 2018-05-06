//
// Created by DING on 2018/2/23.
//

#ifndef FCE_HWK_5_Q1_TREE_H
#define FCE_HWK_5_Q1_TREE_H

#include "Object.h"

class Tree {
    struct Node {
        Node();
        Node *left, *right, *parent;
        Object *key, *data;
    };

    Node *root;

    int tree_size;

    Node *MinAux(Node *node);

    Node *SearchAux(Object *key);

    void PrintAux(Node *node);

    void Transplant(Node *u, Node *v);

    int getHeightAux(Node *node);

    void RotateRight_private(Node *node);

    void RotateLeft_private(Node *node);

public:
    Tree();

    void Print();

    void Insert(Object *key, Object *data);

    Object *Min();

    Object *Search(Object *key);

    Object *Delete(Object *key);

    int getHeight();

    void RotateRight();

    void RotateLeft();

};

#endif //FCE_HWK_5_Q1_TREE_H
