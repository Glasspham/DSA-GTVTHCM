#ifndef BST_H
#define BST_H
#include "Node.h"
class BST {
public:
    BST();
    virtual ~BST();
    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    bool InsertNodeRe(Node*,Node*);
    Node* deleteNode(Node*, int);
    void deleteNode(Node*);
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    Node* search_x(int);
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
    Node* root;
};
#endif // BST_H