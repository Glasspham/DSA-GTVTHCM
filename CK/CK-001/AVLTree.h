#pragma once
#include "Appointment.h"
#include <vector>

class AVLNode {
public:
    Appointment data;
    AVLNode *left, *right;
    int height;
    AVLNode(const Appointment& appt);
};

class AVLTree {
private:
    AVLNode* root;
    AVLNode* insert(AVLNode* node, const Appointment& appt);
    AVLNode* deleteNode(AVLNode* root, string datetime);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* searchByDatetime(AVLNode* node, string datetime);
    void searchByName(AVLNode* node, const string& name, std::vector<Appointment>& result);
    void inorder(AVLNode* node);
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
public:
    AVLTree();
    void addAppointment(const Appointment& appt);
    void removeAppointment(string datetime);
    void searchByDatetime(string datetime);
    void searchByName(string name);
    void printAll();
};
