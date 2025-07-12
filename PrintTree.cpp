#include <iostream>
#include <utility>
using namespace std;

// Data structure to store binary tree node
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Utility function to print two-dimensional view of a binary tree using reverse inorder traversal
void printBinaryTree(Node *root, int space = 0, int height = 5) {
    // Base case
    if (root == nullptr) return;
    // now increase distance between levels
    space += height;
    // print the right child first
    printBinaryTree(root->right, space);
    cout << endl;
    // print the current node after increasing with spaces
    for (int i = height; i < space; i++)
        cout << ' ';
    cout << root->data;
    // print the left child
    cout << endl;
    printBinaryTree(root->left, space);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // print binary tree
    printBinaryTree(root);
    return 0;
}