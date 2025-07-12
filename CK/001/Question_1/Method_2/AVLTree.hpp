#pragma once
#include "AVLTree.h"

// --- Private methods --- //
template <typename T, typename K>
int AVLTree<T, K>::getHeight(Node<T>* node) {  return node ? node->height : 0; }

template <typename T, typename K>
void AVLTree<T, K>::updateHeight(Node<T>* node) {
    if (node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

template <typename T, typename K>
int AVLTree<T, K>::getBalanceFactor(Node<T>* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::rotateRight(Node<T>* node) {
    Node<T>* leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::rotateLeft(Node<T>* node) {
    Node<T>* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::balance(Node<T>* node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::insert(Node<T>* node, T data, K (*getKey)(T)) {
    if (!node) return new Node<T>(data);
    if (getKey(data) < getKey(node->data))
        node->left = insert(node->left, data, getKey);
    else
        node->right = insert(node->right, data, getKey);
    return balance(node);
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::remove(Node<T>* node, K key, K (*getKey)(T)) {
    if (!node) return nullptr;
    if (key < getKey(node->data))
        node->left = remove(node->left, key, getKey);
    else if (key > getKey(node->data))
        node->right = remove(node->right, key, getKey);
    else {
        if (!node->left || !node->right) {
            Node<T>* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            Node<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, getKey(minNode->data), getKey);
        }
    }
    return balance(node);
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::search(Node<T>* node, K key, K (*getKey)(T)) {
    if (!node || getKey(node->data) == key) return node;
    if (key < getKey(node->data)) return search(node->left, key, getKey);
    return search(node->right, key, getKey);
}

template <typename T, typename K>
Node<T>* AVLTree<T, K>::findMin(Node<T>* node) {
    return node->left ? findMin(node->left) : node;
}

template <typename T, typename K>
void AVLTree<T, K>::divideGroup(Node<T>* node) {
    queue<Node<T>*> q;
    q.push(node);
    while (!q.empty()) {
        Node<T>* cur = q.front();
        q.pop();
        if (cur) {
            listgroup[cur->data.getGroup()].push_back(cur->data);
            q.push(cur->left);
            q.push(cur->right);
        }
    }
}

// --- Public methods --- //
template <typename T, typename K>
AVLTree<T, K>::AVLTree() : root(nullptr) {}

template <typename T, typename K>
void AVLTree<T, K>::insert(T data, K (*getKey)(T)) {
    root = insert(root, data, getKey);
}

template <typename T, typename K>
void AVLTree<T, K>::remove(K key, K (*getKey)(T)) {
    root = remove(root, key, getKey);
}

template <typename T, typename K>
T* AVLTree<T, K>::search(K key, K (*getKey)(T)) {
    Node<T>* result = search(root, key, getKey);
    return result ? &result->data : nullptr;
}

template <typename T, typename K>
void AVLTree<T, K>::display() {
    listgroup.clear();
    divideGroup(root);
    for (int i = 1; i <= 4; i++) {
        cout << "Group ";
        if (i == 1) cout << "Family:" << endl;
        else if (i == 2) cout << "Company:" << endl;
        else if (i == 3) cout << "Friend" << endl;
        else cout << "Other:" << endl;
        bool flag = true;
        for (Contact c : listgroup[i]) {
            c.display();
            flag = false;
        }
        if (flag) cout << "Empty!" << endl;
    }
}