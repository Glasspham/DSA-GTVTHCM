#ifndef _NODE_H_
#define _NODE_H_
#include "Student.h"
using namespace std;

class Node{
private:
    Student student;
    Node* left;
    Node* right;
    int height;

public:
    // Constructors
    Node() : left(nullptr), right(nullptr), height(1) {}
    Node(const Student& s) : student(s), left(nullptr), right(nullptr), height(1) {}

    // Getters and setters
    const Student& getStudent() const { return student; }
    void setStudent(const Student& s) { student = s; }
    Node* getLeft() const { return left; }
    void setLeft(Node* n) { left = n; }
    Node* getRight() const { return right; }
    void setRight(Node* n) { right = n; }
    int getHeight() const { return height; }
    void setHeight(int h) { height = h; }
};
#endif // _NODE_H_