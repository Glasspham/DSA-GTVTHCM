#pragma once
#ifndef AVLTreeByName_H
#define AVLTreeByName_H
#include "AVLTree.h"
#include "unordered_map"
#include "vector"
#include "queue"
using namespace std;
class AVLTreeByName: public AVLTree {
private:
    unordered_map<int, vector<Contact>> groupMap;
    Node *insert(Node*, Contact);
    Node *search(Node*, string);
    Node *remove(Node*, string);
    Node *getMin(Node*);
    void divideGroup();
public:
    void insert(Contact);
    Contact *search(string);
    void update(string, Contact);
    void remove(string);
    void display();
};
#endif // AVLTreeByName_H