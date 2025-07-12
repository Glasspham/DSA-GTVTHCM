#include "BST.h"

BST::BST() {
    // ctor
    this->root = nullptr;
}

BST::~BST() {
    // dtor
}

void BST::ImportByFile(ifstream &file) {
    string str;
    while (file >> str)
        InsertNode(new Node(str));
    file.close();
}

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

void BST::LNR(Node *r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << " ";
        LNR(r->Getright());
    }
}

void BST::TravelLNR() {
    LNR(this->root);
}

void BST::PrintDistinctValues() {
    PrintDistinctValues(this->root);
}

void BST::PrintDistinctValues(Node *root) {
    if(!root) return;
    PrintDistinctValues(root->Getleft());
    cout << root->Getkey() << ": " << root->Getquantity() << endl;
    PrintDistinctValues(root->Getright());
}

void BST::Find(string x) {
    Node *p = this->root;
    while (p != nullptr) {
        if (p->Getkey() == x) {
            cout << p->Getkey() << ": " << p->Getquantity() << endl;
            return;
        }
        else if (p->Getkey() > x)
            p = p->Getleft();
        else p = p->Getright();
    }
    cout << x << ": 0" << endl;
}