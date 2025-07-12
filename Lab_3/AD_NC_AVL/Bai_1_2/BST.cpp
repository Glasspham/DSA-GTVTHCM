#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() { this->root = nullptr; }

BST::~BST() {}

bool BST::InsertNode(Node *n) {
    Node *p = this->root;
    Node *T;
    if (root == nullptr) {
        this->root = n;
        return true;
    }
    while (p != nullptr) {
        T = p;
        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else if (p->Getkey() < n->Getkey())
            p = p->Getright();
        else if (p->Getkey() == n->Getkey()) {
            p->IncrementQuantity();
            delete n;
            return false;
        }
    }
    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    return true;
}

void BST::NLR(Node *r) {
    if (r != nullptr) {
        cout << r->Getkey() << " ";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

void BST::TravelNLR() { NLR(this->root); }

Node *BST::search_x(int k, int &compareCount) {
    // sinh vien code
    if(!this->root) return nullptr;
    Node* p = this->root;
    while(p != nullptr) {
        ++compareCount;
        if(p->Getkey() == k) return p;
        else if(p->Getkey() > k) p = p->Getleft();
        else p = p->Getright();
    }
    return nullptr;
}

void BST::deleteNode(Node* x) {
    if (!x) return;
    root = deleteNode(root, x->Getkey());
}

Node* BST::deleteNode(Node* root, int x) {
    if(!root) return root;
    if(x < root->Getkey()) root->Setleft(deleteNode(root->Getleft(), x));
    else if(x > root->Getkey()) root->Setright(deleteNode(root->Getright(), x));
    else {
        if(root->Getleft() == NULL) {
            Node* tmp = root->Getright();
            delete root;
            return tmp;
        } else if(root->Getright() == NULL) {
            Node* tmp = root->Getleft();
            delete root;
            return tmp;
        } else {
            Node* tmp = root->Getright();
            while (tmp->Getleft()) tmp = tmp->Getleft();
            root->Setkey(tmp->Getkey());
            root->Setright(deleteNode(root->Getright(), tmp->Getkey()));
        }
    } return root;
}
