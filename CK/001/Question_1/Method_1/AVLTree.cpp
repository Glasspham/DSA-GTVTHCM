#include "AVLTree.h"
// ---Protected Functions---- //
int AVLTree::getHeight(Node* node) { return node ? node->getHeight() : 0; }

void AVLTree::setHeight(Node* node) { node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight()))); }

int AVLTree::getBalanceFactor(Node* node) { return node ? getHeight(node->getLeft()) - getHeight(node->getRight()) : 0; }

Node* AVLTree::rotateRight(Node* node) {
    Node* left = node->getLeft();
    node->setLeft(left->getRight());
    left->setRight(node);
    setHeight(node);
    setHeight(left);
    return left;
}

Node* AVLTree::rotateLeft(Node* node) {
    Node* right = node->getRight();
    node->setRight(right->getLeft());
    right->setLeft(node);
    setHeight(node);
    setHeight(right);
    return right;
}

Node* AVLTree::balance(Node* node) {
    setHeight(node);
    int balance = getBalanceFactor(node);
    if (balance > 1) {
        if (getBalanceFactor(node->getLeft()) < 0)
            node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    if (balance < -1) {
        if (getBalanceFactor(node->getRight()) > 0)
            node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }
    return node;
}