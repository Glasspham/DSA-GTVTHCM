#include "AVL_tree.h"
#include <iostream>
#include <algorithm>
#include "Node.h"
using namespace std;

AVL_tree::AVL_tree() {
    // ctor
    this->root = nullptr;
}

AVL_tree::~AVL_tree() {
    // dtor
    this->root = nullptr;
    this->nNum = this->height = 0;
}

bool AVL_tree::InsertNode(Node *n) {
    Node *p = this->root;
    Node *T = nullptr;
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
    n->Setparent(T);
    Node *x = n;
    Node *parentX = x->Getparent();
    while (x != nullptr) {
        int bal = this->CheckBal(x);
        switch (bal) {
        case -1: // Trường hợp mất cân bằng nhẹ bên trái (Left-heavy), không cần xoay
        case 0: // Can bang
        case 1: // Trường hợp mất cân bằng nhẹ bên phải (Right-heavy), không cần xoay
            break; 
        case 2:
            if (this->CheckBal(x->Getright()) >= 0) { // LEFT-LEFT
                if (x == this->root)
                    this->RightRotate(this->root);
                else {
                    Node *parentX = x->Getparent();
                    this->RightRotate(x);
                    if (parentX->Getleft() == x)
                        parentX->Setleft(x);
                    else parentX->Setright(x);
                }
            } else { // Left-Right
                Node* leftChild = x->Getleft();
                    this->LeftRotate(leftChild);
                    if (x == this->root) 
                        this->RightRotate(this->root);
                    else {
                        Node* parentX = x->Getparent();
                        this->RightRotate(x);
                        if (parentX->Getleft() == x) 
                            parentX->Setleft(x);
                        else parentX->Setright(x);
                    }
            }
            break; // Thoát vòng lặp sau khi xử lý mất cân bằng LEFT-LEFT hoặc LEFT-RIGHT
        case -2:
            if (this->CheckBal(x->Getright()) <= 0) { // RIGHT-RIGHT
                if (x == this->root)
                    this->LeftRotate(this->root);
                else {
                    Node* parentX = x->Getparent();
                    this->LeftRotate(x);
                    if (parentX->Getright() == x)
                        parentX->Setright(x);
                    else parentX->Setleft(x);
                }
            } else { // Right-left
                Node* rightChild = x->Getright();
                this->RightRotate(rightChild);
                if (x == this->root)
                    this->LeftRotate(this->root);
                else {
                    Node* parentX = x->Getparent();
                    this->LeftRotate(x);
                    if (parentX->Getright() == x) 
                        parentX->Setright(x);
                    else parentX->Setleft(x);
                }
            }
            break; // Thoát vòng lặp sau khi xử lý mất cân bằng RIGHT-RIGHT hoặc RIGHT-LEFT
        }
        x = x->Getparent();
    }
    return true;
}

Node *AVL_tree::InsertNode(Node *r, Node *p) {
    if (r == nullptr) return p;
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

void AVL_tree::InsertNodeRe(Node *p) {
    this->root = InsertNode(this->root, p);
}

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
            while (tmp->Getleft() != nullptr)
                tmp = tmp->Getleft();
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

void AVL_tree::deleteNode(Node *n) {
    this->root = deleteNode(this->root, n->Getkey());
}

void AVL_tree::NLR(Node *r) {
    if (!r) return;
    cout << r->Getkey() << " ";
    NLR(r->Getleft());
    NLR(r->Getright());
}

void AVL_tree::LNR(Node *r) {
    // sinh vien code
    if (!r) return;
    NLR(r->Getleft());
    cout << r->Getkey() << " ";
    NLR(r->Getright());
}

void AVL_tree::LRN(Node *r) {
    // sinh vien code
    if (!r) return;
    NLR(r->Getleft());
    NLR(r->Getright());
    cout << r->Getkey() << " ";
}

void AVL_tree::TravelNLR() {
    NLR(this->root);
}

void AVL_tree::TravelLNR() {
    // sinh vien code
    LNR(this->root);
}

void AVL_tree::TravelLRN() {
    // sinh vien code
    LRN(this->root);
}

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

int AVL_tree::GetHeight() {
    return GetHeight(this->root);
}

int AVL_tree::GetHeight(Node *p) {
    if (p == nullptr) return 0;
    else return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}

Node *AVL_tree::search_x(int k) {
    // sinh vien code
    if (!root) return nullptr;
    Node *p = this->root;
    while (p != nullptr) {
        if (p->Getkey() == k) return p;
        else if (p->Getkey() > k) p = p->Getleft();
        else p = p->Getright();
    }
    return nullptr;
}

int AVL_tree::SumTree() {
    return SumTree(this->root);
}

int AVL_tree::SumTree(Node* root) {
    if(!root) return 0;
    return root->Getkey() + SumTree(root->Getleft()) + SumTree(root->Getright());
}

Node *AVL_tree::FindMax() {
    return FindMax(this->root);
}

Node *AVL_tree::FindMax(Node* root) {
    if(!root) return nullptr;
    while(root->Getright()) root = root->Getright();
    return root;
}

Node *AVL_tree::FindMin() {
    return FindMin(this->root);
}

Node *AVL_tree::FindMin(Node *root) {
    if(!root) return nullptr;
    while(root->Getleft()) root = root->Getleft();
    return root;
}

int AVL_tree::CountNode() {
    return CountNode(this->root);
}

int AVL_tree::CountNode(Node *root) {
    if(!root) return 0;
    return 1 + CountNode(root->Getleft()) + CountNode(root->Getright());
}

int AVL_tree::CountLeaf() {
    return CountLeaf(this->root);
}

int AVL_tree::CountLeaf(Node *root) {
    if(!root) return 0;
    if(!root->Getleft() && !root->Getright()) return 1;
    return CountLeaf(root->Getleft()) + CountLeaf(root->Getright());
}

int AVL_tree::DistinctValues() {
    return CountNode();
}

void AVL_tree::PrintDistinctValues() {
    PrintDistinctValues(this->root);
}

void AVL_tree::PrintDistinctValues(Node *root) {
    if(!root) return;
    PrintDistinctValues(root->Getleft());
    cout << "Value: " << root->Getkey() << ", Frequency: " << root->Getquantity() << endl;
    PrintDistinctValues(root->Getright());
}