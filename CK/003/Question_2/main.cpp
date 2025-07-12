#include "BSTree.h"
#include <iostream>
int main() {
    BST *bst = new BST();
    int arr[] = {70, 18, 40, 20, 90, -10, 10, 19, 35, 45, 60, 55};
    for (int x : arr) bst->insert(x);
    bst->printTree();
    cout << "Nhap so Y can tim: ";
    int Y; cin >> Y;
    bst->search(Y);
    bst->printTree();
}