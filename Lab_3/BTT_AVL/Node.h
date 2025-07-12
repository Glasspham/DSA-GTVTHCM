#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include "Word.h"
using namespace std;

class Node {
private:
    Word key;
    Node* left;
    Node* right;
    int height;
public:
    Node() : left(nullptr), right(nullptr), height(1) {}
    Node(Word key) : key(key), left(nullptr), right(nullptr), height(1) {}
    ~Node() {};
    Word getKey() { return key; };
    Node* getLeft() { return left; };
    Node* getRight() { return right; };
    int getHeight() { return height; };
    void setKey(Word key) { this->key = key; };
    void setLeft(Node* left) { this->left = left; };
    void setRight(Node* right) { this->right = right; };
    void setHeight(int height) { this->height = height; };
};
#endif // _NODE_H_