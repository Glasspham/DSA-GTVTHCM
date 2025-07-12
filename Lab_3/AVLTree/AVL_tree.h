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
    bool InsertNode(Node*);
    Node *InsertNode(Node*, Node*);
    void InsertNodeRe(Node*);
    Node *deleteNode(Node*, int);
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    void LeftRotate(Node*&);
    void RightRotate(Node*&);
    int CheckBal(Node*);
    int GetHeight();
    int GetHeight(Node*);
    Node *search_x(int);
    int SumTree();
    int SumTree(Node*);
    Node* FindMax();
    Node* FindMax(Node*);
    Node* FindMin();
    Node* FindMin(Node*);
    int CountNode();
    int CountNode(Node*);
    int CountLeaf();
    int CountLeaf(Node*);
    int DistinctValues();
    void PrintDistinctValues();
    void PrintDistinctValues(Node*);
protected:
private:
    Node *root;
    int nNum;   // Node number of tree
    int height; // height of tree
};
#endif // AVL_TREE_H