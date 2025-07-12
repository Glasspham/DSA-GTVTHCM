#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    // ctor
    this->root = nullptr;
}

BST::~BST() {
    // dtor
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

bool BST::InsertNodeRe(Node *root, Node *p) {
    if (root == nullptr) {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey()) {
        p->IncrementQuantity();
        delete p;
        return false;
    }
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}

void BST::NLR(Node *r) {
    if (r != nullptr) {
        cout << r->Getkey() << " ";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

void BST::LNR(Node *r) {
    // sinh vien code
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << " ";
        LNR(r->Getright());
    }
}

void BST::LRN(Node *r) {
    // sinh vien code
    if (r != nullptr) {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << " ";
    }
}

void BST::TravelNLR() {
    NLR(this->root);
}

void BST::TravelLNR() {
    // sinh vien code
    LNR(this->root);
}

void BST::TravelLRN() {
    // sinh vien code
    LRN(this->root);
}

Node *BST::search_x(int k) {
    // sinh vien code
    if(!this->root) return nullptr;
    Node* p = this->root;
    while(p != nullptr) {
        if(p->Getkey() == k) return p;
        else if(p->Getkey() > k) p = p->Getleft();
        else p = p->Getright();
    }
    return nullptr;
}

void BST::deleteNode(Node* n) {
    // sinh vien code
    if (!n) return;
    root = deleteNode(root, n->Getkey());
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
            Node* tmp = FindMin(root->Getright());
            root->Setkey(tmp->Getkey());
            root->Setright(deleteNode(root->Getright(), tmp->Getkey()));
        }
    } return root;
}

// --- Áp dụng – Nâng cao --- //
int BST::SumTree() { return SumTree(this->root); }

int BST::SumTree(Node* root) {
    if(!root) return 0;
    return root->Getkey() + SumTree(root->Getleft()) + SumTree(root->Getright());
}

Node *BST::FindMax() { return FindMax(this->root); }

Node *BST::FindMax(Node* root) {
    if(!root) return nullptr;
    while(root->Getright()) root = root->Getright();
    return root;
}

Node *BST::FindMin() { return FindMin(this->root); }

Node *BST::FindMin(Node *root) {
    if(!root) return nullptr;
    while(root->Getleft()) root = root->Getleft();
    return root;
}

int BST::CountNode() { return CountNode(this->root); }

int BST::CountNode(Node *root) {
    if(!root) return 0;
    return 1 + CountNode(root->Getleft()) + CountNode(root->Getright());
}

int BST::CountLeaf() { return CountLeaf(this->root); }

int BST::CountLeaf(Node *root) {
    if(!root) return 0;
    if(!root->Getleft() && !root->Getright()) return 1;
    return CountLeaf(root->Getleft()) + CountLeaf(root->Getright());
}

int BST::DistinctValues() { return CountNode(); }

void BST::PrintDistinctValues() { PrintDistinctValues(this->root); }

void BST::PrintDistinctValues(Node *root) {
    if(!root) return;
    PrintDistinctValues(root->Getleft());
    cout << "Value: " << root->Getkey() << ", Frequency: " << root->Getquantity() << endl;
    PrintDistinctValues(root->Getright());
}