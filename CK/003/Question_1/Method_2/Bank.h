#pragma once
#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <fstream>
using namespace std;

class Bank {
private:
    struct Node {
        Account* acc;
        Node* left;
        Node* right;
        int height;
        Node(Account* account) : acc(account), left(nullptr), right(nullptr), height(1) {}
    };
    Node* root;
    int getHeight(Node*);
    int getBalanceFactor(Node*);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    Node* balance(Node*);
    Node* insert(Node*, Account*);
    Node* search(Node*, string);
public:
    Bank();
    ~Bank();
    void insert(Account*);
    Account* search(string);
    void depositMoney(string);
    void checkAndUnblock(string);
};
#endif // BANK_H