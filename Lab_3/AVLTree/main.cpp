#include "AVL_tree.h"
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    // TODO Yêu cầu
    /**********Test**********/
    AVL_tree tree;
    string path = "data.txt";
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Cannot open file: " << endl;
        return 0;
    }
    int num;
    while(file >> num)
        tree.InsertNodeRe(new Node(num));
    
    tree.TravelNLR();
    cout << endl;

    cout << "Function delete: " << endl;
    tree.deleteNode(new Node(15));
    tree.TravelNLR();
    cout << endl;

    cout << "Function search: " << endl;
    Node* foundNode = tree.search_x(4);
    if(foundNode != nullptr)
        cout << "Found: " << foundNode->Getkey() << endl;
    else cout << "Not found" << endl;

    cout << "Function SumTree: " << tree.SumTree() << endl;
    cout << "Function HeightTree: " << tree.GetHeight() << endl;
    cout << "Function Max: " << tree.FindMax()->Getkey() << endl;
    cout << "Function Min: " << tree.FindMin()->Getkey() << endl;
    cout << "Function CountNode: " << tree.CountNode() << endl;
    cout << "Function CountLeaf: " << tree.CountLeaf() << endl;
    cout << "Function PrintDistinctValues:\n";
    tree.PrintDistinctValues();
    return 0;
}