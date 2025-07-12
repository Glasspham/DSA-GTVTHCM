#include "Dictionary.h"
#include <iostream>
#include <limits>
using namespace std;

void menu() {
    cout << "\n===== Tu dien Anh-Viet =====\n";
        cout << "1. Them tu\n";
        cout << "2. Tim kiem tu\n";
        cout << "3. Sua tu\n";
        cout << "4. Hien thi tat ca tu\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
}

int main() {
    Dictionary dict;
    int choice;
    string eng, vie;
    while(true) {
        menu();
        cin >> choice;
        if (choice == 1) {
            cout << "Nhap tu Anh: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, eng);
            cout << "Nhap nghia tieng Viet: ";
            getline(cin, vie);
            dict.addWord(eng, vie);
            cout << "Them tu thanh cong.\n";
        } else if (choice == 2) {
            cout << "Nhap tu Anh can tim: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, eng);
            vie = "";
            dict.lookupWord(eng, vie);
        }
        else if (choice == 3) {
            cout << "Nhap tu Anh can sua: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, eng);
            cout << "Nghia tieng Viet moi: ";
            getline(cin, vie);
            dict.modifyWord(eng, vie);
            cout << "Sua thanh cong.\n";
        } else if (choice == 4) {
            dict.displayAll();
        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else cout << "Lua chon khong hop le. Vui long nhap lai.\n";
    }
    return 0;
}