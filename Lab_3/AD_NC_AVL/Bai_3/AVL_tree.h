#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class AVL_tree {
private:
    Node* root;
    int getHeight(Node*);
    int checkBalance(Node*);
    void rotateLeft(Node*&);
    void rotateRight(Node*&);
    Node* deleteNode(Node*, int);
    Node* insert(Node*, const Student&);
    bool search(Node*, int);

public:
    AVL_tree() : root(nullptr) {}
    void insert(const Student&);
    void deleteNode(int);
    bool search(int);
    void LNR(Node*);
    void TravelLNR();
    void NLR(Node*);
    void TravelNLR();
};
#endif // _AVL_TREE_H_