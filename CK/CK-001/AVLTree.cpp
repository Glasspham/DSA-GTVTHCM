#include "AVLTree.h"
#include <iostream>
#include <vector>
using namespace std;

AVLNode::AVLNode(const Appointment& appt) : data(appt), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::getHeight(AVLNode* node) { return node ? node->height : 0; }
int AVLTree::getBalance(AVLNode* node) { return node ? getHeight(node->left) - getHeight(node->right) : 0; }
AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
AVLNode* AVLTree::insert(AVLNode* node, const Appointment& appt) {
    if (!node) return new AVLNode(appt);
    if (appt.datetime < node->data.datetime)
        node->left = insert(node->left, appt);
    else if (appt.datetime > node->data.datetime)
        node->right = insert(node->right, appt);
    else
        return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && appt.datetime < node->left->data.datetime)
        return rightRotate(node);
    if (balance < -1 && appt.datetime > node->right->data.datetime)
        return leftRotate(node);
    if (balance > 1 && appt.datetime > node->left->data.datetime) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && appt.datetime < node->right->data.datetime) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}
AVLNode* AVLTree::deleteNode(AVLNode* root, string datetime) {
    if (!root) return root;
    if (datetime < root->data.datetime)
        root->left = deleteNode(root->left, datetime);
    else if (datetime > root->data.datetime)
        root->right = deleteNode(root->right, datetime);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.datetime);
        }
    }
    if (!root) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
AVLNode* AVLTree::searchByDatetime(AVLNode* node, string datetime) {
    if (!node) return nullptr;
    if (datetime == node->data.datetime) return node;
    if (datetime < node->data.datetime)
        return searchByDatetime(node->left, datetime);
    return searchByDatetime(node->right, datetime);
}
void AVLTree::searchByName(AVLNode* node, const string& name, vector<Appointment>& result) {
    if (!node) return;
    searchByName(node->left, name, result);
    if (node->data.patientName == name)
        result.push_back(node->data);
    searchByName(node->right, name, result);
}
void AVLTree::inorder(AVLNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data.datetime << " | " << node->data.patientName << " | " << node->data.doctorName << " | " << node->data.note << endl;
    inorder(node->right);
}
void AVLTree::addAppointment(const Appointment& appt) {
    root = insert(root, appt);
}
void AVLTree::removeAppointment(string datetime) {
    root = deleteNode(root, datetime);
}
void AVLTree::searchByDatetime(string datetime) {
    AVLNode* res = searchByDatetime(root, datetime);
    if (res) {
        cout << "Tim thay lich hen: " << res->data.datetime << " | " << res->data.patientName << " | " << res->data.doctorName << " | " << res->data.note << endl;
    } else {
        cout << "Khong tim thay lich hen!" << endl;
    }
}
void AVLTree::searchByName(string name) {
    vector<Appointment> result;
    searchByName(root, name, result);
    if (result.empty()) cout << "Khong tim thay lich hen!" << endl;
    else {
        for (auto& appt : result) {
            cout << appt.datetime << " | " << appt.patientName << " | " << appt.doctorName << " | " << appt.note << endl;
        }
    }
}
void AVLTree::printAll() {
    cout << "Danh sach lich hen theo thu tu thoi gian:" << endl;
    inorder(root);
}
