#pragma once
#ifndef AVLTree_H
#define AVLTree_H
#include "node.h"
class AVLTree {
protected:
    Node *root;
    int getHeight(Node*);
    void setHeight(Node*);
    int getBalanceFactor(Node*);
    Node *rotateRight(Node*);
    Node *rotateLeft(Node*);
    Node *balance(Node*);
public:
    AVLTree() : root(nullptr) {}
};
#endif // AVLTree_H