#include "BST.h"
#include <iostream>
int main() {
    BST *bst = new BST();
    int arr[] = {50, 18, 35, 14, 90, -5, 10, 15, 35, 55, 65, 52};
    for (int x : arr) bst->insert(x);
    bst->printTree();
    cout << "Nhap so Y can tim: ";
    int Y; cin >> Y;
    bst->search(Y);
    int sum = bst->sum();
    cout << "Tong gia tri cac nut co 1 nhanh con:  " << sum << endl;
}