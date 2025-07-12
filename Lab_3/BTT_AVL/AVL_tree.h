#pragma once
#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_
#include "Node.h"
#include <iostream>
using namespace std;
class AVL_tree {
private:
    Node* root;
    int getHeight(Node*);
    int checkBalance(Node*);
    void rotateLeft(Node*&);
    void rotateRight(Node*&);
    Node* deleteNode(Node*, string);
    Node* insert(Node*, Word);
    Node* search(Node*, string);

public:
    AVL_tree() : root(nullptr) {}
    void insert(Word);
    void deleteNode(string);
    bool search(string, string&);
    bool modify(string, string);
    void LNR(Node*);
    void TravelLNR();
};
#endif // _AVL_TREE_H_