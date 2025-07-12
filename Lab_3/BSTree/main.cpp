#include <iostream>
#include "BST.h"
using namespace std;
int main() {
    BST *tree = new BST();
    Node *n;
    n = new Node(10);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(9);
    tree->InsertNode(n);
    n = new Node(3);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(8);
    tree->InsertNode(n);
    n = new Node(4);
    tree->InsertNode(n);
    n = new Node(1);
    tree->InsertNode(n);
    n = new Node(15);
    tree->InsertNode(n);
    /**********Test**********/
    tree->TravelNLR();
    cout << endl;

    cout << "Function search_x" << endl;
    Node* foundNode = tree->search_x(4);
    if(foundNode != nullptr)
        cout << "Found: " << foundNode->Getkey() << endl;
    else cout << "Not found" << endl;

    cout << "Function deleteNode" << endl;
    n = new Node(10);
    tree->deleteNode(n);
    tree->TravelNLR();
    cout << endl;
    
    cout << "Function Sum of tree: " << tree->SumTree() << endl;
    cout << "Function Min of tree: " << tree->FindMin()->Getkey() << endl;
    cout << "Function Max of tree: " << tree->FindMax()->Getkey() << endl;
    cout << "Function Total number of nodes: " << tree->CountNode() << endl;
    cout << "Function Total number of leaf nodes: " << tree->CountLeaf() << endl;
    cout << "Function Distinct values: " << tree->DistinctValues() << endl;
    cout << "Function PrintDistinctValues: " << endl;
    tree->PrintDistinctValues();

    tree->TravelNLR();
    cout << endl;
    return 0;   
}
