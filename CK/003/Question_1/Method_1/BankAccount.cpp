#include "BankAccount.h"

BankAccount::BankAccount(string accNum, string name, string type, double bal, int stat) {
    accountNumber = accNum;
    accountName = name;
    accountType = type;
    balance = bal;
    status = stat;
}

string BankAccount::getAccountNumber() const { return accountNumber; }

string BankAccount::getAccountType() const { return accountType; }

int BankAccount::getStatus() const { return status; }

double BankAccount::getBalance() const { return balance; }

void BankAccount::setStatus(int stat) { status = stat; }

void BankAccount::setBalance(double bal) { balance = bal; }

bool BankAccount::checkPassword(string inputPassword) {
    if (inputPassword != PASSWORD) {
        wrongPasswordCount++;
        if (wrongPasswordCount >= 3) {
            status = 1; // Block account
            return false;
        }
        return false;
    }
    wrongPasswordCount = 0;
    return true;
}