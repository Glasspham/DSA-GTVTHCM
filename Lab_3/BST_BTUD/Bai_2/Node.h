#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    Node();
    Node(string);
    virtual ~Node();
    Node *Getleft() { return left; }
    void Setleft(Node *val) { left = val; }
    Node *Getright() { return right; }
    void Setright(Node *val) { right = val; }
    string Getkey() { return key; }
    void Setkey(string val) { key = val; }
    int Getquantity() { return quantity; }
    void Setquantity(int val) { quantity = val; }
    void IncrementQuantity() { quantity++; }
protected:
private:
    Node *left;
    Node *right;
    string key;
    int quantity;
};
#endif // NODE_H