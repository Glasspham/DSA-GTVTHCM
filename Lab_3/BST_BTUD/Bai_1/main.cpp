#include "BST.h"

/**
 *  1. Sử dụng cây nhị phân tìm kiếm để giải bài toán đếm (thống kê) số lượng ký tự có trong văn bản 
 * (Không dấu).
 * a. Xây dựng cây cho biết mỗi ký tự có trong văn bản xuất hiện mấy lần
 * b. Nhập vào 1 ký tự. Kiểm tra ký tự đó xuất hiện bao nhiêu lần trong văn bản
 * */
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
        cin.ignore();
        string str;
        cout << "Enter string: " << endl;
        getline(cin, str);
        for(char c : str) {
            Node *n = new Node(c);
            tree->InsertNode(n);
        }
    }
    tree->PrintDistinctValues();

    cout << "Enter character: ";
    char c; cin >> c;
    tree->Find(c);
    return 0;   
}
