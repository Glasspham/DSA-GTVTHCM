#pragma once
#ifndef NODE_H
#define NODE_H
#include "Contact.h"
class Node {
private:
    Contact data;
    Node* left;
    Node* right;
    int height;
public:
    Node() : data(Contact()), right(nullptr), left(nullptr), height(1) {}
    Node(Contact data) : data(data), right(nullptr), left(nullptr), height(1) {}
    void setData(Contact data) { this->data = data; }
    Contact& getData() { return data; }
    void setLeft(Node* left) { this->left = left; }
    Node* getLeft() { return left; }
    void setRight(Node* right) { this->right = right; }
    Node* getRight() { return right; }
    void setHeight(int height) { this->height = height; }
    int getHeight() { return height; }
};
#endif // NODE_H