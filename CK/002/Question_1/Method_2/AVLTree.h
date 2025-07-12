#ifndef AVLTREE_H
#define AVLTREE_H

#include "Store.h"

class AVLNode {
public:
    Store* store;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(Store* store);
};

class AVLTree {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode*, Store*);
    AVLNode* remove(AVLNode*, string);
    AVLNode* minValueNode(AVLNode*);
    AVLNode* balance(AVLNode*);
    int getHeight(AVLNode*);
    int getBalanceFactor(AVLNode*);
    AVLNode* rotateRight(AVLNode*);
    AVLNode* rotateLeft(AVLNode*);
    void inOrder(AVLNode*);
    void listStoresWithEmployeesGreaterThan(AVLNode*, int);
    AVLNode* removeOldLowRevenueStores(AVLNode*, int, int, int);
    void averageRevenueByOperationTime(AVLNode*, string, double&, int&);
public:
    AVLTree();
    void insert(Store*);
    void remove(string);
    void inOrder();
    void listStoresWithEmployeesGreaterThan(int);
    void removeOldLowRevenueStores(int, int, int);
    double averageRevenueByOperationTime(string);
};

#endif
