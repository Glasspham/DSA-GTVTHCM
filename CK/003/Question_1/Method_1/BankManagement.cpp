#include "BankManagement.h"

void BankManagement::addAccount(BankAccount account) { accounts.push_back(account); }

bool BankManagement::deposit(string accountNumber) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            cout << "\nKiem tra tai khoan..." << endl;
            // Kiểm tra tài khoản tồn tại
            cout << "- Tai khoan " << accountNumber << " ton tai" << endl;
            // Kiểm tra trạng thái active
            cout << "- Tinh trang tai khoan: " << acc.getStatus() << endl;
            if (acc.getStatus() == 1) {
                cout << "- Tai khoan bi khoa!" << endl;
                return false;
            }
            // Kiểm tra loại tài khoản
            if (acc.getAccountType() != "001") {
                cout << "- Chi tai khoan thanh toan moi duoc nop tien!" << endl;
                return false;
            }
            cout << "- Tai khoan thanh toan hop le" << endl;
            cout << "\nTat ca dieu kien deu thoa man. Tiep tuc giao dich...\n" << endl;
            for (int i = 0; i < 3; i++) {
                string password;
                cout << "Nhap mat khau: ";
                cin >> password;
                if (acc.checkPassword(password)) {
                    ifstream file("tiennop.txt");
                    if (!file.is_open()) {
                        cout << "Khong the mo file tiennop.txt!" << endl;
                        return false;
                    }
                    double amount;
                    if (file >> amount) {
                        acc.setBalance(acc.getBalance() + amount);
                        cout << fixed << setprecision(0);
                        cout << "Nop tien thanh cong!" << endl;
                        cout << "So tien nop: " << amount << " VND" << endl;
                        cout << "So du moi: " << acc.getBalance() << " VND" << endl;
                        file.close();
                        return true;
                    } else {
                        cout << "Khong the doc so tien tu file!" << endl;
                        file.close();
                        return false;
                    }
                }
                cout << "Mat khau sai! Con " << 2 - i << " lan thu" << endl;
            }
            return false;
        }
    }
    cout << "Khong tim thay tai khoan!" << endl;
    return false;
}

/* void BankManagement::checkStatus(string accountNumber) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            cout << "Tinh trang tai khoan: " << acc.getStatus() << endl;
            return;
        }
    }
    cout << "Khong tim thay tai khoan!" << endl;
}
 */

void BankManagement::checkStatus(string accountNumber) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            cout << "Tinh trang tai khoan: " << acc.getStatus()
                      << " (0 - Active, 1 - Block)" << endl;
            if (acc.getStatus() == 1) {
                char choice;
                cout << "Ban co muon kich hoat lai tai khoan? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    // Yêu cầu nhập mật khẩu để kích hoạt
                    int attempts = 0;
                    while (attempts < 3) {
                        string password;
                        cout << "Nhap mat khau de kich hoat: ";
                        cin >> password;
                        if (acc.checkPassword(password)) {
                            acc.setStatus(0);
                            cout << "Tai khoan da duoc kich hoat lai!" << endl;
                            cout << "Tinh trang tai khoan moi: 0 (0 - Active, 1 - Block)" << endl;
                            return;
                        } else {
                            attempts++;
                            if (attempts < 3)
                                cout << "Mat khau sai! Con " << (3 - attempts) << " lan thu." << endl;
                        }
                    }
                    cout << "Nhap sai mat khau qua 3 lan. Tai khoan van bi khoa!" << endl;
                }
            }
            return;
        }
    }
    cout << "Khong tim thay tai khoan!" << endl;
}
