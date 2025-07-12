#include "BST.h"
#include <iostream>
int main() {
    BST *bst = new BST();
    int arr[] = {60, 20, 30, 15, 90, -8, 9, 16, 30, 57, 60, 48, -2};
    for (int x : arr) bst->insert(x);
    bst->printTree();
    cout << "So nut co 2 con va it nhat 1 con la so chan: " << bst->countNodesWithEvenChild() << endl;
    cout << "Tong cac gia tri le tren tung tang cua cay BST:\n";
    bst->printSumOddValuesByLevel();
}