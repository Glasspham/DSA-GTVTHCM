#include "AVL_tree.h"
#include "BST.h"
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    string path = "data.txt";
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Cannot open file: " << endl;
        return 0;
    }
    AVL_tree *AVLTree = new AVL_tree();
    BST *BSTree = new BST();
    int num;
    while(file >> num) {
        cout << num << ' ';
        Node *node1 = new Node(num); // Node cho AVLTree
        Node *node2 = new Node(num); // Node cho BSTree
        AVLTree->InsertNodeRe(node1);
        BSTree->InsertNode(node2);
    }
    cout << endl;
    cout << "Tree AVL: " << endl;
    AVLTree->TravelNLR();
    cout << endl;
    cout << "Tree BST: " << endl;
    BSTree->TravelNLR();
    cout << endl;
    int key = 21, compareCount = 0;
    AVLTree->search_x(key, compareCount);
    cout << "Found: " << key << " with compare count: " << compareCount << endl;
    key = 21;
    BSTree->search_x(key, compareCount);
    cout << "Found: " << key << " with compare count: " << compareCount << endl;
    return 0;
}