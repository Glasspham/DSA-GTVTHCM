#include <bits/stdc++.h>
#include "BankManagement.h"
#include "BankAccount.h" 
using namespace std;
int main() {
    BankManagement bank;
    // Thêm một số tài khoản mẫu
    bank.addAccount(BankAccount("0111222233334444", "Nguyen Van A", "001", 1000000, 0));
    bank.addAccount(BankAccount("0111222233335555", "Tran Thi B", "002", 2000000, 1));
    int choice;
    string accountNumber;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Nop tien" << endl;
        cout << "2. Kiem tra trang thai tai khoan" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Nhap so tai khoan: ";
            cin >> accountNumber;
            if (bank.deposit(accountNumber))
                cout << "Giao dich hoan tat!" << endl;
            else cout << "Giao dich that bai!" << endl;
            break;
        }
        case 2: {
            cout << "Nhap so tai khoan: ";
            cin >> accountNumber;
            bank.checkStatus(accountNumber);
            break;
        }
        case 0:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);
    return 0;
}