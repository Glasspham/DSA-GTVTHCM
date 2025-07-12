#pragma once
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>
using namespace std;
class BankAccount {
private:
    string accountNumber;
    string accountName;
    string accountType; // 001: Thanh toan, 002: Tiet kiem
    double balance;
    int status; // 0: Active, 1: Block
    const string PASSWORD = "123456";
    int wrongPasswordCount = 0;

public:
    BankAccount(string accNum, string name, string type, double bal, int stat);
    // Getters
    string getAccountNumber() const;
    string getAccountType() const;
    int getStatus() const;
    double getBalance() const;
    // Setters
    void setStatus(int stat);
    void setBalance(double bal);
    bool checkPassword(string inputPassword);
};
#endif