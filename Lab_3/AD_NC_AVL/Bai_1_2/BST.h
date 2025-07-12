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
    Node* deleteNode(Node*, int);
    void deleteNode(Node*);
    void NLR(Node*);
    void TravelNLR();
    Node *search_x(int, int&);
protected:
private:
    Node* root;
};
#endif // BST_H