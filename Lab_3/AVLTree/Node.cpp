#include "Node.h"
Node::Node() {
    // ctor
    this->key = this->quantity = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}

Node::Node(int k) {
    // ctor
    this->key = k;
    this->quantity = 1;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}

Node::~Node() {
    // dtor
    this->key = this->quantity = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}