#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"
#include "Contact.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

template <typename T, typename K>
class AVLTree {
private:
    Node<T>* root;
    unordered_map<int, vector<Contact>> listgroup;
    int getHeight(Node<T>* node);
    void updateHeight(Node<T>* node);
    int getBalanceFactor(Node<T>* node);
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
    Node<T>* balance(Node<T>* node);
    Node<T>* insert(Node<T>* node, T data, K (*getKey)(T));
    Node<T>* remove(Node<T>* node, K key, K (*getKey)(T));
    Node<T>* search(Node<T>* node, K key, K (*getKey)(T));
    Node<T>* findMin(Node<T>* node);
    void divideGroup(Node<T>* node);
public:
    AVLTree();
    void insert(T data, K (*getKey)(T));
    void remove(K key, K (*getKey)(T));
    T* search(K key, K (*getKey)(T));
    void display();
};

#include "AVLTree.hpp" // Bắt buộc do class template
#endif // AVLTREE_H