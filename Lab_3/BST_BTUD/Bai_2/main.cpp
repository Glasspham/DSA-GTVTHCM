#include "BST.h"
int main() {
    BST *tree = new BST();
    int select;
    do {
        cout << "1. Import by file " << endl;
        cout << "2. Import by terminal " << endl;
        cout << "Select: ";
        cin >> select;
        if (select != 1 && select != 2) 
            cout << "Wrong input" << endl;
    } while(select != 1 && select != 2);
    if (select == 1) {
        string path;
        cout << "Enter path: "; cin >> path;
        cin.ignore();
        ifstream file(path);
        if (!file.is_open()) {
            cout << "Cannot open file: " << endl;
            return 0;
        }
        tree->ImportByFile(file);
    } else {
        string str;
        while(cin >> str)
            tree->InsertNode(new Node(str));
    }
    tree->PrintDistinctValues();
    cout << "Enter character: ";
    string c; cin >> c;
    tree->Find(c);
    return 0;   
}
