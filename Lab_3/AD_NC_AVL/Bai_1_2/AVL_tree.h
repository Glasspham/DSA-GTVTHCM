#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "Node.h"
class AVL_tree {
public:
    AVL_tree();
    virtual ~AVL_tree();
    Node *Getroot() { return root; }
    void Setroot(Node *val) { root = val; }
    Node *InsertNode(Node*, Node*);
    void InsertNodeRe(Node*);
    Node *deleteNode(Node*, int);
    void deleteNode(Node*);
    void NLR(Node*);
    void TravelNLR();
    void LeftRotate(Node*&);
    void RightRotate(Node*&);
    int CheckBal(Node*);
    int GetHeight(Node*);
    Node *search_x(int, int&);
protected:
private:
    Node *root;
    int nNum;   // Node number of tree
    int height; // height of tree
};
#endif // AVL_TREE_H