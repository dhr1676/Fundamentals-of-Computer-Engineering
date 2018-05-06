//
// Created by DING on 2018/2/23.
//

#include <iostream>
#include <algorithm>
#include "Tree.h"

Tree::Node::Node() {
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

Tree::Tree() {
    root = NULL;
    tree_size = 0;
}

Tree::Node *Tree::MinAux(Node *node) {
    while (node && node->left)
        node = node->left;
    return node;
}

void Tree::PrintAux(Node *node) {
    if (!node)
        return;
    PrintAux(node->left);
    std::cout << '\n';
    std::cout << "Key: ";
    node->key->Print();
    node->data->Print();
    PrintAux(node->right);
}

Tree::Node *Tree::SearchAux(Object *key) {
    Node *node = root;
    while (node) {
        if (node->key->Compare(key))
            node = node->right;
        else if (key->Compare(node->key))
            node = node->left;
        else
            return node;
    }
    return NULL;
}

void Tree::Print() {
    PrintAux(root);
    std::cout << '\n';
}

void Tree::Insert(Object *key, Object *data) {
    Node *node;
    Node *x, *y;
/* Create new node */
    node = new Node;
    node->key = key;
    node->data = data;
    y = NULL;
    x = root;
    while (x) {
        y = x;
        if (key->Compare(x->key))
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (!y)
        root = node;
    else if (key->Compare(y->key))
        y->left = node;
    else
        y->right = node;

    tree_size++;

//==============================================
//    A simple and partial balancing technique
    float distance = (float)getHeightAux(this->root);
    if (distance > (float)tree_size / 2) {
        if (node->key->Compare(root->key))
            RotateRight();
        else
            RotateLeft();
    }

}

void Tree::Transplant(Node *u, Node *v) {
    if (!u->parent)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}

Object *Tree::Min() {
    Node *node = MinAux(root);
    return node ? node->data : NULL;
}

Object *Tree::Search(Object *key) {
    Node *node = SearchAux(key);
    return node ? node->data : NULL;
}

Object *Tree::Delete(Object *key) {
    Object *data;
    Node *node;
    Node *succ;
/* Search element */
    node = SearchAux(key);
    if (!node)
        return NULL;
    if (!node->left)
        Transplant(node, node->right);
    else if (!node->right)
        Transplant(node, node->left);
    else {
        succ = MinAux(node->right);
        if (succ == node->right) {
            Transplant(node, succ);
            succ->left = node->left;
            succ->left->parent = succ;
        } else {
            Transplant(succ, succ->right);
            Transplant(node, succ);
            succ->left = node->left;
            succ->left->parent = succ;
            succ->right = node->right;
            succ->right->parent = succ;
        }
    }
// Return
    data = node->data;
    tree_size--;
    delete node;
    return  data;
}

int Tree::getHeightAux(Node *node) {
    int node_height = 0;
    Node *left_temp = node->left, *right_temp = node->right;
    if (left_temp != NULL || right_temp != NULL) {
        if (left_temp == NULL) {
            node_height++;
            node_height+=getHeightAux(right_temp);
            return node_height;
        } else if (right_temp == NULL) {
            node_height++;
            node_height+=getHeightAux(left_temp);
            return node_height;
        } else{
            node_height++;
            node_height+=std::max(getHeightAux(left_temp), getHeightAux(right_temp));
            return node_height;
        }

    } else
        return node_height;
}

int Tree::getHeight() {
    int tree_height;
    tree_height = getHeightAux(root);
    return tree_height;
}

void Tree::RotateRight_private(Node *node) {
    if (node->left == NULL)
        return;

//    改当前node的parent和node->left的关系
//    change the relationship between the node->parent and node->left
    if (node->parent == NULL) {
        this->root = node->left;
        node->left->parent = NULL;                  // Remember change node->left to parent!!!
    } else {
        if (node == node->parent->left) {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        else {
            node->parent->right = node->left;
            node->left->parent = node->parent;
        }
    }

    Node *temp_b = node->left->right;
    Node *temp_y = node;

    node = node->left;
    temp_y->left = temp_b;
    if (temp_b != NULL) {
        temp_b->parent = temp_y;
    }

    node->right = temp_y;
    temp_y->parent = node;

}

void Tree::RotateRight() {
    RotateRight_private(this->root);
}

void Tree::RotateLeft_private(Node *node) {
    if (node->right == NULL)
        return;

    if (node->parent == NULL) {
        this->root = node->right;
        node->right->parent = NULL;
    } else {
        if (node == node->parent->right) {
            node->parent->right = node->right;
            node->left->parent = node->parent;
        }
        else {
            node->parent->left = node->right;
            node->right->parent = node->parent;
        }
    }

    Node *temp_b = node->right->left;
    Node *temp_x = node;

    node = node->right;
    temp_x->right = temp_b;
    if (temp_b != NULL) {
        temp_b->parent = temp_x;
    }

    node->left = temp_x;
    temp_x->parent = node;
}

void Tree::RotateLeft() {
    RotateLeft_private(this->root);
};