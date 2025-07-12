#include "Bank.h"

int main() {
    Bank bank;
    bank.insert(new Account("0111222233334444", "Nguyen Van An", "001", 200000000, 0));
    bank.insert(new Account("0222333444555666", "Le Thi B", "002", 50000000, 1));

    string accNumber;
    
    // Thực hiện nộp tiền
    cout << "Nhap so tai khoan de nop tien: ";
    cin >> accNumber;
    bank.depositMoney(accNumber);

    // Kiểm tra và mở khóa tài khoản
    cout << "Nhap so tai khoan de kiem tra trang thai: ";
    cin >> accNumber;
    bank.checkAndUnblock(accNumber);

    return 0;
}
