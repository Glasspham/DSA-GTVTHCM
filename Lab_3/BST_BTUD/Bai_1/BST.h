#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "Node.h"
class BST {
public:
    BST();
    virtual ~BST();
    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    void ImportByFile(ifstream&);
    bool InsertNode(Node*);
    bool InsertNodeRe(Node*, Node*);
    void LNR(Node*);
    void TravelLNR();
    Node* search_x(int);
    void PrintDistinctValues();
    void PrintDistinctValues(Node*);
    void Find(char);
protected:
private:
    Node* root;
};
#endif // BST_H