#include "AVL_tree.h"

int AVL_tree::getHeight(Node* p) {
    if (p == nullptr) return 0;
    return p->getHeight();
}

int AVL_tree::checkBalance(Node* p) {
    if (p == nullptr) return 0;
    return getHeight(p->getLeft()) - getHeight(p->getRight());
}

void AVL_tree::rotateLeft(Node*& x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();
    y->setLeft(x);
    x->setRight(T2);
    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
    x = y;
}

void AVL_tree::rotateRight(Node*& y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();
    x->setRight(y);
    y->setLeft(T2);
    y->setHeight(1 + max(getHeight(y->getLeft()), getHeight(y->getRight())));
    x->setHeight(1 + max(getHeight(x->getLeft()), getHeight(x->getRight())));
    y = x;
}

Node* AVL_tree::deleteNode(Node* root, int key) {
    if (root == nullptr) return root;
    if (key < root->getStudent().getStudentID())
        root->setLeft(deleteNode(root->getLeft(), key));
    else if (key > root->getStudent().getStudentID())
        root->setRight(deleteNode(root->getRight(), key));
    else  {
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            Node* temp = root->getLeft() ? root->getLeft() : root->getRight();
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else *root = *temp;
            delete temp;
        } else {
            Node* temp = root->getRight();
            while (temp->getLeft()) temp = temp->getLeft();
            root->setStudent(temp->getStudent());
            root->setRight(deleteNode(root->getRight(), temp->getStudent().getStudentID()));
        }
    }
    if (root == nullptr) return root;
    root->setHeight(1 + max(getHeight(root->getLeft()), getHeight(root->getRight())));
    int balance = checkBalance(root);
    if (balance > 1 && checkBalance(root->getLeft()) >= 0)
        rotateRight(root);
    if (balance > 1 && checkBalance(root->getLeft()) < 0) {
        Node* nLeft = root->getLeft();
        rotateLeft(nLeft);
        root->setLeft(nLeft);
        rotateRight(root);
    }
    if (balance < -1 && checkBalance(root->getRight()) <= 0)
        rotateLeft(root);
    if (balance < -1 && checkBalance(root->getRight()) > 0) {
        Node* nRight = root->getRight();
        rotateRight(nRight);
        root->setRight(nRight);
        rotateLeft(root);
    }
    return root;
}

Node* AVL_tree::insert(Node* node, const Student& student) {
    if (node == nullptr) return new Node(student);
    if (student.getStudentID() < node->getStudent().getStudentID())
        node->setLeft(insert(node->getLeft(), student));
    else if (student.getStudentID() > node->getStudent().getStudentID())
        node->setRight(insert(node->getRight(), student));
    else return node;
    node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight())));
    int balance = checkBalance(node);
    if (balance > 1 && student.getStudentID() < node->getLeft()->getStudent().getStudentID())
        rotateRight(node);
    if (balance < -1 && student.getStudentID() > node->getRight()->getStudent().getStudentID())
        rotateLeft(node);
    if (balance > 1 && student.getStudentID() > node->getLeft()->getStudent().getStudentID()) {
        Node* nLeft = node->getLeft();
        rotateLeft(nLeft);
        node->setLeft(nLeft);
        rotateRight(node);
    }
    if (balance < -1 && student.getStudentID() < node->getRight()->getStudent().getStudentID()) {
        Node* nRight = node->getRight();
        rotateRight(nRight);
        node->setRight(nRight);
        rotateLeft(node);
    }
    return node;
}

bool AVL_tree::search(Node* root, int key) {
    if (root == nullptr) return false;
    if (key == root->getStudent().getStudentID())
        return true;
    else if (key < root->getStudent().getStudentID())
        return search(root->getLeft(), key);
    else return search(root->getRight(), key);
}

void AVL_tree::insert(const Student& student) {
    root = insert(root, student);
}

void AVL_tree::deleteNode(int key) {
    root = deleteNode(root, key);
}

bool AVL_tree::search(int key) {
    return search(root, key);
}

void AVL_tree::LNR(Node* root) {
    if (!root) return;
    LNR(root->getLeft());
    cout << "Student ID: " << root->getStudent().getStudentID() << ", Name: " << root->getStudent().getName()
        << ", dateOfBirth: " << root->getStudent().getdateOfBirth() << ", GPA: " << root->getStudent().getGPA() << endl;
    LNR(root->getRight());
}

void AVL_tree::TravelLNR() { LNR(root); }

void AVL_tree::NLR(Node* root) {
    if (!root) return;
    cout << "Student ID: " << root->getStudent().getStudentID() << ", Name: " << root->getStudent().getName()
        << ", dateOfBirth: " << root->getStudent().getdateOfBirth() << ", GPA: " << root->getStudent().getGPA() << endl;
    LNR(root->getLeft());
    LNR(root->getRight());
}

void AVL_tree::TravelNLR() { NLR(root); }