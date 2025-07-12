#include "AVLTreeByPhone.h"

// ----Private Functions---- //
Node* AVLTreeByPhone::insert(Node* node, Contact contact) {
    if (!node) return new Node(contact);
    if (contact.getPhone() < node->getData().getPhone())
        node->setLeft(insert(node->getLeft(), contact));
    else if (contact.getPhone() > node->getData().getPhone())
        node->setRight(insert(node->getRight(), contact));
    return balance(node);
}

Node* AVLTreeByPhone::search(Node* node, string phone) {
    if (!node) return nullptr;
    if (phone == node->getData().getPhone()) return node;
    if (phone < node->getData().getPhone()) return search(node->getLeft(), phone);
    return search(node->getRight(), phone);
}

Node* AVLTreeByPhone::remove(Node* node, string phone) {
    if (!node) return nullptr;
    if (phone < node->getData().getPhone())
        node->setLeft(remove(node->getLeft(), phone));
    else if (phone > node->getData().getPhone())
        node->setRight(remove(node->getRight(), phone));
    else {
        if (!node->getLeft()) {
            Node* temp = node->getRight();
            delete node;
            return temp;
        } else if (!node->getRight()) {
            Node* temp = node->getLeft();
            delete node;
            return temp;
        } else {
            Node* temp = getMin(node->getRight());
            node->setData(temp->getData());
            node->setRight(remove(node->getRight(), temp->getData().getPhone()));
        }
    }
    return balance(node);
}

Node* AVLTreeByPhone::getMin(Node* node) {
    while (node->getLeft()) node = node->getLeft();
    return node;
}

// ----Public Functions---- //
void AVLTreeByPhone::insert(Contact contact) { root = insert(root, contact); }

Contact* AVLTreeByPhone::search(string phone) {
    Node* node = search(root, phone);
    return node ? &node->getData() : nullptr;
}

void AVLTreeByPhone::update(string phone, Contact contact) { 
    root = remove(root, phone);
    root = insert(root, contact);
}

void AVLTreeByPhone::remove(string phone) { root = remove(root, phone); }