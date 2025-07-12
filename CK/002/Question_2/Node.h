#ifndef NODE_H
#define NODE_H
class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node() : key(0), left(nullptr), right(nullptr) {};
    Node(int key) : key(key), left(nullptr), right(nullptr) {};
};
#endif // NODE_H