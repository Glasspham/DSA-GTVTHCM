#include "AVL_tree.h"
#include <iostream>
#include <algorithm>
#include "Node.h"
using namespace std;

AVL_tree::AVL_tree() { this->root = nullptr; }

AVL_tree::~AVL_tree() {}

Node *AVL_tree::InsertNode(Node *r, Node *p) {
    if (r == nullptr)
        return p;
    if (p->Getkey() < r->Getkey())
        r->Setleft(InsertNode(r->Getleft(), p));
    else if (p->Getkey() > r->Getkey()) 
        r->Setright(InsertNode(r->Getright(), p));
    else {
        r->IncrementQuantity();
        return r;
    }
    r->Setheight(1 + max(GetHeight(r->Getleft()), GetHeight(r->Getright())));
    int balance = CheckBal(r);
    if (balance > 1 && p->Getkey() < r->Getleft()->Getkey())
        RightRotate(r);
    if (balance < -1 && p->Getkey() > r->Getright()->Getkey())
        LeftRotate(r);
    if (balance > 1 && p->Getkey() > r->Getleft()->Getkey()) {
        Node* rLeft = r->Getleft();
        LeftRotate(rLeft);
        r->Setleft(rLeft);
        RightRotate(r);
    } if (balance < -1 && p->Getkey() < r->Getright()->Getkey()) {
        Node* rRight = r->Getright();
        RightRotate(rRight);
        r->Setright(rRight);
        LeftRotate(r);
    }
    return r;
}

void AVL_tree::InsertNodeRe(Node *p) { this->root = InsertNode(this->root, p); }

Node *AVL_tree::deleteNode(Node *root, int key) {
    if (root == nullptr) return root;
    if (key < root->Getkey())
        root->Setleft(deleteNode(root->Getleft(), key));
    else if (key > root->Getkey())
        root->Setright(deleteNode(root->Getright(), key));
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
    }
    if (root == nullptr) return root;
    root->Setheight(1 + max(GetHeight(root->Getleft()), GetHeight(root->Getright())));
    int balance = CheckBal(root);
    if (balance > 1 && CheckBal(root->Getleft()) >= 0)
        RightRotate(root);
    if (balance > 1 && CheckBal(root->Getleft()) < 0) {
        Node* nLeft = root->Getleft();
        LeftRotate(nLeft);
        root->Setleft(nLeft);
        RightRotate(root);
    }
    if (balance < -1 && CheckBal(root->Getright()) <= 0)
        LeftRotate(root);
    if (balance < -1 && CheckBal(root->Getright()) > 0) {
        Node* nRight = root->Getright();
        RightRotate(nRight);
        root->Setright(nRight);
        LeftRotate(root);
    }    
    return root;
}

void AVL_tree::deleteNode(Node *n) { this->root = deleteNode(this->root, n->Getkey()); }

void AVL_tree::NLR(Node *r) {
    if (!r) return;
    cout << r->Getkey() << " ";
    NLR(r->Getleft());
    NLR(r->Getright());
}

void AVL_tree::TravelNLR() { NLR(this->root); }

void AVL_tree::LeftRotate(Node *&P) {
    Node *Q = P->Getright();
    Node *T = Q->Getleft();
    P->Setright(T);
    Q->Setleft(P);
    P->Setparent(Q);
    if (T != nullptr)
        T->Setparent(P);
    P = Q;
}

void AVL_tree::RightRotate(Node *&P) {
    Node *Q = P->Getleft();
    Node *T = Q->Getright();
    P->Setleft(T);
    Q->Setright(P);
    P->Setparent(Q);
    if (T != nullptr)
        T->Setparent(P);
    P = Q;
}

int AVL_tree::CheckBal(Node *p) {
    int bal = this->GetHeight(p->Getleft()) - this->GetHeight(p->Getright());
    return bal;
}

int AVL_tree::GetHeight(Node *p) {
    if (p == nullptr) return 0;
    else return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}

Node *AVL_tree::search_x(int k, int &compareCount) {
    if(!this->root) return nullptr;
    Node* p = this->root;
    while(p != nullptr) {
        compareCount++;
        if(p->Getkey() == k) return p;
        else if(p->Getkey() > k) p = p->Getleft();
        else p = p->Getright();
    }
    return nullptr;
}
