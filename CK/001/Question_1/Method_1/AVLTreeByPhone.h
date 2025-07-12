#pragma once
#ifndef AVLTreeByPhone_H
#define AVLTreeByPhone_H
#include "AVLTree.h"
class AVLTreeByPhone : public AVLTree {
private:
    Node *insert(Node*, Contact);
    Node *search(Node*, string);
    Node *remove(Node*, string);
    Node *getMin(Node*);
public:
    void insert(Contact);
    Contact *search(string);
    void update(string, Contact);
    void remove(string);
};
#endif // AVLTreeByPhone_H