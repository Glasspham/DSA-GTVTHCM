#pragma once
#ifndef AVL_H
#define AVL_H
#include "AVLTreeByName.h"
#include "AVLTreeByPhone.h"
class ContactBook {
private:
    AVLTreeByName treeByName;
    AVLTreeByPhone treeByPhone;
public:
    void insert(Contact);
    void search(string);
    void update(string, Contact);
    void remove(string);
    void display();
};
#endif // BST_H