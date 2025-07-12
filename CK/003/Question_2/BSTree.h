#ifndef BST_H
#define BST_H
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key) 
            node->right = insert(node->right, key);
        return node;
    }
    
    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key)
            return node;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr) return node;
        if (key < node->key) 
            node->left = remove(node->left, key);
        else if (key > node->key) 
            node->right = remove(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = node->right;
            while (temp->left != nullptr) temp = temp->left;
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
        return node;
    }

    // Function to find the height of the binary tree
    int findHeight(Node *root) {
        if (!root) return -1;
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }

    // Helper function to perform inorder traversal and
    // populate the 2D matrix
    void inorder(Node *root, int row, int col, int height, vector<vector<string>> &ans) {
        if (!root) return;
        // Calculate offset for child positions
        int offset = pow(2, height - row - 1);
        // Traverse the left subtree
        if (root->left) inorder(root->left, row + 1, col - offset, height, ans);
        // Place the current node's value in the matrix
        ans[row][col] = to_string(root->key);
        // Traverse the right subtree
        if (root->right) inorder(root->right, row + 1, col + offset, height, ans);
    }

    // Function to convert the binary tree to a 2D matrix
    vector<vector<string>> treeToMatrix(Node *root) {
        // Find the height of the tree
        int height = findHeight(root);
        // Rows are height + 1; columns are 2^(height+1) - 1
        int rows = height + 1;
        int cols = pow(2, height + 1) - 1;
        // Initialize 2D matrix with empty strings
        vector<vector<string>> ans(rows, vector<string>(cols, ""));
        // Populate the matrix using inorder traversal
        inorder(root, 0, (cols - 1) / 2, height, ans);
        return ans;
    }
    
    void print2DArray(vector<vector<string>> &arr) {
        for (auto &row : arr) {
            for (auto &cell : row) {
                if (cell.empty()) cout << " ";
                else cout << cell;
            }
            cout << endl << endl;
        }
    }

public:
    BST() : root(nullptr){};

    ~BST() { delete root; };

    void insert(int key) { root = insert(root, key); }

    void search(int key) { 
        Node* result = search(root, key);
        if (result == nullptr) cout << "Khong tim thay nut " << key << " trong cay.\n";
        else {
            cout << "Nut " << key << " ton tai trong cay.\n";
            if (result->left == nullptr && result->right == nullptr) cout << "Nut la.\n";
            else if (result->left != nullptr && result->right != nullptr) {
                cout << "Nut co 2 con.\n";
                root = remove(root, key);
                cout << "Da xoa nut " << key << " khoi cay.\n";
            }
            else if (result->left != nullptr) cout << "Nut co 1 con trai.\n";
            else cout << "Nut co 1 con phai.\n";
        }
    }

    void printTree() {
        vector<vector<string>> matrix = treeToMatrix(root);
        print2DArray(matrix);
    }
};
#endif // BST_H